// week 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma warning(disable:4996)

bool isSmallLetter(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

bool isCapitalLetter(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

bool containsOnlySmallChars(const char* str)
{
    size_t strLen = strlen(str);
    for (int i = 0; i < strLen; i++)
    {
        if (!isSmallLetter(str[i]))
        {
            return false;
        }
    }
    return true;
}

constexpr size_t MIN_AGE = 5;
constexpr size_t MAX_AGE = 90;
constexpr size_t MIN_LEN_NAME = 2;
constexpr size_t MAX_LEN_NAME = 20;

class Student
{
private:
    char name[MAX_LEN_NAME] = "Unknown";
    int age = MIN_AGE;

    bool isValidAge(int age)
    {
        return age >= MIN_AGE && age <= MAX_AGE;
    }

    bool isValidName(const char* name)
    {
        if (name==nullptr)
        {
            return false;
        }

        unsigned nameLen = strlen(name);
        if (nameLen<=MIN_LEN_NAME&&nameLen>=MAX_LEN_NAME)
        {
            return false;
        }
        if (!isCapitalLetter(*name))
        {
            return false;
        }
        /*if (!containsOnlySmallChars(name+1))
        {
            return false;
        }
        return true;*/
        return containsOnlySmallChars(name + 1);
    }

public:
    Student() = default;

    Student(const char* name, int age)
    {
        setName(name);
        setAge(age);
    }

    const char* getName() const//kopie na ukazatelya
    {
        return name;
    }

    int getAge() const //vrashta kopie
    {
        return age;
    }

    void setName(const char* name)
    {
        if (isValidName(name))
        {
            strcpy(this->name, name);
        }
        else
        {
            strcpy(this->name, "Unknown");
        }
    }

    void setAge(int age)
    {
        if (isValidAge(age))
        {
            this->age = age;
        }
        else
        {
            this->age = 15;
        }
    }
};

//int main()
//{
//    Student s("Iliana", 20);
//   
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
