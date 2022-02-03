#pragma once
using namespace System;
using namespace CSconfig;
ref class BridgeCS
{
public:
	property String^ propBridgeCalc
	{
		String^ get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			return l->PcsCalc; // a json string

		}
		void set(String^ pb)

		{
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			l->PcsCalc = pb;
		}
	}
	property String^ propBridgeCarat
	{
		String^ get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			return l->PcsCarat;

		}
		void set(String^ pb)

		{
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			l->PcsCarat = pb;
		}
	}
	property String^ propBridge1000
	{
		String^ get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			return l->Pcs1000;

		}
		void set(String^ pb)

		{
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			l->Pcs1000 = pb;
		}
	}

	property Boolean propBridgeSaveDate
	{
		Boolean get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			return l->PcsSaveDate;

		}
		void set(Boolean b)

		{
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			l->PcsSaveDate = b;
		}
	}

	property Boolean propBridgeSaveTime
	{
		Boolean get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			return l->PcsSaveTime;

		}
		void set(Boolean b)

		{
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			l->PcsSaveTime = b;
		}
	}
};

