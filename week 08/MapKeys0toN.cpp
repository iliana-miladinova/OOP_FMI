#include "MapKeys0toN.h"

MapKeys0toN::MapKeys0toN(unsigned _nullvalue)
{
	for (int i = 0; i < N; i++)
	{
		values[i] = _nullvalue;
	}
	nullvalue = _nullvalue;
}

void MapKeys0toN::add(unsigned key, unsigned value)
{
	if (value==nullvalue)
	{
		return;
	}
	values[key] = value;
}

bool MapKeys0toN::contains(unsigned key) const
{
	return values[key] != nullvalue;
}

unsigned MapKeys0toN::getValue(unsigned key) const
{
	if (!contains(key))
	{
		throw "Error";
	}
	return values[key];
}