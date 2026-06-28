// next_line_prefetcher.sv
//
// A simple next-line prefetcher placed between simple_dcache and dram_model.
// It does not modify the L1 cache internals. Instead, it keeps one prefetched
// cache line in a small buffer. If L1 later misses on that line, the buffer
// returns the block immediately and L1 fills itself through its normal refill
// path.
//
// Policy:
//   - After every demand read miss that goes to downstream memory, prefetch the
//     next sequential cache line.
//   - After every prefetch-buffer hit, prefetch the next sequential cache line.
//   - Demand requests always have priority. A demand arriving while a prefetch
//     is in flight is latched and served as soon as the in-flight read returns.
//   - Writes are forwarded to memory and invalidate a matching buffered line.

module next_line_prefetcher #(
    parameter AW          = 32,
    parameter BLOCK_BYTES = 16
) (
    input  logic clk,
    input  logic rst,

    // L1-side: acts as memory for simple_dcache.
    dcache_if.dram      upstream,

    // DRAM-side: acts as requester toward dram_model.
    dcache_if.cache_mem downstream,

    // Optional observation signals for verification/performance counters.
    output logic                 prefetch_busy,
    output logic                 prefetch_valid,
    output logic [AW-1:0]        prefetch_addr,
    output logic                 prefetch_issue_pulse,
    output logic                 prefetch_fill_pulse,
    output logic                 prefetch_hit_pulse,
    output logic [31:0]          prefetch_issue_count,
    output logic [31:0]          prefetch_fill_count,
    output logic [31:0]          prefetch_hit_count
);

    localparam OFFSET_BITS = $clog2(BLOCK_BYTES);
    localparam BLOCK_BITS  = BLOCK_BYTES * 8;
    localparam logic [AW-1:0] BLOCK_BYTES_AW = BLOCK_BYTES;

    typedef enum logic [2:0] {
        IDLE,
        HIT_RESPOND,
        DEMAND_WAIT,
        PREFETCH_WAIT,
        PENDING_WAIT
    } state_t;

    state_t state;

    logic [AW-1:0]        buffer_addr;
    logic [BLOCK_BITS-1:0] buffer_data;
    logic                  buffer_valid;

    logic [AW-1:0]        active_addr;
    logic                  active_rw;

    logic [AW-1:0]        hit_resp_addr;
    logic [BLOCK_BITS-1:0] hit_resp_data;

    logic                  pending_valid;
    logic [AW-1:0]        pending_addr;
    logic                  pending_rw;
    logic [BLOCK_BITS-1:0] pending_wdata;

    function automatic logic [AW-1:0] block_align(input logic [AW-1:0] addr);
        block_align = {addr[AW-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
    endfunction

    function automatic logic [AW-1:0] next_line(input logic [AW-1:0] addr);
        next_line = block_align(addr) + BLOCK_BYTES_AW;
    endfunction

    logic [AW-1:0] incoming_addr_aligned;
    logic          incoming_buffer_hit;
    logic          eff_pending_valid;
    logic [AW-1:0] eff_pending_addr;
    logic          eff_pending_rw;
    logic [BLOCK_BITS-1:0] eff_pending_wdata;
    logic          eff_pending_buffer_hit;
    logic          eff_pending_matches_prefetch;

    assign incoming_addr_aligned = block_align(upstream.addr);
    assign incoming_buffer_hit   = buffer_valid && !upstream.rw &&
                                   (incoming_addr_aligned == buffer_addr);
    assign eff_pending_valid = pending_valid ||
                               ((state == PREFETCH_WAIT) && upstream.req_valid);
    assign eff_pending_addr  = pending_valid ? pending_addr : incoming_addr_aligned;
    assign eff_pending_rw    = pending_valid ? pending_rw   : upstream.rw;
    assign eff_pending_wdata = pending_valid ? pending_wdata : upstream.wdata;
    assign eff_pending_buffer_hit = buffer_valid && !eff_pending_rw &&
                                    (eff_pending_addr == buffer_addr);
    assign eff_pending_matches_prefetch = eff_pending_valid && !eff_pending_rw &&
                                          (eff_pending_addr == active_addr);

    assign prefetch_busy  = (state == PREFETCH_WAIT);
    assign prefetch_valid = buffer_valid;
    assign prefetch_addr  = buffer_addr;

    // Combinational outputs.
    always_comb begin
        upstream.ready        = 1'b0;
        upstream.rdata        = '0;

        downstream.req_valid  = 1'b0;
        downstream.rw         = 1'b0;
        downstream.addr       = '0;
        downstream.wdata      = '0;

        prefetch_issue_pulse  = 1'b0;
        prefetch_fill_pulse   = 1'b0;
        prefetch_hit_pulse    = 1'b0;

        case (state)
            IDLE: begin
                if (upstream.req_valid) begin
                    if (incoming_buffer_hit) begin
                        // Response is intentionally delayed until HIT_RESPOND
                        // so simple_dcache has entered READ_MISS/WRITE_MISS.
                    end else begin
                        downstream.req_valid = 1'b1;
                        downstream.rw        = upstream.rw;
                        downstream.addr      = incoming_addr_aligned;
                        downstream.wdata     = upstream.wdata;
                    end
                end
            end

            HIT_RESPOND: begin
                upstream.ready       = 1'b1;
                upstream.rdata       = hit_resp_data;
                prefetch_hit_pulse   = 1'b1;

                downstream.req_valid = 1'b1;
                downstream.rw        = 1'b0;
                downstream.addr      = next_line(hit_resp_addr);
                downstream.wdata     = '0;
                prefetch_issue_pulse = 1'b1;
            end

            DEMAND_WAIT: begin
                if (downstream.ready) begin
                    upstream.ready = 1'b1;
                    upstream.rdata = downstream.rdata;

                    if (!active_rw) begin
                        downstream.req_valid = 1'b1;
                        downstream.rw        = 1'b0;
                        downstream.addr      = next_line(active_addr);
                        downstream.wdata     = '0;
                        prefetch_issue_pulse = 1'b1;
                    end
                end
            end

            PREFETCH_WAIT: begin
                if (downstream.ready) begin
                    prefetch_fill_pulse = 1'b1;

                    if (pending_valid && eff_pending_matches_prefetch) begin
                        upstream.ready       = 1'b1;
                        upstream.rdata       = downstream.rdata;
                        prefetch_hit_pulse   = 1'b1;

                        downstream.req_valid = 1'b1;
                        downstream.rw        = 1'b0;
                        downstream.addr      = next_line(eff_pending_addr);
                        downstream.wdata     = '0;
                        prefetch_issue_pulse = 1'b1;
                    end else if (eff_pending_valid) begin
                        if (pending_valid && eff_pending_buffer_hit) begin
                            upstream.ready       = 1'b1;
                            upstream.rdata       = buffer_data;
                            prefetch_hit_pulse   = 1'b1;

                            downstream.req_valid = 1'b1;
                            downstream.rw        = 1'b0;
                            downstream.addr      = next_line(eff_pending_addr);
                            downstream.wdata     = '0;
                            prefetch_issue_pulse = 1'b1;
                        end else begin
                            downstream.req_valid = 1'b1;
                            downstream.rw        = eff_pending_rw;
                            downstream.addr      = eff_pending_addr;
                            downstream.wdata     = eff_pending_wdata;
                        end
                    end
                end
            end

            PENDING_WAIT: begin
                if (downstream.ready) begin
                    upstream.ready = 1'b1;
                    upstream.rdata = downstream.rdata;

                    if (!active_rw) begin
                        downstream.req_valid = 1'b1;
                        downstream.rw        = 1'b0;
                        downstream.addr      = next_line(active_addr);
                        downstream.wdata     = '0;
                        prefetch_issue_pulse = 1'b1;
                    end
                end
            end

            default: ;
        endcase
    end

    // State, buffer, and counter updates.
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state                <= IDLE;
            buffer_valid         <= 1'b0;
            buffer_addr          <= '0;
            buffer_data          <= '0;
            active_addr          <= '0;
            active_rw            <= 1'b0;
            hit_resp_addr        <= '0;
            hit_resp_data        <= '0;
            pending_valid        <= 1'b0;
            pending_addr         <= '0;
            pending_rw           <= 1'b0;
            pending_wdata        <= '0;
            prefetch_issue_count <= 32'd0;
            prefetch_fill_count  <= 32'd0;
            prefetch_hit_count   <= 32'd0;
        end else begin
            if (prefetch_issue_pulse)
                prefetch_issue_count <= prefetch_issue_count + 32'd1;
            if (prefetch_fill_pulse)
                prefetch_fill_count <= prefetch_fill_count + 32'd1;
            if (prefetch_hit_pulse)
                prefetch_hit_count <= prefetch_hit_count + 32'd1;

            if (state == PREFETCH_WAIT && upstream.req_valid &&
                !pending_valid && !downstream.ready) begin
                pending_valid <= 1'b1;
                pending_addr  <= incoming_addr_aligned;
                pending_rw    <= upstream.rw;
                pending_wdata <= upstream.wdata;
            end

            case (state)
                IDLE: begin
                    pending_valid <= 1'b0;

                    if (upstream.req_valid) begin
                        if (incoming_buffer_hit) begin
                            hit_resp_addr <= incoming_addr_aligned;
                            hit_resp_data <= buffer_data;
                            buffer_valid  <= 1'b0;
                            state         <= HIT_RESPOND;
                        end else begin
                            active_addr        <= incoming_addr_aligned;
                            active_rw          <= upstream.rw;

                            if (upstream.rw && buffer_valid &&
                                (incoming_addr_aligned == buffer_addr)) begin
                                buffer_valid <= 1'b0;
                            end

                            state <= DEMAND_WAIT;
                        end
                    end
                end

                HIT_RESPOND: begin
                    active_addr <= next_line(hit_resp_addr);
                    active_rw   <= 1'b0;
                    state       <= PREFETCH_WAIT;
                end

                DEMAND_WAIT: begin
                    if (downstream.ready) begin
                        if (!active_rw) begin
                            active_addr        <= next_line(active_addr);
                            active_rw          <= 1'b0;
                            state              <= PREFETCH_WAIT;
                        end else begin
                            state <= IDLE;
                        end
                    end
                end

                PREFETCH_WAIT: begin
                    if (downstream.ready) begin
                        buffer_valid <= 1'b1;
                        buffer_addr  <= active_addr;
                        buffer_data  <= downstream.rdata;

                        if (eff_pending_matches_prefetch) begin
                            if (pending_valid) begin
                                active_addr   <= next_line(eff_pending_addr);
                                active_rw     <= 1'b0;
                                pending_valid <= 1'b0;
                                state         <= PREFETCH_WAIT;
                            end else begin
                                hit_resp_addr <= eff_pending_addr;
                                hit_resp_data <= downstream.rdata;
                                buffer_valid  <= 1'b0;
                                state         <= HIT_RESPOND;
                            end
                        end else if (eff_pending_valid) begin
                            if (eff_pending_buffer_hit) begin
                                if (pending_valid) begin
                                    buffer_valid  <= 1'b0;
                                    active_addr   <= next_line(eff_pending_addr);
                                    active_rw     <= 1'b0;
                                    pending_valid <= 1'b0;
                                    state         <= PREFETCH_WAIT;
                                end else begin
                                    hit_resp_addr <= eff_pending_addr;
                                    hit_resp_data <= buffer_data;
                                    state         <= HIT_RESPOND;
                                end
                            end else begin
                                active_addr        <= eff_pending_addr;
                                active_rw          <= eff_pending_rw;
                                pending_valid      <= 1'b0;

                                if (eff_pending_rw && buffer_valid &&
                                    (eff_pending_addr == buffer_addr)) begin
                                    buffer_valid <= 1'b0;
                                end

                                state <= PENDING_WAIT;
                            end
                        end else begin
                            state <= IDLE;
                        end
                    end
                end

                PENDING_WAIT: begin
                    if (downstream.ready) begin
                        if (!active_rw) begin
                            active_addr        <= next_line(active_addr);
                            active_rw          <= 1'b0;
                            state              <= PREFETCH_WAIT;
                        end else begin
                            state <= IDLE;
                        end
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
