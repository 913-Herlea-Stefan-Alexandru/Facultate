#pragma once
#include <string>

using std::string;

class Measurement
{
protected:
	string date;

public:
	Measurement();
	Measurement(string date);
	virtual bool isNormalValue() = 0;
	virtual string toString() = 0;
};