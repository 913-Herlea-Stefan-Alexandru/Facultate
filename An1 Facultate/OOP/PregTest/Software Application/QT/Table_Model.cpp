//
// Created by User on 20/06/2021.
//

#include "Table_Model.h"
using namespace std;
#include <cstring>

int Table_Model::rowCount(const QModelIndex &parent) const {
    return this->repository_issue.len_repository_issues();
}

int Table_Model::columnCount(const QModelIndex &parent) const {
   return 4;

}

QVariant Table_Model::data(const QModelIndex &index, int role) const {

    int row=index.row();
    int column=index.column();
    Issue current_issue = this->repository_issue.get_issues()[row];

    if(role== Qt::DisplayRole || role== Qt::EditRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(current_issue.get_issue_description());
            case 1:
                return QString::fromStdString(current_issue.get_issue_status());
            case 2:
                return QString::fromStdString(current_issue.get_issue_reporter());
            case 3:
                return QString::fromStdString(current_issue.get_issue_solver());
            default:
                return QVariant();
        }


    }

    return QVariant();
}

QVariant Table_Model::headerData(int section, Qt::Orientation orientation, int role) const {


    if(role== Qt::DisplayRole || role == Qt::EditRole ) {

        if(orientation==Qt::Horizontal)
        {
            switch(section)
            {
                case 0:
                    return QString("Description");
                case 1:
                    return QString("Status");
                case 2:
                    return QString("Reporter");
                case 3:
                    return QString("Solver");
                default:
                    break;
            }
        }
    }

    return QVariant();
}

bool Table_Model::setData(const QModelIndex &index, const QVariant &value, int role) {

    if(role!=Qt::EditRole)
       return false;
   int row=index.row();
   int column=index.column();

   Issue current_issue = this->repository_issue.get_issues()[row];

   switch (column)
   {
       case 0:
           break;
       case 1:
       {
           string status{value.toString().toStdString()};
           current_issue.set_issue_status(status);
           this->repository_issue.update_issue_repository(current_issue.get_issue_description(),current_issue);
           break;
       }

       case 2:
           break;

       case 3:
           break;

       case 4:
           break;

       default:
           break;
   }

   emit dataChanged(index,index);
   return true;
}

Qt::ItemFlags Table_Model::flags(const QModelIndex &index) const {

    if(index.column()==0)
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void Table_Model::update_internal_data() {
    endResetModel();
}

Table_Model::~Table_Model() {

}
