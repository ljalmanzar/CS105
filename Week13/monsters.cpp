#include "formatted_console_io_v19.h" 
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	startCurses();
	char monsterGrid[24][80];
	int i = 0;
	int indexR = 0;
	int indexC = 0;
	while( indexR < 24 )
		{
			indexC = 0;
			while( indexC < 80 )
				{
					monsterGrid[indexR][indexC] = ' ';
					indexC++;
				}
			indexR++;
		}
	while( i < 10 )
	{
		int Xspot = rand() % 75;
		int Yspot = rand() % 20;
		
		if( monsterGrid[Yspot][Xspot] != 'm' && monsterGrid[Yspot][Xspot+1] != 'm' && monsterGrid[Yspot+1][Xspot] != 'm' && monsterGrid[Yspot+1][Xspot+1] != 'm' && 
			monsterGrid[Yspot+2][Xspot] != 'm' && monsterGrid[Yspot+2][Xspot+1] != 'm')		
			{
				printCharAt( Xspot, Yspot, '*' );
				monsterGrid[Yspot][Xspot] = 'm';
			
				printCharAt( Xspot+1, Yspot, '*' );
				monsterGrid[Yspot][Xspot+1] = 'm';
			
		
				
			
				printCharAt( Xspot, Yspot+1, '*' );
				monsterGrid[Yspot+1][Xspot] = 'm';
		
				printCharAt( Xspot+1, Yspot+1, '*' );
				monsterGrid[Yspot+1][Xspot+1] = 'm';
			
				
			
				printCharAt( Xspot, Yspot+2, '*' );
				monsterGrid[Yspot+2][Xspot] = 'm';
		
				printCharAt( Xspot+1, Yspot+2, '*' );
				monsterGrid[Yspot+2][Xspot+1] = 'm';
			}

		i = waitForInput(5);
	}

	return 0;
}	
