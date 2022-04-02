#pragma once
#include "Building.h"

class BuildingRepo
{
private:

	vector<Building> list;
	string fileName;

public:

	BuildingRepo(string fileName);

	void add(Building b);

	Building& operator[](int id);

	void load();

	void save();

	vector<Building>& getAll();
};

