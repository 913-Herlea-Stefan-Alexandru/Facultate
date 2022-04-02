#pragma once

#include "measurement.h"

class BMI : public Measurement
{
private:
	double value;

public:
	BMI(string date, double value);
	bool isNormalValue() override;
	string toString();
};