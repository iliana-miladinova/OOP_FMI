#include "TriangleVisitor.h"

Triangle1::Triangle1(int x1, int y1, int x2, int y2, int x3, int y3) :Shape1(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

bool Triangle1::intersectsWith(const Shape1* other) const
{
	return other->intersectsWithTriangle(this);
}

bool Triangle1::intersectsWithTriangle(const Triangle1* other)const
{
	std::cout << "Formula for triangle with triangle" << std::endl;
	return true;
}

bool Triangle1::intersectsWithRect(const Rectangle1* other) const
{
	std::cout << "Formula for triangle with rect" << std::endl;
	return true;
}

bool Triangle1::intersectsWithCircle(const Circle1* other) const
{
	std::cout << "Formula for triangle with circle" << std::endl;
	return true;
}