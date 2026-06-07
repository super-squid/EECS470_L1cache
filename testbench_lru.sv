// testbench_configurable_lru.sv
module tb_basic_lru;
    parameter NUM_SETS = 4;
    parameter NUM_WAYS = 4;
    parameter SET_BITS = (NUM_SETS <= 1) ? 1 : $clog2(NUM_SETS);
    parameter WAY_BITS = (NUM_WAYS <= 1) ? 1 : $clog2(NUM_WAYS);

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

    task automatic touch(input logic [SET_BITS-1:0] set,
                         input logic [WAY_BITS-1:0] way);
        begin
            @(negedge clk);
            update_en = 1;
            update_set = set;
            update_way = way;
            @(negedge clk);
            update_en = 0;
        end
    endtask

    task automatic check_victim(input logic [SET_BITS-1:0] set,
                                input logic [WAY_BITS-1:0] expected);
        begin
            lookup_set = set;
            #1;
            if (victim_way !== expected) begin
                $display("FAILED: set=%0d victim=%0d expected=%0d", set, victim_way, expected);
                $finish;
            end else begin
                $display("PASSED: set=%0d victim=%0d", set, victim_way);
            end
        end
    endtask

    initial begin
        rst = 1;
        update_en = 0;
        update_set = '0;
        update_way = '0;
        lookup_set = '0;

        repeat (3) @(posedge clk);
        rst = 0;
        @(posedge clk);

        check_victim(0, NUM_WAYS-1);

        touch(0, 3);
        check_victim(0, 2);

        touch(0, 2);
        check_victim(0, 1);

        touch(0, 1);
        check_victim(0, 0);

        touch(0, 0);
        check_victim(0, 3);

        $display("All configurable LRU tests passed.");
        $finish;
    end
endmodule
