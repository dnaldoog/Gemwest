#include "pch.h"
#include "CDcalc.h"
//void CDcalc::Initializer(
//	String^ cutName,
//	String^ fac,
//	String^ d1,
//	String^ d2,
//	String^ dep,
//	String^ sg,
//	String^ adj,
//	String^ gt,
//	String^ pv,
//	String^ so,
//	Boolean isdiamond,
//	Boolean interp,
//	Boolean recut,
//	//Boolean roundish,
//	Boolean depthisperc) {
//	// load all arrays of fancy cut adjustments
//	/*load class with GUI values from user*/
//	m_cutName = cutName; // name of cut
//	m_factor = fac; // name of cut
//	m_d1 = d1; // diameter 1 (could be length)
//	m_d2 = d2; // diamter 2 (could be width)
//	m_depth = dep; // depth of stone in millimeters // or percentage
//	m_sg = sg; //Specific Gravity
//	m_isDiamond = isdiamond;
//	m_adj = adj; // user adjustments  
//	m_interp = interp; // interpolate?
//	m_recut = recut; // recut?
//	//m_roundish = roundish; // is the cut round necessitating in a different LW formula?
//	m_depthIsPerc = depthisperc; // is the incoming Depth a represenatation of percentage or mm?
//	//if (_isDiamond) { _sg = 1 };
//}



Decimal CDcalc::term() {
	//Double l, w, d, a, adj, f;
	//l = System::Convert::ToDouble(m_d1);
	//w = System::Convert::ToDouble(m_d2);
	//d = System::Convert::ToDouble(m_depth);
	//f = System::Convert::ToDouble(m_factor);
	//a = System::Convert::ToDouble(m_adj);

	//adj = CDcalc::adjustments(l*w*d*f,a);
	//adj = 1;
	//Double c = l * w * d * adj * f;
	//return c;
	Decimal factor = System::Convert::ToDecimal(m_factor);
	//Double l, w, d, f;
	//l = System::Convert::ToDouble(m_d1);
	//w = System::Convert::ToDouble(m_d2);
	//d = System::Convert::ToDouble(m_depth);
	//f = System::Convert::ToDouble(m_factor);
	//Double c = l * w * d * f;
	//return c;
	return m_d1 * m_d2 * m_depth * factor;
}
Decimal CDcalc::recut_weight() { return Convert::ToDecimal(0); };

Double CDcalc::adjustments(Double startValue,Double percentage) {
	Double adjp=1;
	if (percentage < 0) {

		adjp = startValue * (1 - percentage / 100);
	}
	else if (percentage > 0) {
		adjp =  startValue * (1 + percentage / 100);
	}
	else {
		adjp = 1;
	}
return adjp;
} // end adjust function

Double CDcalc::depthConvertFromPercent(Double summedWidth, Double depth, Boolean isPercentage) {

	if (isPercentage) {
		depth = (summedWidth*depth) / 100;
	}
/*************************************************************/
	return depth;
} // end adjust function

	 
