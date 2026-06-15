`timescale 1ns/1ps

module testbench_lru_full;

    logic clk;
    logic rst;

    always #5 clk = ~clk;

    localparam NUM_SETS_4 = 4;
    localparam NUM_WAYS_4 = 4;
    localparam SET_BITS_4 = $clog2(NUM_SETS_4);
    localparam WAY_BITS_4 = $clog2(NUM_WAYS_4);

    logic update_en_4;
    logic [SET_BITS_4-1:0] update_set_4;
    logic [WAY_BITS_4-1:0] update_way_4;
    logic [SET_BITS_4-1:0] lookup_set_4;
    logic [WAY_BITS_4-1:0] victim_way_4;

    basic_lru #(
        .NUM_SETS(NUM_SETS_4),
        .NUM_WAYS(NUM_WAYS_4)
    ) dut4 (
        .clk(clk),
        .rst(rst),
        .update_en(update_en_4),
        .update_set(update_set_4),
        .update_way(update_way_4),
        .lookup_set(lookup_set_4),
        .victim_way(victim_way_4)
    );

    localparam NUM_SETS_2 = 1;
    localparam NUM_WAYS_2 = 2;
    localparam SET_BITS_2 = 1;
    localparam WAY_BITS_2 = 1;

    logic update_en_2;
    logic [SET_BITS_2-1:0] update_set_2;
    logic [WAY_BITS_2-1:0] update_way_2;
    logic [SET_BITS_2-1:0] lookup_set_2;
    logic [WAY_BITS_2-1:0] victim_way_2;

    basic_lru #(
        .NUM_SETS(NUM_SETS_2),
        .NUM_WAYS(NUM_WAYS_2)
    ) dut2 (
        .clk(clk),
        .rst(rst),
        .update_en(update_en_2),
        .update_set(update_set_2),
        .update_way(update_way_2),
        .lookup_set(lookup_set_2),
        .victim_way(victim_way_2)
    );

    int ref_age_4 [0:NUM_SETS_4-1][0:NUM_WAYS_4-1];
    int ref_age_2 [0:NUM_SETS_2-1][0:NUM_WAYS_2-1];

    task print_ages_4(input int set);
        $display("    Set %0d reference ages: way0=%0d way1=%0d way2=%0d way3=%0d",
                 set,
                 ref_age_4[set][0],
                 ref_age_4[set][1],
                 ref_age_4[set][2],
                 ref_age_4[set][3]);
    endtask

    task print_ages_2;
        $display("    2-way reference ages: way0=%0d way1=%0d",
                 ref_age_2[0][0],
                 ref_age_2[0][1]);
    endtask

    task reset_ref_4;
        for (int s = 0; s < NUM_SETS_4; s++) begin
            for (int w = 0; w < NUM_WAYS_4; w++) begin
                ref_age_4[s][w] = w;
            end
        end
    endtask

    task reset_ref_2;
        for (int s = 0; s < NUM_SETS_2; s++) begin
            for (int w = 0; w < NUM_WAYS_2; w++) begin
                ref_age_2[s][w] = w;
            end
        end
    endtask

    function int expected_victim_4(input int set);
        int victim;
        victim = 0;
        for (int w = 1; w < NUM_WAYS_4; w++) begin
            if (ref_age_4[set][w] > ref_age_4[set][victim]) begin
                victim = w;
            end
        end
        return victim;
    endfunction

    function int expected_victim_2(input int set);
        int victim;
        victim = 0;
        for (int w = 1; w < NUM_WAYS_2; w++) begin
            if (ref_age_2[set][w] > ref_age_2[set][victim]) begin
                victim = w;
            end
        end
        return victim;
    endfunction

    task ref_update_4(input int set, input int way);
        int old_age;
        old_age = ref_age_4[set][way];

        for (int w = 0; w < NUM_WAYS_4; w++) begin
            if (w == way) begin
                ref_age_4[set][w] = 0;
            end else if (ref_age_4[set][w] < old_age) begin
                ref_age_4[set][w]++;
            end
        end
    endtask

    task ref_update_2(input int set, input int way);
        int old_age;
        old_age = ref_age_2[set][way];

        for (int w = 0; w < NUM_WAYS_2; w++) begin
            if (w == way) begin
                ref_age_2[set][w] = 0;
            end else if (ref_age_2[set][w] < old_age) begin
                ref_age_2[set][w]++;
            end
        end
    endtask

    task check_victim_4(input int set, input string msg);
        lookup_set_4 = set[SET_BITS_4-1:0];
        #1;
        ev = expected_victim_2(set); 
        $display("[CHECK 4-WAY] %s", msg);
        $display("    lookup_set=%0d expected_victim=%0d actual_victim=%0d",
                 set, ev, victim_way_4);
        print_ages_4(set);

        if (victim_way_4 !== ev[WAY_BITS_4-1:0]) begin
            $display("    RESULT: FAIL");
            $finish;
        end else begin
            $display("    RESULT: PASS");
        end
    endtask

    task check_victim_2(input int set, input string msg);
        lookup_set_2 = set[SET_BITS_2-1:0];
        #1;
        
        ev = expected_victim_2(set); 
        $display("[CHECK 2-WAY] %s", msg);
        $display("    expected_victim=%0d actual_victim=%0d",
                 ev, victim_way_2);
        print_ages_2();
        if (victim_way_2 !== ev[WAY_BITS_2-1:0]) begin
            $display("    RESULT: FAIL");
            $finish;
        end else begin
            $display("    RESULT: PASS");
        end
    endtask

    task touch_4(input int set, input int way, input string msg);
        $display("");
        $display("[UPDATE 4-WAY] %s", msg);
        $display("    Access set=%0d way=%0d", set, way);

        update_en_4 = 1'b1;
        update_set_4 = set[SET_BITS_4-1:0];
        update_way_4 = way[WAY_BITS_4-1:0];

        @(posedge clk);
        #1;

        ref_update_4(set, way);
        update_en_4 = 1'b0;

        check_victim_4(set, msg);
    endtask

    task touch_2(input int way, input string msg);
        $display("");
        $display("[UPDATE 2-WAY] %s", msg);
        $display("    Access way=%0d", way);

        update_en_2 = 1'b1;
        update_set_2 = '0;
        update_way_2 = way[WAY_BITS_2-1:0];

        @(posedge clk);
        #1;

        ref_update_2(0, way);
        update_en_2 = 1'b0;

        check_victim_2(0, msg);
    endtask

    task hold_check_4(input int set, input string msg);
        int expected_before;

        $display("");
        $display("[HOLD TEST] %s", msg);
        $display("    update_en = 0 for 3 cycles");
        $display("    Set being checked: %0d", set);

        lookup_set_4 = set[SET_BITS_4-1:0];
        #1;
        expected_before = expected_victim_4(set);

        update_en_4 = 1'b0;
        update_set_4 = set[SET_BITS_4-1:0];
        update_way_4 = 0;

        repeat (3) @(posedge clk);
        #1;

        $display("    expected_victim_before=%0d actual_victim_after=%0d",
                 expected_before, victim_way_4);

        if (victim_way_4 !== expected_before[WAY_BITS_4-1:0]) begin
            $display("    RESULT: FAIL");
            $finish;
        end else begin
            $display("    RESULT: PASS");
        end
    endtask

    initial begin
        $dumpfile("lru_full_verbose_test.vcd");
        $dumpvars(0, testbench_lru_full_verbose);

        clk = 0;
        rst = 1;

        update_en_4 = 0;
        update_set_4 = 0;
        update_way_4 = 0;
        lookup_set_4 = 0;

        update_en_2 = 0;
        update_set_2 = 0;
        update_way_2 = 0;
        lookup_set_2 = 0;

        reset_ref_4();
        reset_ref_2();

        $display("========================================");
        $display("START FULL VERBOSE LRU TESTBENCH");
        $display("========================================");

        repeat (2) @(posedge clk);
        rst = 0;
        #1;

        $display("");
        $display("TEST 1: Reset initialization");
        $display("Expected: initial victim should be the way with largest age.");

        for (int s = 0; s < NUM_SETS_4; s++) begin
            check_victim_4(s, "reset victim check");
        end

        check_victim_2(0, "2-way reset victim check");

        $display("");
        $display("TEST 2: Basic sequential access on set 0");
        touch_4(0, 3, "set 0 touch way 3");
        touch_4(0, 2, "set 0 touch way 2");
        touch_4(0, 1, "set 0 touch way 1");
        touch_4(0, 0, "set 0 touch way 0");

        $display("");
        $display("TEST 3: Different sets");
        touch_4(1, 0, "set 1 touch way 0");
        touch_4(1, 2, "set 1 touch way 2");
        touch_4(2, 1, "set 2 touch way 1");
        touch_4(3, 3, "set 3 touch way 3");

        $display("");
        $display("TEST 4: Set independence");
        check_victim_4(1, "set 1 before updating set 2");
        touch_4(2, 3, "update set 2 only");
        check_victim_4(1, "set 1 after updating set 2");

        $display("");
        $display("TEST 5: Repeated access to same way");
        touch_4(0, 0, "repeat way 0 first time");
        touch_4(0, 0, "repeat way 0 second time");
        touch_4(0, 0, "repeat way 0 third time");

        $display("");
        $display("TEST 6: update_en = 0 hold behavior");
        hold_check_4(0, "set 0 hold test");
        hold_check_4(1, "set 1 hold test");

        $display("");
        $display("TEST 7: Different access order");
        touch_4(3, 0, "set 3 access way 0");
        touch_4(3, 2, "set 3 access way 2");
        touch_4(3, 1, "set 3 access way 1");
        touch_4(3, 3, "set 3 access way 3");
        touch_4(3, 2, "set 3 access way 2 again");
        touch_4(3, 0, "set 3 access way 0 again");

        $display("");
        $display("TEST 8: Boundary case, 1 set and 2 ways");
        touch_2(0, "2-way touch way 0");
        touch_2(1, "2-way touch way 1");
        touch_2(1, "2-way repeat way 1");
        touch_2(0, "2-way touch way 0 again");

        $display("");
        $display("TEST 9: Long deterministic pseudo-random sequence");
        for (int i = 0; i < 100; i++) begin
            int set;
            int way;

            set = (i * 3 + 1) % NUM_SETS_4;
            way = (i * 5 + 2) % NUM_WAYS_4;

            $display("    Random step %0d: set=%0d way=%0d", i, set, way);
            touch_4(set, way, "long deterministic pseudo-random sequence");
        end

        $display("");
        $display("FINAL CHECK: all sets after long sequence");
        for (int s = 0; s < NUM_SETS_4; s++) begin
            check_victim_4(s, "final victim check");
        end

        $display("");
        $display("========================================");
        $display("PASS: FULL VERBOSE LRU TESTBENCH PASSED");
        $display("========================================");

        $finish;
    end

endmodule