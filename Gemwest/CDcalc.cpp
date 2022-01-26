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
	
	Decimal l = this->m_d1;
	Decimal w = this->m_d2;
	Decimal d = this->m_depth;
	Decimal f = System::Convert::ToDecimal(m_factor);

	//Double factor = Convert::ToDouble(m_factor);
	return this->add_adjustments_to_carat_weight(l * w * d * f);
}
Decimal CDcalc::recut_weight() { return Convert::ToDecimal(0); };

Double CDcalc::depthConvertFromPercent(Double summedWidth, Double depth, Boolean isPercentage) {

	if (isPercentage) {
		depth = (summedWidth*depth) / 100;
	}
/*************************************************************/
	return depth;
} // end adjust function

Decimal CDcalc::add_adjustments_to_carat_weight(Decimal rw) {
	//Double rw=Convert::ToDouble(raw_weight);
	Double rwd = Convert::ToDouble(rw);
	Double conv = Convert::ToDouble(m_adj);
	signed short sign = Math::Sign(conv);
	Double retValue = 0;

	if (sign == -1) {
		//MessageBox::Show("sign=" + ((conv / 100)));
		retValue = rwd * (1 - (Math::Abs(conv / 100)));

	}
	else if (sign == 1)
	{
		//MessageBox::Show("sign=" + sign + " conv=" + conv);
		retValue = rwd * (1 + (conv / 100));
	}
	else if (sign == 0)
		//MessageBox::Show("sign=" + sign + " conv=" + conv);
	{
		retValue = rwd;
	}
	//MessageBox::Show(""+Math::Sign(conv));
	//return "yes";
	return Convert::ToDecimal(retValue);
	//return Convert::ToDecimal(retValue);
}

	 
