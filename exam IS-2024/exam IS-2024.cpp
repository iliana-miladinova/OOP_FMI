// exam IS-2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SetByCriteria.hpp"
#include "SetOperation.h"
#include "IntersectionOfSets.h"
#include "UnionOfSets.h"
#include "Set.h"
#include <fstream>

struct ExampleCriteria
{
    bool include = false;
    size_t size = 0;
    int arr[32] = { 0 };

    bool operator()(unsigned n) const
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i]==n)
            {
                return include;
            }
        }
        return !include;
    }
};

void readFileToArr(const char* fileName, int* arr, size_t& size, size_t maxSize)
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }

    size = 0;
    while (true)
    {
        ifs >> arr[size];
        size++;
        if (ifs.eof())
        {
            return;
        }
    }
}

void printSetInterval(const Set& set, unsigned begin, unsigned end)
{
    for (unsigned i = begin; i <= end ; i++)
    {
        if (set.accepts(i))
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}
int main()
{
    ExampleCriteria cr1;
    cr1.include = true;
    readFileToArr("include.txt", cr1.arr, cr1.size, 32);

    ExampleCriteria cr2;
    cr2.include = false;
    readFileToArr("exclude.txt", cr2.arr, cr2.size, 32);

    SetByCriteria<ExampleCriteria> s1(cr1);
    SetByCriteria<ExampleCriteria> s2(cr2);
    SetByCriteria<bool(*)(unsigned)> s3([](unsigned n) {return n % 2 == 0; });

    const Set** sets = new const Set * [3] {&s1, & s2, & s3};
    IntersectionOfSets s4(sets, 3);
    UnionOfSets s5(sets, 3);

    printSetInterval(s1, 0, 10);
    printSetInterval(s2, 0, 10);
    printSetInterval(s3, 0, 10);
    printSetInterval(s4, 0, 10);
    printSetInterval(s5, 0, 10);

    delete[] sets;
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
