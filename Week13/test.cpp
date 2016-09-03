// Header Files
#include <iostream>
#include <cstdlib>
#include "formatted_console_io_v19.h"
using namespace std;
// Global Constants

// Function Prototypes
void showSplashScreen ();

char displayMenu ();

int setDifficulty ();

void showTopScores (char fileName [], char nameArr[], int score);

int playGame (int difficulty, char nameArr[]);

void saveScore (char fileName [], char nameArr[], int score);

// Main Program
int main ()
   {
	int number = 100;
	
	while (number != 1)
		{
			void showSplashScreen();
			number --;
		}

system ("pause");
return 0;
	}

// Function Implementation
void showSplashScreen ()
{
	cout << " told ya so " << endl;
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
void showTopScores (char fileName [], char nameArr[], int score)
{
	// stub
}
int playGame (int difficulty, char nameArr[])
{
	return 0; // stub
}
void saveScore (char fileName [], char nameArr[], int score)
{
	// stub
}
