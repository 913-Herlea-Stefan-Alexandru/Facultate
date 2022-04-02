#pragma once
#include "Ethnologist.h"

class EthRepo
{
private:

	vector<Ethnologist> list;
	string fileName;

public:

	EthRepo(string fileName);

	void load();

	void save();

	vector<Ethnologist>& getAll();
};

