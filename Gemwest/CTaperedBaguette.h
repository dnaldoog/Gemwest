#pragma once
#include "CDcalc.h"
ref class TaperedBaguette : public CDcalc
{
private:
    String^ m_minW; // minimum Width
    String^ m_maxW; // maximum Width
    //String^ _length; // length of tapered baguette
    //String^ _depth; // depth of tapered baguette
    //String^ _factor; // factor of tapered baguette should be 0.00915
    //String^ _adjust; // adjustments
    //Boolean _depthaspercent;

//public:
    //TaperedBaguette();
    //TaperedBaguette(String^ minw, String^ maxw, String^ l, String^ d, String^ f, String^ adj, Boolean isperc)
    //	:_minW(minw), _maxW(maxw), _length(l), _depth(d), _factor(f), _adjust(adj), _depthaspercent(isperc)
    //{}

public:
    //TaperedBaguette(String^ min, String^ max) {
    //    m_maxW(max);
    //    m_minW(min);

    //};
	virtual Double term() override;
	//String^ dia_tapered_baguette_formula(void);
};

/*public ref class Xyz
{
private:
  int _x, _y;
    String ^_name;
public:
  property int X
    {
      int get()
        {
          return _x;
        }
        void set(int x)
        {
          _x = x;
        }
    }
  property String ^Name
  {
    void set(String ^N)
    {
      _name = N;
    }
    String ^get()
    {
      return _name;
    }
  }
};*/



