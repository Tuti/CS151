/*
	SentenceCap.cpp

	Algorithm:

	START

	Take in user input
	Save input to char pointer
	Display original sentence to user
	Pass input into capitalizedSentences 
	Check char if == '.'
		if so char[i + 2] -= 32 if char[i + 2] > 96 (ascii table lowercase letters)
	Return to user sentence 
	
	END 
*/

#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

int static LENGTH = 80;

//Prototypes: 
void capitalizedSentences(char *input, int length);

int main()
{
	char *input = new char[LENGTH];

	std::cout << "Enter sentence to capitalize: \n";
	std::cin.getline(input, LENGTH);

	std::cout << "\nOriginal: " << input << "\n";
	capitalizedSentences(input, LENGTH);
	std::cout << "Capitalized: " << input << "\n";

	system("pause");
    return 0;
}

void capitalizedSentences(char *input, int length)
{
	if (input[0] > 96 && input[0] < 123)
	{
		input[0] -= 32;
	}

	for (int i = 0; i < length; i++)
	{
		if ((input[i] == '.') && ((i + 2) < length) && (input[i + 2] > 96))
		{
			input[i + 2] -= 32;
		}
	}
}

