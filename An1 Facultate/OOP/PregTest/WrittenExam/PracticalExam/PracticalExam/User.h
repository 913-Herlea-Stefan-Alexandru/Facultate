#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class User
{
public:

	string name;
	string type;

public:

	User(string name, string type);
	User();

	friend std::ostream& operator<<(std::ostream& output, const User& u);

	friend std::istream& operator>>(std::istream& input, User& u);
};

