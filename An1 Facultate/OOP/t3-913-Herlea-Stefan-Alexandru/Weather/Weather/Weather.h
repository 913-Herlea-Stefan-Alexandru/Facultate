#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Weather
{
private:

	//the object's fields
	int start;
	int end;
	int pp;
	string desc;

public:

	Weather(int field1, int field2, int field3, string field4);
	Weather() : start{ -1 }, end{ -1 }, pp{ -1 }, desc{ "" }
	{

	}
	~Weather();

	//create the getters
	int getStart();
	int getEnd();
	int getPp();
	string getDesc();

	//create the setters
	void setStart(int newVal);
	void setEnd(int newVal);
	void setPp(int newVal);
	void setDesc(string newVal);

	//red/write functions
	friend std::ostream& operator<<(std::ostream& output, const Weather& m);

	friend std::istream& operator>>(std::istream& input, Weather& m);
};

