#include "MyString.h"
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;//ako veche e stepen na dvojkata nyama da promenim chisloto
	//promenyame naj desnite bitove, koito sa 0 na 1
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++; //chisloto e stanalo naprimer 111, uvelichavame go s 1 i stava 1000, koeto e stepen na 2
	return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLen)
{
	return std::max(roundToPowerOfTwo(stringLen + 1)/*zaradi /0*/, 16u);//pameta, koyato tryabva da zadelim e pone 16 bita
}

MyString::MyString() :MyString("")
{

}

MyString::MyString(const char* data)
{
	_size = strlen(data);
	_alocatedDataSize = dataToAllocByStringLen(_size);
	_data = new char[_alocatedDataSize];
	std::strcpy(_data, data);
}

MyString::MyString(size_t stringLength)
{
	_alocatedDataSize = dataToAllocByStringLen(stringLength);
	_data = new char[_alocatedDataSize];
	_size = 0;
	_data[0] = '\0';
}

void MyString::copyFrom(const MyString& other)
{
	_alocatedDataSize = other._alocatedDataSize;
	_data = new char[_alocatedDataSize];
	std::strcpy(_data, other._data);
	_size = other._size;
}

void MyString::free()
{
	delete[] _data;
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
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

MyString::~MyString()
{
	free();
}

size_t MyString::getCapacity() const
{
	return _alocatedDataSize - 1;
}

size_t MyString::getSize() const
{
	return _size;
}

const char* MyString::c_str() const
{
	return _data;
}

void MyString::resize(unsigned newAllocatedDataSize)
{
	char* newData = new char[newAllocatedDataSize + 1];
	std::strcpy(newData, _data);
	delete[] _data;
	_data = newData;
	_alocatedDataSize = newAllocatedDataSize;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (getSize()+other.getSize()+1>_alocatedDataSize)
	{
		resize(getSize() + other.getSize());
	}

	// we need to use strncat instead of strcat, because strcat will not work for str += str 
  // (the terminating zero of str will be destroyed by the first char)
	std::strncat(_data, other._data, other.getSize());
	_size = getSize() + other.getSize();
	return *this;
}

char& MyString::operator[](size_t index)
{
	return _data[index];  // no security check!
}

const char& MyString::operator[](size_t index) const
{
	return _data[index];  // no security check!
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj._data;
}

std::istream& operator>>(std::istream& is, MyString& ref)
{
	char buff[1024];
	is >> buff; //Извършва се четене от входния поток is (например, std::cin) и
	//се записва съдържанието му в буфера buff.
	//  Този оператор чете до първото срещнато бяло пространство 
	// (като интервал, табулация или нов ред) и 
	//добавя терминиращ нулев символ ('\0') в края на низа.
	size_t buffStringSize = std::strlen(buff);
	if (buffStringSize>ref.getCapacity())
	{
		ref.resize(dataToAllocByStringLen(buffStringSize));
	}
	strcpy(ref._data, buff);
	ref._size = buffStringSize;
	return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString res(lhs.getSize() + rhs.getSize());
	res += lhs;// no resize is needed
	res += rhs;
	return res;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}