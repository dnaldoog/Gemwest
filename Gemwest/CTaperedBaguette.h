#pragma once
#include "CDcalc.h"
ref class CTaperedBaguette : public CDcalc
{
private:
   // String^ m_minW; // minimum Width - this is dia2
    String^ m_maxW; // maximum Width
public:

	explicit CTaperedBaguette(
		String^ cutName, //
		String^ fac, //
		String^ d1, //
		String^ d2, //
		String^ dep, //
		String^ sg, //
		String^ adj, //
		String^ gt, //
		String^ pv, //
		String^ so, //

		Boolean isdiamond, //
		Boolean interp, //
		Boolean recut, //

		Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, interp, recut, depthisperc) {}


    property String^ maxW
    {
        String^ get() { return m_maxW; }
        void set(String^ s)
        {
            m_maxW=s;
        }
    }
    virtual Double term() override;
};




