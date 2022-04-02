#pragma once

#include "measurement.h"
#include <vector>

using std::vector;

class Person
{
private:
	string name;

	vector<Measurement*> list;

public:
	Person(string name);

	void addMeasuremend(Measurement *m);

	vector<Measurement*> getAllMeasurements();

	vector<Measurement*> getByMonth(int month);

	bool isHealthy(int month);

	vector<Measurement*> getMeasurementsNewerThan(string date);

	void writeToFile(string file_name, string date);

	string getName();
};