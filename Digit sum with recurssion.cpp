#include<iostream>;
using namespace std;

//global function to hold the sum of the digits in an integer
int sum;

void intro() {
	cout << "Sum of integers using Recursion" << endl;
	cout << "*******************************/n" << endl;
	cout << "This program takes the sum of the integers input by the user using a recursive function. " << endl << endl;
}

//sumDigits function is a recursive function that takes the sum of each digit in an integer.
//modulus operator is used to take the last digit and then the integer is divided by 10 and sent back to the function
//base case is when the value is less then 10.
int sumDigits(int number) {
	if (number > 10) {
		sum = sum + (number % 10);
		number = number / 10;
		return sumDigits(number);
	} else {
		sum = sum + number % 10;
		return sum;
	}
}

int main() {

	//print program description
	intro();
	//initiate x value and store the user input into that x.
	int x;
	cout << "Enter a positive integer(1 to quit): ";
	cin >> x;

	//while function to prompt the user for a new integer, and troubleshoot when the value is negative.
	//the function exits when the user inputs 1
	while (x != 1) {
		if (x < 0) {
			cout << "Please enter a positive integer!" << endl;
			cout << "Enter a positive integer: ";
			cin >> x;
		} else {
			cout << sumDigits(x) << endl;;
			cout << "Enter a positive integer: ";
			cin >> x;
		}
		sum = 0;
	}


	system("pause");
	return 0;
}