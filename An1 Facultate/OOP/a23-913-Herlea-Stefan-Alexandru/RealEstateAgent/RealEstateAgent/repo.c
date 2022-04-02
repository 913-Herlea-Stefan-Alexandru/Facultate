#include "repo.h"
#include <string.h>

List* create_repo()
{
	List* estate_list = (List*)malloc(sizeof(List));
	estate_list->list = (Estate**)malloc(sizeof(Estate*) * 5);
	estate_list->size = 0;
	estate_list->space = 5;
}

Estate* get_by_address(List* estate_list, char* address)
{
	char* address_e;
	for (int i = 0; i < estate_list->size; i++)
	{
		address_e = get_address(estate_list->list[i]);
		if (strcmp(address_e, address) == 0)
		{
			free(address_e);
			return estate_list->list[i];
		}
		free(address_e);
	}
	return NULL;
}

void expand_list(List* estate_list)
{
	Estate** new_list = (Estate**)malloc(sizeof(Estate*) * (estate_list->space * 2));

	for (int i = 0; i < estate_list->size; i++)
	{
		new_list[i] = estate_list->list[i];
	}

	free(estate_list->list);

	estate_list->list = new_list;
	estate_list->space *= 2;
}

void reduce_list(List* estate_list)
{
	Estate** new_list = (Estate**)malloc(sizeof(Estate*) * (estate_list->space / 2));

	for (int i = 0; i < estate_list->size; i++)
	{
		new_list[i] = estate_list->list[i];
	}

	free(estate_list->list);

	estate_list->list = new_list;
	estate_list->space /= 2;
}

int add_estate(List* estate_list, Estate* est)
{
	char* address_e;
	for (int i = 0; i < estate_list->size; i++)
	{
		address_e = get_address(estate_list->list[i]);
		if (strcmp(address_e, est->address) == 0)
		{
			free(address_e);
			return 1;
		}
		free(address_e);
	}

	if (estate_list->size == estate_list->space)
	{
		expand_list(estate_list);
	}

	estate_list->list[estate_list->size] = est;
	estate_list->size++;

	return 0;
}

void remove_estate(List* estate_list, Estate* est)
{
	char* address_e;
	int pos = 0;
	for (int i = 0; i < estate_list->size; i++)
	{
		address_e = get_address(estate_list->list[i]);
		if (strcmp(address_e, est->address) == 0)
		{
			free(address_e);
			pos = i;
			break;
		}
		free(address_e);
	}

	for (int i = pos; i < estate_list->size - 1; i++)
	{
		estate_list->list[i] = estate_list->list[i + 1];
	}

	estate_list->size--;

	if (estate_list->space != 5 && estate_list->size == estate_list->space / 2)
	{
		reduce_list(estate_list);
	}

	destroy_est(est);
}

int get_size(List* estate_list)
{
	return estate_list->size;
}

void** get_list(List* estate_list)
{
	void** new_list = (Estate**)malloc(sizeof(Estate*) * estate_list->size);

	for (int i = 0; i < estate_list->size; i++)
	{
		new_list[i] = copy_estate(estate_list->list[i]);
	}

	return new_list;
}

List* copy_repo(List* estate_list)
{
	List* new_repo = create_repo();

	for (int i = 0; i < estate_list->size; i++)
	{
		add_estate(new_repo, copy_estate(estate_list->list[i]));
	}

	return new_repo;
}

void sort_asc_surface(List* estate_list)
{
	for (int i = 0; i < estate_list->size - 1; i++)
	{
		for (int j = i + 1; j < estate_list->size; j++)
		{
			int surface_i = get_surface(estate_list->list[i]);
			int surface_j = get_surface(estate_list->list[j]);

			if (surface_i > surface_j)
			{
				Estate* est = estate_list->list[i];
				estate_list->list[i] = estate_list->list[j];
				estate_list->list[j] = est;
			}
		}
	}
}

void sort_desc_surface(List* estate_list)
{
	for (int i = 0; i < estate_list->size - 1; i++)
	{
		for (int j = i + 1; j < estate_list->size; j++)
		{
			int surface_i = get_surface(estate_list->list[i]);
			int surface_j = get_surface(estate_list->list[j]);

			if (surface_i < surface_j)
			{
				Estate* est = estate_list->list[i];
				estate_list->list[i] = estate_list->list[j];
				estate_list->list[j] = est;
			}
		}
	}
}

void sort_asc_price(List* estate_list)
{
	for (int i = 0; i < estate_list->size - 1; i++)
	{
		for (int j = i + 1; j < estate_list->size; j++)
		{
			int price_i = get_price(estate_list->list[i]);
			int price_j = get_price(estate_list->list[j]);

			if (price_i > price_j)
			{
				Estate* est = estate_list->list[i];
				estate_list->list[i] = estate_list->list[j];
				estate_list->list[j] = est;
			}
		}
	}
}

void destroy_list_of_estates(void** list, int size)
{
	for (int i = 0; i < size; i++)
	{
		destroy_est(list[i]);
	}
	free(list);
}

void destroy_repo(List* estate_list)
{
	for (int i = 0; i < estate_list->size; i++)
		destroy_est(estate_list->list[i]);
	free(estate_list->list);
	free(estate_list);
}
