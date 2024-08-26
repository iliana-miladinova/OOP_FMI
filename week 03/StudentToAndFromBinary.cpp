#include <iostream>
#include <fstream>

struct Student
{
	char name[30];
	int age;
	int fn;
};

//int main()
//{
//	//std::ofstream ofs("file1.dat", std::ios::out | std::ios::binary);
//	//if (!ofs.is_open())
//	//{
//	//	return -1;
//	//}
//
//	//Student st{ "Iliana",20,326 };
//	//ofs.write((const char*)&st, sizeof(st));
//
//	std::ifstream ifs("file1.dat", std::ios::in | std::ios::binary);
//	if (!ifs.is_open())
//	{
//		return -1;
//	}
//	Student st;
//	ifs.read((char*)&st, sizeof(st));
//	std::cout << st.name << ' ' << st.age << ' ' << st.fn;
//}