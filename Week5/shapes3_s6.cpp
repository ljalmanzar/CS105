// Header Files
#include "formatted_cmdline_io_v10.h"
#include <cmath>
#include <cstdlib>

using namespace std;

// Global Constants 
const int FULL_BLOCK_SIZE = 80;
const int NO_BLOCK_SIZE = 0;

const int endOne = 1;

// Function Prototypes

/*
Name: showTitle
Process: shows title with underline
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: title with underline
Dependencies: iostream I/O tools
*/
void showTitle();

/*
Name: getShape
Process: asks user for name of shape, capitalizes it, and returns it
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: shape name (string)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
string getShape();

/*
name: toUpperCaseLetter
Process: if letter passed is lower case, converts to upper case,
         has no effect otherwise
Function Input/parameters: letter character (char)
Function Output/parameters: none
Function Output/returned: upper case letter character, as appropriate (char)
Device Input: none
Device Output: none
Dependencies: none
*/
char toUpperCaseLetter( char letterChar );

/*
name: toUpperCaseWord
Process: if word passed has any lower case letters, 
         converts to individual letters to upper case,
         has no effect otherwise
Function Input/parameters: word (string)
Function Output/parameters: none
Function Output/returned: upper case letter word, as appropriate (string)
Device Input: none
Device Output: none
Dependencies: toUpperCaseLetter, string management tools
*/
string toUpperCaseWord( const string &word );

/*
Name: checkShapeName
Process: takes the returned string from getShapes and checks for valid shape
Function Input/parameters: shape
Function Output/parameters: none
Function Output/Return: true or false
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
bool checkShapeName(const string &shape);

/*
Name: displayErrorMessage
Process: shows error message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: error message 
Dependencies: iostream I/O tools
*/
void displayErrorMessage();

/*
Name: getSide
Process: returns side lengths 
Function Input/parameters: shape (string), which side (int)
Function Output/parameters: none
Function Output/Return: side lengths (double)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
double getSide(const string &shape, int whichSide);

/*
Name: calcArea
Process: gets inputs and calculates area
Function Input/parameters: shape (string), sideone (double), sidetwo (double)
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools, cmath
*/
double calcArea(const string &shape, double sideOne, double sideTwo);

/*
Name: showDividerLines
Process: shows specified divider
Function Input/parameters: type of divider 
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: divider
Dependencies: iostream I/O tools
*/
void showDividerLines(int type);

/*
Name: showResults
Process: shows results
Function Input/parameters: measurements and area 
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: results
Dependencies: iostream I/O tools
*/
void showResults(const string &shape, double sideOne, double sideTwo, double area);



// Main Program

int main ()
   {
	// Initialize program

		// Variables
		string shape;
		double sideOne, sideTwo;
		double area;

		int first = 1;
		int second = 2;

		// Diplay title 
			// function : displayTitle
			showTitle();

	// Get shape
		
		// Get shape name
			// Uppercase
				// function : getShape
				shape = getShape();

		// Check for valid shape name
			// function : checkShapeName

			// case : bad name
			if (!checkShapeName(shape))
				{
					//display error
					//function : displayErrorMessage
					displayErrorMessage();
					
					return 0;
				}
	 

			// case : name ok
			 // continue normally

	// Get side measurements
		
		// Get side one
			// function : getSide
			sideOne = getSide(shape, first);

		// Get side two
			// function : getSide 
			sideTwo = getSide(shape, second);

	// Calculate area
		// function : calcArea
		area = calcArea(shape, sideOne, sideTwo);

		// clear string
		system( "cls" );

	// Display results
		// function : showResults
		showResults (shape, sideOne, sideTwo, area);
		

	// End program

		// hold program for the user
		system( "pause" );

		// return success 

	return 0;
   }

// Function Implementation 

void showTitle()
   {
	// print title
	printString ("TWO DIMENSIONAL SHAPE AREA CALCULATOR", FULL_BLOCK_SIZE, "CENTER");
	
	// print underline
	printString ("=====================================", FULL_BLOCK_SIZE, "CENTER");

	printEndLines (endOne);

   }

