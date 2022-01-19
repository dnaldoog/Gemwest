#include "pch.h"
#include "CDiamondCut.h"
//#include <cstddef>


void CDiamondCut::dictInitializer(){
Dictionary<String^, String^>^ diaCut = gcnew Dictionary<String^, String^>;
array<String^>^ diaCutNames = gcnew array<String^>{
		"asscher",
		"barion",
		"cushion brilliant",
		"eight cut",
		"emerald cut diamond",
		"heart brilliant",
		"flanders cut (dia.)",
		"old european cut",
		"old mine cut",
		"oval brilliant",
		"marquise brilliant",
		"pear brilliant",
		"princess brilliant",
		"radiant cut (dia.)",
		"round brilliant",
		"rose cut",
		"square cut (dia.)",
		"small baguette",
		"semi circle cut (dia.)",
		"tapered baguette",
		"triangular cut (dia.)",
		"trilliant cut (dia.)",
		"trillion (rounded sides)",
};
diaCut->Add("asscher", "0.00800");
diaCut->Add("barion", "0.00800");
diaCut->Add("cushion brilliant", "0.00815");
diaCut->Add("eight cut", "0.0061");
diaCut->Add("emerald cut diamond", "0.008");
diaCut->Add("heart brilliant", "0.0059");
diaCut->Add("flanders cut (dia.)", "0.007");
diaCut->Add("old european cut", "0.0067");
diaCut->Add("old mine cut", "0.0071");
diaCut->Add("oval brilliant", "0.0062");
diaCut->Add("marquise brilliant", "0.00565");
diaCut->Add("pear brilliant", "0.00615");
diaCut->Add("princess brilliant", "0.0082");
diaCut->Add("radiant cut (dia.)", "0.00800");
diaCut->Add("round brilliant", "0.0061");
diaCut->Add("rose cut", "0.0074");
diaCut->Add("square cut (dia.)", "0.0082");
diaCut->Add("small baguette", "0.00915");
diaCut->Add("semi circle cut (dia.)", "0.0077");
diaCut->Add("tapered baguette", "0.00915");
diaCut->Add("triangular cut (dia.)", "0.0057");
diaCut->Add("trilliant cut (dia.)", "0.0057");
diaCut->Add("trillion (rounded sides)", "0.0059");
this->setCut(diaCut);
this->m_diaCutNames = diaCutNames;
}

	void CDiamondCut::setCut(Dictionary<String^, String^>^ arr) {
		this->m_diaCut = arr;

	}

	String^ CDiamondCut::getCut(String^ key) {
		//if (this->_diaCut != nullptr) {
			return this->m_diaCut[key];
		//}else{
		//	return "not found";
		//}

	}

	array<String^>^ CDiamondCut::getCutNames() {
		return m_diaCutNames;
	}
