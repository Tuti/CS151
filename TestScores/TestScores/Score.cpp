
#include "stdafx.h"
#include "score.h"
#include <string>
#include <sstream>

using namespace std;

//Class Score defintion
Score::Score()
{
	//default constructor
}

Score::Score(string name, int score)
{
	this->name = name;
	this->score = score;
}

string Score::getName()
{
	return this->name;
}

int Score::getScore()
{
	return this->score;
}

string Score::toString()
{
	stringstream ss;
	ss << "Name: " + this->name + " Score " + ' ' + to_string(this->score);
	
	return ss.str();
}

