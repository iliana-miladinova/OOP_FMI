#include "ModifiableNaturalNumbersFunction.h"

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction() :NaturalNumbersFunction()
{
	m_capacity = 2;
	m_pModifiedPoints = new Pair[m_capacity];
	m_currentSize = 0;
}

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction(UnaryUnsignedFunction pFunc, unsigned pointsToChange) :
	NaturalNumbersFunction(pFunc)
{
	m_capacity = pointsToChange;
	m_pModifiedPoints = new Pair[m_capacity];
	m_currentSize = 0;
}

void ModifiableNaturalNumbersFunction::copyFrom(const ModifiableNaturalNumbersFunction& other)
{
	m_pModifiedPoints = new Pair[other.m_capacity];
	for (int i = 0; i < other.m_currentSize; i++)
	{
		m_pModifiedPoints[i] = other.m_pModifiedPoints[i];
	}
	m_capacity = other.m_capacity;
	m_currentSize = other.m_currentSize;
}

void ModifiableNaturalNumbersFunction::moveFrom(ModifiableNaturalNumbersFunction&& other)
{
	m_pModifiedPoints = other.m_pModifiedPoints;
	other.m_pModifiedPoints = nullptr;

	m_capacity = other.m_capacity;
	
	m_currentSize = other.m_currentSize;

	other.m_capacity = other.m_currentSize = 0;
}

void ModifiableNaturalNumbersFunction::free()
{
	delete[] m_pModifiedPoints;
	m_capacity = 0;
	m_currentSize = 0;
}

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction(const ModifiableNaturalNumbersFunction& other)
{
	copyFrom(other);
}

ModifiableNaturalNumbersFunction& ModifiableNaturalNumbersFunction::operator=(const ModifiableNaturalNumbersFunction& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction(ModifiableNaturalNumbersFunction&& other) noexcept
{
	moveFrom(std::move(other));
}

ModifiableNaturalNumbersFunction& ModifiableNaturalNumbersFunction::operator=(ModifiableNaturalNumbersFunction&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ModifiableNaturalNumbersFunction::~ModifiableNaturalNumbersFunction()
{
	free();
}

int ModifiableNaturalNumbersFunction::findPointIndex(unsigned point) const
{
	for (int i = 0; i < m_currentSize; i++)
	{
		if (m_pModifiedPoints[i].m_point==point)
		{
			return i;
		}
	}
	return InvalidIndex;
}

void ModifiableNaturalNumbersFunction::removeAllModifications()
{
	m_currentSize = 0;
}

bool ModifiableNaturalNumbersFunction::modify(unsigned point, unsigned value)
{
	int ind = findPointIndex(point);
	if (ind==InvalidIndex)
	{
		if (m_currentSize>=m_capacity)
		{
			return false;
		}
		ind = m_currentSize++;
	}
	m_pModifiedPoints[ind].m_point = point;
	m_pModifiedPoints[ind].m_value = value;
	return true;
}

bool ModifiableNaturalNumbersFunction::removeModification(unsigned point)
{
	int ind = findPointIndex(point);

	if (ind==InvalidIndex)
	{
		return false;
	}
	if (ind != m_currentSize - 1)
	{
		std::swap(m_pModifiedPoints[ind], m_pModifiedPoints[m_currentSize - 1]);
	}
	m_pModifiedPoints[m_currentSize - 1]=Pair();
	m_currentSize--;
	return true;

}

unsigned ModifiableNaturalNumbersFunction::operator()(unsigned x) const
{
	int ind = findPointIndex(x);
	return ind == InvalidIndex ? m_pFunc(x) : m_pModifiedPoints[ind].m_value;
}

void ModifiableNaturalNumbersFunction::setFunction(UnaryUnsignedFunction pFunc)
{
	removeAllModifications();
	m_pFunc = pFunc;
}