#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

/*Program to compute users gross annual income and taxes required given their
 * monthly salary, months worked in the year, price of car sold, number of cars
 * sold, misconducts observed, tax year, and state in which the user is filing.
 */

int main()
{
	//Begin the code

	cout << endl;
	cout << endl;
	cout << "Input your information below: " << endl;
	cout << endl;
	cout << endl;
	
	//User inputs necessary for computation

	float MS; //Monthly salary
	cout << "Enter your monthly salary: ";
	cin >> MS;
	int MW; //Months worked in a year
	cout << "Enter the number of months you worked in the year: ";
	cin >> MW;
	float CC; //Cost of a car
	cout << "Enter the cost of the car model you sold: ";
	cin >> CC;
	int CS; //Cars sold in the year
	cout << "Enter the number of cars you sold: ";
	cin >> CS;
	int MO; //Misconducts observed
	cout << "Enter the number of misconducts observed that year: ";
	cin >> MO;
	int TY; //Tax year being filed in
	cout << "Which tax year are you filing in: ";
	cin >> TY;
	char STATE; //State being filed in
	cout << "Which state are you filing in: ";
	cin >> STATE;

	//Whitespace between inputs and outputs
	
	cout << endl;
	cout << endl;
	cout << "Your tax information: " << endl;
	cout << endl;
	cout << endl;
	
	//Computation of annual salary
	
	float AS; //Annual salary
	AS = MS * MW;
	cout << "Your annual salary is: $" << AS << endl;

	//Computation of profit margin 
	
	srand(time(NULL));
	int PM = rand() % 5 + 6; //Profit margin %
	float SP = PM/100.00 * CC + CC;
	cout << "Average Profit Margin: " << PM << "%" <<  endl;
	cout << "Average Selling Price of Car: $" << SP << endl;
	
	//Computation of profit	

	float profit = ((SP - CC) * CS) * 0.02;
	cout << "Your profit from car sales this year totalled: $" << profit << endl;

	//Computation of misconduct cost

	int MD = 0; //Misconduct deduction

	if (MO == 0){
		cout << "You had no misconduct deductions necessary." << endl;
	} 
	else {
		MD = 100 * pow (2, MO - 1);
		cout << "Misconduct deductions totalled: $" << MD <<  endl;
	}

	//Computation of gross income
	
 	float GI = AS - MD + profit; //Gross income
	cout << "Your gross income is: $" << GI << endl;	

	//Computation of tax bracket and required payment
	
	float TP; //Tax payment

	if(STATE == 'A'){

		if(TY == 2017){
			TP = GI * 0.06;
			
		} else if(TY == 2018){
			TP = GI * 0.08;
		}

	}else if(STATE == 'B'){

		if(TY == 2017){

			if(GI < 2000){
				TP = 0;

			} else if(GI >= 2000 && GI <= 10000){
				TP = 100;

			} else if(GI > 10000){
				TP = (GI - 10000) * 0.1 + 100;
			}

		} else if(TY == 2018){

			if(GI < 2500){
				TP = 0;

			} else if(GI >= 2500 && GI <= 10000){
				TP = 115;

			} else if(GI > 10000){
				TP = (GI - 10000) * 0.105 + 115;
			}
		}

	} else if(STATE == 'C'){

		if(TY == 2017){

			if(GI < 3500){
				TP = GI * 0.05;

			} else if(GI >= 3500 && GI <= 9000){
				TP = (GI - 3500) * 0.07 + 175;

			} else if(GI > 9000 && GI <= 125000){
				TP = (GI - 9000) * 0.09 + 560;

			} else if(GI > 125000){
				TP = (GI - 125000) * 0.099 + 11000;
			}

		} else if(TY == 2018){

			if(GI < 3450){
				TP = GI * 0.05;

			} else if(GI >= 3450 && GI <= 8700){
				TP = (GI - 3450) * 0.07 + 172.5;

			} else if(GI > 8700 && GI <= 125000){
				TP = (GI - 8700) * 0.09 + 540;

			} else if(GI > 125000){
				TP = (GI - 125000) * 0.099 + 11007;
			}
		}
	}
	
	//Display the tax payment
	
	cout << "The tax you need to pay is: $" << TP << endl;

	//Computation and display of remaining funds

	float remaining = GI - TP; //Remaining funds
	cout << "Remaining funds: $" << remaining << endl;

return 0;
}

