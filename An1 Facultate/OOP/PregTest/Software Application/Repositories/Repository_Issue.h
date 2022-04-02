//
// Created by User on 20/06/2021.
//

#ifndef STAR_CATALOGUE_REPOSITORY_STAR_H
#define STAR_CATALOGUE_REPOSITORY_STAR_H

#include <vector>
#include <Observer.h>
#include "../Entities/Issue.h"


class Repository_Issue: public Observable
{
private:

    void clear_all();
    void read_all_from_file_issue();
    void write_all_to_file_issue();
    std::string file_name;
    std::vector<Issue> issues;

public:

    explicit Repository_Issue(string file_name);
    //~Repository_Issue() { this->clear_all(); this->write_all_to_file_star();};

    int len_repository_issues();
    std::vector<Issue>& get_issues();

    Issue* get_all_issues_array();



    //param: the issue that will be added
    //return: this function returns a boolean function: if there is already an issue with the same description
    //it will return false, without adding this issue
    //otherwise, it will return true
    bool add_issue_repository(Issue issue);

    //param: the description of the issue that has to be updated and the new issue
    //because description cannot be changed, the only attribute that will be updated are status reporter and solver

    void update_issue_repository(string description, Issue new_issue);
    bool remove_issue_repository(string description);
};



#endif //STAR_CATALOGUE_REPOSITORY_STAR_H
