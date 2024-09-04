#pragma once
#include <fstream>

static bool isValidSymbol(unsigned char ch)
{
	return ch >= 32;
}

static unsigned char* createAndFillByteArray(size_t destSize, const unsigned char* source, size_t sourceSize)
{
	unsigned char* dest = new unsigned char[destSize];

	memcpy(dest, source, sourceSize);
	return dest;
}

static const char* getFileExtension(const char* fileName)
{
	while (*fileName&&*fileName!='.')
	{
		fileName++;
	}
	return fileName + 1;
}

static size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);
	return size;
}

static int getCharCount(std::ifstream& ifs, char ch)
{
	if (!ifs.is_open())
	{
		return -1;
	}
	int count = 0;
	while (true)
	{
		char curr = ifs.get();
		if (ifs.eof())
		{
			return count;
		}
		if (curr==ch)
		{
			count++;
		}
	}
	return 0;
}