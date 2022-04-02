#include "Repository.h"

Repository::Repository()
{

}

Repository::~Repository()
{

}

void Repository::add(Model m)
{
	for (Model& mod : this->list)
	{
		if (mod.getField1() == m.getField1())
		{
			throw RepoException("Item with field 1 alredy in list\n");
		}
	}
	this->list.push_back(m);
}

void Repository::remove(string field1)
{
	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i].getField1() == field1)
		{
			this->list.erase(this->list.begin() + i);
			return;
		}
	}
	throw RepoException("Item not found");
}

void Repository::update(string field1, string f1, string f2, int f3, int f4)
{
	for (Model& m : this->list)
	{
		if (m.getField1() == field1)
		{
			if (f1 != "")
			{
				m.setField1(f1);
			}
			if (f2 != "")
			{
				m.setField2(f2);
			}
			if (f3 != -1)
			{
				m.setField3(f3);
			}
			if (f4 != -1)
			{
				m.setField4(f4);
			}
			return;
		}
	}
}

vector<Model>& Repository::getAll()
{
	return this->list;
}
