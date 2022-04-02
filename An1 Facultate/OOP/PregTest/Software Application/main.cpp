#include <iostream>
#include "Repositories/Repository_Issue.h"
#include "Repositories/Repository_User.h"

//#include "Table_Model.h"
#include "QApplication"
#include <vector>
#include <QT/User_Window.h>
#include <QT/Table_Model.h>


int main(int argc, char** argv) {


    QApplication a(argc,argv);

    Repository_User repository_user("../users.txt");
    Repository_Issue repository_issues("../issues.txt");

//    auto* model= new Table_Model{repository_issues};
    auto* users=repository_user.get_all_users_array();
    vector<User_Window*> users_windows;

    //auto* model= new Table_Model{repository_issues};


    for(int i=0; i < repository_user.len_repository_users(); i++)
        users_windows.push_back(new User_Window(users[i], repository_issues));

    return a.exec();

}
