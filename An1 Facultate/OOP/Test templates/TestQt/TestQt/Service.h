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
	void remove(string field1);
	void update(string field1, string new_f1, string new_f2, string new_f3, string new_f4);
	vector<Model>& getAll();

	//sort functions
	vector<Model> sort(std::function <bool(Model m1, Model m2)> f);
	vector<Model> sortF1();
	vector<Model> sortF2();
	vector<Model> sortF3();
	vector<Model> sortF4();

	//filter functions
	vector<Model> filter(std::function <bool(Model m)> f);
	vector<Model> filterF1(string f1);
	vector<Model> filterF2(string f2);
	vector<Model> filterF3(string f3);
	vector<Model> filterF4(string f4);
};

