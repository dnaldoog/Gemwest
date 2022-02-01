#include "pch.h"
#include "CGcalc.h"
Decimal CGcalc::term() {
	Decimal f = Convert::ToDecimal(m_factor);
	Decimal sg = Convert::ToDecimal(m_sg);
	Decimal tw = m_d1 * m_d2 * m_depth * sg * f;
	return CCalculator::add_adjustments_to_carat_weight(tw,m_adj);


}

Decimal CGcalc::recut_weight() { return Convert::ToDecimal(0); };