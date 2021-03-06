
/*
	@author: Jose A Huerta <josehuerta115@gmail.com>
	@version: 1.0

	Algorithm: 

	START 

	Read in user input of text file name
	Save each line to vector<string>
	Check is vector.size() is < 10
	IF LESS THAN 10
		print vector's contents to screen
	ELSE
		subtract vector.size() - 10
		print vector's contents starting from vector.size() - 10 to vector.size()

	END	
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include<cstring>

//Prototypes 
void printLastTenLines(std::vector<std::string> list);

int main()
{
	std::string filename;
	std::fstream filestream;
	std::vector<std::string> lines;

	std::cout << "Enter name of txt file: \n\n";
	std::cin >> filename;
    
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
	catch (int e)
	{
		std::cout << "Error opening file...\n";
		return 1;
	}

	printLastTenLines(lines);
	

	system("pause");
	return 0;
}

void printLastTenLines(std::vector<std::string> list)
{
	if (list.size() < 10)
	{
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << i << ". " << list.at(i) << "\n";
		}
	}
	else
	{
		for (int i = list.size() - 10; i < list.size(); i++)
		{
			std::cout << i << ". " << list.at(i) << "\n";
		}
	}
	
}