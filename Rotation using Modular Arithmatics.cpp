#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
#include <stdio.h>      
#include <stdlib.h> 
#include<ctime>
#include <iomanip>
#include <chrono>
using namespace std;

//shiftArray class shifts the values within an array
template <typename P>
class shiftArray {
private:
	int length;
	P* arr;

	//increase size function increases the array by 1
	void increaseSize() {

		//temp newArr array stores copy of original array
		P* newArr = new P[length];
		for (int i = 0; i < length; i++) {
			*(newArr + i) = *(arr + i);
		}

		//increase the original array to the new length and copy newArr back into original
		arr = new P[length];

		for (int i = 0; i < length; i++) {
			*(arr + i) = *(newArr + i);
		}
		
		//delete temp array
		delete[] newArr;
	}
public:
	//default constructor
	shiftArray() {
		length = 0;
		arr = new P[length];
	}

	//push values to array
	void push(P x) {
		length++;
		increaseSize();
		*(arr + (length - 1)) = x;
	}

	//*get clarification for the use of [] operator
	int& operator[] (int index) {
		if (index >= length)
		{
			cout << "entered index is not within array range.";
			exit(0);
		}
		return NULL;
	}

	/*
	shift array position by integer x amount
	first take modulus of shift to the length
	second create a temp array 
	begin filling temp array with original accounting for shift
	finally copy the new array back to the temp and delete the temp array
	*/
	void rotate(int x) {
		int rotation = x % length;
		P* newArr = new P[length];
		for (int i = 0; i < length; i++) {
			int postShift = (i + rotation + length) % length;
			*(newArr + postShift) = *(arr + (i));
		}

		for (int i = 0; i < length; i++) {
			*(arr + i) = *(newArr + i);
		}
		delete[] newArr;

	}

	//iterate through array and display the values 
	void displayArray() {
		cout << endl << endl;
		for (int i = 0; i < length; i++) {
			cout << *(arr + i) << " ";
		}
		cout << endl << endl;
	}
};

//simple menu for user input
void displayMenu() {
	cout << "\nMenu: " << endl;
	cout << "*******" << endl;
	cout << "To display array, enter 1." << endl;
	cout << "to rotate array, enter 2." << endl;
	cout << "To exit, enter 3.\n" << endl;
}

int main() {
	//two ints for menu and for rotation
	int userInput, rotation;

	//create intance of the shift array and populate with random integers
	shiftArray<int> test;
	cout << "populating the array with 10 values" << endl;
	for (int i = 0; i < 10; i++) {
		int value = rand() % 10 + 1;
		test.push(value);
	}

	//display menu and prompt user for options
	displayMenu();
	cout << "Enter choice: ";
	cin >> userInput;
	while (userInput != 3) {
		if (userInput == 1) {
			test.displayArray();
		}
		else if (userInput == 2) {
			cout << "Enter rotation amount(+ or -): ";
			cin >> rotation;
			test.rotate(rotation);
		}
		else {
			cout << "Invalid entry, Try again!" << endl;
		}


		displayMenu();
		cout << "Enter choice: ";
		cin >> userInput;
	}

	return 0;
}