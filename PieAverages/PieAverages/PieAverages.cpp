// PieAverages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//Prototypes
int CalculateMode(int *someArray, int size);
bool BubbleSort(int *someArray, int size);

int main()
{
	int amount;

	cout << "Enter number of values: " << endl;
	cin >> amount;

	while (amount < 1)
	{
		cout << "Enter a valid number! " << endl;
		cin >> amount;
	}

	



	system("pause");
    return 0;
}

int CalculateMode(int *someArray, int size)
{
	if (someArray == NULL)
	{
		return -999;
	}

	BubbleSort(someArray, size);

	int currentMode = someArray[0];
	int possibleMode = 0;
	int counter1 = 0;
	int counter2 = 0;

	for (int i = 1; i < size-1; i++)
	{
		if (currentMode == someArray[i])
		{
			counter1++;
		}
		else if(possibleMode != someArray[i])
		{
			possibleMode = someArray[i];
			counter2 = 1;
		}
		else if (counter2 > counter1)
		{
			currentMode = possibleMode;
			possibleMode = 0;
			counter1 = counter2;
			counter2 = 0;
		}
		else {}
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