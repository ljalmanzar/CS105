// Header Files
#include "formatted_cmdline_io_v10.h"
#include <fstream>
#include <cstring>

using namespace std;

// Global Constants
const char NULL_CHAR = '\0';
const char NEWLINE_CHAR = '\n';
const int STRING_MAX_LENGTH = 125;
const int MAX_REPLACEMENT = 20;
const int MAX_STRINGS = 10000;

const int MAX_INPUTS = 4;

const int inputFile = 0;
const int outputFile = 1;
const int searchString = 2;
const int replacementString = 3;

const int endOfString = -1;
const int FLAG = -2;

const int NO_BLOCK_SIZE = 0;
const int ONE_ENDLINE = 1;

const int typeOne = 1;
const int typeTwo = 2;
const int ZERO = 0;

// Function Prototypes
/*
Name: showTitle
Process: shows title
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the table
Dependencies: iostream cmdline
*/
void showTitle ();

/*
Name: erroMessage
Process: gets type of error and prints it
Function Input/parameters: type of error
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: cmdline
*/
void errorMessage (int type);

/*
Name: getInputs
Process: prompts user for all the necessary info
Function Input/parameters: array to hold info
Function Output/parameters: the input, and output string/string to replace and string to replace with
Function Output/Return: none
Device Input: none
Device Output/Monitor: questions
Dependencies: cstring, cmdline
*/
void getInputs (char myInputsArr [][STRING_MAX_LENGTH]);

/*
Name: readFile 
Process: reads input file and inserts it to the array
Function Input/parameters: array with the file string and complete file array
Function Output/parameters: the array
Function Output/Return: how many strings there are
Device Input: none
Device Output/Monitor: operation update
Dependencies: cstring, cmdline
*/
int readFile (char myInputsArr [], char fileArr [][STRING_MAX_LENGTH]);

/*
Name: findSubString
Process: looks within the string and finds the string to replace
Function Input/parameters: the string at the index
Function Output/parameters: none
Function Output/Return: the index to change
Device Input: none
Device Output/Monitor: operation update 
Dependencies: cstring, cmdline
*/
int findSubString (char  fileArr [], const char myInputsArr []);

/*
Name: adjustString                                                
Process: makes space for the string to replace                                                                                                                                                      
Function Input/parameters: array string and index to change
Function Output/parameters: array 
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: cstring, cmdline
*/
void adjustString (char fileArr [], const char searchString [], const char replacementString[], int adjustmentNdx);

/*
Name: insertReplacement
Process: puts replacemennt string into string
Function Input/parameters: file array and new string and ndx to insert
Function Output/parameters: the file array
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: cstring, cmdline
*/
void insertReplacement (char fileArr [], const char myInputsArr [], int adjustmentNdx);

/*
Name: upload to file
Process: gets string and puts it to desired file
Function Input/parameters: the whole file array and how many strings there are
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: operation update
Dependencies: cstring, cmdline
*/
void uploadToFile (char fileArr [][STRING_MAX_LENGTH], const char output[], int howManyStrings);

