#pragma once
#include "CDcalc.h"
ref class CDround :
    public CDcalc
{
public:
	explicit CDround(
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
    //virtual Double term() const = 0;
    Double term() override;
    Double recut_weight() override;
    //virtual Double term() override;
    //String^ recut_weight() override;

};

