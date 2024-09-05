#include "UnionOfSets.h"

UnionOfSets::UnionOfSets(const Set**& sets, size_t count) :SetOperation(sets, count)
{

}

UnionOfSets::UnionOfSets(Set**&& sets, size_t count) :SetOperation(std::move(sets), count)
{

}

bool UnionOfSets::accepts(uint32_t el) const 
{
	for (int i = 0; i < count; i++)
	{
		if (sets[i]->accepts(el))
		{
			return true;
		}
	}
	return false;
}

Set* UnionOfSets::clone() const
{
	return new UnionOfSets(*this);
}