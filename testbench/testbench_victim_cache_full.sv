`timescale 1ns/1ps

// Comprehensive victim cache testbench.
//
// Cache geometry (CACHE_BYTES=256, BLOCK_BYTES=16, ASSOC=1):
//   OFFSET_BITS=4  INDEX_BITS=4  L1_TAG_BITS=24  VC_TAG_BITS=28 (addr[31:4])
//   16 L1 sets, direct-mapped.  4-entry fully-associative VC.
//
// Address convention used in this file:
//   tag-0 block for set s  =  s * 0x10  (e.g. set 0 = 0x000, set 1 = 0x010)
//   tag-1 block for set s  =  0x100 + s * 0x10  (conflict address, same index, different L1 tag)
//
// DRAM pre-init: memory[i] = i[7:0].
//   Word-0 at block-aligned addr A = {(A+3)[7:0], (A+2)[7:0], (A+1)[7:0], A[7:0]}.
//
// Cycle-count conventions with READ_DELAY=2:
//   L1 hit   = 1 cycle   (combinatorial from IDLE)
//   VC hit   = 2 cycles  (one pipeline stage through VC_HIT state)
//   DRAM     = 4 cycles  (1 request + 2 READ_DELAY + 1 capture)
//
// Test phases:
//   1. Cold-fill all 16 L1 sets from DRAM.  VC stays empty.
//   2. Conflict-miss sets 0-3: evict tag-0 lines into VC (fills VC).
//   3. 5th conflict miss (set 4): VC full, LRU evicts vc[3]=0x000 to make room.
//   4. VC-hit reads for retained entries (0x010, 0x020, 0x030, 0x040): 2 cycles each.
//   5. Read 0x000: not in VC (LRU-evicted in phase 3) -> DRAM, 4 cycles.

module testbench_victim_cache_full;

    localparam AW          = 32;
    localparam DW          = 32;
    localparam CACHE_BYTES = 256;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_BITS  = BLOCK_BYTES * 8;   // 128
    localparam NUM_SETS    = CACHE_BYTES / BLOCK_BYTES;  // 16 L1 sets
    localparam NUM_VC      = 4;
    localparam OB          = 4;   // OFFSET_BITS = log2(BLOCK_BYTES)

    // Expected word-0 value for any block-aligned addr using DRAM init formula.
    function automatic [DW-1:0] exp_word(input [AW-1:0] a);
        return {8'(a + 3), 8'(a + 2), 8'(a + 1), 8'(a)};
    endfunction

    logic clk, rst;
    initial clk = 0;
    always #5 clk = ~clk;

    // Interfaces
    dcache_if #(.AW(AW), .DW(DW))         cpu_if();
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) l1_vc_if();
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) vc_dram_if();

    logic                  evict_valid;
    logic [AW-1:0]         evict_addr;
    logic [BLOCK_BITS-1:0] evict_data;

    simple_dcache #(.AW(AW), .DW(DW), .CACHE_BYTES(CACHE_BYTES), .BLOCK_BYTES(BLOCK_BYTES)) l1 (
        .clk(clk), .rst(rst),
        .cpu_if(cpu_if.cpu), .mem_if(l1_vc_if.cache_mem),
        .evict_valid(evict_valid), .evict_addr(evict_addr), .evict_data(evict_data)
    );

    victim_cache #(.AW(AW), .BLOCK_BYTES(BLOCK_BYTES), .NUM_VC_LINES(NUM_VC)) vc (
        .clk(clk), .rst(rst),
        .upstream(l1_vc_if.dram), .downstream(vc_dram_if.cache_mem),
        .evict_valid(evict_valid), .evict_addr(evict_addr), .evict_data(evict_data)
    );

    dram_model #(.AW(AW), .BLOCK_BYTES(BLOCK_BYTES), .READ_DELAY(2)) dram (
        .clk(clk), .rst(rst), .iface(vc_dram_if.dram)
    );

    // Read task: waits for cpu_if.ready, returns data and cycle count.
    task automatic do_read(input [AW-1:0] addr, output [DW-1:0] data, output int cyc);
        @(negedge clk);
        cpu_if.req_valid = 1'b1;
        cpu_if.rw        = 1'b0;
        cpu_if.addr      = addr;
        cpu_if.wdata     = '0;
        cyc = 0;
        do begin @(posedge clk); cyc++; end while (!cpu_if.ready);
        data = cpu_if.rdata;
        @(negedge clk);
        cpu_if.req_valid = 1'b0;
    endtask

    task print_vc;
        for (int i = 0; i < NUM_VC; i++) begin
            if (vc.vc[i].valid)
                $display("      vc[%0d] tag=0x%07h (block addr=0x%08h)",
                    i, vc.vc[i].tag, {vc.vc[i].tag, 4'b0});
            else
                $display("      vc[%0d] empty", i);
        end
    endtask

    logic [DW-1:0] rdata;
    int cyc, failures;

    initial begin
        $dumpfile("tb_vc_full.vcd");
        $dumpvars(0, testbench_victim_cache_full);

        failures = 0;
        cpu_if.req_valid = 0; cpu_if.rw = 0; cpu_if.addr = '0; cpu_if.wdata = '0;
        rst = 1'b1;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        @(posedge clk);

        // ============================================================
        // PHASE 1: Cold-fill all 16 L1 sets.
        // Each access: L1 miss -> VC miss -> DRAM (4 cycles).
        // No evictions (L1 was invalid), VC stays empty throughout.
        // ============================================================
        $display("=== PHASE 1: Cold-fill all %0d L1 sets from DRAM ===", NUM_SETS);
        for (int s = 0; s < NUM_SETS; s++) begin
            automatic logic [AW-1:0] addr = s << OB;   // 0x000, 0x010, ..., 0x0F0
            automatic logic [DW-1:0] exp  = exp_word(addr);
            do_read(addr, rdata, cyc);
            if (rdata !== exp) begin
                $display("  FAIL set %0d addr=0x%08h: data 0x%08h != expected 0x%08h",
                    s, addr, rdata, exp);
                failures++;
            end else if (cyc !== 4) begin
                $display("  FAIL set %0d addr=0x%08h: %0d cycles, expected 4 (DRAM)", s, addr, cyc);
                failures++;
            end
        end
        $display("  All 16 L1 sets filled. VC state (should be fully empty):");
        print_vc();
        if (vc.vc[0].valid || vc.vc[1].valid || vc.vc[2].valid || vc.vc[3].valid) begin
            $display("  FAIL: VC should be empty after cold fills (no valid lines were displaced)");
            failures++;
        end else
            $display("  PASS: all 16 cold misses -> DRAM (4 cycles), VC empty");

        // ============================================================
        // PHASE 2: Conflict-miss first 4 sets to fill the VC.
        //
        // Each conflict address (tag=1) maps to the same L1 index as the
        // tag=0 line loaded in Phase 1.  The tag=0 line is displaced from
        // L1 and written into the victim cache via evict_valid.
        //
        // LRU victim sequence (VC ages start at [0,1,2,3]):
        //   eviction 1 (addr 0x000) -> victim_way=3  -> vc[3]=0x000, new ages [1,2,3,0]
        //   eviction 2 (addr 0x010) -> victim_way=2  -> vc[2]=0x010, new ages [2,3,0,1]
        //   eviction 3 (addr 0x020) -> victim_way=1  -> vc[1]=0x020, new ages [3,0,1,2]
        //   eviction 4 (addr 0x030) -> victim_way=0  -> vc[0]=0x030, new ages [0,1,2,3]
        //   -> VC full; vc[3]=0x000 is the new LRU victim (age=3 again).
        // ============================================================
        $display("");
        $display("=== PHASE 2: Conflict-miss sets 0-3 to fill all 4 VC entries ===");
        for (int s = 0; s < NUM_VC; s++) begin
            automatic logic [AW-1:0] conf = 32'h100 + (s << OB); // 0x100,0x110,0x120,0x130
            automatic logic [DW-1:0] exp  = exp_word(conf);
            do_read(conf, rdata, cyc);
            if (rdata !== exp || cyc !== 4) begin
                $display("  FAIL set %0d conflict 0x%08h: rdata=0x%08h exp=0x%08h cyc=%0d",
                    s, conf, rdata, exp, cyc);
                failures++;
            end
        end
        $display("  VC state after 4 conflict misses (should hold 0x000,0x010,0x020,0x030):");
        print_vc();
        // After 4 evictions LRU cycles fill vc[3..0] in that order.
        begin
            int ok = 1;
            if (!vc.vc[3].valid || vc.vc[3].tag !== 28'h0000000) begin
                $display("  FAIL: vc[3] should hold addr 0x000 (tag=0x0000000)"); ok=0; failures++;
            end
            if (!vc.vc[2].valid || vc.vc[2].tag !== 28'h0000001) begin
                $display("  FAIL: vc[2] should hold addr 0x010 (tag=0x0000001)"); ok=0; failures++;
            end
            if (!vc.vc[1].valid || vc.vc[1].tag !== 28'h0000002) begin
                $display("  FAIL: vc[1] should hold addr 0x020 (tag=0x0000002)"); ok=0; failures++;
            end
            if (!vc.vc[0].valid || vc.vc[0].tag !== 28'h0000003) begin
                $display("  FAIL: vc[0] should hold addr 0x030 (tag=0x0000003)"); ok=0; failures++;
            end
            if (ok) $display("  PASS: VC correctly filled with 4 evicted lines");
        end

        // ============================================================
        // PHASE 3: 5th conflict miss -- VC full, LRU replacement inside VC.
        //
        // Reading 0x140 (set 4, tag=1) misses in L1 and VC, goes to DRAM.
        // When DRAM returns, addr 0x040 (tag=0 line currently in L1[4]) is
        // displaced into VC.  VC is full: current LRU victim is vc[3] (holds
        // addr 0x000, age=3).  vc[3] is overwritten; addr 0x000 is
        // permanently lost from the victim cache.
        //
        // After this eviction (touch way 3, old_age=3):
        //   ages: [0,1,2,3] -> way3=0; ways 0,1,2 (ages 0,1,2 < 3) += 1
        //   new ages: [1,2,3,0]  -> new LRU victim = vc[2] (age=3).
        // ============================================================
        $display("");
        $display("=== PHASE 3: 5th conflict miss — LRU replacement inside full VC ===");
        do_read(32'h140, rdata, cyc);
        $display("  0x00000140 -> %0d cycles, rdata=0x%08h", cyc, rdata);
        if (cyc !== 4) begin
            $display("  FAIL: expected DRAM path (4 cycles), got %0d", cyc); failures++;
        end
        $display("  VC state (vc[3] should now hold addr 0x040; addr 0x000 is gone):");
        print_vc();
        begin
            int ok = 1;
            if (!vc.vc[3].valid || vc.vc[3].tag !== 28'h0000004) begin
                $display("  FAIL: vc[3] should hold addr 0x040 (tag=0x0000004, = 0x40>>4)");
                ok=0; failures++;
            end
            if (vc.vc[3].valid && vc.vc[3].tag === 28'h0000000) begin
                $display("  FAIL: vc[3] still holds addr 0x000 (LRU eviction did not occur)");
                ok=0; failures++;
            end
            if (!vc.vc[2].valid || vc.vc[2].tag !== 28'h0000001) begin
                $display("  FAIL: vc[2] (0x010) should be unchanged"); ok=0; failures++;
            end
            if (!vc.vc[1].valid || vc.vc[1].tag !== 28'h0000002) begin
                $display("  FAIL: vc[1] (0x020) should be unchanged"); ok=0; failures++;
            end
            if (!vc.vc[0].valid || vc.vc[0].tag !== 28'h0000003) begin
                $display("  FAIL: vc[0] (0x030) should be unchanged"); ok=0; failures++;
            end
            if (ok) $display("  PASS: vc[3] replaced with 0x040; 0x000 evicted from VC by LRU");
        end

        // ============================================================
        // PHASE 4: VC-hit reads for the 4 entries retained in VC.
        //
        // After Phase 3 the VC holds (ages in brackets):
        //   vc[3]=0x040 [0=MRU]  vc[2]=0x010 [3=LRU]  vc[1]=0x020 [2]  vc[0]=0x030 [1]
        //
        // Reading 0x010 hits vc[2] (2 cycles).  The displaced L1 line (0x110)
        // is evicted into vc[2] (victim_way==hit_way, last-write-wins in NBA).
        // Similarly for 0x020->vc[1], 0x030->vc[0], 0x040->vc[3].
        //
        // The important check is cycle count == 2 (VC path, not DRAM).
        // ============================================================
        $display("");
        $display("=== PHASE 4: VC-hit reads for retained entries (expect 2 cycles each) ===");
        begin
            // 0x010 in vc[2]
            do_read(32'h010, rdata, cyc);
            $display("  0x00000010 -> %0d cycles  rdata=0x%08h  exp=0x%08h",
                cyc, rdata, exp_word(32'h010));
            if (cyc !== 2 || rdata !== exp_word(32'h010)) begin
                $display("  FAIL: VC hit expected"); failures++;
            end else $display("  PASS");
        end
        begin
            // 0x020 in vc[1]
            do_read(32'h020, rdata, cyc);
            $display("  0x00000020 -> %0d cycles  rdata=0x%08h  exp=0x%08h",
                cyc, rdata, exp_word(32'h020));
            if (cyc !== 2 || rdata !== exp_word(32'h020)) begin
                $display("  FAIL: VC hit expected"); failures++;
            end else $display("  PASS");
        end
        begin
            // 0x030 in vc[0]
            do_read(32'h030, rdata, cyc);
            $display("  0x00000030 -> %0d cycles  rdata=0x%08h  exp=0x%08h",
                cyc, rdata, exp_word(32'h030));
            if (cyc !== 2 || rdata !== exp_word(32'h030)) begin
                $display("  FAIL: VC hit expected"); failures++;
            end else $display("  PASS");
        end
        begin
            // 0x040 in vc[3]
            do_read(32'h040, rdata, cyc);
            $display("  0x00000040 -> %0d cycles  rdata=0x%08h  exp=0x%08h",
                cyc, rdata, exp_word(32'h040));
            if (cyc !== 2 || rdata !== exp_word(32'h040)) begin
                $display("  FAIL: VC hit expected"); failures++;
            end else $display("  PASS");
        end

        // ============================================================
        // PHASE 5: LRU-evicted entry (0x000) must come from DRAM, not VC.
        //
        // addr 0x000 was in vc[3] but was overwritten in Phase 3 when VC
        // was full and the 5th eviction arrived.  Reading it now must miss
        // in both L1 (which holds 0x100 at index 0) and VC -> DRAM (4 cyc).
        // ============================================================
        $display("");
        $display("=== PHASE 5: Verify LRU-evicted 0x000 is no longer in VC (DRAM miss) ===");
        do_read(32'h000, rdata, cyc);
        $display("  0x00000000 -> %0d cycles  rdata=0x%08h  exp=0x%08h",
            cyc, rdata, exp_word(32'h0));
        if (cyc !== 4 || rdata !== exp_word(32'h0)) begin
            $display("  FAIL: expected DRAM (4 cycles); got %0d cycles, rdata=0x%08h",
                cyc, rdata);
            failures++;
        end else
            $display("  PASS: 0x000 correctly fetched from DRAM (not in VC)");

        // ============================================================
        // PHASE 6: L1 hit verification.
        // After the VC-hit reads in Phase 4, each line was moved from VC
        // to L1.  A second read should now be an L1 hit (1 cycle).
        // ============================================================
        $display("");
        $display("=== PHASE 6: L1 hits for lines loaded from VC in Phase 4 ===");
        begin
            // 0x010 should now be in L1[1] (moved from VC in Phase 4)
            do_read(32'h010, rdata, cyc);
            $display("  0x00000010 -> %0d cycles  (expect 1, L1 hit)", cyc);
            if (cyc !== 1 || rdata !== exp_word(32'h010)) begin
                $display("  FAIL: L1 hit expected"); failures++;
            end else $display("  PASS");
        end
        begin
            // 0x020 should now be in L1[2]
            do_read(32'h020, rdata, cyc);
            $display("  0x00000020 -> %0d cycles  (expect 1, L1 hit)", cyc);
            if (cyc !== 1 || rdata !== exp_word(32'h020)) begin
                $display("  FAIL: L1 hit expected"); failures++;
            end else $display("  PASS");
        end
        begin
            // 0x030 should now be in L1[3]
            do_read(32'h030, rdata, cyc);
            $display("  0x00000030 -> %0d cycles  (expect 1, L1 hit)", cyc);
            if (cyc !== 1 || rdata !== exp_word(32'h030)) begin
                $display("  FAIL: L1 hit expected"); failures++;
            end else $display("  PASS");
        end
        begin
            // 0x040 should now be in L1[4]
            do_read(32'h040, rdata, cyc);
            $display("  0x00000040 -> %0d cycles  (expect 1, L1 hit)", cyc);
            if (cyc !== 1 || rdata !== exp_word(32'h040)) begin
                $display("  FAIL: L1 hit expected"); failures++;
            end else $display("  PASS");
        end

        // ============================================================
        $display("");
        if (failures == 0)
            $display("=== ALL %0d PHASES PASSED ===", 6);
        else
            $display("=== %0d TEST(S) FAILED ===", failures);

        #20; $finish;
    end

    // Eviction log
    always @(posedge clk) begin
        if (evict_valid)
            $display("  [EVICT] t=%0t addr=0x%08h -> VC", $time, evict_addr);
    end

endmodule
