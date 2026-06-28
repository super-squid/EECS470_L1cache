// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtestbench_next_line_prefetcher__pch.h"

//============================================================
// Constructors

Vtestbench_next_line_prefetcher::Vtestbench_next_line_prefetcher(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtestbench_next_line_prefetcher__Syms(contextp(), _vcname__, this)}
    , __PVT__testbench_next_line_prefetcher__DOT__l1_pf_if{vlSymsp->TOP.__PVT__testbench_next_line_prefetcher__DOT__l1_pf_if}
    , __PVT__testbench_next_line_prefetcher__DOT__pf_dram_if{vlSymsp->TOP.__PVT__testbench_next_line_prefetcher__DOT__pf_dram_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtestbench_next_line_prefetcher::Vtestbench_next_line_prefetcher(const char* _vcname__)
    : Vtestbench_next_line_prefetcher(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtestbench_next_line_prefetcher::~Vtestbench_next_line_prefetcher() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtestbench_next_line_prefetcher___024root___eval_debug_assertions(Vtestbench_next_line_prefetcher___024root* vlSelf);
#endif  // VL_DEBUG
void Vtestbench_next_line_prefetcher___024root___eval_static(Vtestbench_next_line_prefetcher___024root* vlSelf);
void Vtestbench_next_line_prefetcher___024root___eval_initial(Vtestbench_next_line_prefetcher___024root* vlSelf);
void Vtestbench_next_line_prefetcher___024root___eval_settle(Vtestbench_next_line_prefetcher___024root* vlSelf);
void Vtestbench_next_line_prefetcher___024root___eval(Vtestbench_next_line_prefetcher___024root* vlSelf);

void Vtestbench_next_line_prefetcher::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtestbench_next_line_prefetcher::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtestbench_next_line_prefetcher___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtestbench_next_line_prefetcher___024root___eval_static(&(vlSymsp->TOP));
        Vtestbench_next_line_prefetcher___024root___eval_initial(&(vlSymsp->TOP));
        Vtestbench_next_line_prefetcher___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtestbench_next_line_prefetcher___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtestbench_next_line_prefetcher::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtestbench_next_line_prefetcher::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtestbench_next_line_prefetcher::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtestbench_next_line_prefetcher___024root___eval_final(Vtestbench_next_line_prefetcher___024root* vlSelf);

VL_ATTR_COLD void Vtestbench_next_line_prefetcher::final() {
    contextp()->executingFinal(true);
    Vtestbench_next_line_prefetcher___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtestbench_next_line_prefetcher::hierName() const { return vlSymsp->name(); }
const char* Vtestbench_next_line_prefetcher::modelName() const { return "Vtestbench_next_line_prefetcher"; }
unsigned Vtestbench_next_line_prefetcher::threads() const { return 1; }
void Vtestbench_next_line_prefetcher::prepareClone() const { contextp()->prepareClone(); }
void Vtestbench_next_line_prefetcher::atClone() const {
    contextp()->threadPoolpOnClone();
}
