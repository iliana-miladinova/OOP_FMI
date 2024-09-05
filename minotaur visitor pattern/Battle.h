#pragma once
#include "Creature.h"

class Battle
{
private:
	Creature** creatures;
	size_t creaturesCount;
	size_t capacity;

	void resize();
	void copyFrom(const Battle& other);
	void moveFrom(Battle&& other);
	void free();

public:
	Battle(const Creature**& creatures, size_t count);
	Battle(Creature**&& creatures, size_t count);
	Battle(size_t capacity);
	Battle();

	Battle(const Battle& other);
	Battle& operator=(const Battle& other);
	Battle(Battle&& other) noexcept;
	Battle& operator=(Battle&& other) noexcept;
	~Battle();

	const Creature* getCreature(size_t ind) const;
	Creature* getCreature(size_t ind);

	void addCreature(const Creature& cr);
	void removeCreature(size_t ind);

	int fightAll(size_t ind) const;
};