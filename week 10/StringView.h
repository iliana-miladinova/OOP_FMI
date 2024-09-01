#pragma once
#include <fstream>
#include "MyString.h"

class StringView
{
private:
	const char* begin;
	const char* end; //1 element after the final char;

public:
	StringView(const char* _begin, const char* _end);
	StringView(const char* str);//terminatedString
	StringView(const MyString& string);

	size_t length() const;
	char operator[](size_t ind) const;

	StringView substr(size_t from, size_t length) const;
	friend std::ostream& operator<<(std::ostream& os, const StringView& strView);
};