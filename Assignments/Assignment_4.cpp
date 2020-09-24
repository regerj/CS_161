#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

bool is_palindrome(char *str_op);
char * purge_string_special (char *str_copy);
char * purge_string_leave_space (char *str_copy);
int * count_word(char *str_op, string* words);
void lower_all (char *str_op);
int count_words (char *str_op);
void purge_multi_space(char* str_op);
string* split_all_words (char* str_op);
int * count_custom(char * str_op, string * words, string * search_words, int n);
string to_lower(string search_word);
int get_int(string prompt);
bool is_int(string num);
bool numbers_or_specials_present(string sentence);

/***********************************************************************************
**  Program: Assignment_4.cpp
**  Author: Jacob Reger
**  Date: 11/24/2019
**  Description: This program has the goal of taking input from the user as a
**  c string and giving the user the choice of detecting whether it is a palindrome
**  or not, search it for word frequencies, or search it for frequencies of specific
**  words of any quantity that the user may input.
**  Input: Input will include an initial string, a choice of what test to perform on
**  said string, how many words they would like to search for, what those words will
**  be, and finally if they would like to run the program again.
**  Output: Outputs of the following functions will display whether the c string is 
**  a palindrome, the frequencies of each word in the c string, or the frequencies 
**  of each word the user specifies, along with some basic instructions and error 
**  handling information.
***********************************************************************************/

int main(){

   string again;
   do{
      char input[1025];
      cout << endl << endl << endl << "Please enter a sentence or paragraph: " << endl;
      cin.getline(input, 1024);
      char space[2] = " ";
      strcat(input, space);

      cout << "What test would you like to perform on the input?" << endl << endl;
      cout << "   1. Palindrome Detector" << endl;
      cout << "   2. All Word Frequency" << endl;
      cout << "   3. Custom Word Frequency" << endl << endl;
      char choice [1];
      cout << "Please enter the number cooresponding to your choice: ";
      cin.getline(choice, 2);
      cout << endl;
      while(choice[0] != '1' && choice[0] != '2' && choice[0] != '3'){

	 cout << "Invalid input! Please try again: ";
	 cin.getline(choice, 24);
      }
      if(choice[0] == '1'){

	 char *str_op = purge_string_special(input);
	 lower_all(str_op);
	 if(is_palindrome(str_op) == true)
	    cout << "Your input is a palindrome!" << endl;
	 else 
	    cout << "Your input is not a palindrome!" << endl;

	 delete [] str_op;
      }else if(choice[0] == '2'){

	 char *str_op = purge_string_leave_space (input);
	 lower_all(str_op);      
	 purge_multi_space(str_op);
	 string* words = split_all_words(str_op);     
	 int* counts = count_word(str_op, words);
	 for(int i = 0; i < count_words(str_op); i++)
	    if(counts[i] != 0)
	       cout << "   There was " << counts[i] << " instance(s) of the word \"" << words[i] << "\" found in the input." << endl;
	 delete[] str_op;
	 delete[] words;
	 delete[] counts;
      }else if(choice[0] == '3'){

	 string n;
	 char * str_op = purge_string_leave_space (input);
	 lower_all (str_op);
	 purge_multi_space(str_op);
	 string * words = split_all_words (str_op);
	 cout << "How many words would you like to search for: ";
	 getline(cin, n);
	 while(is_int(n) == 0){	 
	    cout << "Invalid input! Please input a positive integer: ";
	    getline(cin, n);
	 }
	 int num = get_int(n);
	 cout << endl;
	 string * search_words = new string[num];
	 for(int i = 0; i < num; i++){
	    cout << "   Please enter word " << i+1 << " : ";
	    getline(cin, search_words[i]);
	    while(numbers_or_specials_present(search_words[i]) == 1){
	    
	       cout << endl << "Invalid word input! Please input a single word without any special characters or numbers!" << endl;
	       cout << "   Please enter word " << i+1 << " : ";
	       getline(cin, search_words[i]);
	    }
	    search_words[i] = to_lower(search_words[i]);
	 }
	 int * counts = count_custom(str_op, words, search_words, num);
	 cout << endl;
	 for(int i = 0; i < num; i++)
	    cout << "   There was " << counts[i] << " instance(s) of the word \"" << search_words[i] << "\" found in the input." << endl;
	 delete[] str_op;
	 delete[] words;
	 delete[] search_words;
	 delete[] counts;
      }
      cout << endl << "Would you like to run the program again: (0 for no, 1 for yes): ";
      getline(cin, again);
   }while(again == "1");
   while(again != "1" && again != "0"){
      cout << "Invalid input! Please enter 0 or 1: ";
      getline(cin, again);
   }
   return 0;
}

