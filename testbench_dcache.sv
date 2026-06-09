// tb_dcache.sv
module tb_dcache;
    parameter AW = 32;
    parameter DW = 32;
    parameter CACHE_BYTES = 256;
    parameter BLOCK_BYTES = 16;

    logic clk, rst;
    localparam BLOCK_BITS = BLOCK_BYTES * 8;

    dcache_if #(.AW(AW), .DW(DW)) cpu_if();
    dcache_if #(.AW(AW), .DW(BLOCK_BITS)) mem_if();

    simple_dcache #(
        .AW(AW), .DW(DW),
        .CACHE_BYTES(CACHE_BYTES),
        .BLOCK_BYTES(BLOCK_BYTES),
        .ASSOC(1)
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
    
        // Helper task
        task automatic read(input [AW-1:0] addr, output [DW-1:0] data);
            @(negedge clk);
            cpu_if.req_valid = 1;
            cpu_if.rw = 0;
            cpu_if.addr = addr;
            cpu_if.wdata = 0;
        
            do @(posedge clk);
            while (!cpu_if.ready);
        
            data = cpu_if.rdata;
        
            @(negedge clk);
            cpu_if.req_valid = 0;
        endtask

        task automatic write(input [AW-1:0] addr, input [DW-1:0] data);
            @(negedge clk);
            cpu_if.req_valid = 1'b1;
            cpu_if.rw        = 1'b1;   
            cpu_if.addr      = addr;
            cpu_if.wdata     = data;
        
            do @(posedge clk);
            while (!cpu_if.ready);
        
            @(negedge clk);
            cpu_if.req_valid = 1'b0;
            cpu_if.rw        = 1'b0;
            cpu_if.addr      = '0;
            cpu_if.wdata     = '0;
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

        // Test 1: read miss
        read(32'h0000_0000, rdata);
        if (rdata !== 32'h03020100)
            $display("FAIL");
        else
            $display("PASS");
        
        // Test 2: read hit
        read(32'h0000_0000, rdata);
        if (rdata !== 32'h03020100)
            $display("FAIL");
        else
            $display("PASS");
        
        // Test 3: write hit
        write(32'h0000_0000, 32'hDEADBEEF);
        
        // Test 4: read after write hit
        read(32'h0000_0000, rdata);
        if (rdata !== 32'hDEADBEEF)
            $display("FAIL");
        else
            $display("PASS");
        
        // Test 5: write miss
        write(32'h0000_0010, 32'hCAFEBABE);
  
        
        // Test 6: read after write miss
        read(32'h0000_0010, rdata);
        if (rdata !== 32'hCAFEBABE)
            $display("FAIL");
        else
            $display("PASS");
        
        // Test 7: conflict miss
        read(32'h0000_0100, rdata);
        if (rdata !== 32'h03020100)
            $display("FAIL");
        else
            $display("PASS");
        
        // Test 8: read old address after conflict eviction
        read(32'h0000_0000, rdata);
        
        if (rdata !== 32'hDEADBEEF)
            $display("FAIL");
        else
            $display("PASS");
        
        
        #20;
        $finish;
    end

    // Monitor
    initial begin
        $monitor("Time %0t: cpu_req=%b, cpu_addr=%h, rw=%b, cpu_ready=%b, cpu_rdata=%h | mem_req=%b, mem_addr=%h, mem_rw=%b, mem_ready=%b | hit=%b, state=%0d",
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