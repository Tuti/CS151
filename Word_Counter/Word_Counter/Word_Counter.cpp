/*
	Word_Counter.cpp: counts words in a c string parameter

	Algorithm: 
	
	Take in user input from stream
	save input into a c string
	Pass into function wordCounter(char *input, int length)
	run for loop that increments a counter everytime a ' ' char is found
	return counter + 1 to take into account last word
	return to user amount of words

	@author: Jose A Huerta <josehuerta115@gmail.com>
	@version: 1.0
*/



#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstring>
static int LENGTH = 80;

//Prototypes 
int wordCounter(char *input, int length);
double averageLettersPerWord(char *input, int length);

int main()
{
	
	char *input = new char[80];
	std::string temp = "";
	int count;
	double averageLetter;
	
	std::cout << "Enter a sentence: \n";
	std::cin.getline(input, LENGTH);	
	count = wordCounter(input, LENGTH);
	averageLetter = averageLettersPerWord(input, LENGTH);
	std::cout << "\nAmount of words in string: " << count << "\n";
	std::cout << "Letter average per word: " << averageLetter << "\n";
	system("pause");
    return 0;
}

double averageLettersPerWord(char *input, int length)
{
	double sum = 0.0;
	double wordcount = wordCounter(input, length);	
	for (int i = 0; i < length; i++)
	{
		if (input[i] > 64 && input[i] < 126)
		{
			sum++;
		}
	}

	return sum / wordcount;
}
int wordCounter(char *input, int length)
{
	int wordcount = 0;
	for (int i = 0; i < length; i++)
	{
		if (input[i] == ' ')
		{
			wordcount++;
		}
	}
	return wordcount + 1;
}