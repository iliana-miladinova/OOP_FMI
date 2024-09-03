#include "PolymorhicPtr.hpp"
#include "Vector.hpp"
#include <iostream>

class FileSystemEntity
{
public:
	virtual size_t getSize() = 0;
	virtual ~FileSystemEntity() = default;
};

class File :public FileSystemEntity
{
private:
	size_t size = 0;
public:
	size_t getSize() const
	{
		return size;
	}
};

class Diretory :public FileSystemEntity
{
private:
	Vector<Polymorphic_Ptr<FileSystemEntity>>children;
public:
	size_t getSize() const 
	{
		size_t size = 0;
		for (size_t i = 0; i < children.getSize(); i++)
		{
			size += children[i].getSize();
		}
		return size;
	}
};