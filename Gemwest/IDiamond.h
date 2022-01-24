#pragma once
using namespace System;


public interface class IDiamond
{
//public:
	//virtual Decimal term() const = 0;
	virtual Decimal term()  = 0;
	//virtual Decimal term();// = 0;
	virtual String^ return_recut()=0;// = 0;
};

