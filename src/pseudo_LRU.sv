// pseudo_LRU.sv
// Tree-based pseudo-LRU replacement policy.
//
// Bit convention:
//   0: left subtree is older and should be searched for a victim
//   1: right subtree is older and should be searched for a victim
//
// On update, each bit on the accessed way's path is pointed away from the
// accessed way, making that way/subtree less likely to be evicted next.

`timescale 1ns/1ps

/* verilator lint_off DECLFILENAME */
module basic_pseudo_lru #(
    parameter NUM_SETS = 16,
    parameter NUM_WAYS = 2,
    parameter SET_BITS = (NUM_SETS <= 1) ? 1 : $clog2(NUM_SETS),
    parameter WAY_BITS = (NUM_WAYS <= 1) ? 1 : $clog2(NUM_WAYS),
    parameter LEVELS = (NUM_WAYS <= 1) ? 1 : $clog2(NUM_WAYS),
    parameter PLRU_BITS = (NUM_WAYS <= 1) ? 1 : (NUM_WAYS - 1)
) (
    input  logic clk,
    input  logic rst,

    input  logic update_en,
    input  logic [SET_BITS-1:0] update_set,
    input  logic [WAY_BITS-1:0] update_way,

    input  logic [SET_BITS-1:0] lookup_set,
    output logic [WAY_BITS-1:0] victim_way
);

    logic [PLRU_BITS-1:0] tree_bits [0:NUM_SETS-1];

    initial begin
        if (NUM_SETS < 1) begin
            $fatal(1, "NUM_SETS must be at least 1.");
        end
        if (NUM_WAYS < 1) begin
            $fatal(1, "NUM_WAYS must be at least 1.");
        end
        if ((NUM_WAYS > 1) && ((NUM_WAYS & (NUM_WAYS - 1)) != 0)) begin
            $fatal(1, "basic_pseudo_lru requires NUM_WAYS to be a power of two.");
        end
    end

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int s = 0; s < NUM_SETS; s++) begin
                tree_bits[s] <= '0;
            end
        end else if (update_en && (NUM_WAYS > 1)) begin
            int node;
            logic direction;

            node = 0;
            for (int level = 0; level < LEVELS; level++) begin
                direction = update_way[LEVELS - 1 - level];
                tree_bits[update_set][node] <= ~direction;

                if (direction == 1'b0) begin
                    node = (2 * node) + 1;
                end else begin
                    node = (2 * node) + 2;
                end
            end
        end
    end

    always_comb begin
        victim_way = '0;

        if (NUM_WAYS > 1) begin
            int node;
            logic direction;

            node = 0;
            for (int level = 0; level < LEVELS; level++) begin
                direction = tree_bits[lookup_set][node];
                victim_way[LEVELS - 1 - level] = direction;

                if (direction == 1'b0) begin
                    node = (2 * node) + 1;
                end else begin
                    node = (2 * node) + 2;
                end
            end
        end
    end

endmodule
/* verilator lint_on DECLFILENAME */
