#pragma once
#include <vector>
#include <exception>
#include "Model.h"

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

	vector<Model> list;

public:

	Repository();
	~Repository();

	//create the basic functions
	virtual void add(Model m);
	virtual void remove(string field1);
	virtual void update(string field1, string f1, string f2, int f3, int f4);

	vector<Model>& getAll();
};

