/*
	@author: Jose A Huerta <josehuerat115@gmail.com>
	@version: 1.0
	
	Algorithm: 
		
		START 

		Take in user input
		use for loop to run thru string
		check every index of string and increment int array at index of char of string
		after running thru for loop, find biggest value in counter array
		return index of largest number casted as char value
		print most freq char to user

		END
		
*/

#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//Prototypes
char mostFrequentChar(string input);

int main()
{
	string input;
	char mostFreq = ' ';
	cout << "Enter a phrase:";
	getline(cin, input);
	
	mostFreq = mostFrequentChar(input);

	if (mostFreq != ' ')
	{
		cout << "Most frequent char: " << mostFreq << "\n";
	}

	system("pause");
	return 0;
}

char mostFrequentChar(string input)
{
	int index;
	int counts[127];
	for (int i = 0; i < 127; i++) { counts[i] = 0; } //fills array

	for (int i = 0; i < input.length(); i++) 
	{
		if (input.at(i) != ' ')
		{
			counts[input.at(i)] += 1; //counts amount each char in phrase
		}
	} 

	index = 0;
	for (int i = 1; i < 127; i++)
	{
		if (counts[index] < counts[i])
		{
			index = i;
		}
	}

	return (char) index;
}