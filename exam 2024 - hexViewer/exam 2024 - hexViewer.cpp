// exam 2024 - hexViewer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Utility.h"
#pragma warning(disable:4996)


class HexArray
{
public:
    unsigned char* data;
    size_t size;

    void copyFrom(const HexArray& other)
    {
        size = other.size;
        data = createAndFillByteArray(size, other.data, other.size);

        /*data = new unsigned char[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }*/
    }

    void moveFrom(HexArray&& other)
    {
        data = other.data;
        other.data = nullptr;

        size = other.size;
        other.size = 0;
    }

    void free()
    {
        delete[] data;
    }

public:
    HexArray(unsigned char* initData, size_t initSize)
    {
        /*data = createAndFillByteArray(size, initData, initSize);*/
        size = initSize;
        
        data = new unsigned char [initSize];
        for (int i = 0; i < initSize; i++)
        {
            data[i] = initData[i];
        }

    }
    HexArray(const HexArray& other)
    {
        copyFrom(other);
    }
    HexArray& operator=(const HexArray& other)
    {
        if (this!=&other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    HexArray(HexArray&& other) noexcept
    {
        moveFrom(std::move(other));
    }
    HexArray& operator=(HexArray&& other) noexcept
    {
        if (this!=&other)
        {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }
    ~HexArray()
    {
        free();
    }

    friend std::ostream& operator<<(std::ostream& os, const HexArray& arr)
    {
        for (int i = 0; i < arr.size; i++)
        {
            if (isValidSymbol(arr.data[i]))
            {
                os << std::hex << arr.data[i]<<" ";
            }
            else
            {
                os << '.' << " ";
            }
        }
        std::cout<<std::endl;
        for (int i = 0; i < arr.size; i++)
        {
            os << std::hex << (int)arr.data[i] << " ";
        }
        return os;
    }

    template <class T>
    friend void operator>>(const T& toSerialize, HexArray& arr)
    {
        unsigned char* newData = createAndFillByteArray(arr.size + sizeof(T), arr.data, arr.size);
        memcpy(newData + arr.getSize(), reinterpret_cast<const unsigned char*>(&toSerialize), sizeof(T));
        arr.size += sizeof(T);
        delete[] arr.data;
        arr.data = newData;
    }

    const unsigned char* c_str() const
    {
        return data;
    }

    unsigned getSize() const
    {
        return size;
    }
};

class HexArrayView
{
private:
    const unsigned char* begin;
    const unsigned char* end;
public:
    HexArrayView(const unsigned char* _begin, const unsigned char* _end) :begin(_begin), end(_end)
    {

    }

    HexArrayView(const HexArray& arr) :HexArrayView(arr.c_str(), arr.c_str() + arr.getSize())
    {

    }

    size_t length() const
    {
        return end - begin;
    }

    unsigned char operator[](size_t index) const
    {
        return begin[index];
    }

    HexArrayView substr(size_t from, size_t length)
    {
        if (begin+from+length>end)
        {
            throw std::exception("Out of range");
        }
        return HexArrayView(begin + from, begin + from + length);
    }

    friend std::ostream& operator<<(std::ostream& os, const HexArrayView& arr)
    {
        const unsigned char* iter = arr.begin;
        while (iter!=arr.end)
        {
            os <<std::hex << *iter;
            iter++;
            /*std::cout << std::hex << iter++;*/
        }
        return os;
    }
};

class Serializator
{
protected:
    char fileName[128];
    const HexArray& arr;
public:
    Serializator(const char* name, const HexArray& arr) :arr(arr)
    {
        strcpy(fileName, name);
    }
    virtual void serialize() = 0;
    virtual Serializator* clone() const = 0;
    virtual ~Serializator() = default;
};

class BinarySerializator :public Serializator
{
public:
    BinarySerializator(const char* name, const HexArray& arr) :Serializator(name, arr)
    {

    }
    void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open())
        {
            throw std::exception("Cannot open file");
        }
        ofs.write((const char*)arr.c_str(), arr.getSize());
        ofs.close();
    }
    Serializator* clone() const override
    {
        return new BinarySerializator(*this);
    }
};

class TxtHexSerializator :public Serializator
{
public:
    TxtHexSerializator(const char* name, const HexArray& arr) :Serializator(name, arr)
    {

    }
    void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open())
        {
            throw std::exception("Cannot open file");
        }
        for (int i = 0; i < arr.getSize(); i++)
        {
            ofs << std::hex << arr.data[i] << ' ';//arr.c_str()
        }
    }
    Serializator* clone() const override
    {
        return new TxtHexSerializator(*this);
    }
};

