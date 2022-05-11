/*
Leila Diab
Due Date: 05/05/2020
Course:  C0P3014
Assignment:  Program 11
Professor: Sorgente

Description:
number guessing game with a random number generator with 
separate compilation files to store game results.

*************************************************************/
/* This is the main function that will use the guess game object
The guess game class is in separate files:
	guessgame.h - header file interface to the guessgame class
	guessgame.cpp - implementation of the guessgame member functions
*/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
#include "guessgame.h"//interface to the guessgame class
using namespace std;

//HERE IS THE main function

int main()
{
	string yesOrNo = "y";
	guessGame activeGame;
	int numGames = 0;

	//ask the user if they want to play  ";
	cout << "Would you like to play the guessing game? (y or n): ";
	cin >> yesOrNo;

	while (yesOrNo == "y" || yesOrNo == "Y")
	{
		//playOneRound
		activeGame.PlayOneRound();
		numGames++;
		activeGame.SetCount(numGames);//keep track of the number of games
		cout << "Do you want to play another round? (y or n):  ";
		cin >> yesOrNo;
	}
	//print the game results
	activeGame.PrintGameResults();
	return  0;
}

