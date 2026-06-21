// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_basic_lru.h for the primary calling header

#include "Vtb_basic_lru__pch.h"

VlCoroutine Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__0(Vtb_basic_lru___024root* vlSelf);
VlCoroutine Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__1(Vtb_basic_lru___024root* vlSelf);

void Vtb_basic_lru___024root___eval_initial(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_initial\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_basic_lru__DOT__clk = 0U;
    Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_basic_lru___024root____VbeforeTrig_h53d88c7c__0(Vtb_basic_lru___024root* vlSelf, const char* __VeventDescription);
void Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(Vtb_basic_lru___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__0(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_basic_lru__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_basic_lru__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__0__set;
    __Vtask_tb_basic_lru__DOT__check_victim__0__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__0__expected;
    __Vtask_tb_basic_lru__DOT__check_victim__0__expected = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__1__set;
    __Vtask_tb_basic_lru__DOT__touch__1__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__1__way;
    __Vtask_tb_basic_lru__DOT__touch__1__way = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__2__set;
    __Vtask_tb_basic_lru__DOT__check_victim__2__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__2__expected;
    __Vtask_tb_basic_lru__DOT__check_victim__2__expected = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__3__set;
    __Vtask_tb_basic_lru__DOT__touch__3__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__3__way;
    __Vtask_tb_basic_lru__DOT__touch__3__way = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__4__set;
    __Vtask_tb_basic_lru__DOT__check_victim__4__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__4__expected;
    __Vtask_tb_basic_lru__DOT__check_victim__4__expected = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__5__set;
    __Vtask_tb_basic_lru__DOT__touch__5__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__5__way;
    __Vtask_tb_basic_lru__DOT__touch__5__way = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__6__set;
    __Vtask_tb_basic_lru__DOT__check_victim__6__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__6__expected;
    __Vtask_tb_basic_lru__DOT__check_victim__6__expected = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__7__set;
    __Vtask_tb_basic_lru__DOT__touch__7__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__touch__7__way;
    __Vtask_tb_basic_lru__DOT__touch__7__way = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__8__set;
    __Vtask_tb_basic_lru__DOT__check_victim__8__set = 0;
    CData/*1:0*/ __Vtask_tb_basic_lru__DOT__check_victim__8__expected;
    __Vtask_tb_basic_lru__DOT__check_victim__8__expected = 0;
    // Body
    vlSelfRef.tb_basic_lru__DOT__rst = 1U;
    vlSelfRef.tb_basic_lru__DOT__update_en = 0U;
    vlSelfRef.tb_basic_lru__DOT__update_set = 0U;
    vlSelfRef.tb_basic_lru__DOT__update_way = 0U;
    vlSelfRef.tb_basic_lru__DOT__lookup_set = 0U;
    tb_basic_lru__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, tb_basic_lru__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_basic_lru___024root____VbeforeTrig_h53d88c7c__0(vlSelf, 
                                                            "@(posedge tb_basic_lru.clk)");
        co_await vlSelfRef.__VtrigSched_h53d88c7c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_basic_lru.clk)", 
                                                             "testbench/testbench_lru.sv", 
                                                             64);
        tb_basic_lru__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_basic_lru__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_basic_lru__DOT__rst = 0U;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88c7c__0(vlSelf, 
                                                        "@(posedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88c7c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         66);
    __Vtask_tb_basic_lru__DOT__check_victim__0__expected = 3U;
    __Vtask_tb_basic_lru__DOT__check_victim__0__set = 0U;
    vlSelfRef.tb_basic_lru__DOT__lookup_set = __Vtask_tb_basic_lru__DOT__check_victim__0__set;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "testbench/testbench_lru.sv", 
                                         47);
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_basic_lru__DOT__victim_way) 
                      != (IData)(__Vtask_tb_basic_lru__DOT__check_victim__0__expected))))) {
        VL_WRITEF_NX("FAILED: set=%0d victim=%0d expected=%0d\n",3
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__0__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way)
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__0__expected);
        VL_FINISH_MT("testbench/testbench_lru.sv", 50, "");
    } else {
        VL_WRITEF_NX("PASSED: set=%0d victim=%0d\n",2
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__0__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way));
    }
    __Vtask_tb_basic_lru__DOT__touch__1__way = 3U;
    __Vtask_tb_basic_lru__DOT__touch__1__set = 0U;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         34);
    vlSelfRef.tb_basic_lru__DOT__update_en = 1U;
    vlSelfRef.tb_basic_lru__DOT__update_set = __Vtask_tb_basic_lru__DOT__touch__1__set;
    vlSelfRef.tb_basic_lru__DOT__update_way = __Vtask_tb_basic_lru__DOT__touch__1__way;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         38);
    vlSelfRef.tb_basic_lru__DOT__update_en = 0U;
    __Vtask_tb_basic_lru__DOT__check_victim__2__expected = 2U;
    __Vtask_tb_basic_lru__DOT__check_victim__2__set = 0U;
    vlSelfRef.tb_basic_lru__DOT__lookup_set = __Vtask_tb_basic_lru__DOT__check_victim__2__set;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "testbench/testbench_lru.sv", 
                                         47);
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_basic_lru__DOT__victim_way) 
                      != (IData)(__Vtask_tb_basic_lru__DOT__check_victim__2__expected))))) {
        VL_WRITEF_NX("FAILED: set=%0d victim=%0d expected=%0d\n",3
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__2__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way)
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__2__expected);
        VL_FINISH_MT("testbench/testbench_lru.sv", 50, "");
    } else {
        VL_WRITEF_NX("PASSED: set=%0d victim=%0d\n",2
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__2__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way));
    }
    __Vtask_tb_basic_lru__DOT__touch__3__way = 2U;
    __Vtask_tb_basic_lru__DOT__touch__3__set = 0U;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         34);
    vlSelfRef.tb_basic_lru__DOT__update_en = 1U;
    vlSelfRef.tb_basic_lru__DOT__update_set = __Vtask_tb_basic_lru__DOT__touch__3__set;
    vlSelfRef.tb_basic_lru__DOT__update_way = __Vtask_tb_basic_lru__DOT__touch__3__way;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         38);
    vlSelfRef.tb_basic_lru__DOT__update_en = 0U;
    __Vtask_tb_basic_lru__DOT__check_victim__4__expected = 1U;
    __Vtask_tb_basic_lru__DOT__check_victim__4__set = 0U;
    vlSelfRef.tb_basic_lru__DOT__lookup_set = __Vtask_tb_basic_lru__DOT__check_victim__4__set;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "testbench/testbench_lru.sv", 
                                         47);
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_basic_lru__DOT__victim_way) 
                      != (IData)(__Vtask_tb_basic_lru__DOT__check_victim__4__expected))))) {
        VL_WRITEF_NX("FAILED: set=%0d victim=%0d expected=%0d\n",3
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__4__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way)
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__4__expected);
        VL_FINISH_MT("testbench/testbench_lru.sv", 50, "");
    } else {
        VL_WRITEF_NX("PASSED: set=%0d victim=%0d\n",2
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__4__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way));
    }
    __Vtask_tb_basic_lru__DOT__touch__5__way = 1U;
    __Vtask_tb_basic_lru__DOT__touch__5__set = 0U;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         34);
    vlSelfRef.tb_basic_lru__DOT__update_en = 1U;
    vlSelfRef.tb_basic_lru__DOT__update_set = __Vtask_tb_basic_lru__DOT__touch__5__set;
    vlSelfRef.tb_basic_lru__DOT__update_way = __Vtask_tb_basic_lru__DOT__touch__5__way;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         38);
    vlSelfRef.tb_basic_lru__DOT__update_en = 0U;
    __Vtask_tb_basic_lru__DOT__check_victim__6__expected = 0U;
    __Vtask_tb_basic_lru__DOT__check_victim__6__set = 0U;
    vlSelfRef.tb_basic_lru__DOT__lookup_set = __Vtask_tb_basic_lru__DOT__check_victim__6__set;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "testbench/testbench_lru.sv", 
                                         47);
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_basic_lru__DOT__victim_way) 
                      != (IData)(__Vtask_tb_basic_lru__DOT__check_victim__6__expected))))) {
        VL_WRITEF_NX("FAILED: set=%0d victim=%0d expected=%0d\n",3
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__6__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way)
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__6__expected);
        VL_FINISH_MT("testbench/testbench_lru.sv", 50, "");
    } else {
        VL_WRITEF_NX("PASSED: set=%0d victim=%0d\n",2
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__6__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way));
    }
    __Vtask_tb_basic_lru__DOT__touch__7__way = 0U;
    __Vtask_tb_basic_lru__DOT__touch__7__set = 0U;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         34);
    vlSelfRef.tb_basic_lru__DOT__update_en = 1U;
    vlSelfRef.tb_basic_lru__DOT__update_set = __Vtask_tb_basic_lru__DOT__touch__7__set;
    vlSelfRef.tb_basic_lru__DOT__update_way = __Vtask_tb_basic_lru__DOT__touch__7__way;
    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(vlSelf, 
                                                        "@(negedge tb_basic_lru.clk)");
    co_await vlSelfRef.__VtrigSched_h53d88d4e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_basic_lru.clk)", 
                                                         "testbench/testbench_lru.sv", 
                                                         38);
    vlSelfRef.tb_basic_lru__DOT__update_en = 0U;
    __Vtask_tb_basic_lru__DOT__check_victim__8__expected = 3U;
    __Vtask_tb_basic_lru__DOT__check_victim__8__set = 0U;
    vlSelfRef.tb_basic_lru__DOT__lookup_set = __Vtask_tb_basic_lru__DOT__check_victim__8__set;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "testbench/testbench_lru.sv", 
                                         47);
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_basic_lru__DOT__victim_way) 
                      != (IData)(__Vtask_tb_basic_lru__DOT__check_victim__8__expected))))) {
        VL_WRITEF_NX("FAILED: set=%0d victim=%0d expected=%0d\n",3
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__8__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way)
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__8__expected);
        VL_FINISH_MT("testbench/testbench_lru.sv", 50, "");
    } else {
        VL_WRITEF_NX("PASSED: set=%0d victim=%0d\n",2
                     , '#',2,__Vtask_tb_basic_lru__DOT__check_victim__8__set
                     , '#',2,(IData)(vlSelfRef.tb_basic_lru__DOT__victim_way));
    }
    VL_WRITEF_NX("All configurable LRU tests passed.\n",0);
    VL_FINISH_MT("testbench/testbench_lru.sv", 83, "");
    co_return;
}

