#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class CensorePrinter
{
private:
	bool(*shouldCensore)(char ch);
public:
	CensorePrinter();
	CensorePrinter(bool(*pred)(char ch));
	void print(const char* str) const;

};

CensorePrinter::CensorePrinter() :shouldCensore([](char ch) {return false; })
{

}

CensorePrinter::CensorePrinter(bool(*pred)(char ch)) :shouldCensore(pred)
{

}

void CensorePrinter::print(const char* str) const
{
	while (*str)
	{
		if (shouldCensore(*str))
		{
			std::cout << "*";
		}
		else
		{
			std::cout << *str;
		}
		str++;
	}
	std::cout << std::endl;
}

class NumberWrapper
{
private:
	int n;
	const CensorePrinter& consolePrinter;
	char* makeNumToStr() const;

public:
	NumberWrapper(int n, const CensorePrinter& cp);
	int getNum() const;
	void print() const;
};

int getDigitsCount(int num)
{
	if (num==0)
	{
		return 1;
	}
	int count = 0;
	while (num!=0)
	{
		count++;
		num /= 10;
	}
	return count;
}

char* NumberWrapper::makeNumToStr() const
{
	int digitsCount = getDigitsCount(n);
	char* str = new char[digitsCount + 1];
	int tempN = n;
	for (int i = digitsCount - 1; i >= 0; i--)
	{
		str[i] = (tempN % 10 + '0');
		tempN /= 10;
	}

	str[digitsCount] = '\0';
	return str;
}

NumberWrapper::NumberWrapper(int n, const CensorePrinter& cp) :n(n), consolePrinter(cp)
{

}

int NumberWrapper::getNum() const
{
	return n;
}

void NumberWrapper::print() const
{
	char* str = makeNumToStr();
	consolePrinter.print(str);
	delete[] str;
}

class StringWrapper
{
private:
	const char* str;
	const CensorePrinter& cp;
public:
	StringWrapper(const char* str, const CensorePrinter& cp) :str(str), cp(cp)
	{

	}

	void print() const;
};

void StringWrapper::print() const
{
	cp.print(str);
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

int main()
{
	CensorePrinter noNumbers([](char ch) {return ch >= '0' && ch <= '9'; });
	StringWrapper str("Test326abc", noNumbers);
	str.print();

	CensorePrinter no5([](char ch) {return ch == '5'; });
	NumberWrapper num(34567, no5);
	num.print();
}