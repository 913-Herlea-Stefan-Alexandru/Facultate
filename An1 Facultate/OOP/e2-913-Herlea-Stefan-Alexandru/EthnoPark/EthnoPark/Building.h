#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Building
{
private:

	int id;
	string description;
	string area;
	vector<string> location;

public:

	Building(int id, string description, string area, vector<string> location);
	Building()
	{}

	int getId();

	string getDescription();

	string getArea();

	vector<string> getLocation();

	void setDescription(string description);

	void setLocation(vector<string> location);

	friend std::ostream& operator<<(std::ostream& output, const Building& e);

	friend std::istream& operator>>(std::istream& input, Building& e);
};

