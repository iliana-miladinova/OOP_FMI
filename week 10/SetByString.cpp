#include "SetByString.h"
#include <sstream>
#pragma warning (disable : 4996)

void SetByString::extractNumsFronString()
{
	removeAll(); //premahva vsichki elementi ot nojestvoto, zashtoto shte dobavyame novi elementi v zavisimost ot str
	std::stringstream ss(str); //pozvolyava izvlichane na dannite ot niz v potok

	while (!ss.eof())
	{
		unsigned curr;
		ss >> curr; //izvlichame porednoto chislo ot potoka i go dobavyame v current
		add(curr); //dobavyame chisloto v mnojestvoto
	}
}

void SetByString::copyFrom(const SetByString& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
}

void SetByString::moveFrom(SetByString&& other)
{
	str = other.str;
	other.str = nullptr;
}

void SetByString::free()
{
	delete[] str;
	str = nullptr;
}

SetByString::SetByString(unsigned n, const char* data) :DynamicSet(n)
{
	str = new char[strlen(data) + 1];
	strcpy(str, data);
	extractNumsFronString(); //Функцията extractNumbersFromString анализира текста в str, 
	//извлича числата от него и ги добавя към множеството, използвайки функционалността, 
	// наследена от DynamicSet. Без това извикване, множеството няма да съдържа никакви 
	// елементи, тъй като конструкторът на DynamicSet сам по себе си не добавя числа, 
	// а само създава празно множество.
}

SetByString::SetByString(const SetByString& other):DynamicSet(other)
{
	copyFrom(other);
}

SetByString& SetByString::operator=(const SetByString& other)
{
	if (this!=&other)
	{
		DynamicSet::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

SetByString::SetByString(SetByString&& other) noexcept:DynamicSet(std::move(other))
{
	moveFrom(std::move(other));
}

SetByString& SetByString::operator=(SetByString&& other) noexcept
{
	if (this!=&other)
	{
		DynamicSet::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

SetByString::~SetByString()
{
	free();
}

bool SetByString::contains(int i) const
{
	return DynamicSet::contains(i);
}

void SetByString::print() const
{
	DynamicSet::print();
}

void SetByString::setAt(unsigned ind, char ch)
{
	str[ind] = ch;
	extractNumsFronString();
}