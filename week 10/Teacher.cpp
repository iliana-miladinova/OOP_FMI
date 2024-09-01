#include "Teacher.h"
#pragma warning(disable:4996)

static char** copyArrayOfStrings(const char* const* strings, size_t size)
{
	char** res = new char* [size];

	for (int i = 0; i < size; i++)
	{
		res[i] = new char[strlen(strings[i]) + 1];
		strcpy(res[i], strings[i]);
	}

	return res;
}

static void freeArraysOfStrings(char** strings, unsigned stringsCount)
{
	for (int i = 0; i < stringsCount; i++)
	{
		delete[] strings[i];
	}
	delete[] strings;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount):Person(name,age)
{
	this->subjects = copyArrayOfStrings(subjects, subjectsCount);
	this->subjectsCount = subjectsCount;
}

void Teacher::copyFrom(const Teacher& other)
{
	subjects = copyArrayOfStrings(other.subjects, other.subjectsCount);
	subjectsCount = other.subjectsCount;
}

void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;
	other.subjects = nullptr;
	other.subjectsCount = 0;
}

void Teacher::free()
{
	freeArraysOfStrings(subjects, subjectsCount);
}

Teacher::Teacher(const Teacher& other):Person(other)
{
	copyFrom(other);  //only the teacher stuff is copied
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this!=&other)
	{
		Person::operator=(other);//delete data of person + copy the data from person
		free(); //Teacher::free();
		copyFrom(other); //Teacher::copyFrom()
	}
	return *this;
}

Teacher::Teacher(Teacher&& other) noexcept :Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this!=&other)
	{
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Teacher::~Teacher()
{
	free();
}  // destr person