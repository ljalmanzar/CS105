//Header Files	
#include "formatted_cmdline_io_v10.h"
#include <cstdlib>
#include <cmath>
 
//Global Constants
const int NO_BLOCK_SIZE = 0;
const int END_ONE_LINE = 1;
const int END_TWO_LINES = 2;

const int TWO_DECIMAL_SPOTS = 2;
const int FOUR_DECIMAL_SPOTS = 4;

//Function Prototype
	// none
							
//Main Program
int main() 
{
	// create function
		// title
			// function: printString, printEndLines
			printString ("RL Relevance Capacitance Calculation Program", NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);
			printString ("============================================", NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_TWO_LINES);

		// define variables
			// string system name
			string SYSTNAME;
			// double fr
			double SYSTFRQ; 
			// double halfFr
			double halfSYSTFRQ;
			// double twoFr
			double twiceSYSTFRQ;
			// double L
			double INDUCTANCE;

	// Receive inputs from user
		// Ask for inputs
			// Receive System Name
				// function: propmtForString
				SYSTNAME = promptForString ("Enter system name                       : "); 
				printEndLines (END_TWO_LINES);

			// Receive Fr 
				// function: promptForDouble
				SYSTFRQ = promptForDouble ("Enter frequency of system       <Hertz> : ");
				printEndLines (END_TWO_LINES);
				
				halfSYSTFRQ = SYSTFRQ / 2;

				twiceSYSTFRQ = SYSTFRQ * 2;

			// Receive L
				// function: promptForDouble
				INDUCTANCE = promptForDouble ("Enter inductance of system     <Henrys> : ");
				printEndLines (END_TWO_LINES);
					
				printString ("End of data input," , NO_BLOCK_SIZE, "LEFT");
				printEndLines (END_ONE_LINE);
				system("pause");
				printEndLines (END_ONE_LINE);

	// calculate outputs
	double ANGLE_HALF; 
	double ANGLE_SYST; 
	double ANGLE_TWICE; 
	double DENOMINATOR_HALF; 
	double DENOMINATOR_SYST; 
	double DENOMINATOR_TWICE;
	double CAPACITANCE_HALF;
	double CAPACITANCE_SYST;
	double CAPACITANCE_TWICE; 
	double Pi = 3.14159265359;
		// calculate the 'angle' of cos with inputs Fr, 1/2 Fr, and 2 Fr
			// function : cmath
			ANGLE_HALF = 4 * (pow (Pi,2)) * (pow (halfSYSTFRQ,2)) * INDUCTANCE;
			ANGLE_SYST = 4 * (pow (Pi,2)) * (pow (SYSTFRQ,2)) * INDUCTANCE;
			ANGLE_TWICE = 4 * (pow (Pi,2)) * (pow (twiceSYSTFRQ,2)) * INDUCTANCE;

		// calculate the denominators with inputs Fr, 1/2 Fr, and 2 Fr
			// function : cmath 
			DENOMINATOR_HALF = cos (ANGLE_HALF);
			DENOMINATOR_SYST = cos (ANGLE_SYST);
			DENOMINATOR_TWICE = cos (ANGLE_TWICE);

		// calculate the absolute value of the reciprocal of the denominators 
			// function : cmath
			CAPACITANCE_HALF = abs (1/DENOMINATOR_HALF);
			CAPACITANCE_SYST = abs (1/DENOMINATOR_SYST);
			CAPACITANCE_TWICE = abs (1/DENOMINATOR_TWICE);
				
	// display outputs
		// display title 'calculation results'
			// function : printString, printEndLines
			printString ("Calculation Results", NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);
			printString ("===================", NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_TWO_LINES);
		// display System Name
			// function : printString, printEndLines
			printString ("System Name                                        : ", NO_BLOCK_SIZE, "LEFT");
			printString (SYSTNAME, NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);

		// display System Frequency
			// function : printString, printEndLines
			printString ("System Frequency                           <Hertz> : ", NO_BLOCK_SIZE, "LEFT");
			printDouble (SYSTFRQ, TWO_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);

		// display System Inductance
			// function : printString, printEndLines
			printString ("System Inductance                         <Henrys> : ", NO_BLOCK_SIZE, "LEFT");
			printDouble (INDUCTANCE, TWO_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);

		// display calculated capacitance at 1/2 Frequency
			// function : printString, printEndLines
			printString ("Capacitance at half system frequency      <Farads> : ", NO_BLOCK_SIZE, "LEFT");
			printDouble (CAPACITANCE_HALF, FOUR_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);

		// display calculated capacitance at Frequency
			// function : printString, printEndLines
			printString ("Capacitance at system frequency           <Farads> : ", NO_BLOCK_SIZE, "LEFT");
			printDouble (CAPACITANCE_SYST, FOUR_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_ONE_LINE);

		// display calculated capacitance at 2 * Frequency
			// function : printString, printEndLines
			printString ("Capacitance at twice system frequency     <Farads> : ", NO_BLOCK_SIZE, "LEFT");
			printDouble (CAPACITANCE_TWICE, FOUR_DECIMAL_SPOTS, NO_BLOCK_SIZE, "LEFT");
			printEndLines (END_TWO_LINES);

	// end program
		// hold program for user
			//system/pause

		system("pause");
		// return success

	return 0;	
}
//Function Implementaion
	// none
 
