#include "StaticSet.h"

unsigned StaticSet::getBitIndex(unsigned num) const
{
	return num / BUCKET_SIZE;
}

unsigned StaticSet::getBitIndex(unsigned num) const
{
	return num % BUCKET_SIZE;
}

void StaticSet::add(unsigned num)
{
	if (num>MAX_NUM)
	{
		return;
	}

	unsigned bucketInd = getBucketIndex(num);
	unsigned bitInd = getBitIndex(num);
	uint8_t mask = 1 << bitInd;

	buckets[bucketInd] |= mask;
}

void StaticSet::remove(unsigned num)
{
	unsigned bucketInd = getBucketIndex(num);
	unsigned bitInd = getBitIndex(num);
	uint8_t mask = ~(1 << bitInd);
	buckets[bucketInd] &= mask;
}

bool StaticSet::contains(unsigned num) const
{
	unsigned bucketInd = getBucketIndex(num);
	unsigned bitInd = getBitIndex(num);
	uint8_t mask = 1 << bitInd;
	return buckets[bucketInd] & mask;
}

void StaticSet::print() const
{
	std::cout << "{ ";
	for (int i = 0; i <= MAX_NUM; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

StaticSet unionOfSets(const StaticSet& lhs, const StaticSet& rhs)
{
	StaticSet res;
	for (int i = 0; i < BUCKETS_COUNT; i++)
	{
		res.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
	}
	return res;
}

StaticSet intersectionOfSets(const StaticSet& lhs, const StaticSet& rhs)
{
	StaticSet res;
	for (int i = 0; i < BUCKETS_COUNT; i++)
	{
		res.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}
	return res;
}