VlCoroutine Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__1(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "testbench/testbench_lru.sv", 
                                             29);
        vlSelfRef.tb_basic_lru__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_basic_lru__DOT__clk)));
    }
    co_return;
}

void Vtb_basic_lru___024root___eval_triggers_vec__act(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_triggers_vec__act\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((~ (IData)(vlSelfRef.tb_basic_lru__DOT__clk)) 
                                                        & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0)) 
                                                       << 3U) 
                                                      | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.tb_basic_lru__DOT__rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__rst__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_basic_lru__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0 
        = vlSelfRef.tb_basic_lru__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__rst__0 
        = vlSelfRef.tb_basic_lru__DOT__rst;
}

bool Vtb_basic_lru___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_basic_lru___024root___act_comb__TOP__0(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___act_comb__TOP__0\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_basic_lru__DOT__victim_way = 0U;
    if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
         [vlSelfRef.tb_basic_lru__DOT__lookup_set][1U] 
         > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
         [vlSelfRef.tb_basic_lru__DOT__lookup_set][0U])) {
        vlSelfRef.tb_basic_lru__DOT__victim_way = 1U;
    }
    if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
         [vlSelfRef.tb_basic_lru__DOT__lookup_set][2U] 
         > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
         [vlSelfRef.tb_basic_lru__DOT__lookup_set][vlSelfRef.tb_basic_lru__DOT__victim_way])) {
        vlSelfRef.tb_basic_lru__DOT__victim_way = 2U;
    }
    if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
         [vlSelfRef.tb_basic_lru__DOT__lookup_set][3U] 
         > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
         [vlSelfRef.tb_basic_lru__DOT__lookup_set][vlSelfRef.tb_basic_lru__DOT__victim_way])) {
        vlSelfRef.tb_basic_lru__DOT__victim_way = 3U;
    }
}

