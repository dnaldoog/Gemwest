#pragma once
#include "CGcalc.h"
ref class CBriolette :
    public CGcalc
{
public:
     CBriolette(Decimal h, Decimal w, Decimal d, Decimal sg, Decimal f, String^ adj) : CGcalc(h, w, d, sg, f, adj) {}
};

/*
Based on the numbers found in "The Complete Handbook for Gemstone Weight Estimation" by Charles Carmona

Briolette Shape Faceted & Cabachon Stones:
W * H * D * SG * (0.00200 - 0.00240)

where:
W = side to side (width)
H = top to bottom (height)
D = front to back (depth)
SG = Specific Gravity

With thanks to S. Rautiainen of https://www.gemologyonline.com/ for providing formula.
*/

