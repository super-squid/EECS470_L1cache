// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_BASIC_LRU__SYMS_H_
#define VERILATED_VTB_BASIC_LRU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_basic_lru.h"

// INCLUDE MODULE CLASSES
#include "Vtb_basic_lru___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_basic_lru__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_basic_lru* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_basic_lru___024root        TOP;

    // CONSTRUCTORS
    Vtb_basic_lru__Syms(VerilatedContext* contextp, const char* namep, Vtb_basic_lru* modelp);
    ~Vtb_basic_lru__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
