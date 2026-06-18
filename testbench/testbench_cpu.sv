// testbench_cpu.sv
//
// Testbench module name: riscv_cpu_test
//
// Tests:
//   cpu + dcache_interface + dram_model
//
// This intentionally does NOT use simple_dcache or victim_cache yet.
// First we prove the CPU can talk to the most basic memory system.

`timescale 1ns/1ps

module riscv_cpu_test;

    localparam AW = 32;
    localparam DW = 32;

    logic clk;
    logic rst;

    // ------------------------------------------------------------
    // Clock
    // ------------------------------------------------------------

    initial begin
        clk = 1'b0;
    end

    always #5 clk = ~clk;

    // ------------------------------------------------------------
    // Data memory interface
    // ------------------------------------------------------------

    dcache_if #(
        .AW(AW),
        .DW(DW)
    ) dmem_if();

    // ------------------------------------------------------------
    // Instruction memory
    // ------------------------------------------------------------

    logic [31:0] imem_addr;
    logic [31:0] imem_rdata;

    logic [31:0] instr_mem [0:255];

    assign imem_rdata = instr_mem[imem_addr[9:2]];

    // ------------------------------------------------------------
    // CPU
    // ------------------------------------------------------------

    logic halted;

    cpu #(
        .RESET_PC(32'h0000_0000)
    ) u_cpu (
        .clk        (clk),
        .rst        (rst),
        .imem_addr  (imem_addr),
        .imem_rdata (imem_rdata),
        .dmem       (dmem_if.cpu),
        .halted     (halted)
    );

    // ------------------------------------------------------------
    // DRAM
    //
    // IMPORTANT:
    // BLOCK_BYTES must be 4 here because CPU data width is 32 bits.
    // ------------------------------------------------------------

    dram_model #(
        .AW          (AW),
        .BLOCK_BYTES (4),
        .READ_DELAY  (3)
    ) u_dram (
        .clk   (clk),
        .rst   (rst),
        .iface (dmem_if.dram)
    );

    // ------------------------------------------------------------
    // RISC-V instruction encoders
    // ------------------------------------------------------------

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

    // ------------------------------------------------------------
    // DRAM request counters
    // ------------------------------------------------------------

    int dram_read_count;
    int dram_write_count;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            dram_read_count  <= 0;
            dram_write_count <= 0;
        end else begin
            if (dmem_if.req_valid && !dmem_if.rw) begin
                dram_read_count <= dram_read_count + 1;
            end

            if (dmem_if.req_valid && dmem_if.rw) begin
                dram_write_count <= dram_write_count + 1;
            end
        end
    end

    // ------------------------------------------------------------
    // Program
    // ------------------------------------------------------------
    //
    // Data setup:
    //
    //   DRAM[0..3] = 78 56 34 12
    //
    // Because the DRAM model is little-endian for word assembly:
    //
    //   lw x2, 0(x1) gives x2 = 0x12345678
    //
    // Program:
    //
    //   addi x1, x0, 0
    //   lw   x2, 0(x1)
    //   addi x3, x2, 5
    //   addi x4, x0, 16
    //   sw   x3, 0(x4)
    //   lw   x5, 0(x4)
    //   add  x6, x2, x5
    //   ebreak
    //
    // Expected:
    //
    //   x1 = 0x00000000
    //   x2 = 0x12345678
    //   x3 = 0x1234567D
    //   x4 = 0x00000010
    //   x5 = 0x1234567D
    //   x6 = 0x2468ACF5
    //
    // This tests:
    //
    //   1. Instruction fetch
    //   2. ADDI
    //   3. LW from DRAM
    //   4. Load-use stall
    //   5. SW to DRAM
    //   6. LW after SW
    //   7. Register forwarding
    //   8. EBREAK halt
    //
    // ------------------------------------------------------------

    initial begin
        for (int i = 0; i < 256; i++) begin
            instr_mem[i] = INSTR_NOP;
        end

        instr_mem[0] = enc_i(0,  0, F3_ADD_SUB, 1, OPCODE_OPIMM); // addi x1, x0, 0
        instr_mem[1] = enc_i(0,  1, F3_LW,      2, OPCODE_LOAD);  // lw   x2, 0(x1)
        instr_mem[2] = enc_i(5,  2, F3_ADD_SUB, 3, OPCODE_OPIMM); // addi x3, x2, 5
        instr_mem[3] = enc_i(16, 0, F3_ADD_SUB, 4, OPCODE_OPIMM); // addi x4, x0, 16
        instr_mem[4] = enc_s(0,  3, 4, F3_SW,   OPCODE_STORE);    // sw   x3, 0(x4)
        instr_mem[5] = enc_i(0,  4, F3_LW,      5, OPCODE_LOAD);  // lw   x5, 0(x4)
        instr_mem[6] = enc_r(0,  5, 2, F3_ADD_SUB, 6, OPCODE_OP); // add  x6, x2, x5
        instr_mem[7] = INSTR_EBREAK;                              // ebreak
    end

    // ------------------------------------------------------------
    // Test sequence
    // ------------------------------------------------------------

    initial begin
        rst = 1'b1;

        // Let dram_model initial block initialize memory first.
        #1;

        // Initialize DRAM word at address 0 to 0x12345678.
        // Little-endian byte order.
        u_dram.memory[0] = 8'h78;
        u_dram.memory[1] = 8'h56;
        u_dram.memory[2] = 8'h34;
        u_dram.memory[3] = 8'h12;

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
        $display("DRAM reads  = %0d", dram_read_count);
        $display("DRAM writes = %0d", dram_write_count);
        $display("DRAM[16..19] = %02x %02x %02x %02x",
                 u_dram.memory[16],
                 u_dram.memory[17],
                 u_dram.memory[18],
                 u_dram.memory[19]);
        $display("--------------------------------------------------");

        if (u_cpu.regs[1] !== 32'h0000_0000) begin
            $fatal(1, "FAIL: x1 expected 00000000, got %08x", u_cpu.regs[1]);
        end

        if (u_cpu.regs[2] !== 32'h1234_5678) begin
            $fatal(1, "FAIL: x2 expected 12345678, got %08x", u_cpu.regs[2]);
        end

        if (u_cpu.regs[3] !== 32'h1234_567D) begin
            $fatal(1, "FAIL: x3 expected 1234567D, got %08x", u_cpu.regs[3]);
        end

        if (u_cpu.regs[4] !== 32'h0000_0010) begin
            $fatal(1, "FAIL: x4 expected 00000010, got %08x", u_cpu.regs[4]);
        end

        if (u_cpu.regs[5] !== 32'h1234_567D) begin
            $fatal(1, "FAIL: x5 expected 1234567D, got %08x", u_cpu.regs[5]);
        end

        if (u_cpu.regs[6] !== 32'h2468_ACF5) begin
            $fatal(1, "FAIL: x6 expected 2468ACF5, got %08x", u_cpu.regs[6]);
        end

        if (u_dram.memory[16] !== 8'h7D ||
            u_dram.memory[17] !== 8'h56 ||
            u_dram.memory[18] !== 8'h34 ||
            u_dram.memory[19] !== 8'h12) begin
            $fatal(1, "FAIL: DRAM store bytes are incorrect.");
        end

        if (dram_read_count != 2) begin
            $fatal(1, "FAIL: expected 2 DRAM reads, got %0d", dram_read_count);
        end

        if (dram_write_count != 1) begin
            $fatal(1, "FAIL: expected 1 DRAM write, got %0d", dram_write_count);
        end

        $display("PASS: riscv_cpu_test passed.");
        $finish;
    end

    // ------------------------------------------------------------
    // Timeout
    // ------------------------------------------------------------

    initial begin
        #20000;
        $fatal(1, "TIMEOUT: CPU did not halt.");
    end

endmodule