#include <iostream>
#include "Interval.h"

void Interval::setA(int a)
{
	if (a>_b)
	{
		a = _b;
	}
	_a = a;
}

void Interval::setB(int b)
{
	if (b<_a)
	{
		b = _a;
	}
	_b = b;
}

int Interval::getA() const
{
	return _a;
}

int Interval::getB() const
{
	return _b;
}

Interval::Interval() :Interval(0, 0)
{

}

Interval::Interval(int a, int b)
{
	if (a>b)
	{
		a = b = 0;
	}
	setA(a);
	setB(b);
}

bool Interval::isInInterval(int x) const
{
	return x >= _a && x <= _b;
}

int Interval::getIntervalLength() const
{
	return _b - _a;
}

namespace
{
	bool isPrime(int x)
	{
		if (x<2)
		{
			return false;
		}

		double temp = sqrt(x);
		for (int i = 2; i < temp; i++)
		{
			if (x%i==0)
			{
				return false;
			}
		}
		return true;
	}

	int reverse(int n)
	{
		int rev = 0;
		while (n!=0)
		{
			rev = rev*10 + n % 10;
			n /= 10;
		}
		return rev;
	}

	bool isPalindrom(int n)
	{
		return n == reverse(n);
	}
}

unsigned Interval::getCountCondition(bool(*pred)(int)) const
{
	int count = 0;
	for (int i = _a; i <= _b ; i++)
	{
		if (pred(i))
		{
			count++;
		}
	}
	return count;
}

unsigned Interval::getPrimesCount() const
{
	return getCountCondition(isPrime);
}

unsigned Interval::getPalindromesCount() const
{
	return getCountCondition(isPalindrom);
}

bool Interval::isSubinterval(const Interval& other) const
{
	return _a>=other._a && _b <=other._b;
}

Interval intersectInterval(const Interval& lhs, const Interval& rhs)
{
	int maxA = std::max(lhs.getA(), rhs.getA());
	int minB = std::min(lhs.getB(), rhs.getB());

	if (maxA>minB)
	{
		throw "Error";
	}

	return Interval(maxA, minB);
}

//int main()
//{
//	Interval i(11, 20);
//	/*std::cout << i.getPrimesCount() << std::endl;*/
//	std::cout << i.getPalindromesCount() << std::endl;
//	std::cout << i.isInInterval(13) << std::endl;
//
//	Interval i2(13, 17);
//	std::cout << i.isSubinterval(i2) << std::endl;
//
//	/*Interval i3 = intersectInterval(i, i2);
//	std::cout << i3.getA() << ' ' << i3.getB() << std::endl;*/
//}