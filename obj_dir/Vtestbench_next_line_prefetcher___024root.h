// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestbench_next_line_prefetcher.h for the primary calling header

#ifndef VERILATED_VTESTBENCH_NEXT_LINE_PREFETCHER___024ROOT_H_
#define VERILATED_VTESTBENCH_NEXT_LINE_PREFETCHER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestbench_next_line_prefetcher_dcache_if__D80;


class Vtestbench_next_line_prefetcher__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestbench_next_line_prefetcher___024root final {
  public:
    // CELLS
    Vtestbench_next_line_prefetcher_dcache_if__D80* __PVT__testbench_next_line_prefetcher__DOT__l1_pf_if;
    Vtestbench_next_line_prefetcher_dcache_if__D80* __PVT__testbench_next_line_prefetcher__DOT__pf_dram_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__clk;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__rst;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf_issue_pulse;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf_fill_pulse;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf_hit_pulse;
        CData/*2:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__state;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__buffer_valid;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__active_rw;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__pending_valid;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__pending_rw;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__incoming_buffer_hit;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_valid;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_rw;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_buffer_hit;
        CData/*0:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_matches_prefetch;
        CData/*1:0*/ testbench_next_line_prefetcher__DOT__dram__DOT__state;
        CData/*1:0*/ __Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__state;
        CData/*0:0*/ __VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v0;
        CData/*0:0*/ __VdlySet__testbench_next_line_prefetcher__DOT__dram__DOT__memory__v1;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__testbench_next_line_prefetcher__DOT__rst__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf_issue_count;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf_fill_count;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf_hit_count;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__buffer_addr;
        VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__buffer_data;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_addr;
        VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__hit_resp_data;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__pending_addr;
        VlWide<4>/*127:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__pending_wdata;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__pf__DOT__eff_pending_addr;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr;
        IData/*31:0*/ testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__79____VlefCall_0__block_align;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__80__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__81____VlefCall_0__block_align;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__82__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__83____VlefCall_0__block_align;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__84__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__85____VlefCall_0__block_align;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__86__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87__addr;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__next_line__87____VlefCall_0__block_align;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__Vfuncout;
        IData/*31:0*/ __Vfunc_testbench_next_line_prefetcher__DOT__pf__DOT__block_align__88__addr;
    };
    struct {
        IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__pf__DOT__active_addr;
        IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__latched_addr;
        IData/*31:0*/ __Vdly__testbench_next_line_prefetcher__DOT__dram__DOT__wait_cnt;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        VlUnpacked<CData/*7:0*/, 65536> testbench_next_line_prefetcher__DOT__dram__DOT__memory;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__4__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__9__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__10__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__11__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__16__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__17__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__18__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__23__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__28__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__33__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__35__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__42__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__47__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__48__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__50__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__53__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__58__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__63__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__68__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__73__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__74__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__75__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__76__name;
    std::string __Vtask_testbench_next_line_prefetcher__DOT__check__77__name;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h62a1515e__0;
    VlTriggerScheduler __VtrigSched_h62a15e0c__0;

    // INTERNAL VARIABLES
    Vtestbench_next_line_prefetcher__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtestbench_next_line_prefetcher___024root(Vtestbench_next_line_prefetcher__Syms* symsp, const char* namep);
    ~Vtestbench_next_line_prefetcher___024root();
    VL_UNCOPYABLE(Vtestbench_next_line_prefetcher___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
