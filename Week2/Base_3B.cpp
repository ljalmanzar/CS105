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

       // formatted console initialization
          // function: startCurses
       startCurses();
 
    ////////////////////////////////////////////////////////////////////////////
    // Remove this comment block and place necessary code here
    ////////////////////////////////////////////////////////////////////////////

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



