#pragma once
#include <iostream>

namespace CustomPredicates
{
	bool allValid(int, int, int);
}

class ThreeNumbersWrapperCondition
{
private:
	static const int MAX_VALUE = 999;
	static const int MIN_VALUE = 0;

	int a = 0;
	int b = 0;
	int c = 0;

	bool good = true;

	bool (*predicate)(int, int, int) = CustomPredicates::allValid;

	mutable bool isModified = true;
	mutable size_t elementsBeforeCount = 0;

	bool isValidValue(int value) const;
	bool goToNextElement();
	void validateState();

public:
	ThreeNumbersWrapperCondition() = default;
	ThreeNumbersWrapperCondition(bool(*predicate)(int, int, int));
	ThreeNumbersWrapperCondition(int newA, int newB, int newC, bool(*predicate)(int, int, int));

	void setVector(int newA, int newB, int newC);
	void setA(int newA);
	void setB(int newB);
	void setC(int newC);

	int getA() const;
	int getB() const;
	int getC() const;

	bool isGood() const;
	int getIndex() const;
	void goToNextValidElement();

	friend int compare(const ThreeNumbersWrapperCondition& lhs, const ThreeNumbersWrapperCondition& rhs);
};