#include "selfCounting.h"

//static class member's should be
//initialized here ( "only in one .cpp" )
unsigned SelfCounting::liveObjectsCount = 0;
unsigned SelfCounting::createdObjectsCount = 0;

SelfCounting::SelfCounting() :SelfCounting(20)
//initialization of constants
						//can only be done while creating them
						//so the only possible way is in
						//the initialization list
{

}

SelfCounting::SelfCounting(int val) :const_val(val)
{
	liveObjectsCount++;
	createdObjectsCount++;
}

SelfCounting::SelfCounting(const SelfCounting& other) :const_val(other.const_val)
{
	liveObjectsCount++;
	createdObjectsCount++;
}

SelfCounting::~SelfCounting()
{
	liveObjectsCount--;
}

unsigned SelfCounting::getLiveObjectsCount()
{
	return liveObjectsCount;
}

unsigned SelfCounting::getCreatedCount()
{
	return createdObjectsCount;
}

int main()
{
	SelfCounting s(4);
	SelfCounting s2(13);
	{
		SelfCounting s3(123);
		std::cout << SelfCounting::getCreatedCount() << " " << SelfCounting::getLiveObjectsCount() << std::endl;
	}

	std::cout << SelfCounting::getCreatedCount() << " " << SelfCounting::getLiveObjectsCount() << std::endl;

}