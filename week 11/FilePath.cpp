#include "FilePath.h"

FilePath::FilePath(const MyString& filename)
{
	const char* beg = filename.c_str();
	const char* end = filename.c_str() + filename.getSize();
	const char* iter = end;
	while (iter!=beg&&*iter!='.')
	{
		iter--;
	}
	name = filename.substr(0, iter - beg);
	extension = filename.substr(iter - beg, end - iter);
}

const MyString& FilePath::getName() const
{
	return name;
}

const MyString& FilePath::getExtension() const
{
	return extension;
}