#include <iostream>

class SingletonClass
{
private:
	SingletonClass()
	{
		std::cout << "Singleton was created" << std::endl;
	}
	~SingletonClass()
	{
		std::cout << "Singleton was destroyed" << std::endl;
	}
public:
	static SingletonClass& getInstance()
	{
		static SingletonClass instance;
		return instance;
	}

	SingletonClass(const SingletonClass&) = delete;
	SingletonClass& operator=(class SingletonClass) = delete;

	void doStuff()
	{
		std::cout << this << std::endl;
	}
};

//int main()
//{
//	{
//		std::cout << "Hello";
//		SingletonClass& s1 = SingletonClass::getInstance();
//	}
//	SingletonClass& s2 = SingletonClass::getInstance();
//	s2.doStuff();
//	SingletonClass& s3 = SingletonClass::getInstance();
//	s3.doStuff();
//	SingletonClass& s4 = SingletonClass::getInstance();
//}