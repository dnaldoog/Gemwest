#include "pch.h"
#include "SpecificGravity.h"

void SpecificGravity::dictInitializer() {
	Dictionary<String^, String^>^ sg = gcnew Dictionary<String^, String^>;


	sg->Add("agate", "2.6");
	sg->Add("albite", "2.58");
	sg->Add("actinolite", "3.01");
	sg->Add("alexandrite", "3.71");
	sg->Add("almandine", "4");
	sg->Add("amazonite", "2.56");
	sg->Add("amber", "1.08");
	sg->Add("amethyst", "2.65");
	sg->Add("ammolite", "2.80");
	sg->Add("andalusite", "3.15");
	sg->Add("apatite", "3.2");
	sg->Add("aquamarine", "2.69");
	sg->Add("aragonite", "2.94");
	sg->Add("aventurine quartz", "2.66");
	sg->Add("aventurine", "2.6");
	sg->Add("axinite (ferro-axinite)", "3.31");
	sg->Add("azurite", "3.8");
	sg->Add("bakelite", "1.26");
	sg->Add("benitoite", "3.67");
	sg->Add("beryl aquamarine", "2.69");
	sg->Add("beryl colourless", "2.7");
	sg->Add("beryl heliodor", "2.7");
	sg->Add("beryl morganite", "2.7");
	sg->Add("beryl", "2.7");
	sg->Add("beryl maxixe", "2.7");
	sg->Add("blende", "4.09");
	sg->Add("bloodstone", "2.6");
	sg->Add("blue topaz", "3.53");
	sg->Add("bonamite", "4.35");
	sg->Add("bowenite", "2.59");
	sg->Add("brazilianite", "2.99");
	sg->Add("calcite", "2.71");
	sg->Add("californite", "3.32"); // v2.1.2
	sg->Add("carborundum", "3.17");
	sg->Add("carnelian", "2.64");
	sg->Add("cassiterite", "6.9");
	sg->Add("cat's eye chrysoberyl", "3.71");
	sg->Add("celluloid", "1.38");
	sg->Add("chalcedony agate", "2.6");
	sg->Add("chalcedony aventurine", "2.6");
	sg->Add("chalcedony carnelian", "2.64");
	sg->Add("chalcedony heliotrope", "2.6");
	sg->Add("chalcedony moss agate", "2.6");
	sg->Add("chalcedony onyx", "2.6");
	sg->Add("chalcedony", "2.61");
	sg->Add("chrome diopside", "3.3");
	sg->Add("chrysoberyl alexandrite", "3.71");
	sg->Add("chrysoberyl cat's eye", "3.71");
	sg->Add("chrysoberyl cymophane", "3.71");
	sg->Add("chrysoberyl", "3.71");
	sg->Add("chrysocolla", "2.1");
	sg->Add("chrysoprase", "2.6");
	sg->Add("citrine", "2.65");
	sg->Add("colourless beryl", "2.7");
	sg->Add("conch pearl", "2.84");
	sg->Add("copal resin", "1.06");
	sg->Add("coral", "2.68");
	sg->Add("cornelian", "2.64");
	sg->Add("corundum ruby", "3.99");
	sg->Add("corundum sapphire", "3.99");
	sg->Add("corundum synthetic", "4");
	sg->Add("corundum", "4");
	sg->Add("crocidolite", "2.66");
	sg->Add("cubic zirconia", "5.80");
	sg->Add("cymophane", "3.71");
	sg->Add("cz", "5.80");
	sg->Add("danburite", "3");
	sg->Add("datolite", "2.95");
	sg->Add("demantoid", "3.85");
	sg->Add("diamond", "3.52");
	sg->Add("diopside", "3.29");
	sg->Add("dioptase", "3.31");
	sg->Add("ekanite", "3.28");
	sg->Add("emerald (Gilson)", "2.70");
	sg->Add("emerald", "2.71");
	sg->Add("enstatite", "3.27");
	sg->Add("epidote", "3.4");
	sg->Add("euclase", "3.1");
	sg->Add("fibrolite", "3.25");
	sg->Add("fire opal", "2");
	sg->Add("fluorite", "3.18");
	sg->Add("garnet almandine", "4");
	sg->Add("garnet demantoid", "3.85");
	sg->Add("garnet grossular (pure)", "3.59");
	sg->Add("garnet hessonite", "3.63");
	sg->Add("garnet (mali)", "3.67");
	sg->Add("garnet pyrope", "3.8");
	sg->Add("garnet spessartine", "4.16");
	sg->Add("garnet uvarovite", "3.77");
	sg->Add("garnet", "4.00");
	sg->Add("ggg", "7.05");
	sg->Add("glass", "2.65");
	sg->Add("golden beryl", "2.7");
	sg->Add("goshenite", "2.7");
	sg->Add("grossular garnet", "3.59");
	sg->Add("grossular", "3.59");
	sg->Add("grossular (pure)", "3.59");
	sg->Add("haematite", "5.1");
	sg->Add("hambergite", "2.35");
	sg->Add("heliodor", "2.7");
	sg->Add("hematite", "5.1");
	sg->Add("hemimorphite", "3.52");
	sg->Add("hessonite", "3.63");
	sg->Add("hiddenite", "3.18");
	sg->Add("howlite", "2.56");
	sg->Add("idocrase", "3.4");
	sg->Add("imperial topaz", "3.53");
	sg->Add("iolite", "2.63");
	sg->Add("jadeite", "3.33");
	sg->Add("jasper", "2.55");
	sg->Add("jet", "1.33");
	sg->Add("kornerupine", "3.32");
	sg->Add("kunzite", "3.18");
	sg->Add("kyanite", "3.68");
	sg->Add("lapis lazuli", "2.8");
	sg->Add("larimar", "2.74"); //v2.1.2
	sg->Add("lazulite", "3.1");
	sg->Add("lepidolite", "2.8");
	sg->Add("lithium niobate", "4.64");
	sg->Add("malachite", "3.8");
	sg->Add("malaia garnet", "4.00"); // v 2.1.2
	sg->Add("mali garnet", "3.67");
	sg->Add("marcasite", "4.9");
	sg->Add("maw-sit-sit", "3");
	sg->Add("maxixe", "2.71");
	sg->Add("moissanite", "3.22"); //v 2.1.2
	sg->Add("moldavite", "2.36");
	sg->Add("morganite", "2.71");
	sg->Add("moss agate", "2.6");
	sg->Add("nephrite", "3.00");
	sg->Add("obsidian", "2.5");
	sg->Add("odontolite", "3.0"); //v 2.1.2
	sg->Add("onyx", "2.6");
	sg->Add("opal", "2.15");
	sg->Add("painite", "4.01");
	sg->Add("padparadscha", "4.00");
	sg->Add("paraíba tourmaline", "3.05");
	sg->Add("pearl", "2.71");
	sg->Add("periclase", "3.59");
	sg->Add("peridot", "3.34");
	sg->Add("phenakite", "2.96");
	sg->Add("pink beryl", "2.7");
	sg->Add("pink topaz", "3.53");
	sg->Add("pleonaste", "3.8");
	sg->Add("porcelain", "2.3");
	sg->Add("prehnite", "2.87");
	sg->Add("pseudophite", "2.7");
	sg->Add("pyrites", "5.03"); //v 2.1.2
	sg->Add("pyrope", "3.8");
	sg->Add("quartz amethyst", "2.65");
	sg->Add("quartz aventurine", "2.66");
	sg->Add("quartz chalcedony", "2.61");
	sg->Add("quartz citrine", "2.65");
	sg->Add("quartz rutillated", "2.66"); // Thanks to Stephen Challener
	sg->Add("quartz", "2.65");
	sg->Add("rhodochrosite", "3.6");
	sg->Add("rhodonite", "3.6");
	sg->Add("rubbelite", "3.06");
	sg->Add("ruby", "3.99");
	sg->Add("rutile", "4.25");
	sg->Add("rutillated quartz", "2.66"); // Thanks to Stephen Challener
	sg->Add("sapphire", "3.99");
	sg->Add("sard", "2.61");
	sg->Add("scapolite", "2.7");
	sg->Add("scheelite", "6.1");
	sg->Add("schorl", "3.06");
	sg->Add("serpentine", "2.6");
	sg->Add("seraphinite", "2.8");
	sg->Add("silica glass", "2.21");
	sg->Add("sinhalite", "3.48");
	sg->Add("smithsonite", "4.35");
	sg->Add("spessartine", "4.16");
	sg->Add("sphalerite", "4.09");
	sg->Add("sphene", "3.53");
	sg->Add("spinel synthetic", "3.65");
	sg->Add("spinel", "3.65");
	sg->Add("spodumene", "3.18");
	sg->Add("strontium titanate", "5.13");
	sg->Add("sugilite", "2.74");
	sg->Add("synthetic corundum", "4");
	sg->Add("taaffeite", "3.61");
	sg->Add("tanzanite", "3.35");
	sg->Add("tektite", "2.4");
	sg->Add("tiger eye", "2.8");
	sg->Add("titanite", "3.53");
	sg->Add("topaz", "3.53");
	sg->Add("tortoiseshell", "1.29");
	sg->Add("tourmaline schorl", "3.06");
	sg->Add("tourmaline", "3.06");
	sg->Add("turquoise", "2.8");
	sg->Add("uvarovite", "3.77");
	sg->Add("variscite", "2.55");
	sg->Add("vesuvianite", "3.40");
	sg->Add("vivianite", "2.6");
	sg->Add("water opal", "2");
	sg->Add("yttrium aluminate YAG", "4.55"); // v 2.1.2
	sg->Add("zircon (metamict)", "4");
	sg->Add("zircon (normal)", "4.69");
	sg->Add("zirconia (cubic)", "5.7");
	sg->Add("zoisite", "3.35");
	//for each (KeyValuePair<String^, String^> ^ z in sg){
	//Debug::WriteLine(z->Key+","+z->Value);
	//}
	this->m_sg = sg;
}




