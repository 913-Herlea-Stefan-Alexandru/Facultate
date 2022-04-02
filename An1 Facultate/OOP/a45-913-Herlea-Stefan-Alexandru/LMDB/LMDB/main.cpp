#include <iostream>
#include "movie.h"
#include "movieRepo.h"
#include "admin_service.h"
#include "user_service.h"
#include "admin_ui.h"
#include "user_ui.h"
#include "tests.h"
#include <string>

using namespace std;

int main()
{
	Tests tests;
	//tests.run_all();
	MovieRepo database;
	MovieRepo watch_list;
	MovieRepo filter;
	tests.repo_init(database);
	AdminService a_service(database);
	UserService u_service(database, watch_list, filter);
	Admin_ui au(a_service);
	UserUi uu(u_service);

	bool is_running = true;

	std::string command;

	while (is_running)
	{
		std::cout << "\n1. Admin mode\n";
		std::cout << "2. User mode\n";
		std::cout << "0. Exit\n";
		std::cout << ">> ";

		std::cin >> command;
		system("cls");
		if (command == "1")
			au.start();
		else if (command == "2")
			uu.start();
		else if (command == "0")
			is_running = false;
		else
			std::cout << "\nInvalid command\n";
	}
	return 0;
}
