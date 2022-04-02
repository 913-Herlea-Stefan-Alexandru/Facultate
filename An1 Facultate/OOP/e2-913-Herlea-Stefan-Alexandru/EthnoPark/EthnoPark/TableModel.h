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
#include "Service.h"

static class TableModel : public QAbstractTableModel
{
	Q_OBJECT

private:

	Service& user;

public:

	TableModel(Service& user, QObject* parent = nullptr) : user{ user }, QAbstractTableModel(parent)
	{
	}
	~TableModel() {}

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override
	{
		return this->user.getBuildings().size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex{}) const override
	{
		return 4;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		int row = index.row();
		int column = index.column();

		vector<Building> buildings = this->user.getBuildings();

		Building m = buildings[row];

		if (role == 99)
		{
			return index.siblingAtColumn(0).data();
		}
		if (role == 100)
		{
			return index.siblingAtColumn(1).data();
		}
		if (role == Qt::DisplayRole || role == Qt::EditRole)
		{
			switch (column)
			{
			case 0:
				return QString::fromStdString(to_string(m.getId()));
			case 1:
				return QString::fromStdString(m.getDescription());
			case 2:
				return QString::fromStdString(m.getArea());
			default:
				break;
			}
			if (column == 3)
			{
				string str = "";
				for (auto& loc : m.getLocation())
				{
					str += loc + ";";
				}
				return QString::fromStdString(str);
			}
		}
		if (role == Qt::FontRole)
		{
			QFont font("Times", 15, 10, true);
			font.setItalic(false);
			return font;
		}

		return QVariant();
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		if (role == Qt::DisplayRole)
		{
			if (orientation == Qt::Horizontal)
			{
				switch (section)
				{
				case 0:
					return QString{ "Id" };
				case 1:
					return QString{ "Description" };
				case 2:
					return QString{ "Thematic Sector" };
				case 3:
					return QString{ "Location" };
				default:
					break;
				}
			}
		}
		if (role == Qt::FontRole)
		{
			QFont font("Times", 15, 10, true);
			font.setBold(true);
			font.setItalic(false);
			return font;
		}

		return QVariant{};
	}

	bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override
	{
		beginInsertRows(parent, row, row + count - 1);
		endInsertRows();
		return true;
	}

	bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override
	{
		beginRemoveRows(parent, row, row + count - 1);
		endRemoveRows();
		return true;
	}

	Qt::ItemFlags flags(const QModelIndex& index) const override
	{
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	}

};
