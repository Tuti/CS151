#pragma once
#include "stdafx.h"
#include <string>

class Pstring : public std::string
{
	std::string value;

public:
	Pstring(std::string arg);
	bool isPalindrome();
	bool isPalindrome(std::string arg);
};





