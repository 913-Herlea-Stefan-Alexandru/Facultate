
#include "ui.h"

using namespace std;

int main()
{
	string name;

	cout << "Enter the name of the person: ";
	cin >> name;

	Person person(name);
	Service ser(person);
	Ui ui(ser);
	ui.start();

	return 0;
}