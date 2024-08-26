#include <iostream>
#include <fstream>

unsigned getCharCountFromFile(std::ifstream& ifs, char ch)
{
	size_t currPos = ifs.tellg();

	ifs.seekg(0, std::ios::beg);
	if (!ifs.is_open())
	{
		return 0;
	}

	unsigned count = 0;
	while (true)
	{
		char curr = ifs.get();

		if (ifs.eof())
		{
			break;
		}

		if (ch==curr)
		{
			count++;
		}
	}

	ifs.clear();
	ifs.seekg(currPos);
	return count;
}

int* getArrayFromFile(const char* fileName, size_t& arraySize)
{
	if (!fileName)
	{
		return nullptr;
	}

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return nullptr;
	}

	arraySize = getCharCountFromFile(ifs, ' ') + 1;
	int* arr = new int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		ifs >> arr[i];
	}
	ifs.close();
	return arr;
}

int* merge(const int* first, size_t firstSize, const int* second, size_t secondSize)
{
	size_t firstItter = 0;
	size_t secondItter = 0;
	size_t resSize = firstSize + secondSize;
	int* res = new int[resSize];
	size_t resItter = 0;

	while (firstItter<firstSize&&secondItter<secondSize)
	{
		if (first[firstItter]<=second[secondItter])
		{
			res[resItter++] = first[firstItter++];
		}
		else
		{
			res[resItter++] = second[secondItter++];
		}
	}
	while (firstItter<firstSize)
	{
		res[resItter++] = first[firstItter++];
	}
	while (secondItter<secondSize)
	{
		res[resItter++] = second[secondItter++];
	}

	return res;
}

void mergeFromFile(const char* firstFile, const char* secondFile, const char* mergedFile)
{
	size_t firstSize, secondSize;
	int* firstArr = getArrayFromFile(firstFile, firstSize);
	if (!firstArr)
	{
		return;
	}

	int* secondArr = getArrayFromFile(secondFile, secondSize);
	if (!secondArr)
	{
		delete[] firstArr;
		return;
	}

	int* merged = merge(firstArr, firstSize, secondArr, secondSize);

	std::ofstream ofs(mergedFile);
	if (!ofs.is_open())
	{
		delete[] firstArr;
		delete[] secondArr;
		delete[] merged;
		return;
	}

	for (int i = 0; i < firstSize+secondSize; i++)
	{
		ofs << merged[i] << ' ';
	}

	delete[] firstArr;
	delete[] secondArr;
	delete[] merged;
	ofs.close();
}

//int main()
//{
//	mergeFromFile("firstArr.txt", "secondArr.txt", "merged.txt");
//}