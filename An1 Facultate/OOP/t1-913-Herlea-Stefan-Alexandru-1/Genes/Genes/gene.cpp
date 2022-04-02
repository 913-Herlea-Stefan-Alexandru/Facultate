#include "gene.h"

Gene::Gene(string org, string name, string seq) : organism{org}, name{name}, sequence{seq}
{

}

string Gene::getOrganism()
{
	return this->organism;
}

string Gene::getName()
{
	return this->name;
}

string Gene::getSequence()
{
	return this->sequence;
}
