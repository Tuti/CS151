/*
	@author: Jose A Huerta <josehuerta115@gmail.com>
	@version: 1.0

	Algorithm:
	
	START 

	Read in file1 and save input to vector
	Check index if == '.'
	IF index == '.'
		check if i + 2 < input.length() and if so change i + 2 to input.at(i + 2) = input.at(i + 2) - 32
	ELSE
		do nothing
	write new vector to file2

	END
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include<cstring>

using namespace std;

vector<string> MakeUpperCase(vector<string> list);
bool isUpperCaseAlpha(char input);
bool isPeriod(char input);

//vars
static string file1 = "random.txt";
static string file2 = "random2.txt";

int main()
{
	vector<string> lines;
	fstream stream;
	
	cout << "Attempting to read in file...\n";
	try
	{
		stream.open(file1.c_str());
		char *input = new char[256];
		while (!stream.eof())
		{
			stream.getline(input, 256);
			lines.push_back(input);
		}
	}
	catch (const fstream::failure& e)
	{
		std::cout << "Error opening file...\n";
		return 1;
	}
	stream.close();

	cout << "File has been readin...\n";
	lines = MakeUpperCase(lines);

	cout << "Attempting to write to file...\n";
	try
	{
		stream.open(file2.c_str());
		
		for (int i = 0; i < lines.size(); i++)
		{
			stream << lines.at(i) << "\n";
		}
		
	}
	catch (const fstream::failure& e)
	{
		std::cout << "Error opening file...\n";
		return 1;
	}
	stream.close();
	cout << "File has been written to...\n";

	system("pause");
	return 0;
}

vector<string> MakeUpperCase(vector<string> list)
{
	vector<string> uppercase;
	string temp;
	char test;
	
	for (int i = 0; i < list.size(); i++)
	{
		temp = list.at(i);
		for (int j = 0; j < temp.length(); j++)
		{
			
			test = temp.at(j);

			if (j == 0 && !isUpperCaseAlpha(test) && !isPeriod(test))
			{
				temp.at(j) = (test - 32);
			}

			else if (isPeriod(test) && (j + 2) < temp.length())
			{
				temp.at(j + 2) = (temp.at(j + 2) - 32);
			}
		}

		uppercase.push_back(temp);
	}

	return uppercase;
}

bool isUpperCaseAlpha(char input)
{
	return input < 65 && input > 90;
}

bool isPeriod(char input)
{
	return input == '.';
}

