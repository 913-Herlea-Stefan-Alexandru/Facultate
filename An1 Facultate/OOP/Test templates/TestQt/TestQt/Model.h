#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using std::string;

class Model
{
private:

	//the object's fields
	string field1;
	string field2;
	int field3;
	int field4;

public:

	Model(string field1, string field2, int field3, int field4);
	Model() : field1{ "" }, field2{ "" }, field3{ 0 }, field4{ 0 }
	{

	}
	~Model();

	//create the getters
	string getField1();
	string getField2();
	int getField3();
	int getField4();

	//create the setters
	void setField1(string newVal);
	void setField2(string newVal);
	void setField3(int newVal);
	void setField4(int newVal);

	//red/write functions
	friend std::ostream& operator<<(std::ostream& output, const Model& m);

	friend std::istream& operator>>(std::istream& input, Model& m);
};

