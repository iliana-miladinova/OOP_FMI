#include <iostream>
#include <fstream>

void replaceInFile(char ch, char ch2, std::fstream& f)
{
	while (!f.eof())
	{
		char currSymbol = f.get();
		if (currSymbol!=ch)
		{
			continue;
		}
		f.seekp(-1, std::ios::cur);//zashtoto sled f.get ukazatelyat se e premestil nadyasno
		f.put(ch2);
		f.flush();
	}
}

//int main()
//{
//	std::fstream file("treasureTrail.txt", std::ios::in | std::ios::out);
//	if (!file.is_open())
//	{
//		std::cout << "Error while opening the file!" << std::endl;
//		return -1;
//	}
//	replaceInFile('a', '&', file);
//	return 0;
//}