void Vtb_basic_lru___024root___eval_act(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_act\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000dULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.tb_basic_lru__DOT__victim_way = 0U;
        if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][1U] 
             > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][0U])) {
            vlSelfRef.tb_basic_lru__DOT__victim_way = 1U;
        }
        if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][2U] 
             > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set]
             [vlSelfRef.tb_basic_lru__DOT__victim_way])) {
            vlSelfRef.tb_basic_lru__DOT__victim_way = 2U;
        }
        if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][3U] 
             > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set]
             [vlSelfRef.tb_basic_lru__DOT__victim_way])) {
            vlSelfRef.tb_basic_lru__DOT__victim_way = 3U;
        }
    }
}

void Vtb_basic_lru___024root___nba_sequent__TOP__0(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___nba_sequent__TOP__0\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v0;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v0 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v16;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v16 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v16;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v16 = 0;
    CData/*1:0*/ __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v17;
    __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v17 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v17;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v17 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v17;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v17 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v18;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v18 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v18;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v18 = 0;
    CData/*1:0*/ __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v19;
    __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v19 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v19;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v19 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v19;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v19 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v20;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v20 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v20;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v20 = 0;
    CData/*1:0*/ __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v21;
    __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v21 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v21;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v21 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v21;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v21 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v22;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v22 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v22;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v22 = 0;
    CData/*1:0*/ __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v23;
    __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v23 = 0;
    CData/*1:0*/ __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v23;
    __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v23 = 0;
    CData/*0:0*/ __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v23;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v23 = 0;
    // Body
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v0 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v16 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v17 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v18 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v19 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v20 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v21 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v22 = 0U;
    __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v23 = 0U;
    if (vlSelfRef.tb_basic_lru__DOT__rst) {
        __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v0 = 1U;
    } else if (vlSelfRef.tb_basic_lru__DOT__update_en) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__old_age 
            = vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
            [vlSelfRef.tb_basic_lru__DOT__update_set]
            [vlSelfRef.tb_basic_lru__DOT__update_way];
        if ((0U == (IData)(vlSelfRef.tb_basic_lru__DOT__update_way))) {
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v16 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v16 = 1U;
        } else if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                    [vlSelfRef.tb_basic_lru__DOT__update_set][0U] 
                    < (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__old_age))) {
            __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v17 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                                               [vlSelfRef.tb_basic_lru__DOT__update_set][0U])));
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v17 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v17 = 1U;
        }
        if ((1U == (IData)(vlSelfRef.tb_basic_lru__DOT__update_way))) {
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v18 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v18 = 1U;
        } else if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                    [vlSelfRef.tb_basic_lru__DOT__update_set][1U] 
                    < (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__old_age))) {
            __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v19 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                                               [vlSelfRef.tb_basic_lru__DOT__update_set][1U])));
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v19 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v19 = 1U;
        }
        if ((2U == (IData)(vlSelfRef.tb_basic_lru__DOT__update_way))) {
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v20 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v20 = 1U;
        } else if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                    [vlSelfRef.tb_basic_lru__DOT__update_set][2U] 
                    < (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__old_age))) {
            __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v21 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                                               [vlSelfRef.tb_basic_lru__DOT__update_set][2U])));
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v21 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v21 = 1U;
        }
        if ((3U == (IData)(vlSelfRef.tb_basic_lru__DOT__update_way))) {
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v22 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v22 = 1U;
        } else if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                    [vlSelfRef.tb_basic_lru__DOT__update_set][3U] 
                    < (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__old_age))) {
            __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v23 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
                                               [vlSelfRef.tb_basic_lru__DOT__update_set][3U])));
            __VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v23 
                = vlSelfRef.tb_basic_lru__DOT__update_set;
            __VdlySet__tb_basic_lru__DOT__dut__DOT__age__v23 = 1U;
        }
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v0) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[0U][0U] = 0U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[0U][1U] = 1U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[0U][2U] = 2U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[0U][3U] = 3U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[1U][0U] = 0U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[1U][1U] = 1U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[1U][2U] = 2U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[1U][3U] = 3U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[2U][0U] = 0U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[2U][1U] = 1U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[2U][2U] = 2U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[2U][3U] = 3U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[3U][0U] = 0U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[3U][1U] = 1U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[3U][2U] = 2U;
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[3U][3U] = 3U;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v16) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v16][0U] = 0U;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v17) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v17][0U] 
            = __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v17;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v18) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v18][1U] = 0U;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v19) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v19][1U] 
            = __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v19;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v20) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v20][2U] = 0U;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v21) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v21][2U] 
            = __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v21;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v22) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v22][3U] = 0U;
    }
    if (__VdlySet__tb_basic_lru__DOT__dut__DOT__age__v23) {
        vlSelfRef.tb_basic_lru__DOT__dut__DOT__age[__VdlyDim1__tb_basic_lru__DOT__dut__DOT__age__v23][3U] 
            = __VdlyVal__tb_basic_lru__DOT__dut__DOT__age__v23;
    }
}

