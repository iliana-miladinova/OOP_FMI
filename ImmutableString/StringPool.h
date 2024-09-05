#pragma once
#include <iostream>
#pragma warning (disable:4996)

class StringPool
{
private:
	struct StringRecord
	{
		char* str = nullptr;
		unsigned refCount = 0;
	};

	StringRecord* stringRecords;
	size_t stringCount = 0;//Показва текущия брой на записите
	//(стрингове) в масива stringRecords.
	size_t stringCapacity = 0; // Показва максималния брой стрингове,
	//които масивът stringRecords може да побере в момента, 
	// без да е необходимо преоразмеряване.

	unsigned allocatedNewString(const char* str);
	void resize(unsigned newCap);
	int findAllocatedString(const char* str) const;

	void removeRecord(unsigned ind);

public:
	StringPool();
	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);
	StringPool(const StringPool& other) = delete;
	StringPool& operator=(const StringPool& other) = delete;
	~StringPool();
};