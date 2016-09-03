// Header Files
#include "formatted_console_io_v19.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

// Global Constants
const char NULL_CHAR = '\n';
const char fileName[] = "scores.txt";
const int validInput = 1;
const int MAX_NAME_SIZE = 25;

const int numTopScores = 10;
const int tenthScore = 9;
const int newName = 11;

const char head = 'o';
const char heart = '|';
const char leg = 'v';
const char rightArm = '/';
const char leftArm = 92;
const char SPACE = ' ';
const int startX = SCRN_MAX_X / 2;
const int startY = SCRN_MAX_Y / 2;

const int KB_SPACE = 32;


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
int playGame (char monsterGrid [][SCRN_MAX_X], char nameArr[], int difficulty);
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
void saveScore (const char fileName [], char name [], int score);
/*
Name: setMoveCaps
Process: sets caps on xPos and yPos 
Function Input/Parameters: x and y position, x and y direction (int)
Function Output/Parameters: updated x and y direction
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: none
*/
void checkForWalls( int xPos, int yPos, int &xDir, int &yDir );

/*
Name: printObject
Process: prints object on screen
Function Input/Parameters: old and new x and y positions (int)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: object displayed
Dependencies: formatted console I/O tools
*/
void printPlayer( int oldX, int oldY, int newX, int newY );

void printMonsters (char monsterGrid [][SCRN_MAX_X], int oldX, int oldY, int difficulty);

bool checkForCollision (char monsterGrid [][SCRN_MAX_X], int xPos, int yPos);

// Main Program
int main ()
   {
	// variables
	char commandChar;
	int difficulty = 2;
	int score;
	char name [MAX_NAME_SIZE];
	char monsterGrid[24][79];
	
	// start
	startCurses();

	// print splash screen
		// function : showSplashScreen
		showSplashScreen ();

		do
			{
			// show main menu 
				// function displayMenu	
				commandChar = displayMenu();

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
								score = playGame(monsterGrid, name, difficulty);
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
	}

// Function Implementation
void showSplashScreen ()
{	
	// variables 

	// loop  
		// print title design line by line 
		// alternate colors
				setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );
				printStringAt( 40, 0, "TTTTTTTTTT   RRRRRR    AAAA   PPPPPP   PPPPPP   EEEEEEEE  DDDD", "CENTER" );
				printStringAt( 41, 1, "TTTTTTTTTT   RR   RR  AAAAAA  PP   PP  PP   PP  EE     E  DD  DD", "CENTER" );
				printStringAt( 42, 2, "    TT       RR   RR  AA  AA  PP   PP  PP   PP  EEEE      DD   DD", "CENTER" );
				
				setColor( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
				printStringAt( 42, 3, "    TT       RRRRRR   AAAAAA  PPPPPP   PPPPP    EEEE      DD   DD", "CENTER" );
				printStringAt( 41, 4, "    TT       RR RR    AA  AA  PP       PP       EE     E  DD  DD", "CENTER" );
				printStringAt( 40, 5, "    TT       RR  RR   AA  AA  PP       PP       EEEEEEEE  DDDD", "CENTER" );

	// print authors and command
	printStringAt( 40, 9, "By Luis Almanzar and Sashank Kandhadai", "CENTER");
	printStringAt( 40, 10, "Press Any Key To Continue ", "CENTER");
	
	waitForInput (FIXED_WAIT);
}

char displayMenu ()
{	
	// variables
	int input;
	
	// clear screen and add color
	setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
	clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

	setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

	// print menu 
	printStringAt(40,3,  "                                   ", "CENTER" );
	printStringAt(40,4,  "                                   ", "CENTER" );
	printStringAt(40,5,  "                                   ", "CENTER" );
	printStringAt(40, 6, "        MENU SELECTIONS            ", "CENTER" );
	printStringAt(40, 7, "        ---------------            ", "CENTER" );
	printStringAt(40,8,  "                                   ", "CENTER" );
	printStringAt(23, 9, "        1. Set <D>ifficulty        ", "LEFT" );
	printStringAt(23, 10,"        2. <P>lay Game             ", "LEFT" );
	printStringAt(23, 11,"        3. <S>how Top Scores       ", "LEFT");
	printStringAt(23,12, "        4. <Q>uit program          ", "LEFT" );
	printStringAt(40,13, "                                   ", "CENTER" );
	printStringAt(40,14, "                                   ", "CENTER" );
	printStringAt(40,15, "                                   ", "CENTER" );
	printStringAt(40,16, "                                   ", "CENTER" );
	printStringAt(40,17, "                                   ", "CENTER" );
	printStringAt(39,15, "Enter Selection: ", "CENTER");

	input = waitForInput (FIXED_WAIT);

	// return command
	return input; 	
}

int setDifficulty ()
{	
	// variables
	int difficulty;
	
	// set color and clear
	setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
	clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

	setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );


	// print commands
	printStringAt(40, 9, "                                                     ", "CENTER" );
	printStringAt(40, 10, "             Game Difficulty Entry Module            ", "CENTER" );
	printStringAt(40, 11, "                                                     ", "CENTER" );
	printStringAt(40, 12, "                                                     ", "CENTER" );
	//printStringAt(20, 12, " Enter Game Difficulty <1-3>: ", "LEFT" );
	printStringAt(40, 13, "                                                     ", "CENTER" );
	
	// get input and make sure it is valic
	while (difficulty != 1 && difficulty != 2 && difficulty != 3)
		{ 
			difficulty = promptForIntAt( 20, 12, " Enter Game Difficulty <1-3>: " );
		}

	return difficulty; // return difficulty
}

