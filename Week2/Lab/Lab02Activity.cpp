// Header Files
#include "formatted_cmdline_io_v10.h" // for I/O actions
    
using namespace std;

// Global Constant Definitions

const int NO_BLOCK_SIZE = 0; 

const int DECIMAL_PRECISION = 2;

// Global Function Prototypes

   // none

// Main Program Definition
int main()
   {
	
    // initialize program

       // variable initialization
int blockSize; 
blockSize = 10; 

	int intVal;

	double doubleVal;

    // prompt user for input
       // function: promptForInt, promptForDouble

	intVal = promptForInt( "Enter an integer value:" ); 
	doubleVal = promptForDouble( "Enter a double value:" );

    // output the responses
       // function: printString, printInt, printDouble

	printString("The integer value is: ", blockSize, "RIGHT");
	printInt (intVal, NO_BLOCK_SIZE, "LEFT");

	printString("The double value is: ", NO_BLOCK_SIZE, "LEFT");
	printDouble(doubleVal, DECIMAL_PRECISION, NO_BLOCK_SIZE, "LEFT");

    // Close program

       // hold program
          // function: system/pause

	system("pause");

       // return success
       return 0;
   }

// Supporting Function Implementation

   // none


