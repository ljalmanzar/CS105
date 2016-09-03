// header files
#include "formatted_cmdline_io_v10.h"
using namespace std;

// global constants
const string ERROR_CODE = "ERROR - Incorrect code entry, please try again!";
const string ERROR_CODE_TOO_MANY = "ERROR - Too many input items, please try again!";

const int NO_BLOCK_SIZE = 0;
const int GRID_BLOCK_SIZE = 73;
const int endOne = 1;

const int typeDivider = 1;
const int typePipe = 2;
const int typeSpace = 3;

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

/*
Name: printLine 
Process: gets line type and returns corresponding line 
Function Input/parameters: type of line (int)
Function Output/parameters: none
Function Output/Return: line type (string)
Device Input: none
Device Output/Monitor: line
Dependencies: iostream I/O tools
*/
void printLine(int type);


// main program
int main ()
   {
	string finalTranslation;
   	// display title and translations options
   		// show title
   		// show table of translations
			// function : displayTable
		displayTable();
   	
   	// display instructions
		// function : cout
		cout << "Code is in the form A1, B3, C2-, up to ten items ending with a dash" << endl;
		cout << "Enter Code: ";


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
	finalTranslation = getCompleteTranslatedString ();
	printEndLines(endOne);

  	// display translations or error message
   		// display translations			
		// show error message if incorrect inputs

	if (finalTranslation == ERROR_CODE)
		{
		printString (ERROR_CODE, NO_BLOCK_SIZE, "LEFT");
		printEndLines (endOne);
		printEndLines (endOne);

		system ("pause"); 

		return 0;
		}

	else if (finalTranslation == ERROR_CODE_TOO_MANY)
		{
		printString (ERROR_CODE_TOO_MANY, NO_BLOCK_SIZE, "LEFT");
		printEndLines (endOne);
		printEndLines (endOne);

		system ("pause"); 

		return 0;
		}

	else 
		{
		// function : displayResults
		displayResults(finalTranslation);

		// hold for user
		system ("pause");
   	
   		return 0;
		}
   }




   
// function implementation

