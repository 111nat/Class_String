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
		AString temp;
		temp.str = new char[strlen(this->str) + strlen(other.str) + 1];
		int i = 0;
		for (; i < strlen(this->str); i++) 
		{
			temp.str[i] = this->str[i];
		}
		for (int j = 0; j < strlen(other.str); j++,i++)
		{
			temp.str[i] = other.str[j];
		}
		temp.str[strlen(this->str) + strlen(other.str)] = '\0';
		return temp;
	}

	//метод вывода строчек в командную строку
	void print()
	{
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
private:
	char* str;
};



int main() 
{
	AString str="hello";

	AString str1="world";

	AString str2;

	str.print();
	
	str2 = str + str1;
	str2.print();

	return 0;
}

