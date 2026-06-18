// dcache_if.sv
interface dcache_if #(
    parameter AW = 32,   // address width
    parameter DW = 32    // data word width
) ();
    logic        req_valid;
    logic        rw;          // 0=read, 1=write
    logic [AW-1:0] addr;
    logic [DW-1:0] wdata;
    logic [DW-1:0] rdata;
    logic          ready;
    logic          mem_ready; // from DRAM

    modport cpu (
        input  req_valid, rw, addr, wdata,
        output rdata, ready
    );
    modport mem (
        output req_valid, rw, addr, wdata,
        input  rdata, ready
    );
    modport monitor (        // for testbench to observe all signals
        input  req_valid, rw, addr, wdata, rdata, ready, mem_ready
    );
    
    modport cache_mem (
        output req_valid, rw, addr, wdata,
        input  rdata, ready
    );

    modport dram (
        input  req_valid, rw, addr, wdata,
        output rdata, ready
    );
endinterface