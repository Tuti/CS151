

/*
	Algorithm: 

	Take in user amount of values
	Get values from user
	Save values into array
	Make mode calculator

*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//Prototypes
int CalculateMode(int *someArray, int size);
bool BubbleSort(int *someArray, int size);
void getValues(int *someArray, int size);

int main()
{
	int amount;

	cout << "Enter number of values:\n";
	cin >> amount;
	cout << "\n";

	while (amount < 1)
	{
		cout << "Enter a valid number! " << endl;
		cin >> amount;
	}

	int *someArray = new int[amount];

	getValues(someArray, amount);
	cout << "Pie Mode: " << CalculateMode(someArray, amount) << endl;
	system("pause");
    return 0;
}

int CalculateMode(int someArray[], int size)
{
	if (someArray == NULL)
	{
		return -999;
	}

	BubbleSort(someArray, size);

	int mode = someArray[0];
	int possibleMode = 0;
	int counter1 = 1;
	int counter2 = 0;

	for (int i = 1; i < size-1; i++)
	{
		if (mode == someArray[i])
		{
			counter1++;
		}
		else if (possibleMode == someArray[i])
		{
			counter2++;

			if (counter2 > counter1)
			{
				mode = possibleMode;
				possibleMode = 0;
				counter1 = counter2;
				counter2 = 0;
			}
		}
		
		else if (possibleMode != someArray[i])
		{
			possibleMode = someArray[i];
			counter2 = 1;
		}
		else 
		{

		}
	}

	return mode;
}

void getValues(int *someArray, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter a value: " << endl;
		cin >> temp;
		someArray[i] = temp;
	}
}

bool BubbleSort(int *someArray, int size)
{
	//Ascending order
	bool swapped;
	int temp;

	do
	{
		swapped = false;

		for(int i = 0; i < size - 1; i++)
		{
			if (someArray[i] > someArray[i + 1])
			{
				temp = someArray[i];
				someArray[i] = someArray[i + 1]; 
				someArray[i + 1] = temp;
				swapped = false;
			}
		}

	} while (swapped);

	return true;
}