#pragma once
#include "CDcalc.h"
ref class CTaperedBaguette : public CDcalc
{
private:
   // String^ m_minW; // minimum Width - this is dia2
    String^ m_maxW; // maximum Width
public:
    property String^ maxW
    {
        String^ get() { return m_maxW; }
        void set(String^ s)
        {
            m_maxW=s;
        }
    }
    virtual Double term() override;
};




