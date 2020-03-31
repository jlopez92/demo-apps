#include<iostream>
#include<string>
using namespace std;

//void function prints description of program and how to run it.
void printIntro() {
	cout << "USER GENERATED MATRIX" << endl;
	cout << "*********************" << endl << endl;
	cout << "This program creates a 3x4 matrix of integers and sums the columns." << endl;
	cout << "To get started, enter the desired integers row by row using a space seperated list." << endl << endl;
}


//void function takes each column of the matrix and prints out the sum of that column
void sumColumn(int arr[][4], int column) {
	int sum = 0;

	//for loop iterates through each column and prints out the results
	for (int r = 1; r < 4; r++) {
		sum = sum + arr[r][column];
	}
	cout << "sum at column " << column << " is " << sum << endl;
}

int main() {

	
	//grab space seperated integers from user 
	//store list in rawNumbers string

	//string variable to hold user input
	string rawNumbers;
	//initialize matrix
	int numbers[3][4];

	//print intro function
	printIntro();

	//prompt user for 4 integers
	//use for loop to loop through first row and insert user input into matrix
	cout << "Enter first row of integers(4 numbers): ";
	for (int i = 1; i < 5; i++) {
		cin >> numbers[1][i];
	}
	
	//repeat for second row
	cout << "Enter second row of integers(4 numbers): ";
	for (int i = 1; i < 5; i++) {
		cin >> numbers[2][i];
	}

	//repeat for third row
	cout << "Enter third row of integers(4 numbers): ";
	for (int i = 1; i < 5; i++) {
		cin >> numbers[3][i];
	}
	cout << endl;

	//for loop prints out the matrix, row by row
	for (int i = 1; i < 4; i++) {
		cout << "row " << i << " : ";
		for (int j = 1; j < 5; j++) {
			cout << numbers[i][j] << " ";
		}
		cout << endl;
	}
	cout << "*****************************" << endl;

	//call sum function for each column
	//input is the numbers matrix and the column to be summed
	sumColumn(numbers, 1);
	sumColumn(numbers, 2);
	sumColumn(numbers, 3);
	sumColumn(numbers, 4);



	system("pause");
	return 0;
}

