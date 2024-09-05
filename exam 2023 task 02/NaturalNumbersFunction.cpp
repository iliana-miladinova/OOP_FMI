#include "NaturalNumbersFunction.h"

NaturalNumbersFunction::NaturalNumbersFunction()
{
	// Identity function: f(x) = x
	m_pFunc = [](unsigned x) 
		{
			return x; 
		};
}

NaturalNumbersFunction::NaturalNumbersFunction(UnaryUnsignedFunction pFunc) :
	m_pFunc(pFunc)
{

}

void NaturalNumbersFunction::setFunction(UnaryUnsignedFunction pFunc)
{
	m_pFunc = pFunc;
}

unsigned NaturalNumbersFunction::operator()(unsigned x) const
{
	return m_pFunc(x);
}

bool ckeckBounds(int& lowerBound, int& upperBound)
{
	if (lowerBound>upperBound)
	{
		std::swap(lowerBound, upperBound);
	}
	if (upperBound<0)
	{
		return false;
	}
	if (lowerBound<0)
	{
		lowerBound = 0;
	}
	return true;
}

unsigned NaturalNumbersFunction::countFixedPoints(int lowerBound, int upperBound) const
{
	if (!ckeckBounds(lowerBound,upperBound))
	{
		return 0;
	}

	unsigned count = 0;
	for (int i = lowerBound; i <= upperBound ; i++)
	{
		if (this->operator()(i)==i)
		{
			count++;
		}
	}
	return count;
}

bool checkFunctionsInInterval(const NaturalNumbersFunction& lhs, const NaturalNumbersFunction& rhs, int lowerBound, int upperBound)
{
	if (!ckeckBounds(lowerBound,upperBound))
	{
		throw std::invalid_argument("Invalid argument");
	}

	for (int i = lowerBound; i <= upperBound ; i++)
	{
		if (lhs(i)!=rhs(i))
		{
			return false;
		}
	}
	return true;
}