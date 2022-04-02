#pragma once

#include "user_service.h"

class UserUi
{
private:

	UserService& service;

	void printMenu();

	void printLookMenu();

	void seeMoviesGenre();

	void printList();

	void deleteFromList();

public:

	UserUi(UserService& service);

	void start();
};