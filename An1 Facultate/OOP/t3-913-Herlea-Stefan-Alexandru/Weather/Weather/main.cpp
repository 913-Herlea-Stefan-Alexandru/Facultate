#include <QtWidgets/QApplication>
#include "Gui.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Repository repo("Weather.txt");

	Service ser(repo);

	Gui ui(ser);

	ui.show();

	return a.exec();
}