#pragma once
#include <iostream>

class Base1
{
public:
	virtual ~Base1() = default;
};

class Der1 :public Base1 {};

class Der2 :public Base1 {};

//FactoryMethod
class BaseFactory
{
public:
	virtual Base1* create() const = 0;
	virtual ~BaseFactory() = default;
};

class Der1Factory :public BaseFactory
{
public:
	Base1* create() const override
	{
		return new Der1();
	}
};

class Der2Factory :public BaseFactory
{
public:
	Base1* create() const override
	{
		return new Der2();
	}
};

//Factory
BaseFactory* factoryOfFactories(bool useDer1)
{
	if (useDer1)
	{
		return new Der1Factory();
	}
	else
	{
		return new Der2Factory();
	}
}

void runApp(BaseFactory* factory)
{

}

//int main()
//{
//	BaseFactory* factory = factoryOfFactories(true);
//	runApp(factory);
//	delete factory;
//}