#include "pch.h"
#include "CDcalc.h"
void CDcalc::Initializer(
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
	//Boolean roundish,
	Boolean depthisperc) {
	// load all arrays of fancy cut adjustments
	/*load class with GUI values from user*/
	m_cutName = cutName; // name of cut
	m_factor = fac; // name of cut
	m_d1 = d1; // diameter 1 (could be length)
	m_d2 = d2; // diamter 2 (could be width)
	m_depth = dep; // depth of stone in millimeters // or percentage
	m_sg = sg; //Specific Gravity
	m_isDiamond = isdiamond;
	m_adj = adj; // user adjustments  
	m_interp = interp; // interpolate?
	m_recut = recut; // recut?
	//m_roundish = roundish; // is the cut round necessitating in a different LW formula?
	m_depthIsPerc = depthisperc; // is the incoming Depth a represenatation of percentage or mm?
	//if (_isDiamond) { _sg = 1 };
}

//Double CDcalc::dia_round_formula(void) {
//	Double calculate;
//	Double d1, d2, depth, factor, adjust;
//	d1 = System::Convert::ToDouble(m_d1);
//	d2 = System::Convert::ToDouble(m_d2);
//	depth = System::Convert::ToDouble(m_depth);
//	factor = System::Convert::ToDouble(m_factor);
//	adjust = (100 + System::Convert::ToDouble(m_adj)) / 100;
//	Double avDiameter = (d1 + d2) / 2;
//	
//	if (m_depthIsPerc){ depth = (avDiameter * depth) / 100; } // we need to convert depth to mm
//	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
//	//::WriteLine((avDiameter + " * " +  avDiameter) + " * " + depth + " * " + adjust + " * " + factor);
//	//return System::Convert::ToString(calculate);
//	return calculate;
//}
//Double CDcalc::dia_oval_formula(void) {
//	Double calculate;
//	Double length, width, depth, factor, adjust;
//	length = System::Convert::ToDouble(m_d1);
//	width = System::Convert::ToDouble(m_d2);
//	depth = System::Convert::ToDouble(m_depth);
//	factor = System::Convert::ToDouble(m_factor);
//	adjust = (100+System::Convert::ToDouble(m_adj))/100;
//	Double avDiameter = (length + width) / 2;
//	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
//	return calculate;
//}
//Double CDcalc::dia_lwd_formula(void) {
//	return this->dia_oval_formula();
//}

Double CDcalc::term() {
	Double l, w, d, f;
	l = System::Convert::ToDouble(m_d1);
	w = System::Convert::ToDouble(m_d2);
	d = System::Convert::ToDouble(m_depth);
	f = System::Convert::ToDouble(m_factor);
	Double c = l * w * d * f;
	return c;
}

