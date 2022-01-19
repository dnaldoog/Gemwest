#pragma once
#include "CDcalc.h"
ref class CDfancy :
    public CDcalc
{
private:
    String^ m_fancy;
public:
    property String^ fancyType
    {
        String^ get() { return m_fancy; }
        void set(String^ s)
        {
            m_fancy = s;
        }
    }
    virtual Double term() override;
};

//void CDcalc::fancyCutInitializer() {
//	Dictionary<Double, Double>^ marquise_formulae = gcnew Dictionary<Double, Double>;
//	Dictionary<Double, Double>^ emerald_formulae = gcnew Dictionary<Double, Double>;
//	Dictionary<Double, Double>^ pear_formulae = gcnew Dictionary<Double, Double>;
//	Dictionary<String^, String^>^ em_map = gcnew Dictionary<String^, String^>;
//	Dictionary<String^, String^>^ mq_map = gcnew Dictionary<String^, String^>;
//	Dictionary<String^, String^>^ pe_map = gcnew Dictionary<String^, String^>;
//	marquise_formulae->Add(1.0, 0.00565);
//	marquise_formulae->Add(1.5, 0.00580);
//	marquise_formulae->Add(2.0, 0.00585);
//	marquise_formulae->Add(2.5, 0.00595);
//	marquise_formulae->Add(3.0, 0.00600);
//	marquise_formulae->Add(0, 0);
//	emerald_formulae->Add(1.0, 0.0080);
//	emerald_formulae->Add(1.5, 0.0092);
//	emerald_formulae->Add(2.0, 0.0100);
//	emerald_formulae->Add(2.5, 0.0106);
//	emerald_formulae->Add(3.0, 0.0110);
//	emerald_formulae->Add(0, 0);
//	pear_formulae->Add(1.0, 0.00616);
//	pear_formulae->Add(1.5, 0.00600);
//	pear_formulae->Add(2.0, 0.00590);
//	pear_formulae->Add(2.5, 0.00575);
//	pear_formulae->Add(3.0, 0.00540);
//	pear_formulae->Add(0, 0);
//	em_map->Add("1.0", "0.0080");
//	em_map->Add("1.5", "0.0092");
//	em_map->Add("2.0", "0.0100");
//	em_map->Add("2.5", "0.0160");
//	mq_map->Add("1.50", "0.00565");
//	mq_map->Add("2.00", "0.00580");
//	mq_map->Add("2.50", "0.00585");
//	mq_map->Add("3.00", "0.00595");
//	pe_map->Add("1.25", "0.00615");
//	pe_map->Add("1.50", "0.00600");
//	pe_map->Add("1.66", "0.00590");
//	pe_map->Add("2.00", "0.00575");
//
//	_marquise_formulae = marquise_formulae;
//	_emerald_formulae = emerald_formulae;
//	_pear_formulae = pear_formulae;
//	_em_map = em_map;
//	_mq_map = mq_map;
//	_pe_map = pe_map;
//}

