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
		return this->user.getIssueList().size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex{}) const override
	{
		return 4;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		int row = index.row();
		int column = index.column();

		vector<Issue> movies = this->user.getIssueList();

		Issue m = movies[row];

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
				return QString::fromStdString(m.description);
			case 1:
				return QString::fromStdString(m.status);
			case 2:
				return QString::fromStdString(m.reporter);
			case 3:
				return QString::fromStdString(m.solver);
			default:
				break;
			}
		}
		if (role == Qt::FontRole)
		{
			QFont font("Times", 15, 10, true);
			font.setItalic(false);
			return font;
		}
		if (role == Qt::BackgroundRole)
		{
			if (row % 2 == 1)
			{
				return QBrush{ QColor{0, 100, 250} };
			}
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
					return QString{ "Description" };
				case 1:
					return QString{ "Status" };
				case 2:
					return QString{ "Reporter" };
				case 3:
					return QString{ "Solver" };
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
