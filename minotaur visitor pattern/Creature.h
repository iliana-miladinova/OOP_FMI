#pragma once
#include <iostream>

class Minotaur;
class Centaur;
class Sphinx;

class Creature
{
public:
	Creature() = default;

	virtual int fightsWith(const Creature* other)const = 0;
	virtual int fightsWithMinotaur(const Minotaur* other) const = 0;
	virtual int fightsWithCentaur(const Centaur* other) const = 0;
	virtual int fightsWithSphinx(const Sphinx* other) const = 0;

	virtual ~Creature() = default;

	virtual Creature* clone() const = 0;
};