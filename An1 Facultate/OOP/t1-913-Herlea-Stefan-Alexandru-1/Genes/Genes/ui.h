#pragma once

#include "service.h"

class Ui
{
private:

	Service& ser;

	void printMenu();

	void addUi();

	void removeUi();

	void printUi();

	void filterUi();

	void commonUi();

public:

	Ui(Service& ser);

	void start();
};