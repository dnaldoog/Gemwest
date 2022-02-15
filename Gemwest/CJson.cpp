#include "pch.h"
#include "CJson.h"

Drawing::Bitmap^ CJson::getName() {
	Reflection::Assembly^ cutAssembly = Reflection::Assembly::GetExecutingAssembly();
	String^ cutRezName = cutAssembly->GetName()->Name + resxFile;
	//Note: add your resourcefile name here, i.e. ".MyResourceFile" as it appears in solution explorer, without its extension
	Resources::ResourceManager^ cut_pxResourceManager = (gcnew Resources::ResourceManager(cutRezName, cutAssembly));


	//if (_rezImages->ContainsKey(this->_itemName)) {
	if (cut_pxResourceManager->GetObject(this->Image)) {
		return (cli::safe_cast<Drawing::Bitmap^>(cut_pxResourceManager->GetObject(this->Image)));
	}
	else {
		return (cli::safe_cast<Drawing::Bitmap^>(cut_pxResourceManager->GetObject("noimage")));
	}
}
