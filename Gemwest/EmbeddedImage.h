#pragma once
using namespace System;
ref class EmbeddedImage
{
private:
	String^ itemName;
	String^ resxFile = ".Resource";
public:

	void setName(String^ resourceName);
	Drawing::Bitmap^ getName();

};

