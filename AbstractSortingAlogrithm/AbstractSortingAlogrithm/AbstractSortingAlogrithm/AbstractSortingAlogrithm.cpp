// AbstractSortingAlogrithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sort.h"

using namespace std;

void BubbleSort::sort(int arr[], int size)
{
	{
		bool swapped;
		int temp;

		do
		{
			swapped = false;
			for (int i = 0; i < size - 1; i++)
			{
				comparisons++;
				if (arr[i] > arr[i + 1])
				{
					temp = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = temp;
					swapped = true;
				}
			}
		} while (swapped);
	};
}

int main()
{
	BubbleSort x = BubbleSort();
	int y[] = { 5, 3, 1, 3, 2 };

	x.sort(y, 5);

	cout << "Array: ";
	for (int i = 0; i < 5; i++)
	{
		cout << y[i] << " ";
	}
	cout << "\n";

	system("pause");
	return 0;
}
