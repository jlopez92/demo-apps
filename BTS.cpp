#include<iostream>
#include<vector>
#include<stdio.h>     
#include<stdlib.h>   
#include<string>
#include<algorithm>
using namespace std;

//compare function used to compare values in the BTS class
int compare(int x, int y) {
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	else {
		return 0;
	}
}

//simple node class that holds the left and right child 
//as well as the parent
template <typename T>
class Node {
public:
	T x;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	Node() {
		left = right = parent = NULL;
		this->x = x;
	}
};

//queue class used to do the breadth first traverse
template <typename T>
class queue {
private:
	T* arr;
	int capacity;
	int count;

	//increase size function increases the size of the array by 1
	void increaseSize() {
		//create temp array with new size
		T* newArr = new T[capacity];

		//copy values from old array to new array
		for (int i = 0; i < capacity; i++) {
			*(newArr + i) = *(arr + i);
		}

		//increase capacity of original array
		arr = new T[capacity];

		//copy values back to the data member array
		for (int i = 0; i < capacity; i++) {
			*(arr + i) = *(newArr + i);
		}

		//delete temp array
		delete[] newArr;
	}


public:
	//default constructor
	queue() {
		capacity = 20;
		count = 0;
		arr = new T[capacity];

	}

	//push function increases the capacity by 1
	//calls increase size function
	//stores input x into the last index of the array
	void push(T x) {
		if (count == capacity) {
			increaseSize();
		}
		*(arr + count) = x;
		count++;
	}

	//pop stores the last value in the index
	//decreases capacity by 1
	//calls decrease function 
	//if no values left in array to pop, sends message to user
	T pop() {
		if (capacity != 0) {
			T send = *(arr + (count - 1));
			count--;
			return send;
		}
		else {
			cout << "no values left to remove" << endl;
			return NULL;
		}
	}

	int size() {
		return count;
	}

};

//binary search tree holds the root node and a n counter variable
//program is contains three assignments each seperated by a comment
/*
*Three private member functions created to support public member functions
*all member functions are created through pointer manipulation
*size member functin uses recursion to find the size of the tree(number of nodes)
*height member function finds the longest chain of the tree to return the number of levels in the tree
*add child finds home of new data based on a comparison of values
*search methods are added to traverse the tree and find various values or values closest to the input value
*additionally, a depth function finds what level a particular value sits at
*/
template <typename T>
class BinarySearchTree {
private:
	Node<T>* r;
	int n;

	Node<T>* findLast(T x) {
		Node<T>* w = r, * prev = NULL;
		while (w != NULL) {
			prev = w;
			int comp = compare(x, w->x);
			if (comp < 0) {
				w = w->left;
			}
			else if (comp > 0) {
				w = w->right;
			}
			else {
				return w;
			}
		}
		return prev;
	}

	bool addChild(Node<T>* p, Node<T>* u) {
		if (p == NULL) {
			r = u; // inserting into empty tree
		}
		else {
			int comp = compare(u->x, p->x);
			if (comp < 0) {
				p->left = u;
			}
			else if (comp > 0) {
				p->right = u;
			}
			else {
				return false;
			}
			u->parent = p;
		}
		n++;
		return true;
	}

	int size(Node<T>* u) {
		if (u == NULL) {
			return 0;
		}
		return 1 + size(u->left) + size(u->right);
	}

	//assignment 2
	int height(Node<T>* u) {
		if (u == NULL) {
			return -1;
		}
		return 1 + max(height(u->left), height(u->right));
	}

public:
	BinarySearchTree() {
		r = NULL;
		n = 0;
	}

	bool add(T x) {
		Node<T>* p = findLast(x);
		Node<T>* u = new Node<T>;
		u->x = x;
		return addChild(p, u);
	}

	int size() {
		Node<T>* u = r, * prev = NULL, * next;
		int n = 0;
		while (u != NULL) {
			if (prev == u->parent) {
				n++;
				if (u->left != NULL) {
					next = u->left;
				}
				else if (u->right != NULL) {
					next = u->right;
				}
				else {
					next = u->parent;
				}
			}
			else if (prev == u->left) {
				if (u->right != NULL) {
					next = u->right;
				}
				else {
					next = u->parent;
				}
			}
			else {
				next = u->parent;
			}
			prev = u;
			u = next;
		}
		return n;
	}

	//assignment 2
	void bfPrint() {
		queue<Node<T>*> q;
		if (r != NULL) {
			q.push(r);
		}

		while (q.size() > 0) {
			Node<T>* u = q.pop();
			cout << u->x << " ";
			if (u->left != NULL) {
				q.push(u->left);
			}
			if (u->right != NULL) {
				q.push(u->right);
			}
		}
		cout << endl;
	}

	int height() {
		return height(r);
	}

