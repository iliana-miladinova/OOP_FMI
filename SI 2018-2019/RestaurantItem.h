#pragma once
#include <iostream>
#pragma warning(disable:4996)

enum Product
{
	DEFAULT,
	FOOD,
	DRINK
};
class RestaurantItem
{
protected:
	Product product = Product::DEFAULT;
	unsigned amount = 0;
	double price = 0.0;
	char* name = nullptr;

public:
	RestaurantItem() = default;
	RestaurantItem(const char* name, const Product& product, unsigned amount, double price);
	const Product& getProduct() const;
	unsigned getAmount() const;
	double getPrice() const;
	const char* getName()const;

	void setProduct(const Product& product);
	void setAmount(unsigned amount);
	void setPrice(double Price);
	void setName(const char* name);

	virtual ~RestaurantItem() = default;
	virtual RestaurantItem* clone() const = 0;
	virtual void print() const = 0;
};