#pragma once
#include "RestaurantItem.h"

class Restaurant
{
private:
	RestaurantItem** items;
	size_t itemsCount;
	size_t capacity;

	void resize();
	void free();
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);

public:
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void addItem(const RestaurantItem& item);
	void removeItem(size_t ind);
	void changePrice(size_t ind, double price);
	void changeName(size_t ind, const char* name);
	void printAll() const;

	void printAllWithoutAlcohol() const;
};