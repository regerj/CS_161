#include <iostream>
#include <string.h>

using namespace std;

int main(){

   int n = 0;
   cout << "How many words would you like to search for: ";
   cin >> n;
   cin.ignore(256,'\n');
   cin.clear();
   string* wordsearch = NULL;
   wordsearch = new string[n];
   for(int i = 0; i < n; i++){
   
      cout << "Please input word number " << i+1 << " to search for: ";

      getline(cin, wordsearch[i]);
   }
   for(int i = 0; i < n; i++){
   
      cout << wordsearch[i] << " ";
   }

   cout << endl;

   return 0;
}
