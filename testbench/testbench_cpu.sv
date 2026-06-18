// testbench_cpu.sv
`timescale 1ns/1ps

module riscv_cpu_test;

    localparam AW          = 32;
    localparam CPU_DW      = 32;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_DW    = BLOCK_BYTES * 8;

    logic clk;
    logic rst;

    // clk
    initial begin
        clk = 1'b0;
    end

    always #5 clk = ~clk;

    // module connection interfaces
    // CPU & L1 cache: 32-bit word interface
    dcache_if #(
        .AW(AW),
        .DW(CPU_DW)
    ) cpu_l1_if();

    // L1 cache & victim cache: 16-byte block interface
    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) l1_vc_if();

    // Victim cache & DRAM: 16-byte block interface
    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) vc_dram_if();

    // memory to store instructions
    logic [31:0] imem_addr;
    logic [31:0] imem_rdata;

    logic [31:0] instr_mem [0:255];

    assign imem_rdata = instr_mem[imem_addr[9:2]];

    // initiate CPU
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

    // initiate L1 Cache
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

    // victim cache
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

    //DRAM
    dram_model #(
        .AW          (AW),
        .BLOCK_BYTES (BLOCK_BYTES),
        .READ_DELAY  (3)
    ) u_dram (
        .clk   (clk),
        .rst   (rst),
        .iface (vc_dram_if.dram)
    );

    // RISCV instruction encoder
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

    // counter
    int cpu_load_count;
    int cpu_store_count;
    int dram_read_count;
    int dram_write_count;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            cpu_load_count   <= 0;
            cpu_store_count  <= 0;
            dram_read_count  <= 0;
            dram_write_count <= 0;
        end else begin
            if (cpu_l1_if.req_valid && !cpu_l1_if.rw) begin
                cpu_load_count <= cpu_load_count + 1;
            end

            if (cpu_l1_if.req_valid && cpu_l1_if.rw) begin
                cpu_store_count <= cpu_store_count + 1;
            end

            if (vc_dram_if.req_valid && !vc_dram_if.rw) begin
                dram_read_count <= dram_read_count + 1;
            end

            if (vc_dram_if.req_valid && vc_dram_if.rw) begin
                dram_write_count <= dram_write_count + 1;
            end
        end
    end

    // ------------------------------------------------------------
    // Program used to test the modules
    // ------------------------------------------------------------
    //
    // L1 configuration:
    //   CACHE_BYTES = 256
    //   BLOCK_BYTES = 16
    //   ASSOC       = 1
    //
    // Address 0x00000000 and 0x00000100 map to the same L1 index.
    //
    // Data setup:
    //
    //   DRAM[0..3]       = 00 11 22 33
    //   LW address 0     = 0x33221100
    //
    //   DRAM[256..259]   = AA BB CC DD
    //   LW address 256   = 0xDDCCBBAA
    //
    // Program:
    //
    //   addi x1, x0, 0
    //   lw   x2, 0(x1)        ; L1 miss, DRAM read block 0
    //
    //   addi x6, x0, 256
    //   lw   x3, 0(x6)        ; conflict miss, DRAM read block 256
    //                         ; evicts block 0 into victim cache
    //
    //   lw   x4, 0(x1)        ; L1 miss, victim cache hit for block 0
    //   lw   x5, 0(x6)        ; L1 miss, victim cache hit for block 256
    //
    //   add  x7, x2, x5       ; x7 = 0x33221100 + 0xDDCCBBAA
    //
    //   addi x8, x0, 16
    //   sw   x4, 0(x8)        ; store 0x33221100 to address 16
    //   lw   x9, 0(x8)        ; load back stored value
    //
    //   ebreak
    //
    // Expected:
    //
    //   x2 = 0x33221100
    //   x3 = 0xDDCCBBAA
    //   x4 = 0x33221100
    //   x5 = 0xDDCCBBAA
    //   x6 = 0x00000100
    //   x7 = 0x10EECCAA
    //   x8 = 0x00000010
    //   x9 = 0x33221100
    //
    // Expected memory counts:
    //
    //   CPU loads   = 5
    //   CPU stores  = 1
    //   DRAM reads  = 3
    //   DRAM writes = 1
    //
    // Why DRAM reads = 3?
    //   1. load address 0
    //   2. load address 256
    //   3. write miss at address 16 performs write-allocate refill
    //
    // The two later conflict loads should hit in victim cache, not DRAM.
    // ------------------------------------------------------------

    initial begin
        for (int i = 0; i < 256; i++) begin
            instr_mem[i] = INSTR_NOP;
        end

        instr_mem[0]  = enc_i(0,   0, F3_ADD_SUB, 1, OPCODE_OPIMM); // addi x1, x0, 0
        instr_mem[1]  = enc_i(0,   1, F3_LW,      2, OPCODE_LOAD);  // lw   x2, 0(x1)

        instr_mem[2]  = enc_i(256, 0, F3_ADD_SUB, 6, OPCODE_OPIMM); // addi x6, x0, 256
        instr_mem[3]  = enc_i(0,   6, F3_LW,      3, OPCODE_LOAD);  // lw   x3, 0(x6)

        instr_mem[4]  = enc_i(0,   1, F3_LW,      4, OPCODE_LOAD);  // lw   x4, 0(x1)
        instr_mem[5]  = enc_i(0,   6, F3_LW,      5, OPCODE_LOAD);  // lw   x5, 0(x6)

        instr_mem[6]  = enc_r(0,   5, 2, F3_ADD_SUB, 7, OPCODE_OP); // add  x7, x2, x5

        instr_mem[7]  = enc_i(16,  0, F3_ADD_SUB, 8, OPCODE_OPIMM); // addi x8, x0, 16
        instr_mem[8]  = enc_s(0,   4, 8, F3_SW,      OPCODE_STORE); // sw   x4, 0(x8)
        instr_mem[9]  = enc_i(0,   8, F3_LW,      9, OPCODE_LOAD);  // lw   x9, 0(x8)

        instr_mem[10] = INSTR_EBREAK;                               // ebreak
    end

    // ------------------------------------------------------------
    // Test sequence
    // ------------------------------------------------------------

    initial begin
        rst = 1'b1;

        // Let dram_model's initial block run first.
        #1;

        // Word at address 0 = 0x33221100.
        // Little-endian byte order.
        u_dram.memory[0] = 8'h00;
        u_dram.memory[1] = 8'h11;
        u_dram.memory[2] = 8'h22;
        u_dram.memory[3] = 8'h33;

        // Word at address 256 = 0xDDCCBBAA.
        // Little-endian byte order.
        u_dram.memory[256] = 8'hAA;
        u_dram.memory[257] = 8'hBB;
        u_dram.memory[258] = 8'hCC;
        u_dram.memory[259] = 8'hDD;

        repeat (5) @(posedge clk);
        rst = 1'b0;

        wait (halted);

        repeat (5) @(posedge clk);

        $display("--------------------------------------------------");
        $display("CPU halted.");
        $display("x1 = %08x", u_cpu.regs[1]);
        $display("x2 = %08x", u_cpu.regs[2]);
        $display("x3 = %08x", u_cpu.regs[3]);
        $display("x4 = %08x", u_cpu.regs[4]);
        $display("x5 = %08x", u_cpu.regs[5]);
        $display("x6 = %08x", u_cpu.regs[6]);
        $display("x7 = %08x", u_cpu.regs[7]);
        $display("x8 = %08x", u_cpu.regs[8]);
        $display("x9 = %08x", u_cpu.regs[9]);
        $display("CPU load requests  = %0d", cpu_load_count);
        $display("CPU store requests = %0d", cpu_store_count);
        $display("DRAM reads         = %0d", dram_read_count);
        $display("DRAM writes        = %0d", dram_write_count);
        $display("DRAM[16..19]       = %02x %02x %02x %02x",
                 u_dram.memory[16],
                 u_dram.memory[17],
                 u_dram.memory[18],
                 u_dram.memory[19]);
        $display("--------------------------------------------------");

        if (u_cpu.regs[2] !== 32'h3322_1100) begin
            $fatal(1, "FAIL: x2 expected 33221100, got %08x", u_cpu.regs[2]);
        end

        if (u_cpu.regs[3] !== 32'hDDCC_BBAA) begin
            $fatal(1, "FAIL: x3 expected DDCCBBAA, got %08x", u_cpu.regs[3]);
        end

        if (u_cpu.regs[4] !== 32'h3322_1100) begin
            $fatal(1, "FAIL: x4 expected 33221100, got %08x", u_cpu.regs[4]);
        end

        if (u_cpu.regs[5] !== 32'hDDCC_BBAA) begin
            $fatal(1, "FAIL: x5 expected DDCCBBAA, got %08x", u_cpu.regs[5]);
        end

        if (u_cpu.regs[6] !== 32'h0000_0100) begin
            $fatal(1, "FAIL: x6 expected 00000100, got %08x", u_cpu.regs[6]);
        end

        if (u_cpu.regs[7] !== 32'h10EE_CCAA) begin
            $fatal(1, "FAIL: x7 expected 10EECCAA, got %08x", u_cpu.regs[7]);
        end

        if (u_cpu.regs[8] !== 32'h0000_0010) begin
            $fatal(1, "FAIL: x8 expected 00000010, got %08x", u_cpu.regs[8]);
        end

        if (u_cpu.regs[9] !== 32'h3322_1100) begin
            $fatal(1, "FAIL: x9 expected 33221100, got %08x", u_cpu.regs[9]);
        end

        if (u_dram.memory[16] !== 8'h00 ||
            u_dram.memory[17] !== 8'h11 ||
            u_dram.memory[18] !== 8'h22 ||
            u_dram.memory[19] !== 8'h33) begin
            $fatal(1, "FAIL: DRAM store bytes incorrect.");
        end

        if (cpu_load_count != 5) begin
            $fatal(1, "FAIL: expected 5 CPU load requests, got %0d", cpu_load_count);
        end

        if (cpu_store_count != 1) begin
            $fatal(1, "FAIL: expected 1 CPU store request, got %0d", cpu_store_count);
        end

        if (dram_read_count != 3) begin
            $fatal(1, "FAIL: expected 3 DRAM reads, got %0d", dram_read_count);
        end

        if (dram_write_count != 1) begin
            $fatal(1, "FAIL: expected 1 DRAM write, got %0d", dram_write_count);
        end

        $display("PASS: CPU + simple_dcache + victim_cache + DRAM test passed.");
        $finish;
    end

    // ------------------------------------------------------------
    // Timeout
    // ------------------------------------------------------------

    initial begin
        #50000;
        $fatal(1, "TIMEOUT: CPU did not halt.");
    end

endmodule