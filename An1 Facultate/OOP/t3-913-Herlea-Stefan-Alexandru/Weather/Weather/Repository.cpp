#include "Repository.h"
#include <fstream>

Repository::Repository(string fileName) : fileName{ fileName }
{
	this->load();
}

Repository::~Repository()
{
}

void Repository::add(Weather m)
{
	this->list.push_back(m);
	this->save();
}

vector<Weather>& Repository::getAll()
{
	return this->list;
}

void Repository::save()
{
	if (this->fileName != "")
	{
		std::ofstream f(this->fileName);

		f << "";

		f.close();

		f.open(this->fileName, std::ios_base::app);

		for (Weather& m : this->list)
		{
			f << m;
		}

		f.close();
	}
}

void Repository::load()
{
	std::ifstream f(this->fileName);

	if (!f.is_open())
		return;

	Weather m;

	while (f >> m)
	{
		this->list.push_back(m);
	}

	f.close();
}
