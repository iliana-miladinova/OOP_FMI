#include "DynamicSet.h"

DynamicSet::DynamicSet(unsigned N)
{
	bucketsCount = N / elementsInBucket + 1;
	buckets = new uint8_t[bucketsCount]{ 0 };
	this->N = N;
}

void DynamicSet::copyFrom(const DynamicSet& other)
{
	buckets = new uint8_t[other.bucketsCount];
	for (int i = 0; i < other.bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
	bucketsCount = other.bucketsCount;
	N = other.N;
}

void DynamicSet::free()
{
	delete[] buckets;
	buckets = nullptr;
	bucketsCount = 0;
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
	copyFrom(other);
}

DynamicSet& DynamicSet::operator=(const DynamicSet& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicSet::~DynamicSet()
{
	free();
}

unsigned DynamicSet::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;
}

void DynamicSet::add(unsigned num)
{
	if (num>N)
	{
		return;
	}
	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;
	uint8_t mask = 1 << bitIndex;
	buckets[bucketIndex] |= mask;
}

void DynamicSet::remove(unsigned num)
{
	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;
	uint8_t mask = ~(1 << bitIndex);
	buckets[bucketIndex] &= mask;
}

bool DynamicSet::contains(unsigned num) const
{
	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;
	uint8_t mask = 1 << bitIndex;
	return buckets[bucketIndex] & mask;
}

void DynamicSet::print() const
{
	std::cout << "{ ";
	for (int i = 0; i <= N ; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << "} ";
}

DynamicSet unionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet res(std::max(lhs.N, rhs.N));
	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (int i = 0; i < minBucketsCount; i++)
	{
		res.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
	}

	const DynamicSet& biggerN = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs;


	for (int i = minBucketsCount; i < biggerN.bucketsCount; i++)
	{
		res.buckets[i] = biggerN.buckets[i];
	}

	return res;
}

DynamicSet intersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet res(std::min(lhs.N, rhs.N));
	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (int i = 0; i < minBucketsCount; i++)
	{
		res.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}
	return res;
}