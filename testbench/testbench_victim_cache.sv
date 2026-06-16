`timescale 1ns/1ps

// Demonstrates victim_cache interposed between simple_dcache and dram_model.
//
// Address geometry (CACHE_BYTES=256, BLOCK_BYTES=16, ASSOC=1):
//   OFFSET_BITS = 4  (addr[3:0])
//   INDEX_BITS  = 4  (addr[7:4])
//   L1 TAG_BITS = 24 (addr[31:8])
//   VC TAG_BITS = 28 (addr[31:4]) -- fully-associative, so full block address is the tag
//
// ADDR_A = 0x0000_0000  L1 index=0, L1 tag=0x000000  VC tag=0x0000000
// ADDR_B = 0x0000_0100  L1 index=0, L1 tag=0x000001  VC tag=0x0000010  <- conflict
//
// Test flow:
//   1. Read ADDR_A  -> L1 cold miss -> VC miss -> DRAM fetch; L1[0] = ADDR_A
//   2. Read ADDR_B  -> conflict miss -> ADDR_A evicted into VC; L1[0] = ADDR_B
//   3. Re-read ADDR_A -> L1 miss, VC HIT (1-cycle, no DRAM); L1[0] = ADDR_A; ADDR_B evicted into VC
//   4. Re-read ADDR_A -> L1 hit (already refilled in step 3)

module testbench_victim_cache;

    localparam AW          = 32;
    localparam DW          = 32;
    localparam CACHE_BYTES = 256;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_BITS  = BLOCK_BYTES * 8;  // 128

    // DRAM is initialised as memory[i] = i[7:0], so both blocks happen to return
    // the same byte pattern (byte 0=0x00, byte 1=0x01, ...) because 256%256==0.
    // Word at offset 0 = 0x03020100 for both addresses.
    localparam [AW-1:0] ADDR_A = 32'h0000_0000;  // L1 tag=0x000000, index=0
    localparam [AW-1:0] ADDR_B = 32'h0000_0100;  // L1 tag=0x000001, index=0 (conflict)

    // VC uses TAG_BITS = AW - OFFSET_BITS = 28 (full block address).
    // VC_TAG_x = addr[31:4] = addr >> 4.
    localparam OFFSET_BITS_TB = 4;                          // log2(BLOCK_BYTES=16)
    localparam [27:0] VC_TAG_A = ADDR_A >> OFFSET_BITS_TB; // 28'h0000000
    localparam [27:0] VC_TAG_B = ADDR_B >> OFFSET_BITS_TB; // 28'h0000010 = 16

    logic clk, rst;
    initial clk = 0;
    always #5 clk = ~clk;

    // Three interface instances wire the pipeline: CPU-L1-VC-DRAM
    dcache_if #(.AW(AW), .DW(DW))         cpu_if();     // CPU  <-> L1
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) l1_vc_if();   // L1   <-> VC (block-wide)
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) vc_dram_if(); // VC   <-> DRAM

    // Eviction wires carry the displaced L1 block to the victim cache
    logic                  evict_valid;
    logic [AW-1:0]         evict_addr;
    logic [BLOCK_BITS-1:0] evict_data;

    simple_dcache #(
        .AW(AW), .DW(DW),
        .CACHE_BYTES(CACHE_BYTES),
        .BLOCK_BYTES(BLOCK_BYTES),
        .ASSOC(1)
    ) l1 (
        .clk(clk), .rst(rst),
        .cpu_if(cpu_if.cpu),
        .mem_if(l1_vc_if.cache_mem),
        .evict_valid(evict_valid),
        .evict_addr (evict_addr),
        .evict_data (evict_data)
    );

    victim_cache #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES),
        .NUM_VC_LINES(4)
    ) vc (
        .clk(clk), .rst(rst),
        .upstream   (l1_vc_if.dram),
        .downstream (vc_dram_if.cache_mem),
        .evict_valid(evict_valid),
        .evict_addr (evict_addr),
        .evict_data (evict_data)
    );

    dram_model #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES),
        .READ_DELAY(2)
    ) dram (
        .clk(clk), .rst(rst),
        .iface(vc_dram_if.dram)
    );

    // Drive a single CPU read and return the data word
    task automatic do_read(input [AW-1:0] addr, output logic [DW-1:0] data);
        @(negedge clk);
        cpu_if.req_valid = 1'b1;
        cpu_if.rw        = 1'b0;
        cpu_if.addr      = addr;
        cpu_if.wdata     = '0;
        do @(posedge clk);
        while (!cpu_if.ready);
        data = cpu_if.rdata;
        @(negedge clk);
        cpu_if.req_valid = 1'b0;
    endtask

    // Print all four VC entries and the current FSM state
    task print_vc;
        $display("    VC [state=%s]",
            vc.state == 2'd0 ? "IDLE     " :
            vc.state == 2'd1 ? "VC_HIT   " : "DRAM_WAIT");
        for (int i = 0; i < 4; i++) begin
            if (vc.vc[i].valid)
                $display("      vc[%0d] valid  tag=0x%07h", i, vc.vc[i].tag);  // 28-bit tag, 7 hex digits
            else
                $display("      vc[%0d] empty", i);
        end
    endtask

    logic [DW-1:0] rdata;
    int            failures;

    initial begin
        $dumpfile("tb_victim_cache.vcd");
        $dumpvars(0, testbench_victim_cache);

        failures         = 0;
        cpu_if.req_valid = 1'b0;
        cpu_if.rw        = 1'b0;
        cpu_if.addr      = '0;
        cpu_if.wdata     = '0;

        rst = 1'b1;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        @(posedge clk);

        // ----------------------------------------------------------------
        // STEP 1: Cold read -- L1 miss, VC miss, goes all the way to DRAM.
        //         DRAM READ_DELAY=2 means this takes ~3 cycles.
        //         No eviction: cache[0] was invalid, nothing to displace.
        // ----------------------------------------------------------------
        $display("STEP 1 [t=%0t]: Read ADDR_A (0x%08h) -- cold miss", $time, ADDR_A);
        do_read(ADDR_A, rdata);
        $display("  rdata = 0x%08h  (expected 0x03020100)", rdata);
        $display("  L1 index 0: valid=%b  tag=0x%06h", l1.cache[0].valid, l1.cache[0].tag);
        print_vc();
        if (rdata !== 32'h03020100) begin
            $display("  FAIL: rdata mismatch"); failures++;
        end else
            $display("  PASS");

        // ----------------------------------------------------------------
        // STEP 2: Conflict read -- ADDR_B maps to the same L1 index as ADDR_A.
        //         L1 misses; the valid ADDR_A line is displaced.
        //         evict_valid fires when VC returns downstream.ready.
        //         VC absorbs the ADDR_A block into vc[3] (initial LRU victim).
        // ----------------------------------------------------------------
        $display("");
        $display("STEP 2 [t=%0t]: Read ADDR_B (0x%08h) -- conflict miss, evicts ADDR_A into VC", $time, ADDR_B);
        do_read(ADDR_B, rdata);
        $display("  rdata = 0x%08h  (expected 0x03020100)", rdata);
        $display("  L1 index 0: valid=%b  tag=0x%06h  (expect tag=1, ADDR_B)", l1.cache[0].valid, l1.cache[0].tag);
        print_vc();
        if (rdata !== 32'h03020100) begin
            $display("  FAIL: rdata mismatch"); failures++;
        end else if (!vc.vc[3].valid || vc.vc[3].tag !== VC_TAG_A) begin
            $display("  FAIL: expected vc[3] valid with VC_TAG_A (0x%07h), got valid=%b tag=0x%07h",
                     VC_TAG_A, vc.vc[3].valid, vc.vc[3].tag); failures++;
        end else
            $display("  PASS: ADDR_A block stored in vc[3] (VC tag=0x%07h)", VC_TAG_A);

        // ----------------------------------------------------------------
        // STEP 3: Re-read ADDR_A -- L1 still holds ADDR_B, so L1 misses.
        //         VC finds ADDR_A in vc[3]: VC_HIT, returns data in 1 cycle
        //         (no downstream DRAM request).
        //         As VC returns ready, L1 fills cache[0] with ADDR_A and
        //         displaces ADDR_B -- evict_valid fires again.
        //         VC invalidates vc[3] (move semantics) and absorbs ADDR_B into vc[2]
        //         (next LRU victim: ages after STEP 2 are way0=1,way1=2,way2=3,way3=0).
        // ----------------------------------------------------------------
        $display("");
        $display("STEP 3 [t=%0t]: Re-read ADDR_A (0x%08h) -- expect VC HIT, no DRAM", $time, ADDR_A);
        do_read(ADDR_A, rdata);
        $display("  rdata = 0x%08h  (expected 0x03020100)", rdata);
        $display("  L1 index 0: valid=%b  tag=0x%06h  (expect tag=0, ADDR_A re-loaded)", l1.cache[0].valid, l1.cache[0].tag);
        print_vc();
        if (rdata !== 32'h03020100) begin
            $display("  FAIL: rdata mismatch"); failures++;
        end else if (vc.vc[3].valid) begin
            $display("  FAIL: vc[3] should be invalid after VC hit (line moved to L1)"); failures++;
        end else if (!vc.vc[2].valid || vc.vc[2].tag !== VC_TAG_B) begin
            $display("  FAIL: expected vc[2] valid with VC_TAG_B (0x%07h), got valid=%b tag=0x%07h",
                     VC_TAG_B, vc.vc[2].valid, vc.vc[2].tag); failures++;
        end else
            $display("  PASS: data from VC; vc[3] freed, ADDR_B evicted into vc[2] (VC tag=0x%07h)", VC_TAG_B);

        // ----------------------------------------------------------------
        // STEP 4: Read ADDR_A again -- now in L1, should hit immediately.
        // ----------------------------------------------------------------
        $display("");
        $display("STEP 4 [t=%0t]: Re-read ADDR_A (0x%08h) -- expect L1 hit", $time, ADDR_A);
        do_read(ADDR_A, rdata);
        $display("  rdata = 0x%08h  (expected 0x03020100)", rdata);
        if (rdata !== 32'h03020100) begin
            $display("  FAIL"); failures++;
        end else
            $display("  PASS: L1 hit");

        // ----------------------------------------------------------------
        $display("");
        if (failures == 0) begin
            $display("===========================================");
            $display("ALL TESTS PASSED");
            $display("===========================================");
        end else begin
            $display("===========================================");
            $display("%0d TEST(S) FAILED", failures);
            $display("===========================================");
        end

        #20;
        $finish;
    end

    // Log every eviction pulse on the clock edge it fires
    always @(posedge clk) begin
        if (evict_valid)
            $display("  [EVICT] t=%0t  evict_addr=0x%08h -> victim_cache", $time, evict_addr);
    end

endmodule
