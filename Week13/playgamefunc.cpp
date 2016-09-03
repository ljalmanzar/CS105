#include "formatted_console_io_v19.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

const char head = 'o';
const char heart = '|';
const char leg = 'v';
const char rightArm = '/';
const char leftArm = 92;
const char SPACE = ' ';
const int startX = SCRN_MAX_X / 2;
const int startY = SCRN_MAX_Y / 2;

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
void setMoveCaps( int xPos, int yPos, int &xDir, int &yDir );

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
void printObject( int oldX, int oldY, int newX, int newY );

int main()
{
	// initialize function
	int ndxR = 0;
	int ndxC = 0;

	char gameGrid [21][80];

    // set x, y positions
    int newX = startX;
    int newY = startY;

       // initialize direction setting - so object starts moving immediately
       int xVector = 1; 
       int yVector = 0;

       // initialize other variables
       int oldX, oldY; 
       int userInput; 
       int difficulty = 3;

	// set color	
	startCurses ();
	setColor(COLOR_RED, COLOR_BLUE, SET_BRIGHT);
	clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

	// clear gameGrid 
	while (ndxR < 21) 
		{
			ndxC = 0;
			while (ndxC < 80)
				{
					gameGrid [ndxR][ndxC] = ' ';
					ndxC++;
				}

			ndxR ++;
		} 

/*
printCharAt(10, 10, '0');
printCharAt(9,11,'/');
printCharAt(10,11,'|');
printCharAt(12,11,'\');
printCharAt(9,12,'V');
printCharAt(10,12,'V');
printCharAt(11,12,'V');	
*/
 
// show info and instruction screen
printStringAt(0,22,"================================================================================", "LEFT");	
printStringAt(0,23," Press Up or Down Arrow to Set Direction         Time on Board <seconds>: 246 ", "LEFT");
printStringAt(0,24,"================================================================================", "LEFT");		

    // start game loop
  	do
       {
	        // get an input key, time set by difficulty (previously)
           // function: waitForInput
		userInput = waitForInput (difficulty);

        // reset old x and y-positions
        oldX = newX;
        oldY = newY;

        // if user input, set direction, otherwise ignore
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
              setMoveCaps( oldX, oldY, xVector, yVector );

              // print object at new location
                 // function: printObject
              printObject( oldX, oldY, newX, newY );
              break;
           }
       }
    while( userInput != KB_ESCAPE );

	//endCurses();

	waitForInput (FIXED_WAIT);
	return 0;
	
}



void setMoveCaps( int xPos, int yPos, int &xDir, int &yDir )
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

void printObject( int oldX, int oldY, int newX, int newY )
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
