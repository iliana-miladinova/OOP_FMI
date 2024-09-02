#pragma once
#include "ShapeVisitor.h"

class Triangle1 :public Shape1
{
public:
	Triangle1(int x1, int y1, int x2, int y2, int x3, int y3);

	bool intersectsWith(const Shape1* other) const override;
	bool intersectsWithTriangle(const Triangle1* other) const override;
	bool intersectsWithRect(const Rectangle1* other) const override;
	bool intersectsWithCircle(const Circle1* other) const override;
};