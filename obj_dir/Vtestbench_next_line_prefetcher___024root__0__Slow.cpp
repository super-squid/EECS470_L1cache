// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#include "Vtestbench_next_line_prefetcher__pch.h"

void Vtestbench_next_line_prefetcher___024root___timing_ready(Vtestbench_next_line_prefetcher___024root* vlSelf);

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___eval_static(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_static\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__rst__0 
        = vlSelfRef.testbench_next_line_prefetcher__DOT__rst;
    Vtestbench_next_line_prefetcher___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___eval_initial__TOP(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_initial__TOP\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i;
    testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__clk = 0U;
    testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.testbench_next_line_prefetcher__DOT__dram__DOT__memory[(0x0000ffffU 
                                                                          & testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i)] 
            = (0x000000ffU & testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i);
        testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + testbench_next_line_prefetcher__DOT__dram__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___eval_final(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_final\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtestbench_next_line_prefetcher___024root___eval_phase__stl(Vtestbench_next_line_prefetcher___024root* vlSelf);

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___eval_settle(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_settle\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtestbench_next_line_prefetcher___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("testbench/testbench_next_line_prefetcher.sv", 13, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtestbench_next_line_prefetcher___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___eval_triggers_vec__stl(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_triggers_vec__stl\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtestbench_next_line_prefetcher___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtestbench_next_line_prefetcher___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtestbench_next_line_prefetcher___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___stl_sequent__TOP__0(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___stl_sequent__TOP__0\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.testbench_next_line_prefetcher__DOT__pf_fill_pulse = 0U;
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

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___eval_stl(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_stl\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtestbench_next_line_prefetcher___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtestbench_next_line_prefetcher___024root___eval_phase__stl(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___eval_phase__stl\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtestbench_next_line_prefetcher___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtestbench_next_line_prefetcher___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtestbench_next_line_prefetcher___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtestbench_next_line_prefetcher___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtestbench_next_line_prefetcher___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtestbench_next_line_prefetcher___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge testbench_next_line_prefetcher.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge testbench_next_line_prefetcher.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(negedge testbench_next_line_prefetcher.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestbench_next_line_prefetcher___024root___ctor_var_reset(Vtestbench_next_line_prefetcher___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench_next_line_prefetcher___024root___ctor_var_reset\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->testbench_next_line_prefetcher__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5601681696500539323ull);
    vlSelf->testbench_next_line_prefetcher__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3904383105124261580ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf_issue_pulse = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2761275640114593247ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf_fill_pulse = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17509773976015816632ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf_hit_pulse = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16307355508631071041ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf_issue_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9882669348706967425ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf_fill_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7508313211127952743ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf_hit_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11490004967157546698ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3060316165665650148ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1452950935970139939ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data, __VscopeHash, 5447606203378432352ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14892586604016759953ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__active_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10534472977631510616ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__active_rw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4324927444263988977ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17897629426209119727ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data, __VscopeHash, 7126110786093849142ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 685833256888902622ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9192501605753256528ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15541312095924477840ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata, __VscopeHash, 9621858180938032203ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7472579823490147025ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5011964127211821137ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14050603719615353684ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3482031701474850112ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6880520699683053790ull);
    vlSelf->testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11506355439801088400ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->testbench_next_line_prefetcher__DOT__dram__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9943726165661368807ull);
    }
    vlSelf->testbench_next_line_prefetcher__DOT__dram__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7146866123407376530ull);
    vlSelf->testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5966623555829633325ull);
    vlSelf->testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79____VlefCall_0__block_align = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81____VlefCall_0__block_align = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83____VlefCall_0__block_align = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85____VlefCall_0__block_align = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__addr = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87____VlefCall_0__block_align = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__Vfuncout = 0;
    vlSelf->__Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__addr = 0;
    vlSelf->__Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr = 0;
    vlSelf->__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state = 0;
    vlSelf->__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr = 0;
    vlSelf->__Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt = 0;
    vlSelf->__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0 = 0;
    vlSelf->__VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
