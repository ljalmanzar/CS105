// Header Files
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "formatted_cmdline_io_v10.h"
using namespace std;
// Global Constants

// Function Prototypes
void getshit (char arr[][20]);

// Main Program
int main ()
   {
	
char myArr [20][20];

	getshit (myArr);

		cout << endl;
		cout << myArr[1] << " ";
		cout << myArr[2] << endl << endl;

system ("pause");
return 0;

	}

// Function Implementation
void getshit (char arr[][20])
{
 	promptForString ("first: ", arr[1]);
	cout << endl;

	
	promptForString ("second: ", arr[2]);
}
