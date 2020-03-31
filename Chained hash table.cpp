#include<iostream>
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
//four data members function were added to manipulate the list anywhere in the link
//member functions are add, remove, get, and set with position locations and values if needed
template <typename T>
class SLList {
public:
	Node<T>* head;
	Node<T>* tail;
	int n;


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

	//get(i), set(i, x), add(i, x) and remove(i).

	T get(int i) {
		Node<T>* next = NULL;
		Node<T>* current;
		Node<T>* previous = NULL;
		T x;
		current = head;
		if (i == 1) {
			next = head->next;
			next = head;
			n--;
			x = current->data;
			return x;
		}
		for (int j = 1; j < i; j++) {
			previous = current;
			current = current->next;
			next = current->next;
		}
		previous->next = next;
		x = current->data;
		n--;
		return x;
	}

	void set(int i, T x) {
		Node<T>* next;
		Node<T>* current;
		Node<T>* previous;
		Node<T>* newNode = new Node<T>(x);
		current = head;
		next = head->next;
		for (int j = 1; j <= i; j++) {
			if (i == n + 1) {
				tail->next = newNode;
				tail = newNode;
			}
			else if (i > n + 1) {
				cout << "The position is longer than the chain!" << endl;
				j = i;
			}
			else if (i == 1) {
				head = newNode;
				head->next = current;
				n++;
			}
			else if (j == i) {
				previous = current;
				current = current->next;
				next = current->next;
				previous->next = newNode;
				newNode->next = current;
				n++;
			}
			else {
				previous = current;
				current = current->next;
				next = current->next;
			}
		}

	}

	void add(int i, T x) {
		Node<T>* next;
		Node<T>* current;
		Node<T>* previous;
		Node<T>* newNode = new Node<T>(x);
		current = head;
		next = head->next;
		for (int j = 1; j <= i; j++) {
			if (i == n + 1) {
				tail->next = newNode;
				tail = newNode;
			}
			else if (i > n + 1) {
				cout << "The position is longer than the chain!" << endl;
				j = i;
			}
			else if (i == 1) {
				head = newNode;
				head->next = current;
				n++;
			}
			else if (j == i) {
				previous = current;
				current = current->next;
				next = current->next;
				previous->next = newNode;
				newNode->next = current;
				n++;
			}
			else {
				previous = current;
				current = current->next;
				next = current->next;
			}
		}
	}

	bool remove(int i) {
		Node<T>* next = NULL;
		Node<T>* current;
		Node<T>* previous = NULL;
		T x;
		current = head;
		if (i == 1) {
			next = head->next;
			next = head;
			n--;
			x = current->data;
			return x;
		}
		for (int j = 1; j < i; j++) {
			previous = current;
			current = current->next;
			next = current->next;
		}
		previous->next = next;
		x = current->data;
		n--;
		return x;
	}

};

/*
Chained hash table is an array of single linked lists
SLL implemented from previous assignment
array is similar to the array based lists from previous assignments, size can be increased
a hash function determines what position the linked list will have the value added to it
a print function is also added for testing purposes
** one issue addressed in this code is the rehashing of values 
when adding original values into an increased array size
*/

template <typename T>
class ChainedHashTable {
private:

	SLList<T>* arr;
	int capacity = 15;
	int count;

	void doubleSize() {
		Node<T>* temp;
		SLList<T>* newArr = new SLList<T>[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = new SLList<T>[capacity * 2];
		capacity = capacity * 2;
		for (int i = 0; i < capacity; i++) {
			temp = newArr[i].head;
			if (temp != NULL) {
				for (int j = 0; j < newArr[i].n; j++) {
					T value = temp->data;
					add(hash(value));
					temp = temp->next;
				}
			}

		}
	}


public:
	ChainedHashTable() {
		capacity = 15;
		count = 0;
		arr = new SLList<T>[capacity];
	}

	int hash(T x) {
		int value = (32 * x) % capacity;
		return value;
	}

	bool add(T x) {
		Node<T>* temp = arr[hash(x)].head;
		if (count + 1 == capacity) {
			doubleSize();
		}

		for (int j = 0; j < arr[hash(x)].n; j++) {
			T value = temp->data;
			if (value == x) {
				cout << "Value already exists" << endl;
				return false;
			}
			temp = temp->next;
		}

		if (arr[hash(x)].head == NULL) {
			arr[hash(x)].add(x);
			count++;
			return true;
		}


		if (arr[hash(x)].head->data == x) {
			cout << "Value already exists" << endl;
			return false;
		}

		arr[hash(x)].add(x);
		count++;
		return true;
	}

	T remove(T x) {
		
		int j = hash(x);
		Node<T>* temp = arr[j].head;
		T value;
		if (arr[j].head == NULL) {
			cout << "value does not exist" << endl;
			return NULL;
		}
		for (int i = 0; i < arr[j].n; i++) {
			value = temp->data;
			if (hash(value) == j) {
				if (arr[j].n == 1) {
					T y = arr[j].get(i + 1);
					count--;
					return value;
				}
				arr[j].get(i);
				count--;
				return value;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void print() {
		for (int i = 0; i < capacity; i++) {
			Node<T>* temp = arr[i].head;
			cout << "Position: " << i << "    Value:";
			if (temp == NULL) {
				
			}
			else {
				for (int j = 0; j < arr[i].n; j++) {
					T value = temp->data;
					cout <<" " << value;
					temp = temp->next;
				}
			}
			cout << endl;
		}
	}
};

//simple menu for user
void menu() {
	cout << "\nchoose from the following options: " << endl;
	cout << "1. Add value" << endl;
	cout << "2. remove value" << endl;
	cout << "3. Print hash table with values" << endl;
	cout << "0. Quit" << endl;
}
int main() {
	ChainedHashTable<int> test;

	int userChoice;
	menu();
	cout << "Choice: ";
	cin >> userChoice;
	while (userChoice != 0) {
		if (userChoice == 1) {
			//add value
			int userValue;
			cout << "Enter value to add: " << endl;
			cin >> userValue;
			test.add(userValue);
		}
		else if (userChoice == 2) {
			//remove value if exists
			int userValue;
			cout << "enter value to remove" << endl;
			cin >> userValue;
			test.remove(userValue);
		}
		else if (userChoice == 3) {
			//print table
			test.print();
		}
		else {
			cout << "invalid choice. please try again!" << endl;
		}

		menu();
		cout << "Choice: ";
		cin >> userChoice;
	}

	return 0;
}