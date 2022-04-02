#pragma once
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QDialog>
#include <QSlider>
#include <set>
#include <QCheckBox>
//#include <QtWidgets/QMainWindow>
#include "Service.h"

class Gui : public QWidget
{
	Q_OBJECT

public:

	Gui(Service& ser);
	~Gui();

private:

	vector<Weather> currentList;
	set<string> listOfDesc;
	Service& ser;

	QHBoxLayout* layout;
	QListWidget* table;

	QSlider* slider;
	QLineEdit* val;

	QPushButton* ref;

	vector<QLabel*> labels;
	vector<QCheckBox*> cehckBoxes;

	void init();

	void connections();

	void fillTable(vector<Weather> list);

	void value(int k);

	void filterCheckBox(QCheckBox* c);

	void refresh();
};

