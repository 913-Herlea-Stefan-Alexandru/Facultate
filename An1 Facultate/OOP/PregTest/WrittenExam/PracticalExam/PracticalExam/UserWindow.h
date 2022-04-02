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
#include "UserRepository.h"
#include "Service.h"
#include "TableModel.h"

class UserWindow : public QWidget
{
	Q_OBJECT
public:

	UserWindow(User& user, Service& service, TableModel* tableModel);
	~UserWindow();

private:

	User& user;
	Service& service;

	QHBoxLayout* layout;

	QLineEdit* desc;
	QPushButton* add;

	QPushButton* solve;

	QPushButton* remove;

	TableModel* tableModel;
	QTableView* UserWindow::tableView;

	void init();

	void connections();

	void addIssue();

	void removeIssue();

	void getSolved();

	void solveIssue();

};

