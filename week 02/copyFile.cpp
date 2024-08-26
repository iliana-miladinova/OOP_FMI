#include <iostream>
#include <fstream>

bool copyTo(const char* sourceFile, const char* destFile)
{
	std::ifstream ifs(sourceFile);
	if (!ifs.is_open())
	{
		return false;
	}

	std::ofstream ofs(destFile);
	if (!ofs.is_open())
	{
		return false;
	}

	while (!ifs.eof())
	{
		char buff[1024];
		ifs.getline(buff, 1024);//zapisvame 1 red ot ifs v buff
		ofs << buff << std::endl;//zapisvame informaciyata ot buff v ofs i otivame na sledvashtiya red
	}
}

//int main()
//{
//	std::cout << copyTo("test.txt", "copy.txt");
//}