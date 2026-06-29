`timescale 1ns/1ps

module testbench_pseudo_lru;

    logic clk;
    logic rst;

    initial clk = 1'b0;
    always #5 clk = ~clk;

    localparam NUM_SETS_8 = 4;
    localparam NUM_WAYS_8 = 8;
    localparam SET_BITS_8 = $clog2(NUM_SETS_8);
    localparam WAY_BITS_8 = $clog2(NUM_WAYS_8);
    localparam PLRU_BITS_8 = NUM_WAYS_8 - 1;

    logic update_en_8;
    logic [SET_BITS_8-1:0] update_set_8;
    logic [WAY_BITS_8-1:0] update_way_8;
    logic [SET_BITS_8-1:0] lookup_set_8;
    logic [WAY_BITS_8-1:0] victim_way_8;

    basic_pseudo_lru #(
        .NUM_SETS(NUM_SETS_8),
        .NUM_WAYS(NUM_WAYS_8)
    ) dut8 (
        .clk(clk),
        .rst(rst),
        .update_en(update_en_8),
        .update_set(update_set_8),
        .update_way(update_way_8),
        .lookup_set(lookup_set_8),
        .victim_way(victim_way_8)
    );

    localparam NUM_SETS_4 = 2;
    localparam NUM_WAYS_4 = 4;
    localparam SET_BITS_4 = $clog2(NUM_SETS_4);
    localparam WAY_BITS_4 = $clog2(NUM_WAYS_4);
    localparam PLRU_BITS_4 = NUM_WAYS_4 - 1;

    logic update_en_4;
    logic [SET_BITS_4-1:0] update_set_4;
    logic [WAY_BITS_4-1:0] update_way_4;
    logic [SET_BITS_4-1:0] lookup_set_4;
    logic [WAY_BITS_4-1:0] victim_way_4;

    basic_pseudo_lru #(
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
    localparam PLRU_BITS_2 = NUM_WAYS_2 - 1;

    logic update_en_2;
    logic [SET_BITS_2-1:0] update_set_2;
    logic [WAY_BITS_2-1:0] update_way_2;
    logic [SET_BITS_2-1:0] lookup_set_2;
    logic [WAY_BITS_2-1:0] victim_way_2;

    basic_pseudo_lru #(
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

    logic [PLRU_BITS_8-1:0] ref_tree_8 [0:NUM_SETS_8-1];
    logic [PLRU_BITS_4-1:0] ref_tree_4 [0:NUM_SETS_4-1];
    logic [PLRU_BITS_2-1:0] ref_tree_2 [0:NUM_SETS_2-1];

    function automatic int expected_victim_8(input int set);
        int node;
        int victim;
        bit direction;
        begin
            node = 0;
            victim = 0;
            for (int level = 0; level < WAY_BITS_8; level++) begin
                direction = ref_tree_8[set][node];
                victim = (victim << 1) | int'(direction);
                node = direction ? ((2 * node) + 2) : ((2 * node) + 1);
            end
            return victim;
        end
    endfunction

    function automatic int expected_victim_4(input int set);
        int node;
        int victim;
        bit direction;
        begin
            node = 0;
            victim = 0;
            for (int level = 0; level < WAY_BITS_4; level++) begin
                direction = ref_tree_4[set][node];
                victim = (victim << 1) | int'(direction);
                node = direction ? ((2 * node) + 2) : ((2 * node) + 1);
            end
            return victim;
        end
    endfunction

    function automatic int expected_victim_2(input int set);
        return int'(ref_tree_2[set][0]);
    endfunction

    task automatic reset_ref;
        for (int s = 0; s < NUM_SETS_8; s++) begin
            ref_tree_8[s] = '0;
        end
        for (int s = 0; s < NUM_SETS_4; s++) begin
            ref_tree_4[s] = '0;
        end
        for (int s = 0; s < NUM_SETS_2; s++) begin
            ref_tree_2[s] = '0;
        end
    endtask

    task automatic ref_update_8(input int set, input int way);
        int node;
        bit direction;
        begin
            node = 0;
            for (int level = 0; level < WAY_BITS_8; level++) begin
                direction = bit'((way >> (WAY_BITS_8 - 1 - level)) & 1);
                ref_tree_8[set][node] = ~direction;
                node = direction ? ((2 * node) + 2) : ((2 * node) + 1);
            end
        end
    endtask

    task automatic ref_update_4(input int set, input int way);
        int node;
        bit direction;
        begin
            node = 0;
            for (int level = 0; level < WAY_BITS_4; level++) begin
                direction = bit'((way >> (WAY_BITS_4 - 1 - level)) & 1);
                ref_tree_4[set][node] = ~direction;
                node = direction ? ((2 * node) + 2) : ((2 * node) + 1);
            end
        end
    endtask

    task automatic ref_update_2(input int set, input int way);
        ref_tree_2[set][0] = ~way[0];
    endtask

    task automatic print_tree_8(input int set);
        $display("    Tree bits: P0=%0b P1=%0b P2=%0b P3=%0b P4=%0b P5=%0b P6=%0b",
                 dut8.tree_bits[set][0],
                 dut8.tree_bits[set][1],
                 dut8.tree_bits[set][2],
                 dut8.tree_bits[set][3],
                 dut8.tree_bits[set][4],
                 dut8.tree_bits[set][5],
                 dut8.tree_bits[set][6]);
    endtask

    task automatic check_8(input int set, input string msg);
        int ev;
        begin
            lookup_set_8 = SET_BITS_8'(set);
            #1;
            ev = expected_victim_8(set);

            $display("[CHECK 8-WAY] %s", msg);
            $display("    set=%0d expected_victim=%0d actual_victim=%0d", set, ev, victim_way_8);
            print_tree_8(set);

            if (victim_way_8 !== WAY_BITS_8'(ev)) begin
                $display("    RESULT: FAIL victim mismatch");
                $finish;
            end
            if (dut8.tree_bits[set] !== ref_tree_8[set]) begin
                $display("    RESULT: FAIL tree bits mismatch expected=%07b actual=%07b",
                         ref_tree_8[set], dut8.tree_bits[set]);
                $finish;
            end
            $display("    RESULT: PASS");
        end
    endtask

    task automatic check_4(input int set, input string msg);
        int ev;
        begin
            lookup_set_4 = SET_BITS_4'(set);
            #1;
            ev = expected_victim_4(set);

            $display("[CHECK 4-WAY] %s", msg);
            $display("    set=%0d expected_victim=%0d actual_victim=%0d tree_bits=%03b",
                     set, ev, victim_way_4, dut4.tree_bits[set]);

            if (victim_way_4 !== WAY_BITS_4'(ev)) begin
                $display("    RESULT: FAIL victim mismatch");
                $finish;
            end
            if (dut4.tree_bits[set] !== ref_tree_4[set]) begin
                $display("    RESULT: FAIL tree bits mismatch expected=%03b actual=%03b",
                         ref_tree_4[set], dut4.tree_bits[set]);
                $finish;
            end
            $display("    RESULT: PASS");
        end
    endtask

    task automatic check_2(input int set, input string msg);
        int ev;
        begin
            lookup_set_2 = SET_BITS_2'(set);
            #1;
            ev = expected_victim_2(set);

            $display("[CHECK 2-WAY] %s", msg);
            $display("    expected_victim=%0d actual_victim=%0d tree_bit=%0b",
                     ev, victim_way_2, dut2.tree_bits[set][0]);

            if (victim_way_2 !== WAY_BITS_2'(ev)) begin
                $display("    RESULT: FAIL victim mismatch");
                $finish;
            end
            if (dut2.tree_bits[set] !== ref_tree_2[set]) begin
                $display("    RESULT: FAIL tree bit mismatch expected=%0b actual=%0b",
                         ref_tree_2[set], dut2.tree_bits[set]);
                $finish;
            end
            $display("    RESULT: PASS");
        end
    endtask

    task automatic touch_8(input int set, input int way, input string msg);
        begin
            $display("");
            $display("[UPDATE 8-WAY] %s", msg);
            $display("    Access set=%0d way=%0d", set, way);

            update_en_8 = 1'b1;
            update_set_8 = SET_BITS_8'(set);
            update_way_8 = WAY_BITS_8'(way);
            @(posedge clk);
            #1;
            update_en_8 = 1'b0;

            ref_update_8(set, way);
            check_8(set, msg);
        end
    endtask

    task automatic touch_4(input int set, input int way, input string msg);
        begin
            $display("");
            $display("[UPDATE 4-WAY] %s", msg);
            $display("    Access set=%0d way=%0d", set, way);

            update_en_4 = 1'b1;
            update_set_4 = SET_BITS_4'(set);
            update_way_4 = WAY_BITS_4'(way);
            @(posedge clk);
            #1;
            update_en_4 = 1'b0;

            ref_update_4(set, way);
            check_4(set, msg);
        end
    endtask

    task automatic touch_2(input int way, input string msg);
        begin
            $display("");
            $display("[UPDATE 2-WAY] %s", msg);
            $display("    Access way=%0d", way);

            update_en_2 = 1'b1;
            update_set_2 = '0;
            update_way_2 = WAY_BITS_2'(way);
            @(posedge clk);
            #1;
            update_en_2 = 1'b0;

            ref_update_2(0, way);
            check_2(0, msg);
        end
    endtask

    task automatic hold_check_8(input int set, input string msg);
        logic [PLRU_BITS_8-1:0] saved_tree;
        int ev;
        begin
            $display("");
            $display("[HOLD 8-WAY] %s", msg);

            lookup_set_8 = SET_BITS_8'(set);
            saved_tree = dut8.tree_bits[set];
            ev = expected_victim_8(set);
            update_en_8 = 1'b0;

            repeat (3) @(posedge clk);
            #1;

            if ((dut8.tree_bits[set] !== saved_tree) || (victim_way_8 !== WAY_BITS_8'(ev))) begin
                $display("    RESULT: FAIL hold mismatch");
                $finish;
            end
            $display("    RESULT: PASS tree_bits=%07b victim=%0d", dut8.tree_bits[set], victim_way_8);
        end
    endtask

    initial begin
        $dumpfile("pseudo_lru_test.vcd");
        $dumpvars(0, testbench_pseudo_lru);

        rst = 1'b1;
        update_en_8 = 1'b0;
        update_set_8 = '0;
        update_way_8 = '0;
        lookup_set_8 = '0;
        update_en_4 = 1'b0;
        update_set_4 = '0;
        update_way_4 = '0;
        lookup_set_4 = '0;
        update_en_2 = 1'b0;
        update_set_2 = '0;
        update_way_2 = '0;
        lookup_set_2 = '0;
        reset_ref();

        $display("========================================");
        $display("START PSEUDO-LRU TESTBENCH");
        $display("========================================");

        repeat (2) @(posedge clk);
        rst = 1'b0;
        #1;

        check_8(0, "reset set 0 should choose way 0");
        check_8(3, "reset set 3 should choose way 0");

        touch_8(0, 0, "P0,P1,P3 point away from W0");
        touch_8(0, 5, "P0,P2,P5 point away from W5");
        touch_8(0, 2, "P0,P1,P4 point away from W2");
        touch_8(0, 7, "P0,P2,P6 point away from W7");
        touch_8(0, 1, "P0,P1,P3 point away from W1");
        touch_8(0, 6, "P0,P2,P6 point away from W6");

        $display("");
        $display("TEST: set independence");
        check_8(1, "set 1 untouched before update");
        touch_8(1, 4, "update set 1 only");
        check_8(0, "set 0 unchanged by set 1 update");

        hold_check_8(0, "update_en low should preserve tree state");

        $display("");
        $display("TEST: 4-way instance");
        check_4(0, "4-way reset");
        touch_4(0, 0, "4-way touch W0");
        touch_4(0, 3, "4-way touch W3");
        touch_4(1, 2, "4-way touch set 1 W2");
        check_4(0, "4-way set 0 still independent");

        $display("");
        $display("TEST: 2-way boundary instance");
        check_2(0, "2-way reset");
        touch_2(0, "2-way touch W0");
        touch_2(1, "2-way touch W1");

        $display("");
        $display("TEST: deterministic 8-way sequence");
        for (int i = 0; i < 64; i++) begin
            int set;
            int way;
            set = (i * 3 + 2) % NUM_SETS_8;
            way = (i * 5 + 1) % NUM_WAYS_8;
            touch_8(set, way, $sformatf("sequence step %0d", i));
        end

        for (int s = 0; s < NUM_SETS_8; s++) begin
            check_8(s, "final 8-way set check");
        end

        $display("");
        $display("========================================");
        $display("PASS: PSEUDO-LRU TESTBENCH PASSED");
        $display("========================================");

        $finish;
    end

endmodule
