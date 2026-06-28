// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#include "Vtestbench_next_line_prefetcher__pch.h"

void Vtestbench_next_line_prefetcher_dcache_if__D80___ctor_var_reset(Vtestbench_next_line_prefetcher_dcache_if__D80* vlSelf);

Vtestbench_next_line_prefetcher_dcache_if__D80::Vtestbench_next_line_prefetcher_dcache_if__D80() = default;
Vtestbench_next_line_prefetcher_dcache_if__D80::~Vtestbench_next_line_prefetcher_dcache_if__D80() = default;

void Vtestbench_next_line_prefetcher_dcache_if__D80::ctor(Vtestbench_next_line_prefetcher__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtestbench_next_line_prefetcher_dcache_if__D80___ctor_var_reset(this);
}

void Vtestbench_next_line_prefetcher_dcache_if__D80::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtestbench_next_line_prefetcher_dcache_if__D80::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
