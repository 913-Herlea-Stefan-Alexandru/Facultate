//
// Created by User on 20/06/2021.
//

#ifndef STAR_CATALOGUE_REPOSITORY_ASTRONOMER_H
#define STAR_CATALOGUE_REPOSITORY_ASTRONOMER_H

#include <vector>
#include "Observer.h"
#include "../Entities/User.h"


class Repository_User: public Observable
{
private:

    void read_all_from_file_user();
    void write_all_to_file_user();
    std::string file_name;
    std::vector<User> users;

public:

    explicit Repository_User(string file_name);
    int len_repository_users();
    std::vector<User>& get_users();

    User* get_all_users_array();

};


#endif //STAR_CATALOGUE_REPOSITORY_ASTRONOMER_H
