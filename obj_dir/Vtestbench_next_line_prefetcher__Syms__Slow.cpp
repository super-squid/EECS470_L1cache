// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtestbench_next_line_prefetcher__pch.h"

Vtestbench_next_line_prefetcher__Syms::Vtestbench_next_line_prefetcher__Syms(VerilatedContext* contextp, const char* namep, Vtestbench_next_line_prefetcher* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(1863);
    // Setup sub module instances
    TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ctor(this, "testbench_next_line_prefetcher.l1_pf_if");
    TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ctor(this, "testbench_next_line_prefetcher.pf_dram_if");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__testbench_next_line_prefetcher__DOT__l1_pf_if = &TOP__testbench_next_line_prefetcher__DOT__l1_pf_if;
    TOP.__PVT__testbench_next_line_prefetcher__DOT__pf_dram_if = &TOP__testbench_next_line_prefetcher__DOT__pf_dram_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.__Vconfigure(true);
    TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.__Vconfigure(false);
    // Setup scopes
}

Vtestbench_next_line_prefetcher__Syms::~Vtestbench_next_line_prefetcher__Syms() {
    // Tear down scopes
    // Tear down sub module instances
    TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.dtor();
    TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.dtor();
}
