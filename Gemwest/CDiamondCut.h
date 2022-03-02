#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CDiamondCut
{
private:
	Dictionary<String^, Double>^ m_diaCut;
	array<String^>^ m_diaCutNames;
	void setCut(Dictionary<String^, Double>^);
public:
	void dictInitializer();

	Decimal getCutFactor(String^ key);
	array<String^>^ getCutNames();

private:
};
/*https://stackoverflow.com/questions/2364870/is-it-possible-to-create-a-static-dictionary-in-a-c-cli-environment*/


		

