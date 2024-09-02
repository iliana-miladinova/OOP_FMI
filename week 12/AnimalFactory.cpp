#include "AnimalFactory.h"
#include "Cat.h"
#include "Cow.h"
#include "Dog.h"

Animal* animalFactory(AnimalType type)
{
	switch (type)
	{
	case AnimalType::Dog:
		return new Dog();
	case AnimalType::Cat:
		return new Cat();
	case AnimalType::Cow:
		return new Cow();
	}
	return nullptr;
}