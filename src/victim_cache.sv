// victim_cache.sv
// 4-entry fully-associative victim cache, placed between simple_dcache and dram_model.
// Stores lines evicted from L1 to absorb conflict misses before they reach DRAM.
//
// Upstream port (dcache_if.dram):   receives miss requests from simple_dcache.
// Downstream port (dcache_if.cache_mem): forwards misses to dram_model.
// Eviction ports: receive the line being displaced from L1 whenever L1 fills a slot.
//
// Read hit:  returns block directly in one cycle, no DRAM access.
// Read miss: forwards to DRAM, absorbs any evicted L1 line on return.
// Write:     forwarded transparently to DRAM (VC holds only clean read data).

module victim_cache #(
    parameter AW           = 32,
    parameter BLOCK_BYTES  = 16,
    parameter NUM_VC_LINES = 4
) (
    input  logic clk,
    input  logic rst,

    // L1-side: VC acts as "memory" for simple_dcache
    dcache_if.dram      upstream,

    // DRAM-side: VC acts as requester toward dram_model
    dcache_if.cache_mem downstream,

    // Eviction notification from L1 (combinatorial, valid when upstream.ready == 1
    // during a READ_MISS or WRITE_MISS_REFILL in simple_dcache)
    input  logic                      evict_valid,
    input  logic [AW-1:0]             evict_addr,
    input  logic [BLOCK_BYTES*8-1:0]  evict_data
);

    localparam OFFSET_BITS = $clog2(BLOCK_BYTES);
    localparam TAG_BITS    = AW - OFFSET_BITS;   // full block address tag
    localparam WAY_BITS    = $clog2(NUM_VC_LINES);

    // VC storage
    typedef struct packed {
        logic                     valid;
        logic [TAG_BITS-1:0]      tag;
        logic [BLOCK_BYTES*8-1:0] data;
    } vc_line_t;

    vc_line_t vc [0:NUM_VC_LINES-1];

    // LRU replacement: 1 set, NUM_VC_LINES ways
    logic                lru_update_en;
    logic [WAY_BITS-1:0] lru_update_way;
    logic [WAY_BITS-1:0] victim_way;     // combinatorial: current LRU victim slot

    basic_lru #(
        .NUM_SETS(1),
        .NUM_WAYS(NUM_VC_LINES)
    ) lru_inst (
        .clk        (clk),
        .rst        (rst),
        .update_en  (lru_update_en),
        .update_set ('0),
        .update_way (lru_update_way),
        .lookup_set ('0),
        .victim_way (victim_way)
    );

    // FSM
    typedef enum logic [1:0] { IDLE, VC_HIT, DRAM_WAIT } state_t;
    state_t state;

    logic [WAY_BITS-1:0] hit_way_lat;   // hit way latched when entering VC_HIT

    // --- Combinational hit search on the incoming upstream.addr ---
    logic [TAG_BITS-1:0] incoming_tag;
    logic                vc_incoming_hit;
    logic [WAY_BITS-1:0] vc_incoming_hit_way;

    assign incoming_tag = upstream.addr[AW-1:OFFSET_BITS];

    always_comb begin
        vc_incoming_hit     = 1'b0;
        vc_incoming_hit_way = '0;
        for (int i = 0; i < NUM_VC_LINES; i++) begin
            if (vc[i].valid && (vc[i].tag == incoming_tag)) begin
                vc_incoming_hit     = 1'b1;
                vc_incoming_hit_way = i[WAY_BITS-1:0];
            end
        end
    end

    // --- Combinational outputs ---
    always_comb begin
        upstream.ready       = 1'b0;
        upstream.rdata       = '0;
        downstream.req_valid = 1'b0;
        downstream.rw        = 1'b0;
        downstream.addr      = '0;
        downstream.wdata     = '0;
        lru_update_en        = 1'b0;
        lru_update_way       = '0;

        case (state)
            IDLE: begin
                if (upstream.req_valid) begin
                    if (!upstream.rw && vc_incoming_hit) begin
                        // Read hit: will respond from VC_HIT next cycle; no DRAM needed
                    end else begin
                        // Read miss or write: send to DRAM this cycle so DRAM latches it
                        downstream.req_valid = 1'b1;
                        downstream.rw        = upstream.rw;
                        downstream.addr      = upstream.addr;
                        downstream.wdata     = upstream.wdata;
                    end
                end
            end

            VC_HIT: begin
                // Return hit line to L1; L1 evicts its displaced line simultaneously
                upstream.ready = 1'b1;
                upstream.rdata = vc[hit_way_lat].data;
                // Mark the returned way as MRU so the evicted line lands in victim_way
                lru_update_en  = 1'b1;
                lru_update_way = hit_way_lat;
            end

            DRAM_WAIT: begin
                if (downstream.ready) begin
                    upstream.ready = 1'b1;
                    upstream.rdata = downstream.rdata;
                    // Absorb evicted L1 line into the LRU victim slot
                    if (evict_valid) begin
                        lru_update_en  = 1'b1;
                        lru_update_way = victim_way;
                    end
                end
            end

            default: ;
        endcase
    end

    // --- Sequential: state transitions and VC storage ---
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= IDLE;
            hit_way_lat <= '0;
            for (int i = 0; i < NUM_VC_LINES; i++)
                vc[i].valid <= 1'b0;
        end else begin
            case (state)
                IDLE: begin
                    if (upstream.req_valid) begin
                        if (!upstream.rw && vc_incoming_hit) begin
                            hit_way_lat <= vc_incoming_hit_way;
                            state       <= VC_HIT;
                        end else begin
                            state <= DRAM_WAIT;
                        end
                    end
                end

                VC_HIT: begin
                    // Move the hit line to L1 by invalidating it here.
                    // If victim_way == hit_way_lat and evict_valid is true, the
                    // valid=1 write below wins (last NBA write in same always_ff),
                    // so the evicted line correctly replaces the freed slot.
                    vc[hit_way_lat].valid <= 1'b0;

                    // Absorb the L1 evicted line into the current LRU victim slot.
                    if (evict_valid) begin
                        vc[victim_way].valid <= 1'b1;
                        vc[victim_way].tag   <= evict_addr[AW-1:OFFSET_BITS];
                        vc[victim_way].data  <= evict_data;
                    end
                    state <= IDLE;
                end

                DRAM_WAIT: begin
                    if (downstream.ready) begin
                        if (evict_valid) begin
                            vc[victim_way].valid <= 1'b1;
                            vc[victim_way].tag   <= evict_addr[AW-1:OFFSET_BITS];
                            vc[victim_way].data  <= evict_data;
                        end
                        state <= IDLE;
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
