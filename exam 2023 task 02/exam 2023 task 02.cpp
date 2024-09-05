// exam 2023 task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ModifiableNaturalNumbersFunction.h"

unsigned doubleValue(unsigned x)
{
    return x * 2;
}

unsigned squareValue(unsigned x)
{
    return x * x;
}
int main()
{
    ModifiableNaturalNumbersFunction m;
    std::cout << m(5)<<std::endl;
    std::cout << m(3)<<std::endl;
    
    std::cout << m.countFixedPoints(0, 10)<<std::endl;

    ModifiableNaturalNumbersFunction m2(doubleValue, 3);
    std::cout << m2(5) << std::endl;
    m2.modify(6, 15);
    std::cout << m2(6) << std::endl;
    m2.removeModification(6);
    std::cout << m2(6) << std::endl;
    m2.setFunction(squareValue);
    std::cout << m2(6) << std::endl;
    m2.modify(7, 21);
    std::cout << m2(7) << std::endl;

    NaturalNumbersFunction n1;
    NaturalNumbersFunction n2;
    NaturalNumbersFunction n3(doubleValue);
    std::cout << checkFunctionsInInterval(n1, n2, 0, 10) << std::endl;
    std::cout << checkFunctionsInInterval(n1, n3, 0, 10) << std::endl;
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
