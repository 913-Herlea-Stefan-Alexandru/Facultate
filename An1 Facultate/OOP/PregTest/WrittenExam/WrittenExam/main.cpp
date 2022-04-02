#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <assert.h>
#include <algorithm>
//
using namespace std;

//int f(const std::vector<int>& l, int v)
//{
//	if (l.empty())
//	{
//		throw std::exception();
//	}
//	int a = 0;
//	int b = l.size() - 1;
//	while (a <= b)
//	{
//		auto i = (a + b) / 2;
//		if (l[i] < v) a = i + 1;
//		else b = i - 1;
//	}
//	return a;
//}
//
//void testF()
//{
//	std::vector<int> l{ 2, 4, 10, 25, 88 };
//
//	assert(f(l, 25) == 3);
//
//	try
//	{
//		f(std::vector<int>{}, 9);
//		assert(false);
//	}
//	catch (std::exception& e)
//	{
//		assert(true);
//	}
//
//	assert(f(l, 2) == 0);
//
//	assert(f(l, 3) == 1);
//}
//
//template <class T>
//class Vehicul
//{
//private:
//
//	std::string nume;
//	std::vector<T> pasageri;
//
//public:
//
//	Vehicul(std::string nume) : nume{ nume }
//	{
//
//	}
//
//	Vehicul& operator+(T elem)
//	{
//		pasageri.push_back(elem);
//		return *this;
//	}
//
//	Vehicul& operator-(T elem)
//	{
//		for (int i = 0; i < pasageri.size(); i++)
//		{
//			if (pasageri[i] == elem)
//			{
//				pasageri.erase(pasageri.begin() + i);
//				return *this;
//			}
//		}
//		throw std::exception("Pasager inexistent!");
//		return *this;
//	}
//
//	auto begin()
//	{
//		return pasageri.begin();
//	}
//
//	auto end()
//	{
//		return pasageri.end();
//	}
//};
//
//void vh()
//{
//	Vehicul<std::string> tr{ "Tren" };
//	tr = tr + "Ana";
//	tr = tr + "Maria" + "Ion";
//	tr - "Maria" - "Ana";
//	try {
//		tr - "Vasile";
//	}
//	catch (std::exception& ex)
//	{
//		cout << ex.what();
//	}
//	for (auto pasager : tr)
//	{
//		cout << pasager << '\n';
//	}
//}

//class Device
//{
//public:
//	virtual void doIt() = 0;
//};
//
//class Electronic : public Device
//{
//public:
//	void doIt() { cout << "Electronic "; }
//};

//class Phone2 : public Electronic
//{
//public:
//	void doIt(int x) { cout << "Phone2"; }
//};
//
//class Phone3 : public Electronic
//{
//public:
//	void doIt() { cout << "Phone3"; }
//};

class Vehicul
{
private:
	
	int pret;

public:

	Vehicul(int pret = 0) : pret{ pret }
	{

	}

	virtual ~Vehicul() {

	}

	virtual string descriere() = 0;

	virtual int getPret()
	{
		return pret;
	}
};

class Masina : public Vehicul
{
private:

	string model;

public:

	Masina(string model, int pret) : Vehicul{ pret }, model{ model }
	{

	}

	~Masina() override
	{

	}

	string descriere() override
	{
		return model;
	}
};

class SchimbatorAutomat : public Vehicul
{
private:

	Vehicul* vehicul;

public:

	SchimbatorAutomat(Vehicul* vehicul) : vehicul{ vehicul }
	{
		
	}

	~SchimbatorAutomat() override
	{

	}

	string descriere() override
	{
		return vehicul->descriere() + " cu schimbator automat";
	}

	int getPret()
	{
		return vehicul->getPret() + 4000;
	}
};

class SenzorDeParcare : public Vehicul
{
private:

	Vehicul* vehicul;

public:

	SenzorDeParcare(Vehicul* vehicul) : vehicul{ vehicul }
	{

	}

	~SenzorDeParcare() override
	{

	}

	string descriere() override
	{
		return vehicul->descriere() + " cu senzor de parcare";
	}

	int getPret()
	{
		return vehicul->getPret() + 2500;
	}
};

std::vector<Vehicul*> fct()
{
	Vehicul* skoda = new Masina("Skoda", 2600);
	Vehicul* vw = new Masina("VW", 1500);
	Vehicul* duster = new Masina("Duster", 2000);
	Vehicul* seat = new Masina("Seat", 1700);

	Vehicul* vwSc = new SchimbatorAutomat(vw);
	Vehicul* vwScSz = new SenzorDeParcare(vwSc);

	Vehicul* dusterSc = new SchimbatorAutomat(duster);

	Vehicul* seatSz = new SenzorDeParcare(seat);

	return std::vector<Vehicul*>{skoda, vwScSz, dusterSc, seatSz};
}

int main()
{
	std::vector<Vehicul*> lista = fct();
	std::sort(lista.begin(), lista.end(), [](Vehicul* a, Vehicul* b) { return a->getPret() < b->getPret(); });
	for (auto vh : lista)
	{
		cout << vh->descriere() << " " << vh->getPret() << "\n";
	}
	return 0;
}