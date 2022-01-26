#include "pch.h"
#include "CDround.h"
Decimal CDround::term() {
	Decimal factor = this->fac2Dec(m_factor);
	Decimal av_diameter =Decimal::Add(m_d1,m_d2) / 2;
	return this->add_adjustments_to_carat_weight((av_diameter*av_diameter) * m_depth * factor);
}

Decimal CDround::recut_weight() {
	Double l, w, d, f;
	l = System::Convert::ToDouble(m_d1);
	w = System::Convert::ToDouble(m_d2);
	d = System::Convert::ToDouble(m_depth);
	//a = System::Convert::ToDouble(m_adj);
	f = System::Convert::ToDouble(m_factor);
	//adj = CDcalc::adjustments(l * w * d * f, a);
//	Double^ p = nullptr;
	const Double lowThreshold = 55;/*ie threshold is 54%*/
	const Double highThreshold = 62;/*ie threshold is 62%*/
	Double newDiameter = (l + w) / 2;
	Double newDepth = d;
	Double recutWeight;
	/*****************************/
	Double depthpercentage = w / d;/*get original depth percentage*/

	/*****************************/
	Double DeepStone = (w * 62) / 100;
	Double ShallowStone = (d * 100) / 58;
	/*****************************/

	if (depthpercentage < lowThreshold) {/*it's a shallow stone*/
		//p = ShallowStone;
		newDiameter = ShallowStone;
		//tooltipString = "shallow stone";
		//print_RECUTIMAGE_PIX(shallow, tooltipString, tooltipString);
	}
	if (depthpercentage > highThreshold) {/*it's a deep stone*/
		//tooltipString = "deep stone";
		//p = DeepStone;
		newDepth = DeepStone;
		//print_RECUTIMAGE_PIX(deep, tooltipString, tooltipString);
	}
	recutWeight = (newDiameter * newDiameter) * newDepth * f;

	return Math::Round(System::Convert::ToDecimal(recutWeight), 3);
}