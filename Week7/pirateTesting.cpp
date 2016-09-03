#include <iostream>
#include <cstdlib>
using namespace std;

char letterOne, letterTwo, letterThree, letterFour, letterFive, letterSix, letterSeven, letterEight, letterNine, letterTen;
char numberOne, numberTwo, numberThree, numberFour, numberFive, numberSix, numberSeven, numberEight, numberNine, numberTen;
char symbolOne, symbolTwo, symbolThree, symbolFour, symbolFive, symbolSix, symbolSeven, symbolEight, symbolNine, symbolTen;
string translatedOne, translatedTwo, translatedThree, translatedFour, translatedFive, translatedSix, translatedSeven, translatedEight, translatedNine, translatedTen;
string finalTranslation;

//functions
bool checkForDash(char symbol);

string translateInput (char letter, char number);

char getInputs ();


// main
int main ()
{
	string translatedString;

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

	translatedString += translatedTwo;

	translatedString += translatedThree;

	translatedString += translatedFour;

	translatedString += translatedFive;

	translatedString += translatedSix;

	translatedString += translatedSeven;

	translatedString += translatedEight;

	translatedString += translatedNine;

	translatedString += translatedTen;

cout << letterOne;


cout << translatedString;





	system ("pause");
return 0;
}


bool checkForDash (char symbol)
{
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

	string ERROR_CODE = "ERROR - Incorrect code entry, please try again!";

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

