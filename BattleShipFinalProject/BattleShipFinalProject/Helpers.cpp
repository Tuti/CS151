

#include "stdafx.h"
#include "Helpers.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

void toUpperCase(string &input);
bool isCapitalLetterAlpha(char x);
bool isNumber(char x);


//Class Definition of Ship
Ship::Ship()
{
	this->size = 0;
}

Ship::Ship(const int size, const string &mapLocation)
{
	this->size = size;
	this->mapLocation = mapLocation;
}

int Ship::getSize() const
{
	return this->size;
}

string Ship::getMapLocation() const
{
	return this->mapLocation;
}

void Ship::setSize(const int size)
{
	this->size = size;
}

void Ship::setLocation(const string maplocation)
{
	this->mapLocation = maplocation;
}

//Class Definition of Player

Player::Player() 
{
	this->playerName = "";
	this->friendlyMap = new char*[10];
	this->enemyMap = new char*[10];
	 
	for (int i = 0; i < 10; i++)
	{
		this->friendlyMap[i] = new char[10];
		this->enemyMap[i] = new char[10];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->friendlyMap[i][j] = Game::WATER_TILE;
			this->enemyMap[i][j] = Game::WATER_TILE;
		}
	}
}

Player::Player(const string playername)
{
	this->playerName = playername;
	this->friendlyMap = new char*[10];
	this->enemyMap = new char*[10];

	for (int i = 0; i < 10; i++)
	{
		this->friendlyMap[i] = new char[10];
		this->enemyMap[i] = new char[10];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->friendlyMap[i][j] = Game::WATER_TILE;
			this->enemyMap[i][j] = Game::WATER_TILE;
		}
	}
}

Player::Player(const string playername, char **friendlyMap, char **enemyMap)
{
	this->playerName = playername;
	this->friendlyMap = friendlyMap;
	this->enemyMap = enemyMap;
}

inline void KillTutiArray(char **map)
{
	for (int i = 0; i < 10; i++)
	{
		delete map[i];
	}

	delete map;
}

Player::~Player()
{
	KillTutiArray(this->friendlyMap);
	KillTutiArray(this->enemyMap);
}

//Getters 
string Player::getName() const
{
	return this->playerName;
}

char** Player::getFriendlyMap() const
{
	return this->friendlyMap;
}

char** Player::getEnemyMap() const
{
	return this->enemyMap;
}

vector<Ship> Player::getBattleShipGroup() const
{
	return this->battleShipGroup;
}

//Setters 
void Player::setName(const string &name)
{
	this->playerName = name;
}

void Player::setFriendlyMap(char **map)
{
	this->friendlyMap = map;
}

void Player::setEnemyMap(char **map)
{
	this->enemyMap = map;
}

void Player::setBattleShipGroup(const vector<Ship> &battleshipgroup)
{
	this->battleShipGroup = battleshipgroup;
}

void Player::addShipToGroup(const Ship &ship)
{
	this->battleShipGroup.push_back(ship);
}

bool Player::isShipAlive(const Ship &ship) const
{
	char startPointY = ship.getMapLocation().at(0);
	char startPointX = ship.getMapLocation().at(1);
	char endPointY = ship.getMapLocation().at(2);
	char endPointX = ship.getMapLocation().at(3);

	int column = startPointX - 48;
	int row = startPointY - 65;
	char **map = getFriendlyMap();

	if (startPointX == endPointX)
	{
		for (int i = row; i < row + ship.getSize(); i++)
		{
			if (map[i][column] == Game::SHIP_TILE)
				return true;
		}
			
		return false;
	}

	else
	{
		for (int i = column; i < column + ship.getSize(); i++)
		{
			if (map[row][i] == Game::SHIP_TILE)
				return true;
		}

		return false;
	}
}

bool Player::isBattleGroupAlive() const
{
	bool alive = true;

	for (size_t i = 0; i < getBattleShipGroup().size(); i++)
	{
		alive = isShipAlive(getBattleShipGroup().at(i));
	}

	return alive;
}

//Class Defintion of Game
const int Game::shipSizes[] = { 5, 4, 3, 2, 2 };
const char Game::yAxis[] = { 'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J' };

