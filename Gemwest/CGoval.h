#pragma once
#include "CGcalc.h"
ref class CGoval :
    public CGcalc
{
public:

    CGoval(Decimal l, Decimal w, Decimal d, Decimal sg, Decimal f, String^ adj) : CGcalc(l, w, d, sg, f, adj) {}

    Decimal term() override;
};

