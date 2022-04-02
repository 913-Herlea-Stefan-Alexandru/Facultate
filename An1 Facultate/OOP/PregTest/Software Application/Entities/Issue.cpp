//
// Created by User on 20/06/2021.
//

#include "Issue.h"

Issue::Issue(string issue_description,string issue_status,string issue_reporter,string issue_solver):
issue_description(issue_description), issue_status(issue_status), issue_reporter(issue_reporter), issue_solver(issue_solver) {}

bool Issue::operator==(const Issue &issue) {
    return this->issue_description == issue.issue_description;
}

void Issue::operator=(const Issue &issue) {
    this->issue_description=issue.issue_description;
    this->issue_status=issue.issue_status;
    this->issue_reporter=issue.issue_reporter;
    this->issue_solver=issue.issue_solver;
}

std::istream &operator>>(istream &is, Issue &issue) {
    is >> issue.issue_description >> issue.issue_status >> issue.issue_reporter >> issue.issue_solver;
    return is;
}

std::ostream &operator<<(ostream &os, const Issue &issue) {
    os << issue.issue_description << " " << issue.issue_status << " " << issue.issue_reporter << " " << issue.issue_solver;
    return os;
}
