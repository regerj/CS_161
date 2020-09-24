/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>

using namespace std;


int main(){

	int x=3, y;
	char myAnswer;
	bool again;
	char playagain;

	y = x;
	cout << "y is set to: " << y << endl;
	again = true;

	while(again){
		cout << "Please input a number: ";
		cin >> x;
	   	if(x > y){
			cout << "X is greater than Y" << endl;
			cout << "would you like to input another number? (y or n)" << endl;
			cin >> playagain;
			if (playagain == 'y'){
				again = true;
			}else {
				again = false;
			}
		}else if(x == y){
			cout << "X is equal to Y" << endl;
			cout << "would you like to input another number? (y or n)" << endl;
			cin >> playagain;
			if (playagain == 'y'){
				again = true;
			}else {
				again = false;
			}
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?" << endl;
			cin >> playagain;
			if (playagain == 'y'){
				again = true;
			}else {
				again = false;
			}
		}
	}

	for(x = 0; x < 10; x++){
		cout << x << endl;
	}
	
	int num;
	
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
	int a = num;
	
	for(int z = num; z > 1; z--){
	   	a = a * (num-1);
		//cout << "answer rn is: " << a << endl;
		num = num - 1;
		//cout << "Num is: " << num << endl;
		//cout << "Z is: " << z << endl;
	}

	cout << "Answer: " << a << endl;

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer == 'y'){
		cout << "YAY" << endl;
	}else{
		cout << "YOU WILL SOON!" << endl;
	}
	
	return 0;
}

