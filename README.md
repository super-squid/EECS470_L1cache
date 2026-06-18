# EECS470 L1 Data Cache – SystemVerilog Model

This repository contains a simple yet complete L1 data cache model written in SystemVerilog, together with a DRAM model, an LRU replacement policy module, and testbenches. The baseline cache is **direct‑mapped**, uses **write‑through** with **write‑allocate**, and transfers data in **blocks** (cache lines). A standalone **LRU replacement** module is also provided to support set‑associative extensions. The code is intended for educational purposes, e.g., understanding cache state machines, hit/miss handling, replacement policies, and basic memory hierarchies.

---

## Files and Their Functions

| File                     | Description                                                                                   |
|--------------------------|-----------------------------------------------------------------------------------------------|
| `dcache_interface.sv` | Defines the `dcache_if` interface used between CPU/testbench, cache, and DRAM. Includes CPU-side, cache-to-memory, DRAM-side, and monitor modports. |
| `simple_dcache.sv`       | The direct‑mapped L1 data cache. Implements the FSM for read/write hits, read misses, and write misses. Uses write‑through & write‑allocate. |
| `dram_model.sv`          | A simplified DRAM model with configurable read delay. Simulates 64KB byte‑addressable memory. Write‑through writes complete in one cycle; reads take `READ_DELAY` cycles. |
| `testbench_dcache.sv`    | Testbench for the data cache. Instantiates the cache and DRAM, drives basic test patterns (read miss, read hit, write hit, write miss, conflict miss), and prints results. |
| `lru_replacement.sv`     | A parameterized LRU replacement policy module (`basic_lru`). Tracks per‑set way ages; `victim_way` output always points to the least‑recently‑used way. Supports arbitrary `NUM_SETS` × `NUM_WAYS` configurations. |
| `testbench_lru.sv`       | Lightweight sanity testbench for `basic_lru` (4 sets × 4 ways). Verifies that sequential `touch` calls produce the expected victim after each access. |
| `testbench_lru_full.sv`  | Comprehensive testbench for `basic_lru`. Exercises 4‑way and 2‑way instances simultaneously with nine test groups: reset init, sequential access, multi‑set independence, repeated accesses, hold behavior, boundary cases (1 set × 2 ways), and a 100‑step deterministic pseudo‑random sequence. Uses a software reference model for golden comparison. |
| `two_way_dcache.sv` | Parameterized set-associative DCache. Default configuration is 2-way, but `ASSOC` can be changed to test N-way behavior. Supports hit-way detection, invalid-way fill, LRU victim selection, write-through, and write-allocate. | 
| `testbench_two_way_dcache.sv` | Directed testbench for `two_way_dcache.sv`. Tests read miss, read hit, write hit, write miss, same-set multi-way fill, LRU eviction, and write-through persistence after eviction. |

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

### `two_way_dcache.sv` 
| Parameter | Default | Meaning | 
|---|---:|---| 
| `AW` | 32 | Address width in bits. | 
| `DW` | 32 | CPU word width in bits. | 
| `CACHE_BYTES` | 256 | Total cache capacity in bytes. | 
| `BLOCK_BYTES` | 16 | Cache block size in bytes. | 
| `ASSOC` | 2 | Number of ways. Default is 2-way set associative, but it can be changed to 1, 4, etc. | 
| `BLOCK_BITS` | derived | `BLOCK_BYTES * 8`, memory-side cache block width. | 
| `NUM_SETS` | derived | `CACHE_BYTES / (BLOCK_BYTES * ASSOC)`. | 
| `WAY_BITS` | derived | Number of bits needed to select a way. |

### `lru_replacement.sv`

| Parameter    | Default | Meaning                                              |
|--------------|---------|------------------------------------------------------|
| `NUM_SETS`   | 16      | Number of cache sets tracked by the LRU module.     |
| `NUM_WAYS`   | 2       | Number of ways (associativity) per set.             |
| `SET_BITS`   | derived | `$clog2(NUM_SETS)` – bits to address a set.         |
| `WAY_BITS`   | derived | `$clog2(NUM_WAYS)` – bits to address a way.         |

### Derived parameters (internal, `simple_dcache.sv`)
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

## LRU Replacement Module (`basic_lru`)

The `basic_lru` module is a stand‑alone, fully parameterized LRU tracker intended to be instantiated by a set‑associative cache.

**Interface signals**

| Signal        | Direction | Width          | Meaning                                                      |
|---------------|-----------|----------------|--------------------------------------------------------------|
| `clk`         | input     | 1              | Clock.                                                       |
| `rst`         | input     | 1              | Synchronous reset. Initialises way `w` in every set to age `w`. |
| `update_en`   | input     | 1              | When high, marks `update_way` in `update_set` as most recently used. |
| `update_set`  | input     | `SET_BITS`     | Set index to update.                                         |
| `update_way`  | input     | `WAY_BITS`     | Way that was just accessed.                                  |
| `lookup_set`  | input     | `SET_BITS`     | Set to query for the eviction candidate.                     |
| `victim_way`  | output    | `WAY_BITS`     | Combinational output of the least‑recently‑used way in `lookup_set`. |

**Age convention**: age `0` = most recently used; the largest age = least recently used (eviction candidate). On an `update_en` pulse, the accessed way's age resets to `0` and all ways that were younger than it have their age incremented by one; ways that were already older are unchanged.

---

## How to Run

Compile all files with a SystemVerilog simulator (e.g., Synopsys VCS, Cadence Xcelium, Mentor Questa, or open‑source Icarus Verilog with SV support).

### Data cache testbench

Compile `dcache_interface.sv`, `dram_model.sv`, `simple_dcache.sv`, and `testbench_dcache.sv` together, then simulate `testbench_dcache`. The testbench runs six simple tests and prints the results. Expected output (exact data may vary due to uninitialised memory):

```
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
```

### LRU testbenches

**Basic sanity test** – compile `lru_replacement.sv` and `testbench_lru.sv`, then simulate `tb_basic_lru`. Runs a short sequential‑access sequence and prints `PASSED`/`FAILED` for each check. Ends with:

```
All configurable LRU tests passed.
```

**Full verbose test** – compile `lru_replacement.sv` and `testbench_lru_full.sv`, then simulate `testbench_lru_full`. Runs nine test groups against both a 4‑set × 4‑way and a 1‑set × 2‑way instance. Each check prints `RESULT: PASS` or `RESULT: FAIL`. Ends with:

```
========================================
PASS: FULL VERBOSE LRU TESTBENCH PASSED
========================================
```

### Two-way / N-way set-associative cache testbench 
For the set-associative cache, compile the following files: 
```text 
src/dcache_interface.sv 
src/dram_model.sv 
src/lru_replacement.sv 
src/two_way_dcache.sv 
testbench/testbench_two_way_dcache.sv
```
Set the simulation top module to:
```
tb_two_way_dcache
```
In Vivado Tcl Console, run:
```
run -all
```
The testbench uses ASSOC = 2 by default. To test more ways, change the ASSOC parameter in testbench_two_way_dcache.sv, for example:
```
parameter ASSOC = 4;
```

---

## Notes

- The DRAM model is byte‑addressable and supports **only aligned block transfers** (addresses are zeroed in the lower `OFFSET_BITS`).  
- The testbench uses a simple `wait(cpu_if.ready)` to block until the cache completes the request.  
- For real synthesis, the `cache` array would be replaced with a register file or SRAM macro.  
- Write‑through writes to the DRAM are **single‑cycle** in this model – real DRAM would take longer.

---

## License

This code is provided “as is” for educational use. No warranty is implied.