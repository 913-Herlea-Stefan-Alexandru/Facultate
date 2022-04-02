#pragma once

#include "gene.h"
#include <vector>

using std::vector;

class RepoException
{
private:

	string msg;

public:

	RepoException(string msg) : msg{ msg } {}

	string getMessage()
	{
		return this->msg;
	}
};

class Repo
{
private:

	vector<Gene> geneList;

public:

	void add(Gene gene);

	void remove(string org, string name);

	vector<Gene> filterSeq(string seq);

	Gene get(string org, string name);

	int getMaxOrg();

	int getMaxName();

	int getMaxSeq();

	vector<Gene> getAll();
};