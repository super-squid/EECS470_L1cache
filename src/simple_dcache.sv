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
    dcache_if.cpu       cpu_if,
    dcache_if.cache_mem mem_if,

    // Eviction outputs: valid for one cycle whenever a clean valid L1 line is displaced.
    // Dirty evictions are written back to DRAM via WRITEBACK state, not forwarded here.
    output logic                      evict_valid,
    output logic [AW-1:0]             evict_addr,
    output logic [BLOCK_BYTES*8-1:0]  evict_data
);

    // Derived parameters
    localparam OFFSET_BITS = $clog2(BLOCK_BYTES);
    localparam INDEX_BITS  = $clog2(CACHE_BYTES / (BLOCK_BYTES * ASSOC));
    localparam TAG_BITS    = AW - INDEX_BITS - OFFSET_BITS;
    localparam NUM_LINES    = CACHE_BYTES / BLOCK_BYTES;
    localparam NUM_SETS     = NUM_LINES / ASSOC;

    typedef struct packed {
        logic valid;
        logic dirty;
        logic [TAG_BITS-1:0] tag;
        logic [BLOCK_BYTES*8-1:0] data;
    } cache_line_t;

    cache_line_t cache [0:NUM_LINES-1];

    logic [OFFSET_BITS-1:0] offset;
    logic [INDEX_BITS-1:0]  index;
    logic [TAG_BITS-1:0]    tag;

    logic hit;
    logic [TAG_BITS-1:0] cache_tag;
    logic cache_valid;

    typedef enum logic [1:0] {
        IDLE,
        READ_MISS,
        WRITE_MISS_REFILL,
        WRITEBACK
    } state_t;
    state_t state, next_state;

    logic [AW-1:0] req_addr;
    logic          req_rw;
    logic [DW-1:0] req_wdata;
    logic [OFFSET_BITS-1:0] req_offset;
    logic [INDEX_BITS-1:0]  req_index;
    logic [TAG_BITS-1:0]    req_tag;
    logic accept_req;
    logic [BLOCK_BYTES*8-1:0] refill_updated_block;

    assign accept_req = (state == IDLE) && cpu_if.req_valid;

    always_comb begin
        offset = cpu_if.addr[OFFSET_BITS-1:0];
        index  = cpu_if.addr[OFFSET_BITS +: INDEX_BITS];
        tag    = cpu_if.addr[AW-1:OFFSET_BITS+INDEX_BITS];
        refill_updated_block = mem_if.rdata;
        refill_updated_block[req_offset*8 +: DW] = req_wdata;
    end

    assign cache_tag   = cache[index].tag;
    assign cache_valid = cache[index].valid;
    assign hit = cache_valid && (cache_tag == tag);

    // Only forward clean evictions to the victim cache; dirty lines are already
    // written back to DRAM via the WRITEBACK state so the victim cache must not
    // see them (it would double-count or serve stale data).
    assign evict_valid = ((state == READ_MISS) || (state == WRITE_MISS_REFILL))
                         && mem_if.ready
                         && cache[req_index].valid
                         && !cache[req_index].dirty;
    assign evict_addr  = {cache[req_index].tag, req_index, {OFFSET_BITS{1'b0}}};
    assign evict_data  = cache[req_index].data;

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
                cache[i].dirty <= 1'b0;
            end
        end else begin
            state <= next_state;

            if (accept_req) begin
                req_addr   <= cpu_if.addr;
                req_rw     <= cpu_if.rw;
                req_wdata  <= cpu_if.wdata;
                req_offset <= offset;
                req_index  <= index;
                req_tag    <= tag;
            end

            // Read miss fill: line is clean (sourced from DRAM)
            if (state == READ_MISS && mem_if.ready) begin
                cache[req_index].valid <= 1'b1;
                cache[req_index].dirty <= 1'b0;
                cache[req_index].tag   <= req_tag;
                cache[req_index].data  <= mem_if.rdata;
            end

            // Write miss: fill with modified block and mark dirty
            else if (state == WRITE_MISS_REFILL && mem_if.ready) begin
                cache[req_index].valid <= 1'b1;
                cache[req_index].dirty <= 1'b1;
                cache[req_index].tag   <= req_tag;
                cache[req_index].data  <= refill_updated_block;
            end

            // Write hit: update word in cache and mark dirty; DRAM write deferred to eviction
            else if (accept_req && hit && cpu_if.rw == 1'b1) begin
                cache[index].data[offset*8 +: DW] <= cpu_if.wdata;
                cache[index].dirty <= 1'b1;
            end
        end
    end

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
                    if (hit) begin
                        if (!cpu_if.rw) begin   // read hit
                            cpu_if.rdata = cache[index].data[offset*8 +: DW];
                            cpu_if.ready = 1;
                        end else begin           // write hit: update cache only, no DRAM
                            cpu_if.ready = 1;
                        end
                    end else begin
                        if (cache[index].valid && cache[index].dirty) begin
                            // Dirty eviction: write old line to DRAM before fetching new one
                            mem_if.req_valid = 1'b1;
                            mem_if.rw        = 1'b1;
                            mem_if.addr      = {cache[index].tag, index, {OFFSET_BITS{1'b0}}};
                            mem_if.wdata     = cache[index].data;
                            next_state       = WRITEBACK;
                        end else begin
                            // Clean eviction (or cold miss): fetch new line directly
                            mem_if.req_valid = 1'b1;
                            mem_if.rw        = 1'b0;
                            mem_if.addr      = {cpu_if.addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                            next_state       = cpu_if.rw ? WRITE_MISS_REFILL : READ_MISS;
                        end
                    end
                end
            end

            READ_MISS: begin
                if (mem_if.ready) begin
                    cpu_if.rdata = mem_if.rdata[req_offset*8 +: DW];
                    cpu_if.ready = 1;
                    next_state   = IDLE;
                end
            end

            WRITE_MISS_REFILL: begin
                if (mem_if.ready) begin
                    cpu_if.ready = 1;
                    next_state   = IDLE;
                end
            end

            WRITEBACK: begin
                if (mem_if.ready) begin
                    // Dirty writeback acknowledged; now fetch the requested line
                    mem_if.req_valid = 1'b1;
                    mem_if.rw        = 1'b0;
                    mem_if.addr      = {req_addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                    next_state       = req_rw ? WRITE_MISS_REFILL : READ_MISS;
                end else begin
                    // Hold writeback request until DRAM acknowledges
                    mem_if.req_valid = 1'b1;
                    mem_if.rw        = 1'b1;
                    mem_if.addr      = {cache[req_index].tag, req_index, {OFFSET_BITS{1'b0}}};
                    mem_if.wdata     = cache[req_index].data;
                end
            end
        endcase
    end
endmodule
