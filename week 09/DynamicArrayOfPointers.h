#pragma once
#include <iostream>

struct A
{
	int x = 5;
	int y = 6;
};

class DynamicArrayOfPointers
{
private:
	A** data = nullptr;
	size_t capacity = 0;
	size_t count = 0;

	void copyFrom(const DynamicArrayOfPointers& other);
	void moveFrom(DynamicArrayOfPointers&& other);
	void free();

	void resize(size_t newCap);

	int getFirstFreeIndex() const;

public:
	DynamicArrayOfPointers();
	DynamicArrayOfPointers(const DynamicArrayOfPointers& other);
	DynamicArrayOfPointers& operator=(const DynamicArrayOfPointers& other);
	~DynamicArrayOfPointers();

	DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept;
	DynamicArrayOfPointers& operator=(DynamicArrayOfPointers&& other) noexcept;

	void addAtFirstFreeIndex(const A& current);
	void addAtFirstFreeIndex(A&& current);

	bool containsAt(unsigned ind) const;
	void popBack();
	void removeAt(size_t index);

	void setAtIndex(const A& obj, size_t index);
	void setAtIndex(A&& obj, size_t index);

	size_t size() const;
	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};