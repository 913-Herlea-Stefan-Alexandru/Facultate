#include "Building.h"

Building::Building(int id, string description, string area, vector<string> location) : id{ id }, description{ description }, area{ area }, location{ location }
{
}

int Building::getId()
{
	return this->id;
}

string Building::getDescription()
{
	return this->description;
}

string Building::getArea()
{
	return this->area;
}

vector<string> Building::getLocation()
{
	return this->location;
}

void Building::setDescription(string description)
{
	this->description = description;
}

void Building::setLocation(vector<string> location)
{
	this->location = location;
}

std::ostream& operator<<(std::ostream& output, const Building& e)
{
	output << e.id << ";" << e.description << ";" << e.area;
	for (auto& loc : e.location)
	{
		output << ";" << loc;
	}
	return output;
}

std::istream& operator>>(std::istream& input, Building& e)
{
	string line;
	getline(input, line);

	//std::vector<string> tokens = tokenize(line, ';');

	std::vector<string> tokens;
	std::stringstream ss(line);
	string token;
	while (getline(ss, token, ';'))
		tokens.push_back(token);

	if (tokens.size() < 4)
		return input;

	e.location = vector<string>();

	e.id = stoi(tokens[0]);
	e.description = tokens[1];
	e.area = tokens[2];
	for (int i = 3; i < tokens.size(); i++)
	{
		e.location.push_back(tokens[i]);
	}

	return input;
}
