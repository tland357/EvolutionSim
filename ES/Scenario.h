#pragma once

class Scenario {
public:
	Scenario();
	virtual void goodValue(float& value);
	virtual void badValue(float& value);
};