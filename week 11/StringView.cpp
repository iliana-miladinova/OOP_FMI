#include "StringView.h"

StringView::StringView(const char* _begin, const char* _end) :begin(_begin), end(_end)
{

}

StringView::StringView(const char* str) :StringView(str, str + strlen(str))
{

}

StringView::StringView(const MyString& string) :StringView(string.c_str())
{

}

size_t StringView::length() const
{
	return end - begin;
}

char StringView::operator[](size_t ind) const
{
	return begin[ind];
}

StringView StringView::substr(size_t from, size_t length) const
{
	if (begin+from+length>end)
	{
		std::length_error("Substr is out of range");
	}
	return StringView(begin + from, begin + from + length);
}

std::ostream& operator<<(std::ostream& os, const StringView& strView)
{
	const char* itter = strView.begin;
	while (itter!=strView.end)
	{
		os << *itter;
		itter++;
	}
	return os;
}

bool operator==(const StringView& lhs, const StringView& rhs)
{
	if (lhs.length()!=rhs.length())
	{
		return false;
	}

	for (int i = 0; i < lhs.length(); i++)
	{
		if (lhs[i]!=rhs[i])
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const StringView& lhs, const StringView& rhs)
{
	return !operator==(lhs, rhs);
}