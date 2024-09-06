#include "ThreeNumbersWrapperCondition.h"

bool CustomPredicates::allValid(int a, int b, int c)
{
	return true;
}

bool ThreeNumbersWrapperCondition::isValidValue(int value) const
{
	return value >= MIN_VALUE && value <= MAX_VALUE;
}

bool ThreeNumbersWrapperCondition::goToNextElement()
{
	if (!isGood())
	{
		return false;
	}
	c = (c + 1) % (MAX_VALUE + 1);
	if (c==0)
	{
		b = (b + 1) % (MAX_VALUE + 1);
		if (b==0)
		{
			a = (a + 1) % (MAX_VALUE + 1);
			if (a==0)
			{
				return false;//izcherpali sme vsicki vazmojni kombinacii i poveche ne mojem da uvelichavame elemnta
			}
		}
	}
	return true;
}

void ThreeNumbersWrapperCondition::validateState()
{
	good = isValidValue(a) && isValidValue(b) && isValidValue(c);
}

ThreeNumbersWrapperCondition::ThreeNumbersWrapperCondition(bool(*pedicate)(int, int, int)) :predicate(predicate)
{
	goToNextElement();//Методът goToNextValidElement() обхожда всички възможни 
	//комбинации от стойности за a, b и c, докато не намери първата валидна комбинация,
	//която удовлетворява предиката. Ако текущите стойности не са валидни, 
	//методът инкрементира стойностите с помощта на goToNextElement() и ги 
	//проверява отново.
}

void ThreeNumbersWrapperCondition::goToNextValidElement()
{
	while (!predicate(a,b,c)&&goToNextElement())
	{

	}
	validateState();
}

bool ThreeNumbersWrapperCondition::isGood() const
{
	return good;
}

void ThreeNumbersWrapperCondition::setVector(int newA, int newB, int newC)
{
	if (!isGood())
	{
		return;
	}
	a = newA;
	b = newB;
	c = newC;
	isModified = true;

	validateState();
}

ThreeNumbersWrapperCondition::ThreeNumbersWrapperCondition(int newA, int newB, int newC, bool(*predicate)(int,int,int)):
								predicate(predicate)
{
	setVector(newA, newB, newC);
	
}

void ThreeNumbersWrapperCondition::setA(int newA)
{
	if (!isGood())
	{
		return;
	}

	a = newA;
	isModified = true;

	validateState();
}

void ThreeNumbersWrapperCondition::setB(int newB)
{
	if (!isGood())
	{
		return;
	}
	b = newB;
	isModified = true;

	validateState();
}

void ThreeNumbersWrapperCondition::setC(int newC)
{
	if (!isGood())
	{
		return;
	}
	c = newC;
	isModified = true;

	validateState();
}

int ThreeNumbersWrapperCondition::getA() const
{
	if (!isGood())
	{
		return -1;
	}
	return a;
}

int ThreeNumbersWrapperCondition::getB() const
{
	if (!isGood())
	{
		return -1;
	}
	return b;
}

int ThreeNumbersWrapperCondition::getC() const
{
	if (!isGood())
	{
		return -1;
	}
	return c;
}

int ThreeNumbersWrapperCondition::getIndex() const
{
	if (!isGood())
	{
		return -1;
	}

	if (!isModified)
	{
		return elementsBeforeCount;
	}

	elementsBeforeCount = 0;
	ThreeNumbersWrapperCondition start(predicate);

	while (compare(start,*this)<0)
	{
		elementsBeforeCount++;
		start.goToNextValidElement();
	}
	isModified = false;
	return elementsBeforeCount;
}

int compare(const ThreeNumbersWrapperCondition& lhs, const ThreeNumbersWrapperCondition& rhs)
{
	if (lhs.a!=rhs.a)
	{
		return lhs.a - rhs.a;
	}
	if (lhs.b!=rhs.b)
	{
		return lhs.b - rhs.b;
	}
	if (lhs.c!=rhs.c)
	{
		return lhs.c - rhs.c;
	}
	return 0;
}