Game::Game() 
{
	this->gameOver = false;
	this->player1Turn = false;
	this->turnCountTotal = 0;
}

Game::Game(const string &player1, const string &player2) :
	player1(player1),
	player2(player2)
{
	this->gameOver = false;
	this->player1Turn = true;
	this->turnCountTotal = 0;
}

Player &Game::getPlayer1()
{
	return this->player1;
}

Player &Game::getPlayer2()
{
	return this->player2;
}

void Game::setWinner(Player &p)
{
	this->winner = p;
}

void Game::printFriendlyMap(const Player &current)
{
	char **map = current.getFriendlyMap();
	cout << "		Friendly Waters\n       ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i << "  ";
	}
	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		cout << "(" << i << ") " << yAxis[i];
		for (int j = 0; j < 10; j++)
		{
			cout << " | ";

			cout << map[i][j];
		}

		cout << " | ";
		cout << '\n';
	}
}
void Game::printEnemyMap(const Player &current)
{
	cout << "		Enemy Waters\n       ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i << "  ";
	}
	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		cout << "(" << i << ") " << yAxis[i];
		for (int j = 0; j < 10; j++)
		{
			cout << " | ";
			cout << current.getEnemyMap()[i][j];
		}
		cout << " | ";
		cout << '\n';
	}
}

void Game::printBoard()
{
	if (player1Turn)
	{
		printEnemyMap(this->player1);
		printFriendlyMap(this->player1);

	}
	else
	{
		printEnemyMap(this->player2);
		printFriendlyMap(this->player2);
	}
}

bool Game::isValidFormat(string coordinate)
{
	if (coordinate.length() != 4)
	{
		cout << "Length is wrong" << endl;
		return false;
	}

	if (coordinate.find_first_not_of("ABCDEFGHIJ1234567890") != string::npos)
		return false;
	
	
	if (!isCapitalLetterAlpha(coordinate.at(0)) || !isCapitalLetterAlpha(coordinate.at(2)))
		return false;
	if (!isNumber(coordinate.at(1)) || !isNumber(coordinate.at(3)))
		return false;

	return true;
}

bool Game::isValidAttackFormat(string coordinate)
{
	if (coordinate.length() != 2)
	{
		cout << "Length is wrong" << endl;
		return false;
	}

	if (coordinate.find_first_not_of("ABCDEFGHIJ1234567890") != string::npos)
		return false;


	if (!isCapitalLetterAlpha(coordinate.at(0)))
		return false;
	if (!isNumber(coordinate.at(1)))
		return false;

	return true;
}

bool Game::isValidPlacement(char **map, string coordinate, int size)
{
	int row, column;
	char startPointY, startPointX, endPointY, endPointX;
	startPointY = coordinate.at(0);
	startPointX = coordinate.at(1);
	endPointY = coordinate.at(2);
	endPointX = coordinate.at(3);

	column = startPointX - 48;
	row = startPointY - 65;
	if ((abs(startPointY - endPointY) + 1) == size && startPointX == endPointX)
	{
		for (int i = row; i < row + size; i++)
		{
			if (map[i][column] == SHIP_TILE)
				return false;
		}

		for (int i = row; i < row + size; i++)
		{
			map[i][column] = SHIP_TILE;
		}

		return true;
	}

	else if ((abs(startPointX - endPointX) + 1) == size && startPointY == endPointY)
	{
		for (int i = column; i < column + size; i++)
		{
			if ( map[row][i] == SHIP_TILE)
				return false;
		}

		for (int i = column; i < column + size; i++)
		{
			map[row][i] = SHIP_TILE;
		}

		return true;
	}

	else 
		return false;
}

string Game::getCoordinatesFromUser(char **map, int size)
{
	string userinput;
	string example = "A1A4";
	cout << "Place ship of " << size << " size. Example: " << example << "\nCordinates: ";
	getline(cin, userinput);
	toUpperCase(userinput);

	try
	{
		if (!isValidFormat(userinput))
		{
			throw ImproperFormat();
		}

		if (!isValidPlacement(map, userinput, size))
		{
			throw InvalidPlacement();
		}
	}
	  
	catch (ImproperFormat&)
	{
		cout << "\nImproper format... try again.\n";
		userinput = getCoordinatesFromUser(map, size);
	}

	catch (InvalidPlacement&)
	{
		cout << "\nInvalid Placement... try again.\n";
		userinput = getCoordinatesFromUser(map, size);
	}

	return userinput;
}

