#include "Weather.h"

Weather::Weather(int field1, int field2, int field3, string field4) : start{ field1 }, end{ field2 }, pp{ field3 }, desc{ field4 }
{

}

Weather::~Weather()
{

}

int Weather::getStart()
{
	return this->start;
}

int Weather::getEnd()
{
	return this->end;
}

int Weather::getPp()
{
	return this->pp;
}

string Weather::getDesc()
{
	return this->desc;
}

void Weather::setStart(int newVal)
{
	this->start = newVal;
}

void Weather::setEnd(int newVal)
{
	this->end = newVal;
}

void Weather::setPp(int newVal)
{
	this->pp = newVal;
}

void Weather::setDesc(string newVal)
{
	this->desc = newVal;
}

std::vector<string> tokenize(string str, char delimiter)
{
	std::vector<string> result;
	std::stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::ostream& operator<<(std::ostream& output, const Weather& m)
{
	output << m.start << ";" << m.end << ";" << m.pp << ";" << m.desc << "\n";
	return output;
}

std::istream& operator>>(std::istream& input, Weather& m)
{
	string line;
	getline(input, line);

	std::vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 4)
		return input;

	m.start = stoi(tokens[0]);
	m.end = stoi(tokens[1]);
	m.pp = std::stoi(tokens[2]);
	m.desc = tokens[3];

	return input;
}
