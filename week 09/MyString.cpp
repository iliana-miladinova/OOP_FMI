#include "MyString.h"
#pragma warning(disable:4996)

static unsigned roundToNextPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

static unsigned dataToAllocateByStringLen(unsigned stringLen)
{
	return std::max(roundToNextPowerOfTwo(stringLen + 1), 16u);
}

MyString::MyString() :MyString("")
{

}

MyString::MyString(size_t stringLength)
{
	allocatedDataSize = dataToAllocateByStringLen(stringLength);
	data = new char[allocatedDataSize];
	size = 0;
	data[0] = '\0';
}

MyString::MyString(const char* _data)
{
	size = std::strlen(_data);
	allocatedDataSize = dataToAllocateByStringLen(size);
	data = new char[allocatedDataSize];
	strcpy(this->data, _data);
}

void MyString::copyFrom(const MyString& other)
{
	allocatedDataSize = other.allocatedDataSize;
	data = new char[allocatedDataSize];
	strcpy(data, other.data);
	size = other.size;
}

void MyString::moveFrom(MyString&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;

	allocatedDataSize = other.allocatedDataSize;
	other.allocatedDataSize = 0;
}

void MyString::free()
{
	delete[] data;
}

void MyString::resize(unsigned newAllocatedDataSize)
{
	char* newData = new char[newAllocatedDataSize];
	strcpy(newData, data);
	delete[] data;
	data = newData;
	allocatedDataSize = newAllocatedDataSize;
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept 
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

size_t MyString::getCapacity() const
{
	return allocatedDataSize - 1;
}

size_t MyString::getSize() const
{
	return size;
}

const char* MyString::c_str() const
{
	return data;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (getSize()+other.getSize()+1>allocatedDataSize)
	{
		resize(dataToAllocateByStringLen(getSize() + other.getSize()));
	}

	std::strncat(data, other.data, other.getSize());
	size = getSize() + other.getSize();
	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs.getSize()+rhs.getSize());
	result += lhs;
	result += rhs; 
	return result;
}

char& MyString::operator[](size_t index)
{
	return data[index];
}

const char& MyString::operator[](size_t index) const
{
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj.data;
}

std::istream& operator>>(std::istream& is, MyString& ref)
{
	char buff[1024];
	is >> buff;

	size_t buffStringSize = strlen(buff);
	if (buffStringSize>ref.getCapacity())
	{
		ref.resize(dataToAllocateByStringLen(buffStringSize));
	}

	strcpy(ref.data, buff);
	ref.size = buffStringSize;
	return is;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}