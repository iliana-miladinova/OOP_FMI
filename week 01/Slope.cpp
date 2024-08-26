#include <iostream>

struct Point
{
	int x;
	int y;
};

struct Line
{
	Point p1;
	Point p2;
};

double getSlope(const Line& myLine)
{
	double dx = myLine.p1.x - myLine.p2.x;
	double dy = myLine.p1.y - myLine.p2.y;
	return dy / dx;
}

bool areParallel(const Line& l1, const Line& l2)
{
	return getSlope(l1) == getSlope(l2);
}

//int main()
//{
//	Line l1 = { 1,2,3,4 };
//	Line l2 = { 0,1,2,3 };
//	std::cout << areParallel(l1, l2);
//}