# EECS470 L1 Data Cache (Direct‑Mapped, Write‑Through) – SystemVerilog Model

This repository contains a simple yet complete L1 data cache model written in SystemVerilog, together with a DRAM model and a testbench. The cache is **direct‑mapped**, uses **write‑through** with **write‑allocate**, and transfers data in **blocks** (cache lines). It is intended for educational purposes, e.g., understanding cache state machines, hit/miss handling, and basic memory hierarchies.

---

## Files and Their Functions

| File                     | Description                                                                                   |
|--------------------------|-----------------------------------------------------------------------------------------------|
| `dcache_interface.sv`    | Defines the `dcache_if` interface used between CPU, cache, and memory. Contains `modport`s for CPU side, memory side, and a monitor. |
| `simple_dcache.sv`       | The actual direct‑mapped L1 data cache. Implements the FSM for read/write hits, read misses, and write misses. Uses write‑through & write‑allocate. |
| `dram_model.sv`          | A simplified DRAM model with configurable read delay. Simulates 64KB byte‑addressable memory. Write‑through writes are completed in one cycle; reads take `READ_DELAY` cycles. |
| `testbench_dcache.sv`    | A testbench that instantiates the cache and DRAM, drives basic test patterns (read miss, read hit, write hit, write miss, conflict miss), and prints results. |

---

## Parameter Descriptions

### `simple_dcache.sv` / `dram_model.sv`

| Parameter         | Default | Meaning                                                                                   |
|-------------------|---------|-------------------------------------------------------------------------------------------|
| `AW`              | 32      | Address width in bits.                                                                    |
| `DW`              | 32      | CPU word width (bits). One word is transferred per CPU request.                           |
| `CACHE_BYTES`     | 256     | Total cache size in bytes.                                                                |
| `BLOCK_BYTES`     | 16      | Size of one cache line (block) in bytes. Must be a power of two.                          |
| `ASSOC`           | 1       | Associativity. This model is direct‑mapped (only 1).                                      |
| `READ_DELAY`      | 2       | *(dram_model only)* Number of clock cycles a DRAM read takes.                             |

### Derived parameters (internal)
- **`OFFSET_BITS`** = `log2(BLOCK_BYTES)` – bits to select byte inside a block.
- **`INDEX_BITS`**  = `log2(CACHE_BYTES / (BLOCK_BYTES * ASSOC))` – bits to select a set.
- **`TAG_BITS`**    = `AW - INDEX_BITS - OFFSET_BITS` – remaining bits for tag comparison.
- **`NUM_LINES`**   = `CACHE_BYTES / BLOCK_BYTES` – total number of cache lines (ways × sets).
- **`NUM_SETS`**    = `NUM_LINES / ASSOC` – number of sets (for direct‑mapped = `NUM_LINES`).

---

## Cache Architecture Summary

- **Placement**: Direct‑mapped (one line per set).  
- **Write policy**: **Write‑through** – a write updates both the cache and the main memory simultaneously.  
- **Miss policy**: **Write‑allocate** – on a write miss, the entire block is first fetched from memory into the cache, then the word is updated (the write goes to both cache and memory).  
- **Block size**: Configurable via `BLOCK_BYTES` (default 16 bytes = 4 words of 32 bits).  
- **Cache size**: Configurable via `CACHE_BYTES` (default 256 bytes = 16 lines of 16 bytes each).  
- **State machine**:  
  - `IDLE` – waits for a CPU request.  
  - `READ_MISS` – waiting for the memory block to be returned after a read miss.  
  - `WRITE_MISS` – waiting for the memory block to be returned after a write miss (followed by immediate write‑through).

---

## How to Run

1. Compile all files with a SystemVerilog simulator (e.g., Synopsys VCS, Cadence Xcelium, Mentor Questa, or open‑source Icarus Verilog with SV support).  
   Example using `iverilog` (if SV features are supported):

2. The testbench will run six simple tests and print the results. Expected output (exact data may vary due to uninitialised memory):
Test 1: Read miss at 0x0000_0000
Read data = xxxxxxxx
Test 2: Read hit (same address)
Hit data = xxxxxxxx
Test 3: Write hit at 0x0000_0000 -> DEADBEEF
Test 4: Read after write
Data = DEADBEEF (expected DEADBEEF)
Test 5: Write miss at 0x0000_0010 -> CAFEBABE
Test 6: Conflict miss at 0x1000_0000
Data = xxxxxxxx


---

## Notes

- The DRAM model is byte‑addressable and supports **only aligned block transfers** (addresses are zeroed in the lower `OFFSET_BITS`).  
- The testbench uses a simple `wait(cpu_if.ready)` to block until the cache completes the request.  
- For real synthesis, the `cache` array would be replaced with a register file or SRAM macro.  
- Write‑through writes to the DRAM are **single‑cycle** in this model – real DRAM would take longer.

---

## License

This code is provided “as is” for educational use. No warranty is implied.