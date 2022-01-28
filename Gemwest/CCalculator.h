#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class CCalculator abstract
{
public:

	virtual Decimal term()  = 0;
	virtual Decimal recut_weight() = 0;
	static Decimal average_diameter(Decimal length,Decimal width) {

		return Decimal::Divide(Decimal::Add(length,width), 2);

	}
	static Decimal length_width_ratio(Decimal length, Decimal width) {

		return Decimal::Divide(length, width);

	}
	static Decimal depth_percentage_as_percent(Decimal width, Decimal depth) {
		/*for round stones width should be average width:: callDecimal average_Diameter first*/
		return Decimal::Multiply(Decimal::Divide(depth, width),100);

	}
	static Decimal depth_percentage_to_mm(Decimal width, Decimal depthpercent) {

		return Decimal::Multiply(Decimal::Divide(depthpercent, 100), width);
		/*for round stones width should be average width:: callDecimal average_Diameter first*/

	}

};