Ship Game::placeShip(const Player &player, int size) //TODO complete implementing
{
	string coordinates;

	char **map = player.getFriendlyMap();
	coordinates = getCoordinatesFromUser(map, size); //does all validation of coordinate
	
	return Ship(size, coordinates);
}

void Game::placeAllShips(const Player &player)
{
	printFriendlyMap(player);
	for (int i = 0; i < Game::shipCount; i++)
	{
		Ship ship = placeShip(player, shipSizes[i]);
		player.getBattleShipGroup().push_back(ship);
		system("cls");
		printFriendlyMap(player);
	}
}

void Game::prep2PlayerGame()
{
	system("cls");
	cout << "Player 1, place your ships: \n\n";
	placeAllShips(player1);
	Sleep(1000);
	system("cls");

	cout << "Player 2, place your ships: ";
	placeAllShips(player2);

	cout << "Prep phase complete, action phase beginning.";
	Sleep(1000);
	system("cls");
}

string Game::attackCoordinate(const Player &current, const Player &enemy)
{
	string coordinate;
	char y, x;
	cout << "Enter coordinate to attack:";
	getline(cin, coordinate);
	toUpperCase(coordinate);

	try
	{
		while (!isValidAttackFormat(coordinate))
		{
			throw ImproperFormat();
			cout << "Enter coordinate to attack:";
			getline(cin, coordinate);
			toUpperCase(coordinate);
		}
	}
	
	catch (ImproperFormat&)
	{
		cout << "Improper formate of coordinate... try again.\n";
	}

	y = coordinate.at(0) - 65;
	x = coordinate.at(1) - 48;

	if (enemy.getFriendlyMap()[y][x] == SHIP_TILE)
	{
		enemy.getFriendlyMap()[y][x] = SHIP_TILE_HIT;
		current.getEnemyMap()[y][x] = SHIP_TILE_HIT;
		
		return "Successful shot! You have damaged an enemy ship!";
	}
	else
	{
		current.getEnemyMap()[y][x] = SHOT_MISSED_TILE;
		return "Unsuccesful shot! #!@$@!";
	}
}


void Game::playGame()
{
	string message;
	while (player1.isBattleGroupAlive() && player2.isBattleGroupAlive())
	{
		system("cls");
		player1Turn = true;
		cout << "Player 1 Turn:\n";
		Sleep(2000);
		system("cls");

		printBoard();
		message = attackCoordinate(player1, player2);
		system("cls");
		cout << message << "\n";
		printBoard();
		Sleep(2000);
		
		if (!player2.isBattleGroupAlive())
		{
			setWinner(player1);
			return;
		}

		system("cls");
		player1Turn = false; //end of turn
		cout << "Turn ended...";
		Sleep(2000);
		
		system("cls");
		cout << "Player 2 Turn:\n";
		Sleep(2000);

		printBoard();
		message = attackCoordinate(player1, player2);
		system("cls");
		cout << message << "\n";
		printBoard();
		Sleep(2000);

		if (!player1.isBattleGroupAlive())
		{
			setWinner(player2);
			return;
		}
	}

	Sleep(1000);
	system("cls");
	printWinner();
}

void Game::printWinner()
{
	if (player1.getName() == winner.getName())
	{
		cout << "Game over! Player 1 won!";
	}
	else
	{
		cout << "Game over! Player 2 won!";
	}
}

//Helpers
void toUpperCase(string &input)
{
	char hold;
	for (size_t i = 0; i < input.length(); i++)
	{
		hold = (char) toupper(input.at(i));
		if (hold != input.at(i))
			input.at(i) = hold;
	}
}
bool isCapitalLetterAlpha(char x)
{
	return (x >= 'A' && x <= 'Z');
}

bool isNumber(char x)
{
	return (x >= '0' && x <= '9');
}
