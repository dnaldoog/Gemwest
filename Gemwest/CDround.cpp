#include "pch.h"
#include "CDround.h"
Double CDround::term() {
	Double d1, d2, d, f,a, adj,avd,av,caratweight;
	d1 = System::Convert::ToDouble(m_d1);
	d2 = System::Convert::ToDouble(m_d2);
	d = System::Convert::ToDouble(m_depth);
	f = System::Convert::ToDouble(m_factor);
	a = System::Convert::ToDouble(m_adj);
	adj = CDcalc::adjustments(d1*d2*d*f,a);
	av = (d1 + d2) / 2;
	avd = Math::Pow(av, 2);
	caratweight = av * av * d * adj * f;
	return caratweight;
}

Double CDround::recut_weight() {
	Double l, w, d, f, a,adj;
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

	return Math::Round(recutWeight, 3);
}