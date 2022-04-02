#include "Service.h"

Service::Service(BuildingRepo& repo) : repo{ repo }
{
}

void Service::addBuilding(int id, string description, string area, string loc)
{
	if (description == "" || loc == "")
		throw exception("Description/location cannot be empty!");
	vector<string> location;

	std::stringstream ss(loc);
	string token;
	while (getline(ss, token, ';'))
		location.push_back(token);

	for (auto& bld : this->repo.getAll())
	{
		for (auto& lc : bld.getLocation())
		{
			for (auto& given : location)
			{
				if (lc == given)
					throw exception("Buildings cannot overlap!");
			}
		}
	}

	Building b(id, description, area, location);

	this->repo.add(b);
}

void Service::updateBuilding(int id, string description, string loc)
{
	Building& b = repo[id];
	if (description == "" || loc == "")
		throw exception("Description/location cannot be empty!");
	vector<string> location;

	std::stringstream ss(loc);
	string token;
	while (getline(ss, token, ';'))
		location.push_back(token);

	for (auto& bld : this->repo.getAll())
	{
		for (auto& lc : bld.getLocation())
		{
			for (auto& given : location)
			{
				if (lc == given)
					throw exception("Buildings cannot overlap!");
			}
		}
	}

	b.setDescription(description);
	b.setLocation(location);

	this->repo.save();
}

vector<Building>& Service::getBuildings(string area)
{
	return this->repo.getAll();
}
