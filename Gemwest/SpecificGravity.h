#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
ref class SpecificGravity
	{
	private:
		Dictionary<String^, String^>^ m_sg;

		void setSG(Dictionary<String^, String^>^);
	public:
		property Dictionary<String^, String^>^ mySG {
			Dictionary<String^, String^>^ get(){ return m_sg; }

		}

		void dictInitializer();

		String^ getSG(String ^ key);
	};
	/*https://stackoverflow.com/questions/2364870/is-it-possible-to-create-a-static-dictionary-in-a-c-cli-environment*/

