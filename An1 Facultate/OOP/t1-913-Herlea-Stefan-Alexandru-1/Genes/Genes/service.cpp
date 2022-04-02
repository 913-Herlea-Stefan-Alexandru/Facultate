#include "service.h"

Service::Service(Repo& repo) : repo{repo}
{
}

void Service::addGene(string organism, string name, string sequence)
{
	for (int i = 0; i < sequence.size(); i++)
	{
		if (sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'G' && sequence[i] != 'T')
		{
			throw RepoException("Wrong sequence");
		}
	}
	Gene gene(organism, name, sequence);
	this->repo.add(gene);
}

void Service::removeGene(string organism, string name)
{
	this->repo.remove(organism, name);
}



string Service::commonSub(string org1, string name1, string org2, string name2)
{
	Gene g1 = this->repo.get(org1, name1);
	Gene g2 = this->repo.get(org2, name2);
	string seq1 = g1.getSequence();
	string seq2 = g2.getSequence();

	int pos = 0;
	for (int i = 0; i < seq1.size(); i++)
	{
		
	}
}

vector<Gene> Service::getBySeq(string seq)
{
	return this->repo.filterSeq(seq);
}

vector<Gene> Service::getAll()
{
	return this->repo.getAll();
}

string Service::readable(vector<Gene> gl)
{
	string rd = "";

	int maxO = this->repo.getMaxOrg();
	int maxN = this->repo.getMaxName();
	int maxS = this->repo.getMaxSeq();

	for (Gene g : gl)
	{
		string org = g.getOrganism();
		string name = g.getName();
		string seq = g.getSequence();

		while (org.size() < maxO)
		{
			org += " ";
		}

		while (name.size() < maxN)
		{
			name += " ";
		}

		while (seq.size() < maxS)
		{
			seq = " " + seq;
		}

		rd = rd + org + "|" + name + "|" + seq + "\n";
	}
	return rd;
}
