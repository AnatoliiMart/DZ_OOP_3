#pragma once
#include<iostream>
class String
{
public:
	static int amountOfStrings;
	String()
	{
		length = 80;
		str = new char[length + 1];
		std::cin.getline(str, length);
		amountOfStrings++;
	}

	String(const int bufSize)
	{
		length = bufSize;
		str = new char[length + 1];
		std::cin.getline(str, length);
		amountOfStrings++;
	}

	String(const char* Str)
	{
		length = strlen(Str) + 1;
		str = new char[length];
		strcpy_s(str, length, Str);
		amountOfStrings++;
	}

	String(int size, int size2)
	{
		InputString();
		amountOfStrings++;
	}

	String(const String& obj)														// copy constructor
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}

	void InputString()
	{
		length = 150;
		str = new char[length];
		std::cin.getline(str, length);
	}

	void Output()
	{
		std::cout << "Entered string: " << str;
		std::cout << std::endl;
	}

	static int GetAmount()
	{
		return amountOfStrings;
	}

	void SetStr(char* s)
	{
		length = strlen(s);
		str = new char[length + 1];
		if (str)
		{
			strcpy_s(str, length + 1, s);
		}
	}

	char* GetStr() const
	{
		return str;
	}

	bool   operator < (const String& obj)
	{
		return strcmp(this->str, obj.str) < 0 ? true : false;
	}

	String operator+  (const String& obj)												 //operator+ (strcat)
	{
		strcat(this->str, obj.str);
		return *this;
	}

	String operator++ (int)
	{
		char* tmpStr = new char[2] {"x"};
		String tmp;

		tmp.length = length + strlen(tmpStr) + 1;
		tmp.str = new char[tmp.length];
		strcpy(tmp.str, str);
		strcat(tmp.str, tmpStr);

		if (str != nullptr)
		{
			delete[] str;
		}

		str = new char[tmp.length];
		strcpy(str, tmp.str);

		delete[] tmpStr;

		return *this;
	}

	String operator-- (int)
	{
		String tmp;

		tmp.length = strlen(str);
		tmp.str = new char[tmp.length];
		size_t i = 0;
		for (; i < tmp.length - 1; i++)
		{
			tmp.str[i] = str[i];
		}
		tmp.str[i] = 0;

		if (str != nullptr)
		{
			delete[] str;
		}

		str = new char[tmp.length];
		strcpy(str, tmp.str);

		return *this;
	}

	String operator+  (int x)
	{
		char* tmpStr = new char[x + 1];
		for (size_t i = 0; i <= x; i++)
		{
			if (i < x)
			{
				tmpStr[i] = 'x';
			}
			else if (i == x)
			{
				tmpStr[i] = '\0';
			}
		}

		String tmp;
		tmp.length = length + strlen(tmpStr);
		tmp.str = new char[tmp.length + 1];
		strcpy(tmp.str, str);
		strcat(tmp.str, tmpStr);
		delete[] tmpStr;
		return tmp;
	}

	String operator-  (int x)
	{
		String tmp;
		tmp.length = strlen(str) - x;
		tmp.str = new char[tmp.length + 1];

		for (size_t i = 0; i <= tmp.length; i++)
		{
			if (i < tmp.length)
			{
				tmp.str[i] = str[i];
			}
			else if (i == tmp.length)
			{
				tmp.str[i] = '\0';
			}
		}
		return tmp;
	}
private:
	size_t length = 0;
	char* str;
};

String operator+(int xCount, String Obj)
{
	char* tmpStr = new char[xCount + 1];
	for (int i = 0; i <= xCount; i++)
	{
		if (i < xCount)
		{
			tmpStr[i] = { 'x' };
		}
		else if (i == xCount)
		{
			tmpStr[i] = '\0';
		}
	}
	char* tmpStr1 = new char[strlen(tmpStr) + strlen(Obj.GetStr()) + 1];
	strcpy(tmpStr1, tmpStr);
	strcat(tmpStr1, Obj.GetStr());

	String tmp;
	tmp.SetStr(tmpStr1);

	delete[] tmpStr;
	delete[] tmpStr1;

	return tmp;
}

int String::amountOfStrings = 0;