char toUpperCaseLetter( char letterChar )
   {
    // initialize function/variables
       // none

    // check for lower case letter
    if( letterChar >= 'a' && letterChar <= 'z' )
       {
        // change lower case letter to upper case
        letterChar = letterChar - 'a' + 'A';
       }

    // return character
    return letterChar;
   }

string toUpperCaseWord( const string &word )
   {
    // initialize function/variables

       // create new local word
       string upperCaseWord;

       // initialize index to zero
       unsigned index = 0;

    // iterate to end of word    
    while( index < word.length() )
       {
        // set lower case letter to upper case, if needed
           // function: toUpperCaseLetter
        upperCaseWord += toUpperCaseLetter( word.at( index ) );

        // increment index
        index++;
       }

    // return upper case word
    return upperCaseWord;
   }

string getShape()
   {
	string shapeName, upperCaseShapeName;
	// ask for shape
	shapeName = promptForString ("	Enter shape name <e.g., TRIANGLE> : ");

	// upper case it
	upperCaseShapeName = toUpperCaseWord (shapeName);
	
    return upperCaseShapeName; // temporary stub return
   }

bool checkShapeName(const string &shape)
   {
	// case : if shape == PARALLOGAM, TRIANLE, or RECTANGLE return success
	// else failure

	string TRIANGLE, RECTANGLE, PARALLELOGRAM;

	if (shape == "TRIANGLE")
		{
		return true;
		}
	
	else if (shape == "RECTANGLE")
		{
		return true;
		}

	else if (shape == "PARALLELOGRAM")
		{
		return true;
		}

	return false;
   }


void displayErrorMessage()
   {
	//print error message
	printEndLines (endOne);

	printString ("	ERROR: Invalid shape name or data entered; program aborted", NO_BLOCK_SIZE, "CENTER");
	
	printEndLines (endOne);
	printEndLines (endOne);

	system ("pause");
   }


double getSide(const string &shape, int whichSide)
   {
	// check which shape
	// ask for appropriate side/height
	string TRIANGLE, RECTANGLE, PARALLELOGRAM;
	int first = 1;
	double measurement;

	if (shape == "TRIANGLE")
		{
		if (whichSide == first)
			{
			measurement = promptForDouble ("	Enter base of triangle            : ");
			}
		else
			{
			measurement = promptForDouble ("	Enter height of triangle          : ");
			}
		}

	else if (shape == "RECTANGLE")
		{
		if (whichSide == first)
			{
			measurement = promptForDouble ("	Enter length of rectangle         : ");
			}
		else
			{
			measurement = promptForDouble ("	Enter width of rectangle          : ");
			}
		}

	else if (shape == "PARALLELOGRAM")
		{
		if (whichSide == first)
			{
			measurement = promptForDouble ("	Enter base of parrallelogram      : ");
			}
		else
			{
			measurement = promptForDouble ("	Enter height of parrallelogram    : ");
			}
		}

    return measurement; 
   }

double calcArea(const string &shape, double sideOne, double sideTwo)
   {
	string TRIANGLE, RECTANGLE, PARALLELOGRAM;
	double area;

	// check which shape to know which formula

	// calculate

	if (shape == "TRIANGLE")
		{
		area = (sideOne * sideTwo) / 2;
		}
	else 
		{
		area = sideOne * sideTwo;
		}
	

    return area; // temporary stub return
   }

void showDividerLines(int type)
   {
	
	int typeOne = 1;
	int typeTwo = 2;
	int typeThree = 3;
	int typeFour = 4;
	int startSpace = 5;

	//if typeOne print so and so
	// else if typeTwo print so and so
	if (type == typeOne)
		{
		printString ("|========================================================|", FULL_BLOCK_SIZE, "CENTER");
		}

	else if (type == typeTwo)
		{
		printString ("|", NO_BLOCK_SIZE, "CENTER");
		}

	else if (type == typeThree)
		{
		printString ("|====================|===================================|", FULL_BLOCK_SIZE, "CENTER");
		}
	
	else if (type == typeFour)
		{
		printString ("|--------------------|-----------------------------------|", FULL_BLOCK_SIZE, "CENTER");
		}
	
	else if (type == startSpace)
		{
		printString ("           ", NO_BLOCK_SIZE, "CENTER");
		}

	}


