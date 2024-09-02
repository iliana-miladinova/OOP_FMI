#pragma once
#include "Animal.h"

class Farm
{
private:
	Animal** animals;
	size_t animalsCount;
	size_t capacity;

	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void free();
	void resize();

public:
	Farm();
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);

	Farm(Farm&& other) noexcept;
	Farm& operator=(Farm&& other) noexcept;

	~Farm();

	void addAnimal(AnimalType type);
	void addAnimal(const Animal& animal);
	void roarAll() const;

	AnimalType getTypeByIndex(unsigned ind) const;
};