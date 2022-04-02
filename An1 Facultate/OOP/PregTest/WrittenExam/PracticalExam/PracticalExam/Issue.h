#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Issue
{
public:

	string description;
	string status;
	string reporter;
	string solver;

public:

	Issue(string description, string status, string reporter, string solver = "");
	Issue() : description{ "" }, status{ "" }, reporter{ "" }, solver{ "" }
	{
	}

	friend std::ostream& operator<<(std::ostream& output, const Issue& i);

	friend std::istream& operator>>(std::istream& input, Issue& i);
};

