#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int get_gcd(int num, int denom);
int get_int(string prompt);
bool is_int(string num);
bool reduce_fraction(int &numerator, int &denominator);

/***********************************************************************************
**  Program: fraction.cpp
**  Author: Jacob Reger
**  Date: 11/11/2019
**  Description: This program has the goal of taking in a fraction and reducing it
**  as much as possible.
**  Input: main will take the only inputs being the numerator and denominator
**  Output: Outputs of main are simply written prompts and the reduced fraction.
***********************************************************************************/

int main(){

   string again;
   
   do{
      int numerator;
      int denominator;

      string num;
      cout << endl;
      cout << "Please enter a numerator: ";
      
      getline(cin, num);

      cout << endl;

      while(is_int(num) == false){
	 cout << "Invalid input! Please enter a whole number numerator: ";
	 getline(cin, num);
	 cout << endl;
      }
      string denom;
      cout << "Please enter a denominator: ";
      getline(cin, denom);

      cout << endl;

      numerator = get_int(num);
      denominator = get_int(denom);

      while(reduce_fraction(numerator, denominator) == false){
	 cout << "Invalid input! Please enter a whole, non-zero denominator: ";
	 getline(cin, denom);


	 cout << endl;
	 denominator = get_int(denom);
      }

      while(is_int(denom) == false){
	 cout << "Invalid input! Please enter a whole number denominator: ";
	 getline(cin, denom);
	 cout << endl;
      }

      if(denominator < 0){
	 denominator *= -1;
	 if(denominator == 1)
	    cout << "Your reduced fraction is: -" << numerator << endl;
	 else
	    cout << "Your reduced fraction is: -" << numerator << "/" << denominator << endl;
      }else if(denominator == 1)
	 cout << "Your reduced fraction is: " << numerator << endl;
      else
	 cout << "Your reduced fraction is: " << numerator << "/" << denominator << endl;

      cout << endl;
      cout << "Would you like to reduce another fraction (yes or no): ";
      getline(cin, again);
   }
   while(again == "yes");
   return 0;
}

/***********************************************************************************
**  Function: reduce_fraction
**  Description: Will reduce the fraction numerator and denominator by the GCD,
**  which it gets from the get_gcd function.
**  Parameters: int &numerator, int &denominator
**  Pre-conditions: Take in two reference integers.
**  Post-conditions: Return a boolean value after changing the referenced values by
**  dividing them by their GCD.
***********************************************************************************/

bool reduce_fraction(int &numerator, int &denominator){

   cout << "" << endl;

   if(denominator == 0)
      return false;
   if(numerator < 0 && denominator < 0){
      numerator *= -1;
      denominator *= -1;
   }
   
   int gcd = get_gcd(numerator, denominator);
   numerator = numerator / gcd;
   denominator = denominator / gcd;
   return true;
   
}


/***********************************************************************************
**  Function: get_gcd
**  Description: Will test for the greatest common divisor to the parameters and
**  return it.
**  Parameters: int num, int denom
**  Pre-conditions: Take in two integer inputs and calculate their GCD.
**  Post-conditions: Return the GCD.
***********************************************************************************/

int get_gcd(int num, int denom){

   cout << "";
   int gcd;

   if((num < 0 || denom < 0) && (num > 0 || denom > 0)){
   
      if(num < 0)
	 num *= -1;
      if(denom < 0)
	 denom *= -1;
   }

   for(int i = 1; i <= num && i <= denom; i++){
   
      if(num % i == 0 && denom % i == 0){ 
	 gcd = i;
      }
   }
   return gcd;

}

/***********************************************************************************
**  Function: get_int
**  Description: Takes in a string and tests if that string is an 
**  integer. If it is an integer, it will return the provided integer.
**  Parameters: string prompt
**  Pre-conditions: Prompt the user to input a string, then checks if the string
**  is an integer.
**  Post-conditions: Returns the given integer if the string is indeed an integer.
***********************************************************************************/

int get_int(string prompt){

   cout << "";
   int answer = 0;
   int x = 1;
   if(is_int(prompt) == 1){
   
      if(prompt.at(0) == 45){
	 x = -1;
	 for(int j = 1; j < prompt.length(); j++){
	 
	    answer += (prompt.at(j) - 48) * pow(10, prompt.length() - 1 - j);
	 }
      }
      else{
      
	 for(int i = 0; i < prompt.length(); i++){
	 
	    answer += (prompt.at(i) - 48) * pow(10, prompt.length() - 1 - i);
	 }
      }
      return x * answer;
   }
}

/***********************************************************************************
**  Function: is_int
**  Description: Will test if a given string is an integer or not.
**  Parameters: string num
**  Pre-conditions: Take in a string and test whether or not it is an integer. 
**  Post-conditions: Return a boolean value to represent whether the string is      
**  indeed an integer or not.
***********************************************************************************/

bool is_int(string num){

   cout << "";

   if(num.at(0) != 45 && (num.at(0) > 57 || num.at(0) < 48))

      return 0;
   for(int i = 1; i < num.length(); i++){

     
     if(num.at(i) > 57 || num.at(i) < 48){

	 return 0;
      }

   }
   return 1; 
}

