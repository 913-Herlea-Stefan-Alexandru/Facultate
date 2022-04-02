#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "tests.h"
#include "ui.h"
#include "repo.h"
#include "undo_repo.h"
#include "redo_repo.h"

int main()
{
	//test_all();
	List* estate_list = create_repo();
	List* undo_list = create_undo_repo();
	List* redo_list = create_redo_repo();
	repo_init(estate_list);
	start(&estate_list, undo_list, redo_list);
	destroy_repo(estate_list);
	destroy_undo_repo(undo_list);
	destroy_redo_repo(redo_list);
	return 0;
}