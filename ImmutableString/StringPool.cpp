#include "StringPool.h"

StringPool::StringPool()
{
	stringCount = 0;
	stringCapacity = 8;
	stringRecords = new StringRecord[stringCapacity];
}

int StringPool::findAllocatedString(const char* str) const
{
	for (int i = 0; i < stringCount; i++)
	{
		if (strcmp(str,stringRecords[i].str)==0)
		{
			return i;
		}
	}
	return -1;
}

void StringPool::resize(unsigned newCap)
{
	StringRecord* newStringRecords = new StringRecord[newCap];
	for (int i = 0; i < stringCount; i++)
	{
		newStringRecords[i] = stringRecords[i];
	}
	stringCapacity = newCap;
	delete[] stringRecords;
	stringRecords = newStringRecords;
}

unsigned StringPool::allocatedNewString(const char* str)
{
	if (stringCount==stringCapacity)
	{
		resize(stringCapacity * 2);
	}

	unsigned firstFreeInd = stringCount;
	stringCount++;
	stringRecords[firstFreeInd].str = new char[strlen(str) + 1];
	strcpy(stringRecords[firstFreeInd].str, str);
	stringRecords[firstFreeInd].refCount = 0;
	return firstFreeInd;
}

const char* StringPool::getAllocatedString(const char* str)
{
	int ind = findAllocatedString(str);

	if (ind!=-1) //string is found
	{
		stringRecords[ind].refCount++;
		//For debug pourpouses
		std::cout << "String found in cache, ref count: " << stringRecords[ind].refCount << std::endl;
		//
		return stringRecords[ind].str;
	}
	else //string is not found
	{
		// For debug pourpouses
			std::cout << "String NOT found in cache. Allocating.." << std::endl;
		//
		unsigned ind = allocatedNewString(str);
		stringRecords[ind].refCount++;
		return stringRecords[ind].str;
	}
}

void StringPool::removeRecord(unsigned ind)
{
	std::swap(stringRecords[ind], stringRecords[stringCount - 1]);
	delete[] stringRecords[stringCount - 1].str;
	stringRecords[stringCount - 1].str = nullptr;
	stringRecords[stringCount - 1].refCount = 0;

	stringCount--;
}

void StringPool::releaseString(const char* str)
{
	int ind = findAllocatedString(str);

	stringRecords[ind].refCount--;
	if (stringRecords[ind].refCount==0)
	{
		//For debug pourpouses
		std::cout << "Removing record: " << stringRecords[ind].str << " (No more refs)" << std::endl;
		//
		removeRecord(ind);
	}
}

StringPool::~StringPool()
{
	for (int i = 0; i < stringCapacity; i++)
	{
		delete[] stringRecords[i].str;
	}
	delete[] stringRecords;
}