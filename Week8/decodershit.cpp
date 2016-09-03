#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
/*
Name: getEven
Process: looks for even ints in the encoded file
Function Input/parameters: the encoded file 
Function Output/parameters: none
Function Output/Return: the number (int)
Device Input: none
Device Output/Monitor: none
Dependencies: iostream I/O tools
*/
int getEven (const string &inputFile);


if (decoded part = 

int getEven (const string &inputFile)
   {
	//initialize
	ifstream encodedFile;
	encodedFile.open (inputFile.c_str());
	int number;

	// get the int
	while (encodedFile.good())
		{
		encodedFile >> number;

		if (number%2 == 0)
			{
			return number;
			}
		
		}

	}
