#pragma once

#include "repo.h"

//creates and returns a List type redo repo containing a List type array, in size and int space
List* create_redo_repo();

//adds a new estate repo to the given redo repo
void add_repo_redo(List*, List*);

//returns and removes from the given redo repo the last estate repo added
List* remove_repo_redo(List*);

//removes all entries from the redo repo
void empty_redo_repo(List*);

//frees the memory occupied by the redo repo
void destroy_redo_repo(List*);