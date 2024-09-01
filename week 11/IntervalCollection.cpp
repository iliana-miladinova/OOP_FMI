#include "IntervalCollection.h"

IntervalCollection::IntervalCollection(int start, int end)
{
	if (end<start)
	{
		std::swap(start, end);
	}

	this->start = start;
	this->end = end;
	int size = end - start;

	data = new int[size] {0};
}

unsigned IntervalCollection::intervalLength() const
{
	return end - start;
}

void IntervalCollection::add(int el)
{
	if (el<start||el>end)
	{
		return;
	}

	int ind = el - start;
	data[ind]++;
}

void IntervalCollection::remove(int el)
{
	if (el<start||el>end)
	{
		return;
	}
	int ind = el - start;
	if (data[ind]==0)
	{
		return;
	}
	data[ind]--;
}

unsigned IntervalCollection::count(int el) const
{
	if (el<start||el>end)
	{
		return 0;
	}
	int ind = el - start;
	return data[ind];
}

bool IntervalCollection::contains(int el) const
{
	return count(el) > 0;
}