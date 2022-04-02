#include "bp.h"

BP::BP(string date, int systolicValue, int diastolicValue) : Measurement(date), systolicValue{systolicValue}, diastolicValue{diastolicValue}
{
}

bool BP::isNormalValue()
{
	return false;
}

string BP::toString()
{
	string val = "BP:  ";
	val = date;
	val += "   ";
	val += std::to_string(this->systolicValue);
	val += "   ";
	val += std::to_string(this->diastolicValue);
	return val;
}
