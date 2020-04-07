#include <iostream>
using namespace std;

class AString
{
public:

	//конструктор класса без входящих параметров
	AString() 
	{
		str = nullptr;
	}

	//конструктор класса с входящим параметром типа char
	AString(const char *str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}

	//деструктор класса
	~AString()
	{
		delete[] this->str;
	}

	//оператор присваивания
	AString& operator=(const AString & other)
	{
		if (this->str!=nullptr)
		{
			delete[] str;
		}
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}

	//конструктор копирования
	AString(const AString & other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	//конструктор сложения двух строчек
	AString operator+(const AString & other)
	{

	}

	//метод вывода строчек в командную строку
	void print(const AString& other)
	{

	}
private:
	char* str;
};



int main() 
{
	AString str="hello";

	AString str1("hello");

	
	return 0;
}