	//assignment 3
	T findEQ(T x) {
		Node<T>* w = r;
		while (w != NULL) {
			int comp = compare(x, w->x);
			if (comp < 0) {
				w = w->left;
			}
			else if (comp > 0) {
				w = w->right;
			}
			else {
				return w->x;
			}
		}
		return NULL;
	}

	T findLT(T x) {
		Node<T>* w = r;
		Node<T>* z = NULL;
		while (w != NULL) {
			int comp = compare(x, w->x);
			if (comp < 0) {
				cout << "left" << endl;
				if (w->x < x) {
					z = w;
				}
				w = w->left;

			}
			else if (comp > 0) {
				cout << "right" << endl;
				if (w->x < x) {
					z = w;
				}
				w = w->right;

			}
			else {
				return w->x;
			}
		}
		return z == NULL ? NULL : z->x;
	}

	T findGT(T x) {
		Node<T>* w = r;
		Node<T>* z = NULL;
		while (w != NULL) {
			int comp = compare(x, w->x);
			if (comp < 0) {
				if (x < w->x) {
					z = w;
				}
				w = w->left;
			}
			else if (comp > 0) {
				if (x < w->x) {
					z = w;
				}
				w = w->right;

			}
			else {
				return w->x;
			}
		}
		return z == NULL ? NULL : z->x;
	}

	int depth(Node<T>* u) {
		int d = 0;
		while (u != r) {
			u = u->parent;
			d++;
		}
		return d;
	}

	int depth(T x) {
		if (findEQ(x) != x) {
			return 0;
		}
		Node<T>* w = r;
		while (w != NULL) {
			int comp = compare(x, w->x);
			if (comp < 0) {
				w = w->left;
			}
			else if (comp > 0) {
				w = w->right;
			}
			else {
				return depth(w);
			}
		}
		return 0;
	}

};

void printMenu() {
	cout << "\n1: findEQ(x)" << endl;
	cout << "2: findGT(x)" << endl;
	cout << "3: findLT(x)" << endl;
	cout << "4: depth(x)" << endl;
	cout << "5: print" << endl;
	cout << "0: Quit" << endl;
}

int main() {
	cout << "Testing the Binary search tree" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n" << endl;

	cout << "Assignment 1" << endl;
	cout << "************" << endl;
	cout << "BST's Adding Nodes" << endl << endl;
	BinarySearchTree<int> assignment1;

	for (int i = 0; i < (rand() % 10) + 10; i++) {
		int addValue = rand() % 20;
		addValue = addValue - 10;
		assignment1.add(addValue);
		cout << "value " << addValue << " added to tree." << endl;
	}

	cout << "\nSize method output: " << assignment1.size() << endl << endl;

	cout << "Assignment 2" << endl;
	cout << "************" << endl;
	cout << "Breadth first print" << endl << endl;
	BinarySearchTree<int> assignment2;

	for (int i = 0; i < (rand() % 5) + 5; i++) {
		int addValue = rand() % 20;
		addValue = addValue - 10;
		assignment2.add(addValue);
		cout << "value " << addValue << " added to tree." << endl;
	}

	cout << "\nPrinting the values of the tree: ";
	assignment2.bfPrint();
	cout << "The height of the tree is: " << assignment2.height() << endl << endl;

	cout << "Assignment 3" << endl;
	cout << "************" << endl;
	cout << "Breadth first print" << endl << endl;
	BinarySearchTree<int> assignment3;

	for (int i = 0; i < (rand() % 5) + 5; i++) {
		int addValue = rand() % 20;
		addValue = addValue - 10;
		assignment3.add(addValue);
		cout << "value " << addValue << " added to tree." << endl;
	}

	cout << "\nPrinting the values of the tree: ";
	assignment3.bfPrint();
	cout << "Search tree at will. Choose from the following menu." << endl;
	int userChoice;
	printMenu();
	cout << "Choose option: ";
	cin >> userChoice;

	while (userChoice != 0) {
		if (userChoice == 1) {
			//findEQ
			int userInput;
			cout << "Enter value: ";
			cin >> userInput;
			cout << "Value found: " << assignment3.findEQ(userInput);
		}
		else if (userChoice == 2) {
			//findGT
			int userInput;
			cout << "Enter value: ";
			cin >> userInput;
			cout << "Value found: " << assignment3.findGT(userInput);
		}
		else if (userChoice == 3) {
			//findLT
			int userInput;
			cout << "Enter value: ";
			cin >> userInput;
			cout << "Value found: " << assignment3.findLT(userInput);
		}
		else if (userChoice == 4) {
			//depth
			int userInput;
			cout << "Enter value: ";
			cin >> userInput;
			cout << "Value found: " << assignment3.depth(userInput);
		}
		else if (userChoice = 5) {
			assignment3.bfPrint();
		}
		else {
			cout << "Invalid input, try again." << endl;
		}
		printMenu();
		cout << "Choose option: ";
		cin >> userChoice;
	}

	return 0;
}