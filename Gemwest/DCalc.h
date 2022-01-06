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
    Dictionary<double, double>^ _marquise_formulae;
    Dictionary<double, double>^ _emerald_formulae;
    Dictionary<double, double>^ _pear_formulae;
    Dictionary<String^, String^>^ _em_map;
    Dictionary<String^, String^>^ _mq_map;
    Dictionary<String^, String^>^ _pe_map;
    void dictInitializer();
    String^ _cutName; // name of cut
    String^ _factor; // factor selected by cut choice
    String^ _d1; // diameter 1 (could be length)
    String^ _d2; // diamter 2 (could be width)
    String^ _depth; // depth of stone in millimeters
    String^ _sg; //Specific Gravity
    String^ _gt; // girdle thickness
    String^ _pv; // pavilion bulge
    String^ _adj; // user adjustments  
    bool _isDiamond; // is it a diamond (not as found in the gem listing)
    bool _interp; // interpolate?
    bool _recut; // recut?
    bool _roundish; // is the cut round necessitating in a different LW formula?
    bool _depthIsPerc; // is the incoming Depth a represenatation of percentage or mm?

public:
 DCalc( // parameters of GUI input passed to function
     String^ cutName, 
     String^ fac,
     String^ d1, 
     String^ d2, 
     String^ dep, 
     String^ sg, 
     String^ gt,
     String^ pv,
     String^ adj, 
     bool isdiamond, 
     bool interp, 
     bool recut, 
     bool roundish,
     bool depthisperc
 )
 
 {
     this->dictInitializer(); // load all arrays of fancy cut adjustments
     /*load class with GUI values from user*/
     _cutName=cutName; // name of cut
     _factor=fac; // name of cut
     _d1=d1; // diameter 1 (could be length)
     _d2=d2; // diamter 2 (could be width)
     _depth=dep; // depth of stone in millimeters // or percentage
     _sg=sg; //Specific Gravity
     _isDiamond = isdiamond;
     _adj=adj; // user adjustments  
     _interp=interp; // interpolate?
     _recut=recut; // recut?
     _roundish=roundish; // is the cut round necessitating in a different LW formula?
     _depthIsPerc = depthisperc; // is the incoming Depth a represenatation of percentage or mm?
     //if (_isDiamond) { _sg = 1 };
 }
 //DCalc^ C=gcnew DCalc(this->comb)
    /*end constructor*/

 //property  String^ Calculate;
};

