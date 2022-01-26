#pragma once
#include "CDcalc.h"
ref class CTaperedBaguette : public CDcalc
{
private:
   // String^ m_minW; // minimum Width - this is dia2
    Decimal m_maxW; // maximum Width
public:

	explicit CTaperedBaguette(
		String^ cutName, //
		String^ fac, //
		Decimal d1,//
		Decimal d2,//
		Decimal dep,//
		String^ sg, //
		String^ adj, //
		String^ gt, //
		String^ pv, //
		String^ so, //

		Boolean isdiamond, //
		Boolean interp, //
		Boolean recut, //

		Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, interp, recut, depthisperc) {}


    property Decimal maxW
    {
        Decimal get() { return m_maxW; }
        void set(Decimal d)
        {
            m_maxW=d;
        }
    }
    virtual Double term() override;
};




