// testbench_multi_way_benchmark.sv
// Benchmark-oriented testbench for two_way_dcache.


module tb_two_way_benchmark;
    parameter AW = 32;
    parameter DW = 32;
    parameter CACHE_BYTES = 256;
    parameter BLOCK_BYTES = 16;

    // Change this parameter to compare direct-mapped and set-associative behavior.
    // ASSOC = 1: direct-mapped behavior
    // ASSOC = 2: 2-way set-associative behavior
    // ASSOC = 4: 4-way set-associative behavior
    parameter ASSOC = 2;

    parameter BENCH_REPEATS = 8;
    parameter SEQ_BLOCKS = 8;

    localparam BLOCK_BITS = BLOCK_BYTES * 8;
    localparam NUM_SETS   = CACHE_BYTES / (BLOCK_BYTES * ASSOC);

    localparam logic [AW-1:0] CONFLICT_A = 32'h0000_0000;
    localparam logic [AW-1:0] CONFLICT_B = 32'h0000_0100;
    localparam logic [AW-1:0] CONFLICT_C = 32'h0000_0200;
    localparam logic [AW-1:0] CONFLICT_D = 32'h0000_0300;

    logic clk;
    logic rst;

    logic [DW-1:0] rdata;

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


    int cycle_counter;
    int stat_start_cycle;

    int total_reads;
    int read_hits;
    int read_misses;

    int total_writes;
    int write_hits;
    int write_misses;

    int mem_read_txns;
    int mem_write_txns;

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            cycle_counter <= 0;
        else
            cycle_counter <= cycle_counter + 1;
    end

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

    task automatic reset_stats();
        begin
            stat_start_cycle = cycle_counter;

            total_reads    = 0;
            read_hits      = 0;
            read_misses    = 0;

            total_writes   = 0;
            write_hits     = 0;
            write_misses   = 0;

            mem_read_txns  = 0;
            mem_write_txns = 0;
        end
    endtask

    task automatic print_stats(input string title);
        real read_hit_rate;
        real overall_mem_per_access;
        int total_accesses;
        int elapsed_cycles;
        begin
            total_accesses = total_reads + total_writes;
            elapsed_cycles = cycle_counter - stat_start_cycle;

            if (total_reads == 0)
                read_hit_rate = 0.0;
            else
                read_hit_rate = read_hits * 1.0 / total_reads;

            if (total_accesses == 0)
                overall_mem_per_access = 0.0;
            else
                overall_mem_per_access = (mem_read_txns + mem_write_txns) * 1.0 / total_accesses;

            $display("\n================ %s ================", title);
            $display("ASSOC              = %0d", ASSOC);
            $display("NUM_SETS           = %0d", NUM_SETS);
            $display("Elapsed cycles     = %0d", elapsed_cycles);
            $display("Total reads        = %0d", total_reads);
            $display("Read hits          = %0d", read_hits);
            $display("Read misses        = %0d", read_misses);
            $display("Read hit rate      = %0.3f", read_hit_rate);
            $display("Total writes       = %0d", total_writes);
            $display("Write hits         = %0d", write_hits);
            $display("Write misses       = %0d", write_misses);
            $display("Memory read txns   = %0d", mem_read_txns);
            $display("Memory write txns  = %0d", mem_write_txns);
            $display("Mem txns/access    = %0.3f", overall_mem_per_access);
            $display("====================================================\n");
        end
    endtask

    task automatic apply_reset();
        begin
            cpu_if.req_valid = 1'b0;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = '0;
            cpu_if.wdata     = '0;

            rst = 1'b1;
            repeat (3) @(posedge clk);
            rst = 1'b0;
            @(posedge clk);
        end
    endtask

    task automatic read_with_stat(
        input  logic [AW-1:0] addr,
        output logic [DW-1:0] data,
        output bit mem_used
    );
        int guard;
        bit prev_mem_req;
        logic prev_mem_rw;
        logic [AW-1:0] prev_mem_addr;
        begin
            guard = 0;
            mem_used = 1'b0;
            prev_mem_req = 1'b0;
            prev_mem_rw = 1'b0;
            prev_mem_addr = '0;

            @(negedge clk);
            cpu_if.req_valid = 1'b1;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = addr;
            cpu_if.wdata     = '0;

            do begin
                @(posedge clk);

                if (mem_if.req_valid &&
                    (!prev_mem_req ||
                     (mem_if.rw != prev_mem_rw) ||
                     (mem_if.addr != prev_mem_addr))) begin

                    mem_used = 1'b1;

                    if (mem_if.rw)
                        mem_write_txns++;
                    else
                        mem_read_txns++;
                end

                prev_mem_req  = mem_if.req_valid;
                prev_mem_rw   = mem_if.rw;
                prev_mem_addr = mem_if.addr;

                guard++;
                if (guard > 500) begin
                    $display("TIMEOUT during read addr=%08h", addr);
                    $finish;
                end
            end while (!cpu_if.ready);

            data = cpu_if.rdata;

            @(negedge clk);
            cpu_if.req_valid = 1'b0;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = '0;
            cpu_if.wdata     = '0;
        end
    endtask

    task automatic write_with_stat(
        input logic [AW-1:0] addr,
        input logic [DW-1:0] data,
        output bit mem_read_used,
        output bit mem_write_used
    );
        int guard;
        bit prev_mem_req;
        logic prev_mem_rw;
        logic [AW-1:0] prev_mem_addr;
        begin
            guard = 0;
            mem_read_used = 1'b0;
            mem_write_used = 1'b0;
            prev_mem_req = 1'b0;
            prev_mem_rw = 1'b0;
            prev_mem_addr = '0;

            @(negedge clk);
            cpu_if.req_valid = 1'b1;
            cpu_if.rw        = 1'b1;
            cpu_if.addr      = addr;
            cpu_if.wdata     = data;

            do begin
                @(posedge clk);

                if (mem_if.req_valid &&
                    (!prev_mem_req ||
                     (mem_if.rw != prev_mem_rw) ||
                     (mem_if.addr != prev_mem_addr))) begin

                    if (mem_if.rw) begin
                        mem_write_used = 1'b1;
                        mem_write_txns++;
                    end else begin
                        mem_read_used = 1'b1;
                        mem_read_txns++;
                    end
                end

                prev_mem_req  = mem_if.req_valid;
                prev_mem_rw   = mem_if.rw;
                prev_mem_addr = mem_if.addr;

                guard++;
                if (guard > 500) begin
                    $display("TIMEOUT during write addr=%08h", addr);
                    $finish;
                end
            end while (!cpu_if.ready);

            @(negedge clk);
            cpu_if.req_valid = 1'b0;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = '0;
            cpu_if.wdata     = '0;
            @(posedge clk);
        end
    endtask

    task automatic benchmark_read(
        input logic [AW-1:0] addr,
        input logic [DW-1:0] expected,
        input string label
    );
        logic [DW-1:0] data;
        bit mem_used;
        begin
            read_with_stat(addr, data, mem_used);

            total_reads++;

            if (mem_used)
                read_misses++;
            else
                read_hits++;

            $display("%s: addr=%08h data=%08h expected=%08h mem_used=%0d",
                     label, addr, data, expected, mem_used);

            if (data !== expected) begin
                $display("FAIL: wrong data in %s", label);
                $finish;
            end
        end
    endtask

    task automatic benchmark_write(
        input logic [AW-1:0] addr,
        input logic [DW-1:0] data,
        input string label
    );
        bit mem_read_used;
        bit mem_write_used;
        begin
            write_with_stat(addr, data, mem_read_used, mem_write_used);

            total_writes++;
            
            if (mem_read_used)
                write_misses++;
            else
                write_hits++;

            $display("%s: addr=%08h wdata=%08h mem_read=%0d mem_write=%0d",
                     label, addr, data, mem_read_used, mem_write_used);
        end
    endtask

    // ------------------------------------------------------------
    // Benchmark 1: conflict-heavy A/B pattern
    // ------------------------------------------------------------
    task automatic run_conflict_benchmark(input int repeats);
        logic [DW-1:0] expected_a;
        logic [DW-1:0] expected_b;
    begin
        $display("\n[Test Benchmark 1] Conflict-heavy pattern A/B/A/B");
        $display("A = %08h, B = %08h", CONFLICT_A, CONFLICT_B);
        $display("Expected behavior:");
        $display("  ASSOC=1: A and B repeatedly evict each other.");
        $display("  ASSOC>=2: A and B can stay in the same set after cold misses.");
    
        expected_a = expected_init_word(CONFLICT_A);
        expected_b = expected_init_word(CONFLICT_B);
    
        apply_reset();
        reset_stats();
    
        for (int i = 0; i < repeats; i++) begin
            benchmark_read(CONFLICT_A, expected_a, $sformatf("Conflict A iter %0d", i));
            benchmark_read(CONFLICT_B, expected_b, $sformatf("Conflict B iter %0d", i));
        end
    
        print_stats("Conflict Benchmark");
    end
    endtask
    
    // ------------------------------------------------------------
    // Benchmark 2: A/B/C/D pattern
    // ------------------------------------------------------------
    
    task automatic run_four_block_conflict_benchmark(input int repeats);
        logic [DW-1:0] expected_a;
        logic [DW-1:0] expected_b;
        logic [DW-1:0] expected_c;
        logic [DW-1:0] expected_d;
    begin
        $display("\n[Test Benchmark 2] Four-block same-set conflict pattern A/B/C/D");
        $display("A = %08h, B = %08h, C = %08h, D = %08h",
                 CONFLICT_A, CONFLICT_B, CONFLICT_C, CONFLICT_D);
    
        $display("Expected behavior:");
        $display("  ASSOC=1: all four blocks repeatedly evict each other.");
        $display("  ASSOC=2: two ways are not enough for four same-set blocks.");
        $display("  ASSOC=4: all four blocks can stay after the first cold misses.");
    
        expected_a = expected_init_word(CONFLICT_A);
        expected_b = expected_init_word(CONFLICT_B);
        expected_c = expected_init_word(CONFLICT_C);
        expected_d = expected_init_word(CONFLICT_D);
    
        apply_reset();
        reset_stats();
    
        for (int i = 0; i < repeats; i++) begin
            benchmark_read(CONFLICT_A, expected_a, $sformatf("4-block A iter %0d", i));
            benchmark_read(CONFLICT_B, expected_b, $sformatf("4-block B iter %0d", i));
            benchmark_read(CONFLICT_C, expected_c, $sformatf("4-block C iter %0d", i));
            benchmark_read(CONFLICT_D, expected_d, $sformatf("4-block D iter %0d", i));
        end
    
        print_stats("Four-Block Same-Set Conflict Benchmark");
    end
    endtask

    // ------------------------------------------------------------
    // Benchmark 3: sequential block reads
    // ------------------------------------------------------------
    task automatic run_sequential_benchmark(input int blocks);
        logic [AW-1:0] base_addr;
        logic [AW-1:0] addr_i;
        begin
            $display("\n[Test Benchmark 3] Sequential block reads");
            $display("This benchmark is useful as a baseline before adding next-line prefetching.");

            base_addr = 32'h0000_0400;

            apply_reset();
            reset_stats();

            $display("\nFirst pass: cold sequential accesses");
            for (int i = 0; i < blocks; i++) begin
                addr_i = base_addr + i * BLOCK_BYTES;
                benchmark_read(addr_i, expected_init_word(addr_i), $sformatf("Seq first pass block %0d", i));
            end

            $display("\nSecond pass: re-reading the same blocks");
            for (int i = 0; i < blocks; i++) begin
                addr_i = base_addr + i * BLOCK_BYTES;
                benchmark_read(addr_i, expected_init_word(addr_i), $sformatf("Seq second pass block %0d", i));
            end

            print_stats("Sequential Benchmark");
        end
    endtask
    


    initial begin
        rst = 1'b1;
        cpu_if.req_valid = 1'b0;
        cpu_if.rw        = 1'b0;
        cpu_if.addr      = '0;
        cpu_if.wdata     = '0;

        apply_reset();

        $display("Two-way/N-way DCache Benchmark Testbench");
        $display("CACHE_BYTES=%0d BLOCK_BYTES=%0d ASSOC=%0d NUM_SETS=%0d",
                 CACHE_BYTES, BLOCK_BYTES, ASSOC, NUM_SETS);
        $display("Run this testbench with ASSOC=1, 2 and 4 to compare conflict behavior.");

        run_conflict_benchmark(BENCH_REPEATS);
        run_four_block_conflict_benchmark(4);
        
        run_sequential_benchmark(SEQ_BLOCKS);

        $display("\nAll benchmark tests finished.");
        #100;
        $finish;
    end


    /*
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
    */
endmodule
