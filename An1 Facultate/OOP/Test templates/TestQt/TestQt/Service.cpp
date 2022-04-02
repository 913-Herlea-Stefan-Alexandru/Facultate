#include "Service.h"
#include <algorithm>
#include <iterator>

using std::stoi;

Service::Service(Repository& repo) : repo{ repo }
{

}

Service::~Service()
{

}

void Service::add(string field1, string field2, string field3, string field4)
{
	int f3, f4;
	f3 = stoi(field3);
	f4 = stoi(field4);

	Model m(field1, field2, f3, f4);

	this->repo.add(m);
}

void Service::remove(string field1)
{
	this->repo.remove(field1);
}

void Service::update(string field1, string new_f1, string new_f2, string new_f3, string new_f4)
{
	int f3, f4;
	if (new_f3 != "")
		f3 = stoi(new_f3);
	else
		f3 = -1;
	if (new_f4 != "")
		f4 = stoi(new_f4);
	else
		f4 = -1;

	this->repo.update(field1, new_f1, new_f2, f3, f4);
}

vector<Model>& Service::getAll()
{
	return this->repo.getAll();
}

vector<Model> Service::sort(std::function <bool(Model m1, Model m2)> f)
{
	vector<Model> result(this->repo.getAll());
	std::sort(result.begin(), result.end(), f);
	return result;
}

vector<Model> Service::sortF1()
{
	return this->sort([](Model m1, Model m2) { return m1.getField1() < m2.getField1(); });
}

vector<Model> Service::sortF2()
{
	return this->sort([](Model m1, Model m2) { return m1.getField2() < m2.getField2(); });
}

vector<Model> Service::sortF3()
{
	return this->sort([](Model m1, Model m2) { return m1.getField3() < m2.getField3(); });
}

vector<Model> Service::sortF4()
{
	return this->sort([](Model m1, Model m2) { return m1.getField4() < m2.getField4(); });
}

vector<Model> Service::filter(std::function<bool(Model m)> f)
{
	vector<Model> result;
	vector<Model> list = this->repo.getAll();

	std::copy_if(list.begin(), list.end(), std::back_inserter(result), f);

	return result;
}

vector<Model> Service::filterF1(string f1)
{
	return filter([f1](Model m) { return m.getField1().find(f1) != string::npos; });
}

vector<Model> Service::filterF2(string f2)
{
	return filter([f2](Model m) { return m.getField2().find(f2) != string::npos; });
}

vector<Model> Service::filterF3(string f3)
{
	int f3i;
	try
	{
		f3i = stoi(f3);
	}
	catch (...)
	{
		throw RepoException("");
	}
	return filter([f3i](Model m) { return m.getField3() == f3i; });
}

vector<Model> Service::filterF4(string f4)
{
	int f4i;
	try
	{
		f4i = stoi(f4);
	}
	catch (...)
	{
		throw RepoException("");
	}
	return filter([f4i](Model m) { return m.getField4() == f4i; });
}
