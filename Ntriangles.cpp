#include <iostream>
namespace Points
{
	struct Point
	{
		int x = 0;
		int y = 0;
	};

	void readPoint(Point& point)
	{
		std::cin >> point.x;
		std::cin >> point.y;
	}

	double getDistance(const Point& p1, const Point& p2)
	{
		int dx = p1.x - p2.x;
		int dy = p1.y - p2.y;
		return sqrt(dx * dx + dy * dy);
	}

	void printPoint(const Point& point)
	{
		std::cout << "{ " << point.x << ", " << point.y << " }";
	}
}

namespace Figures
{
	using namespace Points;
	struct Triangles
	{
		Point p1;
		Point p2;
		Point p3;
	};

	void readTrinagle(Triangles& triangle)
	{
		readPoint(triangle.p1);
		readPoint(triangle.p2);
		readPoint(triangle.p3);
	}

	double getArea(const Triangles& triangle)
	{
		int sizeA = getDistance(triangle.p1, triangle.p2);
		int sizeB = getDistance(triangle.p2, triangle.p3);
		int sizeC = getDistance(triangle.p3, triangle.p1);

		double halfPer = (sizeA + sizeB + sizeC) / 2;
		return sqrt(halfPer * (halfPer - sizeA) * (halfPer - sizeB) * (halfPer - sizeC));
	}

	void sortTrianglesByArea(Triangles* triangles, size_t N)
	{
		double* areas = new double[N];

		for (int i = 0; i < N; i++)
		{
			areas[i] = getArea(triangles[i]);
		}

		for (int i = 0; i < N-1; i++)
		{
			int minAreaInd = i;
			for (int j = i+1; j < N; j++)
			{
				if (areas[j]<areas[minAreaInd])
				{
					minAreaInd = j;
				}
			}
			if (minAreaInd!=i)
			{
				std::swap(triangles[i], triangles[minAreaInd]);
				std::swap(areas[i], areas[minAreaInd]);
			}
		}
		delete[] areas;
	}
	
	void printTriangle(const Triangles& triangle)
	{
		printPoint(triangle.p1);
		printPoint(triangle.p2);
		printPoint(triangle.p3);
		std::cout<<std::endl;
	}
}

//int main()
//{
//	size_t N;
//	std::cin >> N;
//
//	Figures::Triangles* triangles = new Figures::Triangles[N];
//
//	for (int i = 0; i < N; i++)
//	{
//		Figures::readTrinagle(triangles[i]);
//	}
//
//	Figures::sortTrianglesByArea(triangles, N);
//
//	for (int i = 0; i < N; i++)
//	{
//		Figures::printTriangle(triangles[i]);
//	}
//	delete[] triangles;
//}