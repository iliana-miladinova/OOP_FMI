#include "Battle.h"

void Battle::copyFrom(const Battle& other)
{
	creatures = new Creature * [other.capacity];
	capacity = other.capacity;
	creaturesCount = other.creaturesCount;
	for (int i = 0; i < creaturesCount; i++)
	{
		Creature* cloned = other.creatures[i]->clone();
		if (cloned)
		{
			creatures[i] = cloned;
		}
	}
}

void Battle::moveFrom(Battle&& other)
{
	creatures = other.creatures;
	other.creatures = nullptr;

	creaturesCount = other.creaturesCount;
	capacity = other.capacity;

	other.creaturesCount = other.capacity = 0;
}

void Battle::free()
{
	for (int i = 0; i < creaturesCount; i++)
	{
		delete[] creatures[i];
	}
	delete[] creatures;
}

void Battle::resize()
{
	Creature** newCreatures = new Creature * [capacity *= 2];
	for (int i = 0; i < creaturesCount; i++)
	{
		newCreatures[i] = creatures[i];
	}
	delete[] creatures;
	creatures = newCreatures;
}

Battle::Battle(const Creature**& creatures, size_t count)
{
	this->creaturesCount = count;
	this->creatures = new Creature * [count];
	for (int i = 0; i < count; i++)
	{
		this->creatures[i] = creatures[i]->clone();
	}
}

Battle::Battle(Creature**&& creatures, size_t count)
{
	this->creatures = creatures;
	this->creaturesCount = count;
}

Battle::Battle(const Battle& other)
{
	copyFrom(other);
}

Battle& Battle::operator=(const Battle& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Battle::Battle(Battle&& other) noexcept
{
	moveFrom(std::move(other));
}

Battle& Battle::operator=(Battle&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Battle::Battle(size_t capacity)
{
	creaturesCount = 0;
	this->capacity = capacity;
	creatures = new Creature * [capacity];
}

Battle::Battle()
{
	creaturesCount = 0;
	capacity = 8;
	creatures = new Creature * [capacity];
}


Battle::~Battle()
{
	free();
}

void Battle::addCreature(const Creature& cr)
{
	if (creaturesCount==capacity)
	{
		resize();
	}
	creatures[creaturesCount] = cr.clone();
	creaturesCount++;
}

void Battle::removeCreature(size_t ind)
{
	if (ind>=creaturesCount)
	{
		throw std::invalid_argument("Out of range");
	}

	delete[] creatures[ind];
	creatures[ind] = nullptr;

	std::swap(creatures[ind], creatures[creaturesCount - 1]);

	creaturesCount--;
}

const Creature* Battle::getCreature(size_t ind) const
{
	if (ind>=creaturesCount)
	{
		throw std::invalid_argument("Out of range");
	}
	return creatures[ind];
}

Creature* Battle::getCreature(size_t ind)
{
	if (ind>=creaturesCount)
	{
		throw std::invalid_argument("Out of range");
	}
	return creatures[ind];
}

int Battle::fightAll(size_t ind) const
{
	if (ind>=creaturesCount)
	{
		throw std::invalid_argument("Out of range");
	}

	int countWins = 0;

	for (int i = 0; i < creaturesCount; i++)
	{
		if (i!=ind)
		{
			if (creatures[i]->fightsWith(creatures[ind])==1)
			{
				countWins++;
			}
		}
	}
	return countWins;
}