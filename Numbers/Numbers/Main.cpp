#include "stdafx.h"
#include <iostream>
#include <string>
#include "Numbers.h"

int main()
{
	int number;

	std::cout << "Enter a number from 0-9999\n";
	std::cin >> number;

	while (number < 0 || number > 9999)
	{
		std::cout << "Enter a correct value given the parameters!\n";
		std::cin >> number;
	}

	Numbers num = Numbers(number);
	std::string output = num.Print();
	std::cout << "\nNumber Translation to English: " << output << "\n";
	
	system("pause");
	return 0;
}
