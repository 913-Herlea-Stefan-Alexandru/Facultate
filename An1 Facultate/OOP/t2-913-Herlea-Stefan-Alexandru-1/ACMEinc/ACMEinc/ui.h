#pragma once

#include <iostream>
#include "service.h"

using namespace std;

class Ui
{
private:
	Service ser;

	void printMenu();

	void addUi();

	void printAll();

public:
	Ui(Service ser);

	void start();
};