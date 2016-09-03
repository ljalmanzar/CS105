// Header Files 
#include "formatted_cmdline_io_v10.h"
#include <cmath>
#include <cstdlib>

// Global Constants 

   // none

// Function Prototypes 
 
/*
name: printTitle
process: displays the title with equal sign underline
input parameters: none
output parameters: none
returned value: none
device input: none
device output: program title (string)
dependencies: 
*/

void printTitle( const string );

/*
name: getInputs
process: prompts for the System Frequency and Inductance
input parameters: systFrq and inductance
output parameters: none
returned value: systFrq and inductance
device input: none
device output: none
dependencies: 
*/
double getInputs();

/*
name: calcCapAtRelevanceFreq
process: calculates capacitance
input parameters: Frequency and inductance
output parameters: none
returned value: the capacitance (double)
device input: none
device output: none
dependencies: 
*/
double calcCapAtRelevanceFreq( double systFrq , double halfSystFrq, double twiceSystFrq );

/*
name: displayResultHeader
process: displays the title and underline for the result output 
input parameters: none
output parameters: none
returned value: nothing
device input: none 
device output: the calculation header (string)
dependencies: 
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
dependencies: 
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
dependencies: 
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
		double systFrq, inductance, capacitanceOne, capacitanceTwo, capacitanceThree; 

    // get inputs from the user

		// get System Name
			// function: none

		// get Frequency
			// function: getInputs
		systFrq = getInputs ("Enter system frequency: ")

		// get Inductance
			// function: getInputs
		inductance = getInputs ("Enter system inductance: ")

    // calculate the capacitance
		// function: calcCap
	capacitanceOne = calcCapAtRelevanceFreq(double systFrq);
	capacitanceTwo = calcCapAtRelevanceFreq(double halfSystFrq);
	capacitanceThree = calcCapAtRelevanceFreq(double twiceSystFrq);

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
	
   }

double getInputs()
   {
	
   return 0; // stub
   }

double calcCapAtRelevanceFreq( double capacitanceOne, double capacitanceTwo, double capacitanceThree );
   {
	
   return 0; // stub
   }

void displayResultHeader();
   {
	
   }

void printResultData( double capacitanceOne, double capacitanceTwo, double capacitanceThree  );
   {
	

   }




