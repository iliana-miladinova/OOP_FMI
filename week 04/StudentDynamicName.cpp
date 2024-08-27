#include <iostream>
#pragma warning(disable:4996)

class Student
{
private:
	char* name;
	int age;

public:
	Student(const char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	void print() const
	{
		std::cout << "Name: " << name << " age " << age << std::endl;
	}
	~Student()
	{
		delete[] name;
	}
};

//int main()
//{
//	Student s("Iliana", 20);
//	Student* ptr = new Student("Petur", 19);
//	s.print();
//	ptr->print();
//	delete ptr; //cals destructor of ptr
//}//cals destructor of s