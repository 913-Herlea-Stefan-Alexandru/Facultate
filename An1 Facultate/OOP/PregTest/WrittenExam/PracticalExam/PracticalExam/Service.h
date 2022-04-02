#pragma once
#include "IssueRepository.h"
#include <exception>

class Service
{
private:
	
	IssueRepository& iRepo;

public:

	Service(IssueRepository& iRepo);

	void addIssue(string description, string reporter);

	void removeIssue(string description);

	void solveIssue(string description, string programmer);

	vector<Issue>& getIssueList();


};

