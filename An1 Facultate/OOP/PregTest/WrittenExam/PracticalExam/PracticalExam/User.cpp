#include "User.h"

User::User(string name, string type) : name{ name }, type{ type }
{
}

User::User() : name{ "" }, type{ "" }
{
}

std::ostream& operator<<(std::ostream& output, const User& u)
{
	output << u.name << ";" << u.type;
	return output;
}

std::istream& operator>>(std::istream& input, User& u)
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

	u.name = tokens[0];
	u.type = tokens[1];

	return input;
}
