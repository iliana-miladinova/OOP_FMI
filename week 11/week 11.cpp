// week 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

void printAreas(const Shape* const* shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
	{
		std::cout << shapes[i]->getArea() << std::endl;
	}
}

void printPers(const Shape* const* shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
	{
		std::cout << shapes[i]->getPer() << std::endl;
	}
}

void checkPointIn(const Shape* const* shapes, size_t shapesCount, int x, int y)
{
	for (int i = 0; i < shapesCount; i++)
	{
		std::cout << shapes[i]->isPointIn(x, y) << std::endl;
	}
}

void freeShapes(Shape** shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
	{
		delete[] shapes[i];
	}
	delete[] shapes;
}


#include "FilePath.h"
#include "BinaryFileReader.h"
#include "BinaryFileWriter.h"
#include "CsvFileReader.h"
#include "CsvFileWriter.h"
#include "ArrFileReader.h"
#include "ArrFileWriter.h"

void selectionSort(int* arr, size_t size)
{
	for (int i = 0; i < size-1; i++)
	{
		int minElInd = i;
		for (int j = i+1; j < size; j++)
		{
			if (arr[j]<arr[minElInd])
			{
				minElInd = j;
			}
		}
		if (minElInd!=i)
		{
			std::swap(arr[minElInd], arr[i]);
		}
	}
}

FileReader* getFileReader(const MyString& str)
{
	FilePath path(str);
	if (path.getExtension()==".dat")
	{
		return new BinaryFileReader(str);
	}
	if (path.getExtension()==".csv")
	{
		return new CSVFileReader(str);
	}
	if (path.getExtension()==".arr")
	{
		return new ArrFileReader(str);
	}
	throw std::exception();
}

FileWriter* getFileWriter(const MyString& str)
{
	FilePath path(str);
	if (path.getExtension()==".dat")
	{
		return new BinaryFileWriter(str);
	}
	if (path.getExtension()==".csv")
	{
		return new CSVFileWriter(str);
	}
	if (path.getExtension()==".arr")
	{
		return new ArrFileWriter(str);
	}
	throw std::exception();
}

void transfer(const MyString& in, const MyString& out)
{
	size_t size;
	FileReader* reader = getFileReader(in);
	int* arr = reader->read(size);

	selectionSort(arr, size);

	FileWriter* writer = getFileWriter(out);
	writer->write(arr, size);

	delete[] arr;
	delete[] reader;
	delete[] writer;
}

#include "Collection.h"
#include "Set.h"
#include "NormalCollection.h"
#include "SortedCollection.h"
#include "IntervalCollection.h"
#include <chrono>

void testPerformance(Collection* collection) {
	std::srand(std::time(nullptr));

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < 50000; ++i) {
		int randomNumber = std::rand() % 10000 + 1;
		collection->add(randomNumber);
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsedTime = end - start;
	std::cout << "Time taken to add 10000 random elements: " << elapsedTime.count() << " seconds" << std::endl;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < 10000; ++i) {
		int randomNumber = std::rand() % 10000 + 1;
		collection->remove(randomNumber);
	}
	end = std::chrono::steady_clock::now();
	elapsedTime = end - start;
	std::cout << "Time taken to remove 5000 random elements: " << elapsedTime.count() << " seconds" << std::endl;

	int randomQueryNumber = std::rand() % 10000 + 1;
	start = std::chrono::steady_clock::now();
	unsigned count = collection->count(randomQueryNumber);
	end = std::chrono::steady_clock::now();
	elapsedTime = end - start;
	std::cout << "Time taken to count occurrences of random element: " << elapsedTime.count() << " seconds" << std::endl;

	randomQueryNumber = std::rand() % 10000 + 1;
	start = std::chrono::steady_clock::now();
	bool contains = collection->contains(randomQueryNumber);
	end = std::chrono::steady_clock::now();
	elapsedTime = end - start;
	std::cout << "Time taken to check if random element is contained: " << elapsedTime.count() << " seconds" << std::endl;
}
int main()
{
	/*Shape** arr = new Shape * [4];

	arr[0] = new Rectangle(3, 4, 6, 8);
	arr[1] = new Circle(3, 3, 4);
	arr[2] = new Circle(1, 4, 5);
	arr[3] = new Triangle(1, 1, 2, 2, 3, 3);

	printAreas(arr, 4);
	std::cout << std::endl;
	printPers(arr, 4);
	std::cout << std::endl;
	checkPointIn(arr, 4, 3, 3);
	std::cout << std::endl;

	freeShapes(arr, 4);*/



	/*transfer("numbers.dat", "numbers.arr");*/


	Collection* c1 = new IntervalCollection(100, 1000);
	Collection* c2 = new NormalCollection();
	Collection* c3 = new SortedCollection();
	Collection* c4 = new Set(NORMAL_COLLECTION);
	Collection* c5 = new Set(SORTED_COLLECTION);

	testPerformance(c1);
	std::cout << std::endl;

	testPerformance(c2);
	std::cout << std::endl;

	testPerformance(c3);
	std::cout << std::endl;

	testPerformance(c4);
	std::cout << std::endl;

	testPerformance(c5);
	std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
