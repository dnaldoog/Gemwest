#include "pch.h"
#include "CDfancy.h"

Double CDfancy::lw() {
	return m_length / m_width;

}

void CDfancy::dictInitializer() {

	Dictionary<String^, String^>^ tmp_marquise_formulae = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ tmp_pear_formulae = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ tmp_emerald_formulae = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ tmp_oval_formulae = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ tmp_radiant_formulae = gcnew Dictionary<String^, String^>;

	tmp_marquise_formulae->Add("1.0", "0.00565");
	tmp_marquise_formulae->Add("1.5", "0.00580");
	tmp_marquise_formulae->Add("2.0", "0.00585");
	tmp_marquise_formulae->Add("2.5", "0.00595");
	tmp_marquise_formulae->Add("3.0", "0.00600");

	/*
	Marquise Cut: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.00565
Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.00580
Length to Width Ratio = 2.50 : 1.00, Adjustment Factor = 0.00585
Length to Width Ratio = 3.00 : 1.00, Adjustment Factor = 0.00595
*/

	tmp_pear_formulae->Add("1.0", "0.00616");
	tmp_pear_formulae->Add("1.5", "0.00600");
	tmp_pear_formulae->Add("2.0", "0.00590");
	tmp_pear_formulae->Add("2.5", "0.00575");
	tmp_pear_formulae->Add("3.0", "0.00540");
	/*
	Pear: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
Length to Width Ratio = 1.25 : 1.00, Adjustment Factor = 0.00615
Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.00600
Length to Width Ratio = 1.66 : 1.00, Adjustment Factor = 0.00590
Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.00575
*/
	tmp_emerald_formulae->Add("1.0", "0.00800");
	tmp_emerald_formulae->Add("1.5", "0.00920");
	tmp_emerald_formulae->Add("2.0", "0.01000");
	tmp_emerald_formulae->Add("2.5", "0.01060");
	tmp_emerald_formulae->Add("3.0", "0.01100");

	/*
	Emerald Cut: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
Length to Width Ratio = 1.00 : 1.00, Adjustment Factor = 0.0080
Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.0092
Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.0100
Length to Width Ratio = 2.50 : 1.00, Adjustment Factor = 0.0106
*/

	//tmp_oval_formulae->Add("1.0", "0.00625");
	//tmp_oval_formulae->Add("2.0", "0.00640");
	//tmp_oval_formulae->Add("3.0", "0.00670");
	//tmp_oval_formulae->Add("1.0", "0.00620");
	//tmp_oval_formulae->Add("2.5", "0.00620");
	//tmp_oval_formulae->Add("3.0", "0.00650");


	tmp_radiant_formulae->Add("1.0", "0.00800");
	tmp_radiant_formulae->Add("1.5", "0.00840");
	/*
	Radiant Cut : Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
		Length to Width Ratio = 1.00 : 1.00, Adjustment Factor = 0.0081
		Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.0084
*/


/*Round Brilliant: Approximate Estimated Carat Weight = Diameter2 × Depth × 0.0061 × GTF
Oval: Approximate Estimated Carat Weight = Length × Width × Depth × 0.0062 × GTF × WCF
Princess Cut: Approximate Estimated Carat Weight = Length × Width × Depth × 0.0083 × GTF × WCF
Asscher Cut: Approximate Estimated Carat Weight = Length × Width × Depth × 0.0080 × GTF × WCF
Cushion Cut: Approximate Estimated Carat Weight = Length × Width × Depth × 0.00815 × GTF × WCF
Heart: Approximate Estimated Carat Weight = Length × Width × Depth × 0.0059 × GTF × WCF
Baguette: Approximate Estimated Carat Weight = Length × Width × Depth × 0.00915 × GTF × WCF
Trillion Cut: Approximate Estimated Carat Weight = Length × Width × Depth × 0.0057 × GTF × WCF




https://goodcalculators.com/diamond-weight-calculator/
© 2015-2022 goodcalculators.com*/


	this->setDictM(tmp_marquise_formulae);
	this->setDictP(tmp_pear_formulae);
	this->setDictE(tmp_emerald_formulae);
	//this->setDictO(tmp_oval_formulae);
	this->setDictR(tmp_radiant_formulae);
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
//void CDfancy::setDictO(Dictionary<String^, String^>^ o) {
//	this->m_oval_formulae = o;
//}
void CDfancy::setDictR(Dictionary<String^, String^>^ r) {
	this->m_radiant_formulae = r;
}
/*   SET FACTOR CODE START BELLOW     */

String^ CDfancy::setFancyRecutFactor() {
	if (this->m_interpolate) {
		Double ifact = this->interpolateFactor();
		return System::Convert::ToString(ifact);
	}
	else {
		String^ factor = "0.000";
		Double lw = this->lw();
		if (this->fancyType->Equals(MARQ)) {
			if (lw <= 1.5) { factor = m_marquise_formulae["1.0"]; }
			else if (lw <= 2.0) { factor = m_marquise_formulae["1.5"]; }
			else if (lw <= 2.5) { factor = m_marquise_formulae["2.0"]; }
			else if (lw <= 3.0) { factor = m_marquise_formulae["2.5"]; }
			//else if (lw <= 3.5) { factor = m_marquise_formulae["3.0"]; }
			else { factor = m_marquise_formulae["3.0"]; }
		}
		else if (this->fancyType->Equals(PEAR)) {

			if (lw <= 1.5) { factor = m_pear_formulae["1.0"]; }
			else if (lw <= 2.0) { factor = m_pear_formulae["1.5"]; }
			else if (lw <= 2.5) { factor = m_pear_formulae["2.0"]; }
			else if (lw <= 3.0) { factor = m_pear_formulae["2.5"]; }
			//else if (lw <= 3.5) { factor = m_pear_formulae["3.0"]; }
			else { factor = m_pear_formulae["3.0"]; }

		}
		else if (this->fancyType->Equals(EMER)) {
			if (lw < 1.5) { factor = m_emerald_formulae["1.0"]; }
			else if (lw <= 2.0) { factor = m_emerald_formulae["1.5"]; }
			else if (lw <= 2.5) { factor = m_emerald_formulae["2.0"]; }
			else if (lw <= 3.0) { factor = m_emerald_formulae["2.5"]; }
			//else if (lw <= 3.5) { factor = m_emerald_formulae["3.0"]; }
			else { factor = m_emerald_formulae["3.0"]; }
		}
		//else if (this->fancyType->Equals(OVAL)) {
		//	if (lw <= 1.0) { factor = m_oval_formulae["1.0"]; }
		//	else if (lw <= 2.0) { factor = m_oval_formulae["2.0"]; }
		//	else if (lw <= 3.0) { factor = m_oval_formulae["3.0"]; }
		//	else { factor = m_oval_formulae["3.0"]; }
		//}
		else if (this->fancyType->Equals(RADI)) {
			if (lw < 1.5) {
				factor = m_radiant_formulae["1.0"];
			}
			else { factor = m_radiant_formulae["1.5"]; }
		}

		return factor;
	}// end interpolate
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
		if (lw > 0 && lw <= 1.0) {

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
		if (lw <= 1.5) {

			outOfRange = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
		}
		else if (lw <= 2.0) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["1.5"]);
			loMark = thresh[0], hiMark = thresh[1];
		}
		else if (lw <= 2.5) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["1.5"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["2.0"]);
			loMark = thresh[1], hiMark = thresh[2];
		}
		else if (lw <= 3.0) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["2.0"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["2.5"]);
			loMark = thresh[2], hiMark = thresh[3];
		}
		else if (lw <= 3.5) {
			loFactor = System::Convert::ToDouble(m_emerald_formulae["2.5"]);
			hiFactor = System::Convert::ToDouble(m_emerald_formulae["3.0"]);
			loMark = thresh[3], hiMark = thresh[4];
		}
		else {
			outOfRange = System::Convert::ToDouble(m_emerald_formulae["3.0"]);
		}
	}
	/*
Emerald Cut: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
Length to Width Ratio = 1.00 : 1.00, Adjustment Factor = 0.0080
Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.0092
Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.0100
Length to Width Ratio = 2.50 : 1.00, Adjustment Factor = 0.0106
*/
	//else if (this->fancyType->Equals(OVAL)) {

	//	if (lw <= 1.0) {
	//		//		1.0, 1.5, 2.0, 2.5, 3.0
	//		outOfRange = System::Convert::ToDouble(m_oval_formulae["1.0"]);
	//	}
	//	else if (lw <= 2.5) {
	//		loFactor = System::Convert::ToDouble(m_oval_formulae["1.0"]);
	//		hiFactor = System::Convert::ToDouble(m_oval_formulae["2.5"]);
	//		loMark = thresh[0], hiMark = thresh[3];
	//		/*	tmp_oval_formulae->Add("1.0", "0.00620");
	//tmp_oval_formulae->Add("2.5", "0.00620");
	//tmp_oval_formulae->Add("3.0", "0.00650");*/
	//	}
	//	else {
	//		outOfRange = System::Convert::ToDouble(m_oval_formulae["2.5"]);
	//	}
	//}
	else if (this->fancyType->Equals(RADI)) {
	if (lw < 1.5) {

		outOfRange = System::Convert::ToDouble(m_radiant_formulae["1.0"]);
	}
	else if (lw < 2) {
		loFactor = System::Convert::ToDouble(m_radiant_formulae["1.0"]);
		hiFactor = System::Convert::ToDouble(m_radiant_formulae["1.5"]);
		loMark = thresh[0], hiMark = thresh[2];
	}
	else {
		outOfRange = System::Convert::ToDouble(m_radiant_formulae["1.5"]);
	}
	}
	/*
Radiant Cut : Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
	Length to Width Ratio = 1.00 : 1.00, Adjustment Factor = 0.0081
	Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.0084
*/
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
