#include "BuildingRepo.h"
#include <fstream>
#include <exception>

BuildingRepo::BuildingRepo(string fileName) : fileName{ fileName }
{
	this->load();
}

void BuildingRepo::add(Building b)
{
	for (auto& bld : this->list)
	{
		if (b.getId() == bld.getId())
			throw exception("Building with same id already in!");
	}
	this->list.push_back(b);
	this->save();
}

Building& BuildingRepo::operator[](int id)
{
	for (auto& bld : this->list)
	{
		if (id == bld.getId())
		{
			return bld;
		}
	}
	throw exception("Building not found!");
}

void BuildingRepo::load()
{
	std::ifstream f(this->fileName);

	if (!f.is_open())
		return;

	Building u;

	while (f >> u)
	{
		this->list.push_back(u);
	}

	f.close();
}

void BuildingRepo::save()
{
	if (this->fileName != "")
	{
		std::ofstream f(this->fileName);

		f << "";

		f.close();

		f.open(this->fileName, std::ios_base::app);

		for (Building& u : this->list)
		{
			f << u << '\n';
		}

		f.close();
	}
}

vector<Building>& BuildingRepo::getAll()
{
	return this->list;
}
