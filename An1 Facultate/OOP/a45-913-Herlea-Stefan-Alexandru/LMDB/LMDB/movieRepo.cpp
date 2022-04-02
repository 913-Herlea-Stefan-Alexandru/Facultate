#include "movieRepo.h"
#include "movieIterator.h"

int MovieRepo::add(Movie mv)
{
	int poz = -1;

	for (int i = 0; i < this->arr.length(); i++)
	{
		Movie mv_temp = this->arr[i];
		if (mv_temp.getTitle() == mv.getTitle())
		{
			poz = i;
			break;
		}
	}

	if (poz != -1)
	{
		return 1;
	}

	this->arr.add(mv);

	return 0;
}

int MovieRepo::remove(string title)
{
	int poz = -1;

	for (int i = 0; i < this->arr.length(); i++)
	{
		Movie mv_temp = this->arr[i];
		if (mv_temp.getTitle() == title)
		{
			poz = i;
			break;
		}
	}

	if (poz == -1)
	{
		return 1;
	}

	this->arr.remove(poz);

	return 0;
}

Movie MovieRepo::getObj(string title)
{
	for (int i = 0; i < this->arr.length(); i++)
	{
		Movie mv_temp = this->arr[i];
		if (mv_temp.getTitle() == title)
		{
			return mv_temp;
		}
	}
	return Movie("", "", -1, -1, "");
}

Movie* MovieRepo::getAddress(string title)
{
	for (int i = 0; i < this->arr.length(); i++)
	{
		Movie* mv_temp = this->arr.getAddress(i);
		if (mv_temp->getTitle() == title)
		{
			return mv_temp;
		}
	}
	return NULL;
}

int MovieRepo::length() const
{
	return this->arr.length();
}

void MovieRepo::filterGenre(string genre, MovieRepo& filtered)
{
	for (int i = 0; i < this->arr.length(); i++)
	{
		Movie mv_temp = this->arr[i];
		if (mv_temp.getGenre() == genre || genre == "")
		{
			filtered.add(mv_temp);
		}
	}
}

MViterator MovieRepo::iterator() const
{
	return MViterator(*this);
}

Movie MovieRepo::getByIndex(int index)
{
	return this->arr[index];
}

void MovieRepo::emptyRepo()
{
	for (int i = 0; i < this->arr.length(); i++)
	{
		this->remove(this->arr[i].getTitle());
		i--;
	}
}

string MovieRepo::write_list()
{
	string str = "";
	for (int i = 0; i < this->arr.length(); i++)
	{
		str += this->arr[i].write_movie() + "\n";
	}

	return str;
}
