#include<iostream>
using namespace std;



int main() {
	cout << "Using dynamic memory allocation to create an array." << endl;
	cout << "***************************************************" << endl << endl;

	//create an array using pointer and grabbing the size of the array from the user
	int x;
	cout << "size of array: ";
	cin >> x;
	int* arr;
	arr = new int[x];

	//input each value in array by user input values
	for (int i = 0; i < x; i++) {
		cout << "what is int " << i + 1 << ": ";
		cin >> *(arr + i);
	}

	cout << "\n***********************************************" << endl << endl;

	//calculate average
	double average = 0;
	for (int i = 0; i < x; i++) {
		average = average + *(arr + i);
	}
	average = average / x;

	//find number of values above the average
	int count= 0;
	for (int i = 0; i < x; i++) {
		if (average < *(arr + i)) {
			count = count + 1;
		}
	}

	cout << "The average of the numbers in the array is " << average << endl;
	cout << "The numbers above the average of the array are " << count << endl;

	delete[] arr;
	system("pause");
	return 0;
}