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
};

int main() {

	SLList<int> stack;
	SLList<int> queue;

	cout << "Enter 5 integers seperated by spaces to add to the stack and queue." << endl;
	cout << "values: ";
	for (int i = 0; i < 5; i++) {
		int j;
		cin >> j;
		stack.push(j);
		queue.add(j);
		cout << j << " ";
	}

	cout << endl << "second to last value in stack: " << stack.secondLast() << endl;
	cout << "second to last value in Queue: " << queue.secondLast() << endl;

	cout << endl << "using pop to empty stack" << endl;
	while (!stack.isEmpty()) {
		cout << stack.pop() << " ";
	}

	cout << "\nusing remove to empty Queue" << endl;
	while (!queue.isEmpty()) {
		cout << queue.remove() << " ";
	}

	return 0;
}