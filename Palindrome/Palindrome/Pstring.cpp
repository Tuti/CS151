

#include "stdafx.h"
#include <string>
#include "Pstring.h"
//Class Definition

Pstring::Pstring(std::string arg)
{
	this->value = arg;
}

bool Pstring::isPalindrome()
{
	isPalindrome(this->value);
}

bool Pstring::isPalindrome(std::string arg)
{
	if (arg.size() == 1 || arg.size() == 0)
	{
		return true;
	}

	else if (arg.at(0) == arg.at(arg.size() - 1))
	{
		return isPalindrome(arg.substr(1, arg.size() - 2));
	}
	else
	{
		return false;
	}
	
}
