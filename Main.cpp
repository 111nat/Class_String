#include <iostream>
#include <string>
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

	//����������� �����������
	AString(const AString& other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
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

	

	//����������� �������� ���� �������
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

	//����������� �������� ������� �� ����
	AString& operator+=(const AString & other)
	{
		if (this->str != nullptr)
		{
			if (other.str != nullptr)
			{
				int length_t = strlen(this->str);
				AString temp1;
				temp1.str = new char[length_t + 1];
				for (int i = 0; i < length_t; i++)
				{
					temp1.str[i] = this->str[i];
				}
				temp1.str[length_t] = '\0';

				int length_o = strlen(other.str);
				AString temp2;
				temp2.str = new char[length_o + 1];
				for (int i = 0; i < length_o; i++)
				{
					temp2.str[i] = other.str[i];
				}
				temp2.str[length_t] = '\0';

				delete[] this->str;
				this->str = new char[length_t + length_o + 1];

				int i = 0;
				for (; i < length_t; i++)
				{
					this->str[i] = temp1.str[i];
				}

				for (int j = 0; j < length_o; j++, i++)
				{
					this->str[i] = temp2.str[j];
				}
				this->str[length_t + length_o] = '\0';
				return *this;
			}else{
				return *this;
			}
		}
		else {
			if (other.str != nullptr) {
				str = new char[strlen(other.str) + 1];
				for (int j = 0; j < strlen(other.str); j++)
				{
					this->str[j] = other.str[j];
				}
				this->str[strlen(other.str)] = '\0';
				return *this;
			}else{

			}
		}

		
	}

	//����������� ==
	bool operator ==(const AString& other)
	{	
		if (str == nullptr && other.str !=nullptr)
		{
			return false;
		}
		if (str != nullptr && other.str == nullptr)
		{
			return false;
		}
		if (str == nullptr && other.str == nullptr)
		{
			return true;
		}
		if (str != nullptr && other.str != nullptr)
		{
			int length_t = strlen(str);
			int length_o = strlen(other.str);
			if (length_t != length_o)
			{
				return false;
			}
			for (int i = 0; i < length_t; i++)
			{
				if (str[i] != other.str[i])
				{
					return false;
				}
			}
			return true;
		}	
	}

	//����� ������ ������� � ��������� ������
	void print()
	{
		if (str != nullptr) 
		{
			int length = strlen(str);
			for (int i = 0; i < length; i++)
			{
				cout << str[i];
			}
			cout << endl;
		}
		
	}
private:
	char* str;
};

int main() 
{
	AString str="hell";

	AString str2="hello";
	

	//str += str2;

	//str.print();
	
	cout << (str == str2);

	return 0;
}

