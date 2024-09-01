#include "BinaryFileReader.h"

int BinaryFileReader::getFileSize(std::ifstream& ifs)
{
	int currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	int size = ifs.get();
	ifs.seekg(currPos);
	return size;
}

BinaryFileReader::BinaryFileReader(const MyString& filePath):FileReader(filePath)
{

}

int* BinaryFileReader::read(size_t& size) const
{
	std::ifstream ifs(filePath.c_str(), std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::exception("Cannot open file");
	}

	size = getFileSize(ifs) / sizeof(int);
	int* arr = new int[size];
	ifs.read((char*)arr, size * sizeof(int));
	ifs.close();
	return arr;
}