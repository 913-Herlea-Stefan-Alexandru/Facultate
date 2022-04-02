#include <QtWidgets/QApplication>
#include "Gui.h"
#include "FileRepo.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	//Repository repo;
	Repository* repo;
	repo = new FileRepo("Model.txt");

	Service ser(*repo);

	Gui ui(ser);

	ui.show();

	return a.exec();
}