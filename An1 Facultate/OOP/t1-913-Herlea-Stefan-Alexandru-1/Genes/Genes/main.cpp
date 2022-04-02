#include "ui.h"
#include <assert.h>

void tests()
{
	Repo repo;
	Service service(repo);

	assert(repo.getAll().size() == 0);

	service.addGene("efq", "wegw", "ACGTAAC");

	assert(repo.getAll().size() == 1);

	service.addGene("eqqfq", "wewqrgw", "AGTCA");
	service.addGene("ewg", "weqefqegw", "AGTC");
	service.addGene("ewqefq", "q", "GGTA");

	assert(repo.getAll().size() == 4);

	try
	{
		service.addGene("efq", "wegw", "ACGTAAC");
		assert(false);
	}
	catch (RepoException ex)
	{
		assert(true);
	}
	try
	{
		service.addGene("q", "qf", "qegg");
		assert(false);
	}
	catch (RepoException ex)
	{
		assert(true);
	}
}

int main()
{
	tests();
	Repo repo;
	Service service(repo);
	Ui ui(service);
	ui.start();
	return 0;
}