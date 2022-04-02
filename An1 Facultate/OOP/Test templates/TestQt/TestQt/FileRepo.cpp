#include "FileRepo.h"
#include <fstream>

FileRepo::FileRepo(string fileName) : Repository(), fileName{ fileName }
{
	this->load();
}

void FileRepo::add(Model m)
{
	Repository::add(m);
	this->save();
}

void FileRepo::remove(string field1)
{
	Repository::remove(field1);
	this->save();
}

void FileRepo::update(string field1, string f1, string f2, int f3, int f4)
{
	Repository::update(field1, f1, f2, f3, f4);
	this->save();
}

void FileRepo::save()
{
	if (this->fileName != "")
	{
		std::ofstream f(this->fileName);

		f << "";

		f.close();

		f.open(this->fileName, std::ios_base::app);

		for (Model& m : this->list)
		{
			f << m;
		}

		f.close();
	}
}

void FileRepo::load()
{
	std::ifstream f(this->fileName);

	if (!f.is_open())
		return;

	Model m;

	while (f >> m)
	{
		this->list.push_back(m);
	}

	f.close();
}
