/***********************************************************
Leila Diab
Due Date: 04/6/20
Course:  C0P3014
Assignment:  Program 7
Professor: Sorgente

Description: hangman game

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <fstream> //file input/ output
#include <cstdlib> //for exit()

using namespace std;

const int numGuesses = 6;//six guesses (head, body, arm1, arm2, leg1, leg2

/*********************************************************
//Following is the declaration of a round of the hangman game
**********************************************************/
class hangmanGame
{
public:
	string solution=""; //solution word
	string wordGuess=""; //if the user guesses a correct letter they can guess the word
	char starWord[20]="";//hint word made of *
	char letters[20]="";//letters guessed so far (right or wrong)
	int letterCount=0;//number of letters guessed so far (right or wrong)
	int incorrectCount=0;//number of incorrect letters guessed so far
	char letterGuess=' ';//current letter guess
	int wordLength=0;//length of the solution word
	bool correctLetter=0;//OPTIONAL
	bool win=0;//flag to set if all the user won that round
};


//Declaration/ Prototypes for your functions will go here

void HangmanRules(const string&);
//Precondition: user enters name 
//Postcondition: rules of hangman game will come up after entering name
//Description:  provides instructions to the user on how to play the game

void PlayOneRound(const string&, hangmanGame&, ifstream&);
//Precondition: user says yes to play a round of hangman
//Postcondition: one round of game is played
//Description:  Play one round of the game

void SetUpOneRound(hangmanGame&, ifstream&);
//Precondition: one round is already played
//Postcondition: all functions of game will be reset for the user to replay. 
//Description:  resets and sets up the member variables for the current round

string GetWord(ifstream&);
//Precondition: one round of game is already played, user says yes to play another round
//Postcondition: next word from file will be picked.
//Description: Gets the next word from the file

void SetWord(hangmanGame&, const string&);
//Precondition: user says yes to play one round of game
//Postcondition: solution will be set up for the current round
//Description: sets the solution word for the current round

void SetWordLength(hangmanGame&);
//Precondition: solution is set for round.
//Postcondition: the word length of the solution will be counted
//Description:  Sets the length of the solution word for the current round

void CreateStarArray(hangmanGame&);
//Precondition: solution is set and count for solution is made
//Postcondition: star array will be created so user can see what the word is with the letter count
//Description:  creates the array of *

void GetLetterGuess(hangmanGame&);
//Precondition: solution set for round, count is made, star array is set, guess is made by user
//Postcondition: star array is displayed for user to see, also shows what letters were guessed by user
//Description:  Displays star array and letters guessed and asks and get a current 
//letter guess

void UpdateLetterArray(hangmanGame&);
//Precondition: guess is made by user
//Postcondition: letter is added into an array for user to see
//Description:  Add the letter guessed to the letters array

bool InterpretLetterGuess(hangmanGame&);
//Precondition: letter guessed by user is correct
//Postcondition: replace the * with the correct letter 
//Description:  Check if the letter guessed is in the solution and if it is, replace all * with that 
//letter in the starword and return true, otherwise return false

void CorrectGuess(hangmanGame&, string name);
//Precondition: letter guessed is the final letter to guess
//Postcondition: if not the final letter, the user gets prompted if they want to guess the word
//Description:  checks if it is the final correct letter and if it is not asks if the 
//user wants to guess the word

void GuessTheWord(hangmanGame&);
//Precondition: user says yes to guess the word
//Postcondition: user guesses answer
//Description:  allows the user to guess the word

bool GameOver(const hangmanGame&);
//Precondition: word entered by user
//Postcondition: if the starword matches the solution, it returns true
//Description:  Returns true if the starword matches the solution, you can use ==  
//or if the wordGuess matches the solution, you can use ==

void WonOrLostDisplay(const hangmanGame&, string name);
//Precondition: user guesses a word, or finishes guessing letters
//Postcondition: displays to user if they won or lost 
//Description: Lets the user know if they won or lost the round

void DrawHangman(hangmanGame&);
// I did not do this, but i still did the pre and post condition. 
//Precondition: letter is guessed or word is guessed
//Postcondition: draws body parts or tells user the body parts drawn.
//Description:  Draw or describe the hangman drawing


//HERE IS THE main function, a driver to test your program

