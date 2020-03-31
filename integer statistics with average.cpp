#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

bool isPositive(int positive){
	if (positive > 0){
		return true;
	} else {
		return false; 	
}
}

bool isNegative(int negative){
	if (negative < 0){
		return true;
	} else {
		return false; 	
	}
}
bool isOdd(int odd){
	
	odd = odd % 2;
	if (odd == 1){
		return true;
	} else {
		return false;
	}
}

bool isEven(int even){
	
	even = even % 2;
	if (even == 0){
		return false;
	} else {
		return true;
	}
}




int main () {

	cout << "Integer statistics with average" << endl;
	cout << "-------------------------------\n" << endl;
	
	int userInput;
	int even = 0;
	int odd = 0;
	int positive = 0;
	int negative = 0;
	float average = 0;
	int total = 0;
	
	cout << "Enter an integer (0 to quit): ";
	cin >> userInput;
	int sum = 0;
	while(userInput != 0 ) {
		//take sum of user input, store in sum variable
		sum = sum + userInput;
		//each time while statement is true, total counts(counter for iterations)
		total = total + 1;
		average = sum / total;
		//create bool statement for positive variables and pass to isPositive function
		
		//if statement, test user input with function to determine positive, negative, odd, or even
		//when functions return positive, counter adds one
		//when functions return negative, counters do not increase
		
		if (isPositive(userInput) == true) {
			positive = positive + 1;
		}
		
		if (isNegative(userInput) == true) {
			negative = negative + 1;
		}
		
		if (isOdd(userInput) == true) {
			odd = odd + 1;
		}
		
		if (isOdd(userInput) == true){
			odd = odd + 1;
		}
		if (isEven(userInput) == true){
			even = even + 1;
		}

		
		
	cout << "Enter an integer (0 to quit): ";
	cin >> userInput;
		
	}
	
	cout << "Average of numbers: " << average << endl;
	cout << "positive integers: " << positive << endl;
	cout << "Negative integers: " << negative << endl;
	cout << "Even numbers: " << even << endl;
	cout << "Odd numbers: " << odd << endl;
	cout << "sum of numbers: " << sum << endl;
	return 0;
}
