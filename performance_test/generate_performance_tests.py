#!/usr/bin/env python3
"""Generate long RV32I performance instruction streams.

The emitted .hex files use the same one-32-bit-word-per-line format as
instruction_list.hex.  The companion .S files document the same instruction
stream in readable assembly.
"""

from pathlib import Path

OUT_DIR = Path(__file__).resolve().parent


REG = {f"x{i}": i for i in range(32)}


def check_imm(value, bits, name):
    lo = -(1 << (bits - 1))
    hi = (1 << (bits - 1)) - 1
    if value < lo or value > hi:
        raise ValueError(f"{name} immediate {value} does not fit signed {bits} bits")


def check_uimm(value, bits, name):
    if value < 0 or value >= (1 << bits):
        raise ValueError(f"{name} immediate {value} does not fit unsigned {bits} bits")


def r_type(funct7, rs2, rs1, funct3, rd, opcode=0x33):
    return (
        ((funct7 & 0x7F) << 25)
        | ((rs2 & 0x1F) << 20)
        | ((rs1 & 0x1F) << 15)
        | ((funct3 & 0x7) << 12)
        | ((rd & 0x1F) << 7)
        | (opcode & 0x7F)
    )


def i_type(imm, rs1, funct3, rd, opcode=0x13):
    check_imm(imm, 12, "I")
    return (
        ((imm & 0xFFF) << 20)
        | ((rs1 & 0x1F) << 15)
        | ((funct3 & 0x7) << 12)
        | ((rd & 0x1F) << 7)
        | (opcode & 0x7F)
    )


def s_type(imm, rs2, rs1, funct3, opcode=0x23):
    check_imm(imm, 12, "S")
    imm &= 0xFFF
    return (
        ((imm >> 5) << 25)
        | ((rs2 & 0x1F) << 20)
        | ((rs1 & 0x1F) << 15)
        | ((funct3 & 0x7) << 12)
        | ((imm & 0x1F) << 7)
        | (opcode & 0x7F)
    )


def b_type(imm, rs2, rs1, funct3, opcode=0x63):
    if imm % 2:
        raise ValueError("B immediate must be 2-byte aligned")
    check_imm(imm, 13, "B")
    imm &= 0x1FFF
    return (
        (((imm >> 12) & 0x1) << 31)
        | (((imm >> 5) & 0x3F) << 25)
        | ((rs2 & 0x1F) << 20)
        | ((rs1 & 0x1F) << 15)
        | ((funct3 & 0x7) << 12)
        | (((imm >> 1) & 0xF) << 8)
        | (((imm >> 11) & 0x1) << 7)
        | (opcode & 0x7F)
    )


