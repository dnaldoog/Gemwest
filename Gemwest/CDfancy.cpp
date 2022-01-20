#include "pch.h"
#include "CDfancy.h"

Double CDfancy::lw() {
	return m_length / m_width;

}
String^ CDfancy::setFancyRecutFactor() {
	if (this->m_interpolate) {
		Double ifact = this->interpolateFactor();
		return System::Convert::ToString(ifact);
	}
	else {
		String^ factor = "0.000";
		Double lw = this->lw();
		if (this->fancyType->Equals(MARQ)) {
			if (lw <= 1.0) { factor = m_marquise_formulae["1.0"]; }
			else if (lw <= 1.5) { factor = m_marquise_formulae["1.5"]; }
			else if (lw <= 2.0) { factor = m_marquise_formulae["2.0"]; }
			else if (lw <= 2.5) { factor = m_marquise_formulae["2.5"]; }
			else if (lw <= 3.0) { factor = m_marquise_formulae["3.0"]; }
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
		else if (this->fancyType->Equals(EMER)) {
			if (lw <= 1.0) { factor = m_emerald_formulae["1.0"]; }
			else if (lw <= 1.5) { factor = m_emerald_formulae["1.5"]; }
			else if (lw <= 2.0) { factor = m_emerald_formulae["2.0"]; }
			else if (lw <= 2.5) { factor = m_emerald_formulae["2.5"]; }
			else if (lw <= 3.0) { factor = m_emerald_formulae["3.0"]; }
			else { factor = m_emerald_formulae["3.0"]; }
		}

		return factor;
	}// end interpolate
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
	this->m_marquise_formulae = m;
}
void CDfancy::setDictP(Dictionary<String^, String^>^ p) {
	this->m_pear_formulae = p;
}
void CDfancy::setDictE(Dictionary<String^, String^>^ e) {
	this->m_emerald_formulae = e;
}

Double CDfancy::interpolateFactor() {/*Code taken from Gemwest GTK*/
	Double outOfRange = 0; /*From Gemwest GTK program*/
	Double lw = this->lw();
	Double hiMark = 0;
	Double loMark = 0;
	Double hiFactor = 0;
	Double loFactor=0;
	array<Double>^ thresh = gcnew array<Double>{
		1.0, 1.5, 2.0, 2.5, 3.0
	};
	if (this->fancyType->Equals(MARQ)) {
		if (lw <= 1.0) {
			//loFactor = System::Convert::ToDouble(m_marquise_formulae["1.0"]);
			//hiFactor = System::Convert::ToDouble(m_marquise_formulae["1.0"]);
			//loMark = thresh[0], hiMark = thresh[0];
			outOfRange = System::Convert::ToDouble(m_marquise_formulae["1.0"]);
		}
		else if (lw <= 1.5) {
			loFactor = System::Convert::ToDouble(m_marquise_formulae["1.0"]);
			hiFactor = System::Convert::ToDouble(m_marquise_formulae["1.5"]);
			loMark = thresh[0], hiMark = thresh[1];
		}
		else if (lw <= 2.0) {
			loFactor = System::Convert::ToDouble(m_marquise_formulae["1.5"]);
			hiFactor = System::Convert::ToDouble(m_marquise_formulae["2.0"]);
			loMark = thresh[1], hiMark = thresh[2];
		}
		else if (lw <= 2.5) {
			loFactor = System::Convert::ToDouble(m_marquise_formulae["2.0"]);
			hiFactor = System::Convert::ToDouble(m_marquise_formulae["2.5"]);
			loMark = thresh[2], hiMark = thresh[3];
		}
		else if (lw <= 3.0) {
			loFactor = System::Convert::ToDouble(m_marquise_formulae["2.5"]);
			hiFactor = System::Convert::ToDouble(m_marquise_formulae["3.0"]);
			loMark = thresh[3], hiMark = thresh[4];
		}
		else {
			outOfRange = System::Convert::ToDouble(m_marquise_formulae["3.0"]);
		}
	}
	else if (this->fancyType->Equals(PEAR)) {
		if (lw <= 1.0) {
			//loFactor = System::Convert::ToDouble(m_pear_formulae["1.0"]);
			//hiFactor = System::Convert::ToDouble(m_pear_formulae["1.0"]);
			//loMark = thresh[0], hiMark = thresh[0];
			outOfRange = System::Convert::ToDouble(m_pear_formulae["1.0"]);
		}
		else if (lw <= 1.5) {
			loFactor = System::Convert::ToDouble(m_pear_formulae["1.0"]);
			hiFactor = System::Convert::ToDouble(m_pear_formulae["1.5"]);
			loMark = thresh[0], hiMark = thresh[1];
		}
		else if (lw <= 2.0) {
			loFactor = System::Convert::ToDouble(m_pear_formulae["1.5"]);
			hiFactor = System::Convert::ToDouble(m_pear_formulae["2.0"]);
			loMark = thresh[1], hiMark = thresh[2];
		}
		else if (lw <= 2.5) {
			loFactor = System::Convert::ToDouble(m_pear_formulae["2.0"]);
			hiFactor = System::Convert::ToDouble(m_pear_formulae["2.5"]);
			loMark = thresh[2], hiMark = thresh[3];
		}
		else if (lw <= 3.0) {
			loFactor = System::Convert::ToDouble(m_pear_formulae["2.5"]);
			hiFactor = System::Convert::ToDouble(m_pear_formulae["3.0"]);
			loMark = thresh[3], hiMark = thresh[4];
		}
		else {
			outOfRange = System::Convert::ToDouble(m_pear_formulae["3.0"]);
		}
	}
	else if (this->fancyType->Equals(EMER)) {
		if (lw <= 1.0) {
			//loFactor = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
			//hiFactor = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
			//loMark = thresh[0], hiMark = thresh[0];
			outOfRange = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
		}
		else if (lw <= 1.5) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["1.5"]);
			loMark = thresh[0], hiMark = thresh[1];
		}
		else if (lw <= 2.0) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["1.5"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["2.0"]);
			loMark = thresh[1], hiMark = thresh[2];
		}
		else if (lw <= 2.5) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["2.0"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["2.5"]);
			loMark = thresh[2], hiMark = thresh[3];
		}
		else if (lw <= 3.0) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["2.5"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["3.0"]);
			loMark = thresh[3], hiMark = thresh[4];
		}
		else {
			outOfRange = System::Convert::ToDouble(m_emerald_formulae["3.0"]);
		}
	}
	/*Code taken from Gemwest 1.03 GTK*/
	//gdouble interpolateFancyFactor(gdouble loMark, gdouble hiMark, gdouble loFactor, gdouble hiFactor, gdouble lwratio) {
	//	return_new_outOfRange = interpolateFancyFactor(lowratio, highratio, lowoutOfRange, highoutOfRange, lw_ratio);
	Double r, A, B, C, Z;
	A = ((lw - loMark) / loMark) * 100;
	B = ((hiMark - loMark) / loMark) * 100;
	C = A / B;
	Z = (loFactor + ((hiFactor - loFactor)) * C);
	r = Z;

	if (outOfRange != 0)
		r = Math::Round(outOfRange, 5);

	return Math::Round(r, 5);
}
