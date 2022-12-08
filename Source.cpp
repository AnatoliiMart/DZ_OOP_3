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
		int size = strlen(Str) + 1;
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
		str = new char[BUFSIZ];
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
	std::cout << "First string: " << std::endl;
	String obj;
	obj.Output();

	std::cout << "Second string: " << std::endl;
	String obj1(22);
	obj1.Output();

	std::cout << "Third string:" << std::endl;
	String obj2("Hello World!!!");
	obj2.Output();

	std::cout << "Fourth string:" << std::endl;
	String obj3(5, 10);
	obj3.Output();
	std::cout << String::amountOfStrings << std::endl;
	return 0;
}