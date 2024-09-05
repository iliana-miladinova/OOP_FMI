#pragma once
#include <iostream>

using UnaryUnsignedFunction = unsigned(*)(unsigned);

class NaturalNumbersFunction
{
protected:
	UnaryUnsignedFunction m_pFunc;
public:
	NaturalNumbersFunction();
	explicit NaturalNumbersFunction(UnaryUnsignedFunction pFunc);
	virtual ~NaturalNumbersFunction() = default;

	unsigned countFixedPoints(int lowerBound, int UpperBound) const;

	virtual unsigned operator()(unsigned x) const;
	virtual void setFunction(UnaryUnsignedFunction pFunc);
};

bool ckeckBounds(int& lowerBound, int& upperBound);
bool checkFunctionsInInterval(const NaturalNumbersFunction& lhs, const NaturalNumbersFunction& rhs, int lowerBound, int upperBound);