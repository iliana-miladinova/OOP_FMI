#pragma once
#include <iostream>

constexpr unsigned MAX_NUM = 1023;
constexpr unsigned NUMBERS_COUNT = MAX_NUM + 1;
constexpr unsigned BUCKET_SIZE = sizeof(uint8_t) * 8;
constexpr unsigned BUCKETS_COUNT = NUMBERS_COUNT / BUCKET_SIZE + 1;

class StaticSet
{
private:
	uint8_t buckets[BUCKETS_COUNT] = { 0 };
	unsigned getBucketIndex(unsigned num) const;
	unsigned getBitIndex(unsigned num) const;
public:
	StaticSet() = default;

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num) const;
	void print() const;

	friend StaticSet unionOfSets(const StaticSet& lhs, const StaticSet& rhs);
	friend StaticSet intersectionOfSets(const StaticSet& lhs, const StaticSet& rhs);
};