#pragma once
#include "RestaurantItem.h"

class Drink : public RestaurantItem
{
private:
	double alcoholPerc = 0;

public:
	Drink();
	Drink(const char* name, unsigned quantity, double price, double alcoholPerc);

	void setAlcoholPerc(double alcoholPerc);
	double getAlcoholPers() const;
	friend bool operator>(const Drink& lhs, const Drink& rhs);

	void print() const override;
	RestaurantItem* clone() const override;
};

bool operator>(const Drink& lhs, const Drink& rhs);