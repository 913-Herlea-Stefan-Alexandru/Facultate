#define _CRT_SECURE_NO_WARNINGS

#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "service.h"
#include "repo.h"

void print_menu()
{
	printf("\nMenu\n");
	printf("1. Add an estate\n");
	printf("2. Remove an estate\n");
	printf("3. Update an estate\n");
	printf("4. Show all estates\n");
	printf("5. Filter\n");
	printf("6. Undo\n");
	printf("7. Redo\n");
	printf("0. Exit\n");
	printf(">> ");
}

void print_filter_menu()
{
	printf("\nFilter\n");
	printf("1. Filter by address\n");
	printf("2. Filter by surface (ascending price)\n");
	printf("3. Filter by type and larger than surface\n");
	printf("0. Back\n");
	printf(">> Filter >> ");
}

void add_ui(List* estate_list, List* undo_list, List* redo_list)
{
	char type[256];
	char address[256];
	char surface[256];
	char price[256];

	printf("\nEnter the type: ");
	fgets(type, 255, stdin);
	type[strlen(type) - 1] = '\0';
	printf("Enter the address: ");
	fgets(address, 255, stdin);
	address[strlen(address) - 1] = '\0';
	printf("Enter the surface: ");
	fgets(surface, 255, stdin);
	surface[strlen(surface) - 1] = '\0';
	printf("Enter the price: ");
	fgets(price, 255, stdin);
	price[strlen(price) - 1] = '\0';

	int r = add(estate_list, type, address, surface, price, undo_list, redo_list);

	if (r != 0)
	{
		if (r == 1)
		{
			printf("\nEstate with the same address already exists\n");
		}
		else if (r == -1)
		{
			printf("\nSurface/Price must be positive integers\n");
		}
		else
		{
			if (r % 2 == 0)
				printf("Type must be 'house'/'apartment'/'penthouse'\n");
			if (r % 3 == 0)
				printf("Address must not be empty\n");
			if (r % 5 == 0)
				printf("Surface must be a positive number\n");
			if (r % 7 == 0)
				printf("Price must be a positive number\n");
		}
	}
}

void remove_ui(List* estate_list, List* undo_list, List* redo_list)
{
	char address[256];

	printf("\nEnter the address of the estate you want to remove: ");
	fgets(address, 255, stdin);
	address[strlen(address) - 1] = '\0';

	int r = remove(estate_list, address, undo_list, redo_list);

	if (r == 1)
	{
		printf("Estate not found\n");
	}
}

void modify_ui(List* estate_list, List* undo_list, List* redo_list)
{
	char address[255], new_type[255], new_address[255], new_surface[255], new_price[255];

	printf("\nEnter the address of the estate you want to modify: ");
	fgets(address, 255, stdin);
	address[strlen(address)-1] = '\0';

	printf("\nEnter the type: ");
	fgets(new_type, 255, stdin);
	new_type[strlen(new_type) - 1] = '\0';
	printf("Enter the address: ");
	fgets(new_address, 255, stdin);
	new_address[strlen(new_address) - 1] = '\0';
	printf("Enter the surface: ");
	fgets(new_surface, 255, stdin);
	new_surface[strlen(new_surface) - 1] = '\0';
	printf("Enter the price: ");
	fgets(new_price, 255, stdin);
	new_price[strlen(new_price) - 1] = '\0';

	int r = update(estate_list, address, new_type, new_address, new_surface, new_price, undo_list, redo_list);

	if (r != 0)
	{
		if (r == 1)
		{
			printf("\nEstate with given address not found\n");
		}
		else if (r == -1)
		{
			printf("\nSurface/Price must be positive integers\n");
		}
		else
		{
			if (r % 2 == 0)
				printf("Type must be 'house'/'apartment'/'penthouse'\n");
			if (r % 3 == 0)
				printf("Address must not be empty\n");
			if (r % 5 == 0)
				printf("Surface must be a positive number\n");
			if (r % 7 == 0)
				printf("Price must be a positive number\n");
		}
	}
}

void print_estate(Estate* est)
{
	char* type = get_type(est);
	char* address = get_address(est);
	int surface = get_surface(est);
	int price = get_price(est);

	printf("\nTYPE: %s; ADDRESS: %s; SURFACE: %d; PRICE: %d\n", type, address, surface, price);

	free(type);
	free(address);
}

void print_all_ui(List* estate_list)
{
	int size = get_size(estate_list);
	void** list = get_list(estate_list);

	for (int i = 0; i < size; i++)
	{
		print_estate(list[i]);
	}

	destroy_list_of_estates(list, size);
}

