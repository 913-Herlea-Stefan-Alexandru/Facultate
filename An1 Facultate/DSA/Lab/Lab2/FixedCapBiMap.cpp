#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if (capacity <= 0)
	{
		throw "Capacity must be greater than 0";
	}
	this->capacity = capacity;
	this->list = new TElem[capacity];
	this->count = 0;
}

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->list;
}

int FixedCapBiMap::key_count(TKey key)
{
	int k = 0;

	for (int i = 0; i < this->count; i++)
	{
		if (this->list[i].first == key)
		{
			k++;
		}
	}

	return k;
}

bool FixedCapBiMap::add(TKey c, TValue v){
	//TODO - Implementation
	if (isFull())
	{
		throw "List is full";
	}
	
	if (key_count(c) == 2)
	{
		return false;
	}

	TElem new_elem;

	new_elem.first = c;
	new_elem.second = v;

	this->list[this->count] = new_elem;

	this->count++;

	return true;
}

ValuePair FixedCapBiMap::removeKey(TKey c)
{
	int pos1 = -1;
	int pos2 = -1;
	for (int i = 0; i < this->count; i++)
	{
		if (this->list[i].first == c)
		{
			if (pos1 == -1)
			{
				pos1 = i;
			}
			else
			{
				pos2 = i;
				break;
			}
		}
	}

	TValue val1 = NULL_TVALUE, val2 = NULL_TVALUE;

	if (pos1 != -1)
	{
		val1 = this->list[pos1].second;
		this->list[pos1] = this->list[this->count - 1];
		this->count--;
	}
	if (pos2 != -1)
	{
		val2 = this->list[pos2].second;
		this->list[pos2] = this->list[this->count - 1];
		this->count--;
	}

	ValuePair res(val1, val2);

	return res;
}

ValuePair FixedCapBiMap::search(TKey c) const{
	//TODO - Implementation

	TValue val1 = NULL_TVALUE, val2 = NULL_TVALUE;

	for (int i = 0; i < this->count; i++)
	{
		if (this->list[i].first == c)
		{
			if (val1 == NULL_TVALUE)
			{
				val1 = this->list[i].second;
			}
			else
			{
				val2 = this->list[i].second;
				break;
			}
		}
	}

	ValuePair res(val1, val2);

	return res;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
	//TODO - Implementation
	return false;
}


int FixedCapBiMap::size() const {
	//TODO - Implementation
	return this->count;
}

bool FixedCapBiMap::isEmpty() const{
	//TODO - Implementation
	return this->count == 0;
}

bool FixedCapBiMap::isFull() const {
	//TODO - Implementation
	return this->capacity == this->count;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



