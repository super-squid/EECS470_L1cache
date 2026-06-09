`timescale 1ns / 1ps

module tb_dcache();
    parameter AW = 32;
    parameter DW = 32;

    logic clk;
    logic rst;
    logic [DW-1:0] rdata;

    // Interface Instantiation
    dcache_if #(AW, DW) cpu_if();

    // Cache Device Under Test (DUT) Instantiation
    simple_dcache dut (
        .clk(clk),
        .rst(rst),
        .cpu(cpu_if.mem)
    );

    // Clock Generation (10 ns period)
    initial clk = 0;
    always #5 clk = ~clk;

    // Basic Read Task
    task read(input [AW-1:0] req_addr, output [DW-1:0] req_data_out);
        @(posedge clk);
        cpu_if.req_valid = 1'b1;
        cpu_if.rw = 1'b0;
        cpu_if.addr = req_addr;
        wait(cpu_if.ready);
        req_data_out = cpu_if.rdata;
        @(posedge clk);
        cpu_if.req_valid = 1'b0;
    endtask

    // Basic Write Task
    task write(input [AW-1:0] req_addr, input [DW-1:0] req_data_in);
        @(posedge clk);
        cpu_if.req_valid = 1'b1;
        cpu_if.rw = 1'b1;
        cpu_if.addr = req_addr;
        cpu_if.wdata = req_data_in;
        wait(cpu_if.ready);
        @(posedge clk);
        cpu_if.req_valid = 1'b0;
    endtask

    // Trace-Driven Test Sequence
    initial begin
        // File I/O Variables
        int fd, status;
        logic trace_rw;
        logic [AW-1:0] trace_pc;   // NEW: Program Counter
        logic [AW-1:0] trace_addr;
        logic [DW-1:0] trace_data;
        
        // Performance Counters
        int total_reqs = 0;
        int hit_count = 0;
        int miss_count = 0;
        int start_time, elapsed_time;
        real hit_rate;

        // 1. Hardware Reset Sequence
        rst = 1;
        cpu_if.req_valid = 0;
        repeat (2) @(posedge clk);
        rst = 0;
        @(posedge clk);

        // 2. Open the Trace File
        fd = $fopen("trace.txt", "r");
        if (fd == 0) begin
            $display("Error: Could not open trace.txt");
            $finish;
        end
        $display("Starting PC-Tracked Mock CPU Session...");

        // 3. Main Trace Execution Loop
        while (!$feof(fd)) begin
            // Parse expanded format: <rw> <pc> <addr> <data>
            status = $fscanf(fd, "%b %h %h %h\n", trace_rw, trace_pc, trace_addr, trace_data);
            
            if (status == 4) begin
                total_reqs++;

                // Pipeline Bubble Generator (0-3 idle cycles)
                repeat($urandom_range(0, 3)) @(posedge clk);

                start_time = $time; 

                // Execute the transaction
                if (trace_rw == 1'b0) begin
                    read(trace_addr, rdata);
                end else begin
                    write(trace_addr, trace_data);
                end

                elapsed_time = $time - start_time; 

                // Cycle-Accurate Latency Tracking with PC
                if (elapsed_time <= 10) begin
                    hit_count++;
                    $display("[%0t ns] REQ %0d: HIT  | PC: 0x%h | Addr: 0x%h", 
                             $time, total_reqs, trace_pc, trace_addr);
                end else begin
                    miss_count++;
                    $display("[%0t ns] REQ %0d: MISS | PC: 0x%h | Addr: 0x%h | Latency: %0d ns", 
                             $time, total_reqs, trace_pc, trace_addr, elapsed_time);
                end
            end else if (status != -1) begin
                break; // Prevent Vivado infinite loop on trailing empty lines
            end
        end

        $fclose(fd);

        // Calculate Final Metrics
        if (total_reqs > 0) begin
            hit_rate = (real'(hit_count) / real'(total_reqs)) * 100.0;
        end else begin
            hit_rate = 0.0;
        end
        
        $display("\n==============================");
        $display("    PERFORMANCE RESULTS");
        $display("==============================");
        $display("Total Accesses : %0d", total_reqs);
        $display("Hits           : %0d", hit_count);
        $display("Misses         : %0d", miss_count);
        $display("Hit Rate       : %0.2f%%", hit_rate);
        $display("==============================");
        $finish;
    end
endmodule
