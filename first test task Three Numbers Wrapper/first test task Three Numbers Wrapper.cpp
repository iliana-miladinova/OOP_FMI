// first test task Three Numbers Wrapper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ThreeNumbersWrapperCondition.h"

bool customPredicate(int a, int b, int c)
{
	return (a + b + c) % 3 == 0;
}
int main()
{
	ThreeNumbersWrapperCondition obj1;
	ThreeNumbersWrapperCondition obj2(1, 2, 3, customPredicate);

	std::cout << "Initial values of obj1: (" << obj1.getA() << ", " << obj1.getB() << ", " << obj1.getC()<<')' << std::endl;
	std::cout << "Initial values of obj2: (" << obj2.getA() << ", " << obj2.getB() << ", " << obj2.getC()<<')' << std::endl;

	obj1.setVector(3, 2, 1);
	obj1.setA(4);
	obj2.setB(5);
	obj2.setC(6);

	std::cout << "Updated values of obj1: (" << obj1.getA() << ", " << obj1.getB() << ", " << obj1.getC()<<')' << std::endl;
	std::cout << "Updated values of obj2: (" << obj2.getA() << ", " << obj2.getB() << ", " << obj2.getC() <<')' << std::endl;

	std::cout << "Index of obj1: " << obj1.getIndex() << std::endl;
	std::cout << "Index of obj2: " << obj2.getIndex() << std::endl;

	std::cout << "Is obj1 good? " << obj1.isGood() << std::endl;
	std::cout << "Is obj2 good? " << obj2.isGood() << std::endl;

	ThreeNumbersWrapperCondition obj3(1, 2, 3, customPredicate);
	ThreeNumbersWrapperCondition obj4(1, 2, 4, customPredicate);

	std::cout << "Comparing obj3 and obj4: " << compare(obj3, obj4) << std::endl;

	obj1.goToNextValidElement();
	std::cout << "After moving to next valid element, obj1 values: (" << obj1.getA() << ", " << obj1.getB() << ", " << obj1.getC() <<')' << std::endl;
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
