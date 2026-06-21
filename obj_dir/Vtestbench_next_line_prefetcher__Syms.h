// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTESTBENCH_NEXT_LINE_PREFETCHER__SYMS_H_
#define VERILATED_VTESTBENCH_NEXT_LINE_PREFETCHER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtestbench_next_line_prefetcher.h"

// INCLUDE MODULE CLASSES
#include "Vtestbench_next_line_prefetcher___024root.h"
#include "Vtestbench_next_line_prefetcher_dcache_if__D80.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtestbench_next_line_prefetcher__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtestbench_next_line_prefetcher* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtestbench_next_line_prefetcher___024root TOP;
    Vtestbench_next_line_prefetcher_dcache_if__D80 TOP__testbench_next_line_prefetcher__DOT__l1_pf_if;
    Vtestbench_next_line_prefetcher_dcache_if__D80 TOP__testbench_next_line_prefetcher__DOT__pf_dram_if;

    // CONSTRUCTORS
    Vtestbench_next_line_prefetcher__Syms(VerilatedContext* contextp, const char* namep, Vtestbench_next_line_prefetcher* modelp);
    ~Vtestbench_next_line_prefetcher__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
