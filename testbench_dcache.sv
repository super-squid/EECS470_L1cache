// tb_dcache.sv
module tb_dcache;
    parameter AW = 32;   // address width
    parameter DW = 32;   // data word width
    parameter CACHE_BYTES = 256;
    parameter BLOCK_BYTES = 16;

    logic clk, rst;
    dcache_if #(.AW(AW), .DW(DW)) cpu_if();
    dcache_if #(.AW(AW), .DW(DW)) mem_if();

    // Instantiate Design Under Test (DUT)
    simple_dcache #(
        .AW(AW), .DW(DW),
        .CACHE_BYTES(CACHE_BYTES),
        .BLOCK_BYTES(BLOCK_BYTES),
        .ASSOC(1)
    ) dut (
        .clk(clk),
        .rst(rst),
        .cpu_if(cpu_if.cpu),
        .mem_if(mem_if.mem)
    );

    // Instantiate DRAM Model
    dram_model #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES),
        .READ_DELAY(2)
    ) dram (
        .clk(clk),
        .iface(mem_if)
    );
    
    // Helper tasks to drive interface
    task automatic read(input [AW-1:0] addr, output [DW-1:0] data);
        cpu_if.req_valid = 1;
        cpu_if.rw = 0;
        cpu_if.addr = addr;
        @(posedge clk);
        wait(cpu_if.ready);
        data = cpu_if.rdata;
        cpu_if.req_valid = 0;
    endtask

    task automatic write(input [AW-1:0] addr, input [DW-1:0] data);
        cpu_if.req_valid = 1;
        cpu_if.rw = 1;
        cpu_if.addr = addr;
        cpu_if.wdata = data;
        @(posedge clk);
        wait(cpu_if.ready);
        cpu_if.req_valid = 0;
    endtask

    logic [DW-1:0] rdata;
        
    // Clock
    initial clk = 0;
    always #5 clk = ~clk;

    // Testing with trace file
    initial begin
        // File IO
        int fd, status;
        logic trace_rw;
        logic [AW-1:0] trace_addr;
        logic [DW-1:0] trace_data;
        
        // Performance analysis
        int total_reqs = 0;
        int hit_count = 0;
        int miss_count = 0;
        int start_time, elapsed_time;
        real hit_rate;

        // reset
        rst = 1;
        repeat (2) @(posedge clk);
        rst = 0;
        @(posedge clk);

        // File IO (Read in the trace file)
        fd = $fopen("simple_trace.txt", "r");
        if (fd == 0) begin
            $display("Error");
            $finish;
        end

        // actual testing
        while (!$feof(fd)) begin
            // Parse line format: <read/write bit> <hex address> <hex write data>
            status = $fscanf(fd, "%b %h %h\n", trace_rw, trace_addr, trace_data);
            
            if (status == 3) begin
                total_reqs++;

                // give random idle CPU time
                repeat($urandom_range(0, 3)) @(posedge clk);

                // get request start time
                start_time = $time; 

                // Drive the cache interface
                if (trace_rw == 1'b0) begin
                    read(trace_addr, rdata);
                end else begin
                    write(trace_addr, trace_data);
                end

                // count elapsed time
                elapsed_time = $time - start_time; 

                // count hit count
                if (elapsed_time <= 10) begin
                    hit_count++;
                    $display("[%0t ns] REQ %0d: HIT  | Addr: 0x%h", $time, total_reqs, trace_addr);
                end else begin
                    miss_count++;
                    $display("[%0t ns] REQ %0d: MISS | Addr: 0x%h | Latency: %0d ns", $time, total_reqs, trace_addr, elapsed_time);
                end
            end
        end

        // performance analysis
        $fclose(fd);

        if (total_reqs > 0) begin
            hit_rate = (real'(hit_count) / real'(total_reqs)) * 100.0;
        end else begin
            hit_rate = 0.0;
        end
        
        $display("\nPerformance Results:");
        $display("Total Accesses: %0d", total_reqs);
        $display("Hits: %0d", hit_count);
        $display("Misses: %0d", miss_count);
        $display("Hit Rate: %0.2f%%", hit_rate);
        $finish;
    end

    // Monitor
    initial begin
        $monitor("Time %0t: req=%b, addr=%h, rw=%b, ready=%b, rdata=%h",
                 $time, cpu_if.req_valid, cpu_if.addr, cpu_if.rw, cpu_if.ready, cpu_if.rdata);
    end

endmodule
