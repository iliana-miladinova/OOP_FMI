#include "DynamicArrayOfPointers.h"

void DynamicArrayOfPointers::copyFrom(const DynamicArrayOfPointers& other)
{
	count = other.count;
	capacity = other.capacity;

	data = new A * [capacity];
	for (int i = 0; i < capacity; i++)
	{
		if (other.data[i]==nullptr)
		{
			data[i] = nullptr;
		}
		else
		{
			data[i] = new A(*other.data[i]);//to reuse the A box
		}
	}
}

void DynamicArrayOfPointers::moveFrom(DynamicArrayOfPointers&& other)
{
	data = other.data;
	other.data = nullptr;

	capacity = other.capacity;
	count = other.count;
	other.count = 0;
}

void DynamicArrayOfPointers::free()
{
	for (int i = 0; i < capacity; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

void DynamicArrayOfPointers::resize(size_t newCap)
{
	A** newDataptr = new A * [newCap] {nullptr};
	for (int i = 0; i < capacity; i++)
	{
		newDataptr[i] = data[i];
	}
	delete[] data;
	data = newDataptr;
	capacity = newCap;
}

DynamicArrayOfPointers::DynamicArrayOfPointers()
{
	capacity = 8;
	data = new A * [capacity] {nullptr};
}

DynamicArrayOfPointers::DynamicArrayOfPointers(const DynamicArrayOfPointers& other)
{
	copyFrom(other);
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(const DynamicArrayOfPointers& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicArrayOfPointers::DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(DynamicArrayOfPointers&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicArrayOfPointers::~DynamicArrayOfPointers()
{
	free();
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(const A& current)
{
	if (count>=capacity)
	{
		resize(capacity * 2);
	}
	int ind = getFirstFreeIndex();
	if (ind==-1)
	{
		return;
	}
	data[ind] = new A(current);//C.C
	count++;
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(A&& current)
{
	if (count >= capacity)
	{
		resize(capacity * 2);
	}

	int ind = getFirstFreeIndex();
	if (ind==-1)
	{
		return;
	}
	data[ind] = new A(std::move(current));//M.C
	count++;
}

int DynamicArrayOfPointers::getFirstFreeIndex() const
{
	for (int i = 0; i < capacity; i++)
	{
		if (data[i]==nullptr)
		{
			return i;
		}
	}
	return -1;
}

bool DynamicArrayOfPointers::containsAt(unsigned ind) const
{
	return ind < capacity && data[ind] != nullptr;
}

void DynamicArrayOfPointers::removeAt(size_t index)
{
	if (index>=capacity)
	{
		return;
	}

	delete data[index];
	data[index] = nullptr;
	count--;
}

const A& DynamicArrayOfPointers::operator[](size_t index) const
{
	return *data[index]; //should be carefull for the empty places
}

A& DynamicArrayOfPointers::operator[](size_t index)
{
	return *data[index]; //should be carefull for the empty places
}

void DynamicArrayOfPointers::popBack()
{
	if (size()==0)
	{
		return;
	}
	delete data[count - 1];
	count--;
}

void DynamicArrayOfPointers::setAtIndex(const A& obj, size_t index)
{
	if (index>=capacity)
	{
		resize(capacity * 2);
	}
	if (data[index]!=nullptr)
	{
		data[index]->operator=(obj);
	}
	else
	{
		data[index] = new A(obj);
		count++;
	}
}

void DynamicArrayOfPointers::setAtIndex(A&& obj, size_t index)
{
	if (data[index]!=nullptr)
	{
		*data[index] = obj;
	}
	else
	{
		data[index] = new A(std::move(obj)); //move c-tor
		count++;
	}
}

size_t DynamicArrayOfPointers::size() const
{
	return count;
}