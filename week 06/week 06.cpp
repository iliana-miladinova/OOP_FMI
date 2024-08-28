// week 06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DynamicSet.h"

int main()
{
    DynamicSet s1(1024);

    s1.add(1);
    s1.add(4);
    s1.add(128);
    s1.add(13);
    s1.add(20);

    s1.print();

    std::cout << std::endl;
    s1.remove(128);
    s1.print();
    std::cout << std::endl;
    DynamicSet s2(10);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s2.add(6);
    s2.add(7);
    s2.print();
    std::cout << std::endl;

    DynamicSet unionSet = unionOfSets(s1, s2);
    unionSet.print();
    std::cout << std::endl;
    DynamicSet intersectionSet = intersectionOfSets(s1, s2);
    intersectionSet.print();
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
