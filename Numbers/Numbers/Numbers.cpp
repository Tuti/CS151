
#include "stdafx.h"
#include <string>
#include "Numbers.h"

//Class Definition of Numbers 

Numbers::Numbers(int num)
{
	this->num = num;
	FillLessThan20();
	FillTens();
}

void Numbers::FillLessThan20()
{
	std::string temp[] = { "zero", "one", "two", "three", "four", "five", "six" , "seven", "eight", "nine", "ten",
		"eleven", "twelve" ,"thirteen", "fourteen" , "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	
	for (int i = 0; i < 20; i++)
	{
		this->lessthan20[i] = temp[i];
	}
}

void Numbers::FillTens()
{
	std::string temps[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	for (int i = 0; i < 8; i++)
	{
		this->tens[i] = temps[i];
	}
}

std::string Numbers::GetElementOfTens(int index)
{
	return this->tens[index];
}

std::string Numbers::GetElementOfLessThan(int index)
{
	return this->lessthan20[index];
}

std::string Numbers::GetHundred()
{
	return this->hundred;
}

std::string Numbers::GetThousand()
{
	return this->thousand;
}

int Numbers::GetNum()
{
	return this->num;
}

std::string Numbers::Print()
{
	std::string result = "";
	int thousands;
	int hundreds;
	int tens;
	int ones;
	int num = GetNum();
	//Checks if under twenty
	if (this->num < 20)
	{
		return GetElementOfLessThan(this->num);
	}

	thousands = num / 1000;
	hundreds = (num - (thousands * 1000)) / 100;
	tens = (num  - ((thousands * 1000) + (hundreds * 100)) ) / 10;
	ones = num - ( (thousands * 1000) + (hundreds * 100) + (tens * 10) );

	if (thousands > 0)
	{
		result += GetElementOfLessThan(thousands) + " ";
		result += GetThousand() + " ";
	}

	if (hundreds > 0)
	{
		result += GetElementOfLessThan(hundreds) + " ";
		result += GetHundred() + " ";
	}

	if (tens == 1)
	{
		int temp = 10 + ones;
		result += GetElementOfLessThan(temp) + " ";
	}
	else if(tens > 1)
	{
		result += GetElementOfTens(tens - 2) + " ";
		result += GetElementOfLessThan(ones) + " ";
	}
	else
	{
		result += GetElementOfLessThan(ones) + " ";
	}

	return result;
}








