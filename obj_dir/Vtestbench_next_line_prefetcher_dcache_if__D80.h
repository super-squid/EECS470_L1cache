// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#ifndef VERILATED_VTESTBENCH_NEXT_LINE_PREFETCHER_DCACHE_IF__D80_H_
#define VERILATED_VTESTBENCH_NEXT_LINE_PREFETCHER_DCACHE_IF__D80_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtestbench_next_line_prefetcher__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestbench_next_line_prefetcher_dcache_if__D80 final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ req_valid;
    CData/*0:0*/ rw;
    CData/*0:0*/ ready;
    IData/*31:0*/ addr;
    VlWide<4>/*127:0*/ wdata;
    VlWide<4>/*127:0*/ rdata;

    // INTERNAL VARIABLES
    Vtestbench_next_line_prefetcher__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtestbench_next_line_prefetcher_dcache_if__D80();
    ~Vtestbench_next_line_prefetcher_dcache_if__D80();
    void ctor(Vtestbench_next_line_prefetcher__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtestbench_next_line_prefetcher_dcache_if__D80);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtestbench_next_line_prefetcher_dcache_if__D80* obj);

#endif  // guard
