// header files
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

// global constants

void getFileNames (string &inputFile, string &outputFile);

// main program 
int main ()
   {
	ifstream encodedFile;
	ofstream outputFile;
	string encodedFileString;
	string outputFileString;
	int evenInt;
	char decodedPart;

int number;
int nextnum;
char space = '32';

	// show title
		//function : showTitle

	// get files

		// get encoded file 
		// get file to output to
			// function : getFileNames
			getFileNames(encodedFileString,outputFileString);

			// open files
			encodedFile.open (encodedFileString.c_str());

			encodedFile >> number;
			encodedFile >> nextnum;

			cout << "hi" << space;
			cout << "bye";


	
	// end
	system ("pause");

	return 0;
	}

void getFileNames (string &inputFile, string &outputFile)
   {
	// get file names as string
	cout << "Enter input file name: ";
	cin >> inputFile;
	cout << endl;

	cout << "Enter output file name: ";
	cin >> outputFile;
	cout << endl;

	// open file into the corresponding variable 
	}

