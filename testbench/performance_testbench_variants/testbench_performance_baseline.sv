// CPU-level performance testbench variant.
// Generated from the user's current testbench_performance.sv.
// Use +PROG=<hex_file_name> in Vivado xsim, or put the default .hex file
// under <vivado_project>/<vivado_project>.sim/sim_1/behav/xsim/.
//
// Important: set this module as simulation top before running.
`timescale 1ns/1ps

module performance_analysis_baseline;

    localparam AW          = 32;
    localparam CPU_DW      = 32;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_DW    = BLOCK_BYTES * 8;
    localparam INSTR_NOP   = 32'h0000_0013;
    localparam int IMEM_DEPTH = 16384;

    logic clk;
    logic rst;

    initial clk = 1'b0;
    always #5 clk = ~clk;

    dcache_if #(
        .AW(AW),
        .DW(CPU_DW)
    ) cpu_l1_if();

    logic [31:0] imem_addr;
    logic [31:0] imem_rdata;
    logic [31:0] instr_mem [0:IMEM_DEPTH-1];

    assign imem_rdata = instr_mem[imem_addr[15:2]];

    logic halted;

    cpu #(
        .RESET_PC(32'h0000_0000)
    ) u_cpu (
        .clk        (clk),
        .rst        (rst),
        .imem_addr  (imem_addr),
        .imem_rdata (imem_rdata),
        .dmem       (cpu_l1_if.cpu),
        .halted     (halted)
    );


    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) l1_dram_if();

    logic                     evict_valid_unused;
    logic [AW-1:0]            evict_addr_unused;
    logic [BLOCK_DW-1:0]      evict_data_unused;

    simple_dcache #(
        .AW          (AW),
        .DW          (CPU_DW),
        .CACHE_BYTES (256),
        .BLOCK_BYTES (BLOCK_BYTES),
        .ASSOC       (1)
    ) u_l1 (
        .clk         (clk),
        .rst         (rst),
        .cpu_if      (cpu_l1_if.mem),
        .mem_if      (l1_dram_if.cache_mem),
        .evict_valid (evict_valid_unused),
        .evict_addr  (evict_addr_unused),
        .evict_data  (evict_data_unused)
    );

    dram_model #(
        .AW          (AW),
        .BLOCK_BYTES (BLOCK_BYTES),
        .READ_DELAY  (3)
    ) u_dram (
        .clk   (clk),
        .rst   (rst),
        .iface (l1_dram_if.dram)
    );

    string program_file;

    initial begin
        for (int i = 0; i < IMEM_DEPTH; i++) begin
            instr_mem[i] = INSTR_NOP;
        end

        if (!$value$plusargs("PROG=%s", program_file)) begin
            program_file = "perf_09_next_line_prefetch_stream.hex";
        end

        $readmemh(program_file, instr_mem);
    end


    int cycles;
    int cpu_loads_done;
    int cpu_stores_done;
    int cpu_mem_ops_done;

    int l1_block_reads;
    int l1_block_writes;
    int l1_block_accesses;

    int dram_reads;
    int dram_writes;
    int dram_accesses;

    real dram_reads_per_cpu_mem_op;



    logic prev_l1_req;
    logic prev_dram_req;

    wire l1_req_start;
    wire dram_req_start;

    assign l1_req_start   = l1_dram_if.req_valid && !prev_l1_req;
    assign dram_req_start = l1_dram_if.req_valid && !prev_dram_req;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            cycles           <= 0;
            cpu_loads_done   <= 0;
            cpu_stores_done  <= 0;
            l1_block_reads   <= 0;
            l1_block_writes  <= 0;
            dram_reads       <= 0;
            dram_writes      <= 0;
            prev_l1_req      <= 1'b0;
            prev_dram_req    <= 1'b0;
        end else if (!halted) begin
            cycles <= cycles + 1;

            if (cpu_l1_if.req_valid && cpu_l1_if.ready && !cpu_l1_if.rw) begin
                cpu_loads_done <= cpu_loads_done + 1;
            end

            if (cpu_l1_if.req_valid && cpu_l1_if.ready && cpu_l1_if.rw) begin
                cpu_stores_done <= cpu_stores_done + 1;
            end

            if (l1_req_start && !l1_dram_if.rw) begin
                l1_block_reads <= l1_block_reads + 1;
            end

            if (l1_req_start && l1_dram_if.rw) begin
                l1_block_writes <= l1_block_writes + 1;
            end

            if (dram_req_start && !l1_dram_if.rw) begin
                dram_reads <= dram_reads + 1;
            end

            if (dram_req_start && l1_dram_if.rw) begin
                dram_writes <= dram_writes + 1;
            end

            prev_l1_req   <= l1_dram_if.req_valid;
            prev_dram_req <= l1_dram_if.req_valid;
        end
    end


    initial begin
        rst = 1'b1;

        repeat (5) @(posedge clk);
        rst = 1'b0;

        wait (halted);

        repeat (2) @(posedge clk);

        cpu_mem_ops_done  = cpu_loads_done + cpu_stores_done;
        l1_block_accesses = l1_block_reads + l1_block_writes;
        dram_accesses     = dram_reads + dram_writes;

        if (cpu_mem_ops_done > 0)
            dram_reads_per_cpu_mem_op = real'(dram_reads) / real'(cpu_mem_ops_done);
        else
            dram_reads_per_cpu_mem_op = 0.0;


        $display("");
        $display("Performance Statistics");
        $display("Cache configuration        : baseline: CPU -> simple_dcache -> DRAM");
        $display("Program file                 : %s", program_file);
        $display("Total cycles                 : %0d", cycles);
        $display("");
        $display("CPU-side memory traffic");
        $display("CPU loads completed          : %0d", cpu_loads_done);
        $display("CPU stores completed         : %0d", cpu_stores_done);
        $display("CPU memory ops completed     : %0d", cpu_mem_ops_done);
        $display("");
        $display("L1-to-next-level traffic");
        $display("L1 block read requests       : %0d", l1_block_reads);
        $display("L1 block write requests      : %0d", l1_block_writes);
        $display("L1 block total requests      : %0d", l1_block_accesses);

        $display("");
        $display("DRAM traffic");
        $display("DRAM read requests           : %0d", dram_reads);
        $display("DRAM write requests          : %0d", dram_writes);
        $display("DRAM total requests          : %0d", dram_accesses);
        $display("DRAM reads / CPU mem op      : %.3f", dram_reads_per_cpu_mem_op);
        $display("");

        $finish;
    end

    initial begin
        #50000000;
        $display("");
        $display("TIMEOUT: program did not halt");
        $display("Cache configuration        : baseline: CPU -> simple_dcache -> DRAM");
        $display("Program file               : %s", program_file);
        $display("Current PC                 : %h", imem_addr);
        $display("Current instr              : %h", imem_rdata);
        $display("Cycles                     : %0d", cycles);
        $display("Loads done                 : %0d", cpu_loads_done);
        $display("Stores done                : %0d", cpu_stores_done);
        $display("L1 reads                   : %0d", l1_block_reads);
        $display("L1 writes                  : %0d", l1_block_writes);
        $display("DRAM reads                 : %0d", dram_reads);
        $display("DRAM writes                : %0d", dram_writes);
        $finish;
    end

endmodule
