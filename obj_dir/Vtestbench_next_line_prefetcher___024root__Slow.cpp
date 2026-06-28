// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#include "Vtestbench_next_line_prefetcher__pch.h"

void Vtestbench_next_line_prefetcher___024root___ctor_var_reset(Vtestbench_next_line_prefetcher___024root* vlSelf);

Vtestbench_next_line_prefetcher___024root::Vtestbench_next_line_prefetcher___024root(Vtestbench_next_line_prefetcher__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtestbench_next_line_prefetcher___024root___ctor_var_reset(this);
}

void Vtestbench_next_line_prefetcher___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtestbench_next_line_prefetcher___024root::~Vtestbench_next_line_prefetcher___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
