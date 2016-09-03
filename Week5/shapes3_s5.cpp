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
double calcArea(const string &shape, double someSide, double someOtherSide);

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
void showResults(const string &shape, double someSide, double someOtherSide, double area);



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

	// Get shape
		
		// Get shape name
			// Uppercase
				// function : getShape
			shape = getShape();

		// Check for valid shape name
			// function : checkShapeName
			checkShapeName(shape);

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

void diplayTitle()
   {
	// print title
	
	// print underline

   }

string getShape()
   {
	// ask for shape

	// upper case it

    return 0; // temporary stub return
   }

bool checkShapeName(const string &shape)
   {
	// case : if shape == PARALLOGAM, TRIANLE, or RECTANGLE return success
	// else failure

    return 0; // temporary stub return
   }


void displayErrorMessage()
   {
	//print error message
   }


double getSide(const string &shape, int whichSide)
   {
	// check which shape
	// ask for appropriate side/height

    return 0; // temporary stub return
   }

double calcArea(const string &shape, double someSide, double someOtherSide)
   {
	// check which shape to know which formula

	// calculate

    return 0; // temporary stub return
   }

void showDividerLines(int type)
   {
	//if typeOne print so and so
	// else if typeTwo print so and so
   }

void showResults(const string &shape, double someSide, double someOtherSide, double area)
   {
	// show table
	// show words and results

   }

