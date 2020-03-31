#include<iostream>
#include<vector>
#include<cctype>
#include<ctime>
#include<cstdlib>
using namespace std;


//int function returns a random number
int random() {
	int result = rand();
	result = result % 4;
	result = result + 1;
	return result;
}

//void function iterates through vector matrix to find 4 values that are similar in a vertical row
//inputs are the user generated vector matrix, number of rows, number of columns, and a second vector
//the second vector is the same size as the first. but it holds 0's and 1's.
//0's become 1's when a match of 4 is found
void matrixSearchVert(const vector<vector<int>>& vec, vector<vector<int>>& vec2, int rows, int columns) {
	for (int i = 0; i < rows - 3; i++) {
		for (int j = 0; j < columns; j++) {
			if (vec[i][j] == vec[i + 1][j] && vec[i][j] == vec[i + 2][j] && vec[i][j] == vec[i + 3][j]) {
				vec2[i][j] = 1;
				vec2[i + 1][j] = 1;
				vec2[i + 2][j] = 1;
				vec2[i + 3][j] = 1;
			
			}
		}
	}
}

//void function iterates through vector matrix to find 4 values that are similar in a horizontal row
//inputs are the user generated vector matrix, number of rows, number of columns, and a second vector
//the second vector is the same size as the first. but it holds 0's and 1's.
//0's become 1's when a match of 4 is found
void matrixSearchHorz(const vector<vector<int>>& vec, vector<vector<int>>& vec2, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns - 3; j++) {
			if (vec[i][j] == vec[i][j + 1] && vec[i][j] == vec[i][j + 2] && vec[i][j] == vec[i][j + 3]) {
				
				vec2[i][j] = 1;
				vec2[i][j + 1] = 1;
				vec2[i][j + 2] = 1;
				vec2[i][j + 3] = 1;

			}
		}
	}
}

//void function iterates through vector matrix to find 4 values that are similar in a diagonal row
//inputs are the user generated vector matrix, number of rows, number of columns, and a second vector
//the second vector is the same size as the first. but it holds 0's and 1's.
//0's become 1's when a match of 4 is found
void matrixSearchDiag(const vector<vector<int>>& vec, vector<vector<int>>& vec2, int rows, int columns) {
	for (int i = 0; i < rows - 3; i++) {
		for (int j = 0; j < columns - 3; j++) {
			if (vec[i][j] == vec[i + 1][j + 1] && vec[i][j] == vec[i + 2][j + 2] && vec[i][j] == vec[i + 3][j + 3]) {
				
				vec2[i][j] = 1;
				vec2[i + 1][j + 1] = 1;
				vec2[i + 2][j + 2] = 1;
				vec2[i + 3][j + 3] = 1;

			}
		}
	}
}

//void function iterates through vector matrix to find 4 values that are similar in a diagonal row
//inputs are the user generated vector matrix, number of rows, number of columns, and a second vector
//the second vector is the same size as the first. but it holds 0's and 1's.
//0's become 1's when a match of 4 is found
//second diagonal function is needed to find when a vector is diagonal in the opposite direction of the first diagonal search
void matrixSearchDiag2(const vector<vector<int>>& vec, vector<vector<int>>& vec2, int rows, int columns) {
	for (int i = 3; i < rows; i++) {
		for (int j = 0; j < columns - 3; j++) {
			if (vec[i][j] == vec[i - 1][j + 1] && vec[i][j] == vec[i - 2][j + 2] && vec[i][j] == vec[i - 3][j + 3]) {
				vec2[i][j] = 1;
				vec2[i - 1][j + 1] = 1;
				vec2[i - 2][j + 2] = 1;
				vec2[i - 3][j + 3] = 1;

			}
		}
	}
}



int main() {
	srand(time(0));
	cout << "Connect 4!" << endl;
	cout << "**********" << endl << endl;
	cout << "This program creates a matrix with a size determined by the user, and values chosen at random." << endl;
	cout << "To run the program, enter the number of rows and columns you want in the matrix.\n\n" << endl;

	//initiate rows and columns variables of type int
	int rows;
	int columns;
	
	//grabs user input for the rows and columns
	cout << "Enter the number of rows in the matrix: ";
	cin >> rows;
	cout << "Enter the number of columns in the matrix: ";
	cin >> columns;

	//4 matrices needed
	//first holds the user generated matrix
	//second holds a matrix that holds values to determine repeating vertical matches
	//third is same as second but used to find horizontal 
	//fourth is same as second but used to find diagnoal matchs.
	vector<vector<int>> matrix(rows, vector<int>(columns, 0));
	vector<vector<int>> matrixVert(rows, vector<int>(columns, 0));
	vector<vector<int>> matrixHorz(rows, vector<int>(columns, 0));
	vector<vector<int>> matrixDiag(rows, vector<int>(columns, 0));

	//for loop adds random numbers to the user generated matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = random();
		}
	}

	//for loop prints out the original matrix
	cout << "This is your matrix" << endl;
	cout << "*******************" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
				cout << " " << matrix[i][j] << "  ";
		}
	cout << endl;
	}

	//calls matrixSearchVert function to find the vertical "connect 4's"
	//for loop prints out the original matrix with a "'" added to the vertical matches of 4
	cout << "These are all the vertical matches" << endl;
	cout << "**********************************" << endl;
	matrixSearchVert(matrix, matrixVert, rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixVert[i][j] == 1) {
				cout << "'" << matrix[i][j] << "' ";
			}
			else {
				cout << " " << matrix[i][j] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl; 

	//calls matrixSearchHorz function to find the horizontal "connect 4's"
	//for loop prints out the original matrix with a "'" added to the horizontal matches of 4
	cout << "These are all the horizontal matches" << endl;
	cout << "**********************************" << endl;
	matrixSearchHorz(matrix, matrixHorz, rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixHorz[i][j] == 1) {
				cout << "'" << matrix[i][j] << "' ";
			}
			else {
				cout << " " << matrix[i][j] << "  ";
			}
		}
		cout << endl;
	}

	//calls matrixSearchdiag and matrixSearchDiag2 functions to find the diagonal "connect 4's"
	//for loop prints out the original matrix with a "'" added to the Diagonal matches of 4
	cout << "These are all the Diagonal matches" << endl;
	cout << "**********************************" << endl;
	matrixSearchDiag(matrix, matrixDiag, rows, columns);
	matrixSearchDiag2(matrix, matrixDiag, rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixDiag[i][j] == 1) {
				cout << "'" << matrix[i][j] << "' ";
			}
			else {
				cout << " " << matrix[i][j] << "  ";
			}
		}
		cout << endl;
	}



	system("pause");
	return 0;
}