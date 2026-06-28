// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#include "Vtestbench_next_line_prefetcher__pch.h"

VlCoroutine Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__0(Vtestbench_next_line_prefetcher___024root* vlSelf);
VlCoroutine Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__1(Vtestbench_next_line_prefetcher___024root* vlSelf);

void Vtestbench_next_line_prefetcher___024root___eval_initial(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_initial\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i;
    __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__clk = 0U;
    __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[(0x0000ffffU 
                                                                          & __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i)] 
            = (0x000000ffU & __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i);
        __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vinline__eval_initial__TOP_testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i);
    }
    Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(Vtestbench_next_line_prefetcher___024root* vlSelf, const char* __VeventDescription);
void Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(Vtestbench_next_line_prefetcher___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__0(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block;
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT____VlemCall_4__block_align;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT____VlemCall_3__block_align;
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block;
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block;
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__failures;
    testbench_next_line_prefetcher__DOT__failures = 0;
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT__rblock;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT__rblock);
    VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT__write_block;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT__write_block);
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__cycles;
    testbench_next_line_prefetcher__DOT__cycles = 0;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__cold_cycles;
    testbench_next_line_prefetcher__DOT__cold_cycles = 0;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__prefetched_cycles;
    testbench_next_line_prefetcher__DOT__prefetched_cycles = 0;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__hit_count_before;
    testbench_next_line_prefetcher__DOT__hit_count_before = 0;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__issue_count_before;
    testbench_next_line_prefetcher__DOT__issue_count_before = 0;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__fill_count_before;
    testbench_next_line_prefetcher__DOT__fill_count_before = 0;
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__unnamedblk1_1__DOT____Vrepeat0;
    testbench_next_line_prefetcher__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__addr = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data);
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__4__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__4__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_2__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_2__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_1__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_1__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_0__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__9__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__9__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__10__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__10__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__11__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__11__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__addr = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data);
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__16__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__16__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__17__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__17__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__18__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__18__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_2__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_2__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_1__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_1__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_0__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__23__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__23__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__addr = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data);
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__28__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__28__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_2__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_2__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_1__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_1__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_0__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__33__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__33__condition = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__34__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__34__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__35__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__35__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_2__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_2__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_1__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_1__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_0__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__42__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__42__condition = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout);
    CData/*7:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value;
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__47__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__47__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__48__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__48__condition = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__49__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__49__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__50__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__50__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__53__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__53__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_2__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_2__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_1__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_1__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_0__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__58__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__58__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__addr = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data);
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__63__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__63__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__addr = 0;
    VlWide<4>/*127:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data);
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__addr = 0;
    VlWide<4>/*127:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data);
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__68__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__68__condition = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__addr;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__addr = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_2__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_2__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_1__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_1__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_0__block_align;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__addr = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__73__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__73__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__74__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__74__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__75__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__75__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__76__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__76__condition = 0;
    CData/*0:0*/ __Vtask_testbench_next_line_prefetcher__DOT__check__77__condition;
    __Vtask_testbench_next_line_prefetcher__DOT__check__77__condition = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("tb_next_line_prefetcher.vcd"s);
    VL_PRINTF_MT("-Info: testbench/testbench_next_line_prefetcher.sv:193: $dumpvar ignored, as Verilated without --trace\n");
    testbench_next_line_prefetcher__DOT__failures = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    vlSelfRef.testbench_next_line_prefetcher__DOT__rst = 1U;
    testbench_next_line_prefetcher__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, testbench_next_line_prefetcher__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             202);
        testbench_next_line_prefetcher__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (testbench_next_line_prefetcher__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__rst = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                          "@(posedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         204);
    VL_WRITEF_NX("\nTEST 1: cold demand read should return DRAM data and launch next-line prefetch\n",0);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__addr = 0U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__1__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__data[3U];
    testbench_next_line_prefetcher__DOT__cold_cycles 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__0__cycles;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__addr = 0U;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block);
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__addr);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__3__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(1U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(2U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(3U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(4U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(5U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(6U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(7U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(8U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(9U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(0x0000000aU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(0x0000000bU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(0x0000000cU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(0x0000000dU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(0x0000000eU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
        = ((IData)(0x0000000fU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__byte_addr 
              << 0x00000018U));
    testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[0U];
    testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[1U];
    testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[2U];
    testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__2__data[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__check__4__condition 
        = (0U == ((((testbench_next_line_prefetcher__DOT__rblock[0U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[0U]) 
                    | (testbench_next_line_prefetcher__DOT__rblock[1U] 
                       ^ testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[1U])) 
                   | (testbench_next_line_prefetcher__DOT__rblock[2U] 
                      ^ testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[2U])) 
                  | (testbench_next_line_prefetcher__DOT__rblock[3U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_0__expected_block[3U])));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__4__name = "ADDR_0 block data"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__4__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__4__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__4__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__addr = 0x00000010U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard = 0U;
    while (true) {
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__addr 
            = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__addr;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__Vfuncout = 0;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__Vfuncout 
            = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__addr);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_0__block_align 
            = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__6__Vfuncout;
        if (!(((~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                   & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                      == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_0__block_align))) 
               & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard)))) break;
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             162);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__guard);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_1__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__7__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_2__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__8__Vfuncout;
    __Vtask_testbench_next_line_prefetcher__DOT__check__9__condition 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
              == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_2__block_align));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__9__name 
        = VL_SFORMATF_N_NX("prefetch buffer holds 0x%08h",1
                           , '#',32,__Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__5____VlefCall_1__block_align) ;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__9__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__9__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__9__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__10__condition 
        = (1U == vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__10__name = "one prefetch issued after cold read"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__10__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__10__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__10__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__11__condition 
        = (1U == vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__11__name = "one prefetch filled after cold read"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__11__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__11__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__11__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nTEST 2: read prefetched next line should be faster and chain another prefetch\n",0);
    testbench_next_line_prefetcher__DOT__hit_count_before 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__addr = 0x00000010U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__13__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__data[3U];
    testbench_next_line_prefetcher__DOT__prefetched_cycles 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__12__cycles;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                          "@(posedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         218);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__addr = 0x00000010U;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block);
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__addr);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__15__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(1U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(2U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(3U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(4U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(5U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(6U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(7U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(8U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(9U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(0x0000000aU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(0x0000000bU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(0x0000000cU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(0x0000000dU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(0x0000000eU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
        = ((IData)(0x0000000fU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__byte_addr 
              << 0x00000018U));
    testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[0U];
    testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[1U];
    testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[2U];
    testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__14__data[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__check__16__condition 
        = (0U == ((((testbench_next_line_prefetcher__DOT__rblock[0U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[0U]) 
                    | (testbench_next_line_prefetcher__DOT__rblock[1U] 
                       ^ testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[1U])) 
                   | (testbench_next_line_prefetcher__DOT__rblock[2U] 
                      ^ testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[2U])) 
                  | (testbench_next_line_prefetcher__DOT__rblock[3U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_1__expected_block[3U])));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__16__name = "ADDR_1 block data from prefetch buffer"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__16__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__16__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__16__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__17__condition 
        = (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count 
           == ((IData)(1U) + testbench_next_line_prefetcher__DOT__hit_count_before));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__17__name = "prefetch hit counter increments"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__17__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__17__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__17__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__18__condition 
        = VL_LTS_III(32, testbench_next_line_prefetcher__DOT__prefetched_cycles, testbench_next_line_prefetcher__DOT__cold_cycles);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__18__name = "prefetched refill is faster than cold miss"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__18__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__18__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__18__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__addr = 0x00000020U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard = 0U;
    while (true) {
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__addr 
            = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__addr;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__Vfuncout = 0;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__Vfuncout 
            = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__addr);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_0__block_align 
            = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__20__Vfuncout;
        if (!(((~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                   & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                      == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_0__block_align))) 
               & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard)))) break;
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             162);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__guard);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_1__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__21__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_2__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__22__Vfuncout;
    __Vtask_testbench_next_line_prefetcher__DOT__check__23__condition 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
              == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_2__block_align));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__23__name 
        = VL_SFORMATF_N_NX("prefetch buffer holds 0x%08h",1
                           , '#',32,__Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__19____VlefCall_1__block_align) ;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__23__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__23__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__23__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nTEST 3: non-sequential miss replaces the buffered line with its own next line\n",0);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__addr = 0x00000040U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__25__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__data[3U];
    testbench_next_line_prefetcher__DOT__cycles = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__24__cycles;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__addr = 0x00000040U;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block);
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__addr);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__27__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(1U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(2U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(3U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(4U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(5U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(6U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(7U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(8U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(9U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(0x0000000aU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(0x0000000bU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(0x0000000cU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(0x0000000dU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(0x0000000eU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
        = ((IData)(0x0000000fU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__byte_addr 
              << 0x00000018U));
    testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[0U];
    testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[1U];
    testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[2U];
    testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__26__data[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__check__28__condition 
        = (0U == ((((testbench_next_line_prefetcher__DOT__rblock[0U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[0U]) 
                    | (testbench_next_line_prefetcher__DOT__rblock[1U] 
                       ^ testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[1U])) 
                   | (testbench_next_line_prefetcher__DOT__rblock[2U] 
                      ^ testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[2U])) 
                  | (testbench_next_line_prefetcher__DOT__rblock[3U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_2__expected_block[3U])));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__28__name = "ADDR_4 block data"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__28__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__28__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__28__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__addr = 0x00000050U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard = 0U;
    while (true) {
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__addr 
            = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__addr;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__Vfuncout = 0;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__Vfuncout 
            = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__addr);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_0__block_align 
            = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__30__Vfuncout;
        if (!(((~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                   & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                      == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_0__block_align))) 
               & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard)))) break;
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             162);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__guard);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_1__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__31__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_2__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__32__Vfuncout;
    __Vtask_testbench_next_line_prefetcher__DOT__check__33__condition 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
              == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_2__block_align));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__33__name 
        = VL_SFORMATF_N_NX("prefetch buffer holds 0x%08h",1
                           , '#',32,__Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__29____VlefCall_1__block_align) ;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__33__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__33__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__33__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__34__addr = 0x00000050U;
    testbench_next_line_prefetcher__DOT____VlemCall_3__block_align = 0;
    testbench_next_line_prefetcher__DOT____VlemCall_3__block_align 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__34__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__check__35__condition 
        = (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
           == testbench_next_line_prefetcher__DOT____VlemCall_3__block_align);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__35__name = "old ADDR_2 buffer replaced"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__35__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__35__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__35__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nTEST 4: write to the buffered line invalidates the stale prefetch copy\n",0);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__addr = 0x000000f0U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__37__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__data[3U];
    testbench_next_line_prefetcher__DOT__cycles = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__36__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__addr = 0x00000100U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard = 0U;
    while (true) {
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__addr 
            = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__addr;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__Vfuncout = 0;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__Vfuncout 
            = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__addr);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_0__block_align 
            = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__39__Vfuncout;
        if (!(((~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                   & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                      == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_0__block_align))) 
               & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard)))) break;
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             162);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__guard);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_1__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__40__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_2__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__41__Vfuncout;
    __Vtask_testbench_next_line_prefetcher__DOT__check__42__condition 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
              == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_2__block_align));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__42__name 
        = VL_SFORMATF_N_NX("prefetch buffer holds 0x%08h",1
                           , '#',32,__Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__38____VlefCall_1__block_align) ;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__42__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__42__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__42__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value = 0xa5U;
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout);
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data);
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[0U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[1U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[2U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[3U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[0U] 
        = (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
            << 0x00000018U) | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                << 0x00000010U) | (
                                                   ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                    << 8U) 
                                                   | (IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value))));
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[1U] 
        = (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
            << 0x00000018U) | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                << 0x00000010U) | (
                                                   ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                    << 8U) 
                                                   | ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                      | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                          >> 8U) 
                                                         | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                             >> 0x00000010U) 
                                                            | ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                               >> 0x00000018U)))))));
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[2U] 
        = (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
            << 0x00000018U) | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                << 0x00000010U) | (
                                                   ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                    << 8U) 
                                                   | ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                      | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                          >> 8U) 
                                                         | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                             >> 0x00000010U) 
                                                            | ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                               >> 0x00000018U)))))));
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[3U] 
        = (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
            << 0x00000018U) | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                << 0x00000010U) | (
                                                   ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                    << 8U) 
                                                   | ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                      | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                          >> 8U) 
                                                         | (((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                             >> 0x00000010U) 
                                                            | ((IData)(__Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__value) 
                                                               >> 0x00000018U)))))));
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[0U];
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[1U];
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[2U];
    __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__data[3U];
    testbench_next_line_prefetcher__DOT__write_block[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[0U];
    testbench_next_line_prefetcher__DOT__write_block[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[1U];
    testbench_next_line_prefetcher__DOT__write_block[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[2U];
    testbench_next_line_prefetcher__DOT__write_block[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__fill_block__43__Vfuncout[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[0U] 
        = testbench_next_line_prefetcher__DOT__write_block[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[1U] 
        = testbench_next_line_prefetcher__DOT__write_block[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[2U] 
        = testbench_next_line_prefetcher__DOT__write_block[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[3U] 
        = testbench_next_line_prefetcher__DOT__write_block[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__addr = 0x00000100U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         139);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 1U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__45__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[0U];
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[1U];
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[2U];
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__data[3U];
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         145);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             152);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    testbench_next_line_prefetcher__DOT__cycles = __Vtask_testbench_next_line_prefetcher__DOT__bfm_write__44__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard = 0U;
    while (((3U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state)) 
            & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard))) {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             175);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_idle__46__guard);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__47__condition 
        = (3U != (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__47__name = "prefetcher returns idle"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__47__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__47__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__47__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__48__condition 
        = VL_LTS_III(32, 0U, testbench_next_line_prefetcher__DOT__cycles);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__48__name = "write completed"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__48__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__48__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__48__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__49__addr = 0x00000100U;
    testbench_next_line_prefetcher__DOT____VlemCall_4__block_align = 0;
    testbench_next_line_prefetcher__DOT____VlemCall_4__block_align 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__49__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__check__50__condition 
        = (1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                    & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                       == testbench_next_line_prefetcher__DOT____VlemCall_4__block_align))));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__50__name = "matching prefetched line no longer valid"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__50__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__50__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__50__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nTEST 5: read after write returns written block through normal memory path\n",0);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__addr = 0x00000100U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__52__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__data[3U];
    testbench_next_line_prefetcher__DOT__cycles = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__51__cycles;
    __Vtask_testbench_next_line_prefetcher__DOT__check__53__condition 
        = (0U == ((((testbench_next_line_prefetcher__DOT__rblock[0U] 
                     ^ testbench_next_line_prefetcher__DOT__write_block[0U]) 
                    | (testbench_next_line_prefetcher__DOT__rblock[1U] 
                       ^ testbench_next_line_prefetcher__DOT__write_block[1U])) 
                   | (testbench_next_line_prefetcher__DOT__rblock[2U] 
                      ^ testbench_next_line_prefetcher__DOT__write_block[2U])) 
                  | (testbench_next_line_prefetcher__DOT__rblock[3U] 
                     ^ testbench_next_line_prefetcher__DOT__write_block[3U])));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__53__name = "read-after-write block data"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__53__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__53__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__53__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__addr = 0x00000110U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard = 0U;
    while (true) {
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__addr 
            = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__addr;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__Vfuncout = 0;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__Vfuncout 
            = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__addr);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_0__block_align 
            = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__55__Vfuncout;
        if (!(((~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                   & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                      == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_0__block_align))) 
               & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard)))) break;
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             162);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__guard);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_1__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__56__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_2__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__57__Vfuncout;
    __Vtask_testbench_next_line_prefetcher__DOT__check__58__condition 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
              == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_2__block_align));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__58__name 
        = VL_SFORMATF_N_NX("prefetch buffer holds 0x%08h",1
                           , '#',32,__Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__54____VlefCall_1__block_align) ;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__58__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__58__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__58__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nTEST 6: immediate next-line request while prefetch is in flight is captured\n",0);
    testbench_next_line_prefetcher__DOT__issue_count_before 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count;
    testbench_next_line_prefetcher__DOT__fill_count_before 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__addr = 0x00000200U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__60__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__data[3U];
    testbench_next_line_prefetcher__DOT__cycles = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__59__cycles;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__addr = 0x00000200U;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block);
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__addr);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__62__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(1U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(2U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(3U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(4U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(5U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(6U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(7U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(8U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(9U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(0x0000000aU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(0x0000000bU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(0x0000000cU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(0x0000000dU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(0x0000000eU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
        = ((IData)(0x0000000fU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__byte_addr 
              << 0x00000018U));
    testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[0U];
    testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[1U];
    testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[2U];
    testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__61__data[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__check__63__condition 
        = (0U == ((((testbench_next_line_prefetcher__DOT__rblock[0U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[0U]) 
                    | (testbench_next_line_prefetcher__DOT__rblock[1U] 
                       ^ testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[1U])) 
                   | (testbench_next_line_prefetcher__DOT__rblock[2U] 
                      ^ testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[2U])) 
                  | (testbench_next_line_prefetcher__DOT__rblock[3U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_5__expected_block[3U])));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__63__name = "new stream first read data"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__63__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__63__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__63__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__addr = 0x00000210U;
    VL_ZERO_W(128, __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data);
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         118);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 1U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__addr);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__65__Vfuncout;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U] = 0U;
    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(vlSelf, 
                                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    co_await vlSelfRef.__VtrigSched_h62a15e0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge testbench_next_line_prefetcher.clk)", 
                                                         "testbench/testbench_next_line_prefetcher.sv", 
                                                         124);
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid = 0U;
    do {
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             128);
        __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles);
    } while ((1U & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready))));
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[0U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[1U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[2U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U];
    __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[3U] 
        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U];
    testbench_next_line_prefetcher__DOT__rblock[0U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[0U];
    testbench_next_line_prefetcher__DOT__rblock[1U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[1U];
    testbench_next_line_prefetcher__DOT__rblock[2U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[2U];
    testbench_next_line_prefetcher__DOT__rblock[3U] 
        = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__data[3U];
    testbench_next_line_prefetcher__DOT__cycles = __Vtask_testbench_next_line_prefetcher__DOT__bfm_read__64__cycles;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__addr = 0x00000210U;
    VL_ZERO_W(128, testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block);
    VL_ZERO_W(128, __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__addr);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__67__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U] = 0U;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned;
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(1U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(2U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(3U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(4U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(5U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(6U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(7U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(8U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(9U) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(0x0000000aU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(0x0000000bU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
              << 0x00000018U));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(0x0000000cU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U] 
        = ((0xffffff00U & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U]) 
           | (0x000000ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(0x0000000dU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U] 
        = ((0xffff00ffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U]) 
           | (0x0000ff00U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 8U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(0x0000000eU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U] 
        = ((0xff00ffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U]) 
           | (0x00ff0000U & (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
                             << 0x00000010U)));
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
        = ((IData)(0x0000000fU) + __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__aligned);
    __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U] 
        = ((0x00ffffffU & __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U]) 
           | (__Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__byte_addr 
              << 0x00000018U));
    testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[0U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[0U];
    testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[1U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[1U];
    testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[2U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[2U];
    testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[3U] 
        = __Vfunc_testbench_next_line_prefetcher__DOT__expected_block__66__data[3U];
    __Vtask_testbench_next_line_prefetcher__DOT__check__68__condition 
        = (0U == ((((testbench_next_line_prefetcher__DOT__rblock[0U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[0U]) 
                    | (testbench_next_line_prefetcher__DOT__rblock[1U] 
                       ^ testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[1U])) 
                   | (testbench_next_line_prefetcher__DOT__rblock[2U] 
                      ^ testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[2U])) 
                  | (testbench_next_line_prefetcher__DOT__rblock[3U] 
                     ^ testbench_next_line_prefetcher__DOT____VlemCall_6__expected_block[3U])));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__68__name = "new stream second read data"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__68__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__68__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__68__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__addr = 0x00000220U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard = 0U;
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard = 0U;
    while (true) {
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__addr 
            = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__addr;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__Vfuncout = 0;
        __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__Vfuncout 
            = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__addr);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_0__block_align 
            = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__70__Vfuncout;
        if (!(((~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
                   & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                      == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_0__block_align))) 
               & VL_GTS_III(32, 0x00000032U, __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard)))) break;
        Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(vlSelf, 
                                                                              "@(posedge testbench_next_line_prefetcher.clk)");
        co_await vlSelfRef.__VtrigSched_h62a1515e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge testbench_next_line_prefetcher.clk)", 
                                                             "testbench/testbench_next_line_prefetcher.sv", 
                                                             162);
        __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard 
            = ((IData)(1U) + __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__guard);
    }
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_1__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__71__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__addr 
        = __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__Vfuncout = 0;
    __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__Vfuncout 
        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__addr);
    __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_2__block_align 
        = __Vfunc_testbench_next_line_prefetcher__DOT__block_align__72__Vfuncout;
    __Vtask_testbench_next_line_prefetcher__DOT__check__73__condition 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
              == __Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_2__block_align));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__73__name 
        = VL_SFORMATF_N_NX("prefetch buffer holds 0x%08h",1
                           , '#',32,__Vtask_testbench_next_line_prefetcher__DOT__wait_for_prefetch__69____VlefCall_1__block_align) ;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__73__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__73__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__73__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__74__condition 
        = (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count 
           > testbench_next_line_prefetcher__DOT__issue_count_before);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__74__name = "in-flight/prefetched path made progress"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__74__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__74__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__74__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__75__condition 
        = (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count 
           >= ((IData)(1U) + testbench_next_line_prefetcher__DOT__fill_count_before));
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__75__name = "fills continue after in-flight request"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__75__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__75__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__75__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nTEST 7: prefetch counters remain internally consistent\n",0);
    __Vtask_testbench_next_line_prefetcher__DOT__check__76__condition 
        = (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count 
           <= vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__76__name = "fills never exceed issues"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__76__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__76__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__76__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    __Vtask_testbench_next_line_prefetcher__DOT__check__77__condition 
        = (0U < vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count);
    vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__77__name = "at least one prefetch hit happened"s;
    if (__Vtask_testbench_next_line_prefetcher__DOT__check__77__condition) {
        VL_WRITEF_NX("PASS: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__77__name));
    } else {
        VL_WRITEF_NX("FAIL: %s\n",1, 'S',&(vlSelfRef.__Vtask_testbench_next_line_prefetcher__DOT__check__77__name));
        testbench_next_line_prefetcher__DOT__failures 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__failures);
    }
    VL_WRITEF_NX("\nPrefetch issues=%0d fills=%0d hits=%0d\n",3
                 , '#',32,vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count
                 , '#',32,vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count
                 , '#',32,vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count);
    if ((0U == testbench_next_line_prefetcher__DOT__failures)) {
        VL_WRITEF_NX("==============================================\nPASS: NEXT-LINE PREFETCHER TESTBENCH PASSED\n==============================================\n",0);
    } else {
        VL_WRITEF_NX("==============================================\nFAIL: %0d NEXT-LINE PREFETCHER TEST(S) FAILED\n==============================================\n",1
                     , '~',32,testbench_next_line_prefetcher__DOT__failures);
    }
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "testbench/testbench_next_line_prefetcher.sv", 
                                         279);
    VL_FINISH_MT("testbench/testbench_next_line_prefetcher.sv", 280, "");
    co_return;
}

VlCoroutine Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__1(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "testbench/testbench_next_line_prefetcher.sv", 
                                             30);
        vlSelfRef.testbench_next_line_prefetcher__DOT__clk 
            = (1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk)));
    }
    co_return;
}

void Vtestbench_next_line_prefetcher___024root___eval_triggers_vec__act(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_triggers_vec__act\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                       << 3U) 
                                                      | (((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0)) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__rst__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__rst__0 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__rst;
}

bool Vtestbench_next_line_prefetcher___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___trigger_anySet__act\n"); );
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

void Vtestbench_next_line_prefetcher___024root___act_comb__TOP__0(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___act_comb__TOP__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & ((~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw)) 
              & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                 == (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr))));
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
           | ((IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) 
              & (3U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))));
    if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr;
    } else {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw 
            = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
            = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & ((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw)) 
              & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                 == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr)));
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) 
           & ((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw)) 
              & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                 == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr)));
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 0U;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 0U;
    if ((4U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state)))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                     & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch))) {
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
                } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                    if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                         & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit))) {
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
                    }
                }
            }
        } else if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
    }
    if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                         & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch))) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 1U;
                    } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                        if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                             & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit))) {
                            vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 1U;
                        }
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 1U;
        }
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr = 0U;
    if ((4U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state)))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw)))) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__addr 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__Vfuncout 
                            = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__addr);
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79____VlefCall_0__block_align 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__Vfuncout;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__Vfuncout 
                            = ((IData)(0x00000010U) 
                               + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79____VlefCall_0__block_align);
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__Vfuncout;
                    }
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
                }
            }
        }
    } else if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                     & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch))) {
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__addr 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__addr 
                        = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__addr;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__Vfuncout 
                        = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__addr);
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81____VlefCall_0__block_align 
                        = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__Vfuncout;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__Vfuncout 
                        = ((IData)(0x00000010U) + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81____VlefCall_0__block_align);
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                        = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__Vfuncout;
                } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                    if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                         & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit))) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__addr 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__Vfuncout 
                            = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__addr);
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83____VlefCall_0__block_align 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__Vfuncout;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__Vfuncout 
                            = ((IData)(0x00000010U) 
                               + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83____VlefCall_0__block_align);
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__Vfuncout;
                    } else {
                        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[0U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[1U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[2U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[3U];
                        } else {
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U];
                        }
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                    }
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw 
                        = ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                                     & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit)))) 
                           && (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw));
                }
            }
        } else if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw)))) {
                vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__addr 
                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__addr 
                    = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__addr;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__Vfuncout 
                    = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__addr);
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85____VlefCall_0__block_align 
                    = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__Vfuncout;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__Vfuncout 
                    = ((IData)(0x00000010U) + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85____VlefCall_0__block_align);
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                    = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__Vfuncout;
            }
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
        }
    } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[0U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[1U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[2U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[3U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__addr 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__addr 
            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__addr;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__Vfuncout 
            = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__addr);
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87____VlefCall_0__block_align 
            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__Vfuncout;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__Vfuncout 
            = ((IData)(0x00000010U) + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87____VlefCall_0__block_align);
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__Vfuncout;
    } else {
        if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit)))) {
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
            }
        }
        if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit)))) {
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                    = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
            }
        }
    }
}

