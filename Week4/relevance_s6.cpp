// Header Files 
#include "formatted_cmdline_io_v10.h"
#include <cmath>
#include <cstdlib>

// Global Constants 
	
const int NO_BLOCK_SIZE = 0;
const int END_ONE_LINE = 1;
const int END_TWO_LINES = 2;

const int TWO_DECIMAL_SPOTS = 2;
const int FOUR_DECIMAL_SPOTS = 4;

// Function Prototypes 

/*Design Changes
Removed "getInput" function due to the fact that we have not learned how to return multiple things.
Edited prototypes because I got a better understanding of the parameters and process after reading the text.
Changed names of variables for more consistency and better readability. 
*/
 
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
input parameters: system frequency (double)
output parameters: none
returned value: nothing
device input: none 
device output: system name line and input value (string)
dependencies: formatted file
*/
void printResultString(const string &systName);

/*
name: printResultData
process: shows the input system frequency and inducance and the calculated data
input parameters: system frq, inductance, capacitanceOne, capacitanceTwo, capacitanceThree (double)
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
		string systName;
		double systFrq;
		double inductance;
		double capacitance, halfFrqCapacitance, twoTimesFrqCapacitance;	

    // get inputs from the user

		// get System Name
			// function: none
			systName = promptForString ("Enter system name                       : "); 
			printEndLines (END_TWO_LINES);

		// get Frequency
			// function: none
			systFrq = promptForDouble ("Enter frequency of system       <Hertz> : ");
			printEndLines (END_TWO_LINES);
			

		// get Inductance
			// function: none
			inductance = promptForDouble ("Enter inductance of system     <Henrys> : ");
			printEndLines (END_TWO_LINES);

	// End Input phase
		// print string
		printString ("End of data input," , NO_BLOCK_SIZE, "LEFT");
		printEndLines (END_ONE_LINE);

		system ("pause");
		printEndLines (END_ONE_LINE);

    // calculate the capacitance
		// function: calcCap
		capacitance = calcCapAtRelevanceFreq( systFrq , inductance );

		halfFrqCapacitance = calcCapAtRelevanceFreq( (systFrq / 2) , inductance );

		twoTimesFrqCapacitance = calcCapAtRelevanceFreq( (systFrq * 2) , inductance );

			
    // display the results

		// display title 'calculation results'
		displayResultHeader();

		// display result details
		printResultData( systFrq, inductance, halfFrqCapacitance, capacitance, twoTimesFrqCapacitance  );
		
    // shut down the program
	
		// hold program for user
		system ("pause");

       // return success 
       return 0;
   }

// Supporting Function Implementation

void printTitle()
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

double calcCapAtRelevanceFreq( double systFrq , double inductance )
   {
	double angle, denom, result;
	double Pi = 3.14159265359;
	// calculate the 'angle' of cos
		// function : cmath
		angle = 4 * (pow (Pi,2)) * (pow (systFrq,2)) * inductance;	

	// calculate the denominator
		// function : cmath
		denom = cos (angle);

	// calculate the absolute value of the reciprocal of the denominators 
		// function : cmath
		result = abs (1/denom);
	
   return result; 
   }

void displayResultHeader()
   {
	// display result header
	printString ("Calculation Results", NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_ONE_LINE);

	// display equal signs below
	printString ("===================", NO_BLOCK_SIZE, "LEFT");

	// create endlines
	printEndLines (END_TWO_LINES);	
   }

void printResultString(const string &systName)
   {		
	printString ("System Name                                        : ", NO_BLOCK_SIZE, "LEFT");
	printString (systName, NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_ONE_LINE);
   }

void printResultData( double systFrq, double inductance, double halfFrqCapacitance, double capacitance, double twoTimesFrqCapacitance  )
   {
	// show systm frequency
	printString ("System Frequency                           <Hertz> : ", NO_BLOCK_SIZE, "LEFT");
	printDouble (systFrq, TWO_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_ONE_LINE);

	// show systm inductance
	printString ("System Inductance                         <Henrys> : ", NO_BLOCK_SIZE, "LEFT");
	printDouble (inductance, TWO_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_ONE_LINE);

	// show capacitance at half the frequency
	printString ("Capacitance at half system frequency      <Farads> : ", NO_BLOCK_SIZE, "LEFT");
	printDouble (halfFrqCapacitance, FOUR_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_ONE_LINE);

	// show capacitance at the frequency
	printString ("Capacitance at system frequency           <Farads> : ", NO_BLOCK_SIZE, "LEFT");
	printDouble (capacitance, FOUR_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_ONE_LINE);

	// show capacitance at two times the frequency
	printString ("Capacitance at twice system frequency     <Farads> : ", NO_BLOCK_SIZE, "LEFT");
	printDouble (twoTimesFrqCapacitance, FOUR_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
	printEndLines (END_TWO_LINES);
	
   }




