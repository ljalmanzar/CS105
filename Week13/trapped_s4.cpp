// Header Files
#include "formatted_console_io_v19.h"

// Global Constants
const char fileName[] = "scores.txt";
const int validInput = 1;
const int MAX_NAME_SIZE = 25;

// Function Prototypes
/*
Name: showSplashScreen
Process: shows title screen
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: title, and creators
Dependencies: formatted console
*/
void showSplashScreen ();
/*
Name: displayMenu
Process: shows main menu
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: the users choice
Device Input: none
Device Output/Monitor: the menu
Dependencies: formatted console
*/
char displayMenu ();
/*
Name: setDifficulty
Process: asks for the difficulty
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: the new difficulty
Device Input: none
Device Output/Monitor: difficulty menu
Dependencies: formatted console
*/
int setDifficulty ();
/*
Name: showTopScores
Process: shows the top scores
Function Input/parameters: the file name with the scores
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the table with top scores
Dependencies: formatted console/fstream
*/
void showTopScores (const char fileName []);
/*
Name: playGame
Process: asks for name and initiates the game interface
Function Input/parameters: the place where to store the name and game difficulty
Function Output/parameters: none
Function Output/Return: the score
Device Input: none
Device Output/Monitor: the game
Dependencies: formatted console
*/
int playGame (char nameArr[], int difficulty);
/*
Name: saveScore
Process: saves newest score into the file
Function Input/parameters: the filename, new name and score
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: fstream
*/
void saveScore (const char fileName [], char nameArr[], int score);

// Main Program
int main ()
   {
	char commandChar;
	int difficulty = 1;
	int score;
	char name[MAX_NAME_SIZE];
	
	// print splash screen
		// function : showSplashScreen
		showSplashScreen ();

	// show main menu 
		// show title 
			// function : displayMenu
		// show options
			// function : displayMenu
		// show selection line
			//function : displayMenu

		do
			{
			// get user input
				// get char
					// function displayMenu	
					displayMenu();
				// conditional
						// if D go to difficulty screen
						if ( commandChar == 'd' || commandChar == 'D')
							{
								// function : setDifficulty
								difficulty = setDifficulty();
							}

						// if P go to game 
						if ( commandChar == 'p' || commandChar == 'P')
							{
								// function : playGame
								score = playGame(name, difficulty);
								// save score
									// function : saveScore
									saveScore (fileName, name, score);
							}	
	
						// if S show scores	
						if ( commandChar == 's' || commandChar == 'S')
							{
								 // function : showTopScores
								showTopScores (fileName);
							}
			}
			while (commandChar != 'q' && commandChar != 'Q');

				// if Q end the program
						return 0;
	

	// end program
	
	}

// Function Implementation
void showSplashScreen ()
{
	// stub
}
char displayMenu ()
{
	return 0; // stub
}
int setDifficulty ()
{
	return 0; // stub 
}
void showTopScores (const char fileName [], char nameArr[], int score)
{
	// stub
}
int playGame (char nameArr[], int difficulty)
{
	return 0; // stub
}
void saveScore (const char fileName [], char nameArr[], int score)
{
	// stub
}
