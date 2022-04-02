#include "Service.h"

Service::Service(IssueRepository& iRepo) : iRepo{ iRepo }
{
}

void Service::addIssue(string description, string reporter)
{
	if (description == "")
		throw exception("No issue description entered!");
	Issue i(description, "open", reporter, " ");
	this->iRepo.add(i);
}

void Service::removeIssue(string description)
{
	if (this->iRepo.get(description).status != "closed")
		throw exception("Issue not closed!");
	this->iRepo.remove(description);
}

void Service::solveIssue(string description, string programmer)
{
	this->iRepo.get(description).status = "closed";
	this->iRepo.get(description).solver = programmer;
	this->iRepo.save();
}

vector<Issue>& Service::getIssueList()
{
	return this->iRepo.getAll();
}
