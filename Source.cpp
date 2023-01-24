#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include"String.h"


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

	std::cout << "Overload operator++: " << std::endl;
	String obj7("AAAAA");
	obj7.Output();
	obj7++;
	obj7.Output();

	std::cout << "Overload operator--: " << std::endl;
	String obj8("BBBBB");
	obj8.Output();
	obj8--;
	obj8.Output();

	std::cout << "Overload operator+(int) to end of string: " << std::endl;
	String obj9("CCCCC");
	obj9.Output();
	obj9 = obj9 + 2;
	obj9.Output();

	std::cout << "Overload operator-(int) out of the end of string: " << std::endl;
	obj9 = obj9 - 4;
	obj9.Output();

	String obj10("Moving");
	obj10.Output();
	obj10 = std::move(obj9);
	obj10.Output();

	std::cout << "Initializer List use" << std::endl;
	String obj11{ '1','2', '3', '4', '5','\0'};
	obj11.Output();
	std::cout << "Amount of strings: " << String::amountOfStrings << std::endl;
	return 0;
}