#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen :public Bishop, public Rook
{
public:
	Queen(bool isWhite);
	bool canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const override;
	void print() const override;
};