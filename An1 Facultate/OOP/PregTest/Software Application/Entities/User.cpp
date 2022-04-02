//
// Created by User on 20/06/2021.
//

#include "User.h"

User::User(string user_name, string user_type): user_name(user_name), user_type(user_type) {}

bool User::operator==(const User &user) {
    return this->user_name == user.user_name;
}

void User::operator=(const User &user) {
    this->user_name=user.user_name;
    this->user_type=user.user_type;
}

istream& operator>>(istream &is, User &user) {
    is >> user.user_name >>user.user_type;
    return is;
}

ostream &operator<<(ostream &os, const User &user) {
    os << user.user_name << " " << user.user_type;
    return os;
}

