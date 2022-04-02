#include "user_ui.h"
#include <iostream>

void UserUi::printMenu()
{
	std::cout << "Menu\n";
	std::cout << "1. See movies with given genre\n";
	std::cout << "2. See watch list\n";
	std::cout << "3. Remove from watch list\n";
	std::cout << "0. Back\n";
	std::cout << ">> ";
}

void UserUi::printLookMenu()
{
	std::cout << "Search Menu\n";
	std::cout << "1. Add to watch list\n";
	std::cout << "2. Watch trailer\n";
	std::cout << "3. Continue\n";
	std::cout << "0. Back\n";
	std::cout << ">> ";
}

void UserUi::seeMoviesGenre()
{
	char genre_c[255];

	std::cout << "\nEnter the genre: ";
	cin.get();
	cin.getline(genre_c, 255);

	std::string genre(genre_c);

	service.startOver();

	if (!this->service.getGenre(genre))
	{
		cout << "\nMovies with givn genre not found\n";
		system("pause");
		return;
	}
	
	bool isLooking = true;
	std::string command;

	system("cls");

	while (isLooking)
	{
		Movie mv = this->service.getCurrent();
		std::cout << mv << "\n";

		this->printLookMenu();
		std::cin >> command;

		system("cls");

		if (command == "1")
		{
			try {
				int r = this->service.addCurrent();
			}
			catch (exception& e) {
				cout << e.what();
			}
			//if (r == 1)
			//{
			//	std::cout << "\nMovie already in watch list\n";
			//	system("pause");
			//}
		}
		else if (command == "2")
		{
			mv.runLink();
		}
		else if (command == "3")
		{
			this->service.cont();
		}
		else if (command == "0")
		{
			isLooking = false;
		}
		else
		{
			cout << "\nInvalid command\n";
		}
	}
}

void UserUi::printList()
{
	std::cout << this->service.writeWatchList();
	system("pause");
}

void UserUi::deleteFromList()
{
	char title_c[255];
	std::string like;

	std::cout << "\nEnter the title: ";
	cin.get();
	cin.getline(title_c, 255);
	
	std::string title(title_c);

	std::cout << "\nDid you enjoy the movie?[y/n]: ";
	std::cin >> like;

	try {
		int r = this->service.remove(title, like);
	}
	catch (exception& e) {
		cout << e.what();
	}

	//if (r == 1)
	//	std::cout << "\nInvalid title\n";
	//if (r == 2)
	//	std::cout << "\nInvalid answer\n";
	system("pause");
}

UserUi::UserUi(UserService& service) : service{service}
{

}

void UserUi::start()
{
	bool isRuning = true;

	std::string command;

	while (isRuning)
	{
		this->printMenu();
		std::cin >> command;

		system("cls");
		
		if (command == "1")
		{
			this->seeMoviesGenre();
			system("cls");
		}
		else if (command == "2")
		{
			this->printList();
			system("cls");
		}
		else if (command == "3")
		{
			this->deleteFromList();
			system("cls");
		}
		else if (command == "0")
		{
			isRuning = false;
		}
		else 
		{
			cout << "\nInvalid command\n";
		}
	}
}
