#pragma once
#include <iostream>

class DynamicSet
{
private:
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const DynamicSet& other);

	unsigned getBucketIndex(unsigned num) const;

public:
	DynamicSet(unsigned n);// [0....n] 
	DynamicSet(const DynamicSet& other);
	DynamicSet& operator=(const DynamicSet& other);
	~DynamicSet();

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num) const;
	void print()const;
	friend DynamicSet unionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
	friend DynamicSet intersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
};