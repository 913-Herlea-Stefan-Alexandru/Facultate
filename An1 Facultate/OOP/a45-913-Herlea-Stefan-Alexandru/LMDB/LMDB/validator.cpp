#include "validator.h"

bool Validator::validate_integer(string integer)
{
	string::const_iterator it = integer.begin();
	while (it != integer.end() && isdigit(*it))
		it++;
	return (!integer.empty() && it == integer.end());
}

int Validator::validate_title(string title)
{
	if (title == "")
		return 1;
	return 0;
}

int Validator::validate_genre(string genre)
{
	if (genre == "")
		return 1;
	return 0;
}

int Validator::validate_year(string year)
{
	if (!this->validate_integer(year) || atoi(year.c_str()) < 0)
		return 1;
	return 0;
}

int Validator::validate_likes(string likes)
{
	if (!this->validate_integer(likes) || atoi(likes.c_str()) < 0)
		return 1;
	return 0;
}

int Validator::validate_link(string link)
{
	if (link == "")
		return 1;
	if (link[0] != 'h' || link[1] != 't' || link[2] != 't' || link[3] != 'p' || link[4] != 's' || link[5] != ':')
		return 1;
	return 0;
}