// dram_model.sv
module dram_model #(
    parameter AW = 32,
    parameter BLOCK_BYTES = 16,   // 16 bytes per cache block
    parameter READ_DELAY = 2      // clock cycles
) (
    input logic clk,
    input logic rst,
    dcache_if.dram iface
);
    // Memory size: 64KB for simulation
    localparam MEM_DEPTH = 65536;
    logic [7:0] memory [0:MEM_DEPTH-1];
    
    initial begin
        for (int i = 0; i < MEM_DEPTH; i++) begin
            memory[i] = i[7:0];
        end
    end
    
    typedef enum logic [1:0] { IDLE, WAIT_READ } state_t;
    state_t state, next_state;
    logic [AW-1:0] latched_addr;
    int wait_cnt;
    always_comb begin
        next_state = state;
    end
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            latched_addr <= '0;
            wait_cnt <= 0;
            iface.ready <= 1'b0;
            iface.rdata <= '0;
        end else begin
            iface.ready <= 1'b0;
    
            case (state)
                IDLE: begin
                    if (iface.req_valid) begin
                        latched_addr <= iface.addr;
    
                        if (iface.rw == 1'b0) begin
                            wait_cnt <= READ_DELAY;
                            state <= WAIT_READ;
                        end else begin
                            for (int i = 0; i < BLOCK_BYTES; i++) begin
                                memory[iface.addr + i] <= iface.wdata[i*8 +: 8];
                            end
                            iface.ready <= 1'b1;
                            state <= IDLE;
                        end
                    end
                end
    
                WAIT_READ: begin
                    if (wait_cnt <= 1) begin
                        for (int i = 0; i < BLOCK_BYTES; i++) begin
                            iface.rdata[i*8 +: 8] <= memory[latched_addr + i];
                        end
                        iface.ready <= 1'b1;
                        wait_cnt <= 0;
                        state <= IDLE;
                    end else begin
                        wait_cnt <= wait_cnt - 1;
                    end
                end
    
                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end
endmodule