void Vtb_basic_lru___024root___eval_nba(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_nba\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_basic_lru___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.tb_basic_lru__DOT__victim_way = 0U;
        if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][1U] 
             > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][0U])) {
            vlSelfRef.tb_basic_lru__DOT__victim_way = 1U;
        }
        if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][2U] 
             > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set]
             [vlSelfRef.tb_basic_lru__DOT__victim_way])) {
            vlSelfRef.tb_basic_lru__DOT__victim_way = 2U;
        }
        if ((vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set][3U] 
             > vlSelfRef.tb_basic_lru__DOT__dut__DOT__age
             [vlSelfRef.tb_basic_lru__DOT__lookup_set]
             [vlSelfRef.tb_basic_lru__DOT__victim_way])) {
            vlSelfRef.tb_basic_lru__DOT__victim_way = 3U;
        }
    }
}

void Vtb_basic_lru___024root___timing_ready(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___timing_ready\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h53d88c7c__0.ready("@(posedge tb_basic_lru.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready("@(negedge tb_basic_lru.clk)");
    }
}

void Vtb_basic_lru___024root___timing_resume(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___timing_resume\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h53d88c7c__0.moveToResumeQueue(
                                                          "@(posedge tb_basic_lru.clk)");
    vlSelfRef.__VtrigSched_h53d88d4e__0.moveToResumeQueue(
                                                          "@(negedge tb_basic_lru.clk)");
    vlSelfRef.__VtrigSched_h53d88c7c__0.resume("@(posedge tb_basic_lru.clk)");
    vlSelfRef.__VtrigSched_h53d88d4e__0.resume("@(negedge tb_basic_lru.clk)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_basic_lru___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_basic_lru___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_basic_lru___024root___eval_phase__act(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_phase__act\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_basic_lru___024root___eval_triggers_vec__act(vlSelf);
    Vtb_basic_lru___024root___timing_ready(vlSelf);
    Vtb_basic_lru___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_basic_lru___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_basic_lru___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_basic_lru___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_basic_lru___024root___timing_resume(vlSelf);
        Vtb_basic_lru___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_basic_lru___024root___eval_phase__inact(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_phase__inact\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("testbench/testbench_lru.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_basic_lru___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_basic_lru___024root___eval_phase__nba(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_phase__nba\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_basic_lru___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_basic_lru___024root___eval_nba(vlSelf);
        Vtb_basic_lru___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_basic_lru___024root___eval(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_basic_lru___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("testbench/testbench_lru.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("testbench/testbench_lru.sv", 2, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_basic_lru___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("testbench/testbench_lru.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_basic_lru___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_basic_lru___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_basic_lru___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_basic_lru___024root____VbeforeTrig_h53d88c7c__0(Vtb_basic_lru___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root____VbeforeTrig_h53d88c7c__0\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_basic_lru__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0)) 
                                   << 3U) | ((IData)(vlSelfRef.tb_basic_lru__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0 
        = vlSelfRef.tb_basic_lru__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h53d88c7c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88c7c__0.ready(__VeventDescription);
    }
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0(Vtb_basic_lru___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root____VbeforeTrig_h53d88d4e__0\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_basic_lru__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0)) 
                                   << 3U) | ((IData)(vlSelfRef.tb_basic_lru__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0 
        = vlSelfRef.tb_basic_lru__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h53d88c7c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88c7c__0.ready(__VeventDescription);
    }
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h53d88d4e__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_basic_lru___024root___eval_debug_assertions(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_debug_assertions\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
