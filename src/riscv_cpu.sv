// riscv_cpu.sv
//
// Simple five-stage RV32I-style CPU.
// Module name: cpu
//
// Pipeline:
//   IF  - instruction fetch
//   ID  - decode/register read
//   EX  - ALU/branch
//   MEM - data memory
//   WB  - register writeback
//
// Data memory interface uses dcache_if.cpu.
// This version is designed to work directly with dram_model.sv using:
//   dram_model #(.BLOCK_BYTES(4))
//
// Supported enough instructions for testing:
//   ADD, SUB, AND, OR, XOR, SLT, SLTU, SLL, SRL, SRA
//   ADDI, ANDI, ORI, XORI, SLTI, SLTIU, SLLI, SRLI, SRAI
//   LW, SW
//   BEQ, BNE, BLT, BGE, BLTU, BGEU
//   LUI, AUIPC
//   JAL, JALR
//   EBREAK

module cpu #(
    parameter RESET_PC = 32'h0000_0000
) (
    input  logic clk,
    input  logic rst,

    output logic [31:0] imem_addr,
    input  logic [31:0] imem_rdata,

    dcache_if.cpu dmem,

    output logic halted
);

    // ------------------------------------------------------------
    // Constants
    // ------------------------------------------------------------

    localparam OPCODE_OP     = 7'b0110011;
    localparam OPCODE_OPIMM  = 7'b0010011;
    localparam OPCODE_LOAD   = 7'b0000011;
    localparam OPCODE_STORE  = 7'b0100011;
    localparam OPCODE_BRANCH = 7'b1100011;
    localparam OPCODE_LUI    = 7'b0110111;
    localparam OPCODE_AUIPC  = 7'b0010111;
    localparam OPCODE_JAL    = 7'b1101111;
    localparam OPCODE_JALR   = 7'b1100111;
    localparam OPCODE_SYSTEM = 7'b1110011;

    localparam INSTR_NOP     = 32'h0000_0013; // addi x0, x0, 0
    localparam INSTR_EBREAK  = 32'h0010_0073;

    // ------------------------------------------------------------
    // Register file
    // ------------------------------------------------------------

    logic [31:0] regs [0:31];

    // ------------------------------------------------------------
    // ALU types
    // ------------------------------------------------------------

    typedef enum logic [3:0] {
        ALU_ADD,
        ALU_SUB,
        ALU_AND,
        ALU_OR,
        ALU_XOR,
        ALU_SLT,
        ALU_SLTU,
        ALU_SLL,
        ALU_SRL,
        ALU_SRA,
        ALU_COPY_B
    } alu_op_t;

    typedef enum logic [1:0] {
        WB_ALU,
        WB_MEM,
        WB_PC4
    } wb_sel_t;

    function automatic logic [31:0] alu_exec(
        input alu_op_t op,
        input logic [31:0] a,
        input logic [31:0] b
    );
        case (op)
            ALU_ADD:    alu_exec = a + b;
            ALU_SUB:    alu_exec = a - b;
            ALU_AND:    alu_exec = a & b;
            ALU_OR:     alu_exec = a | b;
            ALU_XOR:    alu_exec = a ^ b;
            ALU_SLT:    alu_exec = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            ALU_SLTU:   alu_exec = (a < b) ? 32'd1 : 32'd0;
            ALU_SLL:    alu_exec = a << b[4:0];
            ALU_SRL:    alu_exec = a >> b[4:0];
            ALU_SRA:    alu_exec = $signed(a) >>> b[4:0];
            ALU_COPY_B: alu_exec = b;
            default:    alu_exec = 32'd0;
        endcase
    endfunction

    // ------------------------------------------------------------
    // Immediate generation
    // ------------------------------------------------------------

    function automatic logic [31:0] imm_i(input logic [31:0] instr);
        imm_i = {{20{instr[31]}}, instr[31:20]};
    endfunction

    function automatic logic [31:0] imm_s(input logic [31:0] instr);
        imm_s = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    endfunction

    function automatic logic [31:0] imm_b(input logic [31:0] instr);
        imm_b = {{19{instr[31]}}, instr[31], instr[7],
                 instr[30:25], instr[11:8], 1'b0};
    endfunction

    function automatic logic [31:0] imm_u(input logic [31:0] instr);
        imm_u = {instr[31:12], 12'b0};
    endfunction

    function automatic logic [31:0] imm_j(input logic [31:0] instr);
        imm_j = {{11{instr[31]}}, instr[31], instr[19:12],
                 instr[20], instr[30:21], 1'b0};
    endfunction

    // ------------------------------------------------------------
    // IF stage
    // ------------------------------------------------------------

    logic [31:0] pc;

    assign imem_addr = pc;

    // ------------------------------------------------------------
    // IF/ID pipeline register
    // ------------------------------------------------------------

    logic        ifid_valid;
    logic [31:0] ifid_pc;
    logic [31:0] ifid_instr;

    // ------------------------------------------------------------
    // ID decode
    // ------------------------------------------------------------

    logic [6:0] id_opcode;
    logic [2:0] id_funct3;
    logic [6:0] id_funct7;
    logic [4:0] id_rs1;
    logic [4:0] id_rs2;
    logic [4:0] id_rd;

    assign id_opcode = ifid_instr[6:0];
    assign id_rd     = ifid_instr[11:7];
    assign id_funct3 = ifid_instr[14:12];
    assign id_rs1    = ifid_instr[19:15];
    assign id_rs2    = ifid_instr[24:20];
    assign id_funct7 = ifid_instr[31:25];

    logic [31:0] id_rs1_val;
    logic [31:0] id_rs2_val;

    assign id_rs1_val = (id_rs1 == 5'd0) ? 32'd0 : regs[id_rs1];
    assign id_rs2_val = (id_rs2 == 5'd0) ? 32'd0 : regs[id_rs2];

    alu_op_t     dec_alu_op;
    logic        dec_alu_src_imm;
    logic        dec_op_a_pc;
    logic        dec_mem_read;
    logic        dec_mem_write;
    logic        dec_reg_write;
    wb_sel_t     dec_wb_sel;
    logic        dec_branch;
    logic        dec_jump;
    logic        dec_jalr;
    logic [31:0] dec_imm;
    logic        dec_use_rs1;
    logic        dec_use_rs2;

    always_comb begin
        dec_alu_op      = ALU_ADD;
        dec_alu_src_imm = 1'b0;
        dec_op_a_pc     = 1'b0;
        dec_mem_read    = 1'b0;
        dec_mem_write   = 1'b0;
        dec_reg_write   = 1'b0;
        dec_wb_sel      = WB_ALU;
        dec_branch      = 1'b0;
        dec_jump        = 1'b0;
        dec_jalr        = 1'b0;
        dec_imm         = 32'd0;
        dec_use_rs1     = 1'b0;
        dec_use_rs2     = 1'b0;

        case (id_opcode)

            OPCODE_OP: begin
                dec_reg_write = 1'b1;
                dec_use_rs1   = 1'b1;
                dec_use_rs2   = 1'b1;

                case ({id_funct7, id_funct3})
                    {7'b0000000, 3'b000}: dec_alu_op = ALU_ADD;
                    {7'b0100000, 3'b000}: dec_alu_op = ALU_SUB;
                    {7'b0000000, 3'b111}: dec_alu_op = ALU_AND;
                    {7'b0000000, 3'b110}: dec_alu_op = ALU_OR;
                    {7'b0000000, 3'b100}: dec_alu_op = ALU_XOR;
                    {7'b0000000, 3'b010}: dec_alu_op = ALU_SLT;
                    {7'b0000000, 3'b011}: dec_alu_op = ALU_SLTU;
                    {7'b0000000, 3'b001}: dec_alu_op = ALU_SLL;
                    {7'b0000000, 3'b101}: dec_alu_op = ALU_SRL;
                    {7'b0100000, 3'b101}: dec_alu_op = ALU_SRA;
                    default:              dec_alu_op = ALU_ADD;
                endcase
            end

            OPCODE_OPIMM: begin
                dec_reg_write   = 1'b1;
                dec_alu_src_imm = 1'b1;
                dec_imm         = imm_i(ifid_instr);
                dec_use_rs1     = 1'b1;

                case (id_funct3)
                    3'b000: dec_alu_op = ALU_ADD; // ADDI
                    3'b111: dec_alu_op = ALU_AND;
                    3'b110: dec_alu_op = ALU_OR;
                    3'b100: dec_alu_op = ALU_XOR;
                    3'b010: dec_alu_op = ALU_SLT;
                    3'b011: dec_alu_op = ALU_SLTU;
                    3'b001: dec_alu_op = ALU_SLL;
                    3'b101: dec_alu_op = ifid_instr[30] ? ALU_SRA : ALU_SRL;
                    default: dec_alu_op = ALU_ADD;
                endcase
            end

            OPCODE_LOAD: begin
                // Only LW is used/supported in this simple CPU.
                dec_reg_write   = 1'b1;
                dec_mem_read    = 1'b1;
                dec_wb_sel      = WB_MEM;
                dec_alu_src_imm = 1'b1;
                dec_alu_op      = ALU_ADD;
                dec_imm         = imm_i(ifid_instr);
                dec_use_rs1     = 1'b1;
            end

            OPCODE_STORE: begin
                // Only SW is used/supported in this simple CPU.
                dec_mem_write   = 1'b1;
                dec_alu_src_imm = 1'b1;
                dec_alu_op      = ALU_ADD;
                dec_imm         = imm_s(ifid_instr);
                dec_use_rs1     = 1'b1;
                dec_use_rs2     = 1'b1;
            end

            OPCODE_BRANCH: begin
                dec_branch  = 1'b1;
                dec_imm     = imm_b(ifid_instr);
                dec_use_rs1 = 1'b1;
                dec_use_rs2 = 1'b1;
            end

            OPCODE_LUI: begin
                dec_reg_write   = 1'b1;
                dec_alu_src_imm = 1'b1;
                dec_alu_op      = ALU_COPY_B;
                dec_imm         = imm_u(ifid_instr);
            end

            OPCODE_AUIPC: begin
                dec_reg_write   = 1'b1;
                dec_alu_src_imm = 1'b1;
                dec_op_a_pc     = 1'b1;
                dec_alu_op      = ALU_ADD;
                dec_imm         = imm_u(ifid_instr);
            end

            OPCODE_JAL: begin
                dec_jump      = 1'b1;
                dec_reg_write = 1'b1;
                dec_wb_sel    = WB_PC4;
                dec_imm       = imm_j(ifid_instr);
            end

            OPCODE_JALR: begin
                dec_jump      = 1'b1;
                dec_jalr      = 1'b1;
                dec_reg_write = 1'b1;
                dec_wb_sel    = WB_PC4;
                dec_imm       = imm_i(ifid_instr);
                dec_use_rs1   = 1'b1;
            end

            OPCODE_SYSTEM: begin
                // EBREAK handled when it reaches WB.
            end

            default: begin
                // Treat unsupported instructions as NOP.
            end
        endcase
    end

    // ------------------------------------------------------------
    // ID/EX pipeline register
    // ------------------------------------------------------------

    logic        idex_valid;
    logic [31:0] idex_pc;
    logic [31:0] idex_pc4;
    logic [31:0] idex_instr;
    logic [4:0]  idex_rs1;
    logic [4:0]  idex_rs2;
    logic [4:0]  idex_rd;
    logic [2:0]  idex_funct3;
    logic [31:0] idex_rs1_val;
    logic [31:0] idex_rs2_val;
    logic [31:0] idex_imm;
    alu_op_t     idex_alu_op;
    logic        idex_alu_src_imm;
    logic        idex_op_a_pc;
    logic        idex_mem_read;
    logic        idex_mem_write;
    logic        idex_reg_write;
    wb_sel_t     idex_wb_sel;
    logic        idex_branch;
    logic        idex_jump;
    logic        idex_jalr;

    // ------------------------------------------------------------
    // EX/MEM pipeline register
    // ------------------------------------------------------------

    logic        exmem_valid;
    logic [31:0] exmem_instr;
    logic [4:0]  exmem_rd;
    logic [31:0] exmem_alu_result;
    logic [31:0] exmem_store_data;
    logic [31:0] exmem_wb_data;
    logic        exmem_mem_read;
    logic        exmem_mem_write;
    logic        exmem_reg_write;
    wb_sel_t     exmem_wb_sel;

    // ------------------------------------------------------------
    // MEM/WB pipeline register
    // ------------------------------------------------------------

    logic        memwb_valid;
    logic [31:0] memwb_instr;
    logic [4:0]  memwb_rd;
    logic [31:0] memwb_wb_data;
    logic        memwb_reg_write;

    // ------------------------------------------------------------
    // Register writeback / halt
    // ------------------------------------------------------------

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 0; i < 32; i++) begin
                regs[i] <= 32'd0;
            end
            halted <= 1'b0;
        end else begin
            if (memwb_valid && memwb_reg_write && memwb_rd != 5'd0) begin
                regs[memwb_rd] <= memwb_wb_data;
            end

            regs[0] <= 32'd0;

            if (memwb_valid && memwb_instr == INSTR_EBREAK) begin
                halted <= 1'b1;
            end
        end
    end

    // ------------------------------------------------------------
    // Forwarding
    // ------------------------------------------------------------

    logic [31:0] fwd_rs1;
    logic [31:0] fwd_rs2;

    always_comb begin
        fwd_rs1 = idex_rs1_val;
        fwd_rs2 = idex_rs2_val;

        if (exmem_valid &&
            exmem_reg_write &&
            !exmem_mem_read &&
            exmem_rd != 5'd0 &&
            exmem_rd == idex_rs1) begin
            fwd_rs1 = exmem_wb_data;
        end else if (memwb_valid &&
                     memwb_reg_write &&
                     memwb_rd != 5'd0 &&
                     memwb_rd == idex_rs1) begin
            fwd_rs1 = memwb_wb_data;
        end

        if (exmem_valid &&
            exmem_reg_write &&
            !exmem_mem_read &&
            exmem_rd != 5'd0 &&
            exmem_rd == idex_rs2) begin
            fwd_rs2 = exmem_wb_data;
        end else if (memwb_valid &&
                     memwb_reg_write &&
                     memwb_rd != 5'd0 &&
                     memwb_rd == idex_rs2) begin
            fwd_rs2 = memwb_wb_data;
        end
    end

    // ------------------------------------------------------------
    // EX stage
    // ------------------------------------------------------------

    logic [31:0] alu_a;
    logic [31:0] alu_b;
    logic [31:0] alu_result;
    logic [31:0] ex_wb_data;

    assign alu_a      = idex_op_a_pc ? idex_pc : fwd_rs1;
    assign alu_b      = idex_alu_src_imm ? idex_imm : fwd_rs2;
    assign alu_result = alu_exec(idex_alu_op, alu_a, alu_b);

    always_comb begin
        case (idex_wb_sel)
            WB_PC4:  ex_wb_data = idex_pc4;
            default: ex_wb_data = alu_result;
        endcase
    end

    logic        branch_taken;
    logic [31:0] branch_target;

    always_comb begin
        branch_taken  = 1'b0;
        branch_target = idex_pc + idex_imm;

        if (idex_valid && idex_branch) begin
            case (idex_funct3)
                3'b000: branch_taken = (fwd_rs1 == fwd_rs2);                  // BEQ
                3'b001: branch_taken = (fwd_rs1 != fwd_rs2);                  // BNE
                3'b100: branch_taken = ($signed(fwd_rs1) <  $signed(fwd_rs2)); // BLT
                3'b101: branch_taken = ($signed(fwd_rs1) >= $signed(fwd_rs2)); // BGE
                3'b110: branch_taken = (fwd_rs1 <  fwd_rs2);                  // BLTU
                3'b111: branch_taken = (fwd_rs1 >= fwd_rs2);                  // BGEU
                default: branch_taken = 1'b0;
            endcase
        end

        if (idex_valid && idex_jump) begin
            branch_taken = 1'b1;

            if (idex_jalr) begin
                branch_target = (fwd_rs1 + idex_imm) & 32'hffff_fffe;
            end else begin
                branch_target = idex_pc + idex_imm;
            end
        end
    end

    // ------------------------------------------------------------
    // Data memory interface
    // ------------------------------------------------------------
    //
    // dram_model expects request valid as a pulse.
    // Therefore, this CPU sends one request pulse and then waits for ready.

    logic exmem_is_mem;
    logic dmem_req_sent;

    assign exmem_is_mem = exmem_valid && (exmem_mem_read || exmem_mem_write);

    assign dmem.req_valid = exmem_is_mem && !dmem_req_sent;
    assign dmem.rw        = exmem_mem_write;
    assign dmem.addr      = exmem_alu_result;
    assign dmem.wdata     = exmem_store_data;

    logic mem_wait;

    assign mem_wait = exmem_is_mem && !dmem.ready;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            dmem_req_sent <= 1'b0;
        end else if (!halted) begin
            if (exmem_is_mem && dmem.ready) begin
                dmem_req_sent <= 1'b0;
            end else if (dmem.req_valid) begin
                dmem_req_sent <= 1'b1;
            end else if (!exmem_is_mem) begin
                dmem_req_sent <= 1'b0;
            end
        end
    end

    // ------------------------------------------------------------
    // Load-use hazard detection
    // ------------------------------------------------------------

    logic load_use_stall;

    always_comb begin
        load_use_stall = 1'b0;

        if (ifid_valid && idex_valid && idex_mem_read && idex_rd != 5'd0) begin
            if ((dec_use_rs1 && idex_rd == id_rs1) ||
                (dec_use_rs2 && idex_rd == id_rs2)) begin
                load_use_stall = 1'b1;
            end
        end
    end

    // ------------------------------------------------------------
    // Main pipeline registers
    // ------------------------------------------------------------

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= RESET_PC;

            ifid_valid <= 1'b0;
            ifid_pc    <= 32'd0;
            ifid_instr <= INSTR_NOP;

            idex_valid       <= 1'b0;
            idex_pc          <= 32'd0;
            idex_pc4         <= 32'd0;
            idex_instr       <= INSTR_NOP;
            idex_rs1         <= 5'd0;
            idex_rs2         <= 5'd0;
            idex_rd          <= 5'd0;
            idex_funct3      <= 3'd0;
            idex_rs1_val     <= 32'd0;
            idex_rs2_val     <= 32'd0;
            idex_imm         <= 32'd0;
            idex_alu_op      <= ALU_ADD;
            idex_alu_src_imm <= 1'b0;
            idex_op_a_pc     <= 1'b0;
            idex_mem_read    <= 1'b0;
            idex_mem_write   <= 1'b0;
            idex_reg_write   <= 1'b0;
            idex_wb_sel      <= WB_ALU;
            idex_branch      <= 1'b0;
            idex_jump        <= 1'b0;
            idex_jalr        <= 1'b0;

            exmem_valid      <= 1'b0;
            exmem_instr      <= INSTR_NOP;
            exmem_rd         <= 5'd0;
            exmem_alu_result <= 32'd0;
            exmem_store_data <= 32'd0;
            exmem_wb_data    <= 32'd0;
            exmem_mem_read   <= 1'b0;
            exmem_mem_write  <= 1'b0;
            exmem_reg_write  <= 1'b0;
            exmem_wb_sel     <= WB_ALU;

            memwb_valid      <= 1'b0;
            memwb_instr      <= INSTR_NOP;
            memwb_rd         <= 5'd0;
            memwb_wb_data    <= 32'd0;
            memwb_reg_write  <= 1'b0;
        end else if (!halted) begin

            // If data memory is busy, freeze the whole pipeline.
            if (!mem_wait) begin

                // ------------------------------
                // MEM/WB update
                // ------------------------------
                memwb_valid     <= exmem_valid;
                memwb_instr     <= exmem_instr;
                memwb_rd        <= exmem_rd;
                memwb_reg_write <= exmem_reg_write;

                if (exmem_mem_read) begin
                    memwb_wb_data <= dmem.rdata;
                end else begin
                    memwb_wb_data <= exmem_wb_data;
                end

                // ------------------------------
                // EX/MEM update
                // ------------------------------
                exmem_valid      <= idex_valid;
                exmem_instr      <= idex_instr;
                exmem_rd         <= idex_rd;
                exmem_alu_result <= alu_result;
                exmem_store_data <= fwd_rs2;
                exmem_wb_data    <= ex_wb_data;
                exmem_mem_read   <= idex_mem_read;
                exmem_mem_write  <= idex_mem_write;
                exmem_reg_write  <= idex_reg_write;
                exmem_wb_sel     <= idex_wb_sel;

                // ------------------------------
                // ID/EX update
                // ------------------------------
                if (branch_taken || load_use_stall) begin
                    idex_valid       <= 1'b0;
                    idex_instr       <= INSTR_NOP;
                    idex_mem_read    <= 1'b0;
                    idex_mem_write   <= 1'b0;
                    idex_reg_write   <= 1'b0;
                    idex_branch      <= 1'b0;
                    idex_jump        <= 1'b0;
                    idex_jalr        <= 1'b0;
                end else begin
                    idex_valid       <= ifid_valid;
                    idex_pc          <= ifid_pc;
                    idex_pc4         <= ifid_pc + 32'd4;
                    idex_instr       <= ifid_instr;
                    idex_rs1         <= id_rs1;
                    idex_rs2         <= id_rs2;
                    idex_rd          <= id_rd;
                    idex_funct3      <= id_funct3;
                    idex_rs1_val     <= id_rs1_val;
                    idex_rs2_val     <= id_rs2_val;
                    idex_imm         <= dec_imm;
                    idex_alu_op      <= dec_alu_op;
                    idex_alu_src_imm <= dec_alu_src_imm;
                    idex_op_a_pc     <= dec_op_a_pc;
                    idex_mem_read    <= dec_mem_read;
                    idex_mem_write   <= dec_mem_write;
                    idex_reg_write   <= dec_reg_write;
                    idex_wb_sel      <= dec_wb_sel;
                    idex_branch      <= dec_branch;
                    idex_jump        <= dec_jump;
                    idex_jalr        <= dec_jalr;
                end

                // ------------------------------
                // IF/ID and PC update
                // ------------------------------
                if (branch_taken) begin
                    pc          <= branch_target;
                    ifid_valid  <= 1'b0;
                    ifid_pc     <= 32'd0;
                    ifid_instr  <= INSTR_NOP;
                end else if (load_use_stall) begin
                    pc          <= pc;
                    ifid_valid  <= ifid_valid;
                    ifid_pc     <= ifid_pc;
                    ifid_instr  <= ifid_instr;
                end else begin
                    ifid_valid  <= 1'b1;
                    ifid_pc     <= pc;
                    ifid_instr  <= imem_rdata;
                    pc          <= pc + 32'd4;
                end
            end
        end
    end

endmodule