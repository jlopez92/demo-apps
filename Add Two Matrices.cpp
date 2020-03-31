#include<iostream>
#include<string>
using namespace std;


//intro function that prints out description of the program, and how to run it.
void printIntro() {
	cout << "Adding two Matrices" << endl;
	cout << "*********************" << endl << endl;
	cout << "This program adds two matrices together and places results into a third matrix." << endl;
	cout << "To get started, the user must enter 9 values for two matrices separated by spaces." << endl << endl;
}

//void function takes in two matrices as constants
//each value in the two first matrices are summed and input into the third matrix
void matrixSumPrint(const int array1[3][3], const int array2[3][3], int array3[3][3]) {

	//nested for loops iterate through each container in the matrix
	//each container is then summed, and value stored into corresponding container in third matrix
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			array3[m][n] = array1[m][n] + array2[m][n];
		}
	}

}

int main() {


	//grab comma seperated integers from user 
	//store list in rawNumbers string
	string rawNumbers;
	string rawNumbers2;

	//initialize three, 3x3 matrices
	int matrix[3][3];
	int matrix2[3][3];
	int sumMatrix[3][3];

	//call function to print intro to screen
	printIntro();

	//prompt user for 9 values
	cout << "Enter 9 values for the first matrix seperated by spaces: ";

	//nested for loops to iterate through each container in 9x9 matrix 
	//store cin values into matrix one by one
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			cin >> matrix[m][n];
		}
	}



	//repeat for matrix 2
	cout << "Enter 9 values for the second matrix seperated by spaces: ";
	
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			cin >> matrix2[m][n];
		}
	}
	
	//call function to sum matrix 1 and matrix 2, store values in a third matrix
	matrixSumPrint(matrix, matrix2, sumMatrix);

	//print out matrix one using nested for loops
	cout << "first matrix: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	//repeat for matrix 2
	cout << "second matrix: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}

	//repeat for matrix 3
	cout << "sum of matrix 1 and matrix 2: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << sumMatrix[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}