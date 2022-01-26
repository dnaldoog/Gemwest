#include "pch.h"
#include "CDfancy.h"

Double CDfancy::lw() {
	return m_length / m_width;

}

void CDfancy::dictInitializer() {

//	//Dictionary<String^, String^>^ tmp_marquise_formulae = gcnew Dictionary<String^, String^>;
//	Dictionary<String^, String^>^ tmp_pear_formulae = gcnew Dictionary<String^, String^>;
//	Dictionary<String^, String^>^ tmp_emerald_formulae = gcnew Dictionary<String^, String^>;
//	Dictionary<String^, String^>^ tmp_oval_formulae = gcnew Dictionary<String^, String^>;
//	Dictionary<String^, String^>^ tmp_radiant_formulae = gcnew Dictionary<String^, String^>;
//
//	//tmp_marquise_formulae->Add("1.0", "0.00565");
//	//tmp_marquise_formulae->Add("1.5", "0.00580");
//	//tmp_marquise_formulae->Add("2.0", "0.00585");
//	//tmp_marquise_formulae->Add("2.5", "0.00595");
//	//tmp_marquise_formulae->Add("3.0", "0.00600");
//
//	/*
//	Marquise Cut: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
//Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.00565
//Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.00580
//Length to Width Ratio = 2.50 : 1.00, Adjustment Factor = 0.00585
//Length to Width Ratio = 3.00 : 1.00, Adjustment Factor = 0.00595
//
//		if (lw <= 1.5) { factor = m_pear_formulae["1.5"]; }
//			else if (lw < 2.0) { factor = m_pear_formulae["2.0"]; }
//			//else if (lw <= 2.5) { factor = m_pear_formulae["2.5"]; }
//			//else if (lw <= 3.0) { factor = m_pear_formulae["3.0"]; }
//			//else if (lw <= 3.5) { factor = m_pear_formulae["3.0"]; }
//			else { factor = m_pear_formulae["2.5"]; }
//*/
//
//	tmp_pear_formulae->Add("vfat", "0.00615");
//	tmp_pear_formulae->Add("fat", "0.00600");
//	tmp_pear_formulae->Add("md1", "0.00580");
//	tmp_pear_formulae->Add("md2", "0.00575");
//	tmp_pear_formulae->Add("nar", "0.00595");
//	//tmp_pear_formulae->Add("3.0", "0.00540");
//	/*
//	Pear: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
//Length to Width Ratio = 1.25 : 1.00, Adjustment Factor = 0.00615
//Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.00600
//Length to Width Ratio = 1.66 : 1.00, Adjustment Factor = 0.00590
//Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.00575
//*/
//	tmp_emerald_formulae->Add("1.0", "0.00800");
//	tmp_emerald_formulae->Add("1.5", "0.00920");
//	tmp_emerald_formulae->Add("2.0", "0.01000");
//	tmp_emerald_formulae->Add("2.5", "0.01060");
//	tmp_emerald_formulae->Add("3.0", "0.01100");
//
//
//	/*
//	Emerald Cut: Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
//Length to Width Ratio = 1.00 : 1.00, Adjustment Factor = 0.0080
//Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.0092
//Length to Width Ratio = 2.00 : 1.00, Adjustment Factor = 0.0100
//Length to Width Ratio = 2.50 : 1.00, Adjustment Factor = 0.0106
//*/
//
////tmp_oval_formulae->Add("1.0", "0.00625");
////tmp_oval_formulae->Add("2.0", "0.00640");
////tmp_oval_formulae->Add("3.0", "0.00670");
////tmp_oval_formulae->Add("1.0", "0.00620");
////tmp_oval_formulae->Add("2.5", "0.00620");
////tmp_oval_formulae->Add("3.0", "0.00650");
//
//
//	tmp_radiant_formulae->Add("1.0", "0.00800");
//	tmp_radiant_formulae->Add("1.5", "0.00840");
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


	////this->setDictM(tmp_marquise_formulae);
	//this->setDictP(tmp_pear_formulae);
	//this->setDictE(tmp_emerald_formulae);
	////this->setDictO(tmp_oval_formulae);
	//this->setDictR(tmp_radiant_formulae);
}

