#include "pch.h"
#include "CutDim.h"
bool CutDim::isRoundish(String^ cutname) {
	Dictionary<String^, bool>^ cutDim = gcnew Dictionary<String^, bool>;
	cutDim->Add("briolette", false);
	cutDim->Add("cabochon - regular", false);
	cutDim->Add("cabochon - high domed cabs", false);
	cutDim->Add("cabochon - low domed cabs", false);
	cutDim->Add("emerald cut", false);
	cutDim->Add("heart", false);
	cutDim->Add("long rectangle", false);
	cutDim->Add("marquise", false);
	cutDim->Add("oval cut", false);
	cutDim->Add("pear cut", false);
	cutDim->Add("square cut", true);
	cutDim->Add("square cushion", true);
	cutDim->Add("square step cut", true);
	cutDim->Add("square with cut corners", true);
	cutDim->Add("round cut", true);
	cutDim->Add("round bead", true);
	cutDim->Add("rectangle", false);
	cutDim->Add("rectangle step cut", false);
	cutDim->Add("rectangle with cut corners", false);
	cutDim->Add("rectangular cushion", false);
	cutDim->Add("triangle", false);
	cutDim->Add("asscher", true);
	cutDim->Add("barion", 2);
	cutDim->Add("cushion brilliant", false);
	cutDim->Add("eight cut", true);
	cutDim->Add("emerald cut diamond", false);
	cutDim->Add("heart brilliant", false);
	cutDim->Add("flanders cut (dia.)", true);
	cutDim->Add("old european cut", true);
	cutDim->Add("old mine cut", true);
	cutDim->Add("oval brilliant", false);
	cutDim->Add("marquise brilliant", false);
	cutDim->Add("pear brilliant", false);
	cutDim->Add("princess brilliant", true);
	cutDim->Add("radiant cut (dia.)", false);
	cutDim->Add("round brilliant", true);
	cutDim->Add("rose cut", true);
	cutDim->Add("square cut (dia.)", true);
	cutDim->Add("small baguette", false);
	cutDim->Add("semi circle cut (dia.)", false);
	cutDim->Add("tapered baguette", false);
	cutDim->Add("triangular cut (dia.)", false);
	cutDim->Add("trilliant cut (dia.)", false);
	cutDim->Add("trillion (rounded sides)", false);
	cutDim->Add("choose from below", false);
	return cutDim[cutname]; // static method
}