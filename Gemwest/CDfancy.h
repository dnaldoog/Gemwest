#pragma once
#include "CDcalc.h"

ref class CDfancy :
    public CDcalc
{
public:

    explicit CDfancy(
        String^ cutName, 
        String^ fac, 
        Decimal d1,
        Decimal d2,
        Decimal dep,
        Decimal sg,
        String^ adj, 
        String^ gt, 
        String^ pv, 
        String^ so, 

        Boolean isdiamond, 
        Boolean recut, 

        Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, recut, depthisperc) {}
private:
    String^ m_fancy;
    Decimal m_length;
    Decimal m_width;
;

public:
    property String^ fancyType
    {
        String^ get() { return m_fancy; }
        void set(String^ s)
        {
            m_fancy = s;
        }
    }
    property Decimal length
    {
        Decimal get() { return m_length; }
        void set(Decimal l)
        {
            m_length = l;
        }
    }
    property Decimal width
    {
        Decimal get() { return m_width; }
        void set(Decimal w)
        {
            m_width = w;
        }
    }


    Double lw();  // return length to width ratio
    String^ setFancyRecutFactor(); // calculate the correct factor for fancy cut stones

    virtual Decimal term() override;
};

