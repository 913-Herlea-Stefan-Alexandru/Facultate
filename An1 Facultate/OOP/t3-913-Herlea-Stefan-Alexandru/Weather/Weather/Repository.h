#pragma once
#include <vector>
#include <exception>
#include "Weather.h"

using std::exception;
using std::vector;

class RepoException : public exception
{
private:

	string message;

public:

	RepoException(string message) : message{ message }
	{

	}

	const char* what() const noexcept override
	{
		return this->message.c_str();
	}
};

class Repository
{
protected:

	vector<Weather> list;
	string fileName;

public:

	Repository(string fileName);
	~Repository();

	//create the basic functions
	void add(Weather m);

	vector<Weather>& getAll();

	void save();

	void load();
};


