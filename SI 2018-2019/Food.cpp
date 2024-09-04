#include "Food.h"

Food::Food() 
{
	setProduct(FOOD);
}

Food::Food(const char* name, unsigned amount, double price, double grammage) :
	RestaurantItem(name, FOOD, amount, price), grammage(grammage)
{

}

void Food::setGrammage(double grammage)
{
	this->grammage = grammage;
}

double Food::getGrammage() const
{
	return grammage;
}

void Food::print() const 
{
	RestaurantItem::print();
	std::cout << "Product: " << "food" << std::endl;
	std::cout << "Grammage: " << grammage << std::endl;
}

bool operator>(const Food& lhs, const Food& rhs)
{
	return lhs.getGrammage() > rhs.getGrammage();
}

RestaurantItem* Food::clone() const
{
	return new Food(*this);
}