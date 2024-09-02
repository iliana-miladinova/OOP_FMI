#include "Queen.h"

//otgovarya za sazdavaneto na Bishop, Rook i Figure
Queen::Queen(bool isWhite) :Bishop(isWhite), Rook(isWhite), Figure(isWhite, QueenFigure)
{

}

bool Queen::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
	return Bishop::canBeMoved(currX, currY, destX, destY) ||
		Rook::canBeMoved(currX, currY, destX, destY);
}

void Queen::print() const
{
	if (getIsWhite())
	{
		std::cout << 'Q';
	}
	else
	{
		std::cout << 'q';
	}
}