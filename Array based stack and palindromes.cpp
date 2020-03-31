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

template<typename T>
class stack {
private:
	T* arr;
	int capacity;
	int counter;

	void doubleSize() {
		T* newArr = new T[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			*(newArr + i) = *(arr + i);
		}
		delete[] arr;
		arr = new T[capacity * 2];


		for (int i = 0; i < capacity; i++) {
			*(arr + i) = *(newArr + i);
		}
		delete[] newArr;
		capacity = capacity * 2;

	}
public:
	stack() {
		capacity = 5;
		counter = 0;
		arr = new T[capacity];

	}

	void push(T x) {
		if (counter == capacity) {
			doubleSize();
		}
		*(arr + counter) = x;
		counter++;
	}

	T pop() {
		T send = *(arr + (counter));

		*(arr + (counter)) = "";
		counter--;

		return send;
	}

	bool isEmpty() {
		if (counter >= 0) {
			return true;
		}
		else {
			return false;
		}
	}



};

int main() {

	cout << "Palindrome?" << endl;
	cout << "***********" << endl << endl;
	cout << "This program checks to see if the word you enter is a palindrome" << endl;

	//creating a string to hold the users word, and a second to hold the word in reverse
	//also creating an instance of stack
	string userWord, check;
	stack<string> test;

	//grabbing palindrome word from user
	cout << "enter a word or sentence to check for palindrome: ";
	getline(cin, userWord);

	//iterate through userWord string and push each character to test stack
	for (int i = 0; i < userWord.length(); i++) {
		char c = userWord[i];
		string s(1, c);
		test.push(s);
	}
	
	//pop out all characters from test stack and store the characters in check string
	while (test.isEmpty()) {
		check.append(test.pop());
	}

	//display the users word in reverse and check to see if it's a palindrome
	cout << check << endl;
	if (check == userWord) {
		cout << "your word is a palindrome" << endl;
	}
	else {
		cout << "word is not a palindrome" << endl;
	}

	return 0;
}