// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_basic_lru.h for the primary calling header

#include "Vtb_basic_lru__pch.h"

void Vtb_basic_lru___024root___ctor_var_reset(Vtb_basic_lru___024root* vlSelf);

Vtb_basic_lru___024root::Vtb_basic_lru___024root(Vtb_basic_lru__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_basic_lru___024root___ctor_var_reset(this);
}

void Vtb_basic_lru___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_basic_lru___024root::~Vtb_basic_lru___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
