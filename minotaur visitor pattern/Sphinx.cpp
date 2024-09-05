#include "Sphinx.h"

int Sphinx::fightsWith(const Creature* other) const
{
	return other->fightsWithSphinx(this);
}

int Sphinx::fightsWithMinotaur(const Minotaur* other) const
{
	return -1;
}

int Sphinx::fightsWithCentaur(const Centaur* other) const
{
	return 1;
}

int Sphinx::fightsWithSphinx(const Sphinx* other) const
{
	return 0;
}

Creature* Sphinx::clone() const
{
	return new Sphinx(*this);
}