
/*


@author: Jose A Huerta <josehuerta115@gmail.com>
@version: 1.0
*/

#include "stdafx.h"
#include "score.h"
#include <string>
#include <iostream>

using namespace std;

//Prototypes
Score getScore();
void ascendingOrder(Score *someArray, int size);
double calcAverage(Score *someArray, int size);

int main()
{
	int scores;
	cout << "Enter amount of scores: " << endl;
	cin >> scores;

	Score *list = new Score[scores];

	for (int i = 0; i < scores; i++)
	{
		list[i] = getScore();
	}

	ascendingOrder(list, scores);

	cout << "Ascending Tests Scores: " << endl;

	for (int i = 0; i < scores; i++)
	{
		cout << "Score[" << i << "]: " << *(list + i)->toString << endl;
	}
	cout << "Average Test Score: " << calcAverage(list, scores) << endl;

	delete list;

	system("pause");
	return 0;
}

Score getScore()
{
	string name;
	int score;

	cout << "Enter name: " << endl;
	cin >> name;

	cout << "Enter score: " << endl;
	cin >> score;

	while (score < 0)
	{
		cout << "Enter a valid score: " << endl;
		cin >> score;
	}

	return Score(name, score);
}

void ascendingOrder(Score someArray[], int size)
{
	bool swapped;
	Score temp;

	do
	{
		swapped = false;

		for (int i = 0; i < size - 1; i++)
		{
			if (*(someArray + i)->getScore > *(someArray + i)->getScore)
			{
				temp = *(someArray + i);
				*(someArray + i) = *(someArray + (i + 1));
				*(someArray + (i + 1)) = temp;
				swapped = true;
			}
		}

	} while (swapped);
}

double calcAverage(Score *someArray, int size)
{
	double sum = 0;
	double average = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(someArray + i)->getScore;
	}
	average = sum / size;

	return average;
}
