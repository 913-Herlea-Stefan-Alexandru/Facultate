#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> tokenize(string str, char delimiter)
{
	std::vector<string> result;
	std::stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}
