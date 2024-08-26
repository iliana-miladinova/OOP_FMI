#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

struct DynamicNameStudent
{
	char* name;
	int age;
	int fn;
};

DynamicNameStudent init(const char* name, int age, int fn)
{
	DynamicNameStudent st;
	st.name = new char[strlen(name) + 1];
	strcpy(st.name, name);
	st.age = age;
	st.fn = fn;
	return st;
}

void freeStudent(DynamicNameStudent& st)
{
	delete[] st.name;
	st.age = st.fn = 0;
}

void saveToBinaryFile(std::ofstream& ofs, const DynamicNameStudent& st)
{
	int nameLen = strlen(st.name);
	ofs.write((const char*)&nameLen, sizeof(int));
	ofs.write(st.name, nameLen+1);
	ofs.write((const char*)& st.age, sizeof(st.age));
	ofs.write((const char*)&st.fn, sizeof(st.fn));
}

DynamicNameStudent readFromBinaryFile(std::ifstream& ifs)
{
	DynamicNameStudent st;
	int nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	st.name = new char[nameLen + 1];

	ifs.read(st.name, nameLen+1);

	ifs.read((char*)&st.age, sizeof(st.age));
	ifs.read((char*)&st.fn, sizeof(st.fn));
	return st;
}

void printStudent(const DynamicNameStudent& st)
{
	std::cout << st.name << " " << st.age << " " << st.fn << std::endl;
}

void savStudentArrayToFile(std::ofstream& ofs, const DynamicNameStudent* arr, size_t arraySize)
{
	ofs.write((const char*)&arraySize, sizeof(arraySize));
	for (int i = 0; i < arraySize; i++)
	{
		saveToBinaryFile(ofs, arr[i]);
	}
}

void readStudentFromFile(std::ifstream& ifs, DynamicNameStudent*& ptr, size_t& size)
{
	ifs.read((char*)&size, sizeof(size));

	ptr = new DynamicNameStudent[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = readFromBinaryFile(ifs);
	}
}

//int main()
//{
//	/*std::ofstream ofs("arrStudents.dat", std::ios::out, std::ios::binary);
//	if (!ofs.is_open())
//	{
//		return -1;
//	}
//
//	DynamicNameStudent arr[3];
//	arr[0] = init("Iliana", 20, 326);
//	arr[1] = init("Georgi", 19, 1234);
//	arr[2] = init("Niki", 20, 12345);
//	savStudentArrayToFile(ofs, arr, 3);
//
//	freeStudent(arr[0]);
//	freeStudent(arr[1]);
//	freeStudent(arr[2]);*/
//
//	std::ifstream ifs("arrStudents.dat", std::ios::in | std::ios::binary);
//	if (!ifs.is_open())
//	{
//		return -1;
//	}
//
//	DynamicNameStudent* arr;
//	size_t size;
//	readStudentFromFile(ifs, arr, size);
//	for (int i = 0; i < size; i++)
//	{
//		printStudent(arr[i]);
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		freeStudent(arr[i]);
//	}
//}