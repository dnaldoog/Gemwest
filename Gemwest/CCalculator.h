#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

class CCalculator abstract
{
public:
	//virtual Double term() const = 0;
	virtual Double term()  = 0;
	virtual String^ return_recut() = 0;
	//virtual String^ print() {
	//	return System::Convert::ToString(5+"many ct");
	//}
};

