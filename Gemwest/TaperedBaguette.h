#pragma once
#include "DCalc.h"
ref class TaperedBaguette// : public DCalc
{
private:
	String^ _minW; // minimum Width
	String^ _maxW; // maximum Width
	String^ _length; // length of tapered baguette
	String^ _depth; // depth of tapered baguette
	String^ _factor; // factor of tapered baguette should be 0.00915
	String^ _adjust; // adjustments
	Boolean _depthaspercent;

public:
	//TaperedBaguette();
	TaperedBaguette(String^ minw, String^ maxw, String^ l, String^ d, String^ f, String^ adj, Boolean isperc)
		:_minW(minw), _maxW(maxw), _length(l), _depth(d), _factor(f), _adjust(adj), _depthaspercent(isperc)
	{}

public:
	String^ calculate(void);
	String^ dia_tapered_baguette_formula(void);
};



