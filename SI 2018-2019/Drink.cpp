#include "Drink.h"

Drink::Drink()
{
	setProduct(Product::DRINK);
}

Drink::Drink(const char* name, unsigned quantity, double price, double alcoholPerc) :
	RestaurantItem(name, DRINK, amount, price)
{
	setAlcoholPerc(alcoholPerc);
}

void Drink::setAlcoholPerc(double alcoholPerc)
{
	this->alcoholPerc = alcoholPerc;
}

void Drink::print() const
{
	RestaurantItem::print();
	std::cout << "Alcohol Percantage: " << alcoholPerc << "%" << std::endl;
}

double Drink::getAlcoholPers() const
{
	return alcoholPerc;
}

RestaurantItem* Drink::clone() const
{
	return new Drink(*this);
}

bool operator>(const Drink& lhs, const Drink& rhs)
{
	return lhs.alcoholPerc > rhs.alcoholPerc;
}