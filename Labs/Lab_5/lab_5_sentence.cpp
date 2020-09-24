#include <iostream>
#include <string>

using namespace std;

/***********************************************************************************
**  Function: get_setence
**  Description: Prompts the user for a sentence and returns it.
**  Parameters: N/A
**  Pre-Conditions: The input is a string.
**  Post-Conditions: Returned the string.
***********************************************************************************/

/*
string get_sentence(){

   string s;
   cout << endl;
   cout << "Please input a word, number, or sentence: ";
   getline(cin, s);
   cout << endl;
   return input;
}
*/

void void_get_sentence(string &sentence){

   cout << endl;
   cout << "Plese input a word, number, or sentence: ";
   getline(cin, sentence);
   cout << endl;
  
}

int main(){

   // Testing get_sentence()

   /*
   string sentence;
   cout << endl;
   cout << "Testing string get_sentence() function." << endl;
   sentence = get_sentence();
   cout << sentence << endl;
   */

   // Testing void_get_sentence
   
   string sentence;
   cout << endl;
   cout << "Testing void void_get_sentence(string &sentence)." << endl;
   void_get_sentence(sentence);
   cout << sentence << endl;


   return 0;
}
