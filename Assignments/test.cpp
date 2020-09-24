#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(){

   char input[1025];
   cout << "Please input string: " << endl;
   cin.getline(input, 1024);

   string words[2];
   string pch = strtok (input, " ");
   cout << "pch: " << pch << endl;
   words[0] = pch;
   out << "words[0]: " << words[0];
   return 0;


}
