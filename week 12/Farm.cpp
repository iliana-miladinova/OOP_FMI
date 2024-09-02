#include "Farm.h"
#include "AnimalFactory.h"

void Farm::copyFrom(const Farm& other)
{
	animals = new Animal * [other.capacity];
	animalsCount = other.animalsCount;
	capacity = other.capacity;

	for (int i = 0; i < animalsCount; i++)
	{
		Animal* cloned = other.animals[i]->clone();
		if (cloned) //nullptr check
		{
			animals[i] = cloned;
		}
	}
}

void Farm::moveFrom(Farm&& other)
{
	animals = other.animals;
	other.animals = nullptr;

	animalsCount = other.animalsCount;
	other.animalsCount = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void Farm::free()
{
	for (int i = 0; i < animalsCount; i++)
	{
		delete[] animals[i];  //не се инт. какъв обект е. (вирт дестр)
	}
	delete[] animals;
}

void Farm::resize()
{
	Animal** newCollection = new Animal * [capacity *= 2];
	for (int i = 0; i < animalsCount; i++)
	{
		newCollection[i] = animals[i]; // !!не правим клониране
	}
	delete[] animals;
	animals = newCollection;
}

Farm::Farm()
{
	capacity = 8;
	animalsCount = 0;
	animals = new Animal * [capacity];
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Farm::~Farm()
{
	free();
}

void Farm::addAnimal(AnimalType animalType)
{
	if (animalsCount==capacity)
	{
		resize();
	}
	animals[animalsCount++] = animalFactory(animalType);
}

void Farm::addAnimal(const Animal& animal)
{
	if (animalsCount==capacity)
	{
		resize();
	}
	animals[animalsCount++] = animal.clone();
}

void Farm::roarAll() const
{
	for (int i = 0; i < animalsCount; i++)
	{
		animals[i]->roar();
	}
}

AnimalType Farm::getTypeByIndex(unsigned ind) const
{
	if (ind>animalsCount)
	{
		std::out_of_range("Invalid index");
	}
	return animals[ind]->getType();
}