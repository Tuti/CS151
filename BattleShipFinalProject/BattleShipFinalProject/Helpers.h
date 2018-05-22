#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Ship
{
	int size;
	string mapLocation;

public:
	Ship();
	Ship(const int size, const string &mapLocation);

	int getSize() const;
	string getMapLocation() const;

	void setSize(int size);
	void setLocation(string mapLocation);
};

class Player 
{
	string playerName;
	char **friendlyMap;
	char **enemyMap;
	int shipsAlive;
	vector<Ship> battleShipGroup; //might be redundant, check later
public: 	

	Player();
	Player(string playerName);
	Player(string playerName, char **friendlyMap, char **enemyMap);
	~Player();

	string getName() const;
	char** getFriendlyMap() const;
	char** getEnemyMap() const;
	vector<Ship> getBattleShipGroup() const;

	void setName(const string &name);
	void setFriendlyMap(char **map);
	void setEnemyMap(char **map);
	void setBattleShipGroup(const vector<Ship> &battleshipgroup);

	void addShipToGroup(const Ship &ship);
	bool isShipAlive(const Ship &ship) const;
	bool isBattleGroupAlive() const;
};


class Game
{
	bool gameOver;
	bool player1Turn;
	int turnCountTotal;

	Player player1;
	Player player2;
	Player winner;

public: 
	static const char WATER_TILE = ' ';
	static const char SHIP_TILE = '*';
	static const char SHIP_TILE_HIT = '!';
	static const char SHOT_HIT_TILE = 'X';
	static const char SHOT_MISSED_TILE = '0';
	static const char yAxis[];
	static const int shipSizes[];
	static const int shipCount = 5;

	Game();
	Game(const string &player1, const string &player2);

	Player &getPlayer1();
	Player &getPlayer2();

	void setWinner(Player &winner);

	void printBoard();
	void printFriendlyMap(const Player &current);
	void printEnemyMap(const Player &enemy);
	void placeAllShips(const Player &player);

	bool isValidFormat(string coordinate);
	bool isValidAttackFormat(string coordinate);
	bool isValidPlacement(char **map, string coordinate, int size);
	string getCoordinatesFromUser(char **map, int size);
	Ship placeShip(const Player &player, int size);

	void prep2PlayerGame();
	void playGame();
	string attackCoordinate(const Player &current, const Player &enemy);
	void printWinner();
};

class ImproperFormat
{};

class InvalidPlacement
{};
