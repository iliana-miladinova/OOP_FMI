#include "Minotaur.h"

int Minotaur::fightsWith(const Creature* other) const
{
	return other->fightsWithMinotaur(this);
}

int Minotaur::fightsWithMinotaur(const Minotaur* other) const
{
	return 0;
}

int Minotaur::fightsWithCentaur(const Centaur* other) const
{
	return -1;
}

int Minotaur::fightsWithSphinx(const Sphinx* other) const
{
	return 1;
}

Creature* Minotaur::clone() const
{
	return new Minotaur(*this);
}