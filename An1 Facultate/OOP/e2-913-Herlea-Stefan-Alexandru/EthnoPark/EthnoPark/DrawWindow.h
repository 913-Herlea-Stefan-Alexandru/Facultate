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
#include <map>
#include <tuple>

class DrawWindow : public QWidget
{
	Q_OBJECT

public:

	DrawWindow(Service& ser);

private:

	Service& ser;
	map<string, int> m;

	QHBoxLayout* layout;

	QTableWidget* table;

	void init();

	void fillTable();
};

