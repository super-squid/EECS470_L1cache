// dram_model.sv
module dram_model #(
    parameter AW = 32,
    parameter BLOCK_BYTES = 16,   // 16 bytes per cache block
    parameter READ_DELAY = 2      // clock cycles
) (
    input logic clk,
    dcache_if.mem iface
);
    // Memory size: 64KB for simulation
    localparam MEM_DEPTH = 65536;
    logic [7:0] memory [0:MEM_DEPTH-1];

    typedef enum logic [1:0] { IDLE, WAIT_READ } state_t;
    state_t state, next_state;
    logic [AW-1:0] latched_addr;
    int wait_cnt;

    always_ff @(posedge clk) begin
        if (iface.rw == 0) begin  // read
            case (state)
                IDLE: begin
                    latched_addr <= iface.addr;
                    wait_cnt <= READ_DELAY;
                    state <= WAIT_READ;
                    iface.ready <= 0;
                end
                WAIT_READ: begin
                    if (wait_cnt == 1) begin
                        // assemble data from memory
                        for (int i = 0; i < BLOCK_BYTES; i++) begin
                            iface.rdata[i*8 +: 8] <= memory[latched_addr + i];
                        end
                        iface.ready <= 1;
                        state <= IDLE;
                    end else begin
                        wait_cnt <= wait_cnt - 1;
                        iface.ready <= 0;
                    end
                end
            endcase
        end else begin  // write
            // write-through: immediate, assume one cycle
            for (int i = 0; i < BLOCK_BYTES; i++) begin
                memory[iface.addr + i] <= iface.wdata[i*8 +: 8];
            end
            iface.ready <= 1;
            state <= IDLE;
        end
    end
endmodule