#include "pch.h"
#include "CEmbeddedImage.h"
#include <cstddef>

void CEmbeddedImage::setName(String^ resourceName) {
	_itemName = resourceName;
	this->loadResources();
	}

Drawing::Bitmap^ CEmbeddedImage::getName() {
	Reflection::Assembly^ cutAssembly = Reflection::Assembly::GetExecutingAssembly();
	String^ cutRezName = cutAssembly->GetName()->Name + resxFile;
	//Note: add your resourcefile name here, i.e. ".MyResourceFile" as it appears in solution explorer, without its extension
	Resources::ResourceManager^ cut_pxResourceManager = (gcnew Resources::ResourceManager(cutRezName, cutAssembly));


	if (_rezImages->ContainsKey(this->_itemName)) {
		return (cli::safe_cast<Drawing::Bitmap^>(cut_pxResourceManager->GetObject(this->_rezImages[this->_itemName])));
	}
	else {
		return (cli::safe_cast<Drawing::Bitmap^>(cut_pxResourceManager->GetObject("noimage")));
	}
}
	
void CEmbeddedImage::loadResources()
{
	Dictionary<String^, String^>^ myRez = gcnew Dictionary<String^, String^>;
	myRez->Add(CHOOSE, "");
	myRez->Add("adjustmentarrow", "adjustmentarrow"); // Gui component
	myRez->Add("asscher", "asscher");
	myRez->Add("barion", "barion");
	myRez->Add("briolette", "briolette");
	myRez->Add("bulge_extreme", "bulge_extreme");
	myRez->Add("bulge_normal", "bulge_normal");
	myRez->Add("bulge_noticeable", "bulge_noticeable");
	myRez->Add("bulge_obvious", "bulge_obvious");
	myRez->Add("bulge_slight", "bulge_slight");
	myRez->Add("cabochon - high domed cabs", "cabochon_high_domed");
	myRez->Add("cabochon - low domed cabs", "cabochon_low_domed");
	myRez->Add("cabochon - regular", "cabochon_regular");
	myRez->Add("checkDepth", "checkDepth"); // when depth percentage is strange!
	myRez->Add("checklength", "checkLW"); // when LW percentage is strange!
	myRez->Add("crown_high", "crown_high");
	myRez->Add("crown_low", "crown_low");
	myRez->Add("crown_normal", "crown_normal");
	myRez->Add("cushion brilliant", "cushion_brilliant");
	myRez->Add("deep_stone", "deep_stone"); // Gui recut series
	myRez->Add("defrec", "defrec"); // depth % component
	myRez->Add("diamond", "diamond"); // USED FOR INITIAL LOAD OF PROGRAM
	myRez->Add("eight cut", "eight_cut");
	myRez->Add("emerald cut diamond", "emerald_cut_diamond");
	myRez->Add("emerald cut", "emerald_cut");
	myRez->Add("flanders cut (dia.)", "flanders_cut");
	myRez->Add("gw", "gw"); // icon file
	myRez->Add("heart brilliant", "heart_brilliant");
	myRez->Add("heart", "heart");
	myRez->Add("helpbackdrop", "dia_prop_gauge"); //Shape Outlines
	myRez->Add("logo48", "gemwest_48x48"); // About logo!
	myRez->Add("long rectangle", "long_rectangle");
	myRez->Add("marquise brilliant", "marquise_brilliant");
	myRez->Add("marquise", "marquise");
	myRez->Add("mediumgirdle", "mediumgirdle");
	myRez->Add("old european cut", "old_european_cut");
	myRez->Add("old mine cut", "old_mine_cut");
	myRez->Add("oval brilliant", "oval_brilliant");
	myRez->Add("oval cut", "oval");
	myRez->Add("paypallogo", "pp"); //PayPal
	myRez->Add("pear brilliant", "pear_brilliant");
	myRez->Add("pear cut", "pear_cut");
	myRez->Add("princess brilliant", "princess_cut");
	myRez->Add("radiant cut (dia.)", "radiant_cut");
	myRez->Add("rectangle step cut", "rectangle_step_cut");
	myRez->Add("rectangle with cut corners", "rectangle_with_cut_corners");
	myRez->Add("rectangle", "rectangle");
	myRez->Add("rectangular cushion", "rectangular_cushion");
	myRez->Add("rectshape", "rect_shape_ouline"); //Shape Outlines
	myRez->Add("recut", "recut"); // Gui recut series
	myRez->Add("rose cut", "rose_cut");
	myRez->Add("round bead", "round_bead");
	myRez->Add("round brilliant", "round_brilliant");
	myRez->Add("round cut", "round_cut");
	myRez->Add("semi circle cut (dia.)", "semi_circle_cut");
	myRez->Add("shallow", "shallow"); // Gui recut series
	myRez->Add("small baguette", "small_baguette");
	myRez->Add("so1", "so_low_very"); //Shape Outlines
	myRez->Add("so2", "so_low_01"); //Shape Outlines
	myRez->Add("so3", "so_ok"); //Shape Outlines
	myRez->Add("so4", "so_high_01"); //Shape Outlines
	myRez->Add("so5", "so_high_02"); //Shape Outlines
	myRez->Add("so6", "so_high_03"); //Shape Outlines
	myRez->Add("square cushion", "square_cushion");
	myRez->Add("square cut (dia.)", "square_cut_diamond");
	myRez->Add("square cut", "square_cut");
	myRez->Add("square step cut", "square_step_cut");
	myRez->Add("square with cut corners", "square_with_cut_corners");
	myRez->Add("sthickgirdle", "sthickgirdle"); // girdle thickness images
	myRez->Add("stonedepthokay", "stonedepthokay"); // Gui recut series
	myRez->Add("tapered baguette", "tapered_baguette");
	myRez->Add("thickgirdle", "thickgirdle");
	myRez->Add("thingirdle", "thingirdle");
	myRez->Add("triangle", "triangle");
	myRez->Add("triangleshape", "triangle_shape_ouline"); //Shape Outlines
	myRez->Add("triangular cut (dia.)", "triangular_cut");
	myRez->Add("trilliant cut (dia.)", "trilliant_cut");
	myRez->Add("trillion (rounded sides)", "trillion");
	myRez->Add("vthickgirdle", "vthickgirdle");// girdle thickness images
	myRez->Add("zaniah", "zaniah"); // Author's logo!
	this->setRez(myRez);
}

void CEmbeddedImage::setRez(Dictionary<String^, String^>^ arr) {
	this->_rezImages = arr;
};


/*https://stackoverflow.com/questions/2364870/is-it-possible-to-create-a-static-dictionary-in-a-c-cli-environment*/