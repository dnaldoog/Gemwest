#pragma once
#include "CDcalc.h"
ref class CTaperedBaguette : public CDcalc
{
private:
    Decimal m_maxW; // maximum Width
public:

	explicit CTaperedBaguette(
		String^ cutName, 
		Decimal fac,
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


    property Decimal maxW
    {
        Decimal get() { return m_maxW; }
        void set(Decimal d)
        {
            m_maxW=d;
        }
    }
    virtual Decimal term() override;
};




