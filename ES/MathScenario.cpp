#include "MathScenario.h"

MathScenario1::MathScenario1() {

}

MathScenario1::MathScenario1(int mult) {
	goodValueMultiplier = mult;
}

void MathScenario1::goodValue(float& value) {

}

void MathScenario1::badValue(float& value) {
	if ((static_cast<int>(value) & 1) == 0)
		value = 0;
}
