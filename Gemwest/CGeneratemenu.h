#pragma once
#include "CJson.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace Newtonsoft::Json;
using namespace Newtonsoft::Json::Linq;

ref class CGenerateMenu
{
public:

	String^ DefaultSg;
	String^ MinSg;
	String^ MaxSg;
	String^ ImageRef;


	static void listAllNames() {

		String^ json = "gemreference.json";


		//Dictionary<String^, Object^>^ o = JsonConvert::DeserializeObject<Dictionary<String^, Object^>^>(json);
		//CGenerateMenu o = gcnew JsonConvert::DeserializeObject<CGenerateMenu>(json);
			//JObject^ o = JObject::Parse(File::ReadAllText(json));

				//for each (String^ Key in o->Keys){
				//for each (KeyValuePair<String^, Object^> ^ z in o){
	//Debug::WriteLine(o[Key]);
}
			//{
				//var jo = JObject.Parse(JSON);
				//var data = (JObject)jo["response"]["user"]["data"];
	/*			for each(JObject^  item in o)
				{
					Console::WriteLine("{0}: {1}", item->Key, item->Value);
				}*/
			//}
	//}
			//while (!o->Last) {
			//for(int i=0; i< 100; ++i){
			//for each(String^ item in o->Type<JProperty>()){
				//String^ tmpEscaped = CJson::AddSlashes(o["tr"]);
				//Debug::WriteLine(">" + tmpEscaped);
			//}

	/*		this->Sg = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".DefaultSg"));
			this->Min = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".MinSg"));
			this->Max = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".MaxSg"));
			this->Image = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".ImageRef"));*/

			//Debug::WriteLine("count is ", Convert::ToString(o->Count));
		


	//}
	//void listAllNames();
	//static void listAllNames() {
	//	String^ json = "gemreference.json";
	//	//public T GetFirstInstance<T>(string propertyName, string json)
	//	// var orderWrapper = JsonConvert.DeserializeObject<OrderWrapper>(json);
	//	JObject^ jResponse = JObject::Parse(File::ReadAllText(json));
	//	//var jResponse = Newtonsoft.Json.Linq.JObject.Parse(rResponse.Content);
	//	//var jOrders = jResponse["orders"];
	//	for each (String ^ jChild in jResponse) {
	//		//string sOrderGUID = ""; //The name/key of the object
	//		String^ jOrder = jChild->ToString();
	//		Debug::WriteLine(jOrder);
	//		//Handle the order data, etc
	//	}

	//}
};
		//IEnumerable<Order> orders = result.GetOrders();

		//public class OrderWrapper
		//{
		//	[JsonProperty("orders")]
		//	private Dictionary<string, Order> _orders;

		//	public IEnumerable<Order> GetOrders()
		//	{
		//		return _orders.Values;
		//	}
		//}
	//	//{
	//	StringReader^ stringReader = gcnew StringReader(json);
	//	JsonTextReader^ jsonReader = gcnew JsonTextReader(stringReader);
	//	//{
	//	int level = 0;

	//	//while (jsonReader->Read()) {
	//	while (level < 100) {
	//		Debug::WriteLine(level + "> " + (jsonReader->Value->ToString()));
	//		if (Convert::ToString(jsonReader->Value) == Convert::ToString(JsonToken::PropertyName)) {
	//			Debug::WriteLine(level + "> " + (String^)jsonReader->Value);
	//			//return } jsonReader.Skip(); }
	//			
	//		}
	//		++level;
	//	}
	//}
//};



	
//	static void listAllNames_() {
//
//
//		//CJson^ dataset = gcnew CJson;
//		String^ json = "gemreference.json";
//		//Temp dataSet = JsonConvert::DeserializeObject<Temp>(json);
//		// read file into a string and deserialize JSON to a type
//		//CGenerateMenu movie1 = JsonConvert::DeserializeObject<CGenerateMenu>(File::ReadAllText(json));
//		//CGenerateMenu^ data = JsonConvert::DeserializeObject<CGenerateMenu^>(json);
//		//List<String^>^ data = JsonConvert::DeserializeObject<List<String^>^>(json);
//		//CGenerateMenu^ data = JsonConvert::DeserializeObject<CGenerateMenu^>(json);
//		//Dictionary<String^,String^>^ dict = JsonConvert::DeserializeObject<Dictionary<String^, String^>^>(json);
//		JObject^ dict = JObject::Parse(File::ReadAllText(json));
//		for (int i = 0; i < 100; ++i)
//		{
//			//Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".DefaultSg"));
//			Debug::WriteLine(L"["+i+ "] parent = "+Convert::ToString(dict->SelectToken(dict->Parent));
//		}
//		/*	for each (KeyValuePair<String^, String^> ^ z in dict) {
//				Debug::WriteLine(z->Key);
//			}*/
//			//Console::WriteLine("ID: {0}\nNodes: {1}", data->MinSg, String::Join(",", System::Linq::Enumerable::Cast<Object^>(data->Nodes)));
//
//			// deserialize JSON directly from a file
//			//StreamReader^ file = gcnew StreamReader(System::File::OpenText(json))
//			//{
//			//	JsonSerializer serializer = new JsonSerializer();
//			//	Movie movie2 = (Movie)serializer::Deserialize(file, typeof(Movie));
//			//}
//			//JObject^ o = JObject::Parse(File::ReadAllText(json));
//			//for (int i = 0; i < data->Count; i++)
//			//{
//			//{
//			//Console::WriteLine(data[i]);
//			//}
//		//}
//	}
//
//};
/*
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
ref class Temp {

	String^ mname;
public:
	array<String^>^ z = gcnew array<String^>{};
	String^ m_sg;
	String^ m_min;
	String^ m_max;
	String^ m_image;
	property String^ n {
		String^ get() {
			return mname;
		}
		void set(String^ s) {
			mname = s;
		}
	}
	}
};
ref class CJson
{
public:
	String^ m_sg;
	String^ m_min;
	String^ m_max;
	String^ m_image;
	String^ resxFile = ".Resource";

public:
	property String^ Sg {
		String^ get() {
			return m_sg;
		}
		void set(String^ s) {
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

		try {
			JObject^ o = JObject::Parse(File::ReadAllText(json));
			String^ tmpEscaped = CJson::AddSlashes(queryraw);

			this->Sg = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".DefaultSg"));
			this->Min = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".MinSg"));
			this->Max = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".MaxSg"));
			this->Image = Convert::ToString(o->SelectToken("['" + tmpEscaped + "']" + ".ImageRef"));

			//Debug::WriteLine("count is ", Convert::ToString(o->Count));
		}
		catch (Exception^ e)
		{
			this->Sg = "0.00";
			this->Min = "0.00";
			this->Max = "0.00";
			this->Image = "no image";
		}
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
			//Console::WriteLine(Ex->Message);
		}

		return Result;
	}



};



*/