/***********************************************************************************
**  Function: numbers_present
**  Description: Will test if the given string contains numbers.
**  Parameters: string sentence
**  Pre-conditions: Take in a string and test if there are numbers present. 
**  Post-conditions: Return a boolean value to represent if a number was found.
***********************************************************************************/

bool numbers_or_specials_present(string sentence){
   for(int i = 0; i < sentence.length(); i++)
      if(sentence.at(i) <= 64 || sentence.at(i) >= 123 || (sentence.at(i) > 90 && sentence.at(i) < 97))
	 return 1;
   return 0;
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
   for(int i = 0; i < num.length(); i++)    
     if(num.at(i) > 57 || num.at(i) < 48)
	 return 0;     
   return 1; 
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
	 for(int j = 1; j < prompt.length(); j++)	 
	    answer += (prompt.at(j) - 48) * pow(10, prompt.length() - 1 - j);	 
      }else     
	 for(int i = 0; i < prompt.length(); i++)	 
	    answer += (prompt.at(i) - 48) * pow(10, prompt.length() - 1 - i);	       
      return x * answer;
   }
}

/***********************************************************************************
 **  Function: to_lower
 **  Description: Lowercase all letters in a given string and leaves non-letter
 **  characters unchanged.
 **  Parameters: string search_words
 **  Pre-conditions: Take in a string and lowercase only the letters. 
 **  Post-conditions: Return a string containing the original sentence with all 
 **  letters lowercased and all numbers left the same.
 ***********************************************************************************/

string to_lower(string search_words){
   for(int i = 0; i < search_words.length(); i++)
      if(search_words.at(i) >= 65 && search_words.at(i) <= 90)
	 search_words.at(i) = search_words.at(i) + 32;  
   return search_words;
}

/***********************************************************************************
 **  Function: count_custom
 **  Description: Counts the frequency of given words in a given string array.
 **  Parameters: char * str_op, string * words, string * search_words, int n
 **  Pre-conditions: Take in the above values and calculate the frequency of the
 **  given words in the given string array. 
 **  Post-conditions: Return an integer pointer to an integer array on the heap,
 **  which contains the properly indexed counts of frequency.
 ***********************************************************************************/

int * count_custom(char * str_op, string * words, string * search_words, int n){

   int * counts = new int [n];   
   for(int i = 0; i < n; i++)
      counts[i] = 0;
   for(int i = 0; i < n; i++)
      for(int j = 0; j < count_words(str_op); j++)    
	 if(search_words[i] == words[j])
	    counts[i] += 1;
   return counts;
}

/***********************************************************************************
 **  Function: count_word
 **  Description: Counts the frequency of all of the present words in a given string
 **  array.
 **  Parameters: char * str_op, string * word
 **  Pre-conditions: Take in the above values and calculate the frequency of all
 **  words in the given string array. 
 **  Post-conditions: Return an integer pointer to an integer array on the heap,
 **  which contains the properly indexed counts of frequency.
 ***********************************************************************************/

int * count_word (char* str_op, string* words){

   int * counts = new int [count_words(str_op)];
   string* words_copy = new string[count_words(str_op)];
   for(int m = 0; m < count_words(str_op); m++)
      words_copy[m] = words[m];
   for(int l = 0; l < count_words(str_op); l++)
      counts[l] = 0;
   for(int i = 0; i < count_words(str_op); i++)   
      if(words_copy[i] != ""){
	 counts[i] = 1;
	 for(int j = 0; j < count_words(str_op); j++) 
	    if(words[i] == words_copy[j] && i != j){
	       counts[i] += 1;
	       words_copy[j] = "";
	    }
	 words_copy[i] = "";
      }
   return counts;
}

/***********************************************************************************
 **  Function: purge_multi_space
 **  Description: Purges the given string of all double spaces
 **  Parameters: char * str_op
 **  Pre-conditions: Take in the string pointer and delete any double spaces present.
 **  Post-conditions: Void function without return, just changes the heap character
 **  array.
 ***********************************************************************************/

