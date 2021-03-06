#include "pch.h"
#include "CTaperedBaguette.h"
Decimal CTaperedBaguette::term() {
	// factor = CCalculator::fac2Dec(m_factor);
	Decimal l = m_d1;
	Decimal min = m_d2;
	Decimal max = this->maxW;
	Decimal d = m_depth;
	return CCalculator::add_adjustments_to_carat_weight(l * (Decimal::Add(min,max) / 2)* d * m_factor ,m_adj);
}