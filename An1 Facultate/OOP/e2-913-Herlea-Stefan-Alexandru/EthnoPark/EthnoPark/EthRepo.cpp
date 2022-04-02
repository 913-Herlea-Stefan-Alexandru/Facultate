#include "EthRepo.h"
#include <fstream>

EthRepo::EthRepo(string fileName) : fileName{ fileName }
{
	this->load();
}

void EthRepo::load()
{
	std::ifstream f(this->fileName);

	if (!f.is_open())
		return;

	Ethnologist u;

	while (f >> u)
	{
		this->list.push_back(u);
	}

	f.close();
}

vector<Ethnologist>& EthRepo::getAll()
{
	return this->list;
}
