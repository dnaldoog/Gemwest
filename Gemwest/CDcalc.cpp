#include "pch.h"
#include "CDcalc.h"

Decimal CDcalc::term() {
	
	Decimal l = this->m_d1;
	Decimal w = this->m_d2;
	Decimal d = this->m_depth;
	Decimal f = System::Convert::ToDecimal(m_factor);
	return CCalculator::add_adjustments_to_carat_weight(l * w * d * f,m_adj);
}
Decimal CDcalc::recut_weight() { return Convert::ToDecimal(0); };



	 
