#pragma once
#include<iostream>
class String
{
public:
	static int amountOfStrings;
	String()
	{
		size = 80;
		str = new char[size + 1];
		std::cin.getline(str, size);
		amountOfStrings++;
	}

	String(const int bufSize)
	{
		size = bufSize;
		str = new char[size + 1];
		std::cin.getline(str, size);
		amountOfStrings++;
	}

	String(const char* Str)
	{
		size = strlen(Str) + 1;
		str = new char[size];
		strcpy_s(str, size, Str);
		amountOfStrings++;
	}

	String(int size, int size2)
	{
		InputString();
		amountOfStrings++;
	}

	String(const String& obj)														// copy constructor
	{
		std::cout << "Copy constructor" << std::endl;
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}
	String(String&& obj) noexcept															// move constructor
	{
		std::cout << "Move constructor" << std::endl;
		this->size = obj.size;
		this->str = obj.str;
		obj.str = nullptr;
		obj.size = 0;
	}
	String(const std::initializer_list<char>& list) : String(list.size())  // InitializerList Constructor
	{
		size = list.size();
		for (auto ptr = list.begin(); ptr != list.end(); ptr++)
		{
			*str = *ptr;
			str++;
		}
		str -= size; 
		amountOfStrings++;
	}

	void InputString()
	{
		size = 150;
		str = new char[size];
		std::cin.getline(str, size);
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
		size = strlen(s);
		str = new char[size + 1];
		if (str)
		{
			strcpy_s(str, size + 1, s);
		}
	}

	char* GetStr() const
	{
		return str;
	}

	bool   operator  < (const String& obj)
	{
		return strcmp(this->str, obj.str) < 0 ? true : false;
	}

	String operator  +  (const String& obj)												 //operator+ (strcat)
	{
		strcat(this->str, obj.str);
		return *this;
	}

	String operator  ++ (int)
	{
		char* tmpStr = new char[2] {"x"};
		String tmp;

		tmp.size = size + strlen(tmpStr) + 1;
		tmp.str = new char[tmp.size];
		strcpy(tmp.str, str);
		strcat(tmp.str, tmpStr);

		if (str != nullptr)
		{
			delete[] str;
		}

		str = new char[tmp.size];
		strcpy(str, tmp.str);

		delete[] tmpStr;

		return *this;
	}

	String operator  -- (int)
	{
		String tmp;

		tmp.size = strlen(str);
		tmp.str = new char[tmp.size];
		size_t i = 0;
		for (; i < tmp.size - 1; i++)
		{
			tmp.str[i] = str[i];
		}
		tmp.str[i] = 0;

		if (str != nullptr)
		{
			delete[] str;
		}

		str = new char[tmp.size];
		strcpy(str, tmp.str);

		return *this;
	}

	String operator  +  (int x)
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
		tmp.size = size + strlen(tmpStr);
		tmp.str = new char[tmp.size + 1];
		strcpy(tmp.str, str);
		strcat(tmp.str, tmpStr);
		delete[] tmpStr;
		return tmp;
	}

	String operator  -  (int x)
	{
		String tmp;
		tmp.size = strlen(str) - x;
		tmp.str = new char[tmp.size + 1];

		for (size_t i = 0; i <= tmp.size; i++)
		{
			if (i < tmp.size)
			{
				tmp.str[i] = str[i];
			}
			else if (i == tmp.size)
			{
				tmp.str[i] = '\0';
			}
		}
		return tmp;
	}
	String& operator = (String&& object)    noexcept     
	{
		std::cout << "Assignment operator for the shuffle constructor\n";
		if (!(this == &object))                              
		{
			delete[] str;
			str = object.str;
			size = object.size;
			object.str = nullptr;
			object.size = 0;
		}
		return *this;
	}
private:
	size_t size = 0;
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

