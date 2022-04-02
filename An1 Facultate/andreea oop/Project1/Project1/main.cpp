#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Measurement
{
private:
	T x;

public:
	Measurement(const T x) : x{ x }
	{

	}

	~Measurement() {}

	Measurement& operator+(const T x2)
	{
		this->x = this->x + x2;
		return *this;
	}

	bool operator<(const Measurement& m)
	{
		return this->x < m.value();
	}

	T value() const
	{
		return x;
	}
};

int main() {
	//creaza un vector de masuratori cu valorile (10,2,3)
	std::vector<Measurement<int>> v{ 10,2,3 };
	v[2] + 3 + 2; //aduna la masuratoarea 3 valuarea 5
	std::sort(v.begin(), v.end()); //sorteaza masuratorile
	//tipareste masuratorile (in acest caz: 2,8,10)
	for (const auto& m : v) std::cout << m.value() << ",";
	return 0;
}