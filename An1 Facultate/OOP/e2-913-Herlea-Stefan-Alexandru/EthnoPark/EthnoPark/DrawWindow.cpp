#include "DrawWindow.h"

#include <random>

DrawWindow::DrawWindow(Service& ser) : ser{ ser }
{
	this->init();
	this->fillTable();
}

void DrawWindow::init()
{
	this->layout = new QHBoxLayout(this);

	this->table = new QTableWidget();

	this->layout->addWidget(this->table);

	for (auto& b : this->ser.getBuildings())
	{
		m[b.getArea()] = rand() % 255;
	}
}

void DrawWindow::fillTable()
{
	this->table->clear();
	this->table->setColumnCount(6);
	this->table->setRowCount(5);
	this->table->setHorizontalHeaderLabels({ "1", "2", "3", "4" , "5", "6"});
	this->table->setVerticalHeaderLabels({ "A", "B", "C", "D" , "E"});

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			QBrush* col = nullptr;
			for (auto& b : this->ser.getBuildings())
			{
				for (auto& loc : b.getLocation())
				{
					char let = char(j + 65);
					if (loc[0] == char(j + 65) && loc[1] == char(i + 49))
					{
						col = new QBrush((m[b.getArea()], 50, 100));
					}
				}
			}
			QTableWidgetItem* f1 = new QTableWidgetItem(" ");
			if (col != nullptr)
				f1->setBackground(*col);
			this->table->setItem(i, j, f1);
		}
	}
}
