#include "pch.h"
#include "CCutDim.h"
Boolean CCutDim::isRoundish(String^ cutname) {
	Dictionary<String^, Boolean>^ CCutDim = gcnew Dictionary<String^, Boolean>;
	CCutDim->Add("briolette", false);
	CCutDim->Add("cabochon - regular", false);
	CCutDim->Add("cabochon - high domed cabs", false);
	CCutDim->Add("cabochon - low domed cabs", false);
	CCutDim->Add("emerald cut", false);
	CCutDim->Add("heart", false);
	CCutDim->Add("long rectangle", false);
	CCutDim->Add("marquise", false);
	CCutDim->Add("oval cut", false);
	CCutDim->Add("pear cut", false);
	CCutDim->Add("square cut", true);
	CCutDim->Add("square cushion", true);
	CCutDim->Add("square step cut", true);
	CCutDim->Add("square with cut corners", true);
	CCutDim->Add("round cut", true);
	CCutDim->Add("round bead", true);
	CCutDim->Add("rectangle", false);
	CCutDim->Add("rectangle step cut", false);
	CCutDim->Add("rectangle with cut corners", false);
	CCutDim->Add("rectangular cushion", false);
	CCutDim->Add("triangle", false);
	CCutDim->Add("asscher", true);
	CCutDim->Add("barion", true);
	CCutDim->Add("cushion brilliant", false);
	CCutDim->Add("eight cut", true);
	CCutDim->Add("emerald cut diamond", false);
	CCutDim->Add("heart brilliant", false);
	CCutDim->Add("flanders cut (dia.)", true);
	CCutDim->Add("old european cut", true);
	CCutDim->Add("old mine cut", true);
	CCutDim->Add("oval brilliant", false);
	CCutDim->Add("marquise brilliant", false);
	CCutDim->Add("pear brilliant", false);
	CCutDim->Add("princess brilliant", true);
	CCutDim->Add("radiant cut (dia.)", false);
	CCutDim->Add("round brilliant", true);
	CCutDim->Add("rose cut", true);
	CCutDim->Add("square cut (dia.)", true);
	CCutDim->Add("small baguette", false);
	CCutDim->Add("semi circle cut (dia.)", false);
	CCutDim->Add("tapered baguette", false);
	CCutDim->Add("triangular cut (dia.)", false);
	CCutDim->Add("trilliant cut (dia.)", false);
	CCutDim->Add("trillion (rounded sides)", false);
	CCutDim->Add("choose from below", false);
	return CCutDim[cutname]; // static method
}