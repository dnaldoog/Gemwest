#include "pch.h"
#include "GemCut.h"

void GemCut::dictInitializer() {
	Dictionary<String^, String^>^ gemCut = gcnew Dictionary<String^, String^>;
	array<String^>^ gemCutNames = gcnew array<String^>{
			"briolette",
			"cabochon - regular",
			"cabochon - high domed cabs",
			"cabochon - low domed cabs",
			"emerald cut",
			"heart",
			"long rectangle",
			"marquise",
			"oval cut",
			"pear cut",
			"square cut",
			"square cushion",
			"square step cut",
			"square with cut corners",
			"round cut",
			"round bead",
			"rectangle",
			"rectangle step cut",
			"rectangle with cut corners",
			"rectangular cushion",
			"triangle"

	};
	gemCut->Add("briolette", "0.0000");
	gemCut->Add("cabochon - regular", "0.0028");
	gemCut->Add("cabochon - high domed cabs", "0.0026");
	gemCut->Add("cabochon - low domed cabs", "0.0029");
	gemCut->Add("emerald cut", "0.00245");
	gemCut->Add("heart", "0.0021");
	gemCut->Add("long rectangle", "0.0026");
	gemCut->Add("marquise", "0.0016");
	gemCut->Add("oval cut", "0.002");
	gemCut->Add("pear cut", "0.00175");
	gemCut->Add("square cut", "0.0023");
	gemCut->Add("square cushion", "0.0018");
	gemCut->Add("square step cut", "0.0023");
	gemCut->Add("square with cut corners", "0.0024");
	gemCut->Add("round cut", "0.0018");
	gemCut->Add("round bead", "0.00259");
	gemCut->Add("rectangle", "0.0026");
	gemCut->Add("rectangle step cut", "0.0025");
	gemCut->Add("rectangle with cut corners", "0.0026");
	gemCut->Add("rectangular cushion", "0.0022");
	gemCut->Add("triangle", "0.0018");
	this->setCut(gemCut);
	this->_gemCutNames = gemCutNames;
}

void GemCut::setCut(Dictionary<String^, String^>^ arr) {
	this->_gemCut = arr;

};

String^ GemCut::getCut(String^ key) {
	return this->_gemCut[key];

};

array<String^>^ GemCut::getCutNames() {
	return _gemCutNames;
}