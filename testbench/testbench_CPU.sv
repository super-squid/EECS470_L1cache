`timescale 1ns/1ps

module riscv_cpu_test;

    localparam AW          = 32;
    localparam CPU_DW      = 32;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_DW    = BLOCK_BYTES * 8;

    logic clk;
    logic rst;

    initial begin
        clk = 1'b0;
    end

    always #5 clk = ~clk;

    dcache_if #(
        .AW(AW),
        .DW(CPU_DW)
    ) cpu_l1_if();

    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) l1_vc_if();

    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) vc_dram_if();

    logic [31:0] imem_addr;
    logic [31:0] imem_rdata;

    logic [31:0] instr_mem [0:255];

    assign imem_rdata = instr_mem[imem_addr[9:2]];

    logic halted;

    cpu #(
        .RESET_PC(32'h0000_0000)
    ) u_cpu (
        .clk        (clk),
        .rst        (rst),
        .imem_addr  (imem_addr),
        .imem_rdata (imem_rdata),
        .dmem       (cpu_l1_if.cpu),
        .halted     (halted)
    );

    logic                     evict_valid;
    logic [AW-1:0]            evict_addr;
    logic [BLOCK_DW-1:0]      evict_data;

    simple_dcache #(
        .AW          (AW),
        .DW          (CPU_DW),
        .CACHE_BYTES (256),
        .BLOCK_BYTES (BLOCK_BYTES),
        .ASSOC       (1)
    ) u_l1 (
        .clk         (clk),
        .rst         (rst),
        .cpu_if      (cpu_l1_if.mem),
        .mem_if      (l1_vc_if.cache_mem),
        .evict_valid (evict_valid),
        .evict_addr  (evict_addr),
        .evict_data  (evict_data)
    );

    victim_cache #(
        .AW           (AW),
        .BLOCK_BYTES  (BLOCK_BYTES),
        .NUM_VC_LINES (4)
    ) u_vc (
        .clk          (clk),
        .rst          (rst),
        .upstream     (l1_vc_if.dram),
        .downstream   (vc_dram_if.cache_mem),
        .evict_valid  (evict_valid),
        .evict_addr   (evict_addr),
        .evict_data   (evict_data)
    );

    dram_model #(
        .AW          (AW),
        .BLOCK_BYTES (BLOCK_BYTES),
        .READ_DELAY  (3)
    ) u_dram (
        .clk   (clk),
        .rst   (rst),
        .iface (vc_dram_if.dram)
    );

    function automatic logic [31:0] enc_i(
        input int imm,
        input int rs1,
        input int funct3,
        input int rd,
        input int opcode
    );
        enc_i = {
            imm[11:0],
            rs1[4:0],
            funct3[2:0],
            rd[4:0],
            opcode[6:0]
        };
    endfunction

    function automatic logic [31:0] enc_s(
        input int imm,
        input int rs2,
        input int rs1,
        input int funct3,
        input int opcode
    );
        enc_s = {
            imm[11:5],
            rs2[4:0],
            rs1[4:0],
            funct3[2:0],
            imm[4:0],
            opcode[6:0]
        };
    endfunction

    function automatic logic [31:0] enc_r(
        input int funct7,
        input int rs2,
        input int rs1,
        input int funct3,
        input int rd,
        input int opcode
    );
        enc_r = {
            funct7[6:0],
            rs2[4:0],
            rs1[4:0],
            funct3[2:0],
            rd[4:0],
            opcode[6:0]
        };
    endfunction

    localparam OPCODE_OP    = 7'h33;
    localparam OPCODE_OPIMM = 7'h13;
    localparam OPCODE_LOAD  = 7'h03;
    localparam OPCODE_STORE = 7'h23;

    localparam F3_ADD_SUB = 3'b000;
    localparam F3_LW      = 3'b010;
    localparam F3_SW      = 3'b010;

    localparam INSTR_NOP    = 32'h0000_0013;
    localparam INSTR_EBREAK = 32'h0010_0073;

    int cpu_load_done_count;
    int cpu_store_done_count;
    int dram_read_req_count;
    int dram_write_req_count;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            cpu_load_done_count  <= 0;
            cpu_store_done_count <= 0;
            dram_read_req_count  <= 0;
            dram_write_req_count <= 0;
        end else begin
            if (cpu_l1_if.req_valid && cpu_l1_if.ready && !cpu_l1_if.rw) begin
                cpu_load_done_count <= cpu_load_done_count + 1;
            end

            if (cpu_l1_if.req_valid && cpu_l1_if.ready && cpu_l1_if.rw) begin
                cpu_store_done_count <= cpu_store_done_count + 1;
            end

            if (vc_dram_if.req_valid && !vc_dram_if.rw) begin
                dram_read_req_count <= dram_read_req_count + 1;
            end

            if (vc_dram_if.req_valid && vc_dram_if.rw) begin
                dram_write_req_count <= dram_write_req_count + 1;
            end
        end
    end

    // Program:
    // load address 0
    // load address 256
    // reload address 0 from victim cache
    // reload address 256 from victim cache
    // store/load address 16
    // halt

    initial begin
        for (int i = 0; i < 256; i++) begin
            instr_mem[i] = INSTR_NOP;
        end

        instr_mem[0]  = enc_i(0,   0, F3_ADD_SUB, 1, OPCODE_OPIMM); // addi x1,x0,0
        instr_mem[1]  = enc_i(0,   1, F3_LW,      2, OPCODE_LOAD);  // lw x2,0(x1)

        instr_mem[2]  = enc_i(256, 0, F3_ADD_SUB, 3, OPCODE_OPIMM); // addi x3,x0,256
        instr_mem[3]  = enc_i(0,   3, F3_LW,      4, OPCODE_LOAD);  // lw x4,0(x3)

        instr_mem[4]  = enc_i(0,   1, F3_LW,      5, OPCODE_LOAD);  // lw x5,0(x1)
        instr_mem[5]  = enc_i(0,   3, F3_LW,      6, OPCODE_LOAD);  // lw x6,0(x3)

        instr_mem[6]  = enc_r(0,   5, 2, F3_ADD_SUB, 7, OPCODE_OP); // add x7,x2,x5

        instr_mem[7]  = enc_i(16,  0, F3_ADD_SUB, 8, OPCODE_OPIMM); // addi x8,x0,16
        instr_mem[8]  = enc_s(0,   5, 8, F3_SW,      OPCODE_STORE); // sw x5,0(x8)
        instr_mem[9]  = enc_i(0,   8, F3_LW,      9, OPCODE_LOAD);  // lw x9,0(x8)

        instr_mem[10] = INSTR_EBREAK;
    end

    initial begin
        rst = 1'b1;

        #1;

        // Simulation-only DRAM setup.
        // This is fine for behavioral simulation.

        u_dram.memory[0] = 8'h00;
        u_dram.memory[1] = 8'h11;
        u_dram.memory[2] = 8'h22;
        u_dram.memory[3] = 8'h33;

        u_dram.memory[256] = 8'hAA;
        u_dram.memory[257] = 8'hBB;
        u_dram.memory[258] = 8'hCC;
        u_dram.memory[259] = 8'hDD;

        repeat (5) @(posedge clk);
        rst = 1'b0;

        wait (halted);

        repeat (5) @(posedge clk);

        $display("CPU halted.");
        $display("x1  = %08x", u_cpu.regs[1]);
        $display("x2  = %08x", u_cpu.regs[2]);
        $display("x3  = %08x", u_cpu.regs[3]);
        $display("x4  = %08x", u_cpu.regs[4]);
        $display("x5  = %08x", u_cpu.regs[5]);
        $display("x6  = %08x", u_cpu.regs[6]);
        $display("x7  = %08x", u_cpu.regs[7]);
        $display("x8  = %08x", u_cpu.regs[8]);
        $display("x9  = %08x", u_cpu.regs[9]);
        $display("CPU completed loads  = %0d", cpu_load_done_count);
        $display("CPU completed stores = %0d", cpu_store_done_count);
        $display("DRAM read requests   = %0d", dram_read_req_count);
        $display("DRAM write requests  = %0d", dram_write_req_count);
        $display("DRAM[16..19]         = %02x %02x %02x %02x",
                 u_dram.memory[16],
                 u_dram.memory[17],
                 u_dram.memory[18],
                 u_dram.memory[19]);

        if (u_cpu.regs[2] !== 32'h3322_1100)
            $fatal(1, "FAIL: x2 expected 33221100, got %08x", u_cpu.regs[2]);

        if (u_cpu.regs[3] !== 32'h0000_0100)
            $fatal(1, "FAIL: x3 expected 00000100, got %08x", u_cpu.regs[3]);

        if (u_cpu.regs[4] !== 32'hDDCC_BBAA)
            $fatal(1, "FAIL: x4 expected DDCCBBAA, got %08x", u_cpu.regs[4]);

        if (u_cpu.regs[5] !== 32'h3322_1100)
            $fatal(1, "FAIL: x5 expected 33221100, got %08x", u_cpu.regs[5]);

        if (u_cpu.regs[6] !== 32'hDDCC_BBAA)
            $fatal(1, "FAIL: x6 expected DDCCBBAA, got %08x", u_cpu.regs[6]);

        if (u_cpu.regs[7] !== 32'h6644_2200)
            $fatal(1, "FAIL: x7 expected 66442200, got %08x", u_cpu.regs[7]);

        if (u_cpu.regs[8] !== 32'h0000_0010)
            $fatal(1, "FAIL: x8 expected 00000010, got %08x", u_cpu.regs[8]);

        if (u_cpu.regs[9] !== 32'h3322_1100)
            $fatal(1, "FAIL: x9 expected 33221100, got %08x", u_cpu.regs[9]);

        if (cpu_load_done_count != 5)
            $fatal(1, "FAIL: expected 5 completed loads, got %0d", cpu_load_done_count);

        if (cpu_store_done_count != 1)
            $fatal(1, "FAIL: expected 1 completed store, got %0d", cpu_store_done_count);

        if (dram_read_req_count != 3)
            $fatal(1, "FAIL: expected 3 DRAM reads, got %0d", dram_read_req_count);

        if (dram_write_req_count != 1)
            $fatal(1, "FAIL: expected 1 DRAM write, got %0d", dram_write_req_count);

        if (u_dram.memory[16] !== 8'h00 ||
            u_dram.memory[17] !== 8'h11 ||
            u_dram.memory[18] !== 8'h22 ||
            u_dram.memory[19] !== 8'h33) begin
            $fatal(1, "FAIL: DRAM store result incorrect.");
        end

        $display("PASS: CPU + dcache + victim cache + DRAM test passed.");
        $finish;
    end

    initial begin
        #50000;
        $fatal(1, "TIMEOUT: CPU did not halt.");
    end

endmodule