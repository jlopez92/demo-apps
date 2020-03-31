#include<iostream>
#include<vector>
using namespace std;

/*
*Node class holds the given data and two node pointers
*two node pointers point to next and previous nodes
*two constructors exist, a default constructor that doesn't set the data
*one arg constructor sets the data
*/
template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* previous;

	Node() {
		next = NULL;
		previous = NULL;
	}

	Node(T x) {
		data = x;
		next = NULL;
		previous = NULL;
	}
};

/*
*DLList contains a dummy node and a n int to count number of nodes
*default constructor points the dummy next and dummy previous to itself
*initializes n to zero
*Standard list methods include push, add, pop, remove
*additionally a set method sets a value anywhere in the list
*a get method grabs any value from anywhere in the list
*a print and print reverse method has been implimented
*check size method confirms n is equal to number of nodes
*isEmpty checks to see if the list is empty
*isPalindrome added to methods. checks to see if items in list are a palindrome
*/
template <typename T>
class DLList {
	int n;
	Node<T>* dummy;
public:
	DLList() {
		dummy = new Node<T>;
		dummy->next = dummy;
		dummy->previous = dummy;
		n = 0;
	}

	void push(T x) {
		Node<T>* newNode = new Node<T>(x);
		if (n == 0) {
			dummy->next = newNode;
			dummy->previous = newNode;
			newNode->next = dummy;
			newNode->previous = dummy;
		}
		else {
			dummy->next->previous = newNode;
			newNode->next = dummy->next;
			newNode->previous = dummy;
			dummy->next = newNode;
		}
		n++;
	}

	void add(T x) {
		Node<T>* newNode = new Node<T>(x);
		if (n == 0) {
			dummy->next = newNode;
			dummy->previous = newNode;
			newNode->next = dummy;
			newNode->previous = dummy;
		}
		else {
			dummy->next->previous = newNode;
			newNode->next = dummy->next;
			newNode->previous = dummy;
			dummy->next = newNode;
		}
		n++;
	}

	T pop() {
		T data = dummy->next->data;
		if (n < 2) {
			dummy->next = dummy->next->next;
			dummy->previous = dummy->previous->previous;
		}
		else {
			dummy->next = dummy->next->next;
		}
		n--;
		return data;

	}

	T remove() {
		T data = dummy->previous->data;
		if (n < 2) {
			dummy->next = dummy->next->next;
			dummy->previous = dummy->previous->previous;
		}
		else {
			dummy->previous = dummy->previous->previous;
		}
		n--;
		return data;
	}

	void set(int i, T x) {
		Node<T>* newNode = new Node<T>(x);

		Node<T>* previous = NULL;
		Node<T>* temp = dummy;
		Node<T>* next = NULL;
		if (i == 1) {
			newNode->next = dummy->next;
			newNode->previous = dummy;
			dummy->next = newNode;
		}
		else {
			for (int j = 0; j < i; j++) {
				temp = temp->next;
			}
			previous = temp->previous;
			next = temp->next;
			previous->next = newNode;
			newNode->next = temp;
			newNode->previous = previous;
			temp->previous = newNode;
		}
		n++;
	}

	T get(int i) {
		if (i > n) {
			throw 1;
		}
		Node<T>* previous = NULL;
		Node<T>* temp = dummy;
		Node<T>* next = NULL;
		for (int j = 0; j < i; j++) {
			temp = temp->next;
		}
		T x = temp->data;
		previous = temp->previous;
		next = temp->next;
		previous->next = next;
		next->previous = previous;
		n--;
		return x;
	}

	void print() {
		Node<T>* temp;
		temp = dummy->next;
		for (int i = 0; i < n; i++) {
			cout << temp->data << " ";
			temp = temp->next;
		}

	}

	void printReverse() {
		Node<T>* temp;
		temp = dummy->previous;
		for (int i = 0; i < n; i++) {
			cout << temp->data << " ";
			temp = temp->previous;
		}
	}

	bool checkSize() {
		Node<T>* temp = dummy;
		int count = 0;
		int i = 1;
		while (temp->next != dummy) {
			count++;
			temp = temp->next;
		}

		if (count == n) {
			cout << "Size matches" << endl;
			return true;
		}
		else {
			cout << "size does not match" << endl;
			return false;
		}
	}

