#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"

class StringView
{
private:
	const char* begin;
	const char* end;
public:
	StringView(const char* _begin, const char* _end);
	StringView(const char* str);
	StringView(const MyString& string);

	size_t length() const;
	char operator[](size_t ind) const;

	StringView substr(size_t from, size_t length) const;
	friend std::ostream& operator<<(std::ostream& os, const StringView& strView);
};

bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);