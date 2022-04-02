#include "service.h"
#include <iostream>

Service::Service(Person person) : person{person}
{
}

bool Service::addBMI(string date, string value)
{
	double val = std::stod(value);
	Measurement* b;
	b = new BMI(date, val);
	this->person.addMeasuremend(b);
	if (18.5 <= val && val <= 25)
		return true;
	return false;
}

bool Service::addBP(string date, string systolicValue, string diastolicValue)
{
	int s = atoi(systolicValue.c_str());
	int d = atoi(diastolicValue.c_str());
	Measurement* b;
	b = new BP(date, s, d);
	this->person.addMeasuremend(b);
	if (90 <= s && s <= 119 && 60 <= d && d <= 79)
		return true;
	return false;
}

void Service::dysplayAll()
{
	vector<Measurement*> vec = this->person.getAllMeasurements();
	std::cout << this->person.getName() << '\n';
	for (Measurement* m : vec)
	{
		std::cout << m->toString() << '\n';
	}
}
