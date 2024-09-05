#pragma once
#include "SetOperation.h"

class IntersectionOfSets :public SetOperation
{
public:
	IntersectionOfSets(const Set**& sets, size_t count);
	IntersectionOfSets(Set**&& sets, size_t count);
	bool accepts(uint32_t el) const override;
	Set* clone() const override;
};