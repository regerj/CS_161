#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

/***********************************************************************************
**  Program: Assignment_2.cpp
**  Author: Jacob Reger
**  Date: 10/27/2019
**  Description: This program has the goal of testing self made implimentations
**  of functions often used in error handling. Each will be coded as a stand alone
**  function and then called on to be tested in the main. 
**  Input: get_int function will be the only function to take an input from the user
**  to test if it is a valid integer, and return the provided integer.
**  Output: Outputs of the following functions will be a test and fail analysis with
**  expected values alongside actual values and whether or not the function behaved
**  as intended.
***********************************************************************************/

/***********************************************************************************
**  Function: check_range
**  Description: Will test whether the provided number is in the specified range.
**  Parameters: int lower_bound, int upper_bound, int test_value
**  Pre-conditions: Take in a lower and upper bound as well as a number to test if
**  it is within the given bounds.
**  Post-conditions: Return a boolean value to represent if the number is indeed
**  within the given bounds.
***********************************************************************************/

bool check_range(int lower_bound, int upper_bound, int test_value){

   if(test_value < upper_bound && test_value > lower_bound)
   	return true;
   else 
        return false;
}

/***********************************************************************************
**  Function: is_capital
**  Description: Will test whether a given character is a capital letter.
**  Parameters: char letter
**  Pre-conditions: Take in a single character input and test whether or not it is a
**  captial letter or not.
**  Post-conditions: Return a boolean value to represent if the character is indeed 
**  a capital or not.
***********************************************************************************/

bool is_capital(char letter){

   if (letter >= 65 && letter <= 90)
      return true;
   else 
      return false;
}

/***********************************************************************************
**  Function: is_even
**  Description: Will test whether a given integer is an even number.
**  Parameters: int num
**  Pre-conditions: Take in a single integer input and test whether or not it is 
**  even or not.
**  Post-conditions: Return a boolean value to represent if the integer is indeed   
**  even or not.
***********************************************************************************/

bool is_even(int num){

   if(num % 2 == 0)
      return 1;
   else
      return 0;
}

/***********************************************************************************
**  Function: is_odd
**  Description: Will test whether a given integer is an odd number.
**  Parameters: int num
**  Pre-conditions: Take in a single integer input and test whether or not it is 
**  odd or not.
**  Post-conditions: Return a boolean value to represent if the integer is indeed   
**  odd or not.
***********************************************************************************/

bool is_odd(int num){

   if(num % 2 == 1)
      return 1;
   else
      return 0;
}

/***********************************************************************************
**  Function: equality_test
**  Description: Will test the equality or inequality of two integers.
**  Parameters: int num1, int num2
**  Pre-conditions: Take in two integers and determine whether the first is greater 
**  than, equal to, or less than the second.
**  Post-conditions: Return an integer -1 if the first integer is less than the     
**  second, an integer 0 if they are equal, and an integer 1 if the first integer is
**  greater than the second.
***********************************************************************************/

int equality_test(int num1, int num2){

   if (num1 < num2)
      return (-1);
   else if (num1 == num2)
      return 0;
   else 
      return 1;
}

/***********************************************************************************
**  Function: float_is_equal
**  Description: Will test if two numbers are eual to each other within a certain   
**  precision.
**  Parameters: float num1, float num2, float precision
**  Pre-conditions: Take in two float numbers and a level of precision and will test
**  if the two numbers are equal to each other rounded to the level of precision    
**  specified.
**  Post-conditions: Return a boolean value representing whether the two numbers are
**  equal.
***********************************************************************************/

bool float_is_equal(float num1, float num2, float precision){

   int count1 = 0;
   float num_1 = num1;
   while (num_1 > 1){
   
      num_1 = num_1 * pow(10, -1);
      count1++;    
   }

   int count2 = 0;
   float num_2 = num2;
   while (num_2 > 1){
   
      num_2 = num_2 * pow(10, -1);
      count2++;
   }
   
   for(int i = 0; i < (precision - count1); i++){
   
      num1 *= 10;
   }

   for(int j = 0; j < (precision - count2); j++){
   
      num2 *= 10;
   }

   if(int(num1) == int(num2))
      return true;
   else
      return false;
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

   if(num.at(0) != 45 && (num.at(0) > 57 || num.at(0) < 48))

      return 0;
   for(int i = 1; i < num.length(); i++){

     
     if(num.at(i) > 57 || num.at(i) < 48){

	 return 0;
      }

   }
   return 1; 
}

/***********************************************************************************
**  Function: numbers_present
**  Description: Will test if the given string contains numbers.
**  Parameters: string sentence
**  Pre-conditions: Take in a string and test if there are numbers present. 
**  Post-conditions: Return a boolean value to represent if a number was found.
***********************************************************************************/

