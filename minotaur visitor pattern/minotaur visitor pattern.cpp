// minotaur visitor pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Minotaur.h"
#include "Centaur.h"
#include "Sphinx.h"
#include "Battle.h"

int main()
{
    Battle b;

    Minotaur m;
    Centaur c;
    Sphinx s;

    b.addCreature(m);
    b.addCreature(c);
    b.addCreature(s);
    b.addCreature(c);
    b.addCreature(s);
    b.addCreature(s);

    std::cout << b.fightAll(0) << std::endl;

    b.removeCreature(2);
    std::cout << b.fightAll(0) << std::endl;
    std::cout << b.fightAll(1) << std::endl;
    std::cout << b.fightAll(3) << std::endl;
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
