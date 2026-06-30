# Auto-generated RV32I performance testcase.
# Extreme high-hit-rate hot-line stream for best-case cache behavior.
# The matching .hex file has one little-endian 32-bit instruction word per line.
.text
.globl _start
_start:

# Extreme high-hit-rate stream: one hot cache line

    lui x1, 0x5                  # 000050b7
    addi x2, x0, 0               # 00000113
    addi x3, x0, 13              # 00d00193
    fence                        # 0000000f
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 8               # 00810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 9               # 00910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 10              # 00a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 11              # 00b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 12              # 00c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 13              # 00d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 14              # 00e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 15              # 00f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 16              # 01010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 17              # 01110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 18              # 01210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 19              # 01310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 20              # 01410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 21              # 01510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 22              # 01610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 23              # 01710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 24              # 01810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 25              # 01910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 26              # 01a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 27              # 01b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 28              # 01c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 29              # 01d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 30              # 01e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 31              # 01f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 32              # 02010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 33              # 02110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 34              # 02210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 35              # 02310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 36              # 02410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 37              # 02510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 38              # 02610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 39              # 02710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 40              # 02810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 41              # 02910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 42              # 02a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 43              # 02b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 44              # 02c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 45              # 02d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 46              # 02e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 47              # 02f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 48              # 03010293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 49              # 03110293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 50              # 03210293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 51              # 03310293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 52              # 03410293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 53              # 03510293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 54              # 03610293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 55              # 03710293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 56              # 03810293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 57              # 03910293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 58              # 03a10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 59              # 03b10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 60              # 03c10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 61              # 03d10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 62              # 03e10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 63              # 03f10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -63             # fc110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -62             # fc210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -61             # fc310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -60             # fc410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -59             # fc510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -58             # fc610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -57             # fc710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -56             # fc810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -55             # fc910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -54             # fca10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -53             # fcb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -52             # fcc10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -51             # fcd10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -50             # fce10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -49             # fcf10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -48             # fd010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -47             # fd110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -46             # fd210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -45             # fd310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -44             # fd410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -43             # fd510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -42             # fd610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -41             # fd710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -40             # fd810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -39             # fd910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -38             # fda10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -37             # fdb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -36             # fdc10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -35             # fdd10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -34             # fde10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -33             # fdf10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -32             # fe010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -31             # fe110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -30             # fe210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -29             # fe310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -28             # fe410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -27             # fe510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -26             # fe610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -25             # fe710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -24             # fe810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -23             # fe910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -22             # fea10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -21             # feb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -20             # fec10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -19             # fed10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -18             # fee10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -17             # fef10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -16             # ff010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -15             # ff110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -14             # ff210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -13             # ff310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -12             # ff410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -11             # ff510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -10             # ff610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -9              # ff710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -8              # ff810293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -7              # ff910293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -6              # ffa10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -5              # ffb10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -4              # ffc10293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -3              # ffd10293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -2              # ffe10293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, -1              # fff10293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 0               # 00010293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 1               # 00110293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 2               # 00210293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 3               # 00310293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 0(x1)                 # 0000a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 4               # 00410293
    sw x5, 0(x1)                 # 0050a023
    lw x6, 0(x1)                 # 0000a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 4(x1)                 # 0040a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 5               # 00510293
    sw x5, 4(x1)                 # 0050a223
    lw x6, 4(x1)                 # 0040a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 8(x1)                 # 0080a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 6               # 00610293
    sw x5, 8(x1)                 # 0050a423
    lw x6, 8(x1)                 # 0080a303
    xor x3, x3, x6               # 0061c1b3
    lw x4, 12(x1)                # 00c0a203
    add x2, x2, x4               # 00410133
    addi x5, x2, 7               # 00710293
    sw x5, 12(x1)                # 0050a623
    lw x6, 12(x1)                # 00c0a303
    xor x3, x3, x6               # 0061c1b3
    lb x7, 15(x1)                # 00f08383
    lbu x8, 0(x1)                # 0000c403
    lh x9, 2(x1)                 # 00209483
    lhu x10, 4(x1)               # 0040d503
    fence                        # 0000000f
    ecall                        # 00000073
