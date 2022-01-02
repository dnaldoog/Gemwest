#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class DiamondCut
{
private:
	Dictionary<String^, String^>^ _diaCut;
	array<String^>^ _diaCutNames;
public:
	void dictInitializer();
	void setCut(Dictionary<String^, String^>^);
	String^ getCut(String^ key);
	array<String^>^ getCutNames();

private:
};
/*https://stackoverflow.com/questions/2364870/is-it-possible-to-create-a-static-dictionary-in-a-c-cli-environment*/


		

