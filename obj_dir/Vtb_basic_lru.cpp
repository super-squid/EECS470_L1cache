// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_basic_lru__pch.h"

//============================================================
// Constructors

Vtb_basic_lru::Vtb_basic_lru(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_basic_lru__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_basic_lru::Vtb_basic_lru(const char* _vcname__)
    : Vtb_basic_lru(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_basic_lru::~Vtb_basic_lru() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_basic_lru___024root___eval_debug_assertions(Vtb_basic_lru___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_basic_lru___024root___eval_static(Vtb_basic_lru___024root* vlSelf);
void Vtb_basic_lru___024root___eval_initial(Vtb_basic_lru___024root* vlSelf);
void Vtb_basic_lru___024root___eval_settle(Vtb_basic_lru___024root* vlSelf);
void Vtb_basic_lru___024root___eval(Vtb_basic_lru___024root* vlSelf);

void Vtb_basic_lru::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_basic_lru::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_basic_lru___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_basic_lru___024root___eval_static(&(vlSymsp->TOP));
        Vtb_basic_lru___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_basic_lru___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_basic_lru___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_basic_lru::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_basic_lru::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_basic_lru::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_basic_lru___024root___eval_final(Vtb_basic_lru___024root* vlSelf);

VL_ATTR_COLD void Vtb_basic_lru::final() {
    contextp()->executingFinal(true);
    Vtb_basic_lru___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_basic_lru::hierName() const { return vlSymsp->name(); }
const char* Vtb_basic_lru::modelName() const { return "Vtb_basic_lru"; }
unsigned Vtb_basic_lru::threads() const { return 1; }
void Vtb_basic_lru::prepareClone() const { contextp()->prepareClone(); }
void Vtb_basic_lru::atClone() const {
    contextp()->threadPoolpOnClone();
}
