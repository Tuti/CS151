#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Score
{
	string name;
	int score;

public: 
	Score();
	Score(string name, int score);
	string getName();
	int getScore();
	string toString();
};