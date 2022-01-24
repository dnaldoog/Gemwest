#pragma once
#include "CCalculator.h"
//#include "IDiamond.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;


ref class CDcalc : CCalculator
//ref class CDcalc : IDiamond
{
	/*

	This code follows an earlier abandoned version written in Qt
	I am just porting it over because it works, but there is no doubt probably a better way!!

	*/
private:
		/*following are Form1 data passed to object*/
protected:
	String^ m_cutName; // name of cut
	String^ m_factor; // factor selected by cut choice
	String^ m_d1; // diameter 1 (could be length)
	String^ m_d2; // diamter 2 (could be width)
	String^ m_depth; // depth of stone in millimeters
	String^ m_sg; //Specific Gravity

	String^ m_adj; // total user adjustments  
	String^ m_gt; // girdle thickness
	String^ m_pv; // pavilion bulge
	String^ m_so; // shape outline

	Boolean m_isDiamond; // is it a diamond (not as found in the gem listing)
	Boolean m_interp; // interpolate?
	Boolean m_recut; // recut?
	//Boolean m_roundish; // is the cut round necessitating in a different LW formula?
	Boolean m_depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?
	//void DCalc::fancyCutInitializer();

public:
	void Initializer(
		String^ cutName,
		String^ fac,
		String^ d1,
		String^ d2,
		String^ dep,
		String^ sg,
		String^ adj,
		String^ gt,
		String^ pv,
		String^ so,

		Boolean isdiamond,
		Boolean interp,
		Boolean recut,

		Boolean depthisperc
	);


public:
	String^ print() {
		return System::Convert::ToString(5 + "many CDcalc");
	}
	property Double getAdj {
		Double get() { return System::Convert::ToDouble(m_adj); }
	}
	 Double term() override;
	 Double recut_weight() override;
	static  Double adjustments(Double,Double);
	};
