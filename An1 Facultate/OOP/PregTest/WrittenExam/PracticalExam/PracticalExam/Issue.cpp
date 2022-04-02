#include "Issue.h"
#include "tokenize.h"

Issue::Issue(string description, string status, string reporter, string solver) : description{ description }, status{ status }, reporter{ reporter }, solver{ solver }
{
}

std::ostream& operator<<(std::ostream& output, const Issue& i)
{
	output << i.description << ";" << i.status << ";" << i.reporter << ";" << i.solver;
	return output;
}

std::istream& operator>>(std::istream& input, Issue& i)
{
	string line;
	getline(input, line);

	std::vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 4)
		return input;

	i.description = tokens[0];
	i.status = tokens[1];
	i.reporter = tokens[2];
	i.solver = tokens[3];

	return input;
}
