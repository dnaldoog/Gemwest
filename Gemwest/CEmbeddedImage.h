#pragma once
using namespace System;
using namespace System::Collections::Generic; // used for Dictionary

ref class CEmbeddedImage
{
private:
	String^ _itemName;
	String^ resxFile = ".Resource";
	Dictionary<String^, String^>^ _rezImages;
	void setRez(Dictionary<String^, String^>^);

public:

	void setName(String^ resourceName);
	void loadResources();
	Drawing::Bitmap^ getName();

};

