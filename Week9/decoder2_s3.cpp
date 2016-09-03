// Header Files
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

// Global Constants
const int ARRAY_SIZE = 5000;
const int MAX_SPACE = 10;

const char SPACE = 32;
const char endline = 10;

// Function Prototypes

void showTitle ();

void getFileNames (string &inputFile, string &outputFile);

int storeInts (const string &inputFileString, int array[]);

int decryptData (int array[], int totalndx);

int findEven (int evArray[], int totalndx, int &ndx);

void changeToChar (int array[], char charArray[], int evenndx);

void insertData (const string &outputFileStr, char charArray[], int evenndx);

// Main Program
int main ()
   {
	
	// initialize variables
	string encodedFileString;
	string outputFileString;
	int totalndxSize;
	int evenndxSize;

	int allIntsArr [ARRAY_SIZE];

	
	// show title
		// function : showTitle
		showTitle ();

	// get input files
		//get file to read from and file to insert to
			// function : getFiles
			getFileNames(encodedFileString,outputFileString);

	// store integers into an array
		// clear/open file
		// read ints into array
		// close
			// function : storeInts
			totalndxSize = storeInts (encodedFileString, allIntsArr);

			if (totalndxSize == 0)
				{
				system ("pause");
				return 0;
				}


	// decrypt data and insert 2 or 3 digits ints back into the same array
		// find even
		// truncate last 3 digits if even
		// insert back into array
			// function : decryptData
			evenndxSize = decryptData (allIntsArr, totalndxSize);


	// write data to the file
		// initialize char array *NOTE* could not be initialized in beginning of main program due to the ndx not having a value until this point
		char charArr [evenndxSize];

		// get chars into array 
		changeToChar (allIntsArr, charArr, evenndxSize);


		// write to new file
			// function : insertData
			insertData (outputFileString, charArr, evenndxSize);

	// hold for user
	system ("pause");
	return 0;

	}

// Function Implementation
void showTitle ()
   {
	// show message
	cout << "     Decoder Program" << endl;
	cout << "     ===============" << endl;
	}

void getFileNames (string &inputFile, string &outputFile)
   {
	// get file names as string
	cout << "Enter input file name: ";
	cin >> inputFile;
	cout << endl;

	cout << "Enter output file name: ";
	cin >> outputFile;
	cout << endl << endl << endl;

	// open file into the corresponding variable 
	}

int storeInts (const string &inputFileString, int array[])
{
	// variables 
	ifstream encodedFile;
	int num;
	int ndx;

	// tell user 
	cout << "Uploading Data . . ." << endl << endl << endl;

	//open and check
	encodedFile.clear();
	encodedFile.open (inputFileString.c_str());

	if (!encodedFile.good())
		{
			cout << endl;
			cout << "ERROR: File \"" << inputFileString << "\" Not Found - Program Aborted" << endl;
			cout << endl << endl;
		
			return 0;
		}

	// read in
	for (ndx = 0; ndx < ARRAY_SIZE && encodedFile.good();ndx++)
		{
			encodedFile >> num;
	
			array[ndx] = num;
		}
	
	// close
	encodedFile.close();

	return ndx;
}

int decryptData (int array[], int totalndx)
{
	// variables
	int housingndx;
	int finderndx;

	// tell user 
	cout << "Decrypting Data . . ." << endl << endl << endl;

	// loop
		// prime the loop 
		housingndx = 0;
		finderndx = 0;

	while (finderndx <= totalndx )
		{	
			if (array[finderndx] % 2 == 0)
				{
					array[finderndx] /= 1000;

					array [housingndx] = array[finderndx];

					housingndx ++; 
				}

			finderndx ++;
		}
	
	return housingndx;
	
}

int findEven (int evArray[], int totalndx, int &ndx)
{
	// variables 
	int number;

	// get even
	while (ndx <= totalndx)
		{
			number = evArray [ndx];

			if (number%2 == 0)
				{
					return number;
				}
			ndx++;

		}
	return 0;
}

void changeToChar (int array[], char charArray[], int evenndx)
{
	//variables 
	int ndx = 0;
	
	// get ints from one array, change to char and insert to other
	while (ndx <= evenndx)
		{
		charArray [ndx] = char (array[ndx]);
	
		// increment 
		ndx ++;	
		}
}

void insertData (const string &outputFileStr, char charArray[], int evenndx)
{
	// variables
	int ndx;
	int spaceCounter;
	ofstream outputFile;

	// tell user
	cout << "Downloading Decrypted Data . . ." << endl << endl << endl;

	// open file
	outputFile.open (outputFileStr.c_str());

	ndx = 0;
	spaceCounter = 0;
	while (ndx <= evenndx)
		{
			// insert to file
			outputFile << charArray[ndx];
			
			// check for space
			if (charArray[ndx] == SPACE)
				{
					spaceCounter ++;
				
						if (spaceCounter == MAX_SPACE)
							{
								outputFile << endl;

								spaceCounter = 0;
							}
				}
			// check for endline
			if (charArray[ndx] == endline)
				{
					spaceCounter = 0;
				}

			//increment
			ndx++; 
		}
	
	// close file
	outputFile.close();
}
