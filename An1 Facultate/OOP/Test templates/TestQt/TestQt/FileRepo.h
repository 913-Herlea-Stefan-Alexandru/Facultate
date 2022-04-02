#pragma once
#include "Repository.h"

class FileRepo : public Repository
{
private:

	string fileName;

public:

	FileRepo(string fileName);

	void add(Model m) override;
	void remove(string field1) override;
	void update(string field1, string f1, string f2, int f3, int f4) override;

	void save();

	void load();
};

