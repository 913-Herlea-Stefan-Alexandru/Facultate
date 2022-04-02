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
#include <QMessageBox>
//#include <QtWidgets/QMainWindow>
#include "EthRepo.h"
#include "Service.h"
#include "TableModel.h"
class EthWindow : public QWidget
{
	Q_OBJECT
public:

	EthWindow(Ethnologist& eth, Service& service, TableModel* tableModel);

private:

	Ethnologist& eth;
	Service& service;

	TableModel* tableModel;
	QTableView* tableView;

	QHBoxLayout* layout;

	QLineEdit* id;
	QLineEdit* desc;
	QLineEdit* loc;

	QPushButton* addButton;
	QPushButton* updateButton;

	void init();

	void connections();

	void color();

	void add();

	void update();
};

