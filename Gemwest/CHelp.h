#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;


ref class CHelp
{

private:
	String^ m_girdle_general_help =
		L"Thin girdle, subtract 1% to 2%.\n"
		"Slightly thick, add 1% to 2%.\n"
		"Thick, add 3% to 4%.\n"
		"Very thick, add 5% to 6%.\n"
		"Extra thick, add 7% to 10%.";
	String^ m_bulge_general_help =
		L"Slight, add 3% to 5%.\n"
		"Noticeable, add 6% to 8%.\n"
		"Obvious, add 9% to 12%.\n"
		"Extreme, add 13% to 18%.\n";
	String^ m_shape_general_help =
		L"Wide corners SQ/RECT - 0~5%.\n"
		"Wide wings OV,PE,MQ,HE + ~10%.\n"
		"Straight shoulders - 1~5% .\n"
		"MQ/PE v.short keel/none - 1%~3%.\n"
		"TRI straight sides - ~10%.\n";

	//L"Wide corners on cut corner squares and rectangles can decrease weight as much as 5%.\n"
	   // "For oval, pear, marquise, and heart cuts, wide wings or high shoulders can add up to 10%. Occasionally, straight shoulders will require a deduction of 1% to 5%.\n"
	   // "Marquise and (sometimes) pears will have a very short keel or none at all. This will reduce the weight by 1% to 3%.\n"
	   // "Triangles with straight sides will require a reduction of up to 10%.\n";

	array<String^>^ m_girdle_dynamic;


public:

	CHelp() {
		array<String^>^ loadGirdleRange = gcnew array<String^>{ "Thin-Medium","Slightly Thick", "Thick", "Very Thick", "Extreme" };
		m_girdle_dynamic=loadGirdleRange;
	}

	property  String^ girdle {
		 String^ get() {return  m_girdle_general_help; }
	}
	property  String^ bulge {
		 String^ get() { return  m_bulge_general_help; }
	}
	property  String^ shape {
		 String^ get() { return  m_shape_general_help; }
	}
	property  array<String^>^ girdleTypes {
		array<String^>^ get() { return  m_girdle_dynamic; }
		void set(array<String^>^ a) { m_girdle_dynamic=a; }
	}


};

