
#include <string>
#include <iostream>
#include "Grade.h"

using namespace std;

//Grade Class

Grade::Grade()
{
	//default
}

Grade::Grade(int score)
{
	this->score = score;
}

double Grade::getScore()
{
	return this->score;
}

void Grade::setScore(int score)
{
	this->score = score;
}
