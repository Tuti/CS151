#pragma once

#include "stdafx.h"

using namespace std;

class Grade
{
	double score;

public:
	Grade();
	Grade(int score);
	double getScore();
	void setScore(int score);
};