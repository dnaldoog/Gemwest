#pragma once
using namespace System;
using namespace System::Collections::Generic;

ref class GCalc
{
private:
    //Dictionary<double, double>^ _marquise_formulae;
    //Dictionary<double, double>^ _emerald_formulae;
    //Dictionary<double, double>^ _pear_formulae;
    //Dictionary<String^, String^>^ _em_map;
    //Dictionary<String^, String^>^ _mq_map;
    //Dictionary<String^, String^>^ _pe_map;
    //void dictInitializer();
    /*following are Form1 data passed to object*/
    String^ _cutName; // name of cut
    String^ _gemName; // name of gem (material)
    String^ _factor; // factor selected by cut choice
    String^ _d1; // diameter 1 (could be length)
    String^ _d2; // diamter 2 (could be width)
    String^ _depth; // depth of stone in millimeters
    String^ _sg; //Specific Gravity

    String^ _adj; // total user adjustments  
    String^ _gt; // girdle thickness
    String^ _pv; // pavilion bulge
    String^ _so; // shape outline

    bool _isDiamond; // is it a diamond (not as found in the gem listing)
    bool _interp; // interpolate?
    bool _recut; // recut?
    bool _roundish; // is the cut round necessitating in a different LW formula?
    bool _depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?



String^ gem_round_formula(void);
String^ gem_round_bead_formula(void);
String^ gem_lwd_formula(void);
String^ gem_oval_formula(void);
String^ gem_briolette_formula(void);
String^ returnWeight(void);

public:
    void Initializer(
        String^ cutName,
        String^ gemName,
        String^ fac,
        String^ d1,
        String^ d2,
        String^ dep,
        String^ sg,
        String^ adj,
        String^ gt,
        String^ pv,
        String^ so,

        bool isdiamond,
        bool interp,
        bool recut,
        bool roundish,
        bool depthisperc
    );

    /*end constructor*/
    String^ calculate();
};

