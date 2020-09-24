#include <iostream>
#include <string>

using namespace std;

void get_string(string *str1);
void set_replace_string(string str1, string *str2);
int get_search_replace(char ch, string str1, string &str2);

int main(){

   string str1;
   get_string(&str1);
   string str2 = str1;
   set_replace_string(str1, &str2);
   char ch;
   cout << str2 << endl;
   cout << "Please enter a character to search for: ";
   cin.get(ch);
   cout << "The number of those characters present is: " << get_search_replace(ch, str1, str2) << endl;
   cout << str2 << endl;
   
   return 0;
}

void get_string(string *str1){

   cout << "Please enter a string: ";
   getline(cin, *str1);
}

void set_replace_string(string str1, string *str2){

   for(int i = 0; i < str1.length(); i++){
   
      if(str1[i] != ' '){
      
	 (*str2)[i] = '-';

      }
   }
}

int get_search_replace(char ch, string str1, string &str2){

   int count = 0;
   for(int j = 0; j < str1.length(); j++){
   
      if(str1[j] == ch){
      
	 str2[j] = ch;
	 count += 1;
      }
   }
   return count;
}