void filter_address_ui(List* estate_list)
{
	char string[255];

	printf("Enter the string to filter by: ");
	fgets(string, 255, stdin);
	string[strlen(string)-1] = '\0';

	List* new_list = filter_by_address(estate_list, string);

	print_all_ui(new_list);
	destroy_repo(new_list);
}

void filter_surface_ascending_price_ui(List* estate_list)
{
	char surface[255];

	printf("Enter the surface to filter by: ");
	fgets(surface, 255, stdin);
	surface[strlen(surface) - 1] = '\0';

	List* new_list = filter_by_surface(estate_list, surface);

	if (new_list == NULL)
	{
		printf("\nThe surface must be a positive number!\n");
		return;
	}

	sort_ascending_price(new_list);

	print_all_ui(new_list);
	destroy_repo(new_list);
}

void filter_type_surface(List* estate_list)
{
	char type[255];

	printf("Enter the type to filter by: ");
	fgets(type, 255, stdin);
	type[strlen(type) - 1] = '\0';

	char surface[255];

	printf("Enter the surface to filter by: ");
	fgets(surface, 255, stdin);
	surface[strlen(surface) - 1] = '\0';

	List* new_list = filter_by_type_surface(estate_list, type, surface);

	if (new_list == NULL)
	{
		printf("\nThe type must be house/apartment/penthouse!\n");
		return;
	}

	printf("\n1. Sort ascending\n");
	printf("2. Sort descending\n");
	printf(": ");

	char choice[255];
	fgets(choice, 255, stdin);
	choice[strlen(choice) - 1] = '\0';

	if (strlen(choice) == 1)
	{
		if (choice[0] == '1')
		{
			sort_ascending_surface(new_list);
		}
		else if (choice[0] == '2')
		{
			sort_descending_surface(new_list);
		}
		else
		{
			printf("\nInvalid imput\n");
			return;
		}
	}
	else
	{
		printf("\nInvalid imput\n");
		return;
	}

	print_all_ui(new_list);
	destroy_repo(new_list);
}

void filter(List* estate_list)
{
	int is_filtering = 1;

	while (is_filtering == 1)
	{
		print_filter_menu();
		
		char* command_f = (char*)malloc(255 * sizeof(char));
		fgets(command_f, 255, stdin);
		command_f[strlen(command_f) - 1] = '\0';

		if (strlen(command_f) == 1)
		{
			if (command_f[0] == '1')
			{
				filter_address_ui(estate_list);
			}
			else if (command_f[0] == '2')
			{
				filter_surface_ascending_price_ui(estate_list);
			}
			else if (command_f[0] == '3')
			{
				filter_type_surface(estate_list);
			}
			else if (command_f[0] == '0')
			{
				is_filtering = 0;
			}
			else
			{
				printf("\nInvalid imput\n");
			}
		}
		else
		{
			printf("\nInvalid imput\n");
		}
		free(command_f);
	}
}

void undo_ui(List** estate_list, List* undo_list, List* redo_list)
{
	int err = undo(undo_list, estate_list, redo_list);
	if (err == 1)
	{
		printf("\nNothing to undo\n");
		return;
	}
}

void redo_ui(List** estate_list, List* undo_list, List* redo_list)
{
	int err = redo(undo_list, estate_list, redo_list);
	if (err == 1)
	{
		printf("\nNothing to redo\n");
		return;
	}
}

void start(List** estate_list, List* undo_list, List* redo_list)
{
	int is_running = 1;

	while (is_running == 1)
	{
		print_menu();

		char* command = (char*)malloc(255 * sizeof(char));
		fgets(command, 255, stdin);
		command[strlen(command)-1] = '\0';

		if (strlen(command) == 1)
		{
			if (command[0] == '1')
			{
				add_ui(*estate_list, undo_list, redo_list);
			}
			else if (command[0] == '2')
			{
				remove_ui(*estate_list, undo_list, redo_list);
			}
			else if (command[0] == '3')
			{
				modify_ui(*estate_list, undo_list, redo_list);
			}
			else if (command[0] == '4')
			{
				print_all_ui(*estate_list);
			}
			else if (command[0] == '5')
			{
				filter(*estate_list);
			}
			else if (command[0] == '6')
			{
				undo_ui(estate_list, undo_list, redo_list);
			}
			else if (command[0] == '7')
			{
				redo_ui(estate_list, undo_list, redo_list);
			}
			else if (command[0] == '0')
			{
				is_running = 0;
			}
			else
			{
				printf("\nInvalid imput\n");
			}
		}
		else
		{
			printf("\nInvalid imput\n");
		}
		free(command);
	}
}
