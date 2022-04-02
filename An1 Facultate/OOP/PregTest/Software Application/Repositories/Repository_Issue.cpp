//
// Created by User on 20/06/2021.
//

#include "Repository_Issue.h"


#include <fstream>
#include <algorithm>


void Repository_Issue::read_all_from_file_issue() {
    std::ifstream f(this->file_name);
    if(f.is_open())
    {
        this->issues.clear();
        Issue issue;
        while(f >> issue)
        {
            this->issues.push_back(issue);
        }
        f.close();
    }
}

void Repository_Issue::write_all_to_file_issue() {
    std::ofstream f(this->file_name);
    if(f.is_open())
    {
        std::for_each(this->issues.begin(), this->issues.end(), [&f](const auto& issue){f << issue << "\n";});
        f.close();
    }
}

Repository_Issue::Repository_Issue(string file_name): file_name(file_name) {read_all_from_file_issue();}

std::vector<Issue>& Repository_Issue::get_issues() {
    //read_all_from_file_star();
    return this->issues;

}

int Repository_Issue::len_repository_issues() {
    read_all_from_file_issue();
    return this->issues.size();
}

bool Repository_Issue::add_issue_repository(Issue issue) {
    this->read_all_from_file_issue();
    for(int i=0; i<this->len_repository_issues(); i++)
    {
        if(issues[i].get_issue_description() == issue.get_issue_description())
            return false;
    }
    this->issues.push_back(issue);
    write_all_to_file_issue();
    this->notify();
    return true;
}

Issue *Repository_Issue::get_all_issues_array() {
    this->read_all_from_file_issue();
    auto* issues_array= new Issue[this->issues.size()];
    for(int index=0; index<this->issues.size(); index++)
        issues_array[index]= this->issues.at(index);
    return issues_array;
}

void Repository_Issue::update_issue_repository(string description, Issue new_issue) {
    this->read_all_from_file_issue();
    int i;
    for(i=0; i<this->len_repository_issues(); i++)
    {
        if(this->issues.at(i).get_issue_description() == description)
        {
            this->issues.at(i)=new_issue;
            break;
        }
    }

    this->write_all_to_file_issue();
    this->notify();

}

void Repository_Issue::clear_all() {
    this->issues.clear();
}

bool Repository_Issue::remove_issue_repository(string description) {
    this->read_all_from_file_issue();
    for(int i=0; i<this->issues.size(); i++)
    {
        if(this->issues[i].get_issue_description()==description)
        {

            this->issues.erase(this->issues.begin()+i);
//            this->issues[i]=this->issues[this->len_repository_issues()-1];
//            this->issues.pop_back();

            this->write_all_to_file_issue();
            this->notify();
            return true;
        }
    }
    return false;
}
