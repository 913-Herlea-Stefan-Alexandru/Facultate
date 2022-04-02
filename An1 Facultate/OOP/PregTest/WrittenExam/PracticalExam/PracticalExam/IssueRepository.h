#pragma once
#include "Issue.h"
#include <fstream>
#include <algorithm>

class IssueRepository
{
private:

	string fileName;
	vector<Issue> list;

public:

	IssueRepository(string fileName) : fileName{ fileName }
	{
		this->load();
		this->sort();
	}

	void load()
	{
		std::ifstream f(this->fileName);

		if (!f.is_open())
			return;

		Issue i;

		while (f >> i)
		{
			this->list.push_back(i);
		}

		f.close();
	}

	void save()
	{
		if (this->fileName != "")
		{
			std::ofstream f(this->fileName);

			f << "";

			f.close();

			f.open(this->fileName, std::ios_base::app);

			for (Issue& i : this->list)
			{
				f << i << '\n';
			}

			f.close();
		}
	}

	void sort()
	{
		std::sort(this->list.begin(), this->list.end(), [](Issue& i1, Issue& i2) { if (i1.status > i2.status || (i1.status == i2.status && i1.description < i2.description)) return true; else return false; });
	}

	void add(Issue i)
	{
		this->list.push_back(i);
		this->save();
	}

	void remove(string description)
	{
		for (int i = 0; i < this->list.size(); i++)
		{
			if (this->list[i].description == description)
			{
				this->list.erase(this->list.begin() + i);
				this->save();
				return;
			}
		}
	}

	Issue& get(string description)
	{
		for (Issue& i : this->list)
		{
			if (i.description == description)
				return i;
		}
	}

	vector<Issue>& getAll()
	{
		this->sort();
		return this->list;
	}
};

