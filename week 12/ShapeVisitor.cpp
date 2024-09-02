#include "ShapeVisitor.h"

Shape1::Shape1(size_t pointsCount) :pointsCount(pointsCount)
{
	points = new point[pointsCount];
}

void Shape1::copyFrom(const Shape1& other)
{
	points = new point[other.pointsCount];
	for (int i = 0; i < other.pointsCount; i++)
	{
		points[i] = other.points[i];
	}
	pointsCount = other.pointsCount;
}

void Shape1::free()
{
	delete[] points;
}

Shape1::Shape1(const Shape1& other)
{
	copyFrom(other);
}

Shape1& Shape1::operator=(const Shape1& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Shape1::~Shape1()
{
	free();
}

const Shape1::point& Shape1::getPointAtIndex(size_t index) const
{
	if (index>=pointsCount)
	{
		throw std::exception("Invalid point index!");
	}
	return points[index];
}

void Shape1::setPoint(size_t pointInd, int x, int y)
{
	if (pointInd>=pointsCount)
	{
		throw std::exception("Invalid point index!");
	}
	points[pointInd] = point(x, y);
}