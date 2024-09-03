#pragma once
#include <iostream>
#include <fstream>

class Base
{
public:
	virtual ~Base() = default;
};

class A :public Base
{

};

class B :public Base
{

};

class SingletonFactory
{
private:
	SingletonFactory()
	{
		std::ifstream in("data.txt");
		if (!in.is_open())
		{
			throw std::exception("Could not open data.txt");
		}
		in >> numbersSize;
		size_t ind = 0;
		while (!in.eof())
		{
			in>>numbers[ind++];
		}

	}

	size_t current = 0;
	size_t numbersSize = 0;
	size_t* numbers = nullptr;

public:
	Base* create()
	{
		if (current>=numbersSize)
		{
			return nullptr;
		}
		if (numbers[current++]%2==0)
		{
			return new A();
		}
		else
		{
			return new B();
		}
	}
	static SingletonFactory& getInstance()
	{
		static SingletonFactory instance;
		return instance;
	}

	SingletonFactory(const SingletonFactory&) = delete;
	SingletonFactory& operator=(const SingletonFactory&) = delete;
};