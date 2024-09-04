// SI 2018-2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.hpp"
#include "RestaurantItem.h"
#include "Food.h"
#include "Drink.h"
#include "Restaurant.h"

int main()
{
	/*Matrix<int> test1(2,2);
	test1.setAt(1, 1, 5);
	test1.setAt(1, 2, 3);
	test1.setAt(2, 1, 4);
	test1.setAt(2, 2, 1);
	test1.print();
	std::cout<<std::endl;
	test1.transpose();
	test1.print();*/
	
	Food t1;
	t1.setName("Pizza");
	t1.setGrammage(0.400);
	t1.setAmount(30);
	t1.setPrice(5.50);

	Drink t2;
	t2.setName("Water");
	t2.setAlcoholPerc(0);
	t2.setAmount(100);
	t2.setPrice(2.80);

	Restaurant restaurant;
	restaurant.addItem(t1);
	restaurant.addItem(t2);
	restaurant.changePrice(1, 1.80);
	restaurant.printAll();
	restaurant.printAllWithoutAlcohol();
	restaurant.removeItem(0);
	restaurant.printAll();

	Food t3;
	t3.setName("Musaka");
	t3.setGrammage(0.400);
	t3.setAmount(50);
	t3.setPrice(6.10);

	restaurant.addItem(t3);
	restaurant.printAll();

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
