#pragma once
#include "CDcalc.h"

ref class CDfancy :
    public CDcalc
{
public:

    explicit CDfancy(
        String^ cutName, //
        String^ fac, //
        Decimal d1,//
        Decimal d2,//
        Decimal dep,//
        String^ sg, //
        String^ adj, //
        String^ gt, //
        String^ pv, //
        String^ so, //

        Boolean isdiamond, //
        Boolean interp, //
        Boolean recut, //

        Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, interp, recut, depthisperc) {}
private:
    String^ m_fancy;
    Double m_length;
    Double m_width;
    Boolean m_interpolate;

    //Dictionary<String^, String^>^ m_marquise_formulae;// = gcnew Dictionary<String^, String^>;
    //Dictionary<String^, String^>^ m_pear_formulae;// = gcnew Dictionary<String^, String^>;
    //Dictionary<String^, String^>^ m_emerald_formulae;// = gcnew Dictionary<String^, String^>;
    ////Dictionary<String^, String^>^ m_oval_formulae;// = gcnew Dictionary<String^, String^>;
    //Dictionary<String^, String^>^ m_radiant_formulae;// = gcnew Dictionary<String^, String^>;


    //void setDictM(Dictionary<String^, String^>^);
    //void setDictP(Dictionary<String^, String^>^);
    //void setDictE(Dictionary<String^, String^>^);
    ////void setDictO(Dictionary<String^, String^>^);
    //void setDictR(Dictionary<String^, String^>^);

public:
    property String^ fancyType
    {
        String^ get() { return m_fancy; }
        void set(String^ s)
        {
            m_fancy = s;
        }
    }
    property Double length
    {
        Double get() { return m_length; }
        void set(Double l)
        {
            m_length = l;
        }
    }
    property Double width
    {
        Double get() { return m_width; }
        void set(Double w)
        {
            m_width = w;
        }
    }
    property Boolean interpolate
    {
        Boolean get() { return m_interpolate; }
        void set(Boolean b)
        {
            m_interpolate = b;
        }
    }

    void dictInitializer();
    //Double interpolateFactor();

    Double lw();  // return length to width ratio
    String^ setFancyRecutFactor(); // calculate the correct factor for fancy cut stones

    virtual Double term() override;
};

