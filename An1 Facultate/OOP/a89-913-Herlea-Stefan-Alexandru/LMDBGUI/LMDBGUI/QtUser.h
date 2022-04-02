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
#include "user_service.h"

class QtUser : public QWidget
{
	Q_OBJECT

public:
	QtUser(UserService& user);
	~QtUser();

private:

	UserService& user;
	QTableWidget* table;
	QPushButton* addMovie;
	QPushButton* removeMovie;
	QPushButton* nextMovie;
	QPushButton* viewTrailer;
	QPushButton* filterButton;
	QLineEdit* filter;
	QLineEdit* currentMovie;
	QDialog* dialog;

	void init();

	void makeConnections();

	void populateTable();

	void filterF();

	void add();

	void next();

	void remove();

	void liked();

	void disliked();

	void trailer();
};

