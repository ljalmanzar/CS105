// Header Files
#include "formatted_console_io_v19.h"
#include <cstring>
#include <ctime>
#include <fstream>

#include <cstdlib>
#include <iostream>
using namespace std;

const char fileName[] = "scores.txt";
const char NULL_CHAR = '\n';

int main ()
{
int scoreArr[10];
char nameArr[10][30];

int ndx = 0;
int ndxTwo = 0;
int checkerNdx = 0;
int columnNdx = 0;
int stringLen;

int score = 30;
char name [30];

ifstream fin;
ofstream fout;

startCurses();

	promptForStringAt (0, 0, " Enter your name: ", name);

stringLen = strlen (name);
name[stringLen+1] = NULL_CHAR; 

cout << scoreArr[0] << endl;
cout << nameArr[0] << endl;
cout << scoreArr[1] << endl;
cout << nameArr[1] << endl;
cout << scoreArr[2] << endl;
cout << nameArr[2] << endl;
cout << scoreArr[3] << endl;
cout << nameArr[3] << endl;
cout << scoreArr[4] << endl;
cout << nameArr[4] << endl;
cout << scoreArr[5] << endl;
cout << nameArr[5] << endl;
cout << scoreArr[6] << endl;
cout << nameArr[6] << endl;
cout << scoreArr[7] << endl;
cout << nameArr[7] << endl;
cout << scoreArr[8] << endl;
cout << nameArr[8] << endl;
cout << scoreArr[9] << endl;
cout << nameArr[9] << endl;

	while (ndx < 10)
		{
			scoreArr [ndx] = 0;
			ndx ++;	
		}

	ndx = 0;
	while (ndx < 10) 
		{
			ndxTwo = 0;
			while (ndxTwo < 30)
				{
					nameArr [ndx][ndxTwo] = ' ';
					ndxTwo++;
				}

			ndx ++;
		} 
	nameArr[9][29] = NULL_CHAR;

fin.clear();
fin.open (fileName);

ndx = 0;
while (fin.good())
{
fin >> scoreArr[ndx];
fin >> nameArr[ndx];
stringLen = strlen (nameArr[ndx]);
nameArr [ndx][stringLen+1] = NULL_CHAR;
ndx++;
}

fin.close();
/*
	// if array is not full enter in next available spot
	if (scoreArr [9] == 0)
      {
		// find first available spot
		while (scoreArr [checkerNdx] != 0)
			{
				checkerNdx ++;
			}

		// assign new score to the first found open spot
		scoreArr [checkerNdx] = score;

		// save new name to the name array
		nameArr [checkerNdx][columnNdx] = ',';
		columnNdx ++;

		while (name [columnNdx-1] != NULL_CHAR)
			{
				nameArr [checkerNdx][columnNdx] = name [columnNdx-1];
				columnNdx ++;
			}
		nameArr [checkerNdx][columnNdx] = NULL_CHAR;
	  }
*/

fout.open (fileName);
	ndx = 0;
	ndxTwo = 0;
	// compare score to all other scores and insert it into proper position
	if (scoreArr [9] == 0)
		{
			// find first available spot
			while (scoreArr [checkerNdx] != 0)
				{
					checkerNdx ++;
				}

			while (ndx < 10)
				{
					if ( score > scoreArr [ndx])
						{
							ndxTwo = checkerNdx;
							// move the scores accordingly
							while (ndxTwo > ndx )
								{
									scoreArr [ndxTwo] = scoreArr [ndxTwo - 1];
									ndxTwo --;
								}

							scoreArr [ndx] = score;
							
							// move the names in the array according to match with their scores
							ndxTwo = checkerNdx;
							while (ndxTwo > ndx )
								{
									columnNdx = 0;
									while (nameArr [ndxTwo-1][columnNdx] != NULL_CHAR)
										{
											nameArr [ndxTwo][columnNdx] = nameArr [ndxTwo-1][columnNdx];	
											columnNdx ++;
										}
		
									nameArr [ndxTwo-1][columnNdx] = NULL_CHAR;
									ndxTwo --;
								}
							// insert new name
							columnNdx = 0;
							nameArr[ndx][columnNdx]=',';
							columnNdx++;
							while (name [columnNdx-1] != NULL_CHAR)
								{
									nameArr [ndx][columnNdx] = name [columnNdx-1];
									columnNdx++;
								}
							name [columnNdx] = NULL_CHAR;

							// end search
							ndx = 10;
						}
					ndx ++;
				}

			ndx = 0;
			// insert everything into file
			while (scoreArr [ndx] != 0)
			{
			fout << scoreArr [ndx] << nameArr[ndx] << endl;
			ndx++;
			}
		}
cout << "WTF" << endl;

cout << scoreArr[0] << endl;
cout << nameArr[0] << endl;
cout << scoreArr[1] << endl;
cout << nameArr[1] << endl;
cout << scoreArr[2] << endl;
cout << nameArr[2] << endl;
cout << scoreArr[3] << endl;
cout << nameArr[3] << endl;
cout << scoreArr[4] << endl;
cout << nameArr[4] << endl;
cout << scoreArr[5] << endl;
cout << nameArr[5] << endl;
cout << scoreArr[6] << endl;
cout << nameArr[6] << endl;
cout << scoreArr[7] << endl;
cout << nameArr[7] << endl;
cout << scoreArr[8] << endl;
cout << nameArr[8] << endl;
cout << scoreArr[9] << endl;
cout << nameArr[9] << endl;

system("pause");


	//prime
	ndx = 0;
	ndxTwo = 0;
	// compare score to all other scores and insert it into proper position
	if (scoreArr [9] != 0)
		{
			while (ndx < 10)
				{
					if ( score > scoreArr [ndx])
						{
							// move the scores accordingly
							ndxTwo = 10 - 1;
							while (ndxTwo > ndx )
								{
									scoreArr [ndxTwo] = scoreArr [ndxTwo - 1];
									ndxTwo --;
								}

							scoreArr [ndx] = score;
							
							// move the names in the array according to match with their scores
							ndxTwo = 10 - 1;
							while (ndxTwo > ndx )
								{
									columnNdx = 0;
									while (nameArr [ndxTwo-1][columnNdx] != NULL_CHAR)
										{
											nameArr [ndxTwo][columnNdx] = nameArr [ndxTwo-1][columnNdx];	
											columnNdx ++;
										}
		
									nameArr [ndxTwo-1][columnNdx] = NULL_CHAR;
									ndxTwo --;
								}
							// insert new name
							columnNdx = 0;
							nameArr[ndxTwo][columnNdx]=',';
							columnNdx++;
							while (name [columnNdx-1] != NULL_CHAR)
								{
									nameArr [ndxTwo][columnNdx] = name [columnNdx-1];
									columnNdx++;
								}
							name [columnNdx] = NULL_CHAR;

							// end search
							ndx = 10;
						}
						ndx ++;
				}

			ndx = 0;
			// insert everything into file
			while (ndx < 10)
			{
			fout << scoreArr [ndx] << nameArr[ndx] << endl;
			ndx++;
			}
		}



fout.close();

cout << "SHIT FUCK`";

cout << scoreArr[0] << endl;
cout << nameArr[0] << endl;
cout << scoreArr[1] << endl;
cout << nameArr[1] << endl;
cout << scoreArr[2] << endl;
cout << nameArr[2] << endl;
cout << scoreArr[3] << endl;
cout << nameArr[3] << endl;
cout << scoreArr[4] << endl;
cout << nameArr[4] << endl;
cout << scoreArr[5] << endl;
cout << nameArr[5] << endl;
cout << scoreArr[6] << endl;
cout << nameArr[6] << endl;
cout << scoreArr[7] << endl;
cout << nameArr[7] << endl;
cout << scoreArr[8] << endl;
cout << nameArr[8] << endl;
cout << scoreArr[9] << endl;
cout << nameArr[9] << endl;

endCurses();
system ("pause");
return 0;	
}

