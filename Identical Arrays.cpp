#include<iostream>
#include<vector>
#include<string>
using namespace std;

//void function describest the program and how to use it
void printIntro() {
	cout << "ARE THE TWO LISTS IDENTICAL?" << endl;
	cout << "****************************\n" << endl;
	cout << "The following program takes two lists provided by the user." << endl;
	cout << "The lists are compared to eachother to identify whether the lists are the same" << endl;
	cout << "The program ignores the order of the numbers." << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n" << endl;
}

//bool function takes in two arrays as constants 
//returns true if the arrays are the same, and false if different
bool compareMatrix(const int array[][3], const int array2[][3]) {
	bool identical = true;
	
	//two vectors are created that hold 101 zero's
	vector<int> values1 (101, 0);
	vector<int> values2(101, 0);

	//each value in the array is located in the index of the value, and a plus 1 is added to that index
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			values1[array[i][j]] = values1[array[i][j]] + 1;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			values2[array2[i][j]] = values2[array2[i][j]] + 1;
		}
	}

	//vectors are compared to eachother. if identical return true, else return false
	if (values1 == values2) {
		identical = true;
	} else {
		identical = false;
	}
	return identical;
}

int main() {

	//call printIntro function
	printIntro();
	//initialize two 3x3 matrices
	int matrix[3][3];
	int matrix2[3][3];
	bool identical;
	

	//prompt user for 9 values
	cout << "Enter 9 values for the first list seperated by spaces:";

	//nested for loops to iterate through each container in 9x9 matrix 
	//store cin values into matrix one by one
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			cin >> matrix[m][n];
		}
	}
	
	//repeat for second matrix
	cout << "Enter a second list of 9 numbers:";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix2[i][j];
		}
	}
	
	//print out array 1
	cout << endl << "list 1 :" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//print out array 2
	cout << "list 2 :" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}
	
	//call the comparematrix function and store value in identical variable
	identical = compareMatrix(matrix, matrix2);

	//if identical variable is true, return "identical" else return "not identical"
	if (identical) {
		cout << "The two lists are identical!" << endl;
	} else {
		cout << "The two lists are NOT identical" << endl;
	}

	system("pause");
	return 0;
}