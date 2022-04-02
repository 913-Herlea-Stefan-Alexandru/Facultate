#include "Model.h"

Model::Model(string field1, string field2, int field3, int field4) : field1{ field1 }, field2{ field2 }, field3{ field3 }, field4{ field4 }
{

}

Model::~Model()
{

}

string Model::getField1()
{
	return this->field1;
}

string Model::getField2()
{
	return this->field2;
}

int Model::getField3()
{
	return this->field3;
}

int Model::getField4()
{
	return this->field4;
}

void Model::setField1(string newVal)
{
	this->field1 = newVal;
}

void Model::setField2(string newVal)
{
	this->field2 = newVal;
}

void Model::setField3(int newVal)
{
	this->field3 = newVal;
}

void Model::setField4(int newVal)
{
	this->field4 = newVal;
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

std::ostream& operator<<(std::ostream& output, const Model& m)
{
	output << m.field1 << "," << m.field2 << "," << m.field3 << "," << m.field4 << "\n";
	return output;
}

std::istream& operator>>(std::istream& input, Model& m)
{
	string line;
	getline(input, line);

	std::vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return input;

	m.field1 = tokens[0];
	m.field2 = tokens[1];
	m.field3 = std::stoi(tokens[2]);
	m.field4 = std::stoi(tokens[3]);

	return input;
}
