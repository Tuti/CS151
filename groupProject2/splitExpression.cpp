
/*
	Algorithm: 

	START

	Ask user for input (expression to parse)
	Create parsing function "split"
		A wrapper for recursive function that takes in string expression
		passes string expression, vector <string>, and int index into recursive function
		parses values into vector and concatenates values if they are numbers
		Once it hits base case, return vector
	Set vector equal to return value of split
	Print vector values to user
	
	END

	@author: Madison Cuppett, Jose Huerta, Charlie Nguyen, Ryan Smith, Victor Lopez
	@version: 1.0

*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//Prototypes
vector <string> split(const string expression);
vector <string> split(const string expression, vector <string> splitVector, int index);

int main()
{
	string expression;
	cout << "Enter math expression to parse: " << endl;
	cin >> expression;

	vector<string> myVec;
	myVec = split(expression);

	cout << endl << "Forward: " << endl;
	
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}

	cout << endl << "Backward: " << endl;
	
	for (int i = myVec.size() - 1; i >= 0; i--)
	{
		cout << myVec[i] << endl;
	}

	system("pause");
	return 0;
}

//Functions
vector <string> split(const string expression)
{
	int index = 0;
	vector<string> splitVector;
	return split(expression, splitVector, index);
}

vector <string> split(const string expression, vector <string> splitVector, int index)
{
	if (expression.empty())
	{
		return splitVector;
	}

	else if (expression.at(0) >= '0' && expression.at(0) <= '9')
	{
		string concat;
		if (index != 0)
		{
			concat = splitVector[index - 1];
		}

		if (concat.at(0) >= '0' && concat.at(0) <= '9')
		{
			concat = concat.append(1, expression.at(0));
			splitVector[index - 1] = concat;
		}
		else
		{
			string temp;
			temp = temp.append(1, expression.at(0));
			splitVector.push_back(temp);
			index++;
		}
		
		return split(expression.substr(1), splitVector, index);
	}

	else
	{
		string temp;
		temp = temp.append(1, expression.at(0));
		splitVector.push_back(temp);
		index++;
		return split(expression.substr(1), splitVector, index);
	}
}