#include "pch.h"
#include "CDround.h"



Decimal CDround::term() {
	Decimal factor = this->fac2Dec();
	Decimal av_diameter =CCalculator::average_diameter(m_d1,m_d2);
	return this->add_adjustments_to_carat_weight((av_diameter*av_diameter) * m_depth * factor);
}

Decimal CDround::recut_weight() {
	/* Code taken from old GTK Version */
	String^ cText = this->m_cutName;
	String^ info=L"";
	Decimal DeepStone, caratLossPerc, ShallowStone, newDiameter, newDepth, depthPercentage, dpCompareWithThreshold, lowThreshold, highThreshold, recutWeight, caratLoss, actualWeight, newDepthPercentage;
	 lowThreshold = 55;/*ie threshold is 54%*/
	 highThreshold = 62;/*ie threshold is 62%*/
	Decimal^ p = nullptr;
	Decimal w, depth;
	w = m_d2;
	depth = m_depth;
	actualWeight = this->term();
	if (depth==0 || w==0) { return 0; }
	depthPercentage = (depth / w) * 100;

	Decimal DEFDIAFACTOR = Convert::ToDecimal(m_factor);
	cutimage = m_cutnames[3];

	DeepStone = (w * 62) / 100;
	ShallowStone = (depth * 100) / 58;

	if (cText->Equals(DIAOVALCUT) || cText->Equals(DIAROUND) || cText->Equals(DIAOLDMINE) || cText->Equals(DIAOLDEURO)) {

		if (depthPercentage < lowThreshold) {
			/*it's a shallow stone*/

			newDiameter = ShallowStone;
			newDepth = depth;

			cutimage = m_cutnames[1];

		}
		if (depthPercentage > highThreshold) {
			/*it's a deep stone*/

			newDiameter = w;
			newDepth = DeepStone;

			cutimage = m_cutnames[2];

		}
		recutWeight = (newDiameter * newDiameter) * newDepth * DEFDIAFACTOR;

		caratLoss = Decimal::Subtract(actualWeight, recutWeight);
		if (actualWeight == 0 || recutWeight == 0) {
			caratLossPerc = 0;
		}
		else {
			caratLossPerc = 100 * ((Decimal::Subtract(actualWeight, recutWeight)) / actualWeight);
		}
		if (newDepth == 0 || newDiameter == 0)
		{
			newDepthPercentage = 0; // stop division by zero
		}
		else {
			newDepthPercentage = (newDepth / newDiameter) * 100;
		}
	
		info=L"New Diameter :"+Decimal::Round(newDiameter,2)+"\nNew Depth :"+ Decimal::Round(newDepth,2)+"\nNew Depth Percentage :"+ Decimal::Round(newDepthPercentage,1)+"%\nCarat weight loss :"+ Decimal::Round(caratLoss,2)+"\nWeight loss Percentage :"+ Decimal::Round(caratLossPerc,2)+"%";
		this->recutinformation = info;
		return Decimal::Round(recutWeight, 4);
	}
	else {
		return  Decimal::Round(recutWeight,2);
	}
}


