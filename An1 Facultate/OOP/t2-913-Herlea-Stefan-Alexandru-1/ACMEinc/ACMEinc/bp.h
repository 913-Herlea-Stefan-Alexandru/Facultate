#pragma once
#include "measurement.h"

class BP : public Measurement
{
private:
	int systolicValue;
	int diastolicValue;

public:
	BP(string date, int systolicValue, int diastolicValue);
	bool isNormalValue() override;
	string toString();
};