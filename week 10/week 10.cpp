// week 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

#include "StringView.h"
#include "SetByCriteria.h"
#include "SetByString.h"

bool even(unsigned n)
{
    return n % 2 == 0;
}

bool multipleOfThree(unsigned n)
{
    return n % 3 == 0;
}
int main()
{
    //char subjects[3][20] = { "English","Mathematics","Physics" };

    //char** subjectsPointer = new char* [3];
    //subjectsPointer[0] = subjects[0];
    //subjectsPointer[1] = subjects[1];
    //subjectsPointer[2] = subjects[2];

    //Teacher t("Prof. Ivanov", 33, subjectsPointer, 3);
    //std::cout << t.getName() << std::endl;
    //delete[] subjectsPointer; //only the pointers - not the data!

    //MyString test = "Hello, Iliana";
    //StringView res(test);
    //StringView res2 = res.substr(7, 6);
    //std::cout << res << std::endl;
    //std::cout << res2<<std::endl;

    //SetByCriteria set(10, even);  // Множество от четни числа от 0 до 10
    //set.print();

    //set.setInclude(multipleOfThree); // Обновява множеството да съдържа кратните на 3 числа
    //set.print();

    SetByString s(1000, "1 5 9");
    s.print();
    s.setAt(1, '8');
    s.print();
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