//void CDfancy::setDictM(Dictionary<String^, String^>^ m) {
//	this->m_marquise_formulae = m;
//}
//void CDfancy::setDictP(Dictionary<String^, String^>^ p) {
//	this->m_pear_formulae = p;
//}
//void CDfancy::setDictE(Dictionary<String^, String^>^ e) {
//	this->m_emerald_formulae = e;
//}
////void CDfancy::setDictO(Dictionary<String^, String^>^ o) {
////	this->m_oval_formulae = o;
////}
//void CDfancy::setDictR(Dictionary<String^, String^>^ r) {
//	this->m_radiant_formulae = r;
//}
/*   SET FACTOR CODE START BELLOW     */

String^ CDfancy::setFancyRecutFactor() {
	if (this->m_interpolate) {
		//Double ifact = this->interpolateFactor();
		//return System::Convert::ToString(ifact);
		return "0.017";
	}
	else {
		String^ factor = "0.001";
		Double coefficient=0;
		Double lw = this->lw();
		if (this->fancyType->Equals(MARQ)) {
			//if (lw <= 1.5) { factor = m_marquise_formulae["1.0"]; }
			//else if (lw <= 2.0) { factor = m_marquise_formulae["1.5"]; }
			//else if (lw <= 2.5) { factor = m_marquise_formulae["2.0"]; }
			//else if (lw <= 3.0) { factor = m_marquise_formulae["2.5"]; }
			////else if (lw <= 3.5) { factor = m_marquise_formulae["3.0"]; }
			//else { factor = m_marquise_formulae["3.0"]; }


			if (lw < 1.44)	{	  coefficient = 0.00565; }
			else if (lw < 1.55) { coefficient = 0.00566; }
			else if (lw < 1.68) { coefficient = 0.00570; }
			else if (lw < 1.83) { coefficient = 0.00575; }
			else if (lw < 2.01) { coefficient = 0.00580; }
			else if (lw < 2.23) { coefficient = 0.00582; }
			else if (lw < 2.51) { coefficient = 0.00585; }
			else if (lw < 2.87) { coefficient = 0.00592; }
			else{				  coefficient = 0.00595; }
			//factor = Convert::ToString(coefficient);
			/*
			Length to width Ratio

Adjustment Factor

1.25:1.00	0.00565
2.00:1.00

0.00580

2.50:1.00

0.00585

3.00:1.00

1.00595

1.25:1	0.00615
1.5:1	0.006
1.66:1	0.0059
2:1	0.00575
			*/
		}
		else if (this->fancyType->Equals(PEAR)) {
			/*https://www.vcalc.com/wiki/KurtHeckman/Diamond+-+Pear-shape+Brilliant following checked against 01/26/2022*/
			//if (lw <= 1.25) { factor = m_pear_formulae["vfat"]; }
			//else if (lw <= 1.5) { factor = m_pear_formulae["fat"]; }
			//else if (lw <= 1.66) { factor = m_pear_formulae["md1"]; }
			//else if (lw < 2.0) { factor = m_pear_formulae["md2"]; }
			//else { factor = m_pear_formulae["nar"]; }
			//tmp_pear_formulae->Add("vfat", "0.00616");
			//tmp_pear_formulae->Add("fat", "0.00600");
			//tmp_pear_formulae->Add("mid", "0.00590");
			//tmp_pear_formulae->Add("nar", "0.00575");
			//tmp_pear_formulae->Add("3.0", "0.00540");
			// 

			//tmp_pear_formulae->Add("3.0", "0.00540");
			//1.25:1.00	0.00615
			//	1.50 : 1.00

			//	0.00600

			//	1.66 : 1.00
			if      (lw < 1.26) { coefficient = 0.00615; }
			else if (lw < 1.34) { coefficient = 0.00610; }
			else if (lw < 1.44) { coefficient = 0.00604; }
			else if (lw < 1.55) { coefficient = 0.00598; }
			else if (lw < 1.68) { coefficient = 0.00590; }
			else if (lw < 1.83) { coefficient = 0.00583; }
			else { coefficient = 0.00575; }
		}
		else if (this->fancyType->Equals(EMER)) {

			if (lw < 1.01) { coefficient = 0.00800; }
			else if (lw < 1.06) { coefficient = 0.00813; }
			else if (lw < 1.12) { coefficient = 0.00827; }
			else if (lw < 1.19) { coefficient = 0.00842; }
			else if (lw < 1.26) { coefficient = 0.00860; }
			else if (lw < 1.34) { coefficient = 0.00880; }
			else if (lw < 1.44) { coefficient = 0.00903; }
			else if (lw < 1.55) { coefficient = 0.00926; }
			else if (lw < 1.68) { coefficient = 0.00947; }
			else if (lw < 1.83) { coefficient = 0.00971; }
			else if (lw < 2.01) { coefficient = 0.01000; }
			else if (lw < 2.23) { coefficient = 0.01027; }
			else { coefficient = 0.01060; }
		}


			//if (lw < 1.5) { factor = m_emerald_formulae["1.0"]; }
			//else if (lw <= 2.0) { factor = m_emerald_formulae["1.5"]; }
			//else if (lw <= 2.5) { factor = m_emerald_formulae["2.0"]; }
			//else if (lw <= 3.0) { factor = m_emerald_formulae["2.5"]; }
			////else if (lw <= 3.5) { factor = m_emerald_formulae["3.0"]; }
			//else { factor = m_emerald_formulae["3.0"]; }
//			Double const loMark = 1;
//			Double  hiMark = Convert::ToDouble(m_d2);
//			Double const loFactor = 0.0080;
//			Double const hiFactor = 0.01060;
//
//
//			//gdouble interpolateFancyFactor(gdouble loMark, gdouble hiMark, gdouble loFactor, gdouble hiFactor, gdouble lwratio) {
////	return_new_outOfRange = interpolateFancyFactor(lowratio, highratio, lowoutOfRange, highoutOfRange, lw_ratio);
//	Double A, B, C, Z;
//	A = ((lw - loMark) / loMark) * 100;
//	B = ((hiMark - loMark) / loMark) * 100;
//	C = A / B;
//	Z = (loFactor + ((hiFactor - loFactor)) * C);
//	coefficient = Z;


		//}
		/*
		1.00:1.00	0.0080
		1.50:1.00

		0.0092

		2.00:1.00

		0.0100

		2.50:1.00

		0.0106
		*/
		else if (this->fancyType->Equals(RADI)) {
			//if (lw < 1.5) {
			//	factor = m_radiant_formulae["1.0"];
			//}
			//else { factor = m_radiant_formulae["1.5"]; }
			coefficient = 0.1;
		}
		factor = Convert::ToString(coefficient);
		return factor;
	}// end interpolate
}


