#include <iostream>
using namespace std;

class AString
{
public:

	//����������� ������ ��� �������� ����������
	AString() 
	{
		str = nullptr;
	}

	//����������� ������ � �������� ���������� ���� char
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

	//���������� ������
	~AString()
	{
		delete[] this->str;
	}

	//�������� ������������
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

	//����������� �����������
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

	//����������� �������� ���� �������
	AString operator+(const AString & other)
	{

	}

	//����� ������ ������� � ��������� ������
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

