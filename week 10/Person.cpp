#include "Person.h"
#pragma warning(disable: 4996)

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	age = other.age;
}

void Person::moveFrom(Person&& other)
{
	name = other.name;
	other.name = nullptr;

	age = other.age;
}

void Person::free()
{
	delete[] name;
}

void Person::setName(const char* name)
{
	if (name==nullptr||this->name==name)
	{
		return;
	}
	delete[] this->name;
	size_t nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	strcpy(this->name, name);
}

void Person::setAge(int age)
{
	this->age = age;
}

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(Person&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Person::~Person()
{
	free();
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::print() const
{
	std::cout << name << " " << age << std::endl;
}