// week 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

////task with enums
//enum Color { red, green, blue };
//enum Card { red_card, green_card, yellow_card };
//enum class Animal { dog, deer, cat, bird, human };
//enum class Mammal { kangaroo, deer, human };
//int main()
//{
//    //examples of bad use
//    Color color = Color::green;
//    Card card = Card::red_card;
//    int num = color;//no problem
//    if (color==Card::green_card)
//    {
//        std::cout << "bad" << std::endl;
//    }
//
//    if (card==Color::red)
//    {
//        std::cout << "bad" << std::endl;
//    }
//
//    //examples of good use of enum class
//    Animal animal = Animal::deer;
//    Mammal mammal = Mammal::deer;
//
//    int num1 = animal;//error
//    if (animal==mammal)
//    {
//        std::cout << "error" << std::endl;
//    }
//
//    if (animal==Mammal::deer)
//    {
//        std::cout << "error" << std::endl;
//    }
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
