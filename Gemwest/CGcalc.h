#pragma once
#include "CCalculator.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CGcalc : public CCalculator
{
private:

    Decimal m_d1; // diameter 1 (could be length)
    Decimal m_d2; // diamter 2 (could be width)
    Decimal m_depth; // depth of stone in millimeters
    Decimal m_sg; //Specific Gravity
    String^ m_factor; // factor selected by cut choice
    String^ m_adj; //Adjustments
public:
    CGcalc(Decimal l,Decimal w,Decimal d,Decimal sg,String^ f,String^adj):
        m_d1(l),
        m_d2(w),
        m_depth(d),
        m_sg(sg),
        m_factor(f),
        m_adj(adj)
        {}
    /*end constructor*/
     property Decimal d1 {
         Decimal get() {
             return m_d1;
         }

    }     
     property Decimal d2 {
         Decimal get() {
             return m_d2;
         }

    }
     property Decimal dp {
         Decimal get() {
             return m_depth;
         }

     }
     property Decimal sg {
         Decimal get() {
             return m_sg;
         }

     }
     property String^ adjust {
         String^ get() {
             return m_adj;
         }

     }
     property String^ factor {
         String^ get() {
             return m_factor;
         }

     }
    Decimal term() override;
    Decimal recut_weight() override;
};

