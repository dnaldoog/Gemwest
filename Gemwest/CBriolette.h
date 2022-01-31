#pragma once
#include "CDcalc.h"

ref class CBriolette :
    public CDcalc
{
    //calculate = (length.toFloat() * width.toFloat()) * width.toFloat() * sg.toFloat() * adj.toFloat() * fac.toFloat();
private:


public:
    CBriolette(
        String^ cutName,
        String^ fac,
        Decimal d1,
        Decimal d2,
        Decimal dep,
        String^ sg,
        String^ adj,
        String^ gt,
        String^ pv,
        String^ so,
        Boolean isdiamond,
        Boolean recut,
        Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, recut, depthisperc) {};
    //property Boolean BoolDiamond
    //{
    //    Boolean get() { return isdiamond; }
    //    void set(String^ d)
    //    {
    //        isdiamond = false;
    //        if (d->Equals("diamond")) 
    //            isdiamond = true;
    //        
    //    }
    //}

    Decimal term() override;
};

