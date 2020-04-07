#include <iostream>
using namespace std;

class AString
{
public:
	AString() 
	{
		
	}

	AString(char* str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}

	~AString()
	{
		delete[] this->str;
	}

private:
	char* str;
};








int main() 
{
	AString str;



	return 0;
}

