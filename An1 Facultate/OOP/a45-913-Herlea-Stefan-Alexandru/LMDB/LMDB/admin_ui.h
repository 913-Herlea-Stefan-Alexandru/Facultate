#pragma once

#include "admin_service.h"

class Admin_ui
{
private:

	AdminService &service;

	void print_menu();

	void add_ui();

	void delete_ui();

	void update_ui();

	void print_all();

public:

	Admin_ui(AdminService &service);

	~Admin_ui();

	void start();
};