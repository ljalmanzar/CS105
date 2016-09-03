// Header files
#include "formatted_console_io_v19.h"

using namespace std;

// Global Constants
const char ASTERISK = '*';

// Global Function Prototypes
   // none required

// main function/program
int main()
   {
    // program initialization

       // variable initialization
		int XCENTER = SCRN_MAX_X / 2;
		int YCENTER = SCRN_MAX_Y / 2 - 7; 

       // formatted console initialization
          // function: startCurses
       startCurses();
 
	//output line 1
	printStringAt( XCENTER, YCENTER, "***********", "CENTER" );
	YCENTER++;

	//output line 2
	printStringAt( XCENTER, YCENTER, "***********", "CENTER" );
	YCENTER++;

	//output line 3
	printStringAt( XCENTER, YCENTER, "***** *****", "CENTER" ); 
	YCENTER++;

	//output line 4
	printStringAt( XCENTER, YCENTER, "****   ****", "CENTER" );
	YCENTER++;

	//output line 5
	printStringAt( XCENTER, YCENTER, "***     ***", "CENTER" );
	YCENTER++;

	//output line 6
	printStringAt( XCENTER, YCENTER, "**       **", "CENTER" );
	YCENTER++;

	//output line 7
	printStringAt( XCENTER, YCENTER, "*         *", "CENTER" );
	YCENTER++;

	//output line 8
	printStringAt( XCENTER, YCENTER, "**       **", "CENTER" );
	YCENTER++;

	//output line 9
	printStringAt( XCENTER, YCENTER, "***     ***", "CENTER" );
	YCENTER++;

	//output line 10
	printStringAt( XCENTER, YCENTER, "****   ****", "CENTER" );
	YCENTER++;

	//output line 11
	printStringAt( XCENTER, YCENTER, "***** *****", "CENTER" );
	YCENTER++;

	//output line 12
	printStringAt( XCENTER, YCENTER, "***********", "CENTER" );
	YCENTER++;

	//output line 13
	printStringAt( XCENTER, YCENTER, "***********", "CENTER" );

    // End program

       // hold the program
          // function: printStringAt, waitForInput
       printStringAt( SCRN_MAX_X, SCRN_MAX_Y, 
                                  "Press any key to continue . . . ", "RIGHT" );
       waitForInput( FIXED_WAIT );

       // end curses
          // function: endCurses
       endCurses();

       // return success
       return 0;

   }  //  end of main function

// Supporting Function Implementations

   // none



