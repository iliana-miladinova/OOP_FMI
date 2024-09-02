#pragma once
#include <iostream>

enum class AnimalType
{
	Dog,
	Cat, 
	Cow
};

class Animal
{
private:
	//ще запазваме типа в член-данна,
	//за да можем да разпознаваме обектите
	AnimalType type;
public:
	Animal(AnimalType type);
	virtual void roar() const = 0;
	virtual Animal* clone() const = 0;//създава копие на текущия обект.
	virtual ~Animal() = default;

	AnimalType getType() const;

};