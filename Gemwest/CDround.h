#pragma once
#include "CDcalc.h"
ref class CDround :
    public CDcalc
{
public:
public:
    //virtual Double term() const = 0;
    Double term() override;
    Double recut_weight() override;
    //virtual Double term() override;
    //String^ recut_weight() override;

};

