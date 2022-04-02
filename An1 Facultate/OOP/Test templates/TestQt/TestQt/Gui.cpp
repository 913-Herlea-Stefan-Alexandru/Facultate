#include "Gui.h"

Gui::Gui(Service& ser) : ser{ ser }
{
	this->init();
	this->connections();
	this->fillTable(this->ser.getAll());
}

Gui::~Gui()
{

}

void Gui::init()
{
	this->setWindowTitle("Test");

	//create the main layout
	this->layout = new QHBoxLayout(this);

	//create the left side layout
	QWidget* leftSideWidget = new QWidget();
	QVBoxLayout* leftSideLayout = new QVBoxLayout(leftSideWidget);

		//create the table and add it to the left side layout
		this->table = new QTableWidget();
		leftSideLayout->addWidget(this->table);

		//create the layout for the sort buttons
		QWidget* buttonsSortWidget = new QWidget();
		QHBoxLayout* buttonsSortLayout = new QHBoxLayout(buttonsSortWidget);

			//create the sort buttons
			this->sortField1 = new QPushButton("Sort field 1");
			this->sortField2 = new QPushButton("Sort field 2");
			this->sortField3 = new QPushButton("Sort field 3");
			this->sortField4 = new QPushButton("Sort field 4");
			
			//add the sort buttons to the sort buttons layout
			buttonsSortLayout->addWidget(this->sortField1);
			buttonsSortLayout->addWidget(this->sortField2);
			buttonsSortLayout->addWidget(this->sortField3);
			buttonsSortLayout->addWidget(this->sortField4);

		//add the sort buttons layout to the left side layout
		leftSideLayout->addWidget(buttonsSortWidget);

	//add the left side layout to the main layout
	this->layout->addWidget(leftSideWidget);

	//create the right side layout
	QWidget* rightSideWidget = new QWidget();
	QVBoxLayout* rightSideLayout = new QVBoxLayout(rightSideWidget);

		//create the form layout for the entities
		QWidget* formWidget = new QWidget();
		QFormLayout* formLayout = new QFormLayout(formWidget);

				//create the fields of the form
				this->field1 = new QLineEdit();
				QLabel* field1Label = new QLabel("&Field 1");
				this->field2 = new QLineEdit();
				QLabel* field2Label = new QLabel("&Field 2");
				this->field3 = new QLineEdit();
				QLabel* field3Label = new QLabel("&Field 3");
				this->field4 = new QLineEdit();
				QLabel* field4Label = new QLabel("&Field 4");

				field1Label->setBuddy(this->field1);
				field2Label->setBuddy(this->field2);
				field3Label->setBuddy(this->field3);
				field4Label->setBuddy(this->field4);

			//add the fields to the form layout
			formLayout->addRow(field1Label, this->field1);
			formLayout->addRow(field2Label, this->field2);
			formLayout->addRow(field3Label, this->field3);
			formLayout->addRow(field4Label, this->field4);

		//add the form layout to the right side layout
		rightSideLayout->addWidget(formWidget);

		//create the layout for the add, remove, update buttons
		QWidget* buttonsWidget = new QWidget();
		QHBoxLayout* buttonsLayout = new QHBoxLayout(buttonsWidget);

			//create the buttons for add, remove, update
			this->add = new QPushButton("Add");
			this->remove = new QPushButton("Remove");
			//this->update = new QPushButton("Update");

			//add the buttons to the buttons layout
			buttonsLayout->addWidget(this->add);
			buttonsLayout->addWidget(this->remove);
			//buttonsLayout->addWidget(this->update);

		//add the buttons layout to the right side layout
		rightSideLayout->addWidget(buttonsWidget);

		//create the filter layout
		QWidget* filterWidget = new QWidget();
		QVBoxLayout* filterLayout = new QVBoxLayout(filterWidget);

			//create the buttons and the line edits for the filters
			this->field1Filter = new QLineEdit();
			this->field2Filter = new QLineEdit();
			this->field3Filter = new QLineEdit();
			this->field4Filter = new QLineEdit();
			this->filterField1 = new QPushButton("Filter field 1");
			this->filterField2 = new QPushButton("Filter field 2");
			this->filterField3 = new QPushButton("Filter field 3");
			this->filterField4 = new QPushButton("Filter field 4");

			//add the line edits and the filter buttons to the filter layout
			filterLayout->addWidget(this->field1Filter);
			filterLayout->addWidget(this->filterField1);
			filterLayout->addWidget(this->field2Filter);
			filterLayout->addWidget(this->filterField2);
			filterLayout->addWidget(this->field3Filter);
			filterLayout->addWidget(this->filterField3);
			filterLayout->addWidget(this->field4Filter);
			filterLayout->addWidget(this->filterField4);

		//add the filter layout to the right side layout
		rightSideLayout->addWidget(filterWidget);

	//add the right side layout to the main layout
	this->layout->addWidget(rightSideWidget);

	//this->dialog = new QDialog(this);
}

