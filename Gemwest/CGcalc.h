#pragma once
using namespace System;
using namespace System::Collections::Generic;

ref class CGcalc
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
    String^ m_cutName; // name of cut
    String^ m_gemName; // name of gem (material)
    String^ m_factor; // factor selected by cut choice
    Decimal m_d1; // diameter 1 (could be length)
    Decimal m_d2; // diamter 2 (could be width)
    Decimal m_depth; // depth of stone in millimeters
    String^ m_sg; //Specific Gravity

    String^ m_adj; // total user adjustments  
    String^ m_gt; // girdle thickness
    String^ m_pv; // pavilion bulge
    String^ m_so; // shape outline

    bool m_isDiamond; // is it a diamond (not as found in the gem listing)
    bool m_interp; // interpolate?
    bool m_recut; // recut?
    bool m_roundish; // is the cut round necessitating in a different LW formula?
    bool m_depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?



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
        Decimal d1,
        Decimal d2,
        Decimal dep,
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

