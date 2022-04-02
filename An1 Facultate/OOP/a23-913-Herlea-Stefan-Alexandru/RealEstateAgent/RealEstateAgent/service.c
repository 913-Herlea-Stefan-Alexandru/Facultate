#include "service.h"
#include "estate.h"
#include "undo_repo.h"
#include "redo_repo.h"
#include "estate_validator.h"
#include "integer_validator.h"
#include <string.h>

int add(List* estate_list, char* type, char* address, char* surface, char* price, List* undo_list, List* redo_list)
{
	int err = 0;

	err = validate_int(surface);
	err = validate_int(price);

	if (err == -1)
	{
		return err;
	}

	int surface_i = atoi(surface);
	int price_i = atoi(price);

	Estate* est = create_estate(type, address, surface_i, price_i);

	err = estate_validator(est);

	if (err != 0)
	{
		destroy_est(est);
		return err;
	}

	add_repo_undo(undo_list, estate_list);
	err = add_estate(estate_list, est);

	if (err == 1)
	{
		destroy_est(est);
		remove_repo_undo(undo_list);
	}
	else
	{
		empty_redo_repo(redo_list);
	}
		
	return err;
}

int remove(List* estate_list, char* address, List* undo_list, List* redo_list)
{
	Estate* est = get_by_address(estate_list, address);

	if (est == NULL)
	{
		return 1;
	}

	add_repo_undo(undo_list, estate_list);
	remove_estate(estate_list, est);
	empty_redo_repo(redo_list);

	return 0;
}

int update(List* estate_list, char* address, char* new_type, char* new_address, char* new_surface, char* new_price, List* undo_list, List* redo_list)
{
	int err = 0;

	err = validate_int(new_surface);
	err = validate_int(new_price);

	if (err == -1)
	{
		return err;
	}

	int surface_i = atoi(new_surface);
	int price_i = atoi(new_price);

	Estate* est = get_by_address(estate_list, address);

	if (est == NULL)
	{
		return 1;
	}

	Estate* new_e = create_estate(new_type, new_address, surface_i, price_i);

	err = estate_validator(new_e);

	if (err != 0)
	{
		destroy_est(new_e);
		return err;
	}

	destroy_est(new_e);

	add_repo_undo(undo_list, estate_list);
	empty_redo_repo(redo_list);

	set_type(est, new_type);
	set_address(est, new_address);
	set_surface(est, surface_i);
	set_price(est, price_i);

	return 0;
}

List* filter_by_address(List* estate_list, char* string)
{
	int size = get_size(estate_list);
	void** list = get_list(estate_list);
	char* address;

	List* new_estate_list = create_repo();

	for (int i = 0; i < size; i++)
	{
		address = get_address(list[i]);
		if (strstr(address, string) != NULL)
		{
			add_estate(new_estate_list, copy_estate(list[i]));
		}
		free(address);
	}

	destroy_list_of_estates(list, size);

	return new_estate_list;
}

List* filter_by_surface(List* estate_list, char* surface)
{
	int err = validate_int(surface);

	if (err == -1)
	{
		return NULL;
	}

	int surface_i = atoi(surface);

	int size = get_size(estate_list);
	void** list = get_list(estate_list);
	int srf;

	List* new_estate_list = create_repo();

	for (int i = 0; i < size; i++)
	{
		srf = get_surface(list[i]);
		if (srf == surface_i)
		{
			add_estate(new_estate_list, copy_estate(list[i]));
		}
	}

	destroy_list_of_estates(list, size);

	return new_estate_list;
}

List* filter_by_type_surface(List* estate_list, char* type, char* surface)
{
	if (strcmp(type, "house") != 0 && strcmp(type, "apartment") != 0 && strcmp(type, "penthouse") != 0)
	{
		return NULL;
	}

	int err = validate_int(surface);

	if (err == -1)
	{
		return NULL;
	}

	int surface_i = atoi(surface);

	int size = get_size(estate_list);
	void** list = get_list(estate_list);
	char* typ;
	int srf;

	List* new_estate_list = create_repo();

	for (int i = 0; i < size; i++)
	{
		typ = get_type(list[i]);
		srf = get_surface(list[i]);
		if (strcmp(typ, type) == NULL && srf > surface_i)
		{
			add_estate(new_estate_list, copy_estate(list[i]));
		}
		free(typ);
	}

	destroy_list_of_estates(list, size);

	return new_estate_list;
}

void sort_ascending_surface(List* estate_list)
{
	sort_asc_surface(estate_list);
}

void sort_descending_surface(List* estate_list)
{
	sort_desc_surface(estate_list);
}

void sort_ascending_price(List* estate_list)
{
	sort_asc_price(estate_list);
}

int undo(List* undo_list, List** estate_list, List* redo_list)
{
	List* previous = remove_repo_undo(undo_list);
	if (previous == NULL)
	{
		return 1;
	}

	add_repo_redo(redo_list, *estate_list);
	destroy_repo(*estate_list);
	*estate_list = previous;
	return 0;
}

int redo(List* undo_list, List** estate_list, List* redo_list)
{
	List* next = remove_repo_redo(redo_list);
	if (next == NULL)
	{
		return 1;
	}

	add_repo_undo(undo_list, *estate_list);
	destroy_repo(*estate_list);
	*estate_list = next;
	return 0;
}
