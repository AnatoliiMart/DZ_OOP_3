#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class String
{
public:
	static int amountOfStrings;
	String()
	{
		str = new char[0];
		std::cin.getline(str, 80);
		amountOfStrings++;
	}
	String(const int bufSize)
	{
		str = new char[bufSize + 1];
		std::cin.getline(str, bufSize);
		amountOfStrings++;
	}
	String(const char* Str)
	{
		size_t size = strlen(Str) + 1;
		str = new char[size];
		strcpy_s(str, strlen(Str) + 1, Str);
		amountOfStrings++;
	}
	String(int size, int size2)
	{
		InputString();
		amountOfStrings++;
	}
	void InputString()
	{
		str = new char[150];
		std::cin.getline(str, 150);
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
	String operator+(const String& obj)												 //operator+ (strcat)
	{
		strcat(this->str, obj.str);
		return *this;
	}
	String(const String& obj)														// copy constructor
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}
	bool operator < (const String& obj)
	{
		return strcmp(this->str, obj.str) < 0 ? true : false;
	}
	void SetStr(char* s)
	{
		size_t length = strlen(s);
		str = new char[length + 1];
		if (str)
		{
			strcpy_s(str, length +1, s);
		}
	}

	char* GetStr() const
	{
		return str;
	}
	
private:
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

	String temp;                                      
	temp.SetStr(tmpStr1); 

	delete[] tmpStr;
	delete[] tmpStr1;

	return temp;                                            
}

int String::amountOfStrings = 0;

int main()
{
	std::cout << "First string (constructor by default): " << std::endl;
	String obj;
	obj.Output();

	std::cout << "Second string (constructor with parameter of buffer size): " << std::endl;
	String obj1(22);
	obj1.Output();

	std::cout << "Third string (constructor with parameter of string): " << std::endl;
	String obj2("Hello World!!!");
	obj2.Output();

	std::cout << "Fourth string (constructor with fake paramerters): " << std::endl;
	String obj3(5, 10);
	obj3.Output();

	std::cout << "Concatenated strings (overload operator+): \n";
	obj2 + obj1;
	obj2.Output();

	bool correct = obj2 < obj1;
	std::cout << "Overload operator < : " << correct << std::endl;

	String obj4(obj2);
	std::cout << "Copy one obj into another (copy constructor):";
	obj4.Output();

	std::cout << "Overload operator +(int): " << std::endl;
	int xAmount;
	String obj5("FFFFF");
	obj5.Output();

	std::cout << "How much symbols you want to add: ";
	std::cin >> xAmount;
	
	String obj6 = xAmount + obj5;
	obj6.Output();

	std::cout << "Amount of strings: " << String::amountOfStrings << std::endl;
	return 0;
}