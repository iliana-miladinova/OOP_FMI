#pragma once
#include <iostream>

class Triangle1;
class Rectangle1;
class Circle1;

class Shape1
{
protected:
	struct point
	{
		int x;
		int y;
		point() :x(0), y(0) {}
		point(int x, int y) :x(x), y(y) {}
		double getDist(const point& other)
		{
			int dx = x - other.x;
			int dy = y - other.y;
			return sqrt(dx * dx + dy * dy);
		}
	};
	const point& getPointAtIndex(size_t index) const;

private:
	point* points;
	size_t pointsCount;

	void copyFrom(const Shape1& other);
	void free();

public:
	Shape1(size_t pointsCount);
	Shape1(const Shape1& other);
	Shape1& operator=(const Shape1& other);
	
	virtual ~Shape1();

	void setPoint(size_t pointInd, int x, int y);

	virtual bool intersectsWith(const Shape1* other)const = 0;

	virtual bool intersectsWithTriangle(const Triangle1* other) const = 0;
	virtual bool intersectsWithRect(const Rectangle1* other) const = 0;
	virtual bool intersectsWithCircle(const Circle1* other)const = 0;
};