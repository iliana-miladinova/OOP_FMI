#pragma once
#include "Shape.h"

class ShapeCollection
{
private:
	Shape** shapes;
	size_t capacity = 0;
	size_t size = 0;

	void copyFrom(const ShapeCollection& other);
	void moveFrom(ShapeCollection&& other);
	void free();
	void resize(size_t newCap);

public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);
	ShapeCollection(ShapeCollection&& other) noexcept;
	ShapeCollection& operator=(ShapeCollection&& other) noexcept;
	~ShapeCollection();

	void addFigure(Shape* shape);
	void addFigure(const Shape& shape);

	double getAreaByIndex(unsigned ind) const;
	double getPerByIndex(unsigned ind) const;
	bool getIsPointInByIndex(unsigned ind, int x, int y)const;

	const Shape* operator[](unsigned) const;
	unsigned getSize() const;
};