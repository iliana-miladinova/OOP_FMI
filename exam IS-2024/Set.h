#pragma once
#include <iostream>

class Set
{
public:
	virtual bool accepts(uint32_t el) const = 0;
	virtual Set* clone() const = 0;
	virtual ~Set() = default;
};