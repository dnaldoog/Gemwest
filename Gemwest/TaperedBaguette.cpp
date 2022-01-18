#include "pch.h"
#include "TaperedBaguette.h"

String^ TaperedBaguette::calculate() {

	return this->dia_tapered_baguette_formula();

}
//Length x(MaxWidth + MinWidth) / 2 * depth * adjustments * 0.00915

String^ TaperedBaguette::dia_tapered_baguette_formula() {
	return DCalc::dia_tapered_baguette_formula(_length, _minW, _maxW, _depth, _factor, _adjust,_depthaspercent)+"ct";
}