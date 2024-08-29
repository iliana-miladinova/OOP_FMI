#pragma once
#include <iostream>

class MapKeys0toN
{
public:
	MapKeys0toN(unsigned _nullvalue);
	void add(unsigned key, unsigned value);
	bool contains(unsigned key) const;
	unsigned getValue(unsigned key) const;
private:
	static constexpr unsigned N = 100;
	unsigned values[N];
	unsigned nullvalue;
};