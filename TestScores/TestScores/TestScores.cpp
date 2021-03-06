/* 
	TestScores.cpp

	Algorithm: 
	Get amount of test scores from user
	Dynamically allocate an array of that size using a pointer
	Use a for loop to get input for the multiple test scores 
	Pass into function that puts array into ascending order
		Use bubble sort to put into ascending order
	Pass pointer and size of array into function that returns average
		Adds all values using for loop into one double value (sum)
		return sum / size
	Print scores to user and print average test score

	@author: Jose A Huerta <josehuerta115@gmail.com>
	@version: 1.0
*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//Prototypes
double getScore();
void ascendingOrder(double* someArray, int size);
double calcAverage(double* someArray, int size);


int main()
{
	int scores;
	cout << "Enter amount of scores: " << endl;
	cin >> scores;

	double *list = new double[scores];

	for (int i = 0; i < scores; i++)
	{
		list[i] = getScore() ;
	}

	ascendingOrder(list, scores);

	cout << "Ascending Tests Scores: " << endl;

	for (int i = 0; i < scores; i++)
	{
		cout << "Score[" << i << "]: " << *(list + i) << endl;
	}
	cout << "Average Test Score: " << calcAverage(list, scores) << endl;

	delete list;

	system("pause");
	return 0;
}

double getScore()
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

void ascendingOrder(double* someArray, int size)
{
	bool swapped;
	double temp;
	do
	{
		swapped = false;
		
		for (int i = 0; i < size - 1; i++)
		{
			if (*(someArray + i) > *(someArray + (i + 1)))
			{
				temp = *(someArray + i);
				*(someArray + i) = *(someArray + (i + 1));
				*(someArray + (i + 1)) = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

double calcAverage(double* someArray, int size)
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

