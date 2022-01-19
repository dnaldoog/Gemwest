#pragma once
#include "CDcalc.h"
ref class CDround :
    public CDcalc
{
public:
    virtual Double term() override;
};

