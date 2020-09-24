#include <iostream>

using namespace std;

/***********************************************************************************
**  Function: a_to_i
**  Description: Turns a character into its decimal value.
**  Parameters: char character
**  Pre-Conditions: The input is a character.
**  Post-Conditions: Returned the decimal value of the character.
***********************************************************************************/

int a_to_i(char character){

   return int(character);
}

/***********************************************************************************
**  Function: i_to_a
**  Description: Turns a decimal value into its character.
**  Parameters: int decimal
**  Pre-Conditions: The input is an integer.
**  Post-Conditions: Returned the character associated with that decimal value.
***********************************************************************************/

char i_to_a(int decimal){

   return char(decimal);
}

int main(){

   cout << endl;
   char input;
   cout << "Testing a_to_i function. Please input a character to be converted to a decimal value: ";
   cin >> input;
   cout << endl;
   cout << "The decimal value of the character you entered is: " << a_to_i(input) << endl;
   cout << endl;

   // Testing i_to_a
  
   cout << endl;
   int input2;
   cout << "Testing i_to_a function. Please input a decimal value to be converted to a character: ";
   cin >> input2;
   cout << endl;
   cout << "The character associated to the value you entered is: " << i_to_a(input2) << endl;
   cout << endl;
   return 0;
}
