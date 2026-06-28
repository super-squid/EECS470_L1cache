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

    localparam INSTR_EBREAK  = 32'h0010_0073;
    localparam INSTR_NOP     = 32'h0000_0013;

    typedef enum logic [1:0] {
        S_FETCH,
        S_EXEC,
        S_MEM,
        S_HALT
    } state_t;

    state_t state;

    logic [31:0] pc;
    logic [31:0] instr;

    logic [31:0] regs [0:31];

    logic [31:0] mem_addr;
    logic [31:0] mem_wdata;
    logic [4:0]  mem_rd;
    logic        mem_write;
    logic        mem_load;

    logic        take_branch;

    assign imem_addr = pc;

    // Instruction fields
    logic [6:0] opcode;
    logic [4:0] rd;
    logic [2:0] funct3;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [6:0] funct7;

    assign opcode = instr[6:0];
    assign rd     = instr[11:7];
    assign funct3 = instr[14:12];
    assign rs1    = instr[19:15];
    assign rs2    = instr[24:20];
    assign funct7 = instr[31:25];

    logic [31:0] rs1_val;
    logic [31:0] rs2_val;

    assign rs1_val = (rs1 == 5'd0) ? 32'd0 : regs[rs1];
    assign rs2_val = (rs2 == 5'd0) ? 32'd0 : regs[rs2];

    // Immediate functions
    function automatic logic [31:0] imm_i(input logic [31:0] insn);
        imm_i = {{20{insn[31]}}, insn[31:20]};
    endfunction

    function automatic logic [31:0] imm_s(input logic [31:0] insn);
        imm_s = {{20{insn[31]}}, insn[31:25], insn[11:7]};
    endfunction

    function automatic logic [31:0] imm_b(input logic [31:0] insn);
        imm_b = {{19{insn[31]}}, insn[31], insn[7],
                 insn[30:25], insn[11:8], 1'b0};
    endfunction

    function automatic logic [31:0] imm_u(input logic [31:0] insn);
        imm_u = {insn[31:12], 12'b0};
    endfunction

    function automatic logic [31:0] imm_j(input logic [31:0] insn);
        imm_j = {{11{insn[31]}}, insn[31], insn[19:12],
                 insn[20], insn[30:21], 1'b0};
    endfunction

    // Data memory interface
    assign dmem.req_valid = (state == S_MEM);
    assign dmem.rw        = mem_write;
    assign dmem.addr      = mem_addr;
    assign dmem.wdata     = mem_wdata;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state     <= S_FETCH;
            pc        <= RESET_PC;
            instr     <= INSTR_NOP;

            mem_addr  <= 32'd0;
            mem_wdata <= 32'd0;
            mem_rd    <= 5'd0;
            mem_write <= 1'b0;
            mem_load  <= 1'b0;

            halted    <= 1'b0;
            take_branch <= 1'b0;

            for (int i = 0; i < 32; i++) begin
                regs[i] <= 32'd0;
            end
        end else begin
            regs[0] <= 32'd0;

            case (state)

                S_FETCH: begin
                    instr <= imem_rdata;
                    state <= S_EXEC;
                end

                S_EXEC: begin
                    if (instr == INSTR_EBREAK) begin
                        halted <= 1'b1;
                        state  <= S_HALT;
                    end else begin
                        case (opcode)

                            OPCODE_OP: begin
                                if (rd != 5'd0) begin
                                    case (funct3)
                                        3'b000: begin
                                            if (funct7 == 7'b0100000)
                                                regs[rd] <= rs1_val - rs2_val;
                                            else
                                                regs[rd] <= rs1_val + rs2_val;
                                        end

                                        3'b111: regs[rd] <= rs1_val & rs2_val;
                                        3'b110: regs[rd] <= rs1_val | rs2_val;
                                        3'b100: regs[rd] <= rs1_val ^ rs2_val;

                                        3'b010: regs[rd] <= ($signed(rs1_val) < $signed(rs2_val)) ? 32'd1 : 32'd0;
                                        3'b011: regs[rd] <= (rs1_val < rs2_val) ? 32'd1 : 32'd0;

                                        3'b001: regs[rd] <= rs1_val << rs2_val[4:0];

                                        3'b101: begin
                                            if (funct7 == 7'b0100000)
                                                regs[rd] <= $signed(rs1_val) >>> rs2_val[4:0];
                                            else
                                                regs[rd] <= rs1_val >> rs2_val[4:0];
                                        end

                                        default: regs[rd] <= 32'd0;
                                    endcase
                                end

                                pc    <= pc + 32'd4;
                                state <= S_FETCH;
                            end

                            OPCODE_OPIMM: begin
                                if (rd != 5'd0) begin
                                    case (funct3)
                                        3'b000: regs[rd] <= rs1_val + imm_i(instr);
                                        3'b111: regs[rd] <= rs1_val & imm_i(instr);
                                        3'b110: regs[rd] <= rs1_val | imm_i(instr);
                                        3'b100: regs[rd] <= rs1_val ^ imm_i(instr);

                                        3'b010: regs[rd] <= ($signed(rs1_val) < $signed(imm_i(instr))) ? 32'd1 : 32'd0;
                                        3'b011: regs[rd] <= (rs1_val < imm_i(instr)) ? 32'd1 : 32'd0;

                                        3'b001: regs[rd] <= rs1_val << instr[24:20];

                                        3'b101: begin
                                            if (instr[30])
                                                regs[rd] <= $signed(rs1_val) >>> instr[24:20];
                                            else
                                                regs[rd] <= rs1_val >> instr[24:20];
                                        end

                                        default: regs[rd] <= 32'd0;
                                    endcase
                                end

                                pc    <= pc + 32'd4;
                                state <= S_FETCH;
                            end

                            OPCODE_LOAD: begin
                                // LW only
                                if (funct3 == 3'b010) begin
                                    mem_addr  <= rs1_val + imm_i(instr);
                                    mem_wdata <= 32'd0;
                                    mem_rd    <= rd;
                                    mem_write <= 1'b0;
                                    mem_load  <= 1'b1;
                                    state     <= S_MEM;
                                end else begin
                                    pc    <= pc + 32'd4;
                                    state <= S_FETCH;
                                end
                            end

                            OPCODE_STORE: begin
                                // SW only
                                if (funct3 == 3'b010) begin
                                    mem_addr  <= rs1_val + imm_s(instr);
                                    mem_wdata <= rs2_val;
                                    mem_rd    <= 5'd0;
                                    mem_write <= 1'b1;
                                    mem_load  <= 1'b0;
                                    state     <= S_MEM;
                                end else begin
                                    pc    <= pc + 32'd4;
                                    state <= S_FETCH;
                                end
                            end

                            OPCODE_BRANCH: begin
                                take_branch = 1'b0;

                                case (funct3)
                                    3'b000: take_branch = (rs1_val == rs2_val);
                                    3'b001: take_branch = (rs1_val != rs2_val);
                                    3'b100: take_branch = ($signed(rs1_val) <  $signed(rs2_val));
                                    3'b101: take_branch = ($signed(rs1_val) >= $signed(rs2_val));
                                    3'b110: take_branch = (rs1_val <  rs2_val);
                                    3'b111: take_branch = (rs1_val >= rs2_val);
                                    default: take_branch = 1'b0;
                                endcase

                                if (take_branch)
                                    pc <= pc + imm_b(instr);
                                else
                                    pc <= pc + 32'd4;

                                state <= S_FETCH;
                            end

                            OPCODE_LUI: begin
                                if (rd != 5'd0)
                                    regs[rd] <= imm_u(instr);

                                pc    <= pc + 32'd4;
                                state <= S_FETCH;
                            end

                            OPCODE_AUIPC: begin
                                if (rd != 5'd0)
                                    regs[rd] <= pc + imm_u(instr);

                                pc    <= pc + 32'd4;
                                state <= S_FETCH;
                            end

                            OPCODE_JAL: begin
                                if (rd != 5'd0)
                                    regs[rd] <= pc + 32'd4;

                                pc    <= pc + imm_j(instr);
                                state <= S_FETCH;
                            end

                            OPCODE_JALR: begin
                                if (rd != 5'd0)
                                    regs[rd] <= pc + 32'd4;

                                pc    <= (rs1_val + imm_i(instr)) & 32'hffff_fffe;
                                state <= S_FETCH;
                            end

                            OPCODE_SYSTEM: begin
                                if (instr == INSTR_EBREAK) begin
                                    halted <= 1'b1;
                                    state  <= S_HALT;
                                end else begin
                                    pc    <= pc + 32'd4;
                                    state <= S_FETCH;
                                end
                            end

                            default: begin
                                pc    <= pc + 32'd4;
                                state <= S_FETCH;
                            end
                        endcase
                    end
                end

                S_MEM: begin
                    if (dmem.ready) begin
                        if (mem_load && !mem_write && mem_rd != 5'd0) begin
                            regs[mem_rd] <= dmem.rdata;
                        end

                        pc    <= pc + 32'd4;
                        state <= S_FETCH;
                    end
                end

                S_HALT: begin
                    halted <= 1'b1;
                    state  <= S_HALT;
                end

                default: begin
                    state <= S_FETCH;
                end
            endcase
        end
    end

endmodule