#pragma once
#include "estate.h"

typedef struct
{
	void** list;
	int size;
	int space;
} List;

//creates and returns a List data structure with a capacity of 5 Estate type entities
List* create_repo();

//returns the estate (Estate type) with the given address from the given List entity
Estate* get_by_address(List*, char*);

//adds the given Estate type entity to the given List entity
//returns 1 if there is already an estate with the given address in the list and 0 otherwise
int add_estate(List*, Estate*);

//removes the given Estate type entity from the given List entity
void remove_estate(List*, Estate*);

//returns the number of elements that are currently in the given List type entity
int get_size(List*);

//returns a copy of the array of Estate type entities inside the given List type entity
void** get_list(List*);

//creates and returns a copy of the List entity given
List* copy_repo(List*);

//deallocates the memory for a given array of estates with the given size
void destroy_list_of_estates(void**, int);

//frees the memory allocated for the List entity given
void destroy_repo(List*);

//sorts the elements of the List entity given ascending by their price
void sort_asc_price(List*);

//sorts the elements of the List entity given ascending by their surface
void sort_asc_surface(List* estate_list);

//sorts the elements of the List entity given descending by their surface
void sort_desc_surface(List* estate_list);