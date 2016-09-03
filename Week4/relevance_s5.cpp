// Header Files 
#include "formatted_cmdline_io_v10.h"
#include <cmath>
#include <cstdlib>

// Global Constants 
	
const int NO_BLOCK_SIZE = 0;
const int END_ONE_LINE = 1;
const int END_TWO_LINES = 2;

// Function Prototypes 
 
/*
name: printTitle
process: displays the title with equal sign underline
input parameters: none
output parameters: none
returned value: none
device input: none
device output: program title (string)
dependencies: formatted file
*/

void printTitle( );

/*
name: calcCapAtRelevanceFreq
process: calculates capacitance
input parameters: Frequency and inductance
output parameters: none
returned value: the capacitance (double)
device input: none
device output: none
dependencies: formatted file
*/
double calcCapAtRelevanceFreq( double systFrq , double inductance );

/*
name: displayResultHeader
process: displays the title and underline for the result output 
input parameters: none
output parameters: none
returned value: nothing
device input: none 
device output: the calculation header (string)
dependencies: cmath
*/
void displayResultHeader();

/*
name: printResultString
process: displays the system name inputted 
input parameters: none
output parameters: none
returned value: nothing
device input: none 
device output: system name line and input value (string)
dependencies: formatted file
*/
void printResultString();

/*
name: printResultData
process: shows the input system frequency and inducance and the calculated data
input parameters: capacitanceOne, capacitanceTwo, capacitanceThree (double)
output parameters: none
returned value: none
device input: none
device output: the capacitance (string and double)
dependencies: formatted file
*/
void printResultData( double systFrq, double inductance, double capacitanceOne, double capacitanceTwo, double capacitanceThree  );

// Main Function 
int main()
   {
	// initialize program

		// show title
			// function: displayTitle
		printTitle ();

		// declare variables

    // get inputs from the user

		// get System Name
			// function: none

		// get Frequency
			// function: getInputs

		// get Inductance
			// function: getInputs

    // calculate the capacitance
		// function: calcCap

	/* THIS IS ALL WITHIN THE FUNCTION
		// calculate the 'angle' of cos
			// function: calcCap

		// calculate the denominator
			// function: calcCap

		// calculate the absolute value of the reciprocal of the denominator
			// function: calcCap 
	*/

			
    // display the results

		// display title 'calculation results'
		void displayResultHeader();

		// display System Name
		void printResultString();

		// display System Frequency
		void printResultData(double systFrq);

		// display System Inductance
		void printResultData(double inductance);

		// display calculated capacitance at 1/2 Frequency
		void printResultData(double capacitanceTwo);

		// display calculated capacitance at Frequency
		void printResultData(double capacitanceOne);

		// display calculated capacitance at 2 * Frequency
		void printResultData(double capacitanceThree);

    // shut down the program
	
		// hold program for user
		system ("pause");

       // return success 
       return 0;
   }

// Supporting Function Implementation

void printTitle( const string )
   {
	    // initialize function/variables

    // display the title
       // function: formatted file
		printString ("RL Relevance Capacitance Calculation Program", NO_BLOCK_SIZE, "LEFT");
		printEndLines (END_ONE_LINE);
			
    // display the underline
       // function: formatted file
		printString ("============================================", NO_BLOCK_SIZE, "LEFT");

    // make vertical space
       // function: formatted file
		printEndLines (END_TWO_LINES);

   }

double getInputs()
   {
	    // initialize function/variables

    // prompt the user for coefficient
       // function: formatted file

    // get the coefficient from the user
       // function: formatted file

    // return the coefficient back to calling function
	
   return 0; // stub
   }

double calcCapAtRelevanceFreq( double capacitanceOne, double capacitanceTwo, double capacitanceThree );
   {
	// calculate the 'angle' of cos
			// function : cmath

	// calculate the denominators
			// function : cmath

	// calculate the absolute value of the reciprocal of the denominators 
			// function : cmath
	
   return 0; // stub
   }

void displayResultHeader();
   {
	
	// display result header

	// display equal signs below

	// created endlines
	
   }

void printResultData( double capacitanceOne, double capacitanceTwo, double capacitanceThree  );
   {
	
	// show systm frequency

	// show systm inductance

	// show capacitance at half the frequency

	// show capacitance at the frequency

	// show capacitance at two times the frequency
	

   }




