#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CCutDim
{
public:
	static Boolean CCutDim::isRoundish(String^);
	static Boolean CCutDim::lwSymbolIsRound(String^ cutname);
};

