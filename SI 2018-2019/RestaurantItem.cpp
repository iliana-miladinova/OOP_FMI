#include "RestaurantItem.h"

//RestaurantItem::RestaurantItem(const char* name, const Product& product, unsigned amount, double price) :product(product), amount(amount), price(price)
//{
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}

RestaurantItem::RestaurantItem(const char* name, const Product& product, unsigned amount, double price)
{
	setName(name);
	setAmount(amount);
	setPrice(price);
	setProduct(product);
}

const Product& RestaurantItem::getProduct() const
{
	return product;
}

unsigned RestaurantItem::getAmount() const
{
	return amount;
}

double RestaurantItem::getPrice() const
{
	return price;
}

void RestaurantItem::setProduct(const Product& product)
{
	this->product = product;
}

void RestaurantItem::setAmount(unsigned amount)
{
	this->amount = amount;
}

void RestaurantItem::setPrice(double price)
{
	this->price = price;
}

void RestaurantItem::setName(const char* name)
{
	if (!name||this->name==name)
	{
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* RestaurantItem::getName() const
{
	return name;
}

void RestaurantItem::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Amount: " << amount << std::endl;
	std::cout << "Price: " << price << std::endl;
}