void showTopScores (const char fileName [])
{
	// variables 
	ifstream fin;
	int ndx;

	int ypos;
	int scoreArr [numTopScores];
	char nameArr [numTopScores][MAX_NAME_SIZE];
	int stringLen;

	// clear arrays
		while (ndx < numTopScores)
		{
			scoreArr [ndx] = 0;
			ndx ++;	
		}

/*	ndx = 0;
	while (ndx < 10) 
		{
			ndxTwo = 0;
			while (ndxTwo < 30)
				{
					nameArr [ndx][ndxTwo] = ' ';
					ndxTwo++;
				}

			ndx ++;
		} 
*/
	// set color and clear
	setColor( COLOR_WHITE, COLOR_BLUE, !SET_BRIGHT );
	clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

	// read in everything
	// open file 
	fin.clear();
	fin.open (fileName);
	
	ndx = 0;
	while (fin.good())
	{
	fin >> scoreArr[ndx];
	fin >> nameArr[ndx];
	stringLen = strlen (nameArr[ndx]);
	nameArr [ndx][stringLen+1] = NULL_CHAR;
	ndx++;
	}
	
	fin.close();


	// show score title
	printStringAt(40, 2, "TOP TEN WINNERS", "CENTER" );
	printStringAt(40, 3, "===============", "CENTER" );
	printStringAt(27, 5, "NAMES", "CENTER" );
	printStringAt(27, 6, "=====", "CENTER" );
	printStringAt(52, 5, "SCORES", "CENTER" );
	printStringAt(52, 6, "======", "CENTER" );
	// print scores
	ndx = 0;
	ypos = 8;
	while (scoreArr[ndx] != 0 && ndx < numTopScores)
		{
			printStringAt (27, ypos, nameArr[ndx], "LEFT");
			printIntAt (52, ypos, scoreArr [ndx], "RIGHT");
			ndx++;
			ypos++;
		}

	// command for exit
	setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
	printStringAt(40, 15, "                 Press any key to continue . . .           ", "CENTER" );
	waitForInput (FIXED_WAIT);
}

