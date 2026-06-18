// testbench_two_way_dcache.sv
// Directed tests for two_way_dcache.
// ASSOC can be changed to 1, 2, 4, etc. to test parameterized N-way behavior.

module tb_two_way_dcache;
    parameter AW = 32;
    parameter DW = 32;
    parameter CACHE_BYTES = 256;
    parameter BLOCK_BYTES = 16;
    parameter ASSOC = 2;

    localparam BLOCK_BITS = BLOCK_BYTES * 8;
    localparam NUM_SETS   = CACHE_BYTES / (BLOCK_BYTES * ASSOC);
    localparam SET_STRIDE = NUM_SETS * BLOCK_BYTES;  // same-set address distance in bytes

    logic clk, rst;
    logic [DW-1:0] rdata;
    logic last_mem_access;

    dcache_if #(.AW(AW), .DW(DW)) cpu_if();
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) mem_if();

    two_way_dcache #(
        .AW(AW),
        .CPU_DW(DW),
        .CACHE_BYTES(CACHE_BYTES),
        .BLOCK_BYTES(BLOCK_BYTES),
        .ASSOC(ASSOC),
        .DW(BLOCK_BITS)
    ) dut (
        .clk(clk),
        .rst(rst),
        .cpu_if(cpu_if.cpu),
        .mem_if(mem_if.cache_mem)
    );

    dram_model #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES),
        .READ_DELAY(2)
    ) dram (
        .clk(clk),
        .rst(rst),
        .iface(mem_if.dram)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    function automatic [DW-1:0] expected_init_word(input logic [AW-1:0] addr);
        logic [AW-1:0] tmp;
        begin
            expected_init_word = '0;
            for (int b = 0; b < (DW/8); b++) begin
                tmp = addr + b;
                expected_init_word[b*8 +: 8] = tmp[7:0];
            end
        end
    endfunction

    task automatic read(input logic [AW-1:0] addr, output logic [DW-1:0] data);
        int guard;
        begin
            last_mem_access = 1'b0;
            guard = 0;

            @(negedge clk);
            cpu_if.req_valid = 1'b1;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = addr;
            cpu_if.wdata     = '0;

            do begin
                @(posedge clk);
                if (mem_if.req_valid)
                    last_mem_access = 1'b1;
                guard++;
                if (guard > 200) begin
                    $display("TIMEOUT during read addr=%08h", addr);
                    $finish;
                end
            end while (!cpu_if.ready);

            if (mem_if.req_valid)
                last_mem_access = 1'b1;

            data = cpu_if.rdata;

            @(negedge clk);
            cpu_if.req_valid = 1'b0;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = '0;
            cpu_if.wdata     = '0;
        end
    endtask

    task automatic write(input logic [AW-1:0] addr, input logic [DW-1:0] data);
        int guard;
        begin
            guard = 0;

            @(negedge clk);
            cpu_if.req_valid = 1'b1;
            cpu_if.rw        = 1'b1;
            cpu_if.addr      = addr;
            cpu_if.wdata     = data;

            do begin
                @(posedge clk);
                guard++;
                if (guard > 200) begin
                    $display("TIMEOUT during write addr=%08h", addr);
                    $finish;
                end
            end while (!cpu_if.ready);

            @(negedge clk);
            cpu_if.req_valid = 1'b0;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = '0;
            cpu_if.wdata     = '0;
        end
    endtask

    task automatic check_read(input logic [AW-1:0] addr,
                              input logic [DW-1:0] expected,
                              input bit expect_mem_access,
                              input string test_name);
        begin
            read(addr, rdata);
            $display("%s: addr=%08h rdata=%08h expected=%08h mem_access=%0d expected_mem=%0d",
                     test_name, addr, rdata, expected, last_mem_access, expect_mem_access);

            if (rdata !== expected) begin
                $display("FAIL: wrong data in %s", test_name);
                $finish;
            end
            if (last_mem_access !== expect_mem_access) begin
                $display("FAIL: unexpected hit/miss behavior in %s", test_name);
                $finish;
            end
            $display("PASS: %s", test_name);
        end
    endtask

    initial begin
        rst = 1'b1;
        cpu_if.req_valid = 1'b0;
        cpu_if.rw        = 1'b0;
        cpu_if.addr      = '0;
        cpu_if.wdata     = '0;

        repeat (3) @(posedge clk);
        rst = 1'b0;
        @(posedge clk);

        $display("CACHE_BYTES=%0d BLOCK_BYTES=%0d ASSOC=%0d NUM_SETS=%0d SET_STRIDE=%0d",
                 CACHE_BYTES, BLOCK_BYTES, ASSOC, NUM_SETS, SET_STRIDE);

        check_read(32'h0000_0000, 32'h03020100, 1'b1, "Test 1: read miss at 0x00000000");
        check_read(32'h0000_0000, 32'h03020100, 1'b0, "Test 2: read hit at 0x00000000");

        $display("\n[Test 3] Write hit at 0x00000000");
        write(32'h0000_0000, 32'hDEADBEEF);
        check_read(32'h0000_0000, 32'hDEADBEEF, 1'b0, "Test 4: read after write hit");

        $display("\n[Test 5] Write miss with write-allocate at 0x00000010");
        write(32'h0000_0010, 32'hCAFEBABE);
        check_read(32'h0000_0010, 32'hCAFEBABE, 1'b0, "Test 6: read after write miss");

        $display("\n[Test 7] Fill all ways in one set and check that all remain hits");
        for (int i = 0; i < ASSOC; i++) begin
            logic [AW-1:0] addr_i;
            logic [DW-1:0] exp_i;
            addr_i = 32'h0000_0020 + i * SET_STRIDE;
            exp_i  = expected_init_word(addr_i);
            check_read(addr_i, exp_i, 1'b1, $sformatf("Fill same-set way %0d", i));
        end

        for (int i = 0; i < ASSOC; i++) begin
            logic [AW-1:0] addr_i;
            logic [DW-1:0] exp_i;
            addr_i = 32'h0000_0020 + i * SET_STRIDE;
            exp_i  = expected_init_word(addr_i);
            check_read(addr_i, exp_i, 1'b0, $sformatf("Re-read same-set way %0d should hit", i));
        end

        $display("\n[Test 8] LRU eviction check");
        check_read(32'h0000_0020, expected_init_word(32'h0000_0020), 1'b0,
                   "Touch first same-set block before eviction");
        check_read(32'h0000_0020 + ASSOC * SET_STRIDE,
                   expected_init_word(32'h0000_0020 + ASSOC * SET_STRIDE),
                   1'b1,
                   "Insert extra same-set block to trigger eviction");
        check_read(32'h0000_0020, expected_init_word(32'h0000_0020), 1'b0,
                   "First block should survive due to LRU update");

        $display("\n[Test 9] Write-through persistence after eviction");
        // Fill more blocks in set 0 until the old 0x00000000 block should be evicted.
        // After eviction, reading 0x00000000 should miss but still return DEADBEEF from DRAM.
        for (int i = 1; i <= ASSOC; i++) begin
            logic [AW-1:0] addr_i;
            addr_i = i * SET_STRIDE;
            check_read(addr_i, expected_init_word(addr_i), 1'b1,
                       $sformatf("Fill set-0 block %0d to force eviction", i));
        end
        check_read(32'h0000_0000, 32'hDEADBEEF, 1'b1,
                   "Read old written address after eviction");

        $display("\n All Tests Passed.");
        #50;
        $finish;
    end

    initial begin
        $monitor("Time %0t: cpu_req=%b addr=%h rw=%b cpu_ready=%b rdata=%h | mem_req=%b mem_addr=%h mem_rw=%b mem_ready=%b | hit=%b state=%0d",
                 $time,
                 cpu_if.req_valid,
                 cpu_if.addr,
                 cpu_if.rw,
                 cpu_if.ready,
                 cpu_if.rdata,
                 mem_if.req_valid,
                 mem_if.addr,
                 mem_if.rw,
                 mem_if.ready,
                 dut.hit,
                 dut.state);
    end
endmodule
