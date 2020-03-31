#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//pointer int function takes in an array, two ints of original size and an increased size
//function makes an array of the new size, takes the information of the smaller array
//copies the information over to the new array and deletes the smaller array
//finally returns the new array
int* increaseSize(int arr[], int size, int newSize) {
	int* newArray;
	newArray = new int[newSize];
	for (int i = 0; i < size; i++) {

		*(newArray + i) = *(arr + i) ;
	}

	delete[] arr;
	return newArray;
}

int main() {
	cout << "Increase array size" << endl;
	cout << "****************************" << endl << endl;

	//create an array of size 10, populate with random numbers between 1 and 10, and also create a variable
	// with a value of 20 to be used when creating a larger array
	int x = 10;
	int newX = 20;
	int* arr;
	arr = new int[x];
	for (int i = 0; i < x; i++) {

		*(arr + i) = rand() % 10 + 1;
	}

	//printing original array
	cout << "Printing original array of size 10." << endl;
	for (int i = 0; i < x; i++) {

		cout << *(arr + i) << " ";
	}

	//calling the increasesize function to increase the size of the array 
	cout << "\nIncreasing array size by 10 using a function, and adding digits to the empty spaces in new array.... " << endl;
	int* newArray = increaseSize(arr, x, newX);

	//populating the empty points in the new array with random numbers
	for (int i = x; i < newX; i++) {

		*(newArray + i) = rand() % 10 + 1;
	}

	//displaying new array values
	cout << "Printing new array with 10 original values and 10 new values." << endl;
	for (int i = 0; i < newX; i++) {

		cout << *(newArray + i) << " ";
	}


	delete[] newArray;
	system("pause");
	return 0;
}