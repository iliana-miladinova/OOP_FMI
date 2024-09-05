#include "Centaur.h"

int Centaur::fightsWith(const Creature* other) const
{
	return other->fightsWithCentaur(this);
}

int Centaur::fightsWithMinotaur(const Minotaur* other) const
{
	return 1;
}

int Centaur::fightsWithCentaur(const Centaur* other) const
{
	return 0;
}

int Centaur::fightsWithSphinx(const Sphinx* other) const
{
	return -1;
}

Creature* Centaur::clone() const
{
	return new Centaur(*this);
}