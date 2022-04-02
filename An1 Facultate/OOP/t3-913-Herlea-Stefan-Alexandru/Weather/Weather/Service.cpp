#include "Service.h"
#include <algorithm>
#include <iterator>

Service::Service(Repository& repo) : repo{ repo }
{
}

Service::~Service()
{
}

void Service::add(string field1, string field2, string field3, string field4)
{
	int start = stoi(field1);
	int end = stoi(field2);
	int pp = stoi(field3);
	
	Weather m(start, end, pp, field4);

	this->repo.add(m);
}

vector<Weather>& Service::getAll()
{
	return this->repo.getAll();
}

vector<Weather> Service::filter(std::function<bool(Weather m)> f)
{
	vector<Weather> result;
	vector<Weather> list = this->repo.getAll();

	std::copy_if(list.begin(), list.end(), std::back_inserter(result), f);

	return result;
}

vector<Weather> Service::filterPp(string pp)
{
	int p = stoi(pp);

	return this->filter([p](Weather m) { return m.getPp() < p; });
}

vector<Weather> Service::filterDesc(string desc)
{
	return this->filter([desc](Weather m) { return m.getDesc() == desc; });
}