void Vtestbench_next_line_prefetcher___024root___eval_act(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_act\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000dULL & vlSelfRef.__VactTriggered[0U])) {
        Vtestbench_next_line_prefetcher___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__0(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89____VlefCall_0__block_align;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91____VlefCall_0__block_align;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93____VlefCall_0__block_align;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95____VlefCall_0__block_align;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__addr = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97____VlefCall_0__block_align;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97____VlefCall_0__block_align = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__Vfuncout;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__addr;
    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__addr = 0;
    IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf_issue_count;
    __Vdly__testbench_next_line_prefetcher__DOT__pf_issue_count = 0;
    IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf_fill_count;
    __Vdly__testbench_next_line_prefetcher__DOT__pf_fill_count = 0;
    CData/*2:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0;
    CData/*0:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0;
    IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr = 0;
    VlWide<4>/*127:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data;
    VL_ZERO_W(128, __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data);
    CData/*0:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0;
    IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr = 0;
    CData/*0:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 0;
    IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf_hit_count;
    __Vdly__testbench_next_line_prefetcher__DOT__pf_hit_count = 0;
    // Body
    __Vdly__testbench_next_line_prefetcher__DOT__pf_fill_count 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count;
    __Vdly__testbench_next_line_prefetcher__DOT__pf_hit_count 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count;
    __Vdly__testbench_next_line_prefetcher__DOT__pf_issue_count 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count;
    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__state;
    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr;
    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt;
    vlSelfRef.__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 = 0U;
    vlSelfRef.__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 = 0U;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U] 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U];
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U] 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U];
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U] 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U];
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U] 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U];
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw;
    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state;
    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid;
    if (vlSelfRef.testbench_next_line_prefetcher__DOT__rst) {
        __Vdly__testbench_next_line_prefetcher__DOT__pf_fill_count = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf_hit_count = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf_issue_count = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U] = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U] = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U] = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U] = 0U;
        vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[0U] = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[1U] = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[2U] = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[3U] = 0U;
        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[0U] = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[1U] = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[2U] = 0U;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[3U] = 0U;
    } else {
        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse) {
            __Vdly__testbench_next_line_prefetcher__DOT__pf_fill_count 
                = ((IData)(1U) + vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count);
        }
        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse) {
            __Vdly__testbench_next_line_prefetcher__DOT__pf_hit_count 
                = ((IData)(1U) + vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count);
        }
        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse) {
            __Vdly__testbench_next_line_prefetcher__DOT__pf_issue_count 
                = ((IData)(1U) + vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count);
        }
        if (((((3U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state)) 
               & (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid)) 
              & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid))) 
             & (~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready)))) {
            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 1U;
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr 
                = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[0U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U];
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[1U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U];
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[2U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U];
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[3U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U];
        }
        if ((4U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0U;
            } else if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw) {
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0U;
                } else {
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__addr 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__addr 
                        = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__addr;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__Vfuncout 
                        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__addr);
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0U;
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 3U;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89____VlefCall_0__block_align 
                        = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__90__Vfuncout;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__Vfuncout 
                        = ((IData)(0x00000010U) + __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89____VlefCall_0__block_align);
                    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                        = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__89__Vfuncout;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 1U;
                    if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch) {
                        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
                            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__addr 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__addr 
                                = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__addr;
                            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__Vfuncout 
                                = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__addr);
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0U;
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 0U;
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 3U;
                            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91____VlefCall_0__block_align 
                                = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__92__Vfuncout;
                            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__Vfuncout 
                                = ((IData)(0x00000010U) 
                                   + __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91____VlefCall_0__block_align);
                            vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                                = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__91__Vfuncout;
                        } else {
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[0U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
                            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[1U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
                            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[2U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
                            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[3U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0U;
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 1U;
                        }
                    } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit) {
                            if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
                                __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__addr 
                                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                                __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__addr 
                                    = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__addr;
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0U;
                                __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__Vfuncout 
                                    = (0xfffffff0U 
                                       & __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__addr);
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0U;
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 0U;
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 3U;
                                __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93____VlefCall_0__block_align 
                                    = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__94__Vfuncout;
                                __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__Vfuncout 
                                    = ((IData)(0x00000010U) 
                                       + __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93____VlefCall_0__block_align);
                                vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                                    = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__93__Vfuncout;
                            } else {
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr 
                                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                                vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[0U] 
                                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U];
                                vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[1U] 
                                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U];
                                vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[2U] 
                                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U];
                                vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[3U] 
                                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U];
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 1U;
                            }
                        } else {
                            if ((((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw) 
                                  & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid)) 
                                 & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
                                    == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr))) {
                                __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0U;
                            }
                            vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw;
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 0U;
                            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 4U;
                        }
                    } else {
                        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0U;
                    }
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
                }
            } else if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw) {
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 0U;
                } else {
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__addr 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__addr 
                        = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__addr;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__Vfuncout 
                        = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__addr);
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0U;
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 3U;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95____VlefCall_0__block_align 
                        = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__96__Vfuncout;
                    __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__Vfuncout 
                        = ((IData)(0x00000010U) + __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95____VlefCall_0__block_align);
                    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                        = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__95__Vfuncout;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__addr 
                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__addr 
                = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__addr;
            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__Vfuncout 
                = (0xfffffff0U & __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__addr);
            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = 0U;
            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 3U;
            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97____VlefCall_0__block_align 
                = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__98__Vfuncout;
            __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__Vfuncout 
                = ((IData)(0x00000010U) + __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97____VlefCall_0__block_align);
            vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                = __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__97__Vfuncout;
        } else {
            __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = 0U;
            if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) {
                if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit) {
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0U;
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr 
                        = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[0U] 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U];
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[1U] 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U];
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[2U] 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U];
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[3U] 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U];
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 1U;
                } else {
                    if ((((IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw) 
                          & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid)) 
                         & ((0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr) 
                            == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr))) {
                        __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = 0U;
                    }
                    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                        = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
                    __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state = 2U;
                }
            }
        }
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_count 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf_fill_count;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_count 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf_hit_count;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_count 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf_issue_count;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U] 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U];
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U] 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U];
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U] 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U];
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U] 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U];
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_rw;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__state;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid 
        = __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid;
}

void Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__1(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__1\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14 = 0;
    CData/*7:0*/ __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15;
    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15 = 0;
    SData/*15:0*/ __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15;
    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15 = 0;
    // Body
    if (vlSelfRef.testbench_next_line_prefetcher__DOT__rst) {
        vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state = 0U;
        vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr = 0U;
        vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U] = 0U;
    } else {
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready = 0U;
        if ((0U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__state))) {
            if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid) {
                vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr;
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw) {
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 
                        = (0x000000ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U]);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 
                        = (0x0000ffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr);
                    vlSelfRef.__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready = 1U;
                    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state = 0U;
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                                          >> 8U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    vlSelfRef.__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 = 1U;
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                                          >> 0x00000010U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2 
                        = (0x0000ffffU & ((IData)(2U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3 
                        = (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                           >> 0x00000018U);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3 
                        = (0x0000ffffU & ((IData)(3U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4 
                        = (0x000000ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U]);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4 
                        = (0x0000ffffU & ((IData)(4U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                                          >> 8U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5 
                        = (0x0000ffffU & ((IData)(5U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                                          >> 0x00000010U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6 
                        = (0x0000ffffU & ((IData)(6U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7 
                        = (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                           >> 0x00000018U);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7 
                        = (0x0000ffffU & ((IData)(7U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8 
                        = (0x000000ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U]);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8 
                        = (0x0000ffffU & ((IData)(8U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                                          >> 8U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9 
                        = (0x0000ffffU & ((IData)(9U) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                                          >> 0x00000010U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10 
                        = (0x0000ffffU & ((IData)(0x000aU) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11 
                        = (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                           >> 0x00000018U);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11 
                        = (0x0000ffffU & ((IData)(0x000bU) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12 
                        = (0x000000ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U]);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12 
                        = (0x0000ffffU & ((IData)(0x000cU) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                                          >> 8U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13 
                        = (0x0000ffffU & ((IData)(0x000dU) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14 
                        = (0x000000ffU & (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                                          >> 0x00000010U));
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14 
                        = (0x0000ffffU & ((IData)(0x000eU) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                    __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15 
                        = (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                           >> 0x00000018U);
                    __VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15 
                        = (0x0000ffffU & ((IData)(0x000fU) 
                                          + vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr));
                } else {
                    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt = 3U;
                    vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state = 1U;
                }
            }
        } else if ((1U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__state))) {
            if (VL_GTES_III(32, 1U, vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt)) {
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U] 
                    = ((0xffffff00U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U]) 
                       | vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                       [(0x0000ffffU & vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr)]);
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready = 1U;
                vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt = 0U;
                vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U] 
                    = ((0xffff00ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(1U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 8U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U] 
                    = ((0xff00ffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(2U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000010U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U] 
                    = ((0x00ffffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(3U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000018U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U] 
                    = ((0xffffff00U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U]) 
                       | vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                       [(0x0000ffffU & ((IData)(4U) 
                                        + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]);
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U] 
                    = ((0xffff00ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(5U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 8U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U] 
                    = ((0xff00ffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(6U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000010U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U] 
                    = ((0x00ffffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(7U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000018U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U] 
                    = ((0xffffff00U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U]) 
                       | vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                       [(0x0000ffffU & ((IData)(8U) 
                                        + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]);
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U] 
                    = ((0xffff00ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(9U) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 8U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U] 
                    = ((0xff00ffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(0x000aU) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000010U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U] 
                    = ((0x00ffffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(0x000bU) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000018U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U] 
                    = ((0xffffff00U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U]) 
                       | vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                       [(0x0000ffffU & ((IData)(0x000cU) 
                                        + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]);
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U] 
                    = ((0xffff00ffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(0x000dU) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 8U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U] 
                    = ((0xff00ffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(0x000eU) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000010U));
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U] 
                    = ((0x00ffffffU & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U]) 
                       | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory
                                  [(0x0000ffffU & ((IData)(0x000fU) 
                                                   + vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr))]) 
                          << 0x00000018U));
            } else {
                vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt 
                    = (vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt 
                       - (IData)(1U));
            }
        } else {
            vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state = 0U;
        }
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__state 
        = vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state;
    vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr 
        = vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr;
    vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt 
        = vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt;
    if (vlSelfRef.__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0;
    }
    if (vlSelfRef.__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v2;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v3;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v4;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v5;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v6;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v7;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v8;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v9;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v10;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v11;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v12;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v13;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v14;
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[__VdlyDim0__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15] 
            = __VdlyVal__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v15;
    }
}

void Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__2(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__2\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse))) {
        VL_WRITEF_NX("  [PF ISSUE] t=%0t addr=0x%08h\n",3, 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',32,vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr);
    }
    if (VL_UNLIKELY((vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse))) {
        VL_WRITEF_NX("  [PF FILL ] t=%0t addr=0x%08h\n",3, 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',32,vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr);
    }
    if (VL_UNLIKELY((vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse))) {
        VL_WRITEF_NX("  [PF HIT  ] t=%0t\n",2, 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
    }
}

void Vtestbench_next_line_prefetcher___024root___nba_comb__TOP__0(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___nba_comb__TOP__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & ((~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw)) 
              & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                 == (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr))));
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
           | ((IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) 
              & (3U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))));
    if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr;
    } else {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw 
            = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
            = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
           & ((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw)) 
              & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                 == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr)));
}

void Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__3(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__3\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse = 1U;
                }
            }
        }
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
        = vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
}

void Vtestbench_next_line_prefetcher___024root___nba_comb__TOP__1(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___nba_comb__TOP__1\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch 
        = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) 
           & ((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw)) 
              & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
                 == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr)));
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 0U;
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 0U;
    if ((4U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state)))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                     & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch))) {
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
                } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                    if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                         & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit))) {
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
                    }
                }
            }
        } else if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.ready = 1U;
    }
    if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                         & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch))) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 1U;
                    } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                        if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                             & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit))) {
                            vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 1U;
                        }
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse = 1U;
        }
    }
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr = 0U;
    if ((4U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state)))) {
                if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                    if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw)))) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__addr 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__Vfuncout 
                            = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__addr);
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79____VlefCall_0__block_align 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__Vfuncout;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__Vfuncout 
                            = ((IData)(0x00000010U) 
                               + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79____VlefCall_0__block_align);
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__Vfuncout;
                    }
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
                }
            }
        }
    } else if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
            if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                     & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch))) {
                    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                        = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__addr 
                        = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__addr 
                        = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__addr;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__Vfuncout 
                        = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__addr);
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81____VlefCall_0__block_align 
                        = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__Vfuncout;
                    vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__Vfuncout 
                        = ((IData)(0x00000010U) + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81____VlefCall_0__block_align);
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                        = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__Vfuncout;
                } else if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid) {
                    if (((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                         & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit))) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[0U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[1U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[2U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data[3U];
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__addr 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__addr;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__Vfuncout 
                            = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__addr);
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83____VlefCall_0__block_align 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__Vfuncout;
                        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__Vfuncout 
                            = ((IData)(0x00000010U) 
                               + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83____VlefCall_0__block_align);
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__Vfuncout;
                    } else {
                        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[0U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[1U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[2U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata[3U];
                        } else {
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U];
                            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U];
                        }
                        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
                    }
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                    vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw 
                        = ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
                                     & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit)))) 
                           && (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw));
                }
            }
        } else if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_rw)))) {
                vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__addr 
                    = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__addr 
                    = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__addr;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__Vfuncout 
                    = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__addr);
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85____VlefCall_0__block_align 
                    = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__Vfuncout;
                vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__Vfuncout 
                    = ((IData)(0x00000010U) + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85____VlefCall_0__block_align);
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                    = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__Vfuncout;
            }
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[0U];
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[1U];
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[2U];
            vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rdata[3U];
        }
    } else if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse = 1U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[0U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[0U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[1U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[1U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[2U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[2U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rdata[3U] 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data[3U];
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] = 0U;
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] = 0U;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__addr 
            = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__addr 
            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__addr;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__Vfuncout 
            = (0xfffffff0U & vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__addr);
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87____VlefCall_0__block_align 
            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__Vfuncout;
        vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__Vfuncout 
            = ((IData)(0x00000010U) + vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87____VlefCall_0__block_align);
        vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
            = vlSelfRef.__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__Vfuncout;
    } else {
        if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit)))) {
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.req_valid = 1U;
            }
        }
        if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) {
            if ((1U & (~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit)))) {
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.rw 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[0U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[0U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[1U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[1U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[2U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[2U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.wdata[3U] 
                    = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.wdata[3U];
                vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr 
                    = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
            }
        }
    }
}

void Vtestbench_next_line_prefetcher___024root___eval_nba(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_nba\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__0(vlSelf);
        Vtestbench_next_line_prefetcher___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        if (VL_UNLIKELY((vlSelfRef.testbench_next_line_prefetcher__DOT__pf_issue_pulse))) {
            VL_WRITEF_NX("  [PF ISSUE] t=%0t addr=0x%08h\n",3, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.addr);
        }
        if (VL_UNLIKELY((vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse))) {
            VL_WRITEF_NX("  [PF FILL ] t=%0t addr=0x%08h\n",3, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr);
        }
        if (VL_UNLIKELY((vlSelfRef.testbench_next_line_prefetcher__DOT__pf_hit_pulse))) {
            VL_WRITEF_NX("  [PF HIT  ] t=%0t\n",2, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
        }
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit 
            = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
               & ((~ (IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw)) 
                  & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                     == (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr))));
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid 
            = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) 
               | ((IData)(vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.req_valid) 
                  & (3U == (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))));
        if (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid) {
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw 
                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw;
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
                = vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr;
        } else {
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw 
                = vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.rw;
            vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr 
                = (0xfffffff0U & vlSymsp->TOP__testbench_next_line_prefetcher__DOT__l1_pf_if.addr);
        }
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit 
            = ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid) 
               & ((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw)) 
                  & (vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr 
                     == vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr)));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse = 0U;
        if ((1U & (~ ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__state))) {
                    if (vlSymsp->TOP__testbench_next_line_prefetcher__DOT__pf_dram_if.ready) {
                        vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse = 1U;
                    }
                }
            }
        }
        vlSelfRef.testbench_next_line_prefetcher__DOT__pf__DOT__active_addr 
            = vlSelfRef.__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtestbench_next_line_prefetcher___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtestbench_next_line_prefetcher___024root___timing_ready(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___timing_ready\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h62a1515e__0.ready("@(posedge testbench_next_line_prefetcher.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready("@(negedge testbench_next_line_prefetcher.clk)");
    }
}

