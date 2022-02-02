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
	myRez->Add("agate", "agate");
	myRez->Add("actinolite", "actinolite");
	myRez->Add("albite", "albite");
	myRez->Add("alexandrite", "alexandrite");
	myRez->Add("almandine", "almandine");
	myRez->Add("amazonite", "amazonite");
	myRez->Add("amber", "amber");
	myRez->Add("amethyst", "amethyst");
	myRez->Add("ammolite", "ammolite");
	myRez->Add("andalusite", "andalusite");
	myRez->Add("apatite", "apatite");
	myRez->Add("aquamarine", "aquamarine");
	myRez->Add("aragonite", "aragonite");
	myRez->Add("asscher", "asscher");
	myRez->Add("aventurine", "aventurine");
	myRez->Add("aventurine quartz", "aventurine quartz");
	myRez->Add("axinite (ferro-axinite)", "axinite (ferro-axinite)");
	myRez->Add("azurite", "azurite");
	myRez->Add("bakelite", "bakelite");
	myRez->Add("barion", "barion");
	myRez->Add("benitoite", "benitoite");
	myRez->Add("beryl", "beryl");
	myRez->Add("beryl aquamarine", "beryl aquamarine");
	myRez->Add("beryl colourless", "beryl colourless");
	myRez->Add("beryl heliodor", "beryl heliodor");
	myRez->Add("beryl maxixe", "beryl maxixe");
	myRez->Add("beryl morganite", "beryl morganite");
	myRez->Add("biron created emerald","biron created emerald");	//no entry
	myRez->Add("blende", "blende");
	myRez->Add("bloodstone", "bloodstone");
	myRez->Add("blue topaz", "blue topaz");
	myRez->Add("bonamite", "bonamite");
	myRez->Add("bowenite", "bowenite");
	myRez->Add("brazilianite", "brazilianite");
	myRez->Add("briolette", "briolette");
	myRez->Add("bulge_normal", "bulge_normal");	//bulge
	myRez->Add("bulge_slight", "bulge_slight");	//bulge
	myRez->Add("bulge_noticeable", "bulge_noticeable");	//bulge
	myRez->Add("bulge_obvious", "bulge_obvious");	//bulge
	myRez->Add("bulge_extreme", "bulge_extreme");	//bulge
	myRez->Add("crown_normal", "crown_normal");	//crown
	myRez->Add("crown_low", "crown_low");	//crown
	myRez->Add("crown_high", "crown_high");	//crown
	myRez->Add("cabochon - high domed cabs", "cabochon_high_domed");	//gem cut
	myRez->Add("cabochon - low domed cabs", "cabochon_low_domed");	//gem cut
	myRez->Add("cabochon - regular", "cabochon_regular");	//gem cut
	myRez->Add("calcite", "calcite");
	myRez->Add("californite", "californite");
	myRez->Add("carborundum", "carborundum");
	myRez->Add("carnelian", "carnelian");
	myRez->Add("cassiterite", "cassiterite");
	myRez->Add("cat's eye chrysoberyl", "cat's eye chrysoberyl");
	myRez->Add("celluloid", "celluloid");
	myRez->Add("chalcedony", "chalcedony");
	myRez->Add("chalcedony agate", "chalcedony agate");
	myRez->Add("chalcedony aventurine", "chalcedony aventurine");
	myRez->Add("chalcedony carnelian", "chalcedony carnelian");
	myRez->Add("chalcedony heliotrope", "chalcedony heliotrope");
	myRez->Add("chalcedony moss agate", "chalcedony moss agate");
	myRez->Add("chalcedony onyx", "chalcedony onyx");
	myRez->Add("chrome diopside", "chrome diopside");
	myRez->Add("chrysoberyl", "chrysoberyl");
	myRez->Add("chrysoberyl alexandrite", "chrysoberyl alexandrite");
	myRez->Add("chrysoberyl cat's eye", "chrysoberyl cat's eye");
	myRez->Add("chrysoberyl cymophane", "chrysoberyl cymophane");
	myRez->Add("chrysocolla", "chrysocolla");
	myRez->Add("chrysoprase", "chrysoprase");
	myRez->Add("citrine", "citrine");
	myRez->Add("colourless beryl", "beryl colourless");
	myRez->Add("conch pearl", "conch pearl");
	myRez->Add("copal resin", "copal resin");
	myRez->Add("coral", "coral");
	myRez->Add("cornelian", "cornelian");
	myRez->Add("corundum", "corundum");
	myRez->Add("corundum ruby", "corundum ruby");
	myRez->Add("corundum sapphire", "corundum sapphire");
	myRez->Add("corundum synthetic", "corundum synthetic");
	myRez->Add("crocidolite", "crocidolite");
	myRez->Add("cubic zirconia", "cubic zirconia");
	myRez->Add("cushion brilliant", "cushion_brilliant");
	myRez->Add("cymophane", "cymophane");
	myRez->Add("cz", "cz");
	myRez->Add("danburite", "danburite");
	myRez->Add("datolite", "datolite");
	myRez->Add("demantoid", "demantoid");
	myRez->Add("diamond", "diamond");
	myRez->Add("diopside", "diopside");
	myRez->Add("eight cut", "eight_cut");
	myRez->Add("ekanite", "ekanite");
	myRez->Add("emerald", "emerald");
	myRez->Add("emerald (Biron)","biron created emerald");	// emerald (Biron)
	myRez->Add("emerald (Chatham)","");	// emerald (Biron)
	myRez->Add("emerald (Gilson)", "emerald (Gilson)");
	myRez->Add("emerald cut", "emerald_cut");	// gem
	myRez->Add("emerald cut diamond", "emerald_cut_diamond");
	myRez->Add("enstatite", "enstatite");
	myRez->Add("epidote", "epidote");
	myRez->Add("euclase", "euclase");
	myRez->Add("fibrolite", "fibrolite");
	myRez->Add("fire opal", "fire opal");
	myRez->Add("flanders cut (dia.)", "flanders_cut");
	myRez->Add("fluorite", "fluorite");
	myRez->Add("garnet", "garnet");
	myRez->Add("garnet (mali)", "garnet mali");
	myRez->Add("garnet almandine", "garnet almandine");
	myRez->Add("garnet demantoid", "garnet demantoid");
	myRez->Add("garnet grossular (pure)", "grossular garnet");
	myRez->Add("garnet hessonite", "garnet hessonite");
	myRez->Add("garnet pyrope", "garnet pyrope");
	myRez->Add("garnet spessartine", "garnet spessartine");
	myRez->Add("garnet uvarovite", "garnet uvarovite");
	myRez->Add("ggg", "ggg");
	myRez->Add("glass", "glass");
	myRez->Add("golden beryl", "golden beryl");
	myRez->Add("goshenite", "goshenite");
	myRez->Add("grossular", "grossular");
	myRez->Add("grossular (pure)", "grossular garnet");
	myRez->Add("grossular garnet", "grossular garnet");
	myRez->Add("haematite", "haematite");
	myRez->Add("hambergite", "hambergite");
	myRez->Add("heart", "heart");
	myRez->Add("heart brilliant", "heart_brilliant");
	myRez->Add("heliodor", "heliodor");
	myRez->Add("heliotrope","heliotrope");	// heliotrope
	myRez->Add("hematite", "hematite");
	myRez->Add("hemimorphite", "hemimorphite");
	myRez->Add("hessonite", "hessonite");
	myRez->Add("hiddenite", "hiddenite");
	myRez->Add("howlite", "howlite");
	myRez->Add("idocrase", "idocrase");
	myRez->Add("imperial topaz", "imperial topaz");
	myRez->Add("iolite", "iolite");
	myRez->Add("jadeite", "jadeite");	// jade
	myRez->Add("jade","jadeite");	// jade
	myRez->Add("jasper", "jasper");
	myRez->Add("jet", "jet");
	myRez->Add("kornerupine", "kornerupine");
	myRez->Add("kunzite", "kunzite");
	myRez->Add("kyanite", "kyanite");
	myRez->Add("lapis lazuli", "lapis lazuli");
	myRez->Add("larimar", "larimar");
	myRez->Add("lazulite", "lazurite");
	myRez->Add("lepidolite", "lepidolite");
	myRez->Add("lithium niobate", "lithium niobate");
	myRez->Add("long rectangle", "long_rectangle");
	myRez->Add("malachite", "malachite");
	myRez->Add("malaia garnet", "malaia_garnet");
	myRez->Add("mali garnet", "mali garnet");
	myRez->Add("marcasite", "marcasite");
	myRez->Add("marquise", "marquise");
	myRez->Add("marquise brilliant", "marquise_brilliant");
	myRez->Add("maw-sit-sit", "maw-sit-sit");
	myRez->Add("maxixe", "maxixe");
	myRez->Add("mediumgirdle", "mediumgirdle");
	myRez->Add("moissanite", "moissanite");
	myRez->Add("moldavite", "molldavite");
	myRez->Add("morganite", "morganite");
	myRez->Add("moss agate", "moss agate");
	myRez->Add("nephrite", "nephrite");
	myRez->Add("obsidian", "obsidian");
	myRez->Add("odontolite", "odontolite");
	myRez->Add("old european cut", "old_european_cut");
	myRez->Add("old mine cut", "old_mine_cut");
	myRez->Add("onyx", "onyx");
	myRez->Add("opal", "opal");
	myRez->Add("oval brilliant", "oval_brilliant");
	myRez->Add("oval cut", "oval");
	myRez->Add("painite", "painite");
	myRez->Add("padparadscha", "padparadscha");
	myRez->Add("paraíba tourmaline", "paraiba");
	myRez->Add("pear brilliant", "pear_brilliant");
	myRez->Add("pear cut", "pear_cut");
	myRez->Add("pearl", "pearl");
	myRez->Add("periclase", "periclase");
	myRez->Add("peridot", "peridot");
	myRez->Add("phenakite", "phenakite");
	myRez->Add("pink beryl", "pink beryl");
	myRez->Add("pink topaz", "pink topaz");
	myRez->Add("pleonaste", "pleonaste");
	myRez->Add("porcelain", "porcelain");
	myRez->Add("prehnite", "prehnite");
	myRez->Add("princess brilliant", "princess_cut");
	myRez->Add("pseudophite", "pseudophite");
	myRez->Add("pyrites", "pyrites");
	myRez->Add("pyrope", "pyrope");
	myRez->Add("quartz", "quartz");
	myRez->Add("quartz amethyst", "quartz amethyst");
	myRez->Add("quartz aventurine", "quartz aventurine");
	myRez->Add("quartz chalcedony", "quartz chalcedony");
	myRez->Add("quartz citrine", "quartz citrine");
	myRez->Add("quartz rutillated", "rutillatedquartz");
	myRez->Add("radiant cut (dia.)", "radiant_cut");
	myRez->Add("rectangle", "rectangle");
	myRez->Add("rectangle step cut", "rectangle_step_cut");
	myRez->Add("rectangle with cut corners", "rectangle_with_cut_corners");
	myRez->Add("rectangular cushion", "rectangular_cushion");
	myRez->Add("rhodochrosite", "rhodochrosite");
	myRez->Add("rhodonite", "rhodonite");
	myRez->Add("rose cut", "rose_cut");
	myRez->Add("round bead", "round_bead");
	myRez->Add("round brilliant", "round_brilliant");
	myRez->Add("round cut", "round_cut");
	myRez->Add("rubbelite", "rubellite");
	myRez->Add("ruby", "ruby");
	myRez->Add("rutile", "rutile");
	myRez->Add("rutillated quartz", "rutillatedquartz");
	myRez->Add("sapphire", "sapphire");
	myRez->Add("sard", "sard");
	myRez->Add("scapolite", "scapolite");
	myRez->Add("scheelite", "scheelite");
	myRez->Add("schorl", "schorl");
	myRez->Add("semi circle cut (dia.)", "semi_circle_cut");
	myRez->Add("seraphinite", "seraphinite");
	myRez->Add("serpentine", "serpentine");
	myRez->Add("silica glass", "silica glass");
	myRez->Add("sinhalite", "sinhalite");
	myRez->Add("small baguette", "small_baguette");
	myRez->Add("smithsonite", "smithsonite");
	myRez->Add("spessartine", "spessartine");
	myRez->Add("sphalerite", "sphalerite");
	myRez->Add("sphene", "sphene");
	myRez->Add("spinel", "spinel");
	myRez->Add("spinel synthetic", "spinel synthetic");
	myRez->Add("spodumene", "spodumene");
	myRez->Add("square cushion", "square_cushion");
	myRez->Add("square cut", "square_cut");
	myRez->Add("square cut (dia.)", "square_cut_diamond");
	myRez->Add("square step cut", "square_step_cut");
	myRez->Add("square with cut corners", "square_with_cut_corners");
	myRez->Add("strontium titanate", "strontium titanate");
	myRez->Add("sugilite", "sugilite");
	myRez->Add("synthetic corundum", "synthetic corundum");
	myRez->Add("taaffeite", "taaffeite");
	myRez->Add("synthetic spinel","spinel synthetic");	// synthetic spinel
	myRez->Add("tanzanite","tanzanite");	//tanzanite
	myRez->Add("vesuvianite","vesuvianite");	// vesuvianite
	myRez->Add("tapered baguette", "tapered_baguette");
	myRez->Add("tektite", "tektite");
	myRez->Add("sthickgirdle", "sthickgirdle"); // girdle thickness images
	myRez->Add("vthickgirdle", "vthickgirdle");// girdle thickness images
	myRez->Add("thickgirdle","thickgirdle");	// girdle thickness images
	myRez->Add("thingirdle","thingirdle");	// girdle thickness images
	myRez->Add("titanite","sphene");	
	myRez->Add("tiger eye","tigerseye");	
	myRez->Add("topaz", "topaz");
	myRez->Add("tortoiseshell", "tortoiseshell");
	myRez->Add("tourmaline", "tourmaline");
	myRez->Add("tourmaline schorl", "tourmaline schorl");
	myRez->Add("triangle", "triangle");
	myRez->Add("triangular cut (dia.)", "triangular_cut");
	myRez->Add("trilliant cut (dia.)", "trilliant_cut");
	myRez->Add("trillion (rounded sides)", "trillion");
	myRez->Add("turquoise", "turquoise");
	myRez->Add("uvarovite", "uvarovite");
	myRez->Add("variscite", "variscite");
	myRez->Add("vivianite", "vivianite");
	myRez->Add("water opal", "water opal");
	myRez->Add("yttrium aluminate YAG", "yttrium aluminate YAG");
	myRez->Add("zircon (metamict)", "zircon (metamict)");
	myRez->Add("zircon (normal)", "zircon (normal)");
	myRez->Add("zirconia (cubic)", "zirconia (cubic)");
	myRez->Add("zoisite", "zoisite");
	myRez->Add("gw", "gw"); // icon file
	myRez->Add("checkDepth", "checkDepth"); // when depth percentage is strange!
	myRez->Add("checklength", "checkLW"); // when LW percentage is strange!
	myRez->Add("zaniah", "zaniah"); // Author's logo!
	myRez->Add("logo48", "gemwest_48x48"); // About logo!
	myRez->Add("adjustmentarrow", "adjustmentarrow"); // Gui component
	myRez->Add("defrec", "defrec"); // depth % component
	myRez->Add("recut", "recut"); // Gui recut series
	myRez->Add("shallow", "shallow"); // Gui recut series
	myRez->Add("deep_stone", "deep_stone"); // Gui recut series
	myRez->Add("stonedepthokay", "stonedepthokay"); // Gui recut series
	myRez->Add("so1", "so_low_very"); //Shape Outlines
	myRez->Add("so2", "so_low_01"); //Shape Outlines
	myRez->Add("so3", "so_ok"); //Shape Outlines
	myRez->Add("so4", "so_high_01"); //Shape Outlines
	myRez->Add("so5", "so_high_02"); //Shape Outlines
	myRez->Add("so6", "so_high_03"); //Shape Outlines
	myRez->Add("triangleshape", "triangle_shape_ouline"); //Shape Outlines
	myRez->Add("rectshape", "rect_shape_ouline"); //Shape Outlines
	myRez->Add("helpbackdrop", "dia_prop_gauge"); //Shape Outlines
	myRez->Add("paypallogo", "pp"); //PayPal
	this->setRez(myRez);

}

void CEmbeddedImage::setRez(Dictionary<String^, String^>^ arr) {
	this->_rezImages = arr;
};