void purge_multi_space(char* str_op){

   for(int i = 0; i < strlen(str_op); i++) 
      if((str_op[i] == ' ' && str_op[i+1] == ' ') || str_op[0] == ' '){
	 memmove (&str_op[i], &str_op[i+1], strlen(str_op)-i);
	 i--;
      }
}

/***********************************************************************************
 **  Function: split_all_words
 **  Description: Splits a given c string into an array of c++ strings each 
 **  containing a single word from the original, in order.
 **  Parameters: char * str_op
 **  Pre-conditions: Take in the c strng, detect words, and save them to a c++ string
 **  array.
 **  Post-conditions: Return said c++ string array.
 ***********************************************************************************/

string * split_all_words (char * str_op){

   char temp[1025];
   strcpy(temp, str_op);
   int n = count_words(str_op);
   string* words = new string[n];
   words[0] = strtok(temp, " ");
   int i = 0;
   while(i < n-1){
      i++;
      words[i] = strtok(NULL, " ");
   }
   return words;
}

/***********************************************************************************
 **  Function: count_words
 **  Description: Counts the number of words in a given c string.
 **  Parameters: char * str_op
 **  Pre-conditions: Take in the c string and count the number of words present.
 **  Post-conditions: Return an integer with the word count.
 ***********************************************************************************/

int count_words (char *str_op){

   int count = 1;
   for(int i = 0; i < strlen(str_op); i++)
      if((str_op[i] == ' ' && str_op[i+1] != ' ') && i != strlen(str_op)-1)
	 count += 1;
   return count; 
}

/***********************************************************************************
 **  Function: purge_string_special
 **  Description: Purges the given string of all special characters and space.
 **  Parameters: char * str_copy
 **  Pre-conditions: Take in the c string and return a c string without any specials.
 **  Post-conditions: Return a c string with no specials
 ***********************************************************************************/

char * purge_string_special (char * str_copy){

   char * temp = new char[1025];
   strcpy (temp, str_copy);
   for (int i = 0; i < strlen(temp); i++)
      if(temp[i] < 48 || (temp[i] > 57 && temp[i] < 65) || (temp[i] > 90 && temp[i] < 97) || temp[i] > 122){
	 memmove (&temp[i], &temp[i+1], strlen(temp)-i);
	 i--;
      }
   return temp;
}

/***********************************************************************************
 **  Function: purge_string_leave_space
 **  Description: Purges a given string of all special characters except space.
 **  Parameters: char * str_copy
 **  Pre-conditions: Take in the c string and purge of all specials.
 **  Post-conditions: Return the purged c string.
 ***********************************************************************************/

char * purge_string_leave_space (char *str_copy){

   char * temp = new char[1025];
   strcpy (temp, str_copy);
   for (int i = 0; i < strlen(temp); i++)
      if((temp[i] < 65 && temp[i] != 32) || (temp[i] > 90 && temp[i] < 97) || temp[i] > 122){
	 memmove (&temp[i], &temp[i+1], strlen(temp)-i);
	 i--;
      }
   return temp;
}

/***********************************************************************************
 **  Function: lower_all
 **  Description: Lower cases all of the characters in a given sting
 **  Parameters: char * str_op
 **  Pre-conditions: Take in the c string and lower case it all.
 **  Post-conditions: Void so no return, just lower cases the entire c string.
 ***********************************************************************************/

void lower_all (char *str_op){

   for(int i = 0; i < strlen(str_op); i ++)
      if(str_op[i] >= 65 && str_op[i] <= 90)
	 str_op[i] = str_op[i] + 32;
}

/***********************************************************************************
 **  Function: is_palindrome
 **  Description: Tests whether a given c string is a palindrome.
 **  Parameters: char * str_op
 **  Pre-conditions: Take in a c string and return a bool for if it is a palindrome.
 **  Post-conditions: Return a bool, true if palindrome, false if not.
 ***********************************************************************************/

bool is_palindrome(char *str_op){

   for(int i = 0; i < (strlen(str_op)/2); i++)
      if(str_op[i] != str_op[strlen(str_op)-i-1])
	 return false;
   return true;
}

