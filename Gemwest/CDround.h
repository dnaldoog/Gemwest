#pragma once
#include "CDcalc.h"
ref class CDround :
    public CDcalc
{
private:
	String^ m_recut_image;
public:
	explicit CDround(
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
		Boolean interp,
		Boolean recut,

		Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, interp, recut, depthisperc) {}

    Decimal term() override;
    Decimal recut_weight() override;
	property String^ cutimage
	{
		String^ get() { return m_recut_image; }
		void set(String^ c)
		{
			m_recut_image = c;
		}
	}
};

