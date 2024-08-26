#include <iostream>

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

int convertCharToNumber(char ch)
{
	return ch - '0';
}

enum class ErrorCode
{
	OK,
	Nullptr,
	WrongCharInString,
	EmptyString
};

struct ConvertResult
{
	ErrorCode errorCode;
	unsigned result;
};

ConvertResult convertStringToNum(const char* str)
{
	if (!str)
	{
		return { ErrorCode::Nullptr,0 };
	}
	unsigned num = 0;
	if (!*str)
	{
		return { ErrorCode::EmptyString,num };
	}

	while (*str)
	{
		if (!isDigit(*str))
		{
			return { ErrorCode::WrongCharInString,0 };
		}
		num = num * 10 + convertCharToNumber(*str);
		str++;
	}
	return { ErrorCode::OK,num };
}

//int main()
//{
//	ConvertResult res = convertStringToNum("1234!");
//	if (res.errorCode==ErrorCode::OK)
//	{
//		std::cout << res.result << std::endl;
//	}
//	else
//	{
//		std::cout << "Error" << std::endl;
//	}
//}