`timescale 1ns/1ps

module performance_analysis;

    localparam AW          = 32;
    localparam CPU_DW      = 32;
    localparam BLOCK_BYTES = 16;
    localparam BLOCK_DW    = BLOCK_BYTES * 8;

    localparam INSTR_NOP = 32'h0000_0013;

    logic clk;
    logic rst;

    initial clk = 1'b0;
    always #5 clk = ~clk;

    dcache_if #(
        .AW(AW),
        .DW(CPU_DW)
    ) cpu_l1_if();

    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) l1_vc_if();

    dcache_if #(
        .AW(AW),
        .DW(BLOCK_DW)
    ) vc_dram_if();

    logic [31:0] imem_addr;
    logic [31:0] imem_rdata;
    logic [31:0] instr_mem [0:255];

    assign imem_rdata = instr_mem[imem_addr[9:2]];

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

    logic                     evict_valid;
    logic [AW-1:0]            evict_addr;
    logic [BLOCK_DW-1:0]      evict_data;

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
        .mem_if      (l1_vc_if.cache_mem),
        .evict_valid (evict_valid),
        .evict_addr  (evict_addr),
        .evict_data  (evict_data)
    );

    victim_cache #(
        .AW           (AW),
        .BLOCK_BYTES  (BLOCK_BYTES),
        .NUM_VC_LINES (4)
    ) u_vc (
        .clk          (clk),
        .rst          (rst),
        .upstream     (l1_vc_if.dram),
        .downstream   (vc_dram_if.cache_mem),
        .evict_valid  (evict_valid),
        .evict_addr   (evict_addr),
        .evict_data   (evict_data)
    );

    dram_model #(
        .AW          (AW),
        .BLOCK_BYTES (BLOCK_BYTES),
        .READ_DELAY  (3)
    ) u_dram (
        .clk   (clk),
        .rst   (rst),
        .iface (vc_dram_if.dram)
    );

    string program_file;

    initial begin
        for (int i = 0; i < 256; i++) begin
            instr_mem[i] = INSTR_NOP;
        end

        if (!$value$plusargs("PROG=%s", program_file)) begin
            program_file = "instruction_list.hex";
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

    int victim_read_hits;

    real dram_reads_per_cpu_mem_op;
    real victim_read_hit_rate;
    real dram_read_reduction_rate;

    logic prev_l1_vc_req;
    logic prev_vc_dram_req;

    wire l1_vc_req_start;
    wire vc_dram_req_start;

    assign l1_vc_req_start   = l1_vc_if.req_valid   && !prev_l1_vc_req;
    assign vc_dram_req_start = vc_dram_if.req_valid && !prev_vc_dram_req;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            cycles           <= 0;

            cpu_loads_done   <= 0;
            cpu_stores_done  <= 0;

            l1_block_reads   <= 0;
            l1_block_writes  <= 0;

            dram_reads       <= 0;
            dram_writes      <= 0;

            prev_l1_vc_req   <= 1'b0;
            prev_vc_dram_req <= 1'b0;
        end else if (!halted) begin
            cycles <= cycles + 1;

            if (cpu_l1_if.req_valid && cpu_l1_if.ready && !cpu_l1_if.rw) begin
                cpu_loads_done <= cpu_loads_done + 1;
            end

            if (cpu_l1_if.req_valid && cpu_l1_if.ready && cpu_l1_if.rw) begin
                cpu_stores_done <= cpu_stores_done + 1;
            end

            if (l1_vc_req_start && !l1_vc_if.rw) begin
                l1_block_reads <= l1_block_reads + 1;
            end

            if (l1_vc_req_start && l1_vc_if.rw) begin
                l1_block_writes <= l1_block_writes + 1;
            end

            if (vc_dram_req_start && !vc_dram_if.rw) begin
                dram_reads <= dram_reads + 1;
            end

            if (vc_dram_req_start && vc_dram_if.rw) begin
                dram_writes <= dram_writes + 1;
            end

            prev_l1_vc_req   <= l1_vc_if.req_valid;
            prev_vc_dram_req <= vc_dram_if.req_valid;
        end
    end

    initial begin
        rst = 1'b1;

        repeat (5) @(posedge clk);
        rst = 1'b0;

        wait (halted);

        repeat (2) @(posedge clk);

        cpu_mem_ops_done = cpu_loads_done + cpu_stores_done;
        l1_block_accesses = l1_block_reads + l1_block_writes;
        dram_accesses = dram_reads + dram_writes;

        victim_read_hits = l1_block_reads - dram_reads;

        if (cpu_mem_ops_done > 0)
            dram_reads_per_cpu_mem_op = real'(dram_reads) / real'(cpu_mem_ops_done);
        else
            dram_reads_per_cpu_mem_op = 0.0;

        if (l1_block_reads > 0)
            victim_read_hit_rate = 100.0 * real'(victim_read_hits) / real'(l1_block_reads);
        else
            victim_read_hit_rate = 0.0;

        if (l1_block_reads > 0)
            dram_read_reduction_rate = 100.0 * real'(victim_read_hits) / real'(l1_block_reads);
        else
            dram_read_reduction_rate = 0.0;

        $display("");
        $display("Performance Statistics");
        $display("Program file                 : %s", program_file);
        $display("Total cycles                 : %0d", cycles);
        $display("");
        $display("CPU-side memory traffic");
        $display("CPU loads completed          : %0d", cpu_loads_done);
        $display("CPU stores completed         : %0d", cpu_stores_done);
        $display("CPU memory ops completed     : %0d", cpu_mem_ops_done);
        $display("");
        $display("L1-to-victim-cache traffic");
        $display("L1 block read requests       : %0d", l1_block_reads);
        $display("L1 block write requests      : %0d", l1_block_writes);
        $display("L1 block total requests      : %0d", l1_block_accesses);
        $display("");
        $display("Victim-cache effect");
        $display("Estimated victim read hits   : %0d", victim_read_hits);
        $display("Victim read hit rate         : %.2f%%", victim_read_hit_rate);
        $display("DRAM read reduction rate     : %.2f%%", dram_read_reduction_rate);
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
        #50000;
        $finish;
    end

endmodule