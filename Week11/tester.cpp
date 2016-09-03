// Header Files
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Global Constants

// Function Prototypes

// Main Program
int main ()
   {
	int ndx;
	int num;
	int count = 0;
	int temp[50]; 
	int binary;
	int newBit;

cin >> num;
		
		while(num != 0) 
			{ 
			  if(num % 2 == 0) 
			  { 
			   temp[count] = 0; 
			  } 
			  else 
			  { 
			   temp[count] = 1; 
			  } 
		
				num = num / 2;

				count ++;
			}


		binary = temp [count-1];
		count = count - 2;


		while (count >= 0)
			{
				newBit = temp[count];

				binary = binary * 10;

				binary = binary + newBit;

				count --;
			}

			cout << binary;
	
	system ("pause");
	return 0;
	}

// Function Implementation
