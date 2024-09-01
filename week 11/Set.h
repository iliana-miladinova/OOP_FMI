#pragma once
#include "Collection.h"
#include "PureNumbersCollection.h"

enum collectionType
{
	NORMAL_COLLECTION,
	SORTED_COLLECTION
};

class Set :public Collection
{
private:
	PureNumbersCollection* collection;
public:
	Set(collectionType);

	Set(const Set&) = delete;
	Set& operator=(const Set&) = delete;

	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;

	~Set();
};