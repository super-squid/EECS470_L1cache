`timescale 1ns/1ps

module tb_top;

    parameter AW = 32;
    parameter DW = 32;

    logic clk;
    logic rst;

    // ==========================================
    // 1. Interfaces
    // ==========================================
    // Interface between CPU and Data Cache
    dcache_if #(.AW(AW), .DW(DW)) cpu_to_cache_if();
    
    // Interface between Data Cache and DRAM
    dcache_if #(.AW(AW), .DW(DW)) cache_to_dram_if();

    // ==========================================
    // 2. Mock Instruction Memory (I-Mem)
    // ==========================================
    logic [AW-1:0] imem_addr;
    logic [DW-1:0] imem_rdata;
    logic [DW-1:0] imem_rom [0:63]; // 64 words of instruction memory

    // Inline instruction ROM setup
    assign imem_rdata = imem_rom[imem_addr >> 2]; // Word-aligned lookups

    initial begin
        // Let's pre-load a simple RISC-V assembly program to test the cache:
        // 1. ADDI x1, x0, 42      -> Move literal 42 into register x1
        imem_rom[0] = 32'h02a00093; 
        // 2. ADDI x2, x0, 256     -> Move memory base address 256 into x2
        imem_rom[1] = 32'h10000113; 
        // 3. SW x1, 0(x2)         -> Store word 42 into address [256] (Triggers Cache Write)
        imem_rom[2] = 32'h00112023; 
        // 4-6. NOPs               -> Mandatory padding to bypass pipeline data hazards for now
        imem_rom[3] = 32'h00000013; 
        imem_rom[4] = 32'h00000013;
        imem_rom[5] = 32'h00000013;
        // 7. LW x3, 0(x2)         -> Load word from address [256] into x3 (Triggers Cache Read)
        imem_rom[6] = 32'h00012183; 
        
        // Pad the rest with NOPs
        for (int i = 7; i < 64; i++) begin
            imem_rom[i] = 32'h00000013;
        end
    end

    // ==========================================
    // 3. Module Instantiations
    // ==========================================
    
    // Instantiate your RISC-V Core
    riscv_cpu #(
        .AW(AW),
        .DW(DW)
    ) u_cpu (
        .clk(clk),
        .rst(rst),
        .imem_addr(imem_addr),
        .imem_rdata(imem_rdata),
        .dcache_mem_if(cpu_to_cache_if.cpu) // Hook to CPU modport
    );

    // Instantiate your Data Cache
    simple_dcache #(
        .AW(AW),
        .DW(DW),
        .CACHE_BYTES(256),
        .BLOCK_BYTES(16),
        .ASSOC(1)
    ) u_dcache (
        .clk(clk),
        .rst(rst),
        .cpu_if(cpu_to_cache_if.mem),       // Receives CPU requests
        .mem_if(cache_to_dram_if.mem)       // Routes misses to DRAM
    );

    // Instantiate your DRAM Model
    dram_model #(
        .AW(AW),
        .BLOCK_BYTES(16),
        .READ_DELAY(4)                      // 4 cycle latency on memory misses
    ) u_dram (
        .clk(clk),
        .rst(rst),
        .iface(cache_to_dram_if)            // Connected directly to cache back-end
    );

    // ==========================================
    // 4. Clock & Simulation Control
    // ==========================================
    always #5 clk = ~clk; // 100MHz clock

    initial begin
        $display("[TB] Starting RISC-V Pipeline + Cache Simulation...");
        clk = 0;
        rst = 1;
        
        // Hold reset for a few cycles
        #25;
        rst = 0;
        $display("[TB] System Reset De-asserted.");

        // Run until our test program completes its execution cycles
        #300;
        
        // Dump Register File contents to verify success
        $display("\n================ SIMULATION RESULTS ================");
        $display("Register x1 (Stored Value)  : %d (Expected: 42)", u_cpu.registers[1]);
        $display("Register x2 (Target Address): %d (Expected: 256)", u_cpu.registers[2]);
        $display("Register x3 (Loaded Value)  : %d (Expected: 42)", u_cpu.registers[3]);
        $display("====================================================\n");
        
        $finish;
    end

    // Optional: Trace changes in wave view tools
    initial begin
        $dumpfile("pipeline_cache_sim.vcd");
        $dumpvars(0, tb_top);
    end

endmodule