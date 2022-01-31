#include "pch.h"
#include "CBriolette.h"

Decimal CBriolette::term() {
	Decimal lsg(3.52);
	if (!m_isDiamond) {
	Decimal lsg = Convert::ToDecimal(m_sg);

	}

		Decimal sumWeight = m_d1 * m_d2 * m_d2 * lsg;
		Decimal sumAdj = this->add_adjustments_to_carat_weight(sumWeight);
		return sumAdj;
	//calculate = (length.toFloat() * width.toFloat()) * width.toFloat() * sg.toFloat() * adj.toFloat() * fac.toFloat();

}