void displayTable()
   {
	// display title
	printLine (typeDivider);
	printEndLines (endOne);

	printLine (typePipe);
	printString ("PIRATE TRANSLATOR", GRID_BLOCK_SIZE, "CENTER");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typeDivider);
	printEndLines (endOne);

	// display translations

	printLine (typePipe);
	printString (" A : | 1-Hello  2-Pardon me  3-Excuse me", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString (" B : | 1-Sir  2-Madam  3-Miss  4-Stranger  5-Officer", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString (" C : | 1-Where is  2-Can you help me find  3-Is that  4-How far is it to", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString (" D : | 1-The  2-A  3-Any  4-Nearby  5-My  6-Your", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString (" E : | 1-Old  2-Attractive  3-Happy", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString (" F : | 1-Restroom  2-Restaurant  3-Hotel  4-Mall  5-Pub  6-Bank", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString ("     | 1-I would like to  2-I desire  3-I wish I knew how to", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);
	printLine (typePipe);
	printString (" G : |", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);
	printLine (typePipe);
	printString ("     | 4-My mother told me to  5-My companion would like to", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printString (" H : | 1-Find  2-Take a nap  3-Make a withdrawal  4-Have a cocktail", GRID_BLOCK_SIZE, "LEFT");
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typePipe);
	printLine (typeSpace);
	printLine (typePipe);
	printEndLines (endOne);

	printLine (typeDivider);
	printEndLines (endOne);

   }

string getCompleteTranslatedString ()
	{
	char letterOne, letterTwo, letterThree, letterFour, letterFive, letterSix, letterSeven, letterEight, letterNine, letterTen;
	char numberOne, numberTwo, numberThree, numberFour, numberFive, numberSix, numberSeven, numberEight, numberNine, numberTen;
	char symbolOne, symbolTwo, symbolThree, symbolFour, symbolFive, symbolSix, symbolSeven, symbolEight, symbolNine, symbolTen, symbolEleven;
	string translatedOne, translatedTwo, translatedThree, translatedFour, translatedFive, translatedSix, translatedSeven, translatedEight, translatedNine, translatedTen;
	string translatedString;
	string space = " ";

	// get inputs (check for dashes)
	cin >> letterOne;
	cin >> numberOne;
	cin >> symbolOne;

	if (!checkForDash(symbolOne))
		{
		cin >> letterTwo;
		cin >> numberTwo;
		cin >> symbolTwo;

		if (!checkForDash(symbolTwo))
			{
			cin >> letterThree;
			cin >> numberThree;
			cin >> symbolThree;

			if (!checkForDash(symbolThree))
				{
				cin >> letterFour;
				cin >> numberFour;
				cin >> symbolFour;
				
				if (!checkForDash(symbolFour))
					{
					cin >> letterFive;
					cin >> numberFive;
					cin >> symbolFive;

					if (!checkForDash(symbolFive))							
						{
						cin >> letterSix;
						cin >> numberSix;
						cin >> symbolSix;

						if (!checkForDash(symbolSix))
							{
							cin >> letterSeven;
							cin >> numberSeven;
							cin >> symbolSeven;

							if (!checkForDash(symbolSeven))
								{
								cin >> letterEight;
								cin >> numberEight;
								cin >> symbolEight;

								if (!checkForDash(symbolEight))							
									{
									cin >> letterNine;
									cin >> numberNine;
									cin >> symbolNine;

									if (!checkForDash(symbolNine))
										{
										cin >> letterTen;
										cin >> numberTen;
										cin >> symbolTen;

										}
									}

								}
							}
						}
					}
				}
			}

		}


	// translate the inputs 
		// function : translateInputs
		translatedOne = translateInput (letterOne, numberOne);
	
			if (!checkForDash(symbolOne))
				{
				translatedTwo = translateInput (letterTwo, numberTwo);
			
					if (!checkForDash(symbolTwo))
						{
						translatedThree = translateInput (letterThree, numberThree);
					
							if (!checkForDash(symbolThree))
								{
								translatedFour = translateInput (letterFour, numberFour);

								if (!checkForDash(symbolFour))
									{
									translatedFour = translateInput (letterFour, numberFour);
			
									if (!checkForDash(symbolFive))
										{
										translatedFive = translateInput (letterFive, numberFive);
					
										if (!checkForDash(symbolSix))
											{
											translatedSix = translateInput (letterSix, numberSix);

											if (!checkForDash(symbolSeven))
												{
												translatedSeven = translateInput (letterSeven, numberSeven);

												if (!checkForDash(symbolEight))
													{
													translatedEight = translateInput (letterEight, numberEight);
			
													if (!checkForDash(symbolNine))
														{
														translatedNine = translateInput (letterNine, numberNine);
					
														if (!checkForDash(symbolTen))
															{
															translatedTen = translateInput (letterTen, numberTen);
															
															if (!checkForDash(symbolEleven))
																{
																return ERROR_CODE_TOO_MANY;
																}
															}
														}
			
													}
												}
											}
										}
			
									}
								}
						}
			
				}

	// combine translated strings
	translatedString = translatedOne;
	translatedString += space;

	translatedString += translatedTwo;
	translatedString += space;

	translatedString += translatedThree;
	translatedString += space;

	translatedString += translatedFour;
	translatedString += space;

	translatedString += translatedFive;
	translatedString += space;

	translatedString += translatedSix;
	translatedString += space;

	translatedString += translatedSeven;
	translatedString += space;

	translatedString += translatedEight;
	translatedString += space;

	translatedString += translatedNine;
	translatedString += space;

	translatedString += translatedTen;
	translatedString += space;

	// return complete translated string or error 
	if (translatedOne == ERROR_CODE || translatedTwo == ERROR_CODE || translatedThree == ERROR_CODE || translatedFour == ERROR_CODE || translatedFive == ERROR_CODE ||
	translatedSix == ERROR_CODE || translatedSeven == ERROR_CODE || translatedEight == ERROR_CODE || translatedNine == ERROR_CODE || translatedTen == ERROR_CODE)
	{
	return ERROR_CODE;
	}

	return translatedString;

	}

bool checkForDash (char symbol)
	{
	// if symbol == '-' return true
	// else return false
	if (symbol == '-')
		{
		return true ;
		}
	else 
		{
		return false;
		}
	}

string translateInput (char letter, char number)
	{
	// if list with A's and all available #'s 
	// else if rest of letters with there own else ifs within 
	string translationAone = "ahoy" ;
	string translationAtwo = "avast" ;
	string translationAthree = "arrr" ;

	string translationBone = "matey" ;
	string translationBtwo = "proud beauty" ;
	string translationBthree = "comely wench" ;
	string translationBfour = "scurvy dog" ;
	string translationBfive = "foul blaggart" ;

	string translationCone = "whar b" ;
	string translationCtwo = "know ye" ;
	string translationCthree = "be that" ;
	string translationCfour = "how many leagues to" ;

	string translationDone = "th'" ;
	string translationDtwo = "a briny" ;
	string translationDthree = "some godforsaken" ;
	string translationDfour = "broadside" ;
	string translationDfive = "me" ;
	string translationDsix = "yer" ;

	string translationEone = "barnacle-covered" ;
	string translationEtwo = "comely" ;
	string translationEthree = "grog-filled" ;

	string translationFone = "head" ;
	string translationFtwo = "galley" ;
	string translationFthree = "fleabag inn" ;
	string translationFfour = "market" ;
	string translationFfive = "Skull & Scuppers" ;
	string translationFsix = "buried treasure" ;

	string translationGone = "I be needin' t'" ;
	string translationGtwo = "I've a fierce fire in me belly t'" ;
	string translationGthree = "I be hankerin' t'" ;
	string translationGfour = "me dear ol' mum, bless her black soul, tol' me t'" ;
	string translationGfive = "me mate, ol' Rumpot, wants t'" ;

	string translationHone = "come across" ;
	string translationHtwo = "have a bit of a lie-down" ;
	string translationHthree = "seize all yer doubloons" ;
	string translationHfour = "swill a pint or two o' grog" ;


	if (letter == 'A' || letter == 'a')
		{	
			if (number == '1')
				{
				return translationAone; 
				}
			else if (number == '2')
				{
				return translationAtwo; 
				}
			else if (number == '3')
				{
				return translationAthree; 
				}
			else 
				{
				return ERROR_CODE;
				}
		}
	else if (letter == 'B' || letter == 'b')
		{
			if (number == '1')
				{
				return translationBone; 
				}
			else if (number == '2')
				{
				return translationBtwo; 
				}
			else if (number == '3')
				{
				return translationBthree; 
				}
			else if (number == '4')
				{
				return translationBfour; 
				}
			else if (number == '5')
				{
				return translationBfive; 
				}
			else 
				{
				return ERROR_CODE;
				}
		}
	else if (letter == 'C' || letter == 'c')
		{
			if (number == '1')
				{
				return translationCone; 
				}
			else if (number == '2')
				{
				return translationCtwo; 
				}
			else if (number == '3')
				{
				return translationCthree; 
				}
			else if (number == '4')
				{
				return translationCfour; 
				}
			else 
				{
				return ERROR_CODE;
				}
		}
	else if (letter == 'D' || letter == 'd')
		{
			if (number == '1')
				{
				return translationDone; 
				}
			else if (number == '2')
				{
				return translationDtwo; 
				}
			else if (number == '3')
				{
				return translationDthree; 
				}
			else if (number == '4')
				{
				return translationDfour; 
				}
			else if (number == '5')
				{
				return translationDfive; 
				}
			else if (number == '6')
				{
				return translationDsix; 
				}
			else 
				{
				return ERROR_CODE;
				}
		}
	else if (letter == 'E' || letter == 'e')
		{
			if (number == '1')
				{
				return translationEone; 
				}
			else if (number == '2')
				{
				return translationEtwo; 
				}
			else if (number == '3')
				{
				return translationEthree; 
				}
			else 
				{
				return ERROR_CODE;
				}
		}
	else if (letter == 'F' || letter == 'f')
		{
			if (number == '1')
				{
				return translationFone; 
				}
			else if (number == '2')
				{
				return translationFtwo; 
				}
			else if (number == '3')
				{
				return translationFthree; 
				}
			else if (number == '4')
				{
				return translationFfour; 
				}
			else if (number == '5')
				{
				return translationFfive; 
				}
			else if (number == '6')
				{
				return translationFsix; 
				}
			else 
				{
				return ERROR_CODE;
				}
		}
	else if (letter == 'G' || letter == 'g')
		{
			if (number == '1')
				{
				return translationGone; 
				}
			else if (number == '2')
				{
				return translationGtwo; 
				}
			else if (number == '3')
				{
				return translationGthree; 
				}
			else if (number == '4')
				{
				return translationGfour; 
				}
			else if (number == '5')
				{
				return translationGfive; 
				}
			else 
				{
				return ERROR_CODE;
				}	
		}
	else if (letter == 'H' || letter == 'h')
		{
			if (number == '1')
				{
				return translationHone; 
				}
			else if (number == '2')
				{
				return translationHtwo; 
				}
			else if (number == '3')
				{
				return translationHthree; 
				}
			else if (number == '4')
				{
				return translationHfour; 
				}
			else 
				{
				return ERROR_CODE;
				}	
		}

	else
		{
		return ERROR_CODE;
		}
	
	}

void displayResults( const string &translation)
   {
	// string out "translation" and enter the returns complete translation
	printString ("------------------------------------------------------------------", NO_BLOCK_SIZE, "LEFT");
	printEndLines (endOne);

	printString ("Translation: ", NO_BLOCK_SIZE, "LEFT");
	printString (translation, NO_BLOCK_SIZE, "LEFT");
	printEndLines (endOne);
	printEndLines (endOne);

   }

void printLine(int type)
	{
	if (type == typeDivider)
		{
		printString ("|-------------------------------------------------------------------------|", NO_BLOCK_SIZE, "LEFT");
		}
	else if (type == typePipe)
		{
		printString ("|", NO_BLOCK_SIZE, "LEFT");
		}
	else
		{
		printString ("", GRID_BLOCK_SIZE, "CENTER");
		}
	}