	bool isEmpty() {
		if (n != 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isPalindrome() {
		Node<T>* tempFace = dummy->next;
		Node<T>* tempTail = dummy->previous;
		int count = n / 2;
		for (int i = 0; i <= count; i++) {
			if (tempFace->data != tempTail->data) {
				cout << "This is not a palindrome!" << endl;
				return false;
			}
			tempFace = tempFace->next;
			tempTail = tempTail->previous;
		}
		cout << "This is a palindrome!" << endl;
		return true;
	}

	DLList<T> truncate(int i) {
		DLList<T> newList;
		int numberOfValues = n - i;
		for (int j = n; j >= i; j--) {
			T dataPoint = this->get(j);
			newList.add(dataPoint);
		}
		

		return newList;
	}

	void absorb(DLList<T> absorbed) {
		while (absorbed.isEmpty()) {
			T dataPoint = absorbed.pop();
			add(dataPoint);
		}
	}

};

//simple menu for user 
void printMenu() {
	cout << "\nChoose an item from the menu and enter the integer" << endl;
	cout << "1: push" << endl;
	cout << "2: add" << endl;
	cout << "3: pop" << endl;
	cout << "4: remove" << endl;
	cout << "5: set(value into position)" << endl;
	cout << "6: get(from position)" << endl;
	cout << "7: print" << endl;
	cout << "8: print Reverse" << endl;
	cout << "9: check size" << endl;
	cout << "10: check if Empty" << endl;
	cout << "11: check if values in list are a palindrome" << endl;
	cout << "0: quit" << endl;
}

int main() {
	int userInput;

	cout << "Initializing an instance of the DLList of type integer..." << endl;
	DLList<int> test;
	DLList<int> test2;
	cout << "Initializing list 1 with 5 integers..." << endl;
	test.add(1);
	test.add(2);
	test.add(3);
	test.add(2);
	test.add(1);

	cout << "Initializing list 2 with 5 integers..." << endl;
	test2.add(9);
	test2.add(8);
	test2.add(7);
	test2.add(8);
	test2.add(9);

	cout << "\nPrinting list 1" << endl;
	test.print();
	cout << "\nprinting list 2" << endl;
	test2.print();

	cout << "\n absorbing list 2 to list 1 and printing" << endl;
	test.absorb(test2);
	test.print();
	cout << endl;

	cout << "truncate new list at any position. Enter position: ";
	cin >> userInput;
	DLList<int> test3 = test.truncate(userInput);
	cout << "printing original list..." << endl;
	test.print();
	cout << "\n printing new list..." << endl;
	test3.print();

	cout << "\nBegin playing with list." << endl << endl;
	printMenu();
	cout << "choice:";
	cin >> userInput;

	while (userInput != 0) {


		if (userInput == 1) {
			//push
			int temp;
			cout << "enter value of new node";
			cin >> temp;
			test.push(temp);
			cout << endl;
		}
		else if (userInput == 2) {
			//add
			int temp;
			cout << "enter value of new node";
			cin >> temp;
			test.add(temp);
			cout << endl;
		}
		else if (userInput == 3) {
			//pop
			try {
				if (!test.isEmpty()) {
					throw 1;
				}
				int temp;
				temp = test.pop();
				cout << "Value 'popped': " << temp << endl;
				cout << endl;
			}
			catch (int i) {
				std::cout << "An error exception was thrown, the list is empty." << '\n';
			}

		}
		else if (userInput == 4) {
			//remove
			try {
				if (!test.isEmpty()) {
					throw 1;
				}
				int temp;
				temp = test.remove();
				cout << "Value 'removed': " << temp << endl;
				cout << endl;
			}
			catch (int i) {
				cout << "An error exception was thrown, the list is empty." << '\n';
			}
		}
		else if (userInput == 5) {
			//set
			int temp, temp2;
			cout << "enter value of new node: ";
			cin >> temp;
			cout << "enter position in which to enter new value: ";
			cin >> temp2;
			test.set(temp2, temp);
			cout << endl;
		}
		else if (userInput == 6) {
			//get
			try {
				if (!test.isEmpty()) {
					throw 1;
				}
				int temp;
				cout << "enter position to remove from: ";
				cin >> temp;
				test.get(temp);
				cout << endl;
			}
			catch (int i) {
				if (i == 1) {
					cout << "An error exception was thrown, the list is empty." << '\n';
				}
				else {
					cout << "An error exception was thrown, the position does not exist" << endl;
				}
			}
		}
		else if (userInput == 7) {
			//print
			test.print();
			cout << endl;
		}
		else if (userInput == 8) {
			//print reverse
			test.printReverse();
			cout << endl;
		}
		else if (userInput == 9) {
			//check size
			if (test.checkSize()) {
				cout << "list size and node amounts match." << endl;
			}
			else {
				cout << "list size and node amounts do not match." << endl;
			}
			cout << endl;
		}
		else if (userInput == 10) {
			//check is empty
			if (test.isEmpty()) {
				cout << "List is not empty" << endl;
			}
			else {
				cout << "List is empty" << endl;
			}
		}
		else if (userInput == 11) {
			//check for palindrome
			test.isPalindrome();
			cout << endl;
		}
		else {
			cout << "invalid entry! try again!" << endl;
			cout << endl;
		}


		printMenu();
		cout << "choice:";
		cin >> userInput;
	}

	return 0;
}