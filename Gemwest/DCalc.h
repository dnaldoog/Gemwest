#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class DCalc
{
    /*
    
    This code follows an earlier abandoned version written in Qt
    I am just porting it over because it works, but there is no doubt probably a better way!!

    */
private:


String^ dia_round_formula(void);
String^ dia_oval_formula(void);
String^ dia_lwd_formula(void);
//String^ dia_tapered_baguette_formula(void);




    Dictionary<Double, Double>^ _marquise_formulae;
    Dictionary<Double, Double>^ _emerald_formulae;
    Dictionary<Double, Double>^ _pear_formulae;
    Dictionary<String^, String^>^ _em_map;
    Dictionary<String^, String^>^ _mq_map;
    Dictionary<String^, String^>^ _pe_map;
    //void dictInitializer();
    /*following are Form1 data passed to object*/
protected:
    String^ _cutName; // name of cut
    String^ _factor; // factor selected by cut choice
    String^ _d1; // diameter 1 (could be length)
    String^ _d2; // diamter 2 (could be width)
    String^ _depth; // depth of stone in millimeters
    String^ _sg; //Specific Gravity

    String^ _adj; // total user adjustments  
    String^ _gt; // girdle thickness
    String^ _pv; // pavilion bulge
    String^ _so; // shape outline
 
    Boolean _isDiamond; // is it a diamond (not as found in the gem listing)
    Boolean _interp; // interpolate?
    Boolean _recut; // recut?
    Boolean _roundish; // is the cut round necessitating in a different LW formula?
    Boolean _depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?
    void DCalc::fancyCutInitializer();

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
        Boolean roundish,
        Boolean depthisperc
    );

    /*end constructor*/
 String^ calculate();
 //property  String^ Calculate;

public:
static String^ dia_tapered_baguette_formula(String^ length, String^ minw, String^ maxw, String^ depth, String^ factor, String^ adj,Boolean perc) {

    Double l = System::Convert::ToDouble(length);
    Double minwidth = System::Convert::ToDouble(minw);
    Double maxwidth = System::Convert::ToDouble(maxw);
    Double d = System::Convert::ToDouble(depth);
    Double f = System::Convert::ToDouble(factor);
    Double a = System::Convert::ToDouble(adj);
    a = (100 + a) / 100;
    
    if (perc) { d = (((minwidth + maxwidth) / 2)*l) * d / 100; } // we need to convert depth to mm
   // if (perc) { d = ((l+((minwidth + maxwidth) / 2)) * d) / 100; } // we need to convert depth to mm

    //NOT SURE ABOUT THE ABOVE
    /*********************************************************************************
 *
 *   String ^List list = str.split(rx);
 *
 * Length x (MaxWidth+MinWidth)/2 * depth * adjustments * 0.00915
 *
 *
 *
 *********************************************************************************/
    Double myResult = l * ((minwidth + maxwidth) / 2) * d * f * a;// don't forget to round to 3 if set tp 0.0003 in preferences
    return System::Convert::ToString(Math::Round(myResult,2));
}
};
