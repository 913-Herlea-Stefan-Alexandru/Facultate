#include "ui.h"
#include <iostream>

using std::cout;
using std::cin;

void Ui::printMenu()
{
	cout << "\nMenu\n";
	cout << "1. Add gene\n";
	cout << "2. Remove gene\n";
	cout << "3. Print all genes\n";
	cout << "4. Filter sequence\n";
	cout << "5. ...\n";
	cout << "0. Exit\n";
	cout << ">> ";
}

void Ui::addUi()
{
	string organism;
	string name;
	string sequence;

	cout << "Enter organism: ";
	cin >> organism;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter sequence: ";
	cin >> sequence;

	try
	{
		this->ser.addGene(organism, name, sequence);
		cout << "\nGene added\n";
	}
	catch (RepoException ex)
	{
		cout << ex.getMessage();
	}
}

void Ui::removeUi()
{
	string organism;
	string name;

	cout << "Enter organism: ";
	cin >> organism;

	cout << "Enter name: ";
	cin >> name;

	try
	{
		this->ser.removeGene(organism, name);
		cout << "\nGene removed\n";
	}
	catch (RepoException ex)
	{
		cout << ex.getMessage();
	}
}

void Ui::printUi()
{
	cout << this->ser.readable(this->ser.getAll());
}

void Ui::filterUi()
{
	string sequence;

	cout << "Enter sequence: ";
	cin >> sequence;

	cout << this->ser.readable(this->ser.getBySeq(sequence));
}

void Ui::commonUi()
{
	string organism;
	string name;

	cout << "Enter organism: ";
	cin >> organism;

	cout << "Enter name: ";
	cin >> name;

	string organism2;
	string name2;

	cout << "Enter organism 2: ";
	cin >> organism2;

	cout << "Enter name 2: ";
	cin >> name2;


}

Ui::Ui(Service& ser) : ser{ser}
{
}

void Ui::start()
{
	bool isRunning = true;
	string command;

	while (isRunning)
	{
		this->printMenu();
		cin >> command;

		if (command.size() == 1)
		{
			switch (command[0])
			{
			case '1':
				this->addUi();
				break;
			case '2':
				this->removeUi();
				break;
			case '3':
				this->printUi();
				break;
			case '4':
				this->filterUi();
				break;
			case '5':
				this->commonUi();
				break;
			case '0':
				isRunning = false;
				break;
			default:
				cout << "\nInvalid command\n";
			}
		}
		else
			cout << "\nInvalid command\n";
	}
}
