//
// Created by User on 20/06/2021.
//

#ifndef STAR_CATALOGUE_ASTRONOMER_H
#define STAR_CATALOGUE_ASTRONOMER_H

#include<string>
#include<iostream>
#include<istream>

using namespace std;

class User{

private:

    string user_name;
    string user_type;

public:
    User()=default;
    User(string user_name, string user_type);

    string get_user_name(){return this->user_name;};
    string get_user_type(){return this->user_type;};
    void set_user_name(string new_user_name){ this->user_name=new_user_name;};
    void set_user_type(string new_user_type){ this->user_type=new_user_type;};

    friend std::istream& operator>>(std::istream &is, User &user);
    friend std::ostream& operator<<(std::ostream &os, const User &user);
    bool operator==(const User &user);
    void operator=(const User &user);


};

#endif //STAR_CATALOGUE_ASTRONOMER_H
