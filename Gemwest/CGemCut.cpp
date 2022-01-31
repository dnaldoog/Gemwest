#include "pch.h"
#include "CGemCut.h"


void CGemCut::dictInitializer() {
	Dictionary<String^, String^>^ gemCut = gcnew Dictionary<String^, String^>;
	cli::array<String^>^ gemCutNames = gcnew array<String^>{
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
/* TO BE ADDED
"briolette",
"cabochon - regular",
"cabochon - high domed cabs",
"cabochon - low domed cabs",
"cabochon - pear",
"cab - heart wide shoulders",
"cab - heart small cleft",
"cab - medium cleft",
"emerald cut",
"heart",
"marquise",
"oval cut",
"pear cut",
"pear wide shoulders",
"pear small cleft",
"pear medium cleft",
"pear deep cleft",
"radiant",
"rectangle",
"rectangle step cut",
"rectangle with cut corners",
"rectangular cushion",
"long rectangle",
"round cut",
"round bead",
"square cut",
"square cushion",
"square cushion brilliant",
"square cushion cabochon",
"square emerald",
"square princess",
"princess cut",
"square radiant",
"square step cut",
"square with cut corners",
"triangle",
*/
	};
	/* †NOTES AND NEW TECHNIQUES
ESTIMATING WEIGHTS OF MOUNTED
COLORED GEMSTONES
By Charles I. Carmona*/
	gemCut->Add("briolette", "0.0000");
	gemCut->Add("cabochon - regular", "0.00270 "); //†
	gemCut->Add("cabochon - high domed cabs", "0.0026");
	gemCut->Add("cabochon - low domed cabs", "0.0029");
	gemCut->Add("cabochon - pear", "0.00245");
	gemCut->Add("cab - heart wide shoulders", "0.00260");//†
	gemCut->Add("cab - heart small cleft", "0.00250");//†
	gemCut->Add("cab - medium cleft", "0.00240");//†
	gemCut->Add("emerald cut", "0.00270");
	gemCut->Add("heart", "0.0021");
	gemCut->Add("marquise", "0.0016");
	gemCut->Add("oval cut", "0.00210");//†
	gemCut->Add("pear cut", "0.00200");//†
	gemCut->Add("pear wide shoulders", "0.00210");//†
	gemCut->Add("pear small cleft", "0.00200");//†
	gemCut->Add("pear medium cleft", "0.00195");//†
	gemCut->Add("pear deep cleft", "0.00190");//†
	gemCut->Add("radiant", "0.00260");
	gemCut->Add("rectangle", "0.0026");
	gemCut->Add("rectangle step cut", "0.00300");//†
	gemCut->Add("rectangle with cut corners", "0.0026");
	gemCut->Add("rectangular cushion", "0.00235");//†
	gemCut->Add("long rectangle", "0.0026");
	gemCut->Add("round cut", "0.0020");
	gemCut->Add("round bead", "0.00259");
	gemCut->Add("square cut", "0.0023");
	gemCut->Add("square cushion", "0.00235");
	gemCut->Add("square cushion brilliant", "0.00235");//†
	gemCut->Add("square cushion cabochon", "0.00300");
	gemCut->Add("square emerald", "0.00230");
	gemCut->Add("square princess", "0.00250");
	gemCut->Add("princess cut", "0.00290");
	gemCut->Add("square radiant", "0.00230");
	gemCut->Add("square step cut", "0.00250");
	gemCut->Add("square with cut corners", "0.0024");
	gemCut->Add("triangle", "0.0018");
	this->setCut(gemCut);
	for each (KeyValuePair<String^, String^> ^ z in gemCut){
	//for each (System::DictionaryEntry ^ cut in gemCut)
		//lbxStudents->Items->Add(entry->Key + L" " + entry->Value);
	Debug::WriteLine(z->Key);
}
	this->m_gemCutNames = gemCutNames;
}

void CGemCut::setCut(Dictionary<String^, String^>^ arr) {
	this->m_gemCut = arr;

}

String^ CGemCut::getCut(String^ key) {
	return this->m_gemCut[key];

}

array<String^>^ CGemCut::getCutNames() {
	return m_gemCutNames;
}
