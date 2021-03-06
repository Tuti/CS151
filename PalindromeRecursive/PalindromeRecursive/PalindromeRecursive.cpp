// PalindromeRecursive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string> 
#include <iostream>

using namespace std;

//Prototype
bool isPalindrome(string arg);

int main()
{
	string input;
	cout << "Enter phrase to check for palindrome: ";
	getline(cin, input);

	if (isPalindrome(input))
	{
		cout << input << " is a palindrome.\n";
	}
	else
	{
		cout << input << " is not a palindrome.\n";
	}

	system("pause");
    return 0;
}


bool isPalindrome(string arg)
{
	if (arg.length() == 1 || arg.length() == 0)
	{
		return true;
	}
	else if (arg.at(0) == arg.at(arg.length() - 1))
	{
		return isPalindrome(arg.substr(1, arg.length() - 2));
	}
	else
	{
		return false;
	}
}