bool numbers_present(string sentence){

   for(int i = 0; i < sentence.length(); i++){

      if(sentence.at(i) <= 57 && sentence.at(i) >= 48){

	 return 1;
      }
   }
   return 0;
}

/***********************************************************************************
**  Function: letters_present
**  Description: Will test if the given string contains letters.
**  Parameters: string sentence
**  Pre-conditions: Take in a string and test if there are letters present. 
**  Post-conditions: Return a boolean value to represent if a letter was found.
***********************************************************************************/

bool letters_present(string sentence){

   for(int i = 0; i < sentence.length(); i++){

      if(sentence.at(i) <= 122 && sentence.at(i) >= 65){

	 return 1;
      }
   }
   return 0;
}

/***********************************************************************************
**  Function: contains_sub_string
**  Description: Will test if the given string contains a given substring.
**  Parameters: string sentence, string sub_string
**  Pre-conditions: Take in a string and test if the given substring is present. 
**  Post-conditions: Return a boolean value to represent if the given substring
**  was found.
***********************************************************************************/

bool contains_sub_string(string sentence, string sub_string){


   //string substring = "Daisy";
   //string string = "Driving Miss Daisy";

   //int x = 0;
   int e = 0;

   for(int i = 0; i < sentence.length(); i++){
   
      //cout << "i is currently equal to " << i << endl;
      if(sentence.at(i) == sub_string.at(e)){
      
	 //cout << "Found an instance of the start of substring at " << i << endl;
	 if(e == sub_string.length() - 1){
	 
	    return 1;
	    //x = 1;
	    //cout << "Substring found at i: " << i << endl;
	 }else{
	 
	    e++;

	 }


      }else{
      
	 e = 0;
      }
   }
   return 0;
}

/***********************************************************************************
**  Function: word_count
**  Description: Will test a given string to determine how many words are present.
**  Parameters: string sentence
**  Pre-conditions: Take in a string and test how many words are present. 
**  Post-conditions: Return an integer to represent the number of words present.
***********************************************************************************/

int word_count(string sentence){

   int j = 1;
   for(int i = 0; i < sentence.length(); i++){

      if(sentence.at(i) == 32){

	 j += 1;
      }
   }
   return j;

}

/***********************************************************************************
**  Function: to_upper
**  Description: Capitalizes all letters in a given string and leaves non-letter
**  characters unchanged.
**  Parameters: string sentence
**  Pre-conditions: Take in a string and capitalizes only the letters. 
**  Post-conditions: Return a string containing the original sentence with all 
**  letters capitalized and all numbers left the same.
***********************************************************************************/

string to_upper(string sentence){

   for(int i = 0; i < sentence.length(); i++){
   
      if(sentence.at(i) >= 97 && sentence.at(i) <= 122){
      
	 sentence.at(i) = sentence.at(i) - 32;
      }
   }

   return sentence;
}

/***********************************************************************************
**  Function: to_lower
**  Description: Lowercase all letters in a given string and leaves non-letter
**  characters unchanged.
**  Parameters: string sentence
**  Pre-conditions: Take in a string and lowercase only the letters. 
**  Post-conditions: Return a string containing the original sentence with all 
**  letters lowercased and all numbers left the same.
***********************************************************************************/

string to_lower(string sentence){

   for(int i = 0; i < sentence.length(); i++){
   
      if(sentence.at(i) >= 65 && sentence.at(i) <= 90){
      
	 sentence.at(i) = sentence.at(i) + 32;
      }
   }

   return sentence;
}

/***********************************************************************************
**  Function: get_int
**  Description: Prompts the user for a string, and tests if that string is an 
**  integer. If it is an integer, it will return the provided integer.
**  Parameters: string prompt
**  Pre-conditions: Prompt the user to input a string, then checks if the string
**  is an integer.
**  Post-conditions: Returns the given integer if the string is indeed an integer.
***********************************************************************************/

int get_int(string prompt){

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
   }else {
   }
}

