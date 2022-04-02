#include "repo.h"
#include <exception>

using std::qsort;


void Repo::add(Gene gene)
{
	for (Gene g : this->geneList)
	{
		if (g.getOrganism() == gene.getOrganism() && g.getName() == gene.getName())
		{
			throw RepoException("Gene already in list");
		}
	}
	this->geneList.push_back(gene);
}

void Repo::remove(string org, string name)
{
	int i = 0;
	for (auto it = this->geneList.begin(); it != this->geneList.end(); ++it)
	{
		Gene g = this->geneList[i];
		if (g.getOrganism() == org && g.getName() == name)
		{
			this->geneList.erase(it);
			return;
		}
		i++;
	}
	throw RepoException("Gene not found");
}

vector<Gene> Repo::filterSeq(string seq)
{
	vector<Gene> gl;
	for (Gene g : this->geneList)
	{
		if (strstr(g.getSequence().c_str(), seq.c_str()))
		{
			gl.push_back(g);
		}
	}
	return gl;
}

Gene Repo::get(string org, string name)
{
	for (Gene g : this->geneList)
	{
		if (g.getOrganism() == org && g.getName() == name)
		{
			return g;
		}
	}
}

int Repo::getMaxOrg()
{
	int maxL = 0;
	for (Gene g : this->geneList)
	{
		if (g.getOrganism().size() > maxL)
		{
			maxL = g.getOrganism().size();
		}
	}
	return maxL;
}

int Repo::getMaxName()
{
	int maxL = 0;
	for (Gene g : this->geneList)
	{
		if (g.getName().size() > maxL)
		{
			maxL = g.getName().size();
		}
	}
	return maxL;
}

int Repo::getMaxSeq()
{
	int maxL = 0;
	for (Gene g : this->geneList)
	{
		if (g.getSequence().size() > maxL)
		{
			maxL = g.getSequence().size();
		}
	}
	return maxL;
}

vector<Gene> Repo::getAll()
{
	return this->geneList;
}
