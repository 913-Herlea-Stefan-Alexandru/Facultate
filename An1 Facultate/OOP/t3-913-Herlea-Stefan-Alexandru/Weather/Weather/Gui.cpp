#include "Gui.h"

Gui::Gui(Service& ser) : ser{ ser }
{
	this->currentList = this->ser.getAll();
	for (auto m : this->currentList)
	{
		this->listOfDesc.insert(m.getDesc());
	}
	this->init();
	this->connections();
	this->fillTable(this->currentList);
}

Gui::~Gui()
{

}

void Gui::init()
{
	this->setWindowTitle("Weather");

	//create the main layout
	this->layout = new QHBoxLayout(this);

	//create the left side layout
	QWidget* leftSideWidget = new QWidget();
	QVBoxLayout* leftSideLayout = new QVBoxLayout(leftSideWidget);

	//create the table and add it to the left side layout
	this->table = new QListWidget();
	leftSideLayout->addWidget(this->table);

	//add the left side layout to the main layout
	this->layout->addWidget(leftSideWidget);

	//create the right side layout
	QWidget* rightSideWidget = new QWidget();
	QVBoxLayout* rightSideLayout = new QVBoxLayout(rightSideWidget);

	this->slider = new QSlider(Qt::Horizontal, 0);
	this->slider->setValue(100);
	this->val = new QLineEdit(QString::fromStdString(to_string(this->slider->value())));
	this->val->setReadOnly(true);
	rightSideLayout->addWidget(this->slider);
	rightSideLayout->addWidget(val);

	//create the filter layout
	QWidget* filterWidget = new QWidget();
	QFormLayout* filterLayout = new QFormLayout(filterWidget);

	for (string s : this->listOfDesc)
	{
		QLabel* l = new QLabel(QString::fromStdString(s));
		this->labels.push_back(l);
		QCheckBox* c = new QCheckBox(l);
		c->setChecked(true);
		l->setBuddy(c);
		this->cehckBoxes.push_back(c);
		filterLayout->addRow(l, c);
	}

	//add the filter layout to the right side layout
	rightSideLayout->addWidget(filterWidget);

	this->ref = new QPushButton("Refresh");
	rightSideLayout->addWidget(ref);

	//add the right side layout to the main layout
	this->layout->addWidget(rightSideWidget);

	//this->dialog = new QDialog(this);
}

void Gui::connections()
{
	connect(this->slider, &QSlider::valueChanged, this, &Gui::value);
	for (auto c : this->cehckBoxes)
	{
		connect(c, &QCheckBox::stateChanged, [this, c]() { this->filterCheckBox(c); });
	}
	connect(this->ref, &QPushButton::clicked, this, &Gui::refresh);
}

void Gui::fillTable(vector<Weather> list)
{
	//set the size and the header of the table
	this->table->clear();

	for (auto& m : list)
	{
		//create a table item for each object
		QListWidgetItem* f1 = new QListWidgetItem(QString::fromStdString(to_string(m.getStart()) + ";" + to_string(m.getEnd()) + ";" + to_string(m.getPp()) + ";" + m.getDesc()), this->table);
	}

	this->table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

void Gui::value(int k)
{
	this->val->setText(QString::fromStdString(to_string(this->slider->value())));
	this->currentList = this->ser.filterPp(to_string(this->slider->value()));
	this->fillTable(this->currentList);
}

void Gui::filterCheckBox(QCheckBox* c)
{
	if (c->isChecked())
	{
		string s;
		int i = 0;
		for (auto s2 : this->listOfDesc)
		{
			if (this->cehckBoxes[i] == c)
			{
				s = s2;
				break;
			}
			i++;
		}
		this->currentList = this->ser.filterDesc(s);
		this->fillTable(this->currentList);
	}
}

void Gui::refresh()
{
	for (auto c : this->cehckBoxes)
	{
		c->setChecked(true);
	}
	this->slider->setValue(100);
}
