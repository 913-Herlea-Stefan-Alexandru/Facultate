#pragma once

#include "person.h"
#include "bmi.h"
#include "bp.h"
#include <exception>

using std::exception;

class ValExcept : public exception
{
private:
	string message;

public:
	
};

class Service
{
private:
	Person person;

public:
	Service(Person person);

	bool addBMI(string date, string value);

	bool addBP(string date, string systolicValue, string diastolicValue);

	void dysplayAll();
};