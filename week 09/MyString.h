#pragma once
#include <iostream>

class MyString
{
private:
	char* data;
	size_t size;
	size_t allocatedDataSize;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();

	void resize(unsigned newAllocatedDataSize);
	explicit MyString(size_t stringLength);

public:
	MyString();
	MyString(const char* _data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	size_t getCapacity() const;
	size_t getSize() const;

	const char* c_str() const;

	char& operator[](size_t ind);
	const char& operator[](size_t ind) const;

	MyString& operator+=(const MyString& other);
	
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& ref);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);