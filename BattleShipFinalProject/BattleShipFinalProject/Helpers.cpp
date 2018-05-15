
#include "Helpers.h"
#include <string>
#include <iostream>

using namespace std;


//Class Definition of Ship
Ship::Ship()
{
	this->size = 0;
	this->alive = false;
}

Ship::Ship(int size, vector<string> mapLocation)
{
	this->size = size;
	this->mapLocation = mapLocation;
}

int Ship::getSize()
{
	return this->size;
}

vector<string> Ship::getMapLocation()
{
	return this->mapLocation;
}

bool Ship::isAlive()
{
	return this->alive;
}

void Ship::setSize(int size)
{
	this->size = size;
}
void Ship::setAlive(bool alive)
{
	this->alive = alive;
}

void Ship::setLocation(vector<string> maplocation)
{
	this->mapLocation = maplocation;
}

bool Ship::checkTile(string location)
{
	if (location.length() > 2)
	{
		return false;
	}

	for (int i = 0; i < mapLocation.size(); i++)
	{
		if (location == mapLocation.at(i))
		{
			return true;
		}
	}

	return false;
}

//Class Definition of Player

Player::Player() 
{
	this->playerName = "";
}

Player::Player(string playername)
{
	this->playerName = playername;
}

Player::Player(string playername, char friendlymap[10][10], char enemymap[10][10])
{
	this->playerName = playername;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			friendlyMap[i][j] = friendlymap[i][j];
			enemyMap[i][j] = enemymap[i][j];
		}
	}
}

string Player::getName()
{
	return this->playerName;
}

char* Player::getFriendlyMap()
{
	char **map = new char[][];
	return 
}