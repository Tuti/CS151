
/*


@author: Jose A Huerta <josehuerta115@gmail.com>
@version: 1.0
*/

#include "stdafx.h"
#include "score.h"
#include <string>
#include <iostream>
#include <sstream>

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
	cin.ignore(100, '\n');

	Score *list = new Score[scores];

	for (int i = 0; i < scores; i++)
	{
		list[i] = getScore();
	}

	ascendingOrder(list, scores);

	cout << "\nAscending Tests Scores: " << endl;

	for (int i = 0; i < scores; i++)
	{
		cout << "Score[" << i << "]: " << list[i].toString() << endl;
	}
	cout << "\nAverage Test Score: " << calcAverage(list, scores) << endl;

	delete list;

	system("pause");
	return 0;
}

Score getScore()
{
	char *input = new char[100];
	string name, temp;
	int score, index;
	

	cout << "Enter name-score pairs: " << endl;
	cin.getline(input, 100);

	temp = string(input);
	index = temp.find_first_of(' ');
	name = temp.substr(0, index);
	score = stoi(temp.substr(index), nullptr, 10);

	cout << "\n";

	return Score(name, score);
}

void ascendingOrder(Score *someArray, int size)
{
	bool swapped;
	Score temp;

	do
	{
		swapped = false;

		for (int i = 0; i < size - 1; i++)
		{
			if (someArray[i].getScore() > someArray[i + 1].getScore())
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
		sum += someArray[i].getScore();
	}
	average = sum / size;

	return average;
}
