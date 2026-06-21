// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#include "Vtestbench_next_line_prefetcher__pch.h"

VL_ATTR_COLD void Vtestbench_next_line_prefetcher_dcache_if__D80___ctor_var_reset(Vtestbench_next_line_prefetcher_dcache_if__D80* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtestbench_next_line_prefetcher_dcache_if__D80___ctor_var_reset\n"); );
    Vtestbench_next_line_prefetcher__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12465084953323796564ull);
    vlSelf->rw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8121497556497431088ull);
    vlSelf->addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14934084843038794831ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->wdata, __VscopeHash, 12890271867161903902ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->rdata, __VscopeHash, 10065165116613087284ull);
    vlSelf->ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 898948264233693212ull);
}
