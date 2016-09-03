// header files
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

// global constants

//function prototype

/*
Name: showTitle
Process: shows title
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the title
Dependencies: iostream I/O tools
*/
void showTitle ();

/*
Name: getFileNames
Process: takes strings from programs and adds the text files to them
Function Input/parameters: the input file names (string)
Function Output/parameters: the text tiles 
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
void getFileNames (string &inputFile, string &outputFile);

/*
Name: checkForValidFile 
Process: takes in the input file .txt and checks if it was accessed correctly
Function Input/parameters: the input file (string)
Function Output/parameters: none
Function Output/Return: true or false
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
bool checkForValidFile (string inputFile);

/*
Name: showErrorMessage
Process: prints error message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void showErrorMessage ();

/*
Name: showProcessingMessage
Process: print the "processing" message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void showProcessingMessage ();

/*
Name: findEven
Process: looks for even ints in the encoded file
Function Input/parameters: the encoded file 
Function Output/parameters: none
Function Output/Return: the number (int)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
int findEven (string inputFile);

/*
Name:extractChar
Process: takes the in from findEven and transfers it to a character 
Function Input/parameters: the int from file
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
char extractChar (int number);

/*
Name: insertToFile
Process: takes the char from extractChar and puts it into the output file 
Function Input/parameters: the char from extractChar (char)
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
void insertToFile (char decoded);

/*
Name: endProcessingMessage
Process: shows the completed message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void endProcessingMessage ();




// main program 
int main ()
   {
	string encodedFile;
	string outputFile;
	int evenInt;
	char decodedPart;

	// show title
		//function : showTitle
		showTitle ();

	// get files

		// get encoded file 
			// function : getFileNames
			getFileNames(encodedFile,outputFile);

		// get file to output to
			// function : getFileNames
 
		// check if open correctly
				// function : checkForValidFile
					// if return false print Error and end program
						// function : showErrorMessage
							if (!checkForValidFile (encodedFile))
								{
								showErrorMessage ();
								system ("pause");
								return 0;
								}
								
	
		// show "processing" 
			// function : showProcessingMessage
			showProcessingMessage ();

	// decrypt the file

		// check for even int
			// function : findEven
			evenInt = findEven (encodedFile);

		// if 5 chars long take first 2 numbers, if 6 chars long take first 3
			// function : extractChar
		// take the corresponding #s and convert to appropriate char 
			decodedPart = extractChar (evenInt);

	// insert decryption into given output file
		
		// function : insertToFile
		insertToFile(decodedPart);

		// show "finish processing" message
			//function : endProcessingMessage
			endProcessingMessage();
	
	// end
	system ("pause");

	return 0;
	}

//function inplementation
void showTitle ()
   {
	
	}

void getFileNames (string &inputFile, string &outputFile)
   {
	
	}

bool checkForValidFile (string inputFile)
   {
	return 0; // temp stub
	}

void showErrorMessage ()
   {
	
	}

void showProcessingMessage ()
   {
	
	}

int findEven (string inputFile)
   {
	return 0; // temp stub
	}

char extractChar (int number)
   {
	return 0; // temp stub
	}
void insertToFile (char decoded)
	{
	}

void endProcessingMessage ()
   {
	
	}
