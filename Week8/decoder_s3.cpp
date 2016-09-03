// header files

// global constants

//function prototype

/*
Name: showTitle
Process: shows title
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the title
Dependencies: iostream I/O tools
*/
void showTitle ();

/*
Name: getFileNames
Process: takes strings from programs and adds the text files to them
Function Input/parameters: the input file names (string)
Function Output/parameters: the text tiles 
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
void getFileNames (string &inputFile, string &outputFile);

/*
Name: checkForValidFile 
Process: takes in the input file .txt and checks if it was accessed correctly
Function Input/parameters: the input file (string)
Function Output/parameters: none
Function Output/Return: true or false
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
bool checkForValidFile (string inputFile);

/*
Name: showErrorMessage
Process: prints error message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void showErrorMessage ();

/*
Name: showProcessingMessage
Process: print the "processing" message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void showProcessingMessage ();

/*
Name: findEven
Process: looks for even ints in the encoded file
Function Input/parameters: the encoded file 
Function Output/parameters: none
Function Output/Return: the number (int)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
int findEven (string inputFile);

/*
Name:extractChar
Process: takes the in from findEven and transfers it to a character 
Function Input/parameters: the int from file
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
char extractChar (int number);

/*
Name: endProcessingMessage
Process: shows the completed message
Function Input/parameters: none
Function Output/parameters: none
Function Output/Return: none
Device Input: none
Device Output/Monitor: the message
Dependencies: iostream I/O tools
*/
void endProcessingMessage ();




// main program 
int main ()
   {
	// show title
		//function : showTitle

	// get files

		// get encoded file 
			// function : getFileNames

		// get file to output to
			// function : getFileNames
 
		// check if open correctly
				// function : checkForValidFile

					// if return false print Error and end program
						// function : showErrorMessage
	
		// show "processing" 
			// function : showProcessingMessage

	// decrypt the file

		// check for even int
			// function : findEven

		// if 5 chars long take first 2 numbers, if 6 chars long take first 3
			// function : extractChar

		// take the corresponding #s and convert to appropriate char 

	// insert decryption into given output file
		
		// function : insertToFile

		// show "finish processing" message
			//function : endProcessingMessage
	
	// end

	return 0;
	}

//function inplementation
void showTitle ()
   {
	return 0; // temp stub
	}

void getFileNames (string &inputFile, string &outputFile)
   {
	return 0; // temp stub
	}

bool checkForValidFile (string inputFile)
   {
	return 0; // temp stub
	}

void showErrorMessage ()
   {
	return 0; // temp stub
	}

void showProcessingMessage ()
   {
	return 0; // temp stub
	}

int findEven ()
   {
	return 0; // temp stub
	}

char extractChar (int number)
   {
	return 0; // temp stub
	}

void endProcessingMessage ()
   {
	return 0; // temp stub
	}
