// week 07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NVector.h"
#include "Complex.h"
#include "MyString.h"

int main()
{
   /* NVector v(3);
    v[2] = 10;
    NVector v2 = 3 * v;
    std::cout << v2;*/

  /*  Complex c(3, 4);
    Complex c2(3, 4);
    std::cout << c * c2;*/

    MyString test = "test str";
    std::cout << test << " ";
    std::cout << test.getSize() << " " << test.getCapacity() << std::endl;

    MyString test2;
    std::cin >> test2;

    MyString test3 = test + test2;
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
    std::cout << test3 << std::endl;

    test3 += test3;
    std::cout << test3 << std::endl;
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
