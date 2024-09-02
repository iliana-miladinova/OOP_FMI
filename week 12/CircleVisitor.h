#pragma once
#include "ShapeVisitor.h"

class Circle1 :public Shape1
{
private:
	double radius;
public:
	Circle1(double radius, int x1, int y1);
	bool intersectsWith(const Shape1* other) const override;
	bool intersectsWithTriangle(const Triangle1* other) const override;
	bool intersectsWithRect(const Rectangle1* other)const override;
	bool intersectsWithCircle(const Circle1* other)const override;
};