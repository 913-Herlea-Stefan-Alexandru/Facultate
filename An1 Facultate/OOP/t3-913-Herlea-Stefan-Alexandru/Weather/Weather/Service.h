#pragma once
#include "Repository.h"
#include <functional>

class Service
{
private:

	Repository& repo;

public:

	Service(Repository& repo);
	~Service();

	//create basic functions
	void add(string field1, string field2, string field3, string field4);
	vector<Weather>& getAll();

	//filter functions
	vector<Weather> filter(std::function <bool(Weather m)> f);
	vector<Weather> filterPp(string pp);
	vector<Weather> filterDesc(string desc);
	vector<Weather> filterF3(string f3);
	vector<Weather> filterF4(string f4);
};



