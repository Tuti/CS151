
/*
	Algorithm: 
	
	START
	Take in user choice
		Depending on choice, exit program or begin 2 player game 
	IF 2 player game
		Create Game object and take in names of both players
		Create 2 player objects with names and initiliaze all variables 
		Player 1 places ships in 2d char array
			take in a string that designates the location of each ship
				Check string if it passes format
				Check string length != 4
				Check string for characters not on board eg ' ' or * 
			Check if string location is avaliable on map
				IF yes
					fill tiles with ship and add to ship container
			Continue until 5 ships are added to player battleshipgroup
		Same is repeated for player2, player 2 adds all ships 

	Game begins
		Player 1 is first
		Print board of enemy map and friendly map contained by player1
		wait for user input to give a tile location
		check if input location is valid
		if valid, check enemy map to see if a ship tile is there
		IF yes, 
			change tile to destroyed, update player1 that shot has hit an enemy ship
		IF no,
			return missed shot message to user
		Check if player 2 still has remaining ships
		IF yes, 
			player 2 turn 
		IF no, 
			declare winner, exit game
		Print winner details and exit game
	END
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

#include "Helpers.h"
using namespace std;

static int shipSizes[] = { 5, 4, 3, 2, 2};
static char yAxis[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

//prototype
void Menu();

int main()
{
	Menu();
	
	system("pause");
    return 0;
}



void Menu() 
{
	int choice;
	cout << "BattleShip\n";
	cout << "1. 2 Player mode.\n";
	cout << "2. Exit.\n";

	cin >> choice;
	cin.ignore();
	if (choice == 1) 
	{
		string name1, name2;
		cout << "Enter player 1 name: ";
		getline(cin, name1);

		cout << "Enter player 2 name: ";
		getline(cin, name2);

		Game game = Game(name1, name2);
		game.prep2PlayerGame();
		game.playGame();
	}
}
