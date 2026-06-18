// fifo_replacement.sv
`timescale 1ns/1ps

module basic_fifo #(
    parameter NUM_SETS = 16,
    parameter NUM_WAYS = 2,
    parameter SET_BITS = (NUM_SETS <= 1) ? 1 : $clog2(NUM_SETS),
    parameter WAY_BITS = (NUM_WAYS <= 1) ? 1 : $clog2(NUM_WAYS)
) (
    input  logic clk,
    input  logic rst,

    input  logic update_en,
    input  logic [SET_BITS-1:0] update_set,
    input  logic [WAY_BITS-1:0] update_way,
    input  logic [SET_BITS-1:0] lookup_set,
    
    output logic [WAY_BITS-1:0] victim_way
);

    logic [WAY_BITS-1:0] next_victim [0:NUM_SETS-1];

    // FIFO replacement order is determined only by insertion/replacement events.
    // Assert update_en when selected victim way for update_set has been filled.
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int s = 0; s < NUM_SETS; s++) begin
                next_victim[s] <= '0;
            end
        end else if (update_en) begin
            if (next_victim[update_set] == WAY_BITS'(NUM_WAYS - 1)) begin
                next_victim[update_set] <= '0;
            end else begin
                next_victim[update_set] <= next_victim[update_set] + 1'b1;
            end
        end
    end

    assign victim_way = next_victim[lookup_set];

endmodule
