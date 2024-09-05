#pragma once
#include "SetOperation.h"

class UnionOfSets :public SetOperation
{
public:
	UnionOfSets(const Set**& sets, size_t count);
	UnionOfSets(Set**&& sets, size_t count);

	bool accepts(uint32_t el) const override;
	Set* clone() const override;
};