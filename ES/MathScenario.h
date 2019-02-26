#pragma once
#include "Scenario.h"

//
class MathScenario1 : public Scenario {
public:
	MathScenario1();
	MathScenario1(int mult);
	virtual void badValue(float& value) override;
	virtual void goodValue(float& value) override;
private:
	int goodValueMultiplier = 2;
};

class MathScenario2 : public MathScenario1 {
	MathScenario2();
};

class MathScenario3 : public MathScenario1 {

};