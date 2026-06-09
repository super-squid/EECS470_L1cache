module dram_model #(
    parameter AW = 32,
    parameter BLOCK_BYTES = 16,
    parameter READ_DELAY = 2
) (
    input logic clk,rst,
    dcache_if.mem iface
);
    localparam MEM_DEPTH = 4 * 1024 * 1024;
    logic [7:0] memory [0:MEM_DEPTH-1];

    typedef enum logic [1:0] { IDLE, WAIT_READ } state_t;
    state_t state, next_state;
    logic [AW-1:0] latched_addr;
    int wait_cnt;
    
    initial begin
    for (int i = 0; i < MEM_DEPTH; i++) 
        memory[i] = 0;
    end
    
    always_ff @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            wait_cnt <= 0;
        end else begin
        case (state)
            IDLE: begin
                if (iface.req_valid) begin
                    if (iface.rw == 0) begin  // read
                        latched_addr <= iface.addr;
                        wait_cnt <= READ_DELAY;
                        state <= WAIT_READ;
                        iface.ready <= 0;
                    end else begin             // write
                        for (int i = 0; i < BLOCK_BYTES; i++)
                            memory[iface.addr + i] <= iface.wdata[i*8 +: 8];
                        iface.ready <= 1;
                    end
                end else begin
                    iface.ready <= 0;
                end
            end

            WAIT_READ: begin
                if (wait_cnt == 1) begin
                    for (int i = 0; i < BLOCK_BYTES; i++)
                        iface.rdata[i*8 +: 8] <= memory[latched_addr + i];
                    iface.ready <= 1;
                    state <= IDLE;
                end else begin
                    wait_cnt <= wait_cnt - 1;
                    iface.ready <= 0;
                end
            end
        endcase
        end
    end
endmodule