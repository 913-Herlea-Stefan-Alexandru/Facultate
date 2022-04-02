#include "movie.h"
#include "admin_service.h"
#include <exception>

AdminService::AdminService(MovieRepo &repo)
: repo(repo)
{

}

AdminService::~AdminService()
{

}

int AdminService::add_movie(string title, string genre, string year, string likes, string link)
{
	int year_i = 0, likes_i = 0;

	if (this->val.validate_year(year) || this->val.validate_likes(likes))
		return 2;

	if (this->val.validate_title(title) == 1)
		return 3;

	if (this->val.validate_genre(genre) == 1)
		return 4;

	if (this->val.validate_link(link) == 1)
		return 5;

	if (year != "")
	{
		year_i = atoi(year.c_str());
	}
	if (likes != "")
	{
		likes_i = atoi(likes.c_str());
	}

	Movie mv(title, genre, year_i, likes_i, link);

	return this->repo.add(mv);
}

int AdminService::remove_movie(string title)
{
	if (this->val.validate_title(title) == 1)
		return 3;
	return this->repo.remove(title);
}

int AdminService::update_movie(string title, string new_title, string new_genre, string new_year, string new_likes, string new_link)
{
	Movie* mv = this->repo.getAddress(title);

	if (mv == NULL)
		return 1;

	int year_i = 0, likes_i = 0;
	if (new_year != "")
	{
		if (this->val.validate_year(new_year))
			return 2;
		year_i = atoi(new_year.c_str());
	}
	if (new_likes != "")
	{
		if (this->val.validate_likes(new_likes))
			return 2;
		likes_i = atoi(new_likes.c_str());
	}

	if (new_title != "")
		mv->setTitle(new_title);
	if (new_genre != "")
		mv->setGenre(new_genre);
	if (new_year != "")
		mv->setYear(year_i);
	if (new_likes != "")
		mv->setLikes(likes_i);
	if (new_link != "")
	{
		if (this->val.validate_link(new_link) == 1)
			return 5;
		mv->setLink(new_link);
	}

	this->repo.save();

	/*this->repo.remove(title);
	this->repo.add(mv);*/

	return 0;
}

vector<Movie> AdminService::getAll()
{
	return this->repo.getAll();
}

string AdminService::write_list()
{
	return this->repo.write_list();
}
