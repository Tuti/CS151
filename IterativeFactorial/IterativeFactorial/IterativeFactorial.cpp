// IterativeFactorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int factorial(int num);

int main()
{
	int num;
	cout << "Enter number to find factorial of: ";
	cin >> num;
	
	cout << "\nFactorial of " << num << ": " << factorial(num);
	cout << "\n";
	
	system("pause");
    return 0;
}

int factorial(int num)
{
	int x = 1;
	for (int i = 1; i <= num; i++) 
	{
		x *= i;
	}

	return x;
}
