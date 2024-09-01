#pragma once
#include <fstream>
#include "MyString.h"

class StringView
{
private:
	const char* begin = nullptr;
	const char* end = nullptr;

public:
	StringView() = default;
	StringView(const char* _begin, const char* _end);
	StringView(const char* str);
	StringView(const MyString& string);

	size_t length() const;
	char operator[](size_t ind) const;

	friend std::ostream& operator<<(std::ostream& os, const StringView& strView);
	StringView substr(size_t from, size_t length) const;
};

bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);