int main()
{
	//declare variables
	string name;
	string yesOrNo;
	//name, y or n, file, hangman game object 
	ifstream in;

	//connect to the input file 
	in.open("words.txt");
	//if //file did not open correctly
	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}
	
	//ask and get the users name
	cout << "Welcome to hangman! Enter your name: ";
	cin >> name;
	//Hangman rules
	HangmanRules(name);
	hangmanGame activeGame;
	
		//ask and get yes or no if the user wants to play
	cout <<"\n"<<  name << ", Do you want to play hangman? (y or n) ";
	cin >> yesOrNo;
	while (yesOrNo == "y"|| yesOrNo == "Y")//loop to contiue to play another round
	{

		//play one round of hangman
		PlayOneRound(name, activeGame, in);
		//again?
		cout << name << ", Do you want to play again? (y or n) ";
		cin >> yesOrNo;
	}
	in.close();
	return  0;
}
void HangmanRules(const string& name) {
	cout << "\n" << name << ", here are the rules!";
	cout << "\n-You will be presented with a word.\n-Guess letters one at a time.";
	cout << "\n-You are only allowed to have six incorrect answers.\n-You can only guess the";
	cout << "word when you have the correct letter guess";
	cout << "\n-The game will be over when you guess the right word or when you guess incorrect letters six times.\n";
	cout << "-Have fun!! :)";
}

