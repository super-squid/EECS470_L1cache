// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_basic_lru.h for the primary calling header

#ifndef VERILATED_VTB_BASIC_LRU___024ROOT_H_
#define VERILATED_VTB_BASIC_LRU___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_basic_lru__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_basic_lru___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_basic_lru__DOT__clk;
    CData/*0:0*/ tb_basic_lru__DOT__rst;
    CData/*0:0*/ tb_basic_lru__DOT__update_en;
    CData/*1:0*/ tb_basic_lru__DOT__update_set;
    CData/*1:0*/ tb_basic_lru__DOT__update_way;
    CData/*1:0*/ tb_basic_lru__DOT__lookup_set;
    CData/*1:0*/ tb_basic_lru__DOT__victim_way;
    CData/*1:0*/ tb_basic_lru__DOT__dut__DOT__old_age;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_basic_lru__DOT__rst__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<VlUnpacked<CData/*1:0*/, 4>, 4> tb_basic_lru__DOT__dut__DOT__age;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h53d88c7c__0;
    VlTriggerScheduler __VtrigSched_h53d88d4e__0;

    // INTERNAL VARIABLES
    Vtb_basic_lru__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_basic_lru___024root(Vtb_basic_lru__Syms* symsp, const char* namep);
    ~Vtb_basic_lru___024root();
    VL_UNCOPYABLE(Vtb_basic_lru___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
