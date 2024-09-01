#pragma once
#include "MyString.h"

class FilePath
{
private:
	MyString name;
	MyString extension;

public:
	FilePath(const MyString& name);
	const MyString& getName() const;
	const MyString& getExtension() const;

};