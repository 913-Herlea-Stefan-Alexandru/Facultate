#include "bmi.h"

BMI::BMI(string date, double value) : Measurement(date), value{value}
{
}

bool BMI::isNormalValue()
{
	return false;
}

string BMI::toString()
{
	string val = "BMI: ";
	val += date;
	val += "   ";
	val += std::to_string(this->value);
	return val;
}
