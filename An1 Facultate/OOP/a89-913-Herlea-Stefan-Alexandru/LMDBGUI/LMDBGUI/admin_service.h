#pragma once
#include <string>
#include "movieRepo.h"
#include "validator.h"

using namespace std;

class AdminService
{
private:

	MovieRepo &repo;
	Validator val;

public:

	//the constructor of the admin service class
	//it passes the given repo to this class's instance of a repo
	AdminService(MovieRepo &repo);

	//the destructor of the class
	~AdminService();

	//adds a movie with a given title(string), genre(string), year(int), likes(int) and link(string) to the current repo
	int add_movie(string title, string genre, string year, string likes, string link);

	//deletes a movie with the given title(string) from the current repo
	int remove_movie(string title);

	//updates the movie with the given title(string) from the current repo with the given new_title(string), 
	//new_genre(string), new_year(int), new_likes(int) and new_link(string)
	//if any of those fields contain an empty string, then the program doesn't change the coresponding variable
	int update_movie(string title, string new_title, string new_genre, string new_year, string new_likes, string new_link);

	vector<Movie> getAll();

	//returns a readable version of the current repo
	string write_list();
};