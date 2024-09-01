#include "NormalCollection.h"

void NormalCollection::add(int el)
{
	if (size==capacity)
	{
		resize(capacity * 2);
	}
	data[size++] = el;
}

void NormalCollection::remove(int el)
{
	int elInd = -1;
	for (int i = 0; i < size; i++)
	{
		if (data[i]==el)
		{
			elInd = i;
			break;
		}
	}
	if (elInd!=-1)
	{
		std::swap(data[elInd], data[size - 1]);
		size--;
	}
}

unsigned NormalCollection::count(int el) const
{
	unsigned count = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i]==el)
		{
			count++;
		}
	}
	return count;
}

bool NormalCollection::contains(int el) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i]==el)
		{
			return true;
		}
	}
	return false;
}