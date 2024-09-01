#pragma once
#include "DynamicSet.h"

class SetByString :private DynamicSet
{
private:
	char* str;

	void extractNumsFronString();
	void copyFrom(const SetByString& other);
	void moveFrom(SetByString&& other);
	void free();

public:
	SetByString(unsigned n, const char* data);
	SetByString(const SetByString& other);
	SetByString& operator=(const SetByString& other);
	SetByString(SetByString&& other) noexcept;
	SetByString& operator=(SetByString&& other) noexcept;
	~SetByString();

	bool contains(int i) const;
	void print() const;
	void setAt(unsigned ind, char ch);
};