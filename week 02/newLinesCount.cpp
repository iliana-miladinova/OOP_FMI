// week 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 
const char NEW_LINE_CHAR = '\n';

int getCharCount(std::ifstream& ifs, char ch)
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
}

int getLinesCount(const char* fileName)
{
	if (!fileName)
	{
		return -1;
	}

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return -1;
	}

	return getCharCount(ifs, NEW_LINE_CHAR) + 1;
}
//int main()
//{
//    std::cout << getLinesCount("test.txt");
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
