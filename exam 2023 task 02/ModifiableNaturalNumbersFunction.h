#pragma once
#include "NaturalNumbersFunction.h"

class ModifiableNaturalNumbersFunction :protected NaturalNumbersFunction
{
private:
	static const int InvalidPoint = -1;
	static const int InvalidIndex = -1;


	struct Pair
	{
		int m_point = -1; // Точката, която е модифицирана
		int m_value = -1;  // Новата стойност за тази точка
	};

	Pair* m_pModifiedPoints = nullptr;
	unsigned m_capacity = 0;
	unsigned m_currentSize = 0;

	void copyFrom(const ModifiableNaturalNumbersFunction& other);
	void moveFrom(ModifiableNaturalNumbersFunction&& other);
	void free();

	int findPointIndex(unsigned point) const;
	void removeAllModifications();

public:
	ModifiableNaturalNumbersFunction();
	ModifiableNaturalNumbersFunction(UnaryUnsignedFunction pFunc, unsigned pointsToChange);
	ModifiableNaturalNumbersFunction(const ModifiableNaturalNumbersFunction& other);
	ModifiableNaturalNumbersFunction& operator=(const ModifiableNaturalNumbersFunction& other);
	ModifiableNaturalNumbersFunction(ModifiableNaturalNumbersFunction&& other) noexcept;
	ModifiableNaturalNumbersFunction& operator=(ModifiableNaturalNumbersFunction&& other) noexcept;
	~ModifiableNaturalNumbersFunction();

	bool modify(unsigned point, unsigned value);
	bool removeModification(unsigned point);

	using NaturalNumbersFunction::countFixedPoints;
	
	unsigned operator()(unsigned x) const override final;
	void setFunction(UnaryUnsignedFunction pFunc) override final;
};