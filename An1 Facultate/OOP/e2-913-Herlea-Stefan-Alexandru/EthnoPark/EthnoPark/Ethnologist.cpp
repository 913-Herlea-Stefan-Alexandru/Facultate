#include "Ethnologist.h"

Ethnologist::Ethnologist(string name, string area) : name{ name }, area{ area }
{
}

string Ethnologist::getName()
{
	return this->name;
}

string Ethnologist::getArea()
{
	return this->area;
}

std::ostream& operator<<(std::ostream& output, const Ethnologist& e)
{
	output << e.name << ";" << e.area;
	return output;
}

std::istream& operator>>(std::istream& input, Ethnologist& e)
{
	string line;
	getline(input, line);

	//std::vector<string> tokens = tokenize(line, ';');

	std::vector<string> tokens;
	std::stringstream ss(line);
	string token;
	while (getline(ss, token, ';'))
		tokens.push_back(token);

	if (tokens.size() != 2)
		return input;

	e.name = tokens[0];
	e.area = tokens[1];

	return input;
}
