#include "pch.h"
#include "CDround.h"



Decimal CDround::term() {
	Decimal factor = this->fac2Dec();
	Decimal av_diameter =Decimal::Add(m_d1,m_d2) / 2;
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
	String^ DIAOVALCUT = "oval brilliant";
	String^ DIAROUND = "round brilliant";
	String^ DIAOLDMINE = "old mine cut";
	String^ DIAOLDEURO = "old european cut";
	Decimal DEFDIAFACTOR = Convert::ToDecimal(m_factor);
	cutimage = m_cutnames[3];

	DeepStone = (w * 62) / 100;
	ShallowStone = (depth * 100) / 58;

	if (cText->Equals(DIAOVALCUT) || cText->Equals(DIAROUND) || cText->Equals(DIAOLDMINE) || cText->Equals(DIAOLDEURO)) {

		if (depthPercentage < lowThreshold) {/*it's a shallow stone*/

			newDiameter = ShallowStone;// *p;
			newDepth = depth;

			cutimage = m_cutnames[1];

		}
		if (depthPercentage > highThreshold) {/*it's a deep stone*/

			newDiameter = w;
			newDepth = DeepStone;

			cutimage = m_cutnames[2];

		}
		recutWeight = (newDiameter * newDiameter) * newDepth * DEFDIAFACTOR;

		caratLoss = Decimal::Subtract(actualWeight, recutWeight);
		caratLossPerc = 100 * ((Decimal::Subtract(actualWeight, recutWeight)) / actualWeight);
		newDepthPercentage = depthPercentage;
		//if (showThous == TRUE) {
		//	return g_strdup_printf("<small>New Diameter (original %4.2f) >> %4.2f\nNew Depth (original %4.2f) >> %4.2f\nNew Depth Percentage=%4.2f%%\nCarat weight loss = %4.2fct\nWeight loss Percentage = %4.2f%%</small>\n<span foreground=\"blue\">Recut Estimation :<b>%4.3f</b>ct</span>", w, newDiameter, depth, newDepth, newDepthPercentage, caratLoss, caratLossPerc, recutWeight);
		//}
		//else {
			//return g_strdup_printf("<small>New Diameter (original %4.2f) >> %4.2f\nNew Depth (original %4.2f) >> %4.2f\nNew Depth Percentage=%4.2f%%\nCarat weight loss = %4.2fct\nWeight loss Percentage = %4.2f%%</small>\n<span foreground=\"blue\">Recut Estimation :<b>%4.2f</b>ct</span>", w, newDiameter, depth, newDepth, newDepthPercentage, caratLoss, caratLossPerc, recutWeight);
		//}//end thousands of a carat formatting
		info=L"New Diameter :"+Decimal::Round(newDiameter,2)+"\nNew Depth :"+ Decimal::Round(newDepth,2)+"\nNew Depth Percentage :"+ Decimal::Round(newDepthPercentage,2)+"%\nCarat weight loss :"+ Decimal::Round(caratLoss,2)+"\nWeight loss Percentage :"+ Decimal::Round(caratLossPerc,2)+"%";
		this->recutinformation = info;
		return Decimal::Round(recutWeight, 2);
	}
	else {
		return  Decimal::Round(recutWeight,2);
	}
}


