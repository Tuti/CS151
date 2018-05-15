#pragma once

class AbstractSort
{
protected:

	int comparisons;

public:
	virtual void sort(int arr[], int size) = 0;
};

class BubbleSort : public AbstractSort
{
public:
	void sort(int arr[], int size) override;
};