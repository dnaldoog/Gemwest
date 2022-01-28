#pragma once
using namespace System;
using namespace CSconfig;

ref class BridgeCS
{
public:
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

	property String^ propBridgeLog
	{
		String^ get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			if (l->PcsLog=="true") { return "true"; }
			else { return "false"; }

		}
		void set(String^ pb)

		{
			CSconfig::SaveSettings^ l = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			l->PcsLog = pb;

		}
	}

	property String^ jsonString
	{
		String^ get()
		{
			// return the value of the private field
			CSconfig::SaveSettings^ j = gcnew CSconfig::SaveSettings;
			if (j->JsonLog!=nullptr)
			return j->JsonLog;

		}
		void set(String^ jsn)

		{
			CSconfig::SaveSettings^ j = gcnew CSconfig::SaveSettings;
			// return the value of the private field
			j->JsonLog=jsn;

		}
	}

	//String^ load1000();
	//String^ loadLog();
	//void save1000(String^);
	//void saveLog(Boolean);
};

