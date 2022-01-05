#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CutDimension
{
private:
	Dictionary<String^,bool>^ _cutDim;
	void CutDimension::init();

	//property bool cutProfile
	//{
	//	String^ get()
	//	{
	//		return _cutDim[cutProfile];
	//	}
	//}
};

