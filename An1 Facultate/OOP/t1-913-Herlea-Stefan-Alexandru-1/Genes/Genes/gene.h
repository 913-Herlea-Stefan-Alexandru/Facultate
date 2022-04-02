#pragma once

#include <string>

using std::string;

class Gene
{
private:

	string organism;
	string name;
	string sequence;

public:

	Gene();

	Gene(string org, string name, string seq);

	string getOrganism();

	string getName();

	string getSequence();
};