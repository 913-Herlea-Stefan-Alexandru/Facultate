#include "redo_repo.h"
#include <string.h>

List* create_redo_repo()
{
	List* redo_list = (List*)malloc(sizeof(List));
	redo_list->list = (List**)malloc(sizeof(List*) * 5);
	redo_list->size = 0;
	redo_list->space = 5;
}

void expand_redo_list(List* redo_list)
{
	List** new_list = (List**)malloc(sizeof(List*) * (redo_list->space * 2));

	for (int i = 0; i < redo_list->size; i++)
	{
		new_list[i] = redo_list->list[i];
	}

	free(redo_list->list);

	redo_list->list = new_list;
	redo_list->space *= 2;
}

void reduce_redo_list(List* redo_list)
{
	List** new_list = (List**)malloc(sizeof(List*) * (redo_list->space / 2));

	for (int i = 0; i < redo_list->size; i++)
	{
		new_list[i] = redo_list->list[i];
	}

	free(redo_list->list);

	redo_list->list = new_list;
	redo_list->space /= 2;
}

void add_repo_redo(List* redo_list, List* repo)
{
	if (redo_list->size == redo_list->space)
	{
		expand_undo_list(redo_list);
	}

	redo_list->list[redo_list->size] = copy_repo(repo);
	redo_list->size++;
}

List* remove_repo_redo(List* redo_list)
{
	if (redo_list->size == 0)
	{
		return NULL;
	}

	List* ret_val = copy_repo(redo_list->list[redo_list->size - 1]);
	destroy_repo(redo_list->list[redo_list->size - 1]);
	redo_list->size--;

	if (redo_list->space > 5 && redo_list->size == redo_list->space / 2)
	{
		reduce_undo_list(redo_list);
	}

	return ret_val;
}

void empty_redo_repo(List* redo_list)
{
	while (redo_list->size > 0)
	{
		List* r = remove_repo_redo(redo_list);
		destroy_repo(r);
	}
}

void destroy_redo_repo(List* redo_list)
{
	for (int i = 0; i < redo_list->size; i++)
	{
		destroy_repo(redo_list->list[i]);
	}
	free(redo_list->list);
	free(redo_list);
}
