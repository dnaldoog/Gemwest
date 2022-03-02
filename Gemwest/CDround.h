#pragma once
#include "CDcalc.h"
//#include <string.h>


ref class CDround :
    public CDcalc
{
private:
	String^ m_recut_image;
	String^ m_recut_info;
	array<String^>^ m_cutnames;
public:
	explicit CDround(
		String^ cutName,
		Decimal fac,
		Decimal d1,
		Decimal d2,
		Decimal dep,
		Decimal sg,
		String^ adj,
		String^ gt,
		String^ pv,
		String^ so,
		Boolean isdiamond,
		Boolean recut,
		Boolean depthisperc) : CDcalc(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, recut, depthisperc) {

		array<String^>^ tmp = gcnew array<String^> {"recut", "shallow", "deep_stone","stonedepthokay"}; // initialise cut pictures
		m_cutnames = tmp;
		m_recut_info = "";

	}

    Decimal term() override;
    Decimal recut_weight() override;

	property String^ cutimage
	{
		String^ get() { return m_recut_image; }
		void set(String^ c)
		{
			m_recut_image = c;
		}
	}
	property String^ recutinformation
	{
		String^ get() { return m_recut_info; }
		void set(String^ info)
		{
			m_recut_info =info;
		}
	}
};

