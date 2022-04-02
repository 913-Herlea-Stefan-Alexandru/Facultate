#include "EthWindow.h"
#include <random>

EthWindow::EthWindow(Ethnologist& eth, Service& service, TableModel* tableModel) : eth{ eth }, service{ service }, tableModel{ tableModel }
{
	this->init();
	this->connections();
}

void EthWindow::init()
{
	this->setWindowTitle(QString::fromStdString(this->eth.getName()));
	QPalette pal;

	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;

	pal.setColor(QPalette::Window, (r, g, b));
	this->setPalette(pal);

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

	QWidget* form = new QWidget();
	QFormLayout* fLayout = new QFormLayout(form);

	this->id = new QLineEdit();
	QLabel* idL = new QLabel("&Id:");
	this->desc = new QLineEdit();
	QLabel* descL = new QLabel("&Description:");
	this->loc = new QLineEdit();
	QLabel* locL = new QLabel("&Location:");

	idL->setBuddy(this->id);
	descL->setBuddy(this->desc);
	locL->setBuddy(this->loc);

	fLayout->addRow(idL, this->id);
	fLayout->addRow(descL, this->desc);
	fLayout->addRow(locL, this->loc);

	vLayout->addWidget(form);

	this->addButton = new QPushButton("Add");
	this->updateButton = new QPushButton("Update");

	vLayout->addWidget(this->addButton);
	vLayout->addWidget(this->updateButton);

	this->layout->addWidget(rightSide);
}

void EthWindow::connections()
{
	QObject::connect(this->addButton, &QPushButton::clicked, this, &EthWindow::add);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &EthWindow::update);
}

void EthWindow::color()
{
	int row = this->tableModel->rowCount();
	int col = this->tableModel->columnCount();
	for (int i = 0; i < row; i++)
	{
		QVariant content = this->tableModel->data(this->tableModel->index(i, 2), Qt::DisplayRole);
	}
}

void EthWindow::add()
{
	try
	{
		this->service.addBuilding(stoi(this->id->text().toStdString()), this->desc->text().toStdString(), this->eth.getArea(), this->loc->text().toStdString());
		this->tableModel->insertRow(this->tableModel->rowCount());
	}
	catch (exception& e)
	{
		QMessageBox msBox;
		msBox.setText(QString::fromStdString(string(e.what())));
		msBox.exec();
	}
}

void EthWindow::update()
{
	QModelIndex ind = this->tableView->currentIndex();
	try
	{
		this->service.updateBuilding(stoi(this->tableModel->data(ind, 99).toString().toStdString()), this->desc->text().toStdString(), this->loc->text().toStdString());
		this->tableModel->insertRow(this->tableModel->rowCount());
		this->tableModel->removeRow(this->tableModel->rowCount()-1);
	}
	catch (exception& e)
	{
		QMessageBox msBox;
		msBox.setText(QString::fromStdString(string(e.what())));
		msBox.exec();
	}
}
