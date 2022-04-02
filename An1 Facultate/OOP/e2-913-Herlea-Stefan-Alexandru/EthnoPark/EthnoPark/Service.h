#pragma once
#include "BuildingRepo.h"

class Service
{
private:

	BuildingRepo& repo;

public:

	Service(BuildingRepo& repo);

	void addBuilding(int id, string description, string area, string loc);

	void updateBuilding(int id, string description, string loc);

	vector<Building>& getBuildings(string area = "");
};

