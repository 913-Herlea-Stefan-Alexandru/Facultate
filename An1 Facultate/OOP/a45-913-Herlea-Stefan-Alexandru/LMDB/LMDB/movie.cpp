#include "movie.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie()
{
	this->year = 0;
	this->likes = 0;
}

Movie::Movie(string title, string genre, int year, int likes, string link)
: title(title), genre(genre), year(year), likes(likes), link(link)
{

}

Movie::~Movie()
{

}

string Movie::getTitle() const
{
	return this->title;
}

string Movie::getGenre() const
{
	return this->genre;
}

int Movie::getYear() const
{
	return this->year;
}

int Movie::getLikes() const
{
	return this->likes;
}

string Movie::getLink() const
{
	return this->link;
}

void Movie::setTitle(string newTitle)
{
	this->title = newTitle;
}

void Movie::setGenre(string newGenre)
{
	this->genre = newGenre;
}

void Movie::setYear(int newYear)
{
	this->year = newYear;
}

void Movie::setLikes(int newLikes)
{
	this->likes = newLikes;
}

void Movie::setLink(string newLink)
{
	this->link = newLink;
}

void Movie::runLink()
{
	ShellExecuteA(0, 0, this->link.c_str(), 0, 0, SW_SHOW);
}

string Movie::write_movie()
{
	string str = "";

	str += "\nTITLE: " + this->title + "\n" + "GENRE: " + this->genre + "\n" + "YEAR: " + to_string(this->year) + "\n" + "LIKES: " 
		+ to_string(this->likes) + "\n" + "TRAILER: " + this->link + "\n";

	return str;
}
