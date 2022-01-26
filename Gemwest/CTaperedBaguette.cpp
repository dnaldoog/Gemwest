#include "pch.h"
#include "CTaperedBaguette.h"
Double CTaperedBaguette::term() {
	Double factor = System::Convert::ToDouble(m_factor);
	Double l = dec2Dub(m_d1);
	Double min = dec2Dub(m_d2);
	Double max = dec2Dub(this->maxW);
	Double d = dec2Dub(m_depth);
	return l * ((min+max) / 2)* d * factor;
}