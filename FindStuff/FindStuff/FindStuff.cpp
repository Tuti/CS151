/*
	@author: Jose Huerta <josehuerta115@gmail.com>
	@version: 1.0

	Algorithm: 

	Take in userinput
	use for loop to check phonelist[] at index i and use find function
	if an index is returned, save i to vector
	if vector size is 0, no contacts were found matching that name
	if vector size is > 0, print phonelist[vector.at(i)] using for loop to print all catches(indexes) saved in vector 

*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

static string phonelist[] = { "Andre 760 123 4567", "Jose Huerta 760 321 4321", "Michael Flaherty 760 432 5423",
								"Jessica Huerta 760 009 4323", "Rick Sanchez 760 696 1113", "Morty Smith 745 644 5342",
								"James smith 705 543 2432", "Jason Doe 683 943 3241", "Summer Smith 763 451 5678", "June Porto 760 241 3256"
							};
static int phonelistsize = 10;
static vector<int> listofcatches;
int main()
{

	string input, output;
	
	cout << "Enter name to search for in phone list: ";
	getline(cin, input);

	for (int i = 0; i < phonelistsize; i++)
	{
		int index = phonelist[i].find(input.c_str());
		if (index != string::npos)
		{
			listofcatches.push_back(i);
		}
	}

	if (listofcatches.size() < 1) { cout << "No contacts found...\n"; }
	else
	{
		cout << "Contacts:\n";
		for (int i = 0; i < listofcatches.size(); i++)
		{
			cout << phonelist[listofcatches.at(i)]<< "\n";
		}
	}
	
	cout << "\n";
	system("pause");
    return 0;
}

