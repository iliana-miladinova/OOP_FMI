// ImmutableString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ImmutableString.h"

StringPool ImmutableString::pool;

ImmutableString::ImmutableString(const char* data)
{
    this->data = pool.getAllocatedString(data);
    this->len = strlen(data);
}

void ImmutableString::copyFrom(const ImmutableString& other)
{
    data = pool.getAllocatedString(other.data);
    len = other.len;
}

void ImmutableString::free()
{
    pool.releaseString(data);
    data = nullptr;
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
    copyFrom(other);
}

ImmutableString::~ImmutableString()
{
    free();
}

size_t ImmutableString::length() const
{
    return len;
}

char ImmutableString::operator[](size_t ind) const
{
    return data[ind];
}

const char* ImmutableString::c_str() const
{
    return data;
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str)
{
    return os << str.c_str(); //char* zapisvame v potoka bez cikal
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}
int main()
{
    ImmutableString str1("abc");
    ImmutableString str2("abc");
    ImmutableString str3("aws");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
