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
//#include <QtWidgets/QMainWindow>
#include "Service.h"

class Gui : public QWidget
{
	Q_OBJECT

public:
	
	Gui(Service& ser);
	~Gui();

private:

	Service& ser;
	
	QHBoxLayout* layout;
	QTableWidget* table;

	//form fields
	QLineEdit* field1;
	QLineEdit* field2;
	QLineEdit* field3;
	QLineEdit* field4;

	//sort buttons
	QPushButton* sortField1;
	QPushButton* sortField2;
	QPushButton* sortField3;
	QPushButton* sortField4;

	//filter inputs
	QLineEdit* field1Filter;
	QLineEdit* field2Filter;
	QLineEdit* field3Filter;
	QLineEdit* field4Filter;

	//filter buttons
	QPushButton* filterField1;
	QPushButton* filterField2;
	QPushButton* filterField3;
	QPushButton* filterField4;

	//add, remove, update buttons
	QPushButton* add;
	QPushButton* remove;
	//QPushButton* update;

	QString previousItem;

	//QDialog* dialog;

	void init();

	void connections();

	void fillTable(vector<Model> list);

	void loadDetails();

	void addFunction();

	void removeFunction();

	void updateFunction();
};

