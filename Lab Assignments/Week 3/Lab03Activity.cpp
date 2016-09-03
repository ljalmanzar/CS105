// Header Files
#include "formatted_cmdline_io_v10.h" // for I/O actions
   
using namespace std;

// Global Constant Definitions

const char PIPE = '|';
const int NO_BLOCK_SIZE = 0;
const int ONE_END_LINE = 1;
const int TWO_END_LINES = 2;
const int DECIMAL_PRECISION = 2;
const int INSIDE_NAME_BLOCK_SIZE = 19;
const int INSIDE_AGE_BLOCK_SIZE = 9;
const int INSIDE_GPA_BLOCK_SIZE = 8;

// Global Function Prototypes

   // none

// Main Program Definition
int main()
   {
    // initialize program

       // variable initialization

		string nameOne = "Susan H. Jones", nameTwo = "Ralph A. Smith";
		int ageOne = 24, ageTwo = 22;
		double gpaOne = 3.515, gpaTwo = 3.243;

    // output the table

       // make vertical lines
          // function: printEndLines
			printEndLines (TWO_END_LINES);

       // display the header
          // function: printString, printEndLines
			printString( " |----------------------------------------|", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );
			printString( " | Student Information |", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );
			printString( " |--------------------|---------|---------|", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );
			printString( " | Name | Age | GPA |", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );
			printString( " |--------------------|---------|---------|", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );

       // display data line one
          // function: printString, printChar, printEndLines
			printString( " | ", NO_BLOCK_SIZE, "LEFT" );
			printString( nameOne, INSIDE_NAME_BLOCK_SIZE, "LEFT" );
			printChar( PIPE );
			printInt( ageOne, INSIDE_AGE_BLOCK_SIZE, "CENTER" );
			printChar( PIPE );
			printDouble( gpaOne, DECIMAL_PRECISION, INSIDE_GPA_BLOCK_SIZE, "RIGHT" ); 
			printString( " |", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );
    
       // display data line two
          // function: printString, printChar, printEndLines
			printString( " | ", NO_BLOCK_SIZE, "LEFT" );
			printString( nameTwo, INSIDE_NAME_BLOCK_SIZE, "LEFT" );
			printChar( PIPE );
			printInt( ageTwo, INSIDE_AGE_BLOCK_SIZE, "CENTER" );
			printChar( PIPE );
			printDouble( gpaTwo, DECIMAL_PRECISION, INSIDE_GPA_BLOCK_SIZE, "RIGHT" ); 
			printString( " |", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( ONE_END_LINE );

       // display table bottom line
          // function: printString, printEndLines
			printString( " |----------------------------------------|", NO_BLOCK_SIZE, "LEFT" );
			printEndLines( TWO_END_LINES );
   
    // Close program

       // hold program
          // function: system/pause
system ("pause");

       // return success
       return 0;
   }

// Supporting Function Implementation

   // none


