#pragma once
#include "Creature.h"

class Sphinx :public Creature
{
public:
	int fightsWith(const Creature* other) const override;
	int fightsWithMinotaur(const Minotaur* other) const override;
	int fightsWithCentaur(const Centaur* other) const override;
	int fightsWithSphinx(const Sphinx* other) const override;

	Creature* clone() const override;
};