//  Header Files
#include "formatted_console_io_V19.h" // for advanced console functions

//  Global Constants

    // object movement constants
    const int MAX_OBJ_X = 79;
    const int MAX_OBJ_Y = 23;

    const int TIME_LOC_X = 60;
    const int TIME_LOC_Y = SCRN_MAX_Y;
    const int CYCLES_PER_MINUTE = 4;
    const char PLUS_SIGN = '+';
    const char SPACE = ' ';

//  Function Prototypes

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

/*
Name: updateTime
Process: checks to see if enough cycles have happened to make one second,
         if so, updates time value and screen display
Function Input/Parameters: time counter (int), time (int)
Function Output/Parameters: updated time (int)
Function Output/Return: none
Device Input: none
Device Output/Monitor: time displayed, as specified
Dependencies: formatted console I/O tools
*/
void updateTime( int counter, int &time );

//  Main Function
int main()
   {
    // initialize program / function

       // initialize direction setting - so object starts moving immediately
       int xVector = 1, yVector = 0, time = 0, timeCounter = 0;

       // initialize other variables
       int newX, newY, oldX, oldY, userInput, waitTime = 2;

       // initialize curses
          // function: startCurses()
       startCurses();

       // set color, clear screen
          // function: setColor, clearScreen
		setColor( COLOR_GREEN, COLOR_BLUE, SET_BRIGHT );
		clearScreen( SCRN_MIN_X , SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // set x, y positions
    newX = SCRN_MAX_X / 2;
    newY = SCRN_MAX_Y / 2;

    // start game loop
    do
       {
        // get an input key, time set by difficulty (previously)
           // function: waitForInput
		userInput = waitForInput (waitTime);

        // increment time counter
        timeCounter++;

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
              setMoveCaps( oldX, oldY, newX, newY );

              // print object at new location
                 // function: printObject
              printObject( oldX, oldY, newX, newY );
              break;
           }

        // check for time update
        updateTime( timeCounter, time );
       }
    while( userInput != KB_ESCAPE );

    // shut down program

       // shut down curses 
          // function: endCurses
       endCurses();

       // return success
       return 0;
   }

//  Supporting Function Implementations

void setMoveCaps( int xPos, int yPos, int &xDir, int &yDir )
   {
    // initialize function / variables
       // none

    // check for position past right side of screen
    if( xPos >= MAX_OBJ_X && xDir == 1 )
       {
        // reset x direction to left-moving
        xDir = -1;
       }

    // check for position past left side of screen
    if( xPos <= SCRN_MIN_X && xDir == -1)
       {
        // reset x direction to right-moving
        xDir = 1;
       }

    // check for position past bottom side of screen
    if( yPos >= MAX_OBJ_Y && yDir == 1 )
       {
        // reset y direction to up-moving
        yDir = -1;
       }

    // check for position past top side of screen
    if( yPos <= SCRN_MIN_Y && yDir == -1 )
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
    printCharAt( oldX, oldY, SPACE );

    // print the object
       // function: printCharAt
    printCharAt( newX, newY, PLUS_SIGN );
   }

void updateTime( int counter, int &time )
   {
    // initialize function / variables
       // none

    // check for one second completed
    if( counter % CYCLES_PER_MINUTE == 0 )
       {
        // update time
        time++;

        // clear previous time
        printStringAt( TIME_LOC_X, TIME_LOC_Y, "Time:       ", "LEFT" );

        // show time
        printIntAt( TIME_LOC_X + 6, TIME_LOC_Y, time, "LEFT" );
       }
   }


