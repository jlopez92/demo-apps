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

//queue class with array of pointers and a capacity data member
template<typename H>
class queue {
private:
	H* arr;
	int capacity;

	//increase size function increases the size of the array by 1
	void increaseSize() {
		//create temp array with new size
		H* newArr = new H[capacity];

		//copy values from old array to new array
		for (int i = 0; i < capacity; i++) {
			*(newArr + i) = *(arr + i);
		}

		//increase capacity of original array
		arr = new H[capacity];

		//copy values back to the data member array
		for (int i = 0; i < capacity; i++) {
			*(arr + i) = *(newArr + i);
		}

		//delete temp array
		delete[] newArr;
	}

	//decrease size function decreases the size of the array by 1
	//operates similar to increase size function
	void decreaseSize() {
		H* newArr = new H[capacity];
		for (int i = 0; i < capacity; i++) {
			*(newArr + i) = *(arr + i);
		}

		arr = new H[capacity];

		for (int i = 0; i < capacity; i++) {
			*(arr + i) = *(newArr + i);
		}
		delete[] newArr;
	}

public:
	//default constructor
	queue() {
		capacity = 0;
		arr = new H[capacity];

	}

	//push function increases the capacity by 1
	//calls increase size function
	//stores input x into the last index of the array
	void push(H x) {
		capacity++;
		increaseSize();
		*(arr + capacity) = x;
	}

	//pop stores the last value in the index
	//decreases capacity by 1
	//calls decrease function 
	//if no values left in array to pop, sends message to user
	H pop() {
		if (capacity != 0) {
			H send = *(arr + (capacity));
			capacity--;
			decreaseSize();

			return send;
		}
		else {
			cout << "no values left to remove" << endl;
			return NULL;
		}
	}


};


int main() {
	cout << "Array based queue performance test" << endl;
	cout << "***********************************" << endl << endl;
	cout << "The following program runs a series of random adds and pops to a queue." << endl;
	cout << "The duration of the test runs is timed in milliseconds." << endl;
	cout << "A final value of operations ran over duration of test value is provided." << endl << endl; 

	//initialize random seed
	srand(time(NULL));

	//initialize an instance of the queue
	queue<int> test;

	//following are ints needed for the tests
	int numOfOperations = 1000;
	int addOrRemove = 1;
	int randomValue = rand() % 100 + 1;
	int userInput;
	int sum = 0;


	cout << "Adding 50 random values to queue to begin." << endl;
	for (int i = 0; i < numOfOperations; i++) {
		randomValue = rand() % 100 + 1;
		test.push(randomValue);
	}

	cout << "how many times to run test? ";
	cin >> userInput;

	cout << "# of Operations" << setw(15) << "run time(ms)" << setw(15) << "        # of operations/run time" << endl;
	for (int i = 0; i < userInput; i++) {
		auto begin = chrono::high_resolution_clock::now();
		numOfOperations = rand() % 10000 + 1;
		for (int i = 0; i < numOfOperations; i++) {
			addOrRemove = rand() % 2 + 1;
			if (addOrRemove == 1) {
				randomValue = rand() % 100 + 1;
				test.push(randomValue);
			} else {
				test.pop();
			}
		}
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		int vOut = (int)ms;

		cout << numOfOperations << setw(25) << vOut << setw(15) << numOfOperations / vOut << endl;
		sum = sum + (numOfOperations / vOut);
	}
	cout << "The average rate of operations ran to time is " << sum / userInput << " operations per millisecond" <<  endl;

	return 0;
}