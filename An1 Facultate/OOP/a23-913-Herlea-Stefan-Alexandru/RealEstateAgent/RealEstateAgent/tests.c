#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "tests.h"
#include <string.h>
#include <assert.h>
#include "estate.h"
#include "estate_validator.h"
#include "repo.h"
#include "undo_repo.h"
#include "redo_repo.h"
#include "service.h"

void repo_init(List* estate_list)
{
	Estate* est1 = create_estate("house", "abc 001", 21, 4536);
	Estate* est2 = create_estate("penthouse", "abc 123", 543, 231);
	Estate* est3 = create_estate("penthouse", "abc 432", 45, 643);
	Estate* est4 = create_estate("apartment", "abc 125", 231, 2341);
	Estate* est5 = create_estate("house", "abc 543", 387, 126);
	Estate* est6 = create_estate("house", "abc 321", 232, 346);
	Estate* est7 = create_estate("penthouse", "abc 876", 21, 4849);
	Estate* est8 = create_estate("apartment", "abc 743", 45, 321);
	Estate* est9 = create_estate("apartment", "abc 582", 231, 13584);
	Estate* est10 = create_estate("apartment", "abc 221", 45, 578);

	add_estate(estate_list, est1);
	add_estate(estate_list, est2);
	add_estate(estate_list, est3);
	add_estate(estate_list, est4);
	add_estate(estate_list, est5);
	add_estate(estate_list, est6);
	add_estate(estate_list, est7);
	add_estate(estate_list, est8);
	add_estate(estate_list, est9);
	add_estate(estate_list, est10);
}

void test_estate()
{
	char* type = (char*)malloc(sizeof(char) * 6);
	strcpy(type, "house\0");
	char* address = (char*)malloc(sizeof(char) * 14);
	strcpy(address, "gradinilor 39\0");
	int surface = 30, price = 20000;

	Estate* est = create_estate(type, address, surface, price);

	assert(get_surface(est) == surface);
	assert(get_price(est) == price);
	char* type_e = get_type(est);
	assert(strcmp(type_e, type) == 0);
	free(type_e);
	char* address_e = get_address(est);
	assert(strcmp(address_e, address) == 0);
	free(address_e);

	free(type);
	free(address);

	type = (char*)malloc(sizeof(char) * 10);
	strcpy(type, "apartment\0");
	address = (char*)malloc(sizeof(char) * 21);
	strcpy(address, "vasile alecsandri 21\0");
	surface = 24;
	price = 31;

	set_type(est, type);
	set_address(est, address);
	set_surface(est, surface);
	set_price(est, price);

	assert(get_surface(est) == surface);
	assert(get_price(est) == price);
	type_e = get_type(est);
	assert(strcmp(type_e, type) == 0);
	free(type_e);
	address_e = get_address(est);
	assert(strcmp(address_e, address) == 0);
	free(address_e);

	destroy_est(est);
	free(type);
	free(address);
}

void test_estate_validator()
{
	char* type = (char*)malloc(sizeof(char) * 6);
	strcpy(type, "house\0");
	char* address = (char*)malloc(sizeof(char) * 14);
	strcpy(address, "gradinilor 39\0");
	int surface = 30, price = 20000;

	Estate* est = create_estate(type, address, surface, price);
	int r = estate_validator(est);
	assert(r == 0);
	destroy_est(est);

	free(type);
	type = (char*)malloc(sizeof(char) * 6);
	strcpy(type, "egrds\0");
	
	est = create_estate(type, address, surface, price);
	r = estate_validator(est);
	assert(r == 2);
	destroy_est(est);

	free(type);
	type = (char*)malloc(sizeof(char) * 6);
	strcpy(type, "house\0");
	free(address);
	address = (char*)malloc(sizeof(char));
	strcpy(address, "");

	est = create_estate(type, address, surface, price);
	r = estate_validator(est);
	assert(r == 3);
	destroy_est(est);

	free(address);
	address = (char*)malloc(sizeof(char) * 14);
	strcpy(address, "gradinilor 39\0");
	surface = -5;
	price = -8;

	est = create_estate(type, address, surface, price);
	r = estate_validator(est);
	assert(r == 35);
	destroy_est(est);
	free(type);
	free(address);
}

