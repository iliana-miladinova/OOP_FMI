#include "SortedCollection.h"

int SortedCollection::lowerBound(int el) const
//Намира най-малкия индекс в масива data, 
// на който може да се постави елементът elem,
//  така че да се запази сортираният ред. 
// Ако в масива вече има елементи, равни на elem,
//  тази функция ще върне индекса на първия от тях.
//Ако имаме масив[1, 2, 4, 4, 5, 7] и търсим lowerBound(4), 
// резултатът ще бъде 2, тъй като първото срещане на 4 е на 
// индекс 2.
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = size;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data[mid]<el)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}
	return indexToReturn;
}

int SortedCollection::upperBound(int el) const
//Намира най - малкия индекс в масива data, 
// който съдържа елемент, по - голям от elem.
// Ако няма такъв елемент, функцията връща size
//Ако имаме масив [1, 2, 4, 4, 5, 7] и търсим upperBound(4), 
// резултатът ще бъде 4, тъй като първият елемент,
//  който е по-голям от 4, е 5 на индекс 4.
{
	int left = 0;
	int right = size - 1;

	int indToReturn = size;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data[mid]<=el)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			indToReturn = mid;
		}
	}
	return indToReturn;
}

void SortedCollection::add(int el)
{
	if (size==capacity)
	{
		resize(capacity * 2);
	}

	int ind = size;
	while (ind!=0&&data[ind-1]>el)
	{
		data[ind] = data[ind - 1];
		ind--;
	}
	data[ind] = el;
	size++;

}

void SortedCollection::remove(int el)
{
	int elementInd = lowerBound(el);
	if (elementInd ==size)
	{
		return;
	}

	for (int i = elementInd; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

unsigned SortedCollection::count(int el) const
{
	int lowerInd = lowerBound(el);
	if (lowerInd==size)
	{
		return 0;
	}
	int upperInd = upperBound(el);
	return upperInd - lowerInd;
}

bool SortedCollection::contains(int el) const
{
	return lowerBound(el) != size;
}