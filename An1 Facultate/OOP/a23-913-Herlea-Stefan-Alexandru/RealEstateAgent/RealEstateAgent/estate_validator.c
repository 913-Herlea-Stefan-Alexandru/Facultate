#include "estate_validator.h"
#include <string.h>

int check_type(char* type)
{
	if (strcmp(type, "house") != 0 && strcmp(type, "apartment") != 0 && strcmp(type, "penthouse") != 0)
		return 1;
	return 0;
}

int check_address(char* address)
{
	if (strlen(address) == 0)
		return 1;
	return 0;
}

int check_surface(int surface)
{
	if (surface <= 0)
		return 1;
	return 0;
}

int check_price(int price)
{
	if (price <= 0)
		return 1;
	return 0;
}

int estate_validator(Estate* est)
{
	int res = 1;

	char* type = get_type(est);
	char* address = get_address(est);
	int surface = get_surface(est);
	int price = get_price(est);

	if (check_type(type) == 1)
	{
		res *= 2;
	}
	if (check_address(address) == 1)
	{
		res *= 3;
	}
	if (check_surface(surface) == 1)
	{
		res *= 5;
	}
	if (check_price(price) == 1)
	{
		res *= 7;
	}

	free(type);
	free(address);

	if (res == 1)
		return 0;
	return res;
}