void showResults(const string &shape, double sideOne, double sideTwo, double area)
   {
	// show table
	// show words and results
	int typeOne = 1;
	int typeTwo = 2;
	int typeThree = 3;
	int typeFour = 4;
	int startSpace = 5;

	int twoDecimals = 2;

	int GRID_BLOCK_SIZE = 56;
	int FIRST_BLOCK = 20;
	int SECOND_BLOCK = 35;

	// first row
	showDividerLines (typeOne);
	
	// second row
	showDividerLines (startSpace); showDividerLines (typeTwo); printString ("SHAPE CALCULATION RESULTS", GRID_BLOCK_SIZE, "CENTER"); showDividerLines (typeTwo); 
	printEndLines (endOne);
	
	//third row
	showDividerLines (typeThree);

	//fourth row
	showDividerLines (startSpace); showDividerLines (typeTwo); printString ("Area of ", FIRST_BLOCK, "RIGHT"); 
	showDividerLines (typeTwo); printString (shape, SECOND_BLOCK, "CENTER"); showDividerLines (typeTwo);
	printEndLines (endOne);

	//fifth row
	showDividerLines (typeFour);

	//sixth row
	showDividerLines (typeFour);

	//seventh row
	showDividerLines (startSpace); showDividerLines (typeTwo), printString ("Measurement", FIRST_BLOCK, "CENTER"); showDividerLines (typeTwo);
	printString ("Value", SECOND_BLOCK, "CENTER"); showDividerLines (typeTwo);
	printEndLines (endOne);

	//eighth row
	showDividerLines (typeFour);

	//ninth row
	showDividerLines (startSpace);
	showDividerLines (typeTwo); 
	if (shape == "RECTANGLE")
		{
		printString (" LENGTH", FIRST_BLOCK, "LEFT");
		}
	else 
		{
		printString (" BOTTOM BASE", FIRST_BLOCK, "LEFT");
		}
	showDividerLines (typeTwo);

	printDouble (sideOne, twoDecimals, SECOND_BLOCK, "CENTER");

	showDividerLines (typeTwo);

	// tenth row
	showDividerLines (startSpace);

	showDividerLines (typeFour);

	// 11th row
	showDividerLines (startSpace);

	showDividerLines (typeTwo);

	if (shape == "RECTANGLE")
		{
		printString (" WIDTH", FIRST_BLOCK, "LEFT");
		}
	else 
		{
		printString (" HEIGHT", FIRST_BLOCK, "LEFT");
		}

	showDividerLines (typeTwo);

	printDouble (sideTwo, twoDecimals, SECOND_BLOCK, "CENTER");

	showDividerLines (typeTwo);

	// 12th row
	showDividerLines (startSpace);

	showDividerLines (typeFour);

	// 13th row
	showDividerLines (typeFour);

	// 14th row
	showDividerLines (startSpace);
	
	showDividerLines (typeTwo);

	printString ("Shape", FIRST_BLOCK, "CENTER");

	showDividerLines (typeTwo);

	printString ("Area", SECOND_BLOCK, "CENTER");

	showDividerLines (typeTwo);

	printEndLines (endOne);

	// 15th row
	showDividerLines (typeFour);

	// 16th row
	showDividerLines (startSpace);
	
	showDividerLines (typeTwo);

	printString (shape, FIRST_BLOCK, "LEFT");

	showDividerLines (typeTwo);

	printDouble (area, twoDecimals, SECOND_BLOCK, "CENTER");

	showDividerLines (typeTwo);

	printEndLines (endOne);

	// 17th row
	showDividerLines (typeFour);

	// 18th row
	showDividerLines (typeOne);

	printEndLines (endOne);
	printEndLines (endOne);	
   }
	
	

