`timescale 1ns/1ps

module testbench_fifo_full;

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

    basic_fifo #(
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

    basic_fifo #(
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

    int ref_next_victim_4 [0:NUM_SETS_4-1];
    int ref_next_victim_2 [0:NUM_SETS_2-1];

    task reset_ref_4;
        for (int s = 0; s < NUM_SETS_4; s++) begin
            ref_next_victim_4[s] = 0;
        end
    endtask

    task reset_ref_2;
        for (int s = 0; s < NUM_SETS_2; s++) begin
            ref_next_victim_2[s] = 0;
        end
    endtask

    function int expected_victim_4(input int set);
        return ref_next_victim_4[set];
    endfunction

    function int expected_victim_2(input int set);
        return ref_next_victim_2[set];
    endfunction

    task ref_update_4(input int set);
        if (ref_next_victim_4[set] == NUM_WAYS_4 - 1) begin
            ref_next_victim_4[set] = 0;
        end else begin
            ref_next_victim_4[set]++;
        end
    endtask

    task ref_update_2(input int set);
        if (ref_next_victim_2[set] == NUM_WAYS_2 - 1) begin
            ref_next_victim_2[set] = 0;
        end else begin
            ref_next_victim_2[set]++;
        end
    endtask

    task print_fifo_4(input int set);
        $display("    Set %0d reference next_victim=%0d",
                 set, ref_next_victim_4[set]);
    endtask

    task print_fifo_2;
        $display("    2-way reference next_victim=%0d",
                 ref_next_victim_2[0]);
    endtask

    task check_victim_4(input int set, input string msg);
        int ev;

        lookup_set_4 = SET_BITS_4'(set);
        #1;

        ev = expected_victim_4(set);
        $display("[CHECK 4-WAY] %s", msg);
        $display("    lookup_set=%0d expected_victim=%0d actual_victim=%0d",
                 set, ev, victim_way_4);
        print_fifo_4(set);

        if (victim_way_4 !== WAY_BITS_4'(ev)) begin
            $display("    RESULT: FAIL");
            $finish;
        end else begin
            $display("    RESULT: PASS");
        end
    endtask

    task check_victim_2(input int set, input string msg);
        int ev;

        lookup_set_2 = SET_BITS_2'(set);
        #1;

        ev = expected_victim_2(set);
        $display("[CHECK 2-WAY] %s", msg);
        $display("    expected_victim=%0d actual_victim=%0d",
                 ev, victim_way_2);
        print_fifo_2();

        if (victim_way_2 !== WAY_BITS_2'(ev)) begin
            $display("    RESULT: FAIL");
            $finish;
        end else begin
            $display("    RESULT: PASS");
        end
    endtask

    task insert_4(input int set, input string msg);
        int inserted_way;

        inserted_way = expected_victim_4(set);

        $display("");
        $display("[INSERT 4-WAY] %s", msg);
        $display("    Fill set=%0d victim/inserted_way=%0d", set, inserted_way);

        update_en_4 = 1'b1;
        update_set_4 = SET_BITS_4'(set);
        update_way_4 = WAY_BITS_4'(inserted_way);

        @(posedge clk);
        #1;

        ref_update_4(set);
        update_en_4 = 1'b0;

        check_victim_4(set, msg);
    endtask

    task insert_2(input string msg);
        int inserted_way;

        inserted_way = expected_victim_2(0);

        $display("");
        $display("[INSERT 2-WAY] %s", msg);
        $display("    Fill victim/inserted_way=%0d", inserted_way);

        update_en_2 = 1'b1;
        update_set_2 = '0;
        update_way_2 = WAY_BITS_2'(inserted_way);

        @(posedge clk);
        #1;

        ref_update_2(0);
        update_en_2 = 1'b0;

        check_victim_2(0, msg);
    endtask

    task hold_check_4(input int set, input string msg);
        int expected_before;

        $display("");
        $display("[HOLD TEST] %s", msg);
        $display("    update_en = 0 for 3 cycles");
        $display("    Set being checked: %0d", set);

        lookup_set_4 = SET_BITS_4'(set);
        #1;
        expected_before = expected_victim_4(set);

        update_en_4 = 1'b0;
        update_set_4 = SET_BITS_4'(set);
        update_way_4 = '0;

        repeat (3) @(posedge clk);
        #1;

        $display("    expected_victim_before=%0d actual_victim_after=%0d",
                 expected_before, victim_way_4);

        if (victim_way_4 !== WAY_BITS_4'(expected_before)) begin
            $display("    RESULT: FAIL");
            $finish;
        end else begin
            $display("    RESULT: PASS");
        end
    endtask

    initial begin
        $dumpfile("fifo_full_verbose_test.vcd");
        $dumpvars(0, testbench_fifo_full);

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
        $display("START FULL VERBOSE FIFO TESTBENCH");
        $display("========================================");

        repeat (2) @(posedge clk);
        rst = 0;
        #1;

        $display("");
        $display("TEST 1: Reset initialization");
        $display("Expected: initial victim should be way 0 for every set.");

        for (int s = 0; s < NUM_SETS_4; s++) begin
            check_victim_4(s, "reset victim check");
        end

        check_victim_2(0, "2-way reset victim check");

        $display("");
        $display("TEST 2: Basic FIFO order and wraparound on set 0");
        insert_4(0, "set 0 insert way 0, next victim way 1");
        insert_4(0, "set 0 insert way 1, next victim way 2");
        insert_4(0, "set 0 insert way 2, next victim way 3");
        insert_4(0, "set 0 insert way 3, next victim wraps to way 0");
        insert_4(0, "set 0 insert way 0 again, next victim way 1");

        $display("");
        $display("TEST 3: Different sets");
        insert_4(1, "set 1 first insert");
        insert_4(1, "set 1 second insert");
        insert_4(2, "set 2 first insert");
        insert_4(3, "set 3 first insert");
        insert_4(3, "set 3 second insert");
        insert_4(3, "set 3 third insert");

        $display("");
        $display("TEST 4: Set independence");
        check_victim_4(1, "set 1 before updating set 2");
        insert_4(2, "update set 2 only");
        check_victim_4(1, "set 1 after updating set 2");

        $display("");
        $display("TEST 5: update_way does not affect FIFO order");
        update_en_4 = 1'b1;
        update_set_4 = SET_BITS_4'(0);
        update_way_4 = WAY_BITS_4'(3);
        @(posedge clk);
        #1;
        ref_update_4(0);
        update_en_4 = 1'b0;
        check_victim_4(0, "set 0 advanced by one regardless of update_way value");

        $display("");
        $display("TEST 6: update_en = 0 hold behavior");
        hold_check_4(0, "set 0 hold test");
        hold_check_4(1, "set 1 hold test");

        $display("");
        $display("TEST 7: Boundary case, 1 set and 2 ways");
        insert_2("2-way insert way 0, next victim way 1");
        insert_2("2-way insert way 1, next victim wraps to way 0");
        insert_2("2-way insert way 0 again");
        insert_2("2-way insert way 1 again");

        $display("");
        $display("TEST 8: Long deterministic pseudo-random set sequence");
        for (int i = 0; i < 100; i++) begin
            int set;

            set = (i * 3 + 1) % NUM_SETS_4;

            $display("    Sequence step %0d: set=%0d", i, set);
            insert_4(set, "long deterministic pseudo-random set sequence");
        end

        $display("");
        $display("FINAL CHECK: all sets after long sequence");
        for (int s = 0; s < NUM_SETS_4; s++) begin
            check_victim_4(s, "final victim check");
        end

        $display("");
        $display("========================================");
        $display("PASS: FULL VERBOSE FIFO TESTBENCH PASSED");
        $display("========================================");

        $finish;
    end

endmodule
