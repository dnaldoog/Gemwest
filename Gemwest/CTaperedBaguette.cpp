#include "pch.h"
#include "CTaperedBaguette.h"
Double CTaperedBaguette::term() {
	Double l, minw,maxw, d;
	l = System::Convert::ToDouble(m_d1);
	minw = System::Convert::ToDouble(m_d2);
	maxw = System::Convert::ToDouble(this->maxW);
	d = System::Convert::ToDouble(m_depth);
	Double c = l * ((minw+maxw)/2) * d * 0.00915;
	return c;
}