#pragma once
#include <string>
#include "movie.h"

using namespace std;

template <class T>

class DynamicArray
{
private:

	T* arr;
	int size, dimension;

	//expands the array of elements
	void expand()
	{
		T* cp_arr = new T[this->dimension];

		for (int i = 0; i < this->dimension; i++)
		{
			cp_arr[i] = this->arr[i];
		}

		delete[] this->arr;

		this->arr = new T[this->dimension * 2];

		for (int i = 0; i < this->dimension; i++)
		{
			this->arr[i] = cp_arr[i];
		}

		this->dimension *= 2;

		delete[] cp_arr;
	}
	
	//decreases the space allocated for the array of elements
	void decrease()
	{
		T* cp_arr = new T[this->dimension / 2];

		for (int i = 0; i < this->dimension / 2; i++)
		{
			cp_arr[i] = this->arr[i];
		}

		delete[] this->arr;

		this->arr = new T[this->dimension / 2];

		for (int i = 0; i < this->dimension / 2; i++)
		{
			this->arr[i] = cp_arr[i];
		}

		this->dimension /= 2;

		delete[] cp_arr;
	}

public:

	//the constructor for the dynamic array
	//allocates memory or 5 entries, setting the size to 0
	DynamicArray()
	{
		this->arr = new T[5];
		this->size = 0;
		this->dimension = 5;
	}

	//the destructor for the dynamic array
	//it deletes the memory allocated for the array
	~DynamicArray()
	{
		delete[] this->arr;
	}

	//adds the object of type T given
	int add(T obj)
	{
		if (this->size == this->dimension)
		{
			this->expand();
		}
		this->arr[size] = obj;
		this->size++;

		return 0;
	}

	//removes the object from pos index(int) given
	//if the index is invalid, returns 1, else returns 0
	int remove(int index)
	{
		if (index < 0 || index >= this->size)
		{
			return 1;
		}

		this->arr[index].~Movie();

		for (int i = index; i < this->size - 1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}

		this->arr[this->size - 1].~Movie();

		this->size--;

		if (this->size <= this->dimension / 2 && this->dimension != 5)
		{
			this->decrease();
		}

		return 0;
	}

	T* getAddress(int index)
	{
		return &this->arr[index];
	}

	//returns a pointer to the object of type T if found on position index(int), otherwise returns null
	T operator[](int index)
	{
		return this->arr[index];
	}

	int length() const
	{
		return this->size;
	}
};
