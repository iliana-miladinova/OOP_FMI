#include "GraduateStudent.h"
#pragma warning(disable:4996)

void GraduateStudent::copyFrom(const GraduateStudent& other)
{
	name = new char[strlen(other.name)];
	strcpy(this->name, other.name);
	grades = new int[gradesCount];
	for (int i = 0; i < other.gradesCount; i++)
	{
		grades[i] = other.grades[i];
	}
	gradesCount = other.gradesCount;
	strcpy(this->quote, other.quote);
}

void GraduateStudent::moveFrom(GraduateStudent&& other)
{
	name = other.name;
	other.name = nullptr;

	gradesCount = other.gradesCount;
	other.gradesCount = 0;

	grades = other.grades;
	other.grades = nullptr;

	strcpy(quote, other.quote);
	strcpy(other.quote, "");
}

void GraduateStudent::free()
{
	delete[] name;
	delete[] grades;

	name = nullptr;
	grades = nullptr;

	gradesCount = 0;

	strcpy(quote, "");
}

GraduateStudent::GraduateStudent(const char* name, const int* grades, size_t gradesCount, const char* quote)
{
	setName(name);
	setGrades(grades, gradesCount);
	setQuote(quote);
}

void GraduateStudent::setName(const char* newName)
{
	if (!newName||newName==name)
	{
		return;
	}
	delete[] name;
	name = new char[strlen(newName)+1];
	strcpy(name, newName);
}

void GraduateStudent::setGrades(const int* newGrades, size_t newGradesCount)
{
	if (!newGrades||newGrades==grades)
	{
		return;
	}
	delete[] grades;
	grades = new int[newGradesCount];
	gradesCount = newGradesCount;
	for (int i = 0; i < newGradesCount; i++)
	{
		grades[i] = newGrades[i];
	}
}

void GraduateStudent::setQuote(const char* newQuote)
{
	if (!newQuote||strlen(newQuote)>30)
	{
		return;
	}
	strcpy(quote, newQuote);
}

GraduateStudent::GraduateStudent(const GraduateStudent& other)
{
	copyFrom(other);
}

GraduateStudent& GraduateStudent::operator=(const GraduateStudent& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

GraduateStudent::GraduateStudent(GraduateStudent&& other) noexcept
{
	moveFrom(std::move(other));
}

GraduateStudent& GraduateStudent::operator=(GraduateStudent&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

GraduateStudent::~GraduateStudent()
{
	free();
}

const char* GraduateStudent::getName() const
{
	return name;
}

const int* GraduateStudent::getGrades() const
{
	return grades;
}

unsigned GraduateStudent::getGradesCount() const
{
	return gradesCount;
}

const char* GraduateStudent::getQuote() const
{
	return quote;
}