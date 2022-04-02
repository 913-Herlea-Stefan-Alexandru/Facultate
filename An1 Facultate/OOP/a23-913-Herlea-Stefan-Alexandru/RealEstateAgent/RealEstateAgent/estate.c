#define _CRT_SECURE_NO_WARNINGS

#include "estate.h"
#include <string.h>

Estate* create_estate(char* type, char* address, int surface, int price)
{
    Estate* est = (Estate*)malloc(sizeof(Estate));

    est->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy(est->type, type);
    est->address = (char*)malloc(sizeof(char) * (strlen(address) + 1));
    strcpy(est->address, address);
    est->surface = surface;
    est->price = price;

    return est;
}

char* get_type(Estate* est)
{
    char* type = (char*)malloc(sizeof(char) * (strlen(est->type) + 1));
    strcpy(type, est->type);
    return type;
}

char* get_address(Estate* est)
{
    char* address = (char*)malloc(sizeof(char) * (strlen(est->address) + 1));
    strcpy(address, est->address);
    return address;
}

int get_surface(Estate* est)
{
    return est->surface;
}

int get_price(Estate* est)
{
    return est->price;
}

void set_type(Estate* est, char* type)
{
    free(est->type);
    est->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy(est->type, type);
}

void set_address(Estate* est, char* address)
{
    free(est->address);
    est->address = (char*)malloc(sizeof(char) * (strlen(address) + 1));
    strcpy(est->address, address);
}

void set_surface(Estate* est, int surface)
{
    est->surface = surface;
}

void set_price(Estate* est, int price)
{
    est->price = price;
}

Estate* copy_estate(Estate* est)
{
    Estate* new_est = create_estate(est->type, est->address, est->surface, est->price);
    return new_est;
}

void destroy_est(Estate* est)
{
    free(est->type);
    free(est->address);
    free(est);
}