def u_type(imm20, rd, opcode):
    check_uimm(imm20, 20, "U")
    return ((imm20 & 0xFFFFF) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def j_type(imm, rd, opcode=0x6F):
    if imm % 2:
        raise ValueError("J immediate must be 2-byte aligned")
    check_imm(imm, 21, "J")
    imm &= 0x1FFFFF
    return (
        (((imm >> 20) & 0x1) << 31)
        | (((imm >> 1) & 0x3FF) << 21)
        | (((imm >> 11) & 0x1) << 20)
        | (((imm >> 12) & 0xFF) << 12)
        | ((rd & 0x1F) << 7)
        | (opcode & 0x7F)
    )


def inst(text, word):
    return text, word & 0xFFFFFFFF


def addi(rd, rs1, imm):
    return inst(f"addi {rd}, {rs1}, {imm}", i_type(imm, REG[rs1], 0, REG[rd]))


def slti(rd, rs1, imm):
    return inst(f"slti {rd}, {rs1}, {imm}", i_type(imm, REG[rs1], 2, REG[rd]))


def sltiu(rd, rs1, imm):
    return inst(f"sltiu {rd}, {rs1}, {imm}", i_type(imm, REG[rs1], 3, REG[rd]))


def xori(rd, rs1, imm):
    return inst(f"xori {rd}, {rs1}, {imm}", i_type(imm, REG[rs1], 4, REG[rd]))


def ori(rd, rs1, imm):
    return inst(f"ori {rd}, {rs1}, {imm}", i_type(imm, REG[rs1], 6, REG[rd]))


def andi(rd, rs1, imm):
    return inst(f"andi {rd}, {rs1}, {imm}", i_type(imm, REG[rs1], 7, REG[rd]))


def slli(rd, rs1, shamt):
    return inst(f"slli {rd}, {rs1}, {shamt}", i_type(shamt, REG[rs1], 1, REG[rd]))


def srli(rd, rs1, shamt):
    return inst(f"srli {rd}, {rs1}, {shamt}", i_type(shamt, REG[rs1], 5, REG[rd]))


def srai(rd, rs1, shamt):
    return inst(f"srai {rd}, {rs1}, {shamt}", i_type(0x400 | shamt, REG[rs1], 5, REG[rd]))


def alu(op, rd, rs1, rs2):
    specs = {
        "add": (0x00, 0),
        "sub": (0x20, 0),
        "sll": (0x00, 1),
        "slt": (0x00, 2),
        "sltu": (0x00, 3),
        "xor": (0x00, 4),
        "srl": (0x00, 5),
        "sra": (0x20, 5),
        "or": (0x00, 6),
        "and": (0x00, 7),
    }
    funct7, funct3 = specs[op]
    return inst(f"{op} {rd}, {rs1}, {rs2}", r_type(funct7, REG[rs2], REG[rs1], funct3, REG[rd]))


def load(op, rd, imm, rs1):
    funct3 = {"lb": 0, "lh": 1, "lw": 2, "lbu": 4, "lhu": 5}[op]
    return inst(f"{op} {rd}, {imm}({rs1})", i_type(imm, REG[rs1], funct3, REG[rd], 0x03))


def store(op, rs2, imm, rs1):
    funct3 = {"sb": 0, "sh": 1, "sw": 2}[op]
    return inst(f"{op} {rs2}, {imm}({rs1})", s_type(imm, REG[rs2], REG[rs1], funct3))


def branch(op, rs1, rs2, imm):
    funct3 = {"beq": 0, "bne": 1, "blt": 4, "bge": 5, "bltu": 6, "bgeu": 7}[op]
    return inst(f"{op} {rs1}, {rs2}, .+{imm}", b_type(imm, REG[rs2], REG[rs1], funct3))


def lui(rd, imm20):
    return inst(f"lui {rd}, 0x{imm20:x}", u_type(imm20, REG[rd], 0x37))


def auipc(rd, imm20):
    return inst(f"auipc {rd}, 0x{imm20:x}", u_type(imm20, REG[rd], 0x17))


def jal(rd, imm):
    return inst(f"jal {rd}, .+{imm}", j_type(imm, REG[rd]))


def jalr(rd, imm, rs1):
    return inst(f"jalr {rd}, {imm}({rs1})", i_type(imm, REG[rs1], 0, REG[rd], 0x67))


def fence():
    return inst("fence", 0x0000000F)


def ecall():
    return inst("ecall", 0x00000073)


def ebreak():
    return inst("ebreak", 0x00100073)


def pad_block(title):
    return f"\n# {title}\n"


def write_case(name, description, rows):
    asm_path = OUT_DIR / f"{name}.S"
    hex_path = OUT_DIR / f"{name}.hex"
    sv_path = OUT_DIR / f"{name}_instruction_list.sv"
    asm_lines = [
        "# Auto-generated RV32I performance testcase.",
        f"# {description}",
        "# The matching .hex file has one little-endian 32-bit instruction word per line.",
        ".text",
        ".globl _start",
        "_start:",
    ]
    words = []
    for row in rows:
        if isinstance(row, str):
            asm_lines.append(row)
        else:
            text, word = row
            asm_lines.append(f"    {text:<28} # {word:08x}")
            words.append(word)
    asm_path.write_text("\n".join(asm_lines) + "\n")
    hex_path.write_text("\n".join(f"{word:08x}" for word in words) + "\n")
    sv_name = name.upper()
    sv_lines = [
        f"// Auto-generated from {Path(__file__).name}.",
        f"// {description}",
        f"localparam int {sv_name}_INSTR_COUNT = {len(words)};",
        f"logic [31:0] {name}_instruction_list [0:{sv_name}_INSTR_COUNT-1] = '{{",
    ]
    for idx, word in enumerate(words):
        comma = "," if idx != len(words) - 1 else ""
        sv_lines.append(f"    32'h{word:08x}{comma}")
    sv_lines.append("};")
    sv_path.write_text("\n".join(sv_lines) + "\n")


def case_sequential_stream():
    rows = [pad_block("Sequential stream over a large memory range")]
    rows += [lui("x1", 0x00001), addi("x2", "x0", 0), addi("x3", "x0", 1), fence()]
    for i in range(720):
        off = (i * 4) % 2048
        rows += [
            load("lw", "x4", off, "x1"),
            addi("x4", "x4", i % 127),
            store("sw", "x4", off, "x1"),
            load("lw", "x5", off, "x1"),
            alu("add", "x2", "x2", "x5"),
            xori("x3", "x3", (i * 17) % 2047),
        ]
        if i % 16 == 15:
            rows += [addi("x1", "x1", 64), andi("x1", "x1", 2047)]
    rows += [fence(), ecall()]
    return rows


def case_conflict_thrash():
    rows = [pad_block("Same-index conflict pattern for 256B cache, 16B lines")]
    rows += [lui("x1", 0x00002), addi("x6", "x0", 3), addi("x7", "x0", 5), fence()]
    offsets = [0, 256, 512, 768, 1024, 1280, 1536, 1792]
    for i in range(520):
        off = offsets[i % len(offsets)]
        rows += [
            load("lw", "x8", off, "x1"),
            alu("xor", "x9", "x8", "x6"),
            store("sw", "x9", off, "x1"),
            load("lw", "x10", off, "x1"),
            alu("add", "x6", "x6", "x10"),
            alu("sltu", "x11", "x10", "x6"),
            branch("bne", "x11", "x0", 8),
            addi("x7", "x7", 1),
        ]
    rows += [fence(), ecall()]
    return rows


def case_mixed_rv32i_alu():
    rows = [pad_block("Instruction-mix stress: RV32I ALU, immediates, branches, jumps")]
    rows += [
        lui("x1", 0x12345),
        auipc("x2", 0x00001),
        addi("x3", "x0", 31),
        addi("x4", "x0", -17),
        jal("x0", 8),
        ebreak(),
    ]
    ops = ["add", "sub", "sll", "slt", "sltu", "xor", "srl", "sra", "or", "and"]
    for i in range(460):
        rd = f"x{5 + (i % 20)}"
        rs1 = f"x{1 + (i % 24)}"
        rs2 = f"x{1 + ((i * 7) % 24)}"
        rows += [
            addi(rd, rs1, (i % 63) - 31),
            slti("x25", rd, (i % 41) - 20),
            sltiu("x26", rd, i % 97),
            xori("x27", rd, (i * 13) % 2047),
            ori("x28", "x27", i % 255),
            andi("x29", "x28", 0x3FF),
            slli("x30", "x29", i % 31),
            srli("x30", "x30", (i + 3) % 31),
            srai("x31", "x30", (i + 5) % 31),
            alu(ops[i % len(ops)], rd, rs1, rs2),
        ]
        if i % 23 == 0:
            rows += [
                branch("beq", "x0", "x0", 8),
                addi("x1", "x1", 99),
                branch("bne", "x1", "x2", 8),
                addi("x2", "x2", 88),
                branch("blt", "x4", "x3", 8),
                addi("x3", "x3", 77),
                branch("bge", "x3", "x4", 8),
                addi("x4", "x4", 66),
                branch("bltu", "x0", "x3", 8),
                addi("x5", "x5", 55),
                branch("bgeu", "x3", "x0", 8),
                addi("x6", "x6", 44),
            ]
    rows += [auipc("x12", 0), jalr("x0", 8, "x12"), ebreak(), fence(), ecall()]
    return rows


def case_branch_pointer_chase():
    rows = [pad_block("Branch-heavy pointer-chase style access stream")]
    rows += [lui("x1", 0x00003), addi("x2", "x0", 0), addi("x3", "x0", 7), addi("x4", "x0", -1)]
    for i in range(620):
        off = (i * 16) % 1536
        rows += [
            load("lw", "x5", off, "x1"),
            alu("add", "x2", "x2", "x5"),
            branch("beq", "x5", "x0", 8),
            addi("x3", "x3", 1),
            branch("bne", "x3", "x4", 8),
            addi("x4", "x4", 2),
            branch("blt", "x4", "x3", 8),
            addi("x2", "x2", -3),
            store("sw", "x2", off, "x1"),
            branch("bgeu", "x3", "x0", 8),
            addi("x1", "x1", 16),
        ]
        if i % 31 == 30:
            rows += [jal("x0", 8), addi("x7", "x7", 123)]
    rows += [fence(), ecall()]
    return rows


def case_working_set_write_read():
    rows = [pad_block("Small working-set write/read reuse for high hit-rate regions")]
    rows += [lui("x1", 0x00004), addi("x2", "x0", 0), addi("x3", "x0", 11), fence()]
    offsets = [0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60]
    for i in range(680):
        off = offsets[i % len(offsets)]
        rows += [
            addi("x4", "x2", i % 1024),
            store("sw", "x4", off, "x1"),
            load("lw", "x5", off, "x1"),
            alu("add", "x6", "x5", "x3"),
            store("sw", "x6", off, "x1"),
            load("lw", "x7", off, "x1"),
            alu("xor", "x2", "x2", "x7"),
        ]
        if i % 64 == 63:
            rows += [addi("x1", "x1", 64), andi("x1", "x1", 1023), ori("x1", "x1", 0x400)]
    rows += [fence(), ecall()]
    return rows


def case_always_hit_hot_line():
    rows = [pad_block("Extreme high-hit-rate stream: one hot cache line")]
    rows += [lui("x1", 0x00005), addi("x2", "x0", 0), addi("x3", "x0", 13), fence()]
    offsets = [0, 4, 8, 12]
    for i in range(960):
        off = offsets[i % len(offsets)]
        rows += [
            load("lw", "x4", off, "x1"),
            alu("add", "x2", "x2", "x4"),
            addi("x5", "x2", (i % 127) - 63),
            store("sw", "x5", off, "x1"),
            load("lw", "x6", off, "x1"),
            alu("xor", "x3", "x3", "x6"),
        ]
        if i % 32 == 31:
            rows += [
                load("lb", "x7", i % 16, "x1"),
                load("lbu", "x8", (i + 1) % 16, "x1"),
                load("lh", "x9", ((i + 2) % 4) * 2, "x1"),
                load("lhu", "x10", ((i + 3) % 4) * 2, "x1"),
            ]
    rows += [fence(), ecall()]
    return rows


def case_always_miss_stride():
    rows = [pad_block("Extreme low-hit-rate stream: cycling through many cache-sized strides")]
    rows += [lui("x1", 0x00006), addi("x2", "x0", 0), addi("x3", "x0", 19), fence()]
    offsets = [0, 256, 512, 768, 1024, 1280, 1536, 1792]
    for i in range(760):
        off = offsets[i % len(offsets)]
        rows += [
            load("lw", "x4", off, "x1"),
            alu("add", "x2", "x2", "x4"),
            store("sw", "x2", off, "x1"),
            load("lw", "x5", off, "x1"),
            alu("sltu", "x6", "x5", "x2"),
            branch("bne", "x6", "x0", 8),
            addi("x3", "x3", -1),
        ]
    rows += [fence(), ecall()]
    return rows


def case_victim_ping_pong():
    rows = [pad_block("Victim-cache friendly ping-pong: two direct-mapped conflict lines")]
    rows += [lui("x1", 0x00007), addi("x2", "x0", 0), addi("x3", "x0", 23), fence()]
    pair_offsets = [0, 256]
    for i in range(1250):
        off = pair_offsets[i % 2]
        rows += [
            load("lw", "x4", off, "x1"),
            alu("add", "x2", "x2", "x4"),
            xori("x5", "x2", i % 2047),
            store("sw", "x5", off, "x1"),
        ]
        if i % 10 == 9:
            rows += [
                load("lw", "x6", pair_offsets[0], "x1"),
                load("lw", "x7", pair_offsets[1], "x1"),
                alu("xor", "x3", "x6", "x7"),
            ]
    rows += [fence(), ecall()]
    return rows


def case_next_line_prefetch_stream():
    rows = [pad_block("Next-line prefetch friendly stream: touch one word per line, then next line")]
    rows += [lui("x1", 0x00008), addi("x2", "x0", 0), addi("x3", "x0", 29), fence()]
    for i in range(980):
        off = (i * 16) % 1792
        next_off = ((i + 1) * 16) % 1792
        rows += [
            load("lw", "x4", off, "x1"),
            alu("add", "x2", "x2", "x4"),
            load("lw", "x5", next_off, "x1"),
            alu("xor", "x3", "x3", "x5"),
            addi("x6", "x5", i % 251),
            store("sw", "x6", next_off, "x1"),
        ]
        if i % 64 == 63:
            rows += [fence()]
    rows += [fence(), ecall()]
    return rows


def case_dirty_writeback_pressure():
    rows = [pad_block("Dirty eviction/writeback pressure: write many conflict lines before reread")]
    rows += [lui("x1", 0x00009), addi("x2", "x0", 0), addi("x3", "x0", 31), fence()]
    offsets = [0, 256, 512, 768, 1024, 1280, 1536, 1792]
    for i in range(700):
        off = offsets[i % len(offsets)]
        rows += [
            addi("x4", "x2", i % 1024),
            store("sw", "x4", off, "x1"),
            load("lw", "x5", off, "x1"),
            alu("add", "x2", "x2", "x5"),
            store("sw", "x2", off + 4, "x1"),
            load("lw", "x6", off + 4, "x1"),
            alu("xor", "x3", "x3", "x6"),
        ]
        if i % 8 == 7:
            rows += [
                load("lw", "x7", offsets[(i + 1) % len(offsets)], "x1"),
                load("lw", "x8", offsets[(i + 2) % len(offsets)], "x1"),
                alu("add", "x2", "x2", "x8"),
            ]
    rows += [fence(), ecall()]
    return rows


def main():
    cases = [
        ("perf_01_sequential_stream", "Long sequential load/store stream for spatial locality and throughput.", case_sequential_stream()),
        ("perf_02_conflict_thrash", "Long same-index conflict stream for miss rate and replacement pressure.", case_conflict_thrash()),
        ("perf_03_mixed_rv32i_alu", "Long mixed RV32I instruction stream covering ALU, branches, jumps, system, and fence.", case_mixed_rv32i_alu()),
        ("perf_04_branch_pointer_chase", "Branch-heavy memory stream with pointer-chase-like reuse and stores.", case_branch_pointer_chase()),
        ("perf_05_working_set_write_read", "Small working-set write/read stream for high-hit-rate and write-through pressure.", case_working_set_write_read()),
        ("perf_06_always_hit_hot_line", "Extreme high-hit-rate hot-line stream for best-case cache behavior.", case_always_hit_hot_line()),
        ("perf_07_always_miss_stride", "Extreme low-hit-rate stride stream for sustained miss and memory-latency pressure.", case_always_miss_stride()),
        ("perf_08_victim_ping_pong", "Two-line direct-mapped conflict stream intended to expose victim-cache benefit.", case_victim_ping_pong()),
        ("perf_09_next_line_prefetch_stream", "Sequential next-line stream intended to expose prefetch benefit.", case_next_line_prefetch_stream()),
        ("perf_10_dirty_writeback_pressure", "Dirty conflict stream intended to stress writeback and eviction behavior.", case_dirty_writeback_pressure()),
    ]
    for name, description, rows in cases:
        write_case(name, description, rows)

    readme = OUT_DIR / "README.md"
    readme.write_text(
        "# RV32I Performance Testcases\n\n"
        "This folder contains ten long RV32I instruction streams generated from "
        "`generate_performance_tests.py`.  Each testcase has a readable `.S` file, "
        "a matching `.hex` file using the same format as the provided "
        "`instruction_list.hex`, and an `_instruction_list.sv` file with a "
        "SystemVerilog `logic [31:0]` instruction array.\n\n"
        "| File | Main purpose |\n"
        "|---|---|\n"
        "| `perf_01_sequential_stream` | Sequential loads/stores for spatial locality, bandwidth, and warm-cache effects. |\n"
        "| `perf_02_conflict_thrash` | Same-cache-index addresses spaced by 256 bytes for conflict misses and replacement stress. |\n"
        "| `perf_03_mixed_rv32i_alu` | Broad RV32I decode/execute mix: U/J/I/R/B forms, loads/stores, fence, ecall, unreachable ebreaks. |\n"
        "| `perf_04_branch_pointer_chase` | Branch-heavy memory stream for control-flow cost plus cache activity. |\n"
        "| `perf_05_working_set_write_read` | Small hot working set with repeated stores and reloads for hit rate and write-through pressure. |\n"
        "| `perf_06_always_hit_hot_line` | One hot 16-byte line after cold start for near-best-case hit rate. |\n"
        "| `perf_07_always_miss_stride` | Many same-index lines spaced by 256 bytes for near-worst-case miss pressure. |\n"
        "| `perf_08_victim_ping_pong` | Two conflicting direct-mapped lines, useful for showing victim-cache recovery. |\n"
        "| `perf_09_next_line_prefetch_stream` | Accesses current and next sequential line to reward next-line prefetching. |\n"
        "| `perf_10_dirty_writeback_pressure` | Repeated writes to conflicting lines to force dirty evictions/writebacks. |\n\n"
        "Notes:\n\n"
        "- All instructions are RV32I base ISA encodings. No compressed, multiply/divide, atomics, or CSR instructions are used.\n"
        "- Most streams end with `ecall` (`00000073`) so an instruction-list testbench can stop there if desired.\n"
        "- The mixed test includes `ebreak` encodings only behind unconditional jumps/JALR skips, so they are present for decode coverage without being executed in the intended flow.\n"
        "- Memory addresses are intentionally low and aligned. The cache-oriented streams target the 256-byte cache / 16-byte line organization used by this project.\n"
    )


if __name__ == "__main__":
    main()
