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



Double CDcalc::term() {
	
	Double l = dec2Dub(m_d1);
	Double w = dec2Dub(m_d2);
	Double d = dec2Dub(m_depth);
	Double f = System::Convert::ToDouble(m_factor);

	//Double factor = Convert::ToDouble(m_factor);
	return l * w * d * f;
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

	 
