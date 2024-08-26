#include <iostream>
#include <assert.h>

struct Rational
{
	int nom;
	int denom;
};

bool isValid(const Rational& rat)
{
	return rat.denom != 0;
}

void printRational(const Rational& rat)
{
	std::cout << rat.nom << "/" << rat.denom;
}

unsigned getGCD(unsigned a, unsigned b)
{
	if (a<b)
	{
		std::swap(a, b);
	}

	while (b!=0)
	{
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

void rationalize(Rational rat)
{
	assert(isValid(rat));

	unsigned gcd = getGCD(rat.nom, rat.denom);
	rat.nom /= gcd;
	rat.denom /= gcd;

	if ((rat.nom<0&&rat.denom<0)||(rat.nom>0&&rat.denom<0))
	{
		rat.nom *= -1;
		rat.denom *= -1;
	}
}

Rational& plus(Rational& lhs, const Rational& rhs)
{
	assert(isValid(lhs) && isValid(rhs));

	lhs.nom *= rhs.denom;
	lhs.nom += rhs.nom * lhs.denom;
	lhs.denom *= rhs.denom;
	rationalize(lhs);
	return lhs;
}

Rational plusAndGetNewObj(const Rational& lhs, const Rational& rhs)
{
	assert(isValid(lhs) && isValid(rhs));
	Rational copyLhs = lhs;
	plus(copyLhs, rhs);
	return copyLhs;
}

//int main()
//{
//	Rational r1{ 1,4 };
//	Rational r2{ 1,3 };
//
//	Rational r3 = plusAndGetNewObj(r1, r2);
//	printRational(r3);
//
//	std::cout << std::endl;
//	plus(r1, r3);
//	printRational(r1);
//}