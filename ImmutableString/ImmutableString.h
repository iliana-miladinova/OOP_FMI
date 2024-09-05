#pragma once
#include "StringPool.h"

class ImmutableString
{
private:
	const char* data;
	size_t len;

	void copyFrom(const ImmutableString& other);
	void free();

	static StringPool pool;

public:
	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other) = delete;
	~ImmutableString();

	size_t length() const;
	char operator[](size_t ind) const;
	const char* c_str() const;
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);