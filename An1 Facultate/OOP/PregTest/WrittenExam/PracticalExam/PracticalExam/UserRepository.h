#pragma once
#include "User.h"
#include <fstream>

using namespace std;

class UserRepository
{
private:

	string fileName;
	vector<User> list;

public:

	UserRepository(string fileName) : fileName{ fileName }
	{
		this->load();
	}

	void load()
	{
		std::ifstream f(this->fileName);

		if (!f.is_open())
			return;

		User u;

		while (f >> u)
		{
			this->list.push_back(u);
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

			for (User& u : this->list)
			{
				f << u << '\n';
			}

			f.close();
		}
	}

	User& get(string name)
	{
		for (User& u : this->list)
		{
			if (u.name == name)
				return u;
		}
	}

	User& operator[](int index)
	{
		return this->list[index];
	}

	int size()
	{
		return this->list.size();
	}
};

