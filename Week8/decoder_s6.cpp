// header files
#include <iostream>
#include <cstdlib>
#include <cmath>
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
Name: showErrorMessage
Process: prints error message
Function Input/parameters: messed up file
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void showErrorMessage (const string &inputFile);

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
Name: getEven
Process: looks for even ints in the encoded file
Function Input/parameters: the encoded file 
Function Output/parameters: none
Function Output/Return: the number (int)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
int getEven (ifstream &inputFile);

/*
Name:getChar
Process: takes the in from getEven and transfers it to a character 
Function Input/parameters: the int from file
Function Output/parameters: none
Function Output/Return: the decoded character (char)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
char getChar (int number);

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
	ifstream encodedFile;
	ofstream outputFile;
	string encodedFileString;
	string outputFileString;
	int evenInt;
	char decodedPart;

	int spaceCounter = 0; 
	char space = 32;
	char endline = 10;

	// show title
		//function : showTitle
		showTitle ();

	// get files

		// get encoded file 
		// get file to output to
			// function : getFileNames
			getFileNames(encodedFileString,outputFileString);

			// open files
			encodedFile.clear();
			encodedFile.open (encodedFileString.c_str());

			outputFile.open (outputFileString.c_str());

		// show error message or  "processing" 
			// function : showProcessingMessage
			if (encodedFile.good())
				{
				showProcessingMessage ();
				}
			else 
				{
				showErrorMessage (encodedFileString);
				system ("pause");
				return 0;
				}
								
	// decrypt the file

		// while check if open correctly
				// function : checkForValidFile
					// if return false print Error and end program
						// function : showErrorMessage

				while (encodedFile.good())
					{
					// get int
					// function : findEven
					evenInt = getEven (encodedFile);

					// take the corresponding #s and convert to appropriate char 
					decodedPart = getChar (evenInt);
				
					// insert decryption into given output file
					outputFile << decodedPart;

					/// check for spaces
					if (decodedPart == space)
						{
						spaceCounter ++;
						
						if (spaceCounter > 9)
							{
							outputFile << endl; 
							
							spaceCounter = 0;
							}
						}
					
					if (decodedPart == endline)
						{
						spaceCounter = 0;
						}

					
					}

		// close the file
		outputFile.close();

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
	cout << endl;

	// open file into the corresponding variable 
	}

void showErrorMessage (const string &inputFile)
   {
	// show message
	cout << endl << endl;
	cout << "ERROR: File \"" << inputFile << "\" " << "Not Found - Program Aborted" << endl << endl << endl << endl;
	}

void showProcessingMessage ()
   {
	// show message
	cout << endl << endl;
	cout << "Processing Data . . ." << endl << endl << endl;
	}

int getEven (ifstream &inputFile)
   {
	// initialize 
	int number;

	// get the int
	while (inputFile.good())
		{
		inputFile >> number;

		if (number%2 == 0)
			{
			return number;
			}
		
		}
	return 0;
	}

char getChar (int number)
   {
	int choppedNum;
	char decodedPart;

	// get first parts of int
	choppedNum = number / 1000;
	
	// make char
	decodedPart = char (choppedNum);

 	return decodedPart; 
	}

void endProcessingMessage ()
   {
	// show messagea
	cout << ". . . Data processing completed." << endl << endl << endl << endl; 
	}
