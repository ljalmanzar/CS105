/*/////////////////////////////////////////////////////////////////////////

    Program:             Lab5Activity.cpp
    Author:              Michael Leverington
    Update By:           n/a
    Description:         Lab Activity - Week 4
                         

    Program Written:     01/22/2009
    Most Recent Update:  01/22/2009 - 12:00 a.m.
    Date Due for Review: 01/22/2009 

/////////////////////////////////////////////////////////////////////////*/

/*
INSTRUCTIONS:

    None

END OF INSTRUCTIONS
*/
//
//  Header Files  /////////////////////////////////////////////////////////
//
    #include <iostream>
	#include <cstdlib>
    
    using namespace std;
//
//  Global Constant Definitions  //////////////////////////////////////////
//
    // none
//
//  Global Function Prototypes  ///////////////////////////////////////////
//

bool isLetter (char testCharOne);

bool isLowerCaseLetter (char testCharTwo);

bool isUpperCaseLetter (char testCharThree);

//
//  Main Program Definition  //////////////////////////////////////////////
//
int main()
   {
    // initialize program

       // variable initialization
       char someChar;
 
    // prompt user for character (someChar) using cout, cin
	cout << "Insert Character : ";
	cin >> someChar;

    // test and report lower case letter
    if( isLowerCaseLetter( someChar ) )
       {
        // report that it is a lower case letter
        cout << endl << endl;
        cout << "Letter " << someChar 
             << " is a lower case letter." << endl << endl;
       }
    else
       {
        // report that it is not a lower case letter
        cout << endl << endl;
        cout << "Letter " << someChar 
             << " is not a lower case letter." << endl << endl;
       }

    // test and report lower case letter
    if( isUpperCaseLetter( someChar ) )
       {
        // report that it is an upper case letter
        cout << endl << endl;
        cout << "Letter " << someChar 
             << " is an upper case letter." << endl << endl;
       }
    else
       {
        // report that it is not an upper case letter
        cout << endl << endl;
        cout << "Letter " << someChar 
             << " is not an upper case letter." << endl << endl;
       }
      
    // Close program
       // hold program
       system( "pause" );

       // return success
       return 0;
   }

//  Supporting Function Implementation


bool isLowerCaseLetter (char someChar)
   {
	if (someChar >= 'a' && someChar <= 'z')
		{return true;
		}
	else 
		{return false;
		}
	}

bool isLetter (char someChar)
   {
	if ((someChar <= 'A' && someChar <= 'Z') || (someChar >= 'a' && someChar <= 'z'))
		{return true;
		}
	else 
		{return false;
		}
	}

bool isUpperCaseLetter (char testCharOne)
   { 
	if (isLetter
	
	return 0; 
	}
