// week 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning (disable:4996)
struct Student
{
	char name[30];
	int age;
	int fn;
};

void initStudent(Student& st, const char* name, int age, int fn)
{
	strcpy(st.name, name);
	st.age = age;
	st.fn = fn;
}

void saveToFile(const Student* students, size_t count, std::ofstream& ofs)
{
	ofs.write((const char*)students, count * sizeof(Student));
}

//int main()
//{
//	constexpr size_t size = 4;
//	Student* arr = new Student[size];
//	initStudent(arr[0], "Iliana", 20, 326);
//	initStudent(arr[1], "Geri", 19, 1234);
//	initStudent(arr[2], "Ivan", 23, 2345);
//	initStudent(arr[3], "Pesho", 24, 987);
//
//	std::ofstream ofs("students.dat", std::ios::binary);
//	if (!ofs.is_open())
//	{
//		std::cout << "Error while opening the file!" << std::endl;
//		delete[] arr;
//		return -1;
//	}
//	saveToFile(arr, size, ofs);
//	delete[] arr;
//	return 0;
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
