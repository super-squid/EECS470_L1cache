// tb_dcache.sv
module tb_dcache;
    parameter AW = 32;
    parameter DW = 32;
    parameter CACHE_BYTES = 256;
    parameter BLOCK_BYTES = 16;

    logic clk, rst;
    dcache_if #(.AW(AW), .DW(DW)) cpu_if();
    dcache_if #(.AW(AW), .DW(DW)) mem_if();

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

    dram_model #(
        .AW(AW),
        .BLOCK_BYTES(BLOCK_BYTES),
        .READ_DELAY(2)
    ) dram (
        .clk(clk),
        .iface(mem_if.mem),
        .rst(rst)
    );
    
        // Helper task
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

    // Test sequence
    initial begin
        rst = 1;
        repeat (2) @(posedge clk);
        rst = 0;
        @(posedge clk);




        // Test 1: Read miss
        $display("Test 1: Read miss at 0x0000_0000");
        read(0, rdata);
        $display("  Read data = %h", rdata);

        // Test 2: Read hit
        $display("Test 2: Read hit (same address)");
        read(32'h0000_0000, rdata);
        $display("  Hit data = %h", rdata);

        // Test 3: Write hit
        $display("Test 3: Write hit at 0x0000_0000 -> DEADBEEF");
        write(32'h0000_0000, 32'hDEADBEEF);

        // Test 4: Read again
        $display("Test 4: Read after write");
        read(32'h0000_0000, rdata);
        $display("  Data = %h (expected DEADBEEF)", rdata);

        // Test 5: Write miss (different index)
        $display("Test 5: Write miss at 0x0000_0010 -> CAFEBABE");
        write(32'h0000_0010, 32'hCAFEBABE);

        // Test 6: Conflict miss (same index, different tag)
        $display("Test 6: Conflict miss at 0x1000_0000");
        read(32'h1000_0000, rdata);
        $display("  Data = %h", rdata);

        #20;
        $finish ;
    end

    // Monitor
    initial begin
        $monitor("Time %0t: req=%b, addr=%h, rw=%b, ready=%b, rdata=%h",
                 $time, cpu_if.req_valid, cpu_if.addr, cpu_if.rw, cpu_if.ready, cpu_if.rdata);
    end
endmodule