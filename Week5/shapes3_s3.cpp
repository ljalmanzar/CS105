// Header Files
#include "formatted_cmdline_io_v10.h"
#include <cmath>
#include <cstdlib>

// Global Constants 

// Function Prototypes

/*
Name: displayTitle
Process: shows title with underline
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: title with underline
Dependencies: iostream I/O tools
*/
void displayTitle();

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
double calcArea(const string &shape, int someSide, int someOtherSide);

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
void showDividerLines(const string &type);

// Main Program

int main ()
   {
	// Initialize program

		// Variables

		// Diplay title 
			// function : displayTitle

	// Get shape
		
		// Get shape name
			// function : getShape

		// Upper Case Word
			// function : getShape

		// Check for valid shape name
			// function : checkShapeName

			// case : bad name
			if ()
				{
					//display error
					//function : displayErrorMessage
				return 0;	
				}	 

			// case : name ok
			 // continue normally

	// Get side measurements
		
		// Get side one
			// function : getSide

		// Get side two
			// function : getSide 

	// Calculate area
		// function : calcArea
		

	// Display results
		// function : showDivider 
		// function : printString
		// function : printDouble
		

	// End program

		// hold program for the user

		// return success 

	return 0;
   }

// Function Implementation 

void diplayTitle()
   {

   }

string getShape( )
   {

    return 0; // temporary stub return
   }

bool checkShapeName(const string &shape)
   {

    return 0; // temporary stub return
   }


void displayErrorMessage()
   {

   
   }


double getSide(const string &shape, int whichSide)
   {

    return 0; // temporary stub return
   }

double calcArea(const string &shape, int someSide, int someOtherSide)
   {

    return 0; // temporary stub return
   }

void showDividerLines(const string &type)
   {

   }


