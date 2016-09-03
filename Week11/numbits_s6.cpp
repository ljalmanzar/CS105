// Header Files 
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

// Global Constants
const int MAX_VALUE = 100000;
const string INDENT = "      "; 

// Function Prototypes
void showTitle ();

int getStuff (int &numToCheck, int &bitsToCheck, string &fileName);

void storeNumbers (int decArr [], int numToCheck);

void changeToBinary (int decArr [], int biArr [], int arrSize);

int findBits (int biArr [], int ndxArr [], int bitsToCheck, int arrSize);

void outPutToFile (int &numToCheck, 
					int &bitsToCheck, 
					const string &fileName, 
					int ndxArr [], 
					int arrSize,
					int decArr [],
					int biArr[]);

// Main Program
int main ()
   {
	// Initialize
		int mainVal;
		int numBits;
		string fileName;
		int testVar;
		int arrSize;
		int ndxArrSize;
		int decimalArr [MAX_VALUE];
		int binaryArr [MAX_VALUE];
		int outputNdxArr [MAX_VALUE];

		
		// show title
			// function : showTitle
				showTitle();

	// Get All Values and files

		// get number to be tested
			//function :getStuff

		// get number of bits to test for
			//function :getStuff

		// get output file name
			//function :getStuff
				testVar = getStuff (mainVal, numBits, fileName);

				arrSize = mainVal;

		// test value given
				if (testVar == 0)
					{
						cout << endl;
						cout << "ERROR: Input value is outside of program limits, program aborted." << endl << endl;
						
						system ("pause");
						return 0;
					}

	// Convert number to binary and insert 1 to num in array
		// get numbers
			// function : storeNumbers
				storeNumbers (decimalArr, mainVal);

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
					ndxArrSize,
					decimalArr,
					binaryArr);

	// End
	system ("pause");
	return 0;
	
   }

// Function Implementation

void showTitle ()
   {
	// print title
	cout << endl << endl;
	cout << INDENT << "NUMBER OF BITS FINDING PROGRAM" << endl;
	cout << INDENT << "==============================" << endl;
   }

int getStuff (int &numToCheck, int &bitsToCheck, string &fileName)
   {
	// ask for numbers and cin value
	cout << INDENT << "Enter number to be tested <max 100000>: ";
	cin >> numToCheck;
	
	// check value
		if (numToCheck > 100000)
			{
				return 0;
			}

		if (numToCheck < 0)
			{
				return 0;
			}
	
	// ask for bits and cin value
	cout << INDENT << "Enter number of bits to searh for     : "; 
	cin >> bitsToCheck;

	// ask for file to output to and cin
	cout << INDENT << "Enter file name for data output       : ";
	cin >> fileName;
	cout << endl;

	return 1;
   }

void storeNumbers (int decArr [], int numToCheck)
   {
	// variables 

	/* make loop that enters 1 to ndx 0, 2 to ndx 1.... and so on until the the 
	numToCheck is inserted  */
		while (numToCheck > 0)
			{
				decArr [numToCheck - 1] = numToCheck;
				
				numToCheck --;
			}

   }

void changeToBinary (int decArr [], int biArr [], int arrSize)
   {
	// variables 
	int ndx = 0;
	int num;
	int count = 0;
	int temp[50]; 
	int binary;
	int newBit;

	// while loop
			// get value from array
			// convert to binary
			// put back into array
			// increment ndx

	while (ndx < arrSize)
		{
			num = decArr [ndx];

			while(num != 0) 
				{ 
				 	if(num % 2 == 0) 
				  		{ 
					  		 temp[count] = 0; 
					 	 } 
					 else 
					 	 { 
					  		 temp[count] = 1; 
					 	 } 
				
						num = num / 2;
						count ++;
				}
		
		
				binary = temp [count-1];

				count = count - 2;
		
				while (count >= 0)
					{
						newBit = temp[count];
		
						binary = binary * 10;
		
						binary = binary + newBit;
		
						count --;
					}

				biArr [ndx] = binary;
		
				ndx ++;
		}		
   }

int findBits (int biArr [], int ndxArr [], int bitsToCheck, int arrSize)
   {
	// variables 
	int searcher = 0;
	int valid = 0;
	int bits = 0;
	int binary;
	int temp;


	// check number 
		// while loop

			// get int from arr

			// get sum the digits of the integer

			 // if the sum is the same as "bitsToCheck" in next available index
			// ALSO store index that 'good' number was found at in the ndxARR

		while (searcher < arrSize)
			{
				binary = biArr [searcher];

				while (binary > 0)
					{
						temp = binary % 10;
						binary /= 10;
						bits += temp;
					}

				if (bits == bitsToCheck)
					{
						ndxArr [valid] = searcher;
						
						valid ++;
					}
	
				searcher ++;
				bits = 0;
			}
			
	// return highest available index
	return valid;

   }

void outPutToFile (int &numToCheck, 
					int &bitsToCheck, 
					const string &fileName, 
					int ndxArr [], 
					int arrSize,
					int decArr[],
					int biArr[])
   {
	// variables
	int ndx;
	ofstream fout;
	int decimal;
	int binary;
	int spaceCounter = 0;

	// open file
	fout.open (fileName.c_str());

	// cout message
	cout << "For the number " << numToCheck << ". " << arrSize << " values with "
		<< bitsToCheck << " one-bits were found." << endl << endl;

	// fout main message
	fout << "Values found up to and including the number " << numToCheck
	<< " that contained " << bitsToCheck << " one-bits." << endl << endl;

	fout << "The numbers identified are as follows:" << endl;

	// fout values found
		/* Go through my decimal array with the ndxArr and fout the value at the
			array and also the converted value taken from that index */
   		while (ndx < arrSize)
			{
				decimal = decArr [ndxArr [ndx]];
				binary = biArr [ndxArr [ndx]];

				fout << decimal;
				fout << "(" << binary << ")";
				fout << ", ";

				if (spaceCounter == 5)
					{
						fout << endl;
						spaceCounter = 0;
					}

				ndx ++;
				spaceCounter ++;
				
			}
	}
