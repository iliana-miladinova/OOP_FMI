#pragma once
#include <iostream>

struct A
{
	int a = 4;
	int b = 3;
};

class DynamicArray
{
private:
	A* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	void moveFrom(DynamicArray&& other);
	void copyFrom(const DynamicArray& other);
	void free();
	void resize(size_t newCap);
public:
	DynamicArray();
	DynamicArray(size_t capacity);

	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	DynamicArray(DynamicArray&& other) noexcept;
	DynamicArray& operator=(DynamicArray&& other) noexcept;

	void push_back(const A& newEl); //add a new element in the end
	void push_back(A&& newEl); //add a new element in the end

	void pop_back();  //removes the last element
	void setAtIndex(const A& el, size_t ind);
	void setAtIndex(A&& el, size_t ind);

	size_t getSize() const;
	bool isEmpty() const;
	
	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};