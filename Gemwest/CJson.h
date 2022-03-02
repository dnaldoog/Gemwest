#pragma once
//#include <string>
//#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace Newtonsoft::Json;
using namespace Newtonsoft::Json::Linq;

ref class CJson
{
private:
	Decimal m_sg;
	String^ m_min;
	String^ m_max;
	String^ m_image;
	String^ resxFile = ".Resource";
public:
	property Decimal Sg {
		Decimal get() {
			return m_sg;
		}
		void set(Decimal s) {
			m_sg = s;
		}
	}
	property String^ Min {
		String^ get() {
			return m_min;
		}
		void set(String^ s) {
			m_min = s;
		}
	}
	property String^ Max {
		String^ get() {
			return m_max;
		}
		void set(String^ s) {
			m_max = s;
		}
	}
	property String^ Image {
		String^ get() {
			return m_image;
		}
		void set(String^ s) {
			m_image = s;
		}
	}

	CJson(String^ queryraw) { // Constructor
		String^ json = "gemreference.json";

	/*	UTF8Encoding^ utf8 = gcnew UTF8Encoding();
		array<Byte>^ encodedBytes = gcnew array<Byte>{};
		
		encodedBytes=utf8->GetBytes(queryraw);
		String^ query = utf8->GetString(encodedBytes);
		Debug::WriteLine(query);*/

		try {
			JObject^ o = JObject::Parse(File::ReadAllText(json));
			String^ tmpEscaped = CJson::AddSlashes(queryraw);
			//Debug::WriteLine("query = {0}", tmpEscaped);
		/*	std::basic_string tmpEscaped = msclr::interop::marshal_as<std::basic_string>(managed);*/
			//static_cast<UTF8Encoding>(tmpEscaped);
			this->Sg = Convert::ToDecimal(o->SelectToken("['" + tmpEscaped + "']" + ".DefaultSg"));
			this->Min = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".MinSg"));
			this->Max = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".MaxSg"));
			this->Image = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".ImageRef"));

			//Debug::WriteLine("sg ", this->Sg);
			//Debug::WriteLine("count is ", Convert::ToString(o->Count));
		}
		catch (Exception^ e)
		{
			Debug::WriteLine("JSON ERROR\n"+e->Message);
			this->Sg = (Decimal)0.00;
			this->Min = "0.00";
			this->Max = "0.00";
			this->Image = "no image";
		}
		//finally
		//{
		//	this->Sg = (Decimal)0.00;
		//	this->Min = "0.00";
		//	this->Max = "0.00";
		//	this->Image = "no image";
		//}
	}

	Drawing::Bitmap^ getName();
	/// <summary>
/// Quote string with slashes
/// </summary>
/// <param name="InputTxt">Text string need to be escape with slashes</param>
	static System::String^ AddSlashes(System::String^ InputTxt)
	{
		// List of characters handled:
		// \000 null
		// \010 backspace
		// \011 horizontal tab
		// \012 new line
		// \015 carriage return
		// \032 substitute
		// \042 double quote
		// \047 single quote
		// \134 backslash
		// \140 grave accent

		System::String^ Result = InputTxt;

		try
		{
			//Result = System::Text::UTF8Encoding::Convert(InputTxt);
			//Result = System::Text::RegularExpressions::Regex::Replace(InputTxt, "[\\000\\010\\011\\012\\015\\032\\042\\047\\134\\140]", "\\$0");
			Result = System::Text::RegularExpressions::Regex::Replace(InputTxt, "[\\047]", "\\$0");
			
		}
		catch (Exception^ Ex)
		{
			// handle any exception here
			Console::WriteLine(Ex->Message);
		}

		return Result;
	}

};

