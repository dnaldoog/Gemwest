#include "pch.h"
#include "DCalc.h"

void DCalc::fancyCutInitializer() {
	Dictionary<double, double>^ marquise_formulae = gcnew Dictionary<double, double>;
	Dictionary<double, double>^ emerald_formulae = gcnew Dictionary<double, double>;
	Dictionary<double, double>^ pear_formulae = gcnew Dictionary<double, double>;
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
	//double Length = System::Convert::ToDouble(_d1);
	//double Width = System::Convert::ToDouble(_d2);
	//double Depth = System::Convert::ToDouble(_depth);
	//double SG = System::Convert::ToDouble(_sg);
	//double Factor = System::Convert::ToDouble(_factor);

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
	//double sum = Math::Round(Length * Width * Depth * Factor, 2);
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
	bool isdiamond,
	bool interp,
	bool recut,
	bool roundish,
	bool depthisperc) {
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
	if (_depthIsPerc) { depth = (avDiameter * depth) / 100; } // we need to convert depth to mm
	calculate = Math::Round(((avDiameter * avDiameter) * depth * factor)*adjust,2);
	return System::Convert::ToString(calculate);
}
String^ DCalc::dia_lwd_formula(void) {
	return this->dia_oval_formula();
}
String^ DCalc::dia_tapered_baguette_formula(void) {
	//String^ minwidth, maxwidth;
	//String^ w = returnWidth();
	///*********************************************************************************
	// *
	// *   String ^List list = str.split(rx);
	// *
	// * Length x (MaxWidth+MinWidth)/2 * depth * adjustments * 0.00915
	// *
	// *
	// *
	// *********************************************************************************/
	//String^ List list;
	//list = w.split(",");
	//if (list.count() != 2) {

	//}
	//else {
	//    maxwidth = list[0];
	//    minwidth = list[1];
	//}


	//Double calculate, addminmax;
	//addminmax = ((maxwidth.toDouble() + minwidth.toDouble()) / 2);
	//sum_all_adjustments();
	//calculate = _length.toDouble() * addminmax * _depth.toDouble() * _adjustments.toDouble() * _factor.toDouble();
	//int x = returnDecPlaces(addminmax);
	//return String ^ ::number(calculate, 'f', x);
	return "tbag";
}

//String^ DCalc::fancy_dia_formula(FDF* a, bool interpolate) {
	//String^ lwratio = returnLengthToWidth();
	//Double factor, calculate;
	//factor = returnFancyFactor(a, lwratio.toDouble(), interpolate);
	//sum_all_adjustments();
	//calculate = (_length.toDouble() * _width.toDouble()) * _depth.toDouble() * _adjustments.toDouble() * factor;
	//this->write_Factor(String ^ ::number(factor, 'f', 6));
	//int x = returnDecPlaces(_width.toDouble());
	//return String ^ ::number(calculate, 'f', x);
//}

/*
Step 3: Formulas for Estimating Cabochon Gem Weight
Flat-bottomed cabs actually range from 0.0023 to 0.0029. Those with a bottom bulge range from 0.0024 to 0.0030. As a general rule, use the following formulas:

High-Domed Cabs
Length ? width ? depth ? SG ? 0.0026

Low-Domed Cabs
Length ? width ? depth ? SG ? 0.0029

Step 4: Adjusting Your Gem Weight Estimate
If the stone you’re examining isn’t well-proportioned or has a very thin or thick girdle, adjust your gem weight estimate as follows:

Girdle
Use an average of the girdle thickness. Don’t base your reading on a bulge at the top of a heart or the point of a gem.

Thin girdle, subtract 1% to 2%.
Slightly thick, add 1% to 2%.
Thick, add 3% to 4%.
Very thick, add 5% to 6%.
Extra thick, add 7% to 10%.
Pavilion Bulge
Slight, add 3% to 5%.
Noticeable, add 6% to 8%.
Obvious, add 9% to 12%.
Extreme, add 13% to 18%.
A long culet due to steep pavilion angles can add up to 5%.

Shape Outline
Wide corners on cut corner squares and rectangles can decrease weight as much as 5%.
For oval, pear, marquise, and heart cuts, wide wings or high shoulders can add up to 10%. Occasionally, straight shoulders will require a deduction of 1% to 5%.
Marquise and (sometimes) pears will have a very short keel or none at all. This will reduce the weight by 1% to 3%.
Triangles with straight sides will require a reduction of up to 10%.
*/

