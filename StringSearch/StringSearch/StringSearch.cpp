
/*
	@author: Jose A Huerta <josehuerta115@gmail.com>
	@version: 1.0

	Algorithm: 

	START 

	Take in user input for file name
	read in file text data
	store values in vector
	read each value in vector, if find function returns value != string::npos, save index of vector value
	IF No indexes saved
		print string not found in file
	ELSE
		print vector.at(indexes saved) to user

	END
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Prototypes
int numberOfOccurences(vector<string> list, string input);
vector<int> locationOfOccurences(vector<string> list, string input);
void printStringSearchDetails(vector<string> list, string input);

int main()
{
	std::string filename;
	std::fstream filestream;
	std::vector<std::string> lines;
	std::vector<int> occurences;
	
	std::string input;

	cout << "Enter name of txt file: ";
	getline(cin, filename);

	try
	{
		filestream.open(filename.c_str());
		char *input = new char[256];
		while (!filestream.eof())
		{
			filestream.getline(input, 256);
			lines.push_back(input);
		}
	}
	catch (const fstream::failure& e)
	{
		std::cout << "Error opening file...\n";
		return 1;
	}

	cout << "Enter phrase to search for: ";
	getline(cin, input);
	cout << "\n";

	printStringSearchDetails(lines, input);

	system("pause");
	return 0;
}

int numberOfOccurences(vector<string> list, string input)
{
	int count = 0;
	int index = -1;

	for(int i = 0;i < list.size(); i++)
	{
		index = list.at(i).find(input.c_str());
		if (index != string::npos)
		{
			count++;
		}
	}

	return count;
}

vector<int> locationOfOccurences(vector<string> list, string input)
{
	vector<int> occurences;
	int index;

	for (int i = 0; i < list.size(); i++)
	{
		index = list.at(i).find(input.c_str());
		if (index != string::npos)
		{
			occurences.push_back(i);
		}
	}
	
	return occurences;
}

void printStringSearchDetails(vector<string> list, string input)
{
	vector<int> occurences = locationOfOccurences(list, input);
	int count = numberOfOccurences(list, input);
	
	if(occurences.size() < 1)
	{
		cout << "String not found in file\n";
		return;
	}
	
	cout << "All occurences of string: " << input << "\n";
	for (int i = 0; i < occurences.size(); i++)
	{
		cout << list.at(occurences.at(i)) << "\n";
	}
	cout << "Total occurences: " << count << "\n";
}