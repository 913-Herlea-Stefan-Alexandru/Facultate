#include "ui.h"

void Ui::printMenu()
{
	cout << "\nMenu\n";
	cout << "1. Add measurement\n";
	cout << "2. Print all\n";
	cout << "3. Is healthy?\n";
	cout << "4. Save to file\n";
	cout << "0. Exit\n";
	cout << ">> ";
}

void Ui::addUi()
{
	string command;
	while (true)
	{
		cout << "\n1. BMI\n";
		cout << "2. BP\n";
		cout << ">> ";
		cin >> command;

		if (command == "1")
		{
			string date, value;
			cout << "Enter the date: ";
			cin >> date;
			cout << "Enter the value: ";
			cin >> value;
			if (this->ser.addBMI(date, value))
			{
				cout << "\nNormal values\n";
			}
			else
			{
				cout << "\nNot normal values\n";
			}
			break;
		}
		else if (command == "2")
		{
			string date, s, d;
			cout << "Enter the date: ";
			cin >> date;
			cout << "Enter the systolicValue: ";
			cin >> s;
			cout << "Enter the diastolicValue: ";
			cin >> d;
			if (this->ser.addBP(date, s, d))
			{
				cout << "\nNormal values\n";
			}
			else
			{
				cout << "\nNot normal values\n";
			}
			break;
		}
		else
		{
			cout << "\nInvlaid command\n";
		}
	}
}

void Ui::printAll()
{
	this->ser.dysplayAll();
}

Ui::Ui(Service ser) : ser{ser}
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
		
		if (command == "1")
		{
			this->addUi();
		}
		else if (command == "2")
		{
			this->printAll();
		}
		else if (command == "3")
		{

		}
		else if (command == "4")
		{

		}
		else if (command == "0")
		{
			isRunning = false;
		}
		else
		{
			cout << "\nInvalid input\n";
		}
	}
}
