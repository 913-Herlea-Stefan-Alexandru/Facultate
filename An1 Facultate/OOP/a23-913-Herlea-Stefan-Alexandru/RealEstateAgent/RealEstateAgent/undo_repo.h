#pragma once

#include "repo.h"

//creates and returns a List type undo repo containing a List type array, in size and int space
List* create_undo_repo();

//adds a new estate repo to the given undo repo
void add_repo_undo(List*, List*);

//returns and removes from the given undo repo the last estate repo added
List* remove_repo_undo(List*);

//frees the memory occupied by the undo repo
void destroy_undo_repo(List*);
