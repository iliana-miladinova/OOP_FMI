#include "CircleVisitor.h"

Circle1::Circle1(double radius, int x, int y) :Shape1(1), radius(radius)
{
	setPoint(0, x, y);
}

bool Circle1::intersectsWith(const Shape1* other) const
{
	return other->intersectsWithCircle(this);
}

bool Circle1::intersectsWithTriangle(const Triangle1* other) const
{
	std::cout << "Formula for circle with triangle" << std::endl;
	return true;
}

bool Circle1::intersectsWithRect(const Rectangle1* other) const
{
	std::cout << "Formula for circle with rect" << std::endl;
	return true;
}

bool Circle1::intersectsWithCircle(const Circle1* other) const
{
	std::cout << "Formula for circle with circle" << std::endl;
	return true;
}