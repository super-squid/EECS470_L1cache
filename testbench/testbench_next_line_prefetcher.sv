`timescale 1ns/1ps

// Comprehensive baseline testbench for next_line_prefetcher.
//
// Topology:
//   L1-miss bus BFM -> next_line_prefetcher -> dram_model
//
// The BFM drives the same memory-side protocol used by simple_dcache: assert
// one aligned block request, deassert it, then wait until ready returns. This
// keeps the finished cache files untouched while still validating the module
// that plugs between simple_dcache.mem_if and dram_model.iface.

module testbench_next_line_prefetcher;

    localparam AW          = 32;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_BITS  = BLOCK_BYTES * 8;

    localparam [AW-1:0] ADDR_0        = 32'h0000_0000;
    localparam [AW-1:0] ADDR_1        = 32'h0000_0010;
    localparam [AW-1:0] ADDR_2        = 32'h0000_0020;
    localparam [AW-1:0] ADDR_4        = 32'h0000_0040;
    localparam [AW-1:0] ADDR_WRAP     = 32'h0000_00f0;
    localparam [AW-1:0] ADDR_STREAM_A = 32'h0000_0200;
    localparam [AW-1:0] ADDR_STREAM_B = 32'h0000_0210;

    logic clk, rst;

    initial clk = 1'b0;
    always #5 clk = ~clk;

    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) l1_pf_if();
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) pf_dram_if();

    logic                 pf_busy;
    logic                 pf_valid;
    logic [AW-1:0]        pf_addr;
    logic                 pf_issue_pulse;
    logic                 pf_fill_pulse;
    logic                 pf_hit_pulse;
    logic [31:0]          pf_issue_count;
    logic [31:0]          pf_fill_count;
    logic [31:0]          pf_hit_count;

    next_line_prefetcher #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES)
    ) pf (
        .clk(clk),
        .rst(rst),
        .upstream(l1_pf_if.dram),
        .downstream(pf_dram_if.cache_mem),
        .prefetch_busy(pf_busy),
        .prefetch_valid(pf_valid),
        .prefetch_addr(pf_addr),
        .prefetch_issue_pulse(pf_issue_pulse),
        .prefetch_fill_pulse(pf_fill_pulse),
        .prefetch_hit_pulse(pf_hit_pulse),
        .prefetch_issue_count(pf_issue_count),
        .prefetch_fill_count(pf_fill_count),
        .prefetch_hit_count(pf_hit_count)
    );

    dram_model #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES),
        .READ_DELAY(3)
    ) dram (
        .clk(clk),
        .rst(rst),
        .iface(pf_dram_if.dram)
    );

    int failures;

    function automatic logic [AW-1:0] block_align(input logic [AW-1:0] addr);
        block_align = {addr[AW-1:4], 4'b0000};
    endfunction

    function automatic logic [BLOCK_BITS-1:0] expected_block(input logic [AW-1:0] addr);
        logic [BLOCK_BITS-1:0] data;
        logic [AW-1:0] aligned;
        logic [AW-1:0] byte_addr;
        begin
            aligned = block_align(addr);
            data = '0;
            for (int i = 0; i < BLOCK_BYTES; i++) begin
                byte_addr = aligned + i;
                data[i*8 +: 8] = byte_addr[7:0];
            end
            expected_block = data;
        end
    endfunction

    function automatic logic [BLOCK_BITS-1:0] fill_block(input logic [7:0] value);
        logic [BLOCK_BITS-1:0] data;
        begin
            data = '0;
            for (int i = 0; i < BLOCK_BYTES; i++)
                data[i*8 +: 8] = value;
            fill_block = data;
        end
    endfunction

    task automatic check(input string name, input bit condition);
        if (condition) begin
            $display("PASS: %s", name);
        end else begin
            $display("FAIL: %s", name);
            failures++;
        end
    endtask

    task automatic bfm_read(input logic [AW-1:0] addr,
                            output logic [BLOCK_BITS-1:0] data,
                            output int cycles);
        cycles = 0;
        @(negedge clk);
        l1_pf_if.req_valid = 1'b1;
        l1_pf_if.rw        = 1'b0;
        l1_pf_if.addr      = block_align(addr);
        l1_pf_if.wdata     = '0;

        @(negedge clk);
        l1_pf_if.req_valid = 1'b0;

        do begin
            @(posedge clk);
            cycles++;
        end while (!l1_pf_if.ready);

        data = l1_pf_if.rdata;
    endtask

    task automatic bfm_write(input logic [AW-1:0] addr,
                             input logic [BLOCK_BITS-1:0] data,
                             output int cycles);
        cycles = 0;
        @(negedge clk);
        l1_pf_if.req_valid = 1'b1;
        l1_pf_if.rw        = 1'b1;
        l1_pf_if.addr      = block_align(addr);
        l1_pf_if.wdata     = data;

        @(negedge clk);
        l1_pf_if.req_valid = 1'b0;
        l1_pf_if.rw        = 1'b0;
        l1_pf_if.addr      = '0;
        l1_pf_if.wdata     = '0;

        do begin
            @(posedge clk);
            cycles++;
        end while (!l1_pf_if.ready);
    endtask

    task automatic wait_for_prefetch(input logic [AW-1:0] addr);
        int guard;
        begin
            guard = 0;
            while (!(pf_valid && pf_addr == block_align(addr)) && guard < 50) begin
                @(posedge clk);
                guard++;
            end
            check($sformatf("prefetch buffer holds 0x%08h", block_align(addr)),
                  pf_valid && pf_addr == block_align(addr));
        end
    endtask

    task automatic wait_for_idle();
        int guard;
        begin
            guard = 0;
            while (pf_busy && guard < 50) begin
                @(posedge clk);
                guard++;
            end
            check("prefetcher returns idle", !pf_busy);
        end
    endtask

    logic [BLOCK_BITS-1:0] rblock;
    logic [BLOCK_BITS-1:0] write_block;
    int cycles;
    int cold_cycles;
    int prefetched_cycles;
    int hit_count_before;
    int issue_count_before;
    int fill_count_before;

    initial begin
        $dumpfile("tb_next_line_prefetcher.vcd");
        $dumpvars(0, testbench_next_line_prefetcher);

        failures          = 0;
        l1_pf_if.req_valid = 1'b0;
        l1_pf_if.rw        = 1'b0;
        l1_pf_if.addr      = '0;
        l1_pf_if.wdata     = '0;

        rst = 1'b1;
        repeat (3) @(posedge clk);
        rst = 1'b0;
        @(posedge clk);

        $display("");
        $display("TEST 1: cold demand read should return DRAM data and launch next-line prefetch");
        bfm_read(ADDR_0, rblock, cold_cycles);
        check("ADDR_0 block data", rblock === expected_block(ADDR_0));
        wait_for_prefetch(ADDR_1);
        check("one prefetch issued after cold read", pf_issue_count == 32'd1);
        check("one prefetch filled after cold read", pf_fill_count == 32'd1);

        $display("");
        $display("TEST 2: read prefetched next line should be faster and chain another prefetch");
        hit_count_before = pf_hit_count;
        bfm_read(ADDR_1, rblock, prefetched_cycles);
        @(posedge clk);
        check("ADDR_1 block data from prefetch buffer", rblock === expected_block(ADDR_1));
        check("prefetch hit counter increments", pf_hit_count == hit_count_before + 1);
        check("prefetched refill is faster than cold miss", prefetched_cycles < cold_cycles);
        wait_for_prefetch(ADDR_2);

        $display("");
        $display("TEST 3: non-sequential miss replaces the buffered line with its own next line");
        bfm_read(ADDR_4, rblock, cycles);
        check("ADDR_4 block data", rblock === expected_block(ADDR_4));
        wait_for_prefetch(ADDR_4 + BLOCK_BYTES);
        check("old ADDR_2 buffer replaced", pf_addr == block_align(ADDR_4 + BLOCK_BYTES));

        $display("");
        $display("TEST 4: write to the buffered line invalidates the stale prefetch copy");
        bfm_read(ADDR_WRAP, rblock, cycles);
        wait_for_prefetch(ADDR_WRAP + BLOCK_BYTES);
        write_block = fill_block(8'hA5);
        bfm_write(ADDR_WRAP + BLOCK_BYTES, write_block, cycles);
        wait_for_idle();
        check("write completed", cycles > 0);
        check("matching prefetched line no longer valid",
              !(pf_valid && pf_addr == block_align(ADDR_WRAP + BLOCK_BYTES)));

        $display("");
        $display("TEST 5: read after write returns written block through normal memory path");
        bfm_read(ADDR_WRAP + BLOCK_BYTES, rblock, cycles);
        check("read-after-write block data", rblock === write_block);
        wait_for_prefetch(ADDR_WRAP + (2 * BLOCK_BYTES));

        $display("");
        $display("TEST 6: immediate next-line request while prefetch is in flight is captured");
        issue_count_before = pf_issue_count;
        fill_count_before  = pf_fill_count;
        bfm_read(ADDR_STREAM_A, rblock, cycles);
        check("new stream first read data", rblock === expected_block(ADDR_STREAM_A));
        bfm_read(ADDR_STREAM_B, rblock, cycles);
        check("new stream second read data", rblock === expected_block(ADDR_STREAM_B));
        wait_for_prefetch(ADDR_STREAM_B + BLOCK_BYTES);
        check("in-flight/prefetched path made progress", pf_issue_count > issue_count_before);
        check("fills continue after in-flight request", pf_fill_count >= fill_count_before + 1);

        $display("");
        $display("TEST 7: prefetch counters remain internally consistent");
        check("fills never exceed issues", pf_fill_count <= pf_issue_count);
        check("at least one prefetch hit happened", pf_hit_count > 0);

        $display("");
        $display("Prefetch issues=%0d fills=%0d hits=%0d",
                 pf_issue_count, pf_fill_count, pf_hit_count);

        if (failures == 0) begin
            $display("==============================================");
            $display("PASS: NEXT-LINE PREFETCHER TESTBENCH PASSED");
            $display("==============================================");
        end else begin
            $display("==============================================");
            $display("FAIL: %0d NEXT-LINE PREFETCHER TEST(S) FAILED", failures);
            $display("==============================================");
        end

        #20;
        $finish;
    end

    always @(posedge clk) begin
        if (pf_issue_pulse)
            $display("  [PF ISSUE] t=%0t addr=0x%08h", $time, pf_dram_if.addr);
        if (pf_fill_pulse)
            $display("  [PF FILL ] t=%0t addr=0x%08h", $time, pf.active_addr);
        if (pf_hit_pulse)
            $display("  [PF HIT  ] t=%0t", $time);
    end

endmodule
