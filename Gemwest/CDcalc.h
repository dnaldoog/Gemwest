#pragma once
#include "CCalculator.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;


ref class CDcalc
{
	/*

	This code follows an earlier abandoned version written in Qt
	I am just porting it over because it works, but there is no doubt probably a better way!!

	*/
private:
		/*following are Form1 data passed to object*/
protected:
	String^ m_cutName; // name of cut
	String^ m_factor; // factor selected by cut choice
	String^ m_d1; // diameter 1 (could be length)
	String^ m_d2; // diamter 2 (could be width)
	String^ m_depth; // depth of stone in millimeters
	String^ m_sg; //Specific Gravity

	String^ m_adj; // total user adjustments  
	String^ m_gt; // girdle thickness
	String^ m_pv; // pavilion bulge
	String^ m_so; // shape outline

	Boolean m_isDiamond; // is it a diamond (not as found in the gem listing)
	Boolean m_interp; // interpolate?
	Boolean m_recut; // recut?
	//Boolean m_roundish; // is the cut round necessitating in a different LW formula?
	Boolean m_depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?
	//void DCalc::fancyCutInitializer();

public:
	void Initializer(
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
		Boolean depthisperc
	);

	/*end constructor*/
 //virtual String^ calculate();
	//virtual Double term();
	//property  String^ Calculate;

public:
	String^ print() {
		return System::Convert::ToString(5 + "many CDcalc");
	}
	virtual Double term() override;
	virtual String^ recut_weight() override;
	//static String^ dia_tapered_baguette_formula(String^ length, String^ minw, String^ maxw, String^ depth, String^ factor, String^ adj,Boolean perc) {
	//
	//    Double l = System::Convert::ToDouble(length);
	//    Double minwidth = System::Convert::ToDouble(minw);
	//    Double maxwidth = System::Convert::ToDouble(maxw);
	//    Double d = System::Convert::ToDouble(depth);
	//    Double f = System::Convert::ToDouble(factor);
	//    Double a = System::Convert::ToDouble(adj);
	//    a = (100 + a) / 100;
	//    
	//    if (perc) { d = (((minwidth + maxwidth) / 2)*l) * d / 100; } // we need to convert depth to mm
	//   // if (perc) { d = ((l+((minwidth + maxwidth) / 2)) * d) / 100; } // we need to convert depth to mm
	//
	//    //NOT SURE ABOUT THE ABOVE
	//    /*********************************************************************************
	// *
	// *   String ^List list = str.split(rx);
	// *
	// * Length x (MaxWidth+MinWidth)/2 * depth * adjustments * 0.00915
	// *
	// *
	// *
	// *********************************************************************************/
	//    Double myResult = l * ((minwidth + maxwidth) / 2) * d * f * a;// don't forget to round to 3 if set tp 0.0003 in preferences
	//    return System::Convert::ToString(Math::Round(myResult,2));
	//}

};
