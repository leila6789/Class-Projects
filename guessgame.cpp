//cpp file for the guess game member function implementation

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
#include "guessgame.h"
using namespace std;

//member function definitions will go here
guessGame::guessGame()
{
	cout << "The default constructor has been called\n";
	//initialize all the member variables here
	guessTooLow = 0;
	guessTooHigh = 0;
	upper_range = 0;
	max_guesses = 0;
	current_guess = 0;
	random_number = 0;
}

//explicit value constuctor
guessGame::guessGame(int upper, int max)
{
	cout << "\nThe explicit-value constructor has been called\n";
	upper_range = upper;
	max_guesses = max;
	current_guess = 0;
	random_number = 0;
	guessTooLow = 0;
	guessTooHigh = 0;
}

void guessGame::SetUpperRange(int upper)
//Description:  sets the upper range for the random number generator. 
{
	//set the upper_range
	upper_range = upper;
}

void guessGame::SetNumGuesses(int numGuesses)
//Description:  Sets the number of guesses for the current round.
{
	//set the max_guesses
	max_guesses = numGuesses;
}

void guessGame::PlayOneRound(string& name)
//Description:  Play one round of the guess game
{
	guessTooLow = 0;
	guessTooHigh = 0;

	//max_guesses is a private member variabble
	cout << "\nYou will have " << max_guesses << " guesses, Good Luck!" << endl;

	GenerateRandomNumber();

	for (int i = 0; i < max_guesses; i++)
	{

		cout << "\nThis is guess number (" << i + 1 << ")";
		GetNextGuess();


		guessTooLow = 0;
		guessTooHigh = 0;
		if (InterpretGuess())

		{
			cout << "\nYou won that round, " << name << "!\n";
			i = max_guesses;
		}
	}
	cout << "\nTHE SOLUTION WAS " << random_number << endl;


}

void guessGame::GetNextGuess()
//Description:  get the next guess from the user
{
	if (guessTooLow)
	{
		cout << "\nEnter a guess above " << current_guess << " : ";
	}
	else if (guessTooHigh)
	{
		cout << "\nEnter a guess below " << current_guess << " : ";

	}
	else
	{
		cout << "\nEnter a guess between 1 and " << upper_range << " : ";
	}
	//get the guess from the user
	cin >> current_guess;
}

bool guessGame::InterpretGuess()
//Description:  Describe what the function does.
{
	if (current_guess > random_number)
	{
		cout << "\nYour guess was too high.";
		cout << "\n-----------------------";
		guessTooHigh = true;
		return false;
	}
	if (current_guess < random_number)
	{
		cout << "\nYour guess was too low.";
		cout << "\n-----------------------";
		guessTooLow = true;
		return false;
	}
	else return true;
	

}

void guessGame::GenerateRandomNumber()
//Precondition: user says yes to play a round of the game and chooses level
//Postcondition: solution will be made for the round
//Description:  comes up with solution for the round being played
{

	srand((unsigned)time(0));
	random_number = 1 + rand() % upper_range;
	//cout << "\nSolution is " << random_number << endl;

}
