#pragma once
#include "CCalculator.h"


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;


ref class CDcalc : CCalculator

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
	Decimal m_d1; // diameter 1 (could be length)
	Decimal m_d2; // diameter 2 (could be width)
	Decimal m_depth; // depth of stone in millimeters
	String^ m_sg; //Specific Gravity
	String^ m_adj; // total user adjustments  
	String^ m_gt; // girdle thickness
	String^ m_pv; // pavilion bulge
	String^ m_so; // shape outline
	Boolean m_isDiamond; // is it a diamond (not as found in the gem listing)
	Boolean m_recut; // recut?
	Boolean m_depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?


public:
	CDcalc(
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

		Boolean isdiamond, //
		Boolean recut, //

		Boolean depthisperc) :
		m_cutName(cutName), //  name of cut
		m_factor(fac), //  factor selected by cut choice
		m_d1(d1), //  diameter 1 (could be length)
		m_d2(d2), //  diamter 2 (could be width)
		m_depth(dep), //  depth of stone in millimeters
		m_sg(sg), // Specific Gravity

		m_adj(adj), //  total user adjustments  
		m_gt(gt), //  girdle thickness
		m_pv(pv), //  pavilion bulge
		m_so(so), //  shape outline

		m_isDiamond(isdiamond), //  is it a diamond (not as found in the gem listing)
		m_recut(recut), //  recut?
		m_depthIsPerc(depthisperc) //  is the incoming Depth a represenatation of percentage or mm?)(), //
	{}
	String^ print() {
		return System::Convert::ToString(5 + "many CDcalc");
	}

	Decimal term() override;
	Decimal add_adjustments_to_carat_weight(Decimal rw);
	Decimal recut_weight() override;

	Decimal fac2Dec() {
		return System::Convert::ToDecimal(m_factor);
	}

};