// Main Program
int main ()
   {
	// variables
	char inputArr [MAX_INPUTS][STRING_MAX_LENGTH];
	char fileArr [MAX_STRINGS][STRING_MAX_LENGTH];

	int numOfStrings;
	int replacementStringLength;
	int ndx = 0;
	int ndxToChange;

	int counter = 0;
	char userOption;

	do
	{
		// clear screen 
		system ("cls");

		// show title
			// function : showTitle
			showTitle();

		// get inputs
			// get file to read from
			// get file to upload to
			// get string to search for
			// get replacement string
				// function : getInputs
				getInputs (inputArr);
	
		// open file and insert strings to array
			// function : readFile
			numOfStrings = readFile (inputArr [inputFile], fileArr);
			
			// if not file found return error		
			if (numOfStrings == FLAG)
				{
					errorMessage (typeOne);			
				}
			else 
				{
					// operation update
					printString ("OPERATION: Searching and replacing being conducted now." ,NO_BLOCK_SIZE, "CENTER");
					printEndLines (ONE_ENDLINE);
					printEndLines (ONE_ENDLINE);
					printEndLines (ONE_ENDLINE);
					
					replacementStringLength = strlen (inputArr[replacementString]);
					/// if string too large return error
					if ( replacementStringLength > MAX_REPLACEMENT)
						{
							errorMessage (typeTwo);
						}
					else 
						{
							// loop  
								while (ndx < numOfStrings)
									{	
									// find the string to replace
										// function : findSubString
										ndxToChange = findSubString (fileArr [ndx], inputArr[searchString]);
							
										if (ndxToChange == endOfString)
											{
												ndx ++;
											}
										else
											{
											// delete the string to replace and make space for new string
												// function : adjustString
												adjustString (fileArr [ndx], inputArr [searchString], inputArr [replacementString], ndxToChange);
										
											// insert string to add
												// function : insertReplacement
												insertReplacement (fileArr [ndx], inputArr[replacementString], ndxToChange);
						
												// count changes
												counter ++;
											}
									}
						
			
								// end of loop
							
								// upload to new file
									// function : uploadToFile
									uploadToFile (fileArr, inputArr [outputFile], numOfStrings);
							
								// show results
								if (counter == ZERO)
									{
										printString ("Sorry: No instances of \"", NO_BLOCK_SIZE, "CENTER");
										printString (inputArr [searchString], NO_BLOCK_SIZE, "CENTER");
										printString ("\" found in text.", NO_BLOCK_SIZE, "CENTER");
										printEndLines (ONE_ENDLINE);
										printEndLines (ONE_ENDLINE);
									}
								else
									{
										printString ("Success: ", NO_BLOCK_SIZE, "CENTER");
										printInt (counter, NO_BLOCK_SIZE, "CENTER");
										printString (" instances of \"", NO_BLOCK_SIZE, "CENTER");
										printString (inputArr [searchString], NO_BLOCK_SIZE, "CENTER");
										printString ("\" found and replaced with \"", NO_BLOCK_SIZE, "CENTER");
										printString (inputArr [replacementString], NO_BLOCK_SIZE, "CENTER");
										printString ("\".", NO_BLOCK_SIZE, "CENTER");	
										printEndLines (ONE_ENDLINE);
										printEndLines (ONE_ENDLINE);
								
									}
						}
				}
			userOption = promptForChar ("Press <Q>uit, or any other key <and ENTER> to continue: ");
   	}
			// give user option to quit or continue
		// do while
		while (userOption != 'q' && userOption != 'Q');	

	// end program
	return 0;

	}

// Function Implementation
void showTitle ()
{
	// print message
	printString ("SEARCH-REPLACE PROGRAM", NO_BLOCK_SIZE, "CENTER");
	printEndLines (ONE_ENDLINE);
	printString ("======================", NO_BLOCK_SIZE, "CENTER");
	printEndLines (ONE_ENDLINE);
	printEndLines (ONE_ENDLINE);
}

void errorMessage (int type)
{
	// determine which error
		if (type == typeOne)
			{
				printString ("ERROR: File or Data Not Found, processing aborted." ,NO_BLOCK_SIZE, "CENTER");
				printEndLines (ONE_ENDLINE);
				printEndLines (ONE_ENDLINE);
			}
		else
			{
				printString ("ERROR: Program insertion attempt too large for string, processing aborted." ,NO_BLOCK_SIZE, "CENTER");
				printEndLines (ONE_ENDLINE);
				printEndLines (ONE_ENDLINE);
			}
}

void getInputs (char myInputsArr [][STRING_MAX_LENGTH])
{
	// variables

	// ask for input file and insert to index 0 of arr
	promptForString ("Enter input file name   : ", myInputsArr[inputFile]);
	printEndLines (ONE_ENDLINE);
	// ask for output file and insert to index 1 of arr 
	promptForString ("Enter output file name  : ", myInputsArr[outputFile]);
	printEndLines (ONE_ENDLINE);
	// ask for the sub string to search for, index 2
	promptForString ("Enter search string     : ", myInputsArr[searchString]);
	printEndLines (ONE_ENDLINE);
	// ask for sub string to insert, index 3
	promptForString ("Enter replacement string: ", myInputsArr[replacementString]);
	printEndLines (ONE_ENDLINE);
	printEndLines (ONE_ENDLINE);
}

