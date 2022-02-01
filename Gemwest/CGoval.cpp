#include "pch.h"
#include "CGoval.h"
Decimal CGoval::term() {
	Decimal factor = CCalculator::fac2Dec(this->factor);
	Decimal av_diameter = CCalculator::average_diameter(this->d1, this->d2);
	return CCalculator::add_adjustments_to_carat_weight((av_diameter * av_diameter) * this->dp * this->sg * factor, this->adjust);
}