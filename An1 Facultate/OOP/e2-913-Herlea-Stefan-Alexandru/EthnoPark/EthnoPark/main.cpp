#include <QApplication>
#include <utility>
#include <QPainter>
#include <QSortFilterProxyModel>
#include "EthRepo.h"
#include "BuildingRepo.h"
#include "Service.h"
#include "EthWindow.h"
#include "DrawWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	EthRepo eth("ethnologists.txt");
	BuildingRepo bld("buildings.txt");

	Service ser(bld);

    TableModel* tableModel = new TableModel(ser);

    vector<EthWindow*> wins;

    vector<Ethnologist> e = eth.getAll();

    for (int i = 0; i < e.size(); i++)
    {
        EthWindow* win = new EthWindow(e[i], ser, tableModel);
        wins.push_back(win);
    }

    for (auto& win : wins)
    {
        win->show();
    }

    DrawWindow dr(ser);

    dr.show();

	return a.exec();
}