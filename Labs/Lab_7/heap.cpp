#include <iostream>

using namespace std;

void allocate(int n, int **p);
void assign(int n, int *ptr2);
void free_mem(int **ptr3);

int main(){

   cout << "How many ints do you want? ";
   int n;
   int *ptr1 = NULL;
   cin >> n;
   allocate(n, &ptr1);

   assign(ptr1);
   free_mem(&ptr1);

   return 0;
}

void allocate(int n, int **p){

   *p = new int[n]
}

void assign(int n, int *ptr2){

   for(int i = 0; i < n; i++){
   
      cout << "Please enter integer number " << i + 1 << ":";
      cin >> ptr2[i];

   }
}

void free_mem(int **ptr3){
   delete [] *ptr3;
   *ptr3 = NULL;
}

