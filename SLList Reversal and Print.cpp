#include<iostream>
#include<vector>
using namespace std;

//Node class holds the data inside each node
//also links the node to the next one in the chain
template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node(T data) {
		this->data = data;
		next = NULL;
	}
};

//SLList is used to manipulate the linked list
//3 data memnbers include the number of nodes created
//a pointer to the head of the list and a pointer to the tail
//basic member functions include push, pop, add, remove
//a member function second last is used to get the data of the second to last node
//additionally a reverse member function reverses the order of the list
//a print function prints out the list in order
template <typename T>
class SLList {
private:
	Node<T>* head;
	Node<T>* tail;
	int n;
public:

	SLList() {
		n = 0;
		head = NULL;
		tail = NULL;
	}

	void push(T x) {
		Node<T>* u = new Node<T>(x);
		u->next = head;
		head = u;
		if (n == 0) {
			tail = u;
		}
		n++;
	}

	T pop() {
		if (n == 0) {
			return NULL;
		}
		T x = head->data;
		Node<T>* u = head;
		head = head->next;
		delete u;
		n--;
		if (n == 0) {
			tail = NULL;
		}
		return x;

	}

	void add(T x) {

		Node<T>* u = new Node<T>(x);
		if (n == 0) {
			head = u;
		}
		else {
			tail->next = u;
		}
		tail = u;
		n++;
	}

	T remove() {
		if (n == 0) {
			return NULL;
		}
		T x = head->data;
		Node<T>* u = head;
		head = head->next;
		n--;
		delete u;
		if (n == 0) {
			tail = NULL;
		}
		return x;
	}

	T secondLast() {
		Node<T>* u = head;
		while (u->next->next != NULL) {
			u = u->next;
		}
		T x = u->data;
		return x;
	}

	bool isEmpty() {
		if (n == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void reverse() {
		Node<T>* next;
		Node<T>* temp;
		Node<T>* previous;

		temp = head;
		next = head->next;
		head->next = NULL;
		previous = head;
		temp = next;
		next = temp->next;
		while (next->next != NULL) {
			temp->next = previous;
			previous = temp;
			temp = next;
			next = temp->next;
		}
		temp->next = previous;
		next->next = temp;
		head = next;

	}

	void print() {
		Node<T>* temp;
		temp = head;
		while (temp->next != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
};

//simple menu void function
void printMenu() {
	cout << "\nChoose an item from the menu and enter the integer" << endl;
	cout << "1: push" << endl;
	cout << "2: pop" << endl;
	cout << "3: add" << endl;
	cout << "4: remove" << endl;
	cout << "5: reverse" << endl;
	cout << "6: print" << endl;
	cout << "0: quit" << endl;
}

int main() {

	cout << "Initiating a stack with 5 integers to begin..." << endl;
	SLList<int> stack;

	for (int i = 5; i < 10; i += 1) {
		stack.push(i);
	}

	int userInput;
	cout << "Choose an option from the menu to begin manipulating the stack." << endl;
	printMenu();
	cout << "Choice: ";
	cin >> userInput;
	while (userInput != 0){
		if (userInput == 1) {
			int temp;
			cout << "enter integer to push a new node" << endl;
			cin >> temp;
			stack.push(temp);
		} else if (userInput == 2) {
			int temp;
			temp = stack.pop();
			cout << "Value 'popped': " << temp << endl;
		}
		else if (userInput == 3) {
			int temp;
			cout << "enter integer to add a new node" << endl;
			cin >> temp;
			stack.push(temp);
		}
		else if (userInput == 4) {
			int temp;
			temp = stack.remove();
			cout << "Value 'removed': " << temp << endl;
		}
		else if (userInput == 5) {
			stack.reverse();
			cout << "\nreverse complete" << endl;
		}
		else if (userInput == 6) {
			stack.print();
		}

		printMenu();
		cout << "Choice: ";
		cin >> userInput;
	}

	return 0;
}