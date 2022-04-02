//
// Created by User on 21/06/2021.
//

#ifndef SOFTWARE_APPLICATION_USER_WINDOW_H
#define SOFTWARE_APPLICATION_USER_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QCheckBox>
#include <qabstractitemmodel.h>
#include <QFormLayout>
#include "Observer.h"
#include "Entities/User.h"
#include "Repositories/Repository_Issue.h"
#include "Table_Model.h"

class User_Window: public QWidget, public Observer
{
    public:
    User user;
    Repository_Issue& repository_issues;
    QVBoxLayout* main_layout;
    Table_Model* model;
    QPushButton* remove_issue_button;

    QPushButton* resolve_issue_button;
    QPushButton* add_issue_button;

    QSortFilterProxyModel* filtered_model_description_status;
    QTableView* issues_table_view;

    QFormLayout* issue_details;
    QLineEdit* description_line;
    QLineEdit* status_line;
    QLineEdit* reporter_line;
    QLineEdit* solver_line;



    User_Window(User user, Repository_Issue& repository_issue,QWidget* parent=Q_NULLPTR);
    ~User_Window();


    void init_gui();
    void connect();
    int get_selected_index();
    void notify_model();


public slots:

    void remove_issue_gui();
    void selected_issue_gui();
    void add_issue_gui();
    void resolve_issue_gui();


    void update() override;
};


#endif //SOFTWARE_APPLICATION_USER_WINDOW_H
