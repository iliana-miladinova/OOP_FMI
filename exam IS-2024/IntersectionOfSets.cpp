#include "IntersectionOfSets.h"

IntersectionOfSets::IntersectionOfSets(const Set**& sets, size_t count) :
	SetOperation(sets, count)
{

}

IntersectionOfSets::IntersectionOfSets(Set**&& sets, size_t count) :
	SetOperation(std::move(sets), count)
{

}

bool IntersectionOfSets::accepts(uint32_t el) const
{
	for (int i = 0; i < count; i++)
	{
		if (!sets[i]->accepts(el))
		{
			return false;
		}
	}
	return true;
}

Set* IntersectionOfSets::clone() const
{
	return new IntersectionOfSets(*this);
}