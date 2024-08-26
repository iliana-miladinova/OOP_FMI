#include <iostream>
#include <fstream>

int main()
{
	/*{
		const int size = 5;
		int arr[size] = { 1,2,3,4,5 };
		std::ofstream ofs("arr.dat", std::ios::out | std::ios::binary);
		ofs.write((const char*)arr, size * sizeof(int));
	}*/
	{
		const int size = 5;
		int arr[size] = {};
		std::ifstream ifs("arr.dat", std::ios::in | std::ios::binary);
		ifs.read((char*)arr, size * sizeof(int));
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << ' ';
		}
	}
}