// two_way_dcache.sv
// Parameterized set-associative DCache.
// Default ASSOC = 2, but ASSOC can be changed to 1, 2, 4, etc.
// Compatible with the current shared files:
//   - dcache_interface.sv: uses dcache_if.cpu and dcache_if.cache_mem
//   - dram_model.sv: memory side should connect through dcache_if.dram
//   - lru_replacement.sv: uses module basic_lru

module two_way_dcache #(
    parameter AW = 32,
    parameter CPU_DW = 32,          // CPU word width, normally 32 bits
    parameter CACHE_BYTES = 256,
    parameter BLOCK_BYTES = 16,
    parameter ASSOC = 2,            // 2 for 2-way, can be changed to N-way
    parameter DW = BLOCK_BYTES * 8  
) (
    input  logic clk,
    input  logic rst,
    dcache_if.cpu       cpu_if,
    dcache_if.cache_mem mem_if
);

    localparam BLOCK_BITS      = BLOCK_BYTES * 8;
    localparam OFFSET_BITS     = (BLOCK_BYTES <= 1) ? 1 : $clog2(BLOCK_BYTES);
    localparam NUM_SETS        = CACHE_BYTES / (BLOCK_BYTES * ASSOC);
    localparam REAL_INDEX_BITS = (NUM_SETS <= 1) ? 0 : $clog2(NUM_SETS);
    localparam INDEX_BITS      = (NUM_SETS <= 1) ? 1 : $clog2(NUM_SETS);
    localparam TAG_BITS        = AW - OFFSET_BITS - REAL_INDEX_BITS;
    localparam WAY_BITS        = (ASSOC <= 1) ? 1 : $clog2(ASSOC);

    initial begin
        if (ASSOC < 1) begin
            $fatal(1, "ASSOC must be at least 1.");
        end
        if ((CACHE_BYTES % (BLOCK_BYTES * ASSOC)) != 0) begin
            $fatal(1, "CACHE_BYTES must be divisible by BLOCK_BYTES * ASSOC.");
        end
        if (CPU_DW > BLOCK_BITS) begin
            $fatal(1, "CPU_DW cannot be larger than one cache block.");
        end
        if (DW != BLOCK_BITS) begin
            $display("Warning: parameter DW is ignored internally; memory side should use BLOCK_BYTES*8 bits.");
        end
    end

    typedef struct packed {
        logic valid;
        logic [TAG_BITS-1:0] tag;
        logic [BLOCK_BITS-1:0] data;
    } cache_line_t;

    cache_line_t cache [0:NUM_SETS-1][0:ASSOC-1];


    logic [OFFSET_BITS-1:0] offset;
    logic [INDEX_BITS-1:0]  index;
    logic [TAG_BITS-1:0]    tag;

    always_comb begin
        offset = cpu_if.addr[OFFSET_BITS-1:0];
        index  = '0;
        tag    = '0;

        if (NUM_SETS <= 1) begin
            tag = cpu_if.addr[AW-1:OFFSET_BITS];
        end else begin
            index = cpu_if.addr[OFFSET_BITS +: INDEX_BITS];
            tag   = cpu_if.addr[AW-1:OFFSET_BITS+INDEX_BITS];
        end
    end

    // Hit detection and replacement selection
    logic hit;
    logic [WAY_BITS-1:0] hit_way;
    logic has_invalid;
    logic [WAY_BITS-1:0] invalid_way;
    logic [WAY_BITS-1:0] fill_way;
    logic [WAY_BITS-1:0] selected_way;
    logic [WAY_BITS-1:0] victim_way;

    always_comb begin
        hit     = 1'b0;
        hit_way = '0;

        for (int w = 0; w < ASSOC; w++) begin
            if (!hit && cache[index][w].valid && (cache[index][w].tag == tag)) begin
                hit     = 1'b1;
                hit_way = w[WAY_BITS-1:0];
            end
        end
    end

    always_comb begin
        has_invalid = 1'b0;
        invalid_way = '0;

        for (int w = 0; w < ASSOC; w++) begin
            if (!has_invalid && !cache[index][w].valid) begin
                has_invalid = 1'b1;
                invalid_way = w[WAY_BITS-1:0];
            end
        end

        // Prefer an invalid way first. If the set is full, use LRU victim way.
        fill_way     = has_invalid ? invalid_way : victim_way;
        selected_way = hit ? hit_way : fill_way;
    end

    logic [AW-1:0]          req_addr;
    logic                  req_rw;
    logic [CPU_DW-1:0]      req_wdata;
    logic [OFFSET_BITS-1:0] req_offset;
    logic [INDEX_BITS-1:0]  req_index;
    logic [TAG_BITS-1:0]    req_tag;
    logic [WAY_BITS-1:0]    req_way;

    typedef enum logic [2:0] {
        IDLE,
        READ_MISS,
        READ_RESP,
        WRITE_MISS_REFILL,
        WRITE_MISS_UPDATE,
        WRITE_THROUGH
    } state_t;
    
    state_t state, next_state;

    logic accept_req;
    assign accept_req = (state == IDLE) && cpu_if.req_valid;
    
    logic [BLOCK_BITS-1:0] updated_block;
    logic [BLOCK_BITS-1:0] refill_updated_block;
    
    always_comb begin
        updated_block = cache[index][hit_way].data;
        updated_block[offset*8 +: CPU_DW] = cpu_if.wdata;
    end
    
    always_comb begin
        refill_updated_block = mem_if.rdata;
        refill_updated_block[req_offset*8 +: CPU_DW] = req_wdata;
    end
    
    // Write-update blocks
    logic [BLOCK_BITS-1:0] write_hit_block;
    logic [BLOCK_BITS-1:0] write_miss_block;

    always_comb begin
        // Write hit.
        write_hit_block = cache[index][hit_way].data;
        write_hit_block[offset*8 +: CPU_DW] = cpu_if.wdata[CPU_DW-1:0];

        // Write miss.
        write_miss_block = mem_if.rdata[BLOCK_BITS-1:0];
        write_miss_block[req_offset*8 +: CPU_DW] = req_wdata;
    end

    // LRU replacement
    logic lru_update_en;
    logic [INDEX_BITS-1:0] lru_update_set;
    logic [WAY_BITS-1:0]   lru_update_way;

    basic_lru #(
        .NUM_SETS(NUM_SETS),
        .NUM_WAYS(ASSOC),
        .SET_BITS(INDEX_BITS),
        .WAY_BITS(WAY_BITS)
    ) lru_inst (
        .clk(clk),
        .rst(rst),
        .update_en(lru_update_en),
        .update_set(lru_update_set),
        .update_way(lru_update_way),
        .lookup_set(index),
        .victim_way(victim_way)
    );

    always_comb begin
        lru_update_en  = 1'b0;
        lru_update_set = '0;
        lru_update_way = '0;

        if (accept_req && hit) begin
            lru_update_en  = 1'b1;
            lru_update_set = index;
            lru_update_way = hit_way;
        end else if (state == READ_RESP || state == WRITE_MISS_UPDATE) begin
            lru_update_en  = 1'b1;
            lru_update_set = req_index;
            lru_update_way = req_way;
        end
    end


    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state      <= IDLE;
            req_addr   <= '0;
            req_rw     <= 1'b0;
            req_wdata  <= '0;
            req_offset <= '0;
            req_index  <= '0;
            req_tag    <= '0;
            req_way    <= '0;

            for (int s = 0; s < NUM_SETS; s++) begin
                for (int w = 0; w < ASSOC; w++) begin
                    cache[s][w].valid <= 1'b0;
                    cache[s][w].tag   <= '0;
                    cache[s][w].data  <= '0;
                end
            end
        end else begin
            state <= next_state;

            if (accept_req) begin
                req_addr   <= cpu_if.addr;
                req_rw     <= cpu_if.rw;
                req_wdata  <= cpu_if.wdata[CPU_DW-1:0];
                req_offset <= offset;
                req_index  <= index;
                req_tag    <= tag;
                req_way    <= selected_way;
            end

            // Write hit: update cached block immediately.
            if (accept_req && hit && cpu_if.rw) begin
                cache[index][hit_way].data <= write_hit_block;
            end

            // Read miss refill.
            else if (state == READ_RESP) begin
                cache[req_index][req_way].valid <= 1'b1;
                cache[req_index][req_way].tag   <= req_tag;
                cache[req_index][req_way].data  <= mem_if.rdata;
            end
            // Write miss refill.
            else if (state == WRITE_MISS_UPDATE) begin
                cache[req_index][req_way].valid <= 1'b1;
                cache[req_index][req_way].tag   <= req_tag;
                cache[req_index][req_way].data  <= refill_updated_block;
            end
        end
    end

    // FSM outputs
    always_comb begin
        next_state = state;

        cpu_if.ready = 1'b0;
        cpu_if.rdata = '0;

        mem_if.req_valid = 1'b0;
        mem_if.rw        = 1'b0;
        mem_if.addr      = '0;
        mem_if.wdata     = '0;

        case (state)
            IDLE: begin
                if (cpu_if.req_valid) begin
                    if (hit) begin
                        cpu_if.ready = 1'b1;

                        if (!cpu_if.rw) begin
                            // Read hit.
                            cpu_if.rdata[CPU_DW-1:0] = cache[index][hit_way].data[offset*8 +: CPU_DW];
                        end else begin
                            // Write hit with write-through.
                            mem_if.req_valid = 1'b1;
                            mem_if.rw        = 1'b1;
                            mem_if.addr      = {cpu_if.addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                            mem_if.wdata[BLOCK_BITS-1:0] = write_hit_block;
                        end
                    end else begin
                        // Both read miss and write miss fetch the full block first.
                        mem_if.req_valid = 1'b1;
                        mem_if.rw        = 1'b0;
                        mem_if.addr      = {cpu_if.addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};

                        if (!cpu_if.rw)
                            next_state = READ_MISS;
                        else
                            next_state = WRITE_MISS_REFILL;
                    end
                end
            end

            READ_MISS: begin
                mem_if.req_valid = 1'b1;
                mem_if.rw        = 1'b0;
                mem_if.addr      = {req_addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
            
                if (mem_if.ready) begin
                    next_state = READ_RESP;
                end
            end

            READ_RESP: begin
                cpu_if.rdata = mem_if.rdata[req_offset*8 +: CPU_DW];
                cpu_if.ready = 1'b1;
                next_state   = IDLE;
            end

            WRITE_MISS_REFILL: begin
                mem_if.req_valid = 1'b1;
                mem_if.rw        = 1'b0;
                mem_if.addr      = {req_addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
            
                if (mem_if.ready) begin
                    next_state = WRITE_MISS_UPDATE;
                end
            end
            
            WRITE_MISS_UPDATE: begin
                next_state = WRITE_THROUGH;
            end
            
            WRITE_THROUGH: begin
                mem_if.req_valid = 1'b1;
                mem_if.rw        = 1'b1;
                mem_if.addr      = {req_addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                mem_if.wdata     = cache[req_index][req_way].data;
            
                cpu_if.ready = 1'b1;
                next_state   = IDLE;
            end

            default: begin
                next_state = IDLE;
            end
        endcase
    end

endmodule