int main(){

   // Testing check_range

   cout << "Testing check_range on if the integer 4 is within the bounds of 2 and 6" << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << check_range(2, 6, 4) << endl;
   (check_range(2, 6, 4) == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing check_range on if the integer 6 is within the bounds of 2 and 4" << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << check_range(2, 4, 6) << endl;
   (check_range(2, 4, 6) == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing is_captial

   cout << "Testing is_capital on if the character T is a captial letter or not." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << is_capital('T') << endl;
   (is_capital('T') == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing is_capital on if the character a is a captial letter or not." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << is_capital('a') << endl;
   (is_capital('a') == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;
   
   // Testing is_even

   cout << "Testing is_even on if the integer 10 is an even number." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << is_even(10) << endl;
   (is_even(10) == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing is_even on if the integer 7 is an even number." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << is_even(7) << endl;
   (is_even(7) == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing is_odd

   cout << "Testing is_odd on if the integer 13 is an odd number." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << is_odd(13) << endl;
   (is_odd(13) == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing is_odd on if the integer 12 is an odd number." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << is_odd(12) << endl;
   (is_odd(12) == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing equality_test

   cout << "Testing equality_test on whether 5 is greater than 3." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << equality_test(5, 3) << endl;
   (equality_test(5, 3) == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing equality_test on wheter 3 is less than 5." << endl;
   cout << "Expected: -1" << endl;
   cout << "Actual: " << equality_test(3, 5) << endl;
   (equality_test(3, 5) == -1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing equality_test on whether 4 is equal to 4." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << equality_test(4, 4) << endl;
   (equality_test(4, 4) == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing float_is_equal

   cout << "Testing float_is_equal on whether 2.1756 is equal to 2.1753 at a precision level of 4." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << float_is_equal(2.1756, 2.1753, 4) << endl;
   (float_is_equal(2.1756, 2.1753, 4) == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing float_is_equal on whether 2.1756 is equal to 2.1753 at a precision level of 5." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << float_is_equal(2.1746, 2.1753, 5) << endl;
   (float_is_equal(2.1756, 2.1753, 5) == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing is_int

   cout << "Testing is_int on whether the string '24' is an integer or not." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << is_int("24") << endl;
   (is_int("24") == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing is_int on whether the string '24TYT' is a string or not." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << is_int("24TYT") << endl;
   (is_int("24TYT") == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing numbers_present

   cout << "Testing numbers_present on whether there are numbers in the sentence 'The 2 cows jumped over the moon' or not." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << numbers_present("The 2 cows jumped over the moon") << endl;
   (numbers_present("The 2 cows jumped over the moon") == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing numbers_present on whether there are numbers present in the sentence 'The cow jumped over the moon' or not." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << numbers_present("The cow jumped over the moon") << endl;
   (numbers_present("The cow jumped over the moon") == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing letters_present

   cout << "Testing letters_present on whether there are letters in the sentence '101 Dalmatians' or not." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << letters_present("101 Dalmatians") << endl;
   (letters_present("101 Dalmatians") == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing numbers_present on whether there are letters present in the sentence '101' or not." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << letters_present("101") << endl;
   (letters_present("101") == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing contains_sub_string

   cout << "Testing contains_sub_string on whether the string 'Driving Miss Daisy' contains the substring 'Daisy' or not." << endl;
   cout << "Expected: 1" << endl;
   cout << "Actual: " << contains_sub_string("Driving Miss Daisy", "Daisy") << endl;
   (contains_sub_string("Driving Miss Daisy", "Daisy") == 1) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   cout << "Testing contains_sub_string on whether the string 'Driving Miss Daisy' contains the substring 'Mister' or not." << endl;
   cout << "Expected: 0" << endl;
   cout << "Actual: " << contains_sub_string("Driving Miss Daisy", "Mister") << endl;
   (contains_sub_string("Driving Miss Daisy", "Mister") == 0) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing word_count

   cout << "Testing word_count on how many words are found in the string 'Sally sells sea shells by the sea shore.'" << endl;
   cout << "Expected: 8" << endl;
   cout << "Actual: " << word_count("Sally sells sea shells by the sea shore.") << endl;
   (word_count("Sally sells sea shells by the sea shore") == 8) ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing to_upper
  
   cout << "Testing to_upper to capitalize every letter in the string 'There are 3 cats and 2 dogs.'" << endl;
   cout << "Expected: 'THERE ARE 3 CATS AND 2 DOGS.'" << endl;
   cout << "Actual: " << "'" << to_upper("There are 3 cats and 2 dogs.") << "'" << endl;
   (to_upper("There are 3 cats and 2 dogs.") == "THERE ARE 3 CATS AND 2 DOGS.") ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing to_lower


   cout << "Testing to_lower to lowercase every letter in the string '2 PUPPIES PLAY IN THE PARK.'" << endl;
   cout << "Expected: '2 puppies play in the park.'" << endl;
   cout << "Actual: " << "'" << to_lower("2 PUPPIES PLAY IN THE PARK.") << "'" << endl;
   (to_lower("2 PUPPIES PLAY IN THE PARK.") == "2 puppies play in the park.") ? cout << "Success" << endl : cout << "Failed" << endl;
   cout << endl;

   // Testing get_int
   
   cout << "Testing get_int on whether your input is an integer or not. If it is, it will return the integer. If not it will return a 0." << endl;
   string z;
   cout << "Please input a string to test: ";
   getline(cin, z);
   cout << "Expected: " << z << endl;
   cout << "Actual: " << get_int(z) << endl;
return 0;

}



























