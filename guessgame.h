
//header file for guessgame
#ifndef GUESSGAME_H
#define GUESSGAME_H

#include<iostream>
using namespace std;

class guessGame
{
public:
	//constructor
	guessGame();

	//explicit value constructor
	//pass the upper range and the max guesses
	guessGame(int, int);

	//the mutator functions are still used by the NON member function
	//SetUpLevel
	void SetUpperRange(int); //sets the upper range for the round
	void SetNumGuesses(int);//sets the number of guesses for the round
	void PlayOneRound(string& name);//plays one round of the game




private:
	//three member functions are now private
	//since PlayOneRound is now member function
	void GetNextGuess(); //gets the next guess from the user
	bool InterpretGuess(); //determines if the guess is right or wrong
	void GenerateRandomNumber(); //generates the solution

	bool guessTooLow;
	bool guessTooHigh;
	int upper_range;
	int max_guesses;
	int current_guess;
	int random_number;
};

#endif GUESSGAME_H