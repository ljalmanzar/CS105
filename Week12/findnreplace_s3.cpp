// Header Files
#include "formatted_cmdline_io_v10.h"
#include <cstring>

using namespace std;

// Global Constants

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
int findSubString (char  fileArr []);

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
void adjustString (char fileArr [], const char myInputsArr [], int adjustmentNdx);

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
void uploadToFile (char fileArr [][STRING_MAX_LENGTH], int howManyStrings);

// Main Program
int main ()
   {
	// variables

	// show title
		// function : showTitle

	// get inputs
		// get file to read from
		// get file to upload to
		// get string to search for
		// get replacement string
			// function : getInputs

	// open file and insert strings to array
			// function : readFile

	// loop  

		// find the string to replace
			// function : findSubString

		// delete the string to replace and make space for new string
			// function : adjustString
	
		// insert string to add
			// function : insertReplacement
		
		// end of loop

		// upload to new file
			// function : uploadToFile
	
	// give user option to quit or continue

	}

// Function Implementation
void showTitle ();
{
	// stub
}

void errorMessage (int type);
{
	// stub
}

void getInputs (char myInputsArr [][STRING_MAX_LENGTH]);
{
	// stub
}

int readFile (char myInputsArr [], char fileArr [][STRING_MAX_LENGTH]);
{
	return 0; // temp
}

int findSubString (char  fileArr []);
{
	return 0; // temp
}

void adjustString (char fileArr [], const char myInputsArr [], int adjustmentNdx);
{
	// stub
}

void insertReplacement (char fileArr [], const char myInputsArr [], int adjustmentNdx);
{
	// stub
}

void uploadToFile (char fileArr [], int howManyStrings);
{
	// stub
}

