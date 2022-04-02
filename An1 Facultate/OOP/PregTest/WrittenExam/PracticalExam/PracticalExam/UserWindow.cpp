#include "UserWindow.h"

UserWindow::UserWindow(User& user, Service& service, TableModel* tableModel) : user{ user }, service{ service }, tableModel{ tableModel }
{
	this->init();
	this->connections();
}

UserWindow::~UserWindow()
{
}

void UserWindow::init()
{
	this->setWindowTitle(QString::fromStdString(this->user.name + " " + this->user.type));

	this->layout = new QHBoxLayout(this);

	QWidget* leftSide = new QWidget();
	QVBoxLayout* vLayout = new QVBoxLayout(leftSide);

	QWidget* tableViewWidget = new QWidget();
	this->tableView = new QTableView(tableViewWidget);
	this->tableView->setModel(tableModel);
	this->tableView->setSortingEnabled(true);
	this->tableView->resizeColumnsToContents();
	vLayout->addWidget(this->tableView);

	this->layout->addWidget(leftSide);

	QWidget* rightSide = new QWidget();
	vLayout = new QVBoxLayout(rightSide);

	if (user.type == "tester")
	{
		QWidget* form = new QWidget();
		QFormLayout* fLayout = new QFormLayout(form);

		this->desc = new QLineEdit();
		QLabel* descL = new QLabel("&Description:");
		descL->setBuddy(this->desc);
		fLayout->addRow(descL, this->desc);

		vLayout->addWidget(form);

		this->add = new QPushButton("Add");
		vLayout->addWidget(this->add);
	}
	else
	{
		this->solve = new QPushButton("Solve");
		this->solve->setEnabled(false);
		vLayout->addWidget(this->solve);
	}

	this->remove = new QPushButton("Remove");
	vLayout->addWidget(this->remove);

	this->layout->addWidget(rightSide);
}

void UserWindow::connections()
{
	QObject::connect(this->remove, &QPushButton::clicked, this, &UserWindow::removeIssue);
	if (this->user.type == "tester")
	{
		QObject::connect(this->add, &QPushButton::clicked, this, &UserWindow::addIssue);
	}
	else
	{
		QObject::connect(this->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &UserWindow::getSolved);
		QObject::connect(this->solve, &QPushButton::clicked, this, &UserWindow::solveIssue);
	}
}

void UserWindow::addIssue()
{
	try
	{
		this->service.addIssue(this->desc->text().toStdString(), this->user.name);
		this->tableModel->insertRow(this->tableModel->rowCount());
	}
	catch (exception& e)
	{

	}
}

void UserWindow::removeIssue()
{
	QModelIndex ind = this->tableView->currentIndex();
	try
	{
		this->service.removeIssue(this->tableModel->data(ind, 99).toString().toStdString());
		this->tableModel->removeRow(ind.row() - 1);
	}
	catch (exception& e)
	{

	}
}

void UserWindow::solveIssue()
{
	QModelIndex ind = this->tableView->currentIndex();
	this->service.solveIssue(this->tableModel->data(ind, 99).toString().toStdString(), this->user.name);
}

void UserWindow::getSolved()
{
	QModelIndex ind = this->tableView->currentIndex();
	if (this->tableModel->data(ind, 100).toString().toStdString() == "open")
	{
		this->solve->setEnabled(true);
	}
	else
	{
		this->solve->setEnabled(false);
	}
}
