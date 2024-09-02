#include "ShapeCollection.h"

void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	shapes = new Shape * [other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
	size = other.size;
	capacity = other.capacity;
}

void ShapeCollection::moveFrom(ShapeCollection&& other)
{
	shapes = other.shapes;
	other.shapes = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void ShapeCollection::free()
{
	for (int i = 0; i < size; i++)
	{
		delete[] shapes[i];
	}
	delete[] shapes;
}

void ShapeCollection::resize(size_t newCap)
{
	Shape** newShapes = new Shape * [newCap];
	for (int i = 0; i < size; i++)
	{
		newShapes[i] = shapes[i];
	}
	delete[] shapes;
	shapes = newShapes;
	capacity = newCap;
}

ShapeCollection::ShapeCollection()
{
	size = 0;
	capacity = 8;
	shapes = new Shape * [capacity] {nullptr};
}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}
ShapeCollection::ShapeCollection(ShapeCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

ShapeCollection& ShapeCollection::operator= (const ShapeCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ShapeCollection::~ShapeCollection() noexcept
{
	free();
}

void ShapeCollection::addFigure(Shape* shape)
{
	if (size==capacity)
	{
		resize(capacity * 2);
	}
	shapes[size++] = shape;
	shape = nullptr;
}

void ShapeCollection::addFigure(const Shape& shape)
{
	Shape* cloned = shape.clone();
	addFigure(cloned);
}

double ShapeCollection::getAreaByIndex(unsigned ind) const
{
	return shapes[ind]->getArea();
}

double ShapeCollection::getPerByIndex(unsigned ind) const
{
	return shapes[ind]->getPer();
}

bool ShapeCollection::getIsPointInByIndex(unsigned ind, int x, int y) const
{
	return shapes[ind]->isPointIn(x, y);
}

unsigned ShapeCollection::getSize() const
{
	return size;
}

const Shape* ShapeCollection::operator[](unsigned ind) const
{
	return shapes[ind];
}