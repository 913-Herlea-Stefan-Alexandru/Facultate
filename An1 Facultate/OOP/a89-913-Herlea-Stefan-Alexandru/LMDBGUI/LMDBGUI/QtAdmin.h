#pragma once
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include "admin_service.h"

class QtAdmin : public QWidget
{
	Q_OBJECT

public:
	QtAdmin(AdminService& admin);
	~QtAdmin();

private:

	AdminService& admin;
	QTableWidget* table;
	QPushButton* addMovie;
	QPushButton* removeMovie;
	QPushButton* updateMovie;
	QLineEdit* title;
	QLineEdit* genre;
	QLineEdit* year;
	QLineEdit* likes;
	QLineEdit* link;

	void init();

	void makeConnections();

	void populateTable();

	void add();

	void remove();

	void update();

	void loadDetails();
};

