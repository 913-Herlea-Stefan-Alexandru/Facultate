#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Ethnologist
{
private:

	string name;
	string area;

public:

	Ethnologist(string name, string area);
	Ethnologist()
	{}

	string getName();

	string getArea();

	friend std::ostream& operator<<(std::ostream& output, const Ethnologist& e);

	friend std::istream& operator>>(std::istream& input, Ethnologist& e);
};

