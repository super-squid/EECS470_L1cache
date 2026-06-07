// configurable_lru.sv

module configurable_lru #(
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

    logic [WAY_BITS-1:0] age [0:NUM_SETS-1][0:NUM_WAYS-1];
    logic [WAY_BITS-1:0] old_age;

    // age = 0 means most recently used
    // largest age means least recently used
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int s = 0; s < NUM_SETS; s++) begin
                for (int w = 0; w < NUM_WAYS; w++) begin
                    age[s][w] <= w[WAY_BITS-1:0];
                end
            end
        end else if (update_en) begin
            old_age = age[update_set][update_way];

            for (int w = 0; w < NUM_WAYS; w++) begin
                if (w[WAY_BITS-1:0] == update_way) begin
                    age[update_set][w] <= '0;
                end else if (age[update_set][w] < old_age) begin
                    age[update_set][w] <= age[update_set][w] + 1'b1;
                end
            end
        end
    end

    always_comb begin
        victim_way = '0;
        for (int w = 1; w < NUM_WAYS; w++) begin
            if (age[lookup_set][w] > age[lookup_set][victim_way]) begin
                victim_way = w[WAY_BITS-1:0];
            end
        end
    end
endmodule
