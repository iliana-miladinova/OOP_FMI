#pragma once
#include "Set.h"

class SetOperation :public Set
{
protected:
	Set** sets;
	size_t count;

	void copyFrom(const SetOperation& other);
	void moveFrom(SetOperation&& other);
	void free();

public:
	SetOperation(const Set**& sets, size_t count);
	SetOperation(Set**&& sets, size_t count);
	SetOperation(const SetOperation& other);
	SetOperation& operator=(const SetOperation& other);
	SetOperation(SetOperation&& other) noexcept;
	SetOperation& operator=(SetOperation&& other) noexcept;
	~SetOperation();
};