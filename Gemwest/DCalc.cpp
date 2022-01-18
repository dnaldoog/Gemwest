#include "pch.h"
#include "DCalc.h"

void DCalc::fancyCutInitializer() {
	Dictionary<Double, Double>^ marquise_formulae = gcnew Dictionary<Double, Double>;
	Dictionary<Double, Double>^ emerald_formulae = gcnew Dictionary<Double, Double>;
	Dictionary<Double, Double>^ pear_formulae = gcnew Dictionary<Double, Double>;
	Dictionary<String^, String^>^ em_map = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ mq_map = gcnew Dictionary<String^, String^>;
	Dictionary<String^, String^>^ pe_map = gcnew Dictionary<String^, String^>;
	marquise_formulae->Add(1.0, 0.00565);
	marquise_formulae->Add(1.5, 0.00580);
	marquise_formulae->Add(2.0, 0.00585);
	marquise_formulae->Add(2.5, 0.00595);
	marquise_formulae->Add(3.0, 0.00600);
	marquise_formulae->Add(0, 0);
	emerald_formulae->Add(1.0, 0.0080);
	emerald_formulae->Add(1.5, 0.0092);
	emerald_formulae->Add(2.0, 0.0100);
	emerald_formulae->Add(2.5, 0.0106);
	emerald_formulae->Add(3.0, 0.0110);
	emerald_formulae->Add(0, 0);
	pear_formulae->Add(1.0, 0.00616);
	pear_formulae->Add(1.5, 0.00600);
	pear_formulae->Add(2.0, 0.00590);
	pear_formulae->Add(2.5, 0.00575);
	pear_formulae->Add(3.0, 0.00540);
	pear_formulae->Add(0, 0);
	em_map->Add("1.0", "0.0080");
	em_map->Add("1.5", "0.0092");
	em_map->Add("2.0", "0.0100");
	em_map->Add("2.5", "0.0160");
	mq_map->Add("1.50", "0.00565");
	mq_map->Add("2.00", "0.00580");
	mq_map->Add("2.50", "0.00585");
	mq_map->Add("3.00", "0.00595");
	pe_map->Add("1.25", "0.00615");
	pe_map->Add("1.50", "0.00600");
	pe_map->Add("1.66", "0.00590");
	pe_map->Add("2.00", "0.00575");

	_marquise_formulae = marquise_formulae;
	_emerald_formulae = emerald_formulae;
	_pear_formulae = pear_formulae;
	_em_map = em_map;
	_mq_map = mq_map;
	_pe_map = pe_map;
}

String^ DCalc::calculate() {
	if (_roundish) {
		return this->dia_round_formula()+ "ct"; }
	else {
		return this->dia_lwd_formula() + "ct";

	}
	//Double Length = System::Convert::ToDouble(_d1);
	//Double Width = System::Convert::ToDouble(_d2);
	//Double Depth = System::Convert::ToDouble(_depth);
	//Double SG = System::Convert::ToDouble(_sg);
	//Double Factor = System::Convert::ToDouble(_factor);

	//switch (index) {
	//case ROUNDCUTFORMULA:
	//	answer = this->dia_round_formula();
	//	break;
	//case RECTANGULARCUTFORMULA:
	//	answer = this->dia_lwd_formula();
	//	break;
	//case OVALCUTFORMULA:
	//	answer = this->dia_oval_formula();
	//	break;
	//case EMERALDCUTFORMULA:
	//	inter = returnInterpolate();
	//	answer = this->fancy_dia_formula(emerald_formulae, inter);
	//	break;
	//case MARQUISECUTFORMULA:
	//	inter = returnInterpolate();
	//	answer = this->fancy_dia_formula(marquise_formulae, inter);
	//	break;
	//case PEARCUTFORMULA:
	//	inter = returnInterpolate();
	//	answer = this->fancy_dia_formula(pear_formulae, inter);
	//	break;
	//case TAPEREDCUTFORMULA:
	//	answer = this->dia_tapered_baguette_formula();
	//	break;
	//default:
	//	answer = "error";
	//	break;
	//}
	//Double sum = Math::Round(Length * Width * Depth * Factor, 2);
	//System::Windows::Forms::MessageBox::Show("DIA>>d:" + _d1 + "d2: " + _d2 + "dp: " + _depth + "F: " + _factor);
	//if (_isDiamond) SG = 1; // the factor laready accounts for specific gravity of 3.52
	//return System::Convert::ToString(sum);
	////return L"1.00 ct";"
}
void DCalc::Initializer(
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
	Boolean depthisperc) {
	// load all arrays of fancy cut adjustments
	/*load class with GUI values from user*/
	_cutName = cutName; // name of cut
	_factor = fac; // name of cut
	_d1 = d1; // diameter 1 (could be length)
	_d2 = d2; // diamter 2 (could be width)
	_depth = dep; // depth of stone in millimeters // or percentage
	_sg = sg; //Specific Gravity
	_isDiamond = isdiamond;
	_adj = adj; // user adjustments  
	_interp = interp; // interpolate?
	_recut = recut; // recut?
	_roundish = roundish; // is the cut round necessitating in a different LW formula?
	_depthIsPerc = depthisperc; // is the incoming Depth a represenatation of percentage or mm?
	//if (_isDiamond) { _sg = 1 };
}

String^ DCalc::dia_round_formula(void) {
	Double calculate;
	Double d1, d2, depth, factor, adjust;
	d1 = System::Convert::ToDouble(_d1);
	d2 = System::Convert::ToDouble(_d2);
	depth = System::Convert::ToDouble(_depth);
	factor = System::Convert::ToDouble(_factor);
	adjust = (100 + System::Convert::ToDouble(_adj)) / 100;
	Double avDiameter = (d1 + d2) / 2;
	
	if (_depthIsPerc){ depth = (avDiameter * depth) / 100; } // we need to convert depth to mm
	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
	//::WriteLine((avDiameter + " * " +  avDiameter) + " * " + depth + " * " + adjust + " * " + factor);
	return System::Convert::ToString(calculate);
}
String^ DCalc::dia_oval_formula(void) {
	Double calculate;
	Double length, width, depth, factor, adjust;
	length = System::Convert::ToDouble(_d1);
	width = System::Convert::ToDouble(_d2);
	depth = System::Convert::ToDouble(_depth);
	factor = System::Convert::ToDouble(_factor);
	adjust = (100+System::Convert::ToDouble(_adj))/100;
	Double avDiameter = (length + width) / 2;
	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
	return System::Convert::ToString(calculate);
}
String^ DCalc::dia_lwd_formula(void) {
	return this->dia_oval_formula();
}

