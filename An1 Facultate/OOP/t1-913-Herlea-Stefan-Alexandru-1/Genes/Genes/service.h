#pragma once

#include "repo.h"

class Service
{
private:

	Repo& repo;

public:

	Service(Repo& repo);

	// creates and adds a gene with the given parameters into the repo
	// throws RepoError if the sequence is not valid
	void addGene(string organism, string name, string sequence);

	void removeGene(string organism, string name);

	string commonSub(string org1, string name1, string org2, string name2);

	vector<Gene> getBySeq(string seq);

	vector<Gene> getAll();

	string readable(vector<Gene> gl);
};