#include "pch.h"
#include "CDfancy.h"
/*https://www.vcalc.com/wiki/KurtHeckman/Diamond+-+Pear-shape+Brilliant following checked against 01/26/2022*/

Double CDfancy::lw() {
	return static_cast<Double>(CCalculator::length_width_ratio(m_length,m_width));

}

String^ CDfancy::setFancyRecutFactor() {

		String^ factor = "0.001";
		Double coefficient=0;
		Double lw = this->lw();

		if (this->fancyType->Equals(MARQ)) {

			if (lw < 1.44)	{	  coefficient = 0.00565; }
			else if (lw < 1.55) { coefficient = 0.00566; }
			else if (lw < 1.68) { coefficient = 0.00570; }
			else if (lw < 1.83) { coefficient = 0.00575; }
			else if (lw < 2.01) { coefficient = 0.00580; }
			else if (lw < 2.23) { coefficient = 0.00582; }
			else if (lw < 2.51) { coefficient = 0.00585; }
			else if (lw < 2.87) { coefficient = 0.00592; }
			else{				  coefficient = 0.00595; }

		}
		else if (this->fancyType->Equals(PEAR)) {


			if      (lw < 1.26) { coefficient = 0.00615; }
			else if (lw < 1.34) { coefficient = 0.00610; }
			else if (lw < 1.44) { coefficient = 0.00604; }
			else if (lw < 1.55) { coefficient = 0.00598; }
			else if (lw < 1.68) { coefficient = 0.00590; }
			else if (lw < 1.83) { coefficient = 0.00583; }
			else { coefficient = 0.00575; }
		}
		else if (this->fancyType->Equals(EMER)) {

			if (lw < 1.01) { coefficient = 0.00800; }
			else if (lw < 1.06) { coefficient = 0.00813; }
			else if (lw < 1.12) { coefficient = 0.00827; }
			else if (lw < 1.19) { coefficient = 0.00842; }
			else if (lw < 1.26) { coefficient = 0.00860; }
			else if (lw < 1.34) { coefficient = 0.00880; }
			else if (lw < 1.44) { coefficient = 0.00903; }
			else if (lw < 1.55) { coefficient = 0.00926; }
			else if (lw < 1.68) { coefficient = 0.00947; }
			else if (lw < 1.83) { coefficient = 0.00971; }
			else if (lw < 2.01) { coefficient = 0.01000; }
			else if (lw < 2.23) { coefficient = 0.01027; }
			else { coefficient = 0.01060; }
		}

		else if (this->fancyType->Equals(RADI)) {

			coefficient = 0.1;
		}
		factor = Convert::ToString(coefficient);
		return factor;

}


Decimal CDfancy::term() {
	Decimal factor = this->fac2Dec();
	return  this->add_adjustments_to_carat_weight(m_d1 * m_d2 * m_depth * factor);
}