#include <iostream>

using namespace std;

void fractal(int n, int col);

/***********************************************************************************
**  Program: fractal.cpp
**  Author: Jacob Reger
**  Date: 11/11/2019
**  Description: This program has the goal of displaying a fractal pattern based on
**  user inputs of their requested max number of stars and their requested shift to
**  the right.
**  Input: main will be the only function to take input from the user. This will be
**  the integers stars and columns.
**  Output: Outputs of main are simply written prompts for the inputs, and the 
**  output of fractal will be the requested fractal design.
***********************************************************************************/

int main(){

   int stars = 0;
   int columns = 0;

   cout << "Enter the number of stars you wish to have: ";
   cin >> stars;

   cout << "Enter the shift you would like: ";
   cin >> columns;

   fractal(stars, columns);

   return 0;
}

/***********************************************************************************
**  Function: fractal
**  Description: Will display a fractal that has n stars and is shifted col columns
**  to the right.
**  Parameters: int n, int col
**  Pre-conditions: Take in a positive odd integer n and a positive integer col.
**  Post-conditions: PRint a fractal based on n star count and col shift.
***********************************************************************************/

void fractal (int n, int col){
   if(n >= 1){   
      fractal(n-2, col + 2);
      for(int i = 0; i < col; i++)
	 cout << " ";
      for(int i = 0; i < n; i++)
	 cout << "* ";
      cout << endl;
      fractal(n - 2, col + 2);
   }
}
