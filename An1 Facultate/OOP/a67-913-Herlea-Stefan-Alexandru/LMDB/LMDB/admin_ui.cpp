#include <iostream>
#include "admin_ui.h"
#include <cstring>
#include <string>

using namespace std;

Admin_ui::Admin_ui(AdminService &service)
: service(service)
{
	
}

Admin_ui::~Admin_ui()
{
	
}

void Admin_ui::print_menu()
{
	cout << "\nMenu\n";
	cout << "1. Add new movie\n";
	cout << "2. Delete movie\n";
	cout << "3. Update information about a movie\n";
	cout << "4. Show all movies\n";
	cout << "0. Exit\n";
	cout << ">> ";
}

void Admin_ui::add_ui()
{
	system("cls");
	cout << "Adding\n";
	char title[255], genre[255], year[255], likes[255], link[255];

	cout << "Enter the title of the movie: ";
	cin.getline(title, 255);

	cout << "Enter the genre of the movie: ";
	cin.getline(genre, 255);

	cout << "Enter the year of the movie: ";
	cin.getline(year, 255);

	cout << "Enter the number of likes of the movie: ";
	cin.getline(likes, 255);

	cout << "Enter the link of the movie trailer: ";
	cin.getline(link, 255);

	string title_s(title);
	string genre_s(genre);
	string year_s(year);
	string likes_s(likes);
	string link_s(link);

	try {
		int r = this->service.add_movie(title_s, genre_s, year_s, likes_s, link_s);
	}
	catch (exception& e) {
		cout << e.what();
	}

	//if (r == 1)
	//{
	//	cout << "\nMovie already in the list\n";
	//}
	//if (r == 2)
	//	cout << "\nYear/likes must be integers\n";
	//if (r == 3)
	//	cout << "\nTitle can't be an empty string\n";
	//if (r == 4)
	//	cout << "\nGenre can't be an empty string\n";
	//if (r == 5)
	//	cout << "\nLink must have the format \"https://.....\"\n";

	system("pause");
}

void Admin_ui::delete_ui()
{
	system("cls");
	cout << "Deleting\n";

	char title[255];

	cout << "Enter the title of the movie: ";
	cin.getline(title, 255);

	string title_s(title);

	try {
		int r = this->service.remove_movie(title_s);
	}
	catch (exception& e) {
		cout << e.what();
	}

	//if (r == 1)
	//	cout << "\nMovie with given title not found\n";
	//if (r == 3)
	//	cout << "\nTitle can't be an empty string\n";

	system("pause");
}

void Admin_ui::update_ui()
{
	system("cls");
	cout << "Updating\n";

	char old_title[255], title[255], genre[255], year[255], likes[255], link[255];

	cout << "Enter the old title of the movie: ";
	cin.getline(old_title, 255);

	cout << "Enter the title of the movie: ";
	cin.getline(title, 255);

	cout << "Enter the genre of the movie: ";
	cin.getline(genre, 255);

	cout << "Enter the year of the movie: ";
	cin.getline(year, 255);

	cout << "Enter the number of likes of the movie: ";
	cin.getline(likes, 255);

	cout << "Enter the link of the movie trailer: ";
	cin.getline(link, 255);

	string old_title_s(old_title);
	string title_s(title);
	string genre_s(genre);
	string year_s(year);
	string likes_s(likes);
	string link_s(link);

	try {
		int r = this->service.update_movie(old_title_s, title_s, genre_s, year_s, likes_s, link_s);
	}
	catch (exception& e) {
		cout << e.what();
	}

	//if (r == 1)
	//	cout << "\nMovie not found\n";
	//if (r == 2)
	//	cout << "\nYear/likes must be integers\n";
	//if (r == 5)
	//	cout << "\nLink must have the format \"https://.....\"\n";

	system("pause");
}

void Admin_ui::print_all()
{
	system("cls");

	cout << this->service.write_list();

	system("pause");
}

void Admin_ui::start()
{
	bool is_runing = true;
	char command[255];
	
	while (is_runing)
	{
		this->print_menu();

		cin.getline(command, 255);

		if (strlen(command) == 1)
		{
			switch (command[0])
			{
			case '1':
				this->add_ui();
				break;
			case '2':
				this->delete_ui();
				break;
			case '3':
				this->update_ui();
				break;
			case '0':
				is_runing = false;
				break;
			case '4':
				this->print_all();
				break;
			default:
				cout << "\nInvalid command\n";
				system("pause");
				break;
			}
		}
		else
		{
			cout << "\nInvalid command\n";
			system("pause");
		}
		system("cls");
	}
}
