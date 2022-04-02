#include "lecture11_demo_custom_models.h"
#include <QtWidgets/QApplication>
#include "GeneRepository.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GeneRepository repo("D:\\OOP\\OOP\\Lectures\\Lecture_10\\genes_custom_model\\Genes.txt");
	Lecture11_demo_custom_models w{ repo };
	w.show();
	return a.exec();
}
