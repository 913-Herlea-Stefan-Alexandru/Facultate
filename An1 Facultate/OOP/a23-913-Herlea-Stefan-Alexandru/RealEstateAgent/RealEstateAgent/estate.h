#pragma once

typedef struct
{
	char* type;
	char* address;
	int surface;
	int price;
} Estate;

//returns an estate with the given properties
Estate* create_estate(char*, char*, int, int);

//returns the type of the given estate
char* get_type(Estate*);

//returns the address of the given estate
char* get_address(Estate*);

//returns the surface of the given estate
int get_surface(Estate*);

//returns the price of the given estate
int get_price(Estate*);

//modifies the type of a given estate with a given type
void set_type(Estate*, char*);

//modifies the address of a given estate with a given address
void set_address(Estate*, char*);

//modifies the surface of a given estate with a given surface
void set_surface(Estate*, int);

//modifies the price of a given estate with a given price
void set_price(Estate*, int);

Estate* copy_estate(Estate*);

//destroys the given estate by freeing the memory
void destroy_est(Estate*);