void Vtestbench_next_line_prefetcher___024root___timing_resume(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___timing_resume\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h62a1515e__0.moveToResumeQueue(
                                                          "@(posedge testbench_next_line_prefetcher.clk)");
    vlSelfRef.__VtrigSched_h62a15e0c__0.moveToResumeQueue(
                                                          "@(negedge testbench_next_line_prefetcher.clk)");
    vlSelfRef.__VtrigSched_h62a1515e__0.resume("@(posedge testbench_next_line_prefetcher.clk)");
    vlSelfRef.__VtrigSched_h62a15e0c__0.resume("@(negedge testbench_next_line_prefetcher.clk)");
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtestbench_next_line_prefetcher___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtestbench_next_line_prefetcher___024root___eval_phase__act(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_phase__act\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtestbench_next_line_prefetcher___024root___eval_triggers_vec__act(vlSelf);
    Vtestbench_next_line_prefetcher___024root___timing_ready(vlSelf);
    Vtestbench_next_line_prefetcher___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtestbench_next_line_prefetcher___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtestbench_next_line_prefetcher___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtestbench_next_line_prefetcher___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtestbench_next_line_prefetcher___024root___timing_resume(vlSelf);
        Vtestbench_next_line_prefetcher___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtestbench_next_line_prefetcher___024root___eval_phase__inact(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_phase__inact\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("testbench/testbench_next_line_prefetcher.sv", 13, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtestbench_next_line_prefetcher___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtestbench_next_line_prefetcher___024root___eval_phase__nba(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_phase__nba\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtestbench_next_line_prefetcher___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtestbench_next_line_prefetcher___024root___eval_nba(vlSelf);
        Vtestbench_next_line_prefetcher___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtestbench_next_line_prefetcher___024root___eval(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtestbench_next_line_prefetcher___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("testbench/testbench_next_line_prefetcher.sv", 13, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("testbench/testbench_next_line_prefetcher.sv", 13, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtestbench_next_line_prefetcher___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("testbench/testbench_next_line_prefetcher.sv", 13, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtestbench_next_line_prefetcher___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtestbench_next_line_prefetcher___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtestbench_next_line_prefetcher___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0(Vtestbench_next_line_prefetcher___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a1515e__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0)) 
                                   << 2U) | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
    }
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0(Vtestbench_next_line_prefetcher___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root____VbeforeTrig_h62a15e0c__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0)) 
                                   << 2U) | ((IData)(vlSelfRef.testbench_next_line_prefetcher__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a1515e__0.ready(__VeventDescription);
    }
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h62a15e0c__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtestbench_next_line_prefetcher___024root___eval_debug_assertions(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_debug_assertions\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
