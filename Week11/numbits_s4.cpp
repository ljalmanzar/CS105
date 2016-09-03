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
	// stub
   }

void getStuff (int &numToCheck, int &bitsToCheck, string &fileName)
   {
	// stub
   }
int storeNumbers (int decArr [], int numToCheck)
   {
	// stub
	return 0;
   }
void changeToBinary (int decArr [], int biArr [], int arrSize)
   {
	// stub
   }
int findBits (int biArr [], int ndxArr [], int bitsToCheck, int arrSize)
   {
	// stub
	return 0;
   }
void outPutToFile (int &numToCheck, 
					int &bitsToCheck, 
					const string &fileName, 
					int ndxArr [], 
					int arrSize)
   {
	// stub
   }
