#include "pch.h"
#include "CDcalc.h"
void CDcalc::Initializer(
	String^ cutName,
	String^ fac,
	String^ d1,
	String^ d2,
	String^ dep,
	String^ sg,
	String^ adj,
	String^ gt,
	String^ pv,
	String^ so,
	Boolean isdiamond,
	Boolean interp,
	Boolean recut,
	//Boolean roundish,
	Boolean depthisperc) {
	// load all arrays of fancy cut adjustments
	/*load class with GUI values from user*/
	m_cutName = cutName; // name of cut
	m_factor = fac; // name of cut
	m_d1 = d1; // diameter 1 (could be length)
	m_d2 = d2; // diamter 2 (could be width)
	m_depth = dep; // depth of stone in millimeters // or percentage
	m_sg = sg; //Specific Gravity
	m_isDiamond = isdiamond;
	m_adj = adj; // user adjustments  
	m_interp = interp; // interpolate?
	m_recut = recut; // recut?
	//m_roundish = roundish; // is the cut round necessitating in a different LW formula?
	m_depthIsPerc = depthisperc; // is the incoming Depth a represenatation of percentage or mm?
	//if (_isDiamond) { _sg = 1 };
}

//Double CDcalc::dia_round_formula(void) {
//	Double calculate;
//	Double d1, d2, depth, factor, adjust;
//	d1 = System::Convert::ToDouble(m_d1);
//	d2 = System::Convert::ToDouble(m_d2);
//	depth = System::Convert::ToDouble(m_depth);
//	factor = System::Convert::ToDouble(m_factor);
//	adjust = (100 + System::Convert::ToDouble(m_adj)) / 100;
//	Double avDiameter = (d1 + d2) / 2;
//	
//	if (m_depthIsPerc){ depth = (avDiameter * depth) / 100; } // we need to convert depth to mm
//	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
//	//::WriteLine((avDiameter + " * " +  avDiameter) + " * " + depth + " * " + adjust + " * " + factor);
//	//return System::Convert::ToString(calculate);
//	return calculate;
//}
//Double CDcalc::dia_oval_formula(void) {
//	Double calculate;
//	Double length, width, depth, factor, adjust;
//	length = System::Convert::ToDouble(m_d1);
//	width = System::Convert::ToDouble(m_d2);
//	depth = System::Convert::ToDouble(m_depth);
//	factor = System::Convert::ToDouble(m_factor);
//	adjust = (100+System::Convert::ToDouble(m_adj))/100;
//	Double avDiameter = (length + width) / 2;
//	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
//	return calculate;
//}
//Double CDcalc::dia_lwd_formula(void) {
//	return this->dia_oval_formula();
//}

Double CDcalc::term() {
	Double l, w, d, f;
	l = System::Convert::ToDouble(m_d1);
	w = System::Convert::ToDouble(m_d2);
	d = System::Convert::ToDouble(m_depth);
	f = System::Convert::ToDouble(m_factor);
	Double c = l * w * d * f;
	return c;
}

String^ CDcalc::recut_weight() {
	Double l, w, d, f, a;
	l = System::Convert::ToDouble(m_d1);
	w = System::Convert::ToDouble(m_d2);
	d = System::Convert::ToDouble(m_depth);
	a = System::Convert::ToDouble(m_adj);
	f = System::Convert::ToDouble(m_factor);
	Double^ p = nullptr;
	const Double lowThreshold = 55;/*ie threshold is 54%*/
	const Double highThreshold = 62;/*ie threshold is 62%*/
	Double newDiameter = (l + w) / 2;
	Double newDepth = d;
	Double recutWeight;
	/*****************************/
	Double depthpercentage = w / d;/*get original depth percentage*/
	//Int16 dpCompareWithThreshold = (guint16)depthpercentage;/*cast*/
	//g_print("dpCompareWithThreshold %d\n",dpCompareWithThreshold);
	//tooltipString = g_strdup_printf("Depth Percentage%4.0f%% falls within %d and %d", depthpercentage, lowThreshold, highThreshold);
	//cutLegendLabel = g_strdup_printf("No Recut:: %4.0f%%", depthpercentage);
	//print_RECUTIMAGE_PIX(noimage_c, tooltipString, cutLegendLabel);/*reset image*/
	/*****************************/
	Double DeepStone = (w * 62) / 100;
	Double ShallowStone = (d * 100) / 58;
	/*****************************/
	//if (strcmp(cText, DIAOVALCUT) == 0 || strcmp(cText, DIAROUND) == 0 || strcmp(cText, DIAOLDMINE) == 0 || strcmp(cText, DIAOLDEURO) == 0) {
		//print_RECUTIMAGE_PIX(noRecut_c, tooltipString, cutLegendLabel);
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
	recutWeight = (newDiameter * newDiameter) * newDepth * 0.0061;

	return System::Convert::ToString(Math::Round(recutWeight,3));
}