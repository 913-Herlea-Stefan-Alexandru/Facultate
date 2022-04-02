#pragma once

#include "repo.h"

//creates and adds an estate with the given type, address, surface and price to the given List entity
//copies the estate list and puts it into the undo repository while deleting what is inside the redo repo
//returns the specific error code for a failed estate creation and repo addition
int add(List*, char*, char*, char*, char*, List*, List*);

//searches for and removes the estate with the given address
//copies the estate list and puts it into the undo repository while deleting what is inside the redo repo
//returns 1 if there is no estate with the given address and 0 otherwise
int remove(List*, char*, List*, List*);

//searches for and modifies the estate with the given address, changing it's address, type, surface and price
//copies the estate list and puts it into the undo repository while deleting what is inside the redo repo
//returns the specific error code for a failed estate creation
int update(List*, char*, char*, char*, char*, char*, List*, List*);

//filters the given estate list by the given string being contained in the estate's address
//returns the newly created List
List* filter_by_address(List*, char*);

//filters the given estate list by the given surface
//returns the newly created List
List* filter_by_surface(List*, char*);

//filters the given estate list by the given type, having the surface larger than the given one
//returns the newly created List
List* filter_by_type_surface(List*, char*, char*);

//sorts the given estate list ascending by the estates prices
void sort_ascending_price(List*);

//sorts the given estate list ascending by the estates surface
void sort_ascending_surface(List* estate_list);

//sorts the given estate list descending by the estates surface
void sort_descending_surface(List* estate_list);

//undos the last operation performed on the given repo
int undo(List*, List**, List*);

//redos the last undo performed on the given repo
int redo(List*, List**, List*);