class TxtDecimalSerializator :public Serializator
{
public:
    TxtDecimalSerializator(const char* name, const HexArray& arr) :Serializator(name, arr)
    {

    }
    void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open())
        {
            throw std::exception("Cannot open file");
        }
        for (int i = 0; i < arr.getSize(); i++)
        {
            ofs << arr.c_str()[i] << ' ';
        }
    }
    Serializator* clone() const override
    {
        return new TxtDecimalSerializator(*this);
    }
};

Serializator* serializatorFactory(const HexArray& arr, const char* filename);

class RecSerializator :public Serializator
{
private:
    Serializator* ser;
public:
    RecSerializator(const char* name, const HexArray& arr) :Serializator(name, arr)
    {
        std::ifstream ifs(name);
        char recFileName[1024];
        ifs >> recFileName;
        ser = serializatorFactory(arr, fileName);
    }
    void serialize() override
    {
        std::ofstream(fileName, std::ios::binary | std::ios::trunc);//izchistvam tekushtite danni ot faila
        ser->serialize();
    }

    Serializator* clone() const override
    {
        return new RecSerializator(*this);
    }

    RecSerializator(const RecSerializator& other) :Serializator(other)
    {
        ser = ser->clone();
    }
    ~RecSerializator()
    {
        delete ser;
    }
};

Serializator* serializatorFactory(const HexArray& arr, const char* filename)
{
    const char* extension = getFileExtension(filename);
    if (strcmp(extension,"dat"))
    {
        return new BinarySerializator(filename, arr);
    }
    if (strcmp(extension,"txtHex"))
    {
        return new TxtHexSerializator(filename, arr);
    }
    if (strcmp(extension,"txt"))
    {
        return new TxtDecimalSerializator(filename, arr);
    }
    if (strcmp(extension,"rec"))
    {
        return new RecSerializator(filename, arr);
    }
    return nullptr;
}

class Deserializator
{
protected:
    char fileName[128];
public:
    Deserializator(const char* name) 
    {
        strcpy(fileName, name);
    }
    
    virtual HexArray deserialize() const = 0;
    virtual ~Deserializator() = default;
};

class BinaryDeserializator :public Deserializator
{
public:
    BinaryDeserializator(const char* name) :Deserializator(name)
    {

    }

    HexArray deserialize() const override
    {
        std::ifstream ifs(fileName);
        if (!ifs.is_open())
        {
            throw std::exception("Cannot open file");
        }
        size_t size = getFileSize(ifs);
        unsigned char* data = new unsigned char[size];
        ifs.read((char*)data, size);
        ifs.close();
        return HexArray(data, size);
    }
};

class TxtHexDeserializator :public Deserializator
{
public:
    TxtHexDeserializator(const char* name) :Deserializator(name)
    {

    }

    HexArray deserialize() const override
    {
        std::ifstream ifs(fileName);
        if (!ifs.is_open())
        {
            throw std::exception("Cannot open file");
        }
        size_t size = getCharCount(ifs, ' ') + 1;
        unsigned char* data = new unsigned char[size];
        for (int i = 0; i < size; i++)
        {
            int tempByte;
            ifs >> std::hex >> tempByte;
            data[i] = tempByte;
        }
        return HexArray(data, size);
    }
};

class TxtDecimalDeserializator :public Deserializator
{
public:
    TxtDecimalDeserializator(const char* name) :Deserializator(name)
    {

    }

    HexArray deserialize() const override
    {
        std::ifstream ifs(fileName);
        if (!ifs.is_open())
        {
            throw std::exception("Cannot open file");
        }
        size_t size1 = getCharCount(ifs, '\n') + 1;
        unsigned char* data1 = new unsigned char[size1];
        for (int i = 0; i < size1; i++)
        {
            int tempByte;
            ifs >> tempByte;
            data1[i] = tempByte;
        }
        return HexArray(data1, size1);
    }
};

Deserializator* deserializatorFactory(const char* fileName)
{
    const char* extension = getFileExtension(fileName);
    if (strcmp(extension,"dat"))
    {
        return new BinaryDeserializator(fileName);
    }
    if (strcmp(extension,"txtHex"))
    {
        return new TxtHexDeserializator(fileName);
    }
    if (strcmp(extension,"txt"))
    {
        return new TxtDecimalDeserializator(fileName);
    }
    return nullptr;
}
int main()
{
    char temp[1024], inputName[128], outputName[128];
    std::cin >> inputName;
    Deserializator* des = deserializatorFactory(inputName);
    std::cin >> temp;
    HexArray ha = des->deserialize();
    int n;
    std::cin >> n;
    n >> ha;
    std::cin >> outputName;
    Serializator* ser = serializatorFactory(ha, outputName);
    std::cin >> temp; //write;
    ser->serialize();
    delete ser;
    delete des;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
