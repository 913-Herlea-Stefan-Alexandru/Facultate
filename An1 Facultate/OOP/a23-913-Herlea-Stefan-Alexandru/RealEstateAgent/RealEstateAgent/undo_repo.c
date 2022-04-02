#include "undo_repo.h"
#include <string.h>

List* create_undo_repo()
{
	List* undo_list = (List*)malloc(sizeof(List));
	undo_list->list = (List**)malloc(sizeof(List*) * 5);
	undo_list->size = 0;
	undo_list->space = 5;
}

void expand_undo_list(List* undo_list)
{
	List** new_list = (List**)malloc(sizeof(List*) * (undo_list->space * 2));

	for (int i = 0; i < undo_list->size; i++)
	{
		new_list[i] = undo_list->list[i];
	}

	free(undo_list->list);

	undo_list->list = new_list;
	undo_list->space *= 2;
}

void reduce_undo_list(List* undo_list)
{
	List** new_list = (List**)malloc(sizeof(List*) * (undo_list->space / 2));

	for (int i = 0; i < undo_list->size; i++)
	{
		new_list[i] = undo_list->list[i];
	}

	free(undo_list->list);

	undo_list->list = new_list;
	undo_list->space /= 2;
}

void add_repo_undo(List* undo_list, List* repo)
{
	if (undo_list->size == undo_list->space)
	{
		expand_undo_list(undo_list);
	}

	undo_list->list[undo_list->size] = copy_repo(repo);
	undo_list->size++;
}

List* remove_repo_undo(List* undo_list)
{
	if (undo_list->size == 0)
	{
		return NULL;
	}

	List* ret_val = copy_repo(undo_list->list[undo_list->size - 1]);
	destroy_repo(undo_list->list[undo_list->size - 1]);
	undo_list->size--;

	if (undo_list->space > 5 && undo_list->size == undo_list->space / 2)
	{
		reduce_undo_list(undo_list);
	}

	return ret_val;
}

void destroy_undo_repo(List* undo_list)
{
	for (int i = 0; i < undo_list->size; i++)
	{
		destroy_repo(undo_list->list[i]);
	}
	free(undo_list->list);
	free(undo_list);
}