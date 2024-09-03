#include <iostream>

struct AirBag {};
struct EUStandartAirBag :AirBag {};
struct USAStandartAirBag :AirBag {};

struct TurnSignal {};
struct EUStandartTurnSignal :TurnSignal {};
struct USAStandartTurnSignal :TurnSignal {};

// Abstract factory creating a family of car parts
class CarPartsFactory
{
public :
	virtual AirBag* createAirBag()const = 0;
	virtual TurnSignal* createTurnSignal()const = 0;

	virtual ~CarPartsFactory() = default;
};

class EuropeanCarPartsFactory :public CarPartsFactory
{
public:
	AirBag* createAirBag() const override
	{
		return new EUStandartAirBag();
	}
	TurnSignal* createTurnSignal() const override
	{
		return new EUStandartTurnSignal();
	}
};

class UsCarPartsFactory :public CarPartsFactory
{
public:
	AirBag* createAirBag() const override
	{
		return new USAStandartAirBag();
	}
	TurnSignal* createTurnSignal()const override
	{
		return new USAStandartTurnSignal();
	}
};

CarPartsFactory* factoryOfFactories(bool isEU)
{
	if (isEU)
	{
		return new EuropeanCarPartsFactory();
	}
	else
	{
		return new UsCarPartsFactory();
	}
}

void createCar(CarPartsFactory* partsFactory)
{
	AirBag* airbag = partsFactory->createAirBag();
	TurnSignal* turnsignal = partsFactory->createTurnSignal();
}

int main()
{
	CarPartsFactory* factory = factoryOfFactories(true);
	createCar(factory);

	delete factory;
}