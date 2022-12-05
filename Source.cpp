#include<iostream>

class String
{
public:
	static int amountOfStrings;
	String()
	{
		std::cin.getline(str, 80);
		amountOfStrings++;
	}
	String(const int bufSize)
	{
		str = new char[bufSize + 1];
		std::cin.getline(str, bufSize);
		amountOfStrings++;
	}
	String(const char* str)
	{
		str = new char[strlen(str + 1)];
		strcpy_s(this->str, strlen(str + 1), str);
		amountOfStrings++;
	}
	String(char str)
	{
		
		InputString();
	  Output();
		amountOfStrings++;
	}
	void InputString()
	{
		str = new char[1];
		std::cin.getline(str, strlen(str + 1));
	}
	void Output()
	{
		std::cout << "Entered string: " << str;
	}
	static int GetAmount()
	{
		return amountOfStrings;
	}
	~String()
	{
		delete[] str;
	}
	

private:
	char* str;
};

int String::amountOfStrings = 0;

int main()
{
	std::cout << String::amountOfStrings << std::endl;
	String obj;
	obj.Output();
	String obj1(22);
	obj1.Output();
	String obj2("Hello World");
	obj2.Output();
	char str[100];
	String obj3(str);
	
	std::cout << String::amountOfStrings << std::endl;

}