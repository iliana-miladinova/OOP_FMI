#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t fileSize = ifs.tellg();
	ifs.seekg(currPos);
	return fileSize;
}

//int main()
//{
//	std::ifstream ifs("test.txt");
//	if (!ifs.is_open())
//	{
//		std::cout << "ERROR" << std::endl;
//	}
//	size_t filesize = getFileSize(ifs);
//	std::cout << filesize;
//	ifs.close();
//}