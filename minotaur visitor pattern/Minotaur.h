#pragma once
#include "Creature.h"

class Minotaur :public Creature
{
public:
	Minotaur() = default;

	int fightsWith(const Creature* other) const override;
	int fightsWithMinotaur(const Minotaur* other) const override;
	int fightsWithCentaur(const Centaur* other) const override;
	int fightsWithSphinx(const Sphinx* other) const override;

	Creature* clone() const override;
};