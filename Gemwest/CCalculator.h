#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CCalculator abstract
{
public:
	//virtual Double term() const = 0;
	virtual Double term()  = 0;
	virtual Double recut_weight() = 0;
	//virtual String^ print() {
	//	return System::Convert::ToString(5+"many ct");
	//}
};