void test_repo()
{
	List* estate_list = create_repo();

	char* type = (char*)malloc(sizeof(char) * 6);
	strcpy(type, "house\0");
	char* address = (char*)malloc(sizeof(char) * 14);
	strcpy(address, "gradinilor 39\0");
	int surface = 30, price = 20000;

	Estate* est1 = create_estate(type, address, surface, price);

	add_estate(estate_list, est1);
	assert(get_size(estate_list) == 1);

	Estate* est2 = create_estate("penthouse", "abc 123", 543, 231);
	Estate* est3 = create_estate("penthouse", "abc 432", 45, 321);
	Estate* est4 = create_estate("apartment", "abc 125", 231, 2341);
	Estate* est5 = create_estate("house", "abc 543", 387, 126);

	add_estate(estate_list, est2);
	add_estate(estate_list, est3);
	add_estate(estate_list, est4);
	add_estate(estate_list, est5);

	assert(get_size(estate_list) == 5);

	Estate* est_t = get_by_address(estate_list, "abc 432");

	assert(est_t == est3);

	est_t = get_by_address(estate_list, "efewf");

	assert(est_t == NULL);

	est_t = estate_list->list[3];

	assert(est_t == est4);

	remove_estate(estate_list, est_t);

	assert(get_size(estate_list) == 4);

	est_t = get_by_address(estate_list, "abc 125");

	assert(est_t == NULL);

	remove_estate(estate_list, est1);
	remove_estate(estate_list, est2);
	remove_estate(estate_list, est3);
	remove_estate(estate_list, est5);

	assert(get_size(estate_list) == 0);

	est1 = create_estate(type, address, surface, price);
	est2 = create_estate("penthouse", "abc 123", 543, 231);
	est3 = create_estate("penthouse", "abc 432", 45, 321);
	est4 = create_estate("apartment", "abc 125", 231, 2341);
	est5 = create_estate("house", "abc 543", 387, 126);
	Estate* est6 = create_estate("house", "abc 321", 232, 346);
	Estate* est7 = create_estate("penthouse", "abc 876", 21, 4849);
	Estate* est8 = create_estate("apartment", "abc 743", 24, 578);
	Estate* est9 = create_estate("apartment", "abc 582", 231, 13584);

	add_estate(estate_list, est1);
	add_estate(estate_list, est2);
	add_estate(estate_list, est3);
	add_estate(estate_list, est4);
	add_estate(estate_list, est5);
	add_estate(estate_list, est6);
	add_estate(estate_list, est7);
	add_estate(estate_list, est8);
	add_estate(estate_list, est9);

	assert(get_size(estate_list) == 9);
	assert(estate_list->space == 10);

	est_t = get_by_address(estate_list, "abc 743");

	assert(est_t == est8);

	remove_estate(estate_list, est1);
	remove_estate(estate_list, est2);
	remove_estate(estate_list, est3);
	remove_estate(estate_list, est5);

	assert(estate_list->space == 5);

	destroy_repo(estate_list);
	free(type);
	free(address);
}

void test_service()
{
	List* estate_list = create_repo();
	List* undo_list = create_undo_repo();
	List* redo_list = create_redo_repo();

	char* type = (char*)malloc(sizeof(char) * 6);
	strcpy(type, "house\0");
	char* address = (char*)malloc(sizeof(char) * 14);
	strcpy(address, "gradinilor 39\0");
	int surface = "30", price = "20000";

	int r = add(estate_list, type, address, surface, price, undo_list, redo_list);

	assert(r == 0);

	r = add(estate_list, "abc", "we", "4", "-3", undo_list, redo_list);

	assert(r == -1);

	r = add(estate_list, type, address, surface, price, undo_list, redo_list);

	assert(r == 1);

	r = remove(estate_list, "wegwe", undo_list, redo_list);

	assert(r == 1);

	r = remove(estate_list, address, undo_list, redo_list);

	assert(r == 0);

	r = add(estate_list, type, address, surface, price, undo_list, redo_list);

	assert(r == 0);

	r = update(estate_list, "feg", "house", "rwehr", "3132", "42", undo_list, redo_list);

	assert(r == 1);

	r = update(estate_list, address, "apartment", "", "-4", "23", undo_list, redo_list);

	assert(r == 15);

	r = update(estate_list, address, "apartment", "vasile 45", "43", "23", undo_list, redo_list);

	assert(r == 0);

	destroy_undo_repo(undo_list);
	destroy_redo_repo(redo_list);
	destroy_repo(estate_list);
	free(type);
	free(address);
}

void test_service2()
{
	List* estate_list = create_repo();
	List* undo_list = create_undo_repo();
	List* redo_list = create_redo_repo();

	repo_init(estate_list);

	List* new_list = filter_by_address(estate_list, "12");
	assert(new_list->size == 2);
	destroy_repo(new_list);

	new_list = filter_by_surface(estate_list, "45");
	assert(new_list->size == 3);
	destroy_repo(new_list);

	new_list = filter_by_type_surface(estate_list, "house", "100");
	assert(new_list->size == 2);
	destroy_repo(new_list);

	add(estate_list, "house", "abc 999", "231", "222", undo_list, redo_list);
	add(estate_list, "penthouse", "abc 431", "25", "24522", undo_list, redo_list);
	add(estate_list, "apartment", "abc 971", "234", "456", undo_list, redo_list);
	add(estate_list, "house", "abc 991", "332", "8643", undo_list, redo_list);

	undo(undo_list, &estate_list, redo_list);
	undo(undo_list, &estate_list, redo_list);
	undo(undo_list, &estate_list, redo_list);

	assert(estate_list->size == 11);

	redo(undo_list, &estate_list, redo_list);
	redo(undo_list, &estate_list, redo_list);

	assert(estate_list->size == 13);

	remove(estate_list, "abc 001", undo_list, redo_list);

	int r = redo(undo_list, &estate_list, redo_list);

	assert(r == 1);

	undo(undo_list, &estate_list, redo_list);

	undo(undo_list, &estate_list, redo_list);
	undo(undo_list, &estate_list, redo_list);
	undo(undo_list, &estate_list, redo_list);

	assert(estate_list->size == 10);

	r = undo(undo_list, &estate_list, redo_list);

	assert(r == 1);

	destroy_undo_repo(undo_list);
	destroy_redo_repo(redo_list);
	destroy_repo(estate_list);
}

void test_all()
{
	test_estate();
	test_estate_validator();
	test_service();
	test_service2();
	test_repo();
}
