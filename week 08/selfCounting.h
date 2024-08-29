#pragma once
#include <iostream>

class SelfCounting
{
private:
	//a constant, which may be different
	//for different objects
	//so it is "per object"
	const int const_val;

	static unsigned liveObjectsCount;
	static unsigned createdObjectsCount;

public:
	SelfCounting();
	SelfCounting(int val);
	SelfCounting(const SelfCounting& other);
	~SelfCounting();

	//methods which aren't
	//related with particular
	//instance
	static unsigned getLiveObjectsCount();
	static unsigned getCreatedCount();
};