#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;


ref class CHelp
{

private:

	//L"Wide corners on cut corner squares and rectangles can decrease weight as much as 5%.\n"
   // "For oval, pear, marquise, and heart cuts, wide wings or high shoulders can add up to 10%. Occasionally, straight shoulders will require a deduction of 1% to 5%.\n"
   // "Marquise and (sometimes) pears will have a very short keel or none at all. This will reduce the weight by 1% to 3%.\n"
   // "Triangles with straight sides will require a reduction of up to 10%.\n";
	String^ m_myGemType;

	String^ m_gem_girdle_general_help =
		L"Thin girdle, subtract 1% to 2%.\n"
		"Normal=0\n"
		"Slightly thick, add 1% to 2%.\n"
		"Thick, add 3% to 4%.\n"
		"Very thick, add 5% to 6%.\n"
		"Extra thick, add 7% to 10%.";

	String^ m_gem_bulge_general_help =
		L"Normal, 0%.\n"
		"Slight, add 3% to 5%.\n"
		"Noticeable, add 6% to 8%.\n"
		"Obvious, add 9% to 12%.\n"
		"Extreme, add 13% to 18%.\n";
	String^ m_gem_shape_general_help =
		L"Wide corners SQ/RECT - 0~-5%.\n"
		"MQ/PE v.short keel/none - 1%~-3%.\n"
		"Straight shoulders - 1~5% .\n"
		"TRI straight sides - ~10%.\n"
		"Normal 0 % .\n"
		"Wide wings OV,PE,MQ,HE + ~10%.\n";

	String^ m_dia_girdle_general_help =
		L"Thin girdle, 0%.\n"
		"Slightly thick, add 2%.\n"
		"Thick, add 4%.\n"
		"Very thick, 6%.\n"
		"Extra thick, add 9%.";
	String^ m_dia_bulge_general_help =
		L"Normal, 0%.\n"
		"Slight, add 3% to 5%.\n"
		"Noticeable, add 6% to 8%.\n"
		"Obvious, add 9% to 12%.\n"
		"Extreme, add 13% to 18%.\n";
	String^ m_dia_shape_general_help =
		L"Wide corners SQ/RECT - 0~5%.\n"
		"MQ/PE v.short keel/none - 1%~3%.\n"
		"Straight shoulders - 1~5% .\n"
		"TRI straight sides - ~10%.\n"
		"Normal 0 % .\n"
		"Wide wings OV,PE,MQ,HE + ~10%.\n";






	array<String^>^ m_gem_girdle_dynamic;
	array<String^>^ m_gem_bulge_dynamic;
	array<String^>^ m_gem_shape_dynamic;

	array<String^>^ m_dia_girdle_dynamic;
	array<String^>^ m_dia_bulge_dynamic;
	array<String^>^ m_dia_shape_dynamic;


public:

	CHelp(String^ myType) :
		m_myGemType(myType) {
		array<String^>^ loadGirdleRangeG = gcnew array<String^>{ "Normal","Thin-Medium","Slightly Thick", "Thick", "Very Thick", "Extreme" };
		m_gem_girdle_dynamic=loadGirdleRangeG;
		array<String^>^ loadBulgeRangeG = gcnew array<String^>{ "Normal", "Slight", "Noticeable", "Obvious", "Extreme" };
		m_gem_bulge_dynamic = loadBulgeRangeG;
		array<String^>^ loadShapeRangeG = gcnew array<String^>{ "Normal","Wide Corners", "MQ/PE v short keel/none", "Straight sides", "Wide wings" };
		m_gem_shape_dynamic = loadShapeRangeG;

		array<String^>^ loadGirdleRangeD = gcnew array<String^>{ "Normal", "Thin-Medium", "Slightly Thick", "Thick", "Very Thick", "Extreme" };
		m_dia_girdle_dynamic = loadGirdleRangeD;
		array<String^>^ loadBulgeRangeD = gcnew array<String^>{ "Normal", "Slight", "Noticeable", "Obvious", "Extreme" };
		m_dia_bulge_dynamic = loadBulgeRangeD;
		array<String^>^ loadShapeRangeD = gcnew array<String^>{ "Normal", "Wide Corners", "MQ/PE v short keel/none", "Straight sides", "Wide wings" };
		m_dia_shape_dynamic = loadShapeRangeD;
	}

	//property  String^ gemgirdle {
	//	 String^ get() {return  m_gem_girdle_general_help; }
	//}
	//property  String^ gembulge {
	//	 String^ get() { return  m_gem_bulge_general_help; }
	//}
	//property  String^ gemshape {
	//	 String^ get() { return  m_gem_shape_general_help; }
	//}
	//property  array<String^>^ gemgirdleTypes {
	//	array<String^>^ get() { return  m_gem_girdle_dynamic; }
	//	void set(array<String^>^ a) { m_gem_girdle_dynamic=a; }
	//}

	property  String^ girdle {
		String^ get() {
			if (m_myGemType == "diamond") {
				return  m_dia_girdle_general_help;
			}
			else {
				return  m_gem_girdle_general_help;
			}
		}
	}
	property  String^ bulge {
		String^ get() {
			if (m_myGemType == "diamond") {
				return  m_dia_bulge_general_help;
			}
			else {
				return  m_gem_bulge_general_help;
			}
		}
	}
	property  String^ shape {
		String^ get() {
			if (m_myGemType == "diamond") {
				return  m_dia_shape_general_help;
			}
			else {
				return m_gem_shape_general_help;
			}
		}
	}
	property  array<String^>^ girdleTypes {
		array<String^>^ get() {
			if (m_myGemType == "diamond") {
				return  m_dia_girdle_dynamic;
			}
			else {
				return  m_gem_girdle_dynamic;
			}
		}
		void set(array<String^>^ a) {
			if (m_myGemType == "diamond") {
				m_dia_girdle_dynamic = a;
			}
			else {
				m_gem_girdle_dynamic = a;
			}
		}
	}
	property  array<String^>^ bulgeTypes {
		array<String^>^ get() {
			if (m_myGemType == "diamond") {
				return  m_dia_bulge_dynamic;
			}
			else {
				return  m_gem_bulge_dynamic;
			}
		}
		void set(array<String^>^ a) {
			if (m_myGemType == "diamond") {
				m_dia_bulge_dynamic = a;
			}
			else {
				m_gem_bulge_dynamic = a;
			}
		}
	}

	property  array<String^>^ shapeTypes {
		array<String^>^ get() {
			if (m_myGemType == "diamond") {
				return  m_dia_shape_dynamic;
			}
			else {
				return  m_gem_shape_dynamic;
			}
		}
		void set(array<String^>^ a) {
			if (m_myGemType == "diamond") {
				m_dia_shape_dynamic = a;
			}
			else {
				m_gem_shape_dynamic = a;
			}
		}
	}
};