int readFile (char myInputsArr [], char fileArr [][STRING_MAX_LENGTH])
{
	// variables
	int ndx = 0;
	ifstream fin;

	// operation update
	printString ("OPERATION: Attempting to read input file being conducted now." , NO_BLOCK_SIZE, "CENTER");
	printEndLines (ONE_ENDLINE);
	printEndLines (ONE_ENDLINE);
	printEndLines (ONE_ENDLINE);

	// open file
	fin.clear();
	fin.open (myInputsArr);

	// check if good
	if (!fin.good())
		{
			return FLAG;
		}

	// while file is good
		while (fin.good())
			{
				// get next avaiable line
				// insert to next available c-string index
				fin.getline(fileArr [ndx], STRING_MAX_LENGTH, NEWLINE_CHAR );

				// increment index
				ndx ++;
			}
	
		// close file
		fin.close();
	
	return ndx; // return index (how many strings)
}

int findSubString (char  fileArr [],const char myInputsArr [])
{	// variables
	int placeNdx = 0;
	int compareNdx = 0;
	int stringNdx = 0;

	// check for sub string in c string sent in
		while (fileArr [placeNdx] != NULL_CHAR)
			{
				// compare first
				while (myInputsArr [stringNdx] != NULL_CHAR && myInputsArr [stringNdx] == fileArr [compareNdx])
					{					
						// if good compare second
						// ect
						compareNdx++;
						stringNdx++;
					}
				// return where string appears
				if (myInputsArr[stringNdx] == NULL_CHAR)
					{
						return placeNdx;
					}
							
				// increment place to start looking
				placeNdx++;
				compareNdx = placeNdx;
				stringNdx = 0;
			}

		// return end if nothing found	
		return endOfString; 
}

void adjustString (char fileArr [], const char searchString [], const char replacementString[], int adjustmentNdx)
{	// variables
	int difference;
	int searchStringSize;
	int replacementStringSize;
	int completeStringSize;

	searchStringSize = strlen (searchString);
	replacementStringSize = strlen (replacementString);
	completeStringSize = strlen (fileArr);

	difference = searchStringSize - replacementStringSize;

	if (difference < 0)
		{
			while (completeStringSize >= adjustmentNdx)
					{
					fileArr [completeStringSize-difference] = fileArr [completeStringSize];
					completeStringSize--;
					}
		}

	if (difference > 0)
		{
			while (fileArr[adjustmentNdx + difference] != NULL_CHAR)
					{
					fileArr [adjustmentNdx+difference] = fileArr [adjustmentNdx+searchStringSize];
					adjustmentNdx++;
					}

			fileArr[adjustmentNdx] = NULL_CHAR;
		}

}

void insertReplacement (char fileArr [], const char myInputsArr [], int adjustmentNdx)
{
	// variables
	int ndx = 0;

	// insert new string
	while (myInputsArr [ndx] != NULL_CHAR)
		{
			fileArr [adjustmentNdx] = myInputsArr [ndx];
			
			adjustmentNdx ++;
			ndx++;
		}
}

void uploadToFile (char fileArr [][STRING_MAX_LENGTH], const char output[], int howManyStrings)
{	// variables
	int ndx = 0;
	ofstream fout;
	
	// open file
	fout.open(output);
	
	// operation update
	printString ("OPERATION: Sending data to output file being conducted now." ,NO_BLOCK_SIZE, "CENTER");
	printEndLines (ONE_ENDLINE);
	printEndLines (ONE_ENDLINE);
	printEndLines (ONE_ENDLINE);

	// loop through array 
	while (ndx < howManyStrings)
		{
			// insert into the file
			fout << fileArr[ndx] << endl;
		
			// increment
			ndx++;
		}
}

