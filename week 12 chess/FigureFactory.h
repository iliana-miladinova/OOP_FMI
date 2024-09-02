#pragma once
#include "Figure.h"
#include "ConfigEnums.h"

class FigureFactory
{
public:
	static Figure* createFigure(bool isWhite, FigureType);
};