#include "RectangleVisitor.h"

Rectangle1::Rectangle1(int x1, int y1, int x3, int y3) :Shape1(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);
}

bool Rectangle1::intersectsWith(const Shape1* other) const
{
	return other->intersectsWithRect(this);
}

bool Rectangle1::intersectsWithTriangle(const Triangle1* other) const
{
	std::cout << "Formula for rect with triangle" << std::endl;
	return true;
}

bool Rectangle1::intersectsWithRect(const Rectangle1* other) const
{
	std::cout << "Formula for rect with rect" << std::endl;
	return true;
}

bool Rectangle1::intersectsWithCircle(const Circle1* other) const
{
	std::cout << "Fromula for rect with circle" << std::endl;
	return true;
}