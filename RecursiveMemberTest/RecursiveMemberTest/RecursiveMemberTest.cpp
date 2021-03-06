// RecursiveMemberTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//Prototypes
bool isMember(int x[], int size, int search);

int main()
{
	int x[10];
	int value;

	cout << "Enter 10 values...";
	cout << "\n";

	for(int i = 0; i < 10; i++)
	{
		cout << "Enter a number: ";
		cin >> value;
		cout << "\n";
		x[i] = value;
	}

	cout << "Enter a value to search for: ";
	cin >> value;
	cout << "\n";

	if (isMember(x, 10, value))
	{
		cout << value << " is in the array.\n";
	}
	else
	{
		cout << value << " is not in the array.\n";
	}

	system("pause");
    return 0;
}

bool isMember(int x[], int size, int search)
{
	if (size == 0)
	{
		return false;
	}
	else if (x[size - 1] == search)
	{
		return true;
	}
	else
	{
		return isMember(x, size - 1, search);
	}
}

