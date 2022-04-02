//
// Created by User on 21/06/2021.
//

#include <QMessageBox>
#include "User_Window.h"
#include "Table_Model.h"

User_Window::User_Window(User user, Repository_Issue &repository_issue,QWidget *parent): user(user), repository_issues(repository_issue),QWidget(parent)
{
    this->repository_issues.add_observer(this);
    this->init_gui();
    this->connect();
    this->show();

}


void User_Window::init_gui() {

    //Title window
    string user=this->user.get_user_name();
    string type=this->user.get_user_type();
    string final;
    final= final.append(user);
    final+=" - ";
    final=final.append(type);
    this->setWindowTitle(QString::fromStdString(final));

    this->resize(600,500);
    this->main_layout=new QVBoxLayout{this};

    this->model=new Table_Model(this->repository_issues);
    this->issues_table_view=new QTableView();

    this->filtered_model_description_status= new QSortFilterProxyModel();
    this->filtered_model_description_status->setSourceModel(this->model);

    //this->issues_table_view->setSortingEnabled(true);
    //this->filtered_model_description_status->sort(0,Qt::AscendingOrder);
    //this->filtered_model_description_status->sort(1,Qt::AscendingOrder);

    this->issues_table_view->setModel(this->filtered_model_description_status);
    this->main_layout->addWidget(this->issues_table_view);


    this->remove_issue_button=new QPushButton{"Remove Issue"};
    this->main_layout->addWidget(this->remove_issue_button);


    this->issue_details=new QFormLayout();

    this->description_line=new QLineEdit();
    this->status_line=new QLineEdit();
    this->reporter_line=new QLineEdit();
    this->solver_line=new QLineEdit();

    this->issue_details->addRow("Description: ",this->description_line);
    this->issue_details->addRow("Status: ", this->status_line);
    this->issue_details->addRow("Reporter: ", this->reporter_line);
    this->issue_details->addRow("Solver: ", this->solver_line);

    this->main_layout->addLayout(this->issue_details);


    this->resolve_issue_button=new QPushButton{"Resolve Issue"};
    this->main_layout->addWidget(this->resolve_issue_button);

    this->add_issue_button=new QPushButton{"Add Issue"};
    this->main_layout->addWidget(this->add_issue_button);

    if(this->user.get_user_type()=="programmer")
    {
        this->add_issue_button->hide();

    }
    else
    {
        this->resolve_issue_button->hide();


    }

}

void User_Window::connect() {

    QObject::connect(this->issues_table_view->selectionModel(),&QItemSelectionModel::selectionChanged, this,  &User_Window::selected_issue_gui);
    QObject::connect(this->remove_issue_button, &QPushButton::clicked, this, &User_Window::remove_issue_gui);
    QObject::connect(this->add_issue_button,&QPushButton::clicked, this, &User_Window::add_issue_gui);
    QObject::connect(this->resolve_issue_button,&QPushButton::clicked, this, &User_Window::resolve_issue_gui);

}

int User_Window::get_selected_index() {

    QModelIndexList selectedIndexes = this->issues_table_view->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

void User_Window::remove_issue_gui() {

    string status=this->status_line->text().toStdString();
    string description=this->description_line->text().toStdString();


    if(status=="open")
    {
        QMessageBox::critical(this, "Error", "This issue cannot be removed because it is not closed!");
        return;
    }
    if(!this->repository_issues.remove_issue_repository(description))
    {
        QMessageBox::critical(this, "Error", "This issue doesn't exist!");
        return;
    }

}

void User_Window::notify_model() {
//    Table_Model* new_model=new Table_Model(this->repository_issues);
    this->model->update_internal_data();
//    this->model=new_model;
//    this->issues_table_view->setModel(this->model);
}

void User_Window::update() {
    this->notify_model();

}

User_Window::~User_Window() {
    this->repository_issues.remove_observer(this);
}

void User_Window::selected_issue_gui() {

    setEnabled(this->resolve_issue_button);
    int index = this->get_selected_index();
    string description = this->model->index(index, 0).data().toString().toStdString();
    string status = this->model->index(index, 1).data().toString().toStdString();
    string reporter = this->model->index(index, 2).data().toString().toStdString();
    string solver = this->model->index(index, 3).data().toString().toStdString();

    this->description_line->setText(QString::fromStdString(description));
    this->status_line->setText(QString::fromStdString(status));
    this->reporter_line->setText(QString::fromStdString(reporter));
    this->solver_line->setText(QString::fromStdString(solver));


}

void User_Window::add_issue_gui() {

    string description=this->description_line->text().toStdString();
    string reporter=this->user.get_user_name();
    if(description.empty())
    {
        QMessageBox::critical(this, "Error", "Invalid description!");
        return;
    }
    string solver="-";
    string status="open";
    Issue issue{description,status,reporter,solver};
    if(!this->repository_issues.add_issue_repository(issue))
    {
        QMessageBox::critical(this, "Error", "There is already an issue with this description");
        return;
    }
//    this->notify_model();
}

void User_Window::resolve_issue_gui() {

    int index = this->get_selected_index();
    string description = this->model->index(index, 0).data().toString().toStdString();
    string status = this->model->index(index, 1).data().toString().toStdString();
    string reporter = this->model->index(index, 2).data().toString().toStdString();
    string solver = this->model->index(index, 3).data().toString().toStdString();


    Issue issue{description,status,reporter,solver};
    issue.set_issue_solver(this->user.get_user_name());
    issue.set_issue_status("closed");
    this->repository_issues.update_issue_repository(description,issue);

}



