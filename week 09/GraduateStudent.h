#pragma once
#include <iostream>

class GraduateStudent
{
private:
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;
	char quote[30 + 1] = "";

	void copyFrom(const GraduateStudent& other);
	void moveFrom(GraduateStudent&& other);
	void free();

public:
	GraduateStudent(const char* name, const int* grades, size_t gradesCount, const char* quote);
	GraduateStudent(const GraduateStudent& other);
	GraduateStudent& operator=(const GraduateStudent& other);
	GraduateStudent(GraduateStudent&& other) noexcept;
	GraduateStudent& operator=(GraduateStudent&& other) noexcept;
	~GraduateStudent();

	void setName(const char* newName);
	void setGrades(const int* newGrades, size_t newGradesCount);
	void setQuote(const char* newQuote);

	const char* getName() const;
	const int* getGrades() const;
	unsigned getGradesCount() const;
	const char* getQuote() const;
};