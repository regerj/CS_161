#include <sys/time.h>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int fib_iter(int n){

   int previous_2;
   int previous_1 = 0;
   int current = 1;

   for(int i = 1; i < n; i++){
   
      previous_2 = previous_1;
      previous_1 = current;
      current = previous_1 + previous_2;
   }

   return current;

}

int fib_recurs(int n){

   if(n == 0)
      return 0;
   else if(n == 1)
      return 1;
   return fib_recurs(n-1) + fib_recurs(n-2);

}

int main (){

   typedef struct timeval time;
   time stop, start;

   int n;
   cout << "Please enter a number to determine its fibonacci number: ";
   cin >> n;

   gettimeofday(&start, NULL);

   cout << "Your fibonacci number is: " << fib_iter(n) << endl;
   cout << endl;
   //cout << "Your fibonacci number is: " << fib_recurs(n) << endl;
   //cout << endl;

   gettimeofday(&stop, NULL);
   if(stop.tv_sec > start.tv_sec)
      cout << "Seconds: " << stop.tv_sec - start.tv_sec << endl;
   else

      cout << "Micro: " << stop.tv_usec - start.tv_usec << endl;
   return 0;
}

