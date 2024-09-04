#include "Restaurant.h"
#include "Drink.h"

void Restaurant::resize()
{
	RestaurantItem** newItems = new RestaurantItem * [capacity *= 2];
	for (size_t i = 0; i < itemsCount; i++)
	{
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
}

void Restaurant::copyFrom(const Restaurant& other)
{
	items = new RestaurantItem * [other.capacity];
	itemsCount = other.itemsCount;
	capacity = other.capacity;

	for (int i = 0; i < itemsCount; i++)
	{
		RestaurantItem* cloned = other.items[i]->clone();
		if (cloned)
		{
			items[i] = cloned;
		}
	}
}

void Restaurant::moveFrom(Restaurant&& other)
{
	items = other.items;
	other.items = nullptr;

	itemsCount = other.itemsCount;
	other.itemsCount = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void Restaurant::free()
{
	for (int i = 0; i < itemsCount; i++)
	{
		delete[] items[i];
	}
	delete[] items;
}

Restaurant::Restaurant(const Restaurant& other)
{
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
{
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Restaurant::~Restaurant()
{
	free();
}

Restaurant::Restaurant()
{
	capacity = 8;
	itemsCount = 0;
	items = new RestaurantItem * [capacity];
}

void Restaurant::addItem(const RestaurantItem& item)
{
	if (itemsCount==capacity)
	{
		resize();
	}
	items[itemsCount++] = item.clone();
}

void Restaurant::removeItem(size_t ind)
{
	if (ind>=itemsCount)
	{
		return;
	}

	delete items[ind];
	items[ind] = nullptr;

	std::swap(items[itemsCount - 1], items[ind]);
	itemsCount--;
}

void Restaurant::changePrice(size_t ind, double price)
{
	if (ind>=itemsCount)
	{
		return;
	}

	items[ind]->setPrice(price);
}

void Restaurant::changeName(size_t ind, const char* name)
{
	if (ind>=itemsCount)
	{
		return;
	}
	items[ind]->setName(name);
}

void Restaurant::printAll() const
{
	for (int i = 0; i < itemsCount; i++)
	{
		items[i]->print();
		if (i!=itemsCount-1)
		{
			std::cout << "--------" << std::endl;
		}
	}
	std::cout << "********" << std::endl;
}

void Restaurant::printAllWithoutAlcohol() const
{
	for (int i = 0; i < itemsCount; i++)
	{
		Drink* drink = dynamic_cast<Drink*>(items[i]);
		if (drink && drink->getAlcoholPers()==0.0)
		{
			drink->print();
			if (i!=itemsCount-1)
			{
				std::cout << "--------" << std::endl;
			}
		}
	}
	std::cout << "********" << std::endl;
}