int playGame (char monsterGrid [][SCRN_MAX_X], char nameArr[], int difficulty)
{
	// initialize function
    int oldX, oldY; 
    int userInput; 
	int speed;
	bool monster;
	int ndx;
	int ndxTwo;
	int score;

	int timeCounter = 0;
	int time = 0;
	int moveCounter = 0;
	int s = 0;

    // set x, y positions
    int newX = startX;
    int newY = startY;

	// set speed for game
		if (difficulty == 1)
           {
			speed = 4;
	       }
		else if (difficulty == 2)
           {
			speed = 2;
	       }
		else
           {
			speed = 1;
	       }

	// clear monsters array
	ndx = 0;
	while( ndx < 24 )
		{
			ndxTwo = 0;
			while( ndxTwo < 80 )
				{
					monsterGrid[ndx][ndxTwo] = ' ';
					ndxTwo++;
				}
			ndx++;
		}

       // initialize direction setting - so object starts moving immediately
       int xVector = 1; 
       int yVector = 0;

	// ask for users name
	// set color and clear
	setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
	clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

	setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
	printStringAt (39, 9, "                                                 ", "CENTER");
	printStringAt (39, 10, "                                                 ", "CENTER");
	printStringAt (39, 12, "                                                 ", "CENTER");
	printStringAt (39, 13, "                                                 ", "CENTER");
	printStringAt (39, 11, "                                                 ", "CENTER");
	promptForStringAt (15, 11, " Enter your name: ", nameArr);




	// set color	
	setColor(COLOR_RED, COLOR_BLUE, SET_BRIGHT);
	clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

 

// show info and instruction screen

printStringAt(0,22,"================================================================================", "LEFT");	
printStringAt(0,23," Press Up or Down Arrow to Set Direction         Time on Board <seconds>: ", "LEFT");
printStringAt(0,24,"         Press Spacebar to pause", "LEFT");




    // start game loop
  	do
       {

	        // get an input key, time set by difficulty (previously)

           // function: waitForInput
		userInput = waitForInput (speed);
		
        // reset old x and y-positions
        oldX = newX;
        oldY = newY;

        // if user input, set direction, otherwise ignore
		if(userInput == KB_SPACE)
			{
				s = 0;
				while( userInput == KB_SPACE )
					{
						s++;
						waitForInput(10);
						
					}
			}
        switch( userInput )

           {
           // right arrow
            case KB_RIGHT_ARROW:

               // set vectors
               xVector = 1;
               yVector = 0;
               break;

           // left arrow
            case KB_LEFT_ARROW:

               // set vectors
				xVector = -1;
				yVector = 0;
               break;

           // up arrow
            case KB_UP_ARROW:
	
               // set vectors
               yVector = -1;
               xVector = 0;
               break;

           // down arrow
            case KB_DOWN_ARROW:

               // set vectors
               yVector = 1;
               xVector = 0;
               break;

           // escape key
            case KB_ESCAPE:

               // set vectors
               xVector = 0;
               yVector = 0;
               break;

           // default
           default:

              // set new x and y-positions
              newX = oldX + xVector;
              newY = oldY + yVector;

              // set caps on movement
                 // function: setMoveCaps
              checkForWalls( oldX, oldY, xVector, yVector );

              // check for monster
              monster = checkForCollision(monsterGrid, newX, newY);

			if (!monster)
				{
	              // print object at new location
	                 // function: printObject
	              printPlayer( oldX, oldY, newX, newY );

				}
	              break;
           }

		// Print more monsters	
		printMonsters(monsterGrid, oldX, oldY, difficulty);

		//display time
		timeCounter++;
	
		if( timeCounter % 4 == 0 )
			{
				time++;
				//printStringAt( 70, 22, "Time: ", "CENTER" );
				printIntAt( 74, 23, time, "CENTER" );
			}
		
		//display number of moves
		moveCounter++;
		printStringAt( 65, 24, "Number of Moves: ", "CENTER");
		printIntAt( 74, 24, moveCounter, "CENTER" );
	
		
       }

    while( userInput != KB_ESCAPE && !monster );
	
	setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
	printStringAt( 20, 24, "End Game-Press Any Key To Continue", "CENTER");


	// calculate score
	score = difficulty * moveCounter * (10 - time);
		// score = difficulty * moves * 10 - time 
	waitForInput (FIXED_WAIT);
	return score; // return score
	
}

void saveScore (const char fileName [], char name [], int score)
{
int scoreArr[10];
char nameArr[10][30];

int ndx = 0;
int ndxTwo = 0;
int checkerNdx = 0;
int columnNdx = 0;
int stringLen;

ifstream fin;
ofstream fout;

stringLen = strlen (name);
name[stringLen+1] = NULL_CHAR; 

	while (ndx < 10)
		{
			scoreArr [ndx] = 0;
			ndx ++;	
		}

	ndx = 0;
	while (ndx < 10) 
		{
			ndxTwo = 0;
			while (ndxTwo < 30)
				{
					nameArr [ndx][ndxTwo] = ' ';
					ndxTwo++;
				}

			ndx ++;
		} 
	nameArr[9][29] = NULL_CHAR;

fin.clear();
fin.open (fileName);

ndx = 0;
while (fin.good())
{
fin >> scoreArr[ndx];
fin >> nameArr[ndx];
stringLen = strlen (nameArr[ndx]);
nameArr [ndx][stringLen+1] = NULL_CHAR;
ndx++;
}

fin.close();

fout.open (fileName);
	ndx = 0;
	ndxTwo = 0;
	// compare score to all other scores and insert it into proper position
	if (scoreArr [9] == 0)
		{
			// find first available spot
			while (scoreArr [checkerNdx] != 0)
				{
					checkerNdx ++;
				}

			while (ndx < 10)
				{
					if ( score > scoreArr [ndx])
						{
							ndxTwo = checkerNdx;
							// move the scores accordingly
							while (ndxTwo > ndx )
								{
									scoreArr [ndxTwo] = scoreArr [ndxTwo - 1];
									ndxTwo --;
								}

							scoreArr [ndx] = score;
							
							// move the names in the array according to match with their scores
							ndxTwo = checkerNdx;
							while (ndxTwo > ndx )
								{
									columnNdx = 0;
									while (nameArr [ndxTwo-1][columnNdx] != NULL_CHAR)
										{
											nameArr [ndxTwo][columnNdx] = nameArr [ndxTwo-1][columnNdx];	
											columnNdx ++;
										}
		
									nameArr [ndxTwo-1][columnNdx] = NULL_CHAR;
									ndxTwo --;
								}
							// insert new name
							columnNdx = 0;
							nameArr[ndx][columnNdx]=',';
							columnNdx++;
							while (name [columnNdx-1] != NULL_CHAR)
								{
									nameArr [ndx][columnNdx] = name [columnNdx-1];
									columnNdx++;
								}
							name [columnNdx] = NULL_CHAR;

							// end search
							ndx = 10;
						}
					ndx ++;
				}

			ndx = 0;
			// insert everything into file
			while (scoreArr [ndx] != 0)
			{
			fout << scoreArr [ndx] << nameArr[ndx] << endl;
			ndx++;
			}
		}

	//prime
	ndx = 0;
	ndxTwo = 0;
	// compare score to all other scores and insert it into proper position
	if (scoreArr [9] != 0)
		{
			while (ndx < 10)
				{
					if ( score > scoreArr [ndx])
						{
							// move the scores accordingly
							ndxTwo = 10 - 1;
							while (ndxTwo > ndx )
								{
									scoreArr [ndxTwo] = scoreArr [ndxTwo - 1];
									ndxTwo --;
								}

							scoreArr [ndx] = score;
							
							// move the names in the array according to match with their scores
							ndxTwo = 10 - 1;
							while (ndxTwo > ndx )
								{
									columnNdx = 0;
									while (nameArr [ndxTwo-1][columnNdx] != NULL_CHAR)
										{
											nameArr [ndxTwo][columnNdx] = nameArr [ndxTwo-1][columnNdx];	
											columnNdx ++;
										}
		
									nameArr [ndxTwo-1][columnNdx] = NULL_CHAR;
									ndxTwo --;
								}
							// insert new name
							columnNdx = 0;
							nameArr[ndxTwo][columnNdx]=',';
							columnNdx++;
							while (name [columnNdx-1] != NULL_CHAR)
								{
									nameArr [ndxTwo][columnNdx] = name [columnNdx-1];
									columnNdx++;
								}
							name [columnNdx] = NULL_CHAR;

							// end search
							ndx = 10;
						}
						ndx ++;
				}

			ndx = 0;
			// insert everything into file
			while (ndx < 10)
			{
			fout << scoreArr [ndx] << nameArr[ndx] << endl;
			ndx++;
			}
		}



fout.close();

}

void checkForWalls( int xPos, int yPos, int &xDir, int &yDir )
   {
    // initialize function / variables
       // none

    // check for position past right side of screen
    if( xPos >= 77 && xDir == 1 )
       {
        // reset x direction to left-moving
        xDir = -1;
       }

    // check for position past left side of screen
    if( xPos <= 2 && xDir == -1)
       {
        // reset x direction to right-moving
        xDir = 1;
       }

    // check for position past bottom side of screen
    if( yPos >= 19 && yDir == 1 )
       {
        // reset y direction to up-moving
        yDir = -1;
       }

    // check for position past top side of screen
    if( yPos <= 2 && yDir == -1 )
       {
        // reset y direction to down-moving
        yDir = 1;
       }
   }

void printPlayer( int oldX, int oldY, int newX, int newY )
   {
    // initialize function / variables
       // none

    // set color
       // function: setColor
    setColor( COLOR_GREEN, COLOR_BLUE, SET_BRIGHT );

    // print space over the old object 
       // function: printCharAt
    printCharAt( oldX, oldY - 1, SPACE );
    printCharAt( oldX, oldY, SPACE );
    printCharAt( oldX - 1, oldY, SPACE );
    printCharAt( oldX + 1, oldY, SPACE );
    printCharAt( oldX, oldY + 1, SPACE );
    printCharAt( oldX - 1, oldY + 1, SPACE );
    printCharAt( oldX + 1, oldY + 1, SPACE );

    // print the object
       // function: printCharAt
    printCharAt( newX, newY - 1, head );
    printCharAt( newX, newY, heart );
    printCharAt( newX - 1, newY, rightArm );
    printCharAt( newX + 1, newY, leftArm );
    printCharAt( newX, newY + 1, leg );
    printCharAt( newX - 1, newY + 1, leg );
    printCharAt( newX + 1, newY + 1, leg );
   }

void printMonsters (char monsterGrid [][SCRN_MAX_X], int oldX, int oldY, int difficulty)
{
   int Xspot;
   int Yspot;
   setColor(COLOR_RED, COLOR_BLUE, true);

	// find random empty spot
	       	 Xspot = rand() % 75;
	       	 Yspot = rand() % 20;

	// print monster and save spot
       if( monsterGrid[Yspot][Xspot] != 'm' && monsterGrid[Yspot][Xspot+1] != 'm' && monsterGrid[Yspot+1][Xspot] != 'm' 
		&& monsterGrid[Yspot+1][Xspot+1] != 'm' && Xspot != oldX && Yspot != oldY)        

           {
               printCharAt( Xspot, Yspot, '#' );
               monsterGrid[Yspot][Xspot] = 'm';

               printCharAt( Xspot+1, Yspot, '#' );
               monsterGrid[Yspot][Xspot+1] = 'm';

               printCharAt( Xspot, Yspot+1, '#' );
               monsterGrid[Yspot+1][Xspot] = 'm';

               printCharAt( Xspot+1, Yspot+1, '#' );
               monsterGrid[Yspot+1][Xspot+1] = 'm';
           }

		if (difficulty == 3)
          {
			// find random empty spot
		       	 Xspot = rand() % 75;
		       	 Yspot = rand() % 20;

			// print monster and save spot
		       if( monsterGrid[Yspot][Xspot] != 'm' && monsterGrid[Yspot][Xspot+1] != 'm' && monsterGrid[Yspot+1][Xspot] != 'm' 
				&& monsterGrid[Yspot+1][Xspot+1] != 'm' && Xspot != oldX && Xspot+1 != oldX && Xspot+2 != oldX && Xspot+3 != oldX && Xspot-1 != oldX && Xspot-2 != oldX && 
			  Xspot-3 != oldX && Yspot != oldY && Yspot+1 != oldY && Yspot+2 != oldY && Yspot+3 != oldY && Yspot-1 != oldY && Yspot-2 != oldY && Yspot-3 != oldY )        
		
		           {
		
		               printCharAt( Xspot, Yspot, '#' );
		               monsterGrid[Yspot][Xspot] = 'm';
		
		               printCharAt( Xspot+1, Yspot, '#' );
		               monsterGrid[Yspot][Xspot+1] = 'm';
		
		               printCharAt( Xspot, Yspot+1, '#' );
		               monsterGrid[Yspot+1][Xspot] = 'm';
		
		               printCharAt( Xspot+1, Yspot+1, '#' );
		               monsterGrid[Yspot+1][Xspot+1] = 'm';
		           }
					
	      }
}

bool checkForCollision (char monsterGrid [][SCRN_MAX_X], int xPos, int yPos)
{
if( monsterGrid[yPos][xPos] == 'm')
{
return true;
}

if( monsterGrid[yPos-1][xPos] == 'm')
{
return true;
}
if( monsterGrid[yPos][xPos-1] == 'm' )
{
return true;
}
if( monsterGrid[yPos][xPos+1] == 'm' )
{
return true;
}
if( monsterGrid[yPos+1][xPos] == 'm' )
{
return true;
}
if( monsterGrid[yPos+1][xPos-1] == 'm' )
{
return true;
}
if( monsterGrid[yPos+1][xPos+1] == 'm' )
{
return true;
}
else
{
return false;
}

}