void PlayOneRound(const string& name, hangmanGame& activeGame, ifstream& in)
//Description:  Play one round of the game
{
	//reset everything for the new round of the game
	//SetUpOneRound function
	SetUpOneRound(activeGame, in);

	//LOOP FOR THE ROUND OF THE GAME
	while (activeGame.win == false && activeGame.incorrectCount< numGuesses) 
	//the number of incorrect guesses is less than numGuesses
	//and win is false
	{
		//GetLetterGuess 
		GetLetterGuess(activeGame);
		//UpdateLetterArray - add the letter to the array of guessed letters
		UpdateLetterArray(activeGame);
		if (InterpretLetterGuess(activeGame))
		{
			//the user guessed a correct letter
			cout << "\ncorrect letter!";
			//the user can now guess the word (if they want)
			CorrectGuess(activeGame, name);
		}
		else
		{
			//the user did not guess a correct letter
			cout << "\nincorrect letter :( try again\n";
		activeGame.incorrectCount++;
		}
		//DrawHangman (tell the user how many incorrect guesses so far)
	}

	//WonOrLostDisplay - lets the user know if they won or lost
	WonOrLostDisplay(activeGame, name);
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

void SetUpOneRound(hangmanGame& activeGame, ifstream& in)
//Description:  resets and sets up the member variables for the current round
{
	activeGame.solution = "";//clear the solution word
	//clear the guessed word
	activeGame.starWord[0] = '\0'; //clear the star array  
	//clear the letters guessed array
	activeGame.letterCount = 0; //letter count starts back at 0
	//reset the number of incorrect guesses
	activeGame.correctLetter = false; //reset correctLetter to false
	//reset win to false
	activeGame.win = false;
	activeGame.incorrectCount = 0;
	activeGame.letters[0] = '\0';

	string word;
	//get a word form the file, GetWord function will return a string
	word = GetWord(in);
	//add the word to the active game, SetWord 
	SetWord(activeGame, word);
	//get the length of the word, SetWordLength 
	SetWordLength(activeGame);
	//CreateStarArray 
	CreateStarArray(activeGame);
	cout <<"here is the star word:" << activeGame.starWord<< endl;
}

//SET UP FUNCTION
string GetWord(ifstream& inFile)
//Description: Gets the next word from the file
{
	string word = "";
	//get, and return a word(string) from the file

	inFile >> word;
	cout << "\nThe solution is " << word;
	return word;
}

//SET UP FUNCTION
void SetWord(hangmanGame& activeGame, const string& word)
//Description: sets the solution word for the current round
{
	//assign the word to the active game
	activeGame.solution= word;
	cout << "\nWord is " << activeGame.solution;
}

//SET UP FUNCTION
void SetWordLength(hangmanGame& activeGame)
//Description:  Sets the length of the solution word for the current round
{
	//get the length of the word and assign it to activeGame.wordLength
	activeGame.wordLength = activeGame.solution.length();
	//let the user know how many letters are the word
	cout << "\nThe word has " << activeGame.wordLength << " letters."<< endl;
}

//SET UP FUNCTION
void CreateStarArray(hangmanGame& activeGame)
//Description:  creates the array of * 
{
	//use  loop to assign '*' to each character in the activeGame.starWord
	//remember to add '\0' to the end of the starword
	//activeGame.wordLength should have the number of letters in the word
	for (int i = 0; i < activeGame.wordLength; i++) {
		activeGame.starWord[i] = '*';
}
	activeGame.starWord[activeGame.wordLength] = '\0';
}


void GetLetterGuess(hangmanGame& activeGame)
//Description:  Display the star array and the letters guessed so far
//and ask and get a current letter guess
{
	//display the star array
	cout << "Guess the word: " << activeGame.starWord << endl << endl;
	//display the letters that have been guessed so far
	cout << "Letters " << activeGame.letters<<  endl << endl ;
	//ask and get a letter guess from the user
	cout << "\nEnter a letter guess: ";
	cin>> activeGame.letterGuess;
}

void UpdateLetterArray(hangmanGame& activeGame)
//Description:  Add the letter guessed to the letters array
{
	activeGame.letters[activeGame.letterCount] = activeGame.letterGuess;
	//update the letterCount
	//add the '\0' character
	activeGame.letterCount++;
	activeGame.letters[activeGame.letterCount] = '\0';
}

bool InterpretLetterGuess(hangmanGame& activeGame)
//Description:  Check if the letter guessed is in the
//word and if it is, replace all * with that letter in the starword
//and return true otherwise return false
{
	bool rv = false;
	//use a loop to search the solution word
	for (int i = 0; i < activeGame.wordLength; i++) {
//if the letter is found
		if (activeGame.letterGuess == activeGame.solution[i])
			//replace the letters in the starword and 
		{
			activeGame.starWord[i] = activeGame.letterGuess;
			rv = true;

		}
			//set the rv to true
	}
	return rv;

}

void CorrectGuess(hangmanGame& activeGame, string name)
//Description:  checks if it is the final correct letter and if it is not
//ask if the user wants to guess the word
{
	char guess;
	cout << "\n-----------------------------------------";
	//display the starword
	if (GameOver(activeGame)) //the correct letter completed the starword	
	{
		activeGame.win = true;//they won the round by entering all the letters
	}
	else //the user entered a correct letter but it was not the final correct letter
	{
		//ask and get a response (y or n) if they want to guess the word
		cout << "Do you want to guess the word?";
		cout << "Note: It does not count if you do not want to!Enter a y or n: ";
		cin >> guess;
		if (guess == 'y')
		{
			//GuessTheWord function
			GuessTheWord(activeGame);
		}
	}
}

void GuessTheWord(hangmanGame& activeGame)
//Description:  allows the user to guess the word
{
	cout << "\nWhat is the word: ";
	cin >> activeGame.wordGuess;
	if (GameOver(activeGame))
	{
		activeGame.win = true;
	}
	else
	{
		cout << "\nTHAT WAS NOT THE CORRECT WORD!\n";
	}
}

bool GameOver(const hangmanGame& activeGame)
//Description:  This function will return true if the 
//starword matches the solution, you can use ==  or if the 
//wordGuess matches the solution, you can use ==
{
	if (activeGame.solution == activeGame.wordGuess)
		return true;
	else if (activeGame.solution == activeGame.starWord)
		return true;
	else 
		return false;
}

void WonOrLostDisplay(const hangmanGame& activeGame, string name)
//Description: Lets the user know if they won or lost the round
{
	cout << "\n-----------------------------------------";
	cout << "\n-----------------------------------------";
	if (activeGame.win)
	{
		//tell the user they won that round
		cout << "\nYou won, " << name << "!";
	}
	else
	{
		//tell the user they did not win that round
		cout << "\nYou lost, " << name << ".";
		//display the solution word
		cout << "The solution was: " << activeGame.solution;
	}
}

void DrawHangman(hangmanGame& activeGame)
//Description:  Draw or describe the hangman drawing
{
	cout << "\n------------------------------------------------------";
	cout << "\nO-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<";
	cout << "\n------------------------------------------------------";
	if (activeGame.incorrectCount == 0)
	{

		cout << "\nYou have no incorrect guesses yet! O-|--<";
	}
	else if (activeGame.incorrectCount == 1)
	{

		cout << "\nHEAD\n - 1 of 6 incorrect guesses!";
	}

}