void Gui::connections()
{
	//create the connections for the add, remove and update buttons
	QObject::connect(this->add, &QPushButton::clicked, [=]() { this->addFunction(); });
	QObject::connect(this->remove, &QPushButton::clicked, [=]() { this->removeFunction(); });
	//QObject::connect(this->update, &QPushButton::clicked, [=]() { this->updateFunction(); });

	//create the sort buttons connections
	QObject::connect(this->sortField1, &QPushButton::clicked, [=]() { this->fillTable(this->ser.sortF1()); });
	QObject::connect(this->sortField2, &QPushButton::clicked, [=]() { this->fillTable(this->ser.sortF2()); });
	QObject::connect(this->sortField3, &QPushButton::clicked, [=]() { this->fillTable(this->ser.sortF3()); });
	QObject::connect(this->sortField4, &QPushButton::clicked, [=]() { this->fillTable(this->ser.sortF4()); });

	//create the filter buttons connections
	QObject::connect(this->filterField1, &QPushButton::clicked, [=]() { try { this->fillTable(this->ser.filterF1(this->field1Filter->text().toStdString())); } catch (...) {} });
	QObject::connect(this->filterField2, &QPushButton::clicked, [=]() { try { this->fillTable(this->ser.filterF2(this->field2Filter->text().toStdString())); } catch (...) {} });
	QObject::connect(this->filterField3, &QPushButton::clicked, [=]() { try { this->fillTable(this->ser.filterF3(this->field3Filter->text().toStdString())); } catch (...) {} });
	QObject::connect(this->filterField4, &QPushButton::clicked, [=]() { try { this->fillTable(this->ser.filterF4(this->field4Filter->text().toStdString())); }  catch (...) {}});

	//create the connection to show the selected entry in the form
	QObject::connect(this->table, &QTableWidget::itemSelectionChanged, [=]() { this->loadDetails(); });

	QObject::connect(this->table, &QTableWidget::doubleClicked, [=]() { this->previousItem = this->table->item(this->table->currentRow(), 0)->text();  });
	QObject::connect(this->table, &QTableWidget::itemChanged, [=]() { this->updateFunction();  });
}

void Gui::fillTable(vector<Model> list)
{
	//set the size and the header of the table
	this->table->clear();
	this->table->setColumnCount(4);
	this->table->setRowCount(list.size());
	this->table->setHorizontalHeaderLabels({ "Field 1", "Field 2", "Field 3", "Field 4"});
	int currentRow = 0;

	for (auto& m : list)
	{
		//set the background row color to alternate between green and white
		QBrush* col;
		if (currentRow % 2 == 0)
			col = new QBrush(Qt::green);
		else
			col = new QBrush(Qt::white);

		//create a table item for each object
		QTableWidgetItem* f1 = new QTableWidgetItem(QString::fromStdString(m.getField1()));
		f1->setBackground(*col);
		this->table->setItem(currentRow, 0, f1);

		QTableWidgetItem* f2 = new QTableWidgetItem(QString::fromStdString(m.getField2()));
		f2->setBackground(*col);
		this->table->setItem(currentRow, 1, f2);

		QTableWidgetItem* f3 = new QTableWidgetItem(QString::fromStdString(std::to_string(m.getField3())));
		f3->setBackground(*col);
		this->table->setItem(currentRow, 2, f3);

		QTableWidgetItem* f4 = new QTableWidgetItem(QString::fromStdString(std::to_string(m.getField4())));
		f4->setBackground(*col);
		this->table->setItem(currentRow, 3, f4);

		currentRow++;
	}

	this->table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

void Gui::loadDetails()
{
	if (this->table->selectedItems().isEmpty())
	{
		//sets the form fields to be empty if there is no item selected
		this->field1->setText("");
		this->field2->setText("");
		this->field3->setText("");
		this->field4->setText("");
	}
	else
	{
		//sets the form fields to the values of the item selected in the table
		QTableWidgetItem* item = this->table->item(this->table->currentRow(), 0);
		this->field1->setText(item->text());
		item = this->table->item(this->table->currentRow(), 1);
		this->field2->setText(item->text());
		item = this->table->item(this->table->currentRow(), 2);
		this->field3->setText(item->text());
		item = this->table->item(this->table->currentRow(), 3);
		this->field4->setText(item->text());
	}
}

void Gui::addFunction()
{
	//get the information from the form
	string f1 = this->field1->text().toStdString();
	string f2 = this->field2->text().toStdString();
	string f3 = this->field3->text().toStdString();
	string f4 = this->field4->text().toStdString();

	//add it to the database
	try
	{
		this->ser.add(f1, f2, f3, f4);
		this->fillTable(this->ser.getAll());
	}
	catch (...)
	{

	}
}

void Gui::removeFunction()
{
	if (!this->table->selectedItems().isEmpty())
	{
		//removes the selected item from the list
		QTableWidgetItem* item = this->table->item(this->table->currentRow(), 0);
		try
		{
			this->ser.remove(item->text().toStdString());
			this->fillTable(this->ser.getAll());
		}
		catch (...)
		{

		}
	}
}

void Gui::updateFunction()
{
	if (!this->table->selectedItems().isEmpty())
	{
		//updates the selected item from the list
		this->table->item(0, 0)->setBackground(QBrush((0, 0, 255)));
		switch (this->table->currentColumn())
		{
		case 0:
			this->ser.update(this->previousItem.toStdString(), this->table->item(this->table->currentRow(), 0)->text().toStdString(), "", "", "");
			break;
				
		case 1:
			this->ser.update(this->previousItem.toStdString(), "", this->table->item(this->table->currentRow(), 1)->text().toStdString(), "", "");
			break;

		case 2:
			this->ser.update(this->previousItem.toStdString(), "", "", this->table->item(this->table->currentRow(), 2)->text().toStdString(), "");
			break;

		case 3:
			this->ser.update(this->previousItem.toStdString(), "", "", "", this->table->item(this->table->currentRow(), 3)->text().toStdString());
			break;
		}
	}
}
