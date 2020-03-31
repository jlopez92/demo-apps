#include<iostream>
#include<vector>
using namespace std;

//void function prints out the name of the program, description, and how it works.
void intro() {
	cout << "Finding the Greatest Common Divisor using Recursion" << endl;
	cout << "***************************************************\n" << endl;
	cout << "The following program takes two user provided integers, and finds the greatest common divisor\n" << endl;
}

//greatest common divisor function
//takes in two int values
//returns the greatest common divisor
int gcd(int x, int y) {

	//if variable returns x when y is zero for the base case
	//otherwise it returns y as the new x and the remainder of y divided by x
	if (y != 0) {
		return gcd(y, x % y);
	} else {
		return x;
	}
}

int main() {
	//print intro
	intro();

	//create two int variables x and y, have user input assigned the values
	int x, y;
	cout << "Enter the first integer: ";
	cin >> x;
	cout << "Enter the second integer: ";
	cin >> y;

	//print out and call the greatest common divisor function of the user provided values
	cout << "\nThe greatest common divisor is " << gcd(x, y) << endl;

	system("pause");
	return 0;
}