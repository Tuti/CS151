#pragma once
#include <string>
#include <vector>
using namespace std;

class Ship
{
	int size;
	bool alive;
	vector<string> mapLocation;

public:
	Ship();
	Ship(int size, vector<string> mapLocation);

	int getSize();
	vector<string> getMapLocation();
	bool isAlive();

	void setSize(int size);
	void setAlive(bool alive);
	void setLocation(vector<string> mapLocation);
	
	bool checkTile(string location);
};

class Player 
{
	string playerName;
	char friendlyMap[10][10];
	char enemyMap[10][10];
	vector<Ship> battleShipGroup;
	
public: 
	Player();
	Player(string playerName);
	Player(string playerName, char friendlyMap[10][10], char FriendlyMap[10][10]);
	
	string getName();
	char* getFriendlyMap();
	char* getEnemyMap();
	vector<Ship> getBattleShipGroup();

	void setName(string name);
	void setFriendlyMap(char map[10][10]);
	void setEnemyMap(char map[10][10]);
	void setBattleShipGroup(vector<Ship> battleshipgroup);

	void printBoard();
	void printFriendlyMap();
	void printEnemyMap();

	void placeAllShips();
	Ship placeShip(int size);
	 

};


class Game
{
	bool gameOver;
	bool turn;
	int playerTurn;
	Player player1;
	Player player2;
	Player winner;

public: 

	Game();
};