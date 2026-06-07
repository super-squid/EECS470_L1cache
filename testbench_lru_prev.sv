// testbench_lru.sv
module tb_basic_lru;
    parameter NUM_SETS = 4;
    parameter NUM_WAYS = 4;
    parameter SET_BITS = $clog2(NUM_SETS);
    parameter WAY_BITS = $clog2(NUM_WAYS);

    logic clk, rst;
    logic update_en;
    logic [SET_BITS-1:0] update_set;
    logic [WAY_BITS-1:0] update_way;
    logic [SET_BITS-1:0] lookup_set;
    logic [WAY_BITS-1:0] victim_way;

    basic_lru #(
        .NUM_SETS(NUM_SETS),
        .NUM_WAYS(NUM_WAYS)
    ) dut (
        .clk(clk),
        .rst(rst),
        .update_en(update_en),
        .update_set(update_set),
        .update_way(update_way),
        .lookup_set(lookup_set),
        .victim_way(victim_way)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    task automatic access_way(input [SET_BITS-1:0] set, input [WAY_BITS-1:0] way);
        begin
            update_en = 1;
            update_set = set;
            update_way = way;
            @(posedge clk);
            update_en = 0;
            #1;
        end
    endtask

    task automatic check_victim(input [WAY_BITS-1:0] expected);
        begin
            #1;
            if (victim_way !== expected) begin
                $display("FAILED: victim=%0d expected=%0d", victim_way, expected);
                $finish;
            end else begin
                $display("PASSED: victim=%0d", victim_way);
            end
        end
    endtask

    initial begin
        rst = 1;
        update_en = 0;
        update_set = 0;
        update_way = 0;
        lookup_set = 0;

        repeat (2) @(posedge clk);
        rst = 0;
        #1;

        $display("Test 1: after reset, way 3 should be LRU in set 0");
        check_victim(3);

        $display("Test 2: access way 3, so way 2 becomes LRU");
        access_way(0, 3);
        check_victim(2);

        $display("Test 3: access way 2, then way 1 becomes LRU");
        access_way(0, 2);
        check_victim(1);

        $display("Test 4: access way 1, then way 0 becomes LRU");
        access_way(0, 1);
        check_victim(0);

        $display("Test 5: set 1 should still be independent");
        lookup_set = 1;
        check_victim(3);

        $display("All configurable LRU tests passed.");
        $finish;
    end
endmodule
