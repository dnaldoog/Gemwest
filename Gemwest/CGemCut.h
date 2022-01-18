#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CGemCut
{
private:
	Dictionary<String^, String^>^ m_gemCut;
	array<String^>^ m_gemCutNames;
	
public:
	void dictInitializer();
	void setCut(Dictionary<String^, String^>^);
	String^ getCut(String^ key);
	array<String^>^ getCutNames();


private:
};
/*https://stackoverflow.com/questions/2364870/is-it-possible-to-create-a-static-dictionary-in-a-c-cli-environment*/
