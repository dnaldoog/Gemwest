#include "pch.h"
#include "EmbeddedImage.h"

void EmbeddedImage::setName(String^ resourceName) {
	itemName = resourceName;
	}

Drawing::Bitmap^  EmbeddedImage::getName() {
	Reflection::Assembly^ cutAssembly = Reflection::Assembly::GetExecutingAssembly();
	String^ cutResName = cutAssembly->GetName()->Name + resxFile;
	//Note: add your resourcefile name here, i.e. ".MyResourceFile" as it appears in solution explorer, without its extension
	Resources::ResourceManager^ cut_pxResourceManager = (gcnew Resources::ResourceManager(cutResName, cutAssembly));
	return (cli::safe_cast<Drawing::Bitmap^>(cut_pxResourceManager->GetObject(itemName)));
	}
