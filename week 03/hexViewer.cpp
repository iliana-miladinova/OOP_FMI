#include <iostream>
#include <fstream>
#include <iomanip>

struct HexViewer
{
	unsigned char* data;
	size_t dataSize;
};

size_t getFileSize1(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);
	return size;
}

HexViewer init(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
	HexViewer file;

	if (!ifs.is_open())
	{
		file.data = nullptr;
		file.dataSize = 0;
		return file;
	}

	file.dataSize = getFileSize1(ifs);
	file.data = new unsigned char[file.dataSize];
	ifs.read((char*)file.data, file.dataSize);
	ifs.close();
	return file;
}

void freeHexViewer(HexViewer& file)
{
	delete[] file.data;
	file.dataSize = 0;
}

void saveHexViewer(const HexViewer& file, const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
	if (!ofs.is_open())
	{
		return;
	}
	ofs.write((const char*)file.data, file.dataSize);
	ofs.close();
}

bool isValidSymbol(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z') ||
		(ch >= '0' && ch <= '9');
}

void print(const HexViewer& file)
{
	for (int i = 0; i < file.dataSize; i++)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)file.data[i] << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < file.dataSize; i++)
	{
		if (isValidSymbol(file.data[i]))
		{
			std::cout << file.data[i] << ' ';
		}
		else
		{
			std::cout << "..";
		}
	}
}

void modify(HexViewer& file, unsigned ind, char ch)
{
	if (ind>=file.dataSize)
	{
		return;
	}

	file.data[ind] = ch;
}

//int main()
//{
//	HexViewer myFile = init("myFile.dat");
//	print(myFile);
//	modify(myFile, 0, 'I');
//	saveHexViewer(myFile, "myFile.dat");
//	freeHexViewer(myFile);
//}