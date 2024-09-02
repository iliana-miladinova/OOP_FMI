#include <iostream>
#include "TriangleVisitor.h"
#include "RectangleVisitor.h"
#include "CircleVisitor.h"

bool intersect(const Shape1* sh1, const Shape1* sh2)
{
	return sh1->intersectsWith(sh2);
}

int main()
{
	Shape1** arr = new Shape1 * [4];

	arr[0] = new Rectangle1(3, 4, 6, 8);
	arr[1] = new Circle1(3, 3, 4);
	arr[2] = new Circle1(1, 4, 5);
	arr[3] = new Triangle1(1, 1, 2, 2, 3, 3);

	intersect(arr[0], arr[1]);
	intersect(arr[1], arr[2]);
	intersect(arr[2], arr[3]);

	for (int i = 0; i < 4; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}