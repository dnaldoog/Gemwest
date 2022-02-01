#pragma once
#include "CGcalc.h"

ref class CBead :
    public CGcalc
{
public:

    CBead(Decimal l, Decimal w, Decimal d, Decimal sg, String^ f, String^ adj) : CGcalc(l,w,d,sg,f,adj) {}

    Decimal term() override;
};


