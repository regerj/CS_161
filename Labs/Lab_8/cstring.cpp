#include <iostream>
#include <string.h>

using namespace std;

int main(){

   char input[1025] = "";
   cout << "Please enter your sentence or paragraph here: ";
   cin.getline(input, 1025);
   cout << "Your input was: " << endl << input << endl;

   return 0;
}
