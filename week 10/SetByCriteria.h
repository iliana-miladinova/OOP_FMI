#pragma once
#include "DynamicSet.h"

class SetByCriteria :private DynamicSet
{
private:
	void fillSet(bool(*criteria)(unsigned n));
public:
	SetByCriteria(unsigned n, bool(*incl)(unsigned n));
	void setInclude(bool(*incl)(unsigned n)); //promenya kriteriya za mnojestvote

	using DynamicSet::print;
	using DynamicSet::contains;
};