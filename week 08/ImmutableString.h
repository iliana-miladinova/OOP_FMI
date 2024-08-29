#pragma once
#include <iostream>
#include "StringPool.h"

class ImmutableString
{
public:
	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other) = delete;//this could be implemented in some cases
	~ImmutableString();

	size_t length() const;
	char operator[](size_t index) const;
	const char* c_str() const;
private:
	const char* _data;
	size_t _length;

	void copyFrom(const ImmutableString& other);
	void free();

	static StringPool _pool; //Статичният член _pool е общ за всички 
	/*инстанции на ImmutableString, 
	т.е., не е специфичен за конкретен обект от този клас. Това позволява:

	Споделена информация : Всички инстанции на ImmutableString да имат достъп
		до същия пул от стрингове.
		Паметна икономия : Да се избегне създаването на нов пул за всяка 
		инстанция на ImmutableString.*/
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
