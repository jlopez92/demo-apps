#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//find smallest iterates through array and finds smallest value. returns smallest
int findSmallest(const int* intArray, const int size) {
	int smallest = 1000;
	for (int i = 0; i < size; i++) {
		if (*(intArray + i) < smallest){
			smallest = *(intArray + i);
		}
		
	}
	return smallest;
}

//find largest iterates through array and finds largest value. returns largest.
int findLargest(const int* intArray, const int size) {
	int largest = -1000;
	for (int i = 0; i < size; i++) {
		if (*(intArray + i) > largest) {
			largest = *(intArray + i);
		}

	}
	return largest;
}

int main() {
	cout << "Arrays as parameters" << endl;
	cout << "*********************" << endl << endl;

	//create an array using pointers with size provided by user
	int x;
	cout << "size of array: ";
	cin >> x;

	int* arr;
	arr = new int[x];
	//input random values between -1000 and 1000 into the array
	for (int i = 0; i < x; i++) {
	
		*(arr + i) = rand() % 2000 - 1000;
	}

	cout << "\n***********************************************" << endl << endl;

	//display values in array
	for (int i = 0; i < x; i++) {

		cout << *(arr + i) << endl;
	}

	//call find smallest and largest values in array functions
	cout << "The smallest value in the array is " << findSmallest(arr, x) << "." << endl;
	cout << "The largest value in the array is " << findLargest(arr, x) << "." << endl;

	delete[] arr;
	system("pause");
	return 0;
}