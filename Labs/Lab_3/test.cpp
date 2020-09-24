#include <iostream>
#include <time>

using namespace std;

int main(){

	int pass_length = 1000000;
	cout << "How long do you want the password to be? ";
	cin >> pass_length;
	
	int letters = 1000000;
	cout << "Do you want letters? ";
	cin >> letters;

	if (letters == 0){

		int up_letters;
		cout << "Do you want uppercase letters? ";
		cin >> up_letters;

		if (up_letters == 0){
			int up_letters_count;
			cout << "How many characters of your password should be upercase? ";
			cin >> up_letters_count;
		}
		int low_letters;
		cout << "Do you want lowercase letters? ";
		cin >> low_letters;

		if (low_letters == 0){
			int low_letters_count;
			cout << "How many characters of your passowrd do you want to be lowercase? ";
			cin >> low_letters_count;

		}
	}

	int numners;
	cout << "Do you want numbers? ";
	cin >> numbers;

	if (numbers == 0){
		int numbers_count;
		cout << "How many characters of the password should be numbers? ";
		cin >> numbers_count;
	}
	
	int n
	for(int i = 0; i < pass_length; i++){
		for(int j = 0; j < up_letters_count; j++){
			n = rand() % 25 + 65;
			cout >> char(n);	
		}
		for (int k = 0; k < low_letters_count; k++){
			n = rand() % 25 +
		}
	}


	return  0;
}
