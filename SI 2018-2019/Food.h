#pragma once
#include "RestaurantItem.h"

class Food : public RestaurantItem
{
private:
	double grammage = 0.0;
public:
	Food();
	Food(const char* name, unsigned amount, double price, double grammage);

	void setGrammage(double Grammage);
	double getGrammage() const;

	void print() const override;
	RestaurantItem* clone() const override;
};

bool operator>(const Food& lhs, const Food& rhs);