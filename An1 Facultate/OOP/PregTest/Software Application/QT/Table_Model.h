//
// Created by User on 20/06/2021.
//

#ifndef STAR_CATALOGUE_STARS_TABLE_MODEL_H
#define STAR_CATALOGUE_STARS_TABLE_MODEL_H


#include <qabstractitemmodel.h>
#include "Repositories/Repository_Issue.h"
#include "Repositories/Repository_User.h"


class Table_Model: public QAbstractTableModel
{
private:
    Repository_Issue& repository_issue;

public:
    explicit Table_Model(Repository_Issue& repository_issue, QObject* parent = NULL): repository_issue{repository_issue}, QAbstractTableModel{parent} {};

    ~Table_Model();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    void update_internal_data();
};

#endif //STAR_CATALOGUE_STARS_TABLE_MODEL_H
