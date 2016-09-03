// header files
#include "formatted_cmdline_io_v10.h"
#include <cstdlib>
using namespace std;

// global constants
char letterOne, letterTwo, letterThree, letterFour, letterFive, letterSix, letterSeven, letterEigth, letterNine, letterTen;
char numberOne, numberTwo, numberThree, numberFour, numberFive, numberSix, numberSeven, numberEigth, numberNine, numberTen;
char symbolOne, symbolTwo, symbolThree, symbolFour, symbolFive, symbolSix, symbolSeven, symbolEigth, symbolNine, symbolTen;
string translatedOne, translatedTwo, translatedThree, translatedFour, translatedFive, translatedSix, translatedSeven, translatedEigth, translatedNine, translatedTen;
string finalTranslation;

// function prototypes

/*
Name: displayTable
Process: shows table with title and translation options
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the table
Dependencies: iostream I/O tools
*/
void displayTable();

/*
Name: getCompleteTranslatedString
Process: will get inputs, then translate the inputs, then add the translated strings together to one string
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: complete translated string
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools, checkForDash, translateInputs
*/

string getCompleteTranslatedString ();

/*
Name: checkForDash
Process: will check if a dash has been entered. will return true if one was entered and false if not.
Function Input/parameters: symbol entered (char)
Function Output/parameters: none
Function Output/Return: true or false (bool)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
bool checkForDash (char symbol);

/*
Name: translateInput
Process: translates the given inputs
Function Input/parameters: letter and number (char)
Function Output/parameters: none
Function Output/Return: translated string (string)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
string translateInput (char letter, char number);

/*
Name: displayResults
Process: shows ending results with complete translated string
Function Input/parameters: translated string (string)
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: separating line and translated string
Dependencies: iostream I/O tools
*/
void displayResults(const string &translation );


// main program
int main ()
   {
   	// display title and translations options
   		// show title
   		// show table of translations
			// function : displayTable
		displayTable();
   	
   	// display instructions
		// function : cout
		cout << "Code is in the form A1, B3, C2-, up to ten items ending with a dash" << endl;
		cout << "Enter Code";


   	// ALL THIS WITHIN FUNCTION getTranslatedString
	/* prompt user for inputs
			//function : cin
   				// check for dash for the end of the input
					// function : checkForDash

		// translate inputs
			// check for valid inputs
			// translate
				// function : translateInputs

		// get translated string
   	*/
	getCompleteTranslatedString ();


   	// display translations or error message
   		// display translations
   		// show error message if incorrect inputs
			// function : displayResults
	displayResults(finalTranslation);

	// hold for user
	system ("pause");
   	
   	return 0;
   }
   
// function implementation

void displayTable()
   {
	// display title

	// display translations

   }

string getCompleteTranslatedString ()
	{
	// get inputs (check for dashes)
		// function : getInputs

	// translate the inputs 
		// function : translateInputs

	// combine translated strings

	// return complete translated string
	return 0; // temp stub
	}

bool checkForDash (char symbol)
	{
	// if symbol == '-' return true
	// else return false
	
	return 0; // temp stub
	}

string translateInput (char letter, char number)
	{
	// if list with A's and all available #'s 
	// else if rest of letters with there own else ifs within 
	
	return 0; // temp stub
	}

void displayResults( const string &one)
   {
	// cout "translation" and enter the returns complete translation

   }
