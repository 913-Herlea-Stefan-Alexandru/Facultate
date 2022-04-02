#include "person.h"

Person::Person(string name) : name{name}
{
}

void Person::addMeasuremend(Measurement *m)
{
	this->list.push_back(m);
}

vector<Measurement*> Person::getAllMeasurements()
{
	return this->list;
}

vector<Measurement*> Person::getByMonth(int month)
{
	return vector<Measurement*>();
}

bool Person::isHealthy(int month)
{
	return false;
}

vector<Measurement*> Person::getMeasurementsNewerThan(string date)
{
	return vector<Measurement*>();
}

void Person::writeToFile(string file_name, string date)
{
}

string Person::getName()
{
	return this->name;
}
