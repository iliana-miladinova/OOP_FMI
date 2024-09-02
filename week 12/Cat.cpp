#include "Cat.h"

Cat::Cat() :Animal(AnimalType::Cat)
{

}

void Cat::roar() const
{
	std::cout << "Meow, meow" << std::endl;
}

Animal* Cat::clone() const
{
	Animal* obj =new (std::nothrow)Cat(*this); //Copy const of mouse
	return obj;

	//return new Cat(*this)
}