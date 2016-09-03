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

int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int h = 8;
int i = 9;
int j = 10;
int k = 11;
int l = 12;
int m = 13;
int n = 14;

// main function/program
int main()
   {
    // program initialization

       // variable initialization

// ouput line 1
printAsterisks(n);
printEndLines(a);

// ouput line 2
printAsterisks(n);
printEndLines(a);

// ouput line 3
printAsterisks(d);
printSpaces(h);
printAsterisks(b);
printEndLines(a);

// ouput line 4
printAsterisks(c);
printSpaces(h);
printAsterisks(c);
printEndLines(a);

// ouput line 5
printAsterisks(b);
printSpaces(h);
printAsterisks(d);
printEndLines(a);

// ouput line 6
printAsterisks(n);
printEndLines(a);

// ouput line 7
printAsterisks(n);
printEndLines(a);



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

