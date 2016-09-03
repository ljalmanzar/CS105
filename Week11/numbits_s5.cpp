// Header Files 
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

// Global Constants
const int MAX_VALUE = 100000;

// Function Prototypes
void showTitle ();

void getStuff (int &numToCheck, int &bitsToCheck, string &fileName);

int storeNumbers (int decArr [], int numToCheck);

void changeToBinary (int decArr [], int biArr [], int arrSize);

int findBits (int biArr [], int ndxArr [], int bitsToCheck, int arrSize);

void outPutToFile (int &numToCheck, 
					int &bitsToCheck, 
					const string &fileName, 
					int ndxArr [], 
					int arrSize);

// Main Program
int main ()
   {
	// Initialize
		int mainVal;
		int numBits;
		string fileName;
		int arrSize;
		int ndxArrSize;
		int decimalArr [MAX_VALUE];
		int binaryArr [MAX_VALUE];
		int outputNdxArr [MAX_VALUE];

		
		// show title
			// function : showTitle
				void showTitle();

	// Get All Values and files

		// get number to be tested
			//function :getStuff

		// get number of bits to test for
			//function :getStuff

		// get output file name
			//function :getStuff
				getStuff (mainVal, numBits, fileName);


	// Convert number to binary and insert 1 to num in array
		// get numbers
			// function : storeNumbers
				arrSize = storeNumbers (decimalArr, mainVal);

		// convert the numbers
			// function : changeToBinary
				changeToBinary (decimalArr, binaryArr, arrSize);

	// Check number for given bits and compare
		// function : findBits
			ndxArrSize = findBits (binaryArr, outputNdxArr, numBits, arrSize);

	// Output results to file
		// function : outPutToFile
			outPutToFile (mainVal, 
					numBits, 
					fileName, 
					outputNdxArr, 
					ndxArrSize);

	// End
	
   }

// Function Implementation

void showTitle ()
   {
	// print title
   }

void getStuff (int &numToCheck, int &bitsToCheck, string &fileName)
   {
	// ask for numbers and cin value
	
	// ask for bits and cin value

	// ask for file to output to and cin
   }
int storeNumbers (int decArr [], int numToCheck)
   {
	// variables 

	/* make loop that enters 1 to ndx 0, 2 to ndx 1.... and so on until the the 
	numToCheck is inserted  */

	return 0;
   }
void changeToBinary (int decArr [], int biArr [], int arrSize)
   {
	// variables 

	// while loop

		// get value from array
	
		// convert to binary

		// put back into array

		// increment ndx

   }
int findBits (int biArr [], int ndxArr [], int bitsToCheck, int arrSize)
   {
	// variables 

	// check number 
		// while loop
			// get int from arr

			// get sum the digits of the integer

			 // if the sum is the same as "bitsToCheck" in next available index
			// ALSO store index that 'good' number was found at in the ndxARR

	// return highest available index
	return 0;
   }
void outPutToFile (int &numToCheck, 
					int &bitsToCheck, 
					const string &fileName, 
					int ndxArr [], 
					int arrSize)
   {
	// variables

	// fout main sentence

	// fout values found

		/* Go through my decimal array with the ndxArr and fout the value at the
			array and also the converted value taken from that index */
   }
