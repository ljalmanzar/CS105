// Header files
#include <iostream>	// for console I/O
#include <cstdlib>

using namespace std;

// Global Constants
const char ASTERISK = '*';
const char SPACE = ' ';
const int END_OF_PROGRAM_LINES = 2;
const int ONE_END_LINE = 1;

// Global Function Prototypes
void printAsterisks( int numAsterisks );
void printSpaces( int numSpaces );
void printEndLines( int numEndLines );

// main function/program
int main()
   {
    // program initialization

       // variable initialization

    ////////////////////////////////////////////////////////////////////////////
    // Remove this comment block and place necessary code here
    ////////////////////////////////////////////////////////////////////////////

    // End program

       // make some vertical spaces
          // function: printEndLine
       printEndLines( END_OF_PROGRAM_LINES );

       // hold program
          // function: system/pause
       system( "pause" );

       // return success
       return 0;

   }  //  end of main function

// Supporting Function Implementations

void printAsterisks( int numAsterisks )
   {
    while( numAsterisks > 0 )
       {
        cout << ASTERISK;
        numAsterisks--;
       }
   }

void printSpaces( int numSpaces )
   {
    while( numSpaces > 0 )
       {
        cout << SPACE;
        numSpaces--;
       }
   }

void printEndLines( int numEndLines )
   {
    while( numEndLines > 0 )
       {
        cout << endl;
        numEndLines--;
       }
   }

