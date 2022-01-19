#include "pch.h"
#include "CDround.h"
Double CDround::term() {
	Double d1, d2, d, f,avd,av;
	d1 = System::Convert::ToDouble(m_d1);
	d2 = System::Convert::ToDouble(m_d2);
	d = System::Convert::ToDouble(m_depth);
	f = System::Convert::ToDouble(m_factor);
	av = (d1 + d2) / 2;
	avd = Math::Pow(av, 2);
	Double c = avd * d * f;
	return c;
}