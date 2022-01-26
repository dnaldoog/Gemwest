#include "pch.h"
#include "CDcalc.h"

Decimal CDcalc::term() {
	
	Decimal l = this->m_d1;
	Decimal w = this->m_d2;
	Decimal d = this->m_depth;
	Decimal f = System::Convert::ToDecimal(m_factor);
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

	Double rwd = Convert::ToDouble(rw);
	Double conv = Convert::ToDouble(m_adj);
	signed short sign = Math::Sign(conv);
	Double retValue = 0;

	if (sign == -1) {

		retValue = rwd * (1 - (Math::Abs(conv / 100)));

	}
	else if (sign == 1)
	{

		retValue = rwd * (1 + (conv / 100));
	}
	else if (sign == 0)

	{
		retValue = rwd;
	}

	return Convert::ToDecimal(retValue);

}

	 
