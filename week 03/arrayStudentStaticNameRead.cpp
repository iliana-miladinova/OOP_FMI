#include <iostream>
#include <fstream>

struct Student
{
	char name[30];
	int age;
	int fn;
};

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);
	return size;
}

void readFromFile(Student*& ptr, size_t& studentsCount, std::ifstream& ifs)
{
	size_t sizeOfFile = getFileSize(ifs);
	studentsCount = sizeOfFile / sizeof(Student);
	ptr = new Student[studentsCount];
	ifs.read((char*)ptr, sizeOfFile);
}

//int main()
//{
//	Student* arr;
//	size_t count;
//	std::ifstream ifs("students.dat", std::ios::binary);
//	if (!ifs.is_open())
//	{
//		std::cout<< "Error while opening the file!" << std::endl;
//		return -1;
//	}
//	readFromFile(arr, count, ifs);
//	for (int i = 0; i < count; i++)
//	{
//		std::cout << "Name: " << arr[i].name << " Age: " << arr[i].age << " FN: " << arr[i].fn << std::endl;
//	}
//	delete[] arr;
//}