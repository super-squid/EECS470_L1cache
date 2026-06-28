// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_basic_lru.h for the primary calling header

#include "Vtb_basic_lru__pch.h"

void Vtb_basic_lru___024root___timing_ready(Vtb_basic_lru___024root* vlSelf);

VL_ATTR_COLD void Vtb_basic_lru___024root___eval_static(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_static\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0 
        = vlSelfRef.tb_basic_lru__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_basic_lru__DOT__rst__0 
        = vlSelfRef.tb_basic_lru__DOT__rst;
    Vtb_basic_lru___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_basic_lru___024root___eval_initial__TOP(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_initial__TOP\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_basic_lru__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_basic_lru___024root___eval_final(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_final\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_basic_lru___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_basic_lru___024root___eval_phase__stl(Vtb_basic_lru___024root* vlSelf);

VL_ATTR_COLD void Vtb_basic_lru___024root___eval_settle(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_settle\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_basic_lru___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("testbench/testbench_lru.sv", 2, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_basic_lru___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_basic_lru___024root___eval_triggers_vec__stl(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_triggers_vec__stl\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_basic_lru___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_basic_lru___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_basic_lru___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_basic_lru___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb_basic_lru___024root___eval_stl(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_stl\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
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

VL_ATTR_COLD bool Vtb_basic_lru___024root___eval_phase__stl(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___eval_phase__stl\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_basic_lru___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_basic_lru___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_basic_lru___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_basic_lru___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_basic_lru___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_basic_lru___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_basic_lru___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_basic_lru.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_basic_lru.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge tb_basic_lru.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_basic_lru___024root___ctor_var_reset(Vtb_basic_lru___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_basic_lru___024root___ctor_var_reset\n"); );
    Vtb_basic_lru__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_basic_lru__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3064753873384989981ull);
    vlSelf->tb_basic_lru__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2179600085904273362ull);
    vlSelf->tb_basic_lru__DOT__update_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13806360307441312050ull);
    vlSelf->tb_basic_lru__DOT__update_set = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15538795524508384781ull);
    vlSelf->tb_basic_lru__DOT__update_way = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15308466421495116399ull);
    vlSelf->tb_basic_lru__DOT__lookup_set = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10426294731088831414ull);
    vlSelf->tb_basic_lru__DOT__victim_way = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16101241676882120337ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_basic_lru__DOT__dut__DOT__age[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4282909199321025240ull);
        }
    }
    vlSelf->tb_basic_lru__DOT__dut__DOT__old_age = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16099323019798046680ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_basic_lru__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_basic_lru__DOT__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
