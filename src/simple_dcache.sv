// simple_dcache.sv
module simple_dcache #(
    parameter AW = 32,
    parameter DW = 32,
    parameter CACHE_BYTES = 256,
    parameter BLOCK_BYTES = 16,
    parameter ASSOC = 1              // direct-mapped
) (
    input  logic clk,
    input  logic rst,
    dcache_if.mem       cpu_if,
    dcache_if.cache_mem mem_if,

    // Eviction outputs: valid for one cycle whenever a valid L1 line is displaced
    // (READ_MISS or WRITE_MISS_REFILL completion). Consumed by victim_cache.
    output logic                      evict_valid,
    output logic [AW-1:0]             evict_addr,
    output logic [BLOCK_BYTES*8-1:0]  evict_data
);

    // Derived parameters
    localparam OFFSET_BITS = $clog2(BLOCK_BYTES);
    localparam INDEX_BITS  = $clog2(CACHE_BYTES / (BLOCK_BYTES * ASSOC));
    localparam TAG_BITS    = AW - INDEX_BITS - OFFSET_BITS;
    localparam NUM_LINES    = CACHE_BYTES / BLOCK_BYTES;   // total lines across all ways
    localparam NUM_SETS     = NUM_LINES / ASSOC;

    // Cache storage: packed struct per line
    typedef struct packed {
        logic valid;
        logic [TAG_BITS-1:0] tag;
        logic [BLOCK_BYTES*8-1:0] data;
    } cache_line_t;

    cache_line_t cache [0:NUM_LINES-1];

    // Address field extraction
    logic [OFFSET_BITS-1:0] offset;
    logic [INDEX_BITS-1:0]  index;
    logic [TAG_BITS-1:0]    tag;

    // For direct-mapped, way = 0
    logic hit;
    logic [TAG_BITS-1:0] cache_tag;
    logic cache_valid;

    // FSM states
    typedef enum logic [1:0] {
        IDLE,
        READ_MISS,
        WRITE_MISS_REFILL,
        WRITE_THROUGH
    } state_t;
    state_t state, next_state;

    // Registered request
    logic [AW-1:0] req_addr;
    logic          req_rw;
    logic [DW-1:0] req_wdata;
    logic [OFFSET_BITS-1:0] req_offset;
    logic [INDEX_BITS-1:0]  req_index;
    logic [TAG_BITS-1:0]    req_tag;
    logic accept_req;
    logic [BLOCK_BYTES*8-1:0] updated_block;
    logic [BLOCK_BYTES*8-1:0] refill_updated_block;
    assign accept_req = (state == IDLE) && cpu_if.req_valid;
    // Combinational address decode
    always_comb begin
        offset = cpu_if.addr[OFFSET_BITS-1:0];
        index  = cpu_if.addr[OFFSET_BITS +: INDEX_BITS];
        tag    = cpu_if.addr[AW-1:OFFSET_BITS+INDEX_BITS];
        updated_block = cache[index].data;
        updated_block[offset*8 +: DW] = cpu_if.wdata;
        refill_updated_block = mem_if.rdata;
        refill_updated_block[req_offset*8 +: DW] = req_wdata;
    end

    // Hit detection (direct‑mapped)
    assign cache_tag   = cache[index].tag;
    assign cache_valid = cache[index].valid;
    assign hit = cache_valid && (cache_tag == tag);

    // Eviction signals: high for one cycle when a valid line is displaced on a miss.
    // cache[req_index] holds the OLD line (pre-fill) because the fill is registered.
    assign evict_valid = ((state == READ_MISS) || (state == WRITE_MISS_REFILL))
                         && mem_if.ready
                         && cache[req_index].valid;
    assign evict_addr  = {cache[req_index].tag, req_index, {OFFSET_BITS{1'b0}}};
    assign evict_data  = cache[req_index].data;

    // FSM sequential
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
    
            req_addr   <= '0;
            req_rw     <= 1'b0;
            req_wdata  <= '0;
            req_offset <= '0;
            req_index  <= '0;
            req_tag    <= '0;
    
            for (int i = 0; i < NUM_LINES; i++) begin
                cache[i].valid <= 1'b0;
            end
        end else begin
            state <= next_state;
    
            // Latch CPU request only when cache accepts a new request
            if (accept_req) begin
                req_addr   <= cpu_if.addr;
                req_rw     <= cpu_if.rw;
                req_wdata  <= cpu_if.wdata;
                req_offset <= offset;
                req_index  <= index;
                req_tag    <= tag;
            end
    
            // Cache fill on read miss
            if (state == READ_MISS && mem_if.ready) begin
                cache[req_index].valid <= 1'b1;
                cache[req_index].tag   <= req_tag;
                cache[req_index].data  <= mem_if.rdata;
            end
    
            // Cache fill on write miss, then update target word
            else if (state == WRITE_MISS_REFILL && mem_if.ready) begin
                cache[req_index].valid <= 1'b1;
                cache[req_index].tag   <= req_tag;
                cache[req_index].data  <= refill_updated_block;
            end
    
            // Write hit: update cache word
            else if (accept_req && hit && cpu_if.rw == 1'b1) begin
                cache[index].data[offset*8 +: DW] <= cpu_if.wdata;
            end
        end
    end
    
    // FSM combinational & outputs
    always_comb begin
        next_state = state;
        cpu_if.ready = 0;
        cpu_if.rdata = 0;
        mem_if.req_valid = 0;
        mem_if.rw = 0;
        mem_if.addr = 0;
        mem_if.wdata = 0;

        case (state)
            IDLE: begin
                if (cpu_if.req_valid) begin
                    // latch request

                    if (hit) begin
                        if (cpu_if.rw == 0) begin   // read hit
                            cpu_if.rdata = cache[index].data[offset*8 +: DW];
                            cpu_if.ready = 1;
                            next_state = IDLE;
                        end else begin              // write hit
                            // write-through: update cache (done in sequential block)
                            // also write to memory (same cycle)
                            mem_if.req_valid = 1;
                            mem_if.rw = 1;
                            mem_if.addr = {cpu_if.addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                            mem_if.wdata = updated_block;  // updated block
                            // CPU ready when memory accepts (immediate)
                            cpu_if.ready = 1;
                            next_state = IDLE;
                        end
                    end else begin
                        if (cpu_if.rw == 0) begin   // read miss
                            next_state = READ_MISS;
                            mem_if.req_valid = 1;
                            mem_if.rw = 0;
                            mem_if.addr = {cpu_if.addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                        end else begin              // write miss with write-allocate
                            next_state = WRITE_MISS_REFILL;
                            mem_if.req_valid = 1'b1;
                            mem_if.rw = 1'b0;  
                            mem_if.addr = {cpu_if.addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                        end
                    end
                end
            end

            READ_MISS: begin
                if (mem_if.ready) begin
                    cpu_if.rdata = mem_if.rdata[req_offset*8 +: DW];
                    cpu_if.ready = 1;
                    next_state = IDLE;
                end
            end

            WRITE_MISS_REFILL: begin
                if (mem_if.ready) begin
                    // The cache line will be filled and modified in always_ff.
                    // Move to a separate state to write the updated block back to DRAM.
                    next_state = WRITE_THROUGH;
                end
            end
            
            WRITE_THROUGH: begin
                mem_if.req_valid = 1'b1;
                mem_if.rw = 1'b1;
                mem_if.addr = {req_addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                mem_if.wdata = cache[req_index].data;
            
                cpu_if.ready = 1'b1;
                next_state = IDLE;
            end
        endcase
    end
endmodule