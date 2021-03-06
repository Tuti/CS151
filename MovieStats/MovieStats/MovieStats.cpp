// MovieStats.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int CalculateMode(int *someArray, int size);
void CalculateStats(int *someArray, int size);
double CalculateAverage(int *someArray, int size);
int CalculateMode(int *someArray, int size);
bool BubbleSort(int *someArray, int size);
int getScore();
int GetMedian(int *someArray, int size);

int main()
{
	int size;
	cout << "Enter amount of students surveyed:\n";
	cin >> size;

	while (size < 1)
	{
		cout << "Enter a valid amount of students!\n";
		cin >> size;
	}

	int *students = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(students + i) = getScore();
	}

	cout << "\n";
	CalculateStats(students, size);

	system("pause");
    return 0;
}

void CalculateStats(int *someArray, int size)
{
	double average = CalculateAverage(someArray, size);
	int median = GetMedian(someArray, size);
	int mode = CalculateMode(someArray, size);

	cout << "Movie stats:\nAverage Watched: " << average << "\nMedian: " << median << "\nMode: " << mode << "\n";
}
double CalculateAverage(int *someArray, int size)
{
	double sum = 0;
	double average = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(someArray + i);
	}
	average = sum / size;

	return average;
}

int GetMedian(int *someArray, int size)
{
	int index = size / 2;
	BubbleSort(someArray, size);

	if (size % 2 != 0)
	{
		return (someArray[index] + someArray[index] / 2.00);
	}
	else
	{
		return someArray[index];
	}
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

	for (int i = 1; i < size - 1; i++)
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
bool BubbleSort(int *someArray, int size)
{
	//Ascending order
	bool swapped;
	int temp;

	do
	{
		swapped = false;

		for (int i = 0; i < size - 1; i++)
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

int getScore()
{
	int score;
	cout << "Enter score: " << endl;
	cin >> score;

	if (score < 0)
	{
		cout << "Error! Enter a valid score! Must not be a negative value." << endl;
		score = getScore();
	}

	return score;
}