#include <iostream>

using namespace std;

int main(){

   //USING STATIC ARRAY

   int static_array[3][4];

   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 4; j++)
	 static_array[i][j] = i+j;

      
   

   //To print off the adress of the pointer to the 1st row pointer

   cout << "The adress of the pointer to the 1st row pointer: " << &static_array << endl;

   //To print off the address of the 1st row pointer
   
   cout << "The address of the 1st row pointer: " << &static_array[0] << endl;

   cout << "or using the contents of the array: " << static_array << endl;

   //To print off the address of the 1st element of the 1st row

   cout << "The address of (1,1) is: " << &static_array[0][0] << endl;

   cout << "or using the contents of the 1st row pointer: " << static_array[0] << endl;

   //To print off the address of the 2nd element of the 1st row
  
   cout << "The adress of (1,2) is: " << &static_array[0][1] << endl;

   //To print off the adress of the 1st element in the 2nd row

   cout << "The adress of (2,1) is: " << &static_array[1][0] << endl;

   //To print off the contents of (2,2)

   cout << "The contents of (2,2) are: " << static_array[1][1] << endl;


   //USING DYNAMIC ARRAY

   int **s;
   s=new int*[5]; 		//Initializes all 5 row pointers
   for(int i = 0; i < 5; i++)
      s[i] = new int[5];	//Initializes all 5 coloumns in each of the 5 row pointers, creating 5X5
   for(int i = 0; i < 5; i++)
      delete [] s[i];		//Deletes each column
   delete [] s;			//Deletes the row pointers

   int *r[5];

   for(int i = 0; i < 5; i++)
      r[i] = new int;		//Initializes one column for each of the 5 rows
   for(int i = 0; i < 5; i++)
      dlelete r[i];		//Deletes each row pointer, which is enough because we dont have multiple columns


   int **dynamic_array;
   dynamic array = new int* [3];
   for(int i = 0; i < 3; i++)
      dynamic_array = new int [4];

   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 4; j++)
         dynamic_array[i][j] = i+j;

   for(int i = 0; i < 3; i++)
      delete [] dynamic_array[i];
   delete [] dynamic_array[];
   return 0;
}
