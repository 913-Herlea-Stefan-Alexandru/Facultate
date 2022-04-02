//
// Created by User on 20/06/2021.
//

#include <fstream>
#include <algorithm>
#include "Repository_User.h"

void Repository_User::read_all_from_file_user() {
    std::ifstream f(this->file_name);
    if(f.is_open())
    {
        this->users.clear();
        User user;
        while(f >> user)
        {
            this->users.push_back(user);
        }
        f.close();
    }
}

void Repository_User::write_all_to_file_user() {
    std::ofstream f(this->file_name);
    if(f.is_open())
    {
        std::for_each(this->users.begin(), this->users.end(), [&f](const auto& users){f << users << "\n";});
        f.close();
    }
}

Repository_User::Repository_User(string file_name): file_name(file_name) {read_all_from_file_user();}

std::vector<User>& Repository_User::get_users() {
    read_all_from_file_user();
    return this->users;
}

int Repository_User::len_repository_users() {
    read_all_from_file_user();
    return this->users.size();
}

User *Repository_User::get_all_users_array() {

    this->read_all_from_file_user();
    auto* users_array= new User[this->users.size()];
    for(int index=0; index<this->users.size(); index++)
        users_array[index]= this->users.at(index);
    return users_array;


}
