#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;

/*
	stack class holds numbers in a vector 
	push member function adds number to vector
	pop member function removes last digit in vecter
*/
class stack {
private:
	vector<int> numbers;
	int count;
public:
	stack() {
		count = 0;
	}

	void push(int x) {
		numbers.push_back(x);
		count++;
	}

	int pop() {
		int value = numbers.back();
		numbers.pop_back();
		return value;
	}

	bool empty() {
		if (numbers.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	stack test;
	int userInput;
	//grab values from user and push to instance of stack test
	cout << "Enter number (0 to quit): " << endl;
	cin >> userInput;
	while (userInput != 0) {
		test.push(userInput);
		cin >> userInput;
	}

	//print values in reverse order
	cout << "\nYour values in reverse order." << endl;
	while (!test.empty()) {
		cout << test.pop() << " ";
	}


	return 0;
}