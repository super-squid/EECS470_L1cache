# RV32I Performance Testcases

This folder contains ten long RV32I instruction streams generated from `generate_performance_tests.py`.  Each testcase has a readable `.S` file, a matching `.hex` file using the same format as the provided `instruction_list.hex`, and an `_instruction_list.sv` file with a SystemVerilog `logic [31:0]` instruction array.

| File | Main purpose |
|---|---|
| `perf_01_sequential_stream` | Sequential loads/stores for spatial locality, bandwidth, and warm-cache effects. |
| `perf_02_conflict_thrash` | Same-cache-index addresses spaced by 256 bytes for conflict misses and replacement stress. |
| `perf_03_mixed_rv32i_alu` | Broad RV32I decode/execute mix: U/J/I/R/B forms, loads/stores, fence, ecall, unreachable ebreaks. |
| `perf_04_branch_pointer_chase` | Branch-heavy memory stream for control-flow cost plus cache activity. |
| `perf_05_working_set_write_read` | Small hot working set with repeated stores and reloads for hit rate and write-through pressure. |
| `perf_06_always_hit_hot_line` | One hot 16-byte line after cold start for near-best-case hit rate. |
| `perf_07_always_miss_stride` | Many same-index lines spaced by 256 bytes for near-worst-case miss pressure. |
| `perf_08_victim_ping_pong` | Two conflicting direct-mapped lines, useful for showing victim-cache recovery. |
| `perf_09_next_line_prefetch_stream` | Accesses current and next sequential line to reward next-line prefetching. |
| `perf_10_dirty_writeback_pressure` | Repeated writes to conflicting lines to force dirty evictions/writebacks. |

Notes:

- All instructions are RV32I base ISA encodings. No compressed, multiply/divide, atomics, or CSR instructions are used.
- Most streams end with `ecall` (`00000073`) so an instruction-list testbench can stop there if desired.
- The mixed test includes `ebreak` encodings only behind unconditional jumps/JALR skips, so they are present for decode coverage without being executed in the intended flow.
- Memory addresses are intentionally low and aligned. The cache-oriented streams target the 256-byte cache / 16-byte line organization used by this project.
