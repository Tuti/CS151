
#pragma once
#include "stdafx.h"
#include <string> 

class Numbers
{
	int num;
	std::string hundred = "hundred";
	std::string thousand = "thousand";
	std::string lessthan20[20];
	std::string tens[10];

public: 
	Numbers(int num);
	void FillLessThan20();
	void FillTens();
	std::string GetHundred();
	std::string GetThousand();
	std::string GetElementOfLessThan(int index);
	std::string GetElementOfTens(int index);
	std::string Print();
	int GetNum();
};
