#include <iostream>
#include <cstring>

using namespace std;

bool checkForA(string);

int main(){

	string input = "";
	cout << "Type your sentence: ";

	getline(cin, input);

	for(int i = 0; i < input.length(); i++){

		cout << "Input sentance: " << input << endl;
		if(contain_a == true){
			cout << "This sentance has an A";
		}else {
			cout << "This sentance does not have an A";
		}
	}
return 0
}

bool checkForA(string str){
	
	for(int i = 0; i < input.length(); i++){

		cout << "Input sentance: " << input << endl;
		if(input.at(i) == 'a'){
			contain_a = true;
			return true;
		}
	}

	return false;
}
