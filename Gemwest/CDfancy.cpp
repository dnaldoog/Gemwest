#include "pch.h"
#include "CDfancy.h"

//Double CDfancy::term() {
//	Double d1, d2, d, f, avd, av;
//
//	d1 = System::Convert::ToDouble(m_d1);
//	d2 = System::Convert::ToDouble(m_d2);
//	d = System::Convert::ToDouble(m_depth);
//	f = System::Convert::ToDouble(m_factor);
//	if (f == 0.00) { f = 0.003; }
//	av = (d1 + d2) / 2;
//	avd = Math::Pow(av, 2);
//	Double c = avd * d * f;
//	return c;
//}

Double CDfancy::lw() {
	return m_length / m_width;

}
String^ CDfancy::setFancyRecutFactor() {
	String^ factor = "0.000";
	Double lw = this->lw();
	if (this->fancyType->Equals(MARQ)) {
	if (lw <= 1.0) { factor = m_marquise_formulae["1.0"]; }
	else if (lw <= 1.5) { factor = m_marquise_formulae["1.5"]; }
	else if (lw <= 2.0) { factor = m_marquise_formulae["2.0"]; }
	else if (lw <= 2.5) { factor = m_marquise_formulae["2.5"]; }
	else if (lw <= 3.0) { factor=m_marquise_formulae["3.0"]; }
	else { factor = m_marquise_formulae["3.0"]; }
	}
	else if (this->fancyType->Equals(PEAR)) {

		if (lw <= 1.0) { factor = m_pear_formulae["1.0"]; }
		else if (lw <= 1.5) { factor = m_pear_formulae["1.5"]; }
		else if (lw <= 2.0) { factor = m_pear_formulae["2.0"]; }
		else if (lw <= 2.5) { factor = m_pear_formulae["2.5"]; }
		else if (lw <= 3.0) { factor = m_pear_formulae["3.0"]; }
		else { factor = m_pear_formulae["3.0"]; }
	
	}
	else if(this->fancyType->Equals(EMER)) {
		if (lw <= 1.0) { factor = m_emerald_formulae["1.0"]; }
		else if (lw <= 1.5) { factor = m_emerald_formulae["1.5"]; }
		else if (lw <= 2.0) { factor = m_emerald_formulae["2.0"]; }
		else if (lw <= 2.5) { factor = m_emerald_formulae["2.5"]; }
		else if (lw <= 3.0) { factor = m_emerald_formulae["3.0"]; }
		else { factor = m_emerald_formulae["3.0"]; }
	}

	return factor;
}

void CDfancy::dictInitializer() {

	Dictionary<String^, String^>^ tmp_marquise_formulae = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ tmp_pear_formulae = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ tmp_emerald_formulae = gcnew Dictionary<String^, String^>;

	tmp_marquise_formulae->Add("1.0", "0.00565");
	tmp_marquise_formulae->Add("1.5", "0.00580");
	tmp_marquise_formulae->Add("2.0", "0.00585");
	tmp_marquise_formulae->Add("2.5", "0.00595");
	tmp_marquise_formulae->Add("3.0", "0.00600");
	//tmp_marquise_formulae->Add("0", "0");


	tmp_pear_formulae->Add("1.0", "0.00616");
	tmp_pear_formulae->Add("1.5", "0.00600");
	tmp_pear_formulae->Add("2.0", "0.00590");
	tmp_pear_formulae->Add("2.5", "0.00575");
	tmp_pear_formulae->Add("3.0", "0.00540");
	//tmp_pear_formulae->Add("0", "0");

	tmp_emerald_formulae->Add("1.0", "0.0080");
	tmp_emerald_formulae->Add("1.5", "0.0092");
	tmp_emerald_formulae->Add("2.0", "0.0100");
	tmp_emerald_formulae->Add("2.5", "0.0106");
	tmp_emerald_formulae->Add("3.0", "0.0110");
	//tmp_emerald_formulae->Add("0", "0");

	this->setDictM(tmp_marquise_formulae);
	this->setDictP(tmp_pear_formulae);
	this->setDictE(tmp_emerald_formulae);
	}

void CDfancy::setDictM(Dictionary<String^, String^>^ m) {
	this->m_marquise_formulae=m;
}
void CDfancy::setDictP(Dictionary<String^, String^>^ p) {
	this->m_pear_formulae=p;
}
void CDfancy::setDictE(Dictionary<String^, String^>^ e) {
	this->m_emerald_formulae=e;
}
