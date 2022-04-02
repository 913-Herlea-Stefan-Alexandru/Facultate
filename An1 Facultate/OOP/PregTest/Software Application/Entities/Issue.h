//
// Created by User on 20/06/2021.
//

#ifndef STAR_CATALOGUE_STAR_H
#define STAR_CATALOGUE_STAR_H

#include<string>
#include<iostream>
#include<istream>

using namespace std;

class Issue{

private:

    string issue_description;
    string issue_status;
    string issue_reporter;
    string issue_solver;

public:
    Issue()=default;
    Issue(string issue_description,string issue_status,string issue_reporter,string issue_solver);

    string get_issue_description(){return this->issue_description;};
    string get_issue_status(){return this->issue_status;};
    string get_issue_reporter(){return this->issue_reporter;};
    string get_issue_solver(){return this->issue_solver;};


    void set_issue_description(string new_issue_description){this->issue_description=new_issue_description;};
    void set_issue_status(string new_issue_status){this->issue_status=new_issue_status;};
    void set_issue_reporter(string new_issue_reporter){this->issue_reporter=new_issue_reporter;};
    void set_issue_solver(string new_issue_solver){this->issue_solver=new_issue_solver;};

    friend std::istream& operator>>(std::istream &is, Issue &issue);
    friend std::ostream& operator<<(std::ostream &os, const Issue &issue);
    bool operator==(const Issue &issue);
    void operator=(const Issue &issue);


};

#endif //STAR_CATALOGUE_STAR_H