//Double CDfancy::interpolateFactor() {/*Code taken from Gemwest GTK*/
//	Double outOfRange = 0; /*From Gemwest GTK program*/
//	Double lw = this->lw();
//	Double hiMark = 0;
//	Double loMark = 0;
//	Double hiFactor = 0;
//	Double loFactor = 0;
//	array<Double>^ thresh = gcnew array<Double>{
//		1.0, 1.5, 2.0, 2.5, 3.0
//	};
//	if (this->fancyType->Equals(MARQ)) {
//		if (lw > 0 && lw <= 1.0) {
//
//			outOfRange = System::Convert::ToDouble(m_marquise_formulae["1.0"]);
//		}
//		else if (lw <= 1.5) {
//			loFactor = System::Convert::ToDouble(m_marquise_formulae["1.0"]);
//			hiFactor = System::Convert::ToDouble(m_marquise_formulae["1.5"]);
//			loMark = thresh[0], hiMark = thresh[1];
//		}
//		else if (lw <= 2.0) {
//			loFactor = System::Convert::ToDouble(m_marquise_formulae["1.5"]);
//			hiFactor = System::Convert::ToDouble(m_marquise_formulae["2.0"]);
//			loMark = thresh[1], hiMark = thresh[2];
//		}
//		else if (lw <= 2.5) {
//			loFactor = System::Convert::ToDouble(m_marquise_formulae["2.0"]);
//			hiFactor = System::Convert::ToDouble(m_marquise_formulae["2.5"]);
//			loMark = thresh[2], hiMark = thresh[3];
//		}
//		else if (lw <= 3.0) {
//			loFactor = System::Convert::ToDouble(m_marquise_formulae["2.5"]);
//			hiFactor = System::Convert::ToDouble(m_marquise_formulae["3.0"]);
//			loMark = thresh[3], hiMark = thresh[4];
//		}
//		else {
//			outOfRange = System::Convert::ToDouble(m_marquise_formulae["3.0"]);
//		}
//	}
//	else if (this->fancyType->Equals(PEAR)) {
//		if (lw <= 1.0) {
//
//			outOfRange = System::Convert::ToDouble(m_pear_formulae["1.0"]);
//		}
//		else if (lw <= 1.5) {
//			loFactor = System::Convert::ToDouble(m_pear_formulae["1.0"]);
//			hiFactor = System::Convert::ToDouble(m_pear_formulae["1.5"]);
//			loMark = thresh[0], hiMark = thresh[1];
//		}
//		else if (lw <= 2.0) {
//			loFactor = System::Convert::ToDouble(m_pear_formulae["1.5"]);
//			hiFactor = System::Convert::ToDouble(m_pear_formulae["2.0"]);
//			loMark = thresh[1], hiMark = thresh[2];
//		}
//		else if (lw <= 2.5) {
//			loFactor = System::Convert::ToDouble(m_pear_formulae["2.0"]);
//			hiFactor = System::Convert::ToDouble(m_pear_formulae["2.5"]);
//			loMark = thresh[2], hiMark = thresh[3];
//		}
//		else if (lw <= 3.0) {
//			loFactor = System::Convert::ToDouble(m_pear_formulae["2.5"]);
//			hiFactor = System::Convert::ToDouble(m_pear_formulae["3.0"]);
//			loMark = thresh[3], hiMark = thresh[4];
//		}
//		else {
//			outOfRange = System::Convert::ToDouble(m_pear_formulae["3.0"]);
//		}
//	}
//	else if (this->fancyType->Equals(EMER)) {
//		if (lw <= 1.5) {
//
//			outOfRange = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
//		}
//		else if (lw <= 2.0) {
//			loFactor = System::Convert::ToDouble(m_emerald_formulae["1.0"]);
//			hiFactor = System::Convert::ToDouble(m_emerald_formulae["1.5"]);
//			loMark = thresh[0], hiMark = thresh[1];
//		}
//		else if (lw <= 2.5) {
//			loFactor = System::Convert::ToDouble(m_emerald_formulae["1.5"]);
//			hiFactor = System::Convert::ToDouble(m_emerald_formulae["2.0"]);
//			loMark = thresh[1], hiMark = thresh[2];
//		}
//		else if (lw <= 3.0) {
//			loFactor = System::Convert::ToDouble(m_emerald_formulae["2.0"]);
//			hiFactor = System::Convert::ToDouble(m_emerald_formulae["2.5"]);
//			loMark = thresh[2], hiMark = thresh[3];
//		}
//		else if (lw <= 3.5) {
//			loFactor = System::Convert::ToDouble(m_emerald_formulae["2.5"]);
//			hiFactor = System::Convert::ToDouble(m_emerald_formulae["3.0"]);
//			loMark = thresh[3], hiMark = thresh[4];
//		}
//		else {
//			outOfRange = System::Convert::ToDouble(m_emerald_formulae["3.0"]);
//		}
//	}
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
	//else if (this->fancyType->Equals(RADI)) {
	//	if (lw < 1.5) {

	//		outOfRange = System::Convert::ToDouble(m_radiant_formulae["1.0"]);
	//	}
	//	else if (lw < 2) {
	//		loFactor = System::Convert::ToDouble(m_radiant_formulae["1.0"]);
	//		hiFactor = System::Convert::ToDouble(m_radiant_formulae["1.5"]);
	//		loMark = thresh[0], hiMark = thresh[2];
	//	}
	//	else {
	//		outOfRange = System::Convert::ToDouble(m_radiant_formulae["1.5"]);
	//	}
	//}
	/*
Radiant Cut : Approximate Estimated Carat Weight = Length × Width × Depth × Adjustment Factor × GTF × WCF
	Length to Width Ratio = 1.00 : 1.00, Adjustment Factor = 0.0081
	Length to Width Ratio = 1.50 : 1.00, Adjustment Factor = 0.0084
*/
/*Code taken from Gemwest 1.03 GTK*/
//gdouble interpolateFancyFactor(gdouble loMark, gdouble hiMark, gdouble loFactor, gdouble hiFactor, gdouble lwratio) {
//	return_new_outOfRange = interpolateFancyFactor(lowratio, highratio, lowoutOfRange, highoutOfRange, lw_ratio);
//	Double r, A, B, C, Z;
//	A = ((lw - loMark) / loMark) * 100;
//	B = ((hiMark - loMark) / loMark) * 100;
//	C = A / B;
//	Z = (loFactor + ((hiFactor - loFactor)) * C);
//	r = Z;
//
//	if (outOfRange != 0)
//		r = Math::Round(outOfRange, 5);
//
//	return Math::Round(r, 5);
//}
Double  CDfancy::term() {
	Double factor = System::Convert::ToDouble(m_factor);
	Double l = dec2Dub(m_d1);
	Double w = dec2Dub(m_d2);
	Double dp = dec2Dub(m_depth);
	return  l * w * dp * factor;
}