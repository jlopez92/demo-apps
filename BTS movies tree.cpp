#include<iostream>
#include<fstream>
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

int compare(string x, string y) {
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
	T movieName;
	T movieYear;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	Node() {
		left = right = parent = NULL;
	}
	Node(T name, T year) {
		left = right = parent = NULL;
		movieName = name;
		movieYear = year;
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
all member functions are created through pointer manipulation
bool add function adds a node by traversing the tree and finding where to allocate it 
based on a Null leaf and traversing alphabetically
size function finds the the number of nodes and returns the value
bfprint, prints the values in the node in order, parent, to child level by level

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
			int comp = compare(x, w->movieName);
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
			int comp = compare(u->movieName, p->movieName);
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
		u->movieName = x;
		return addChild(p, u);
	}

	bool add(T x, T y) {
		Node<T>* p = findLast(x);
		Node<T>* u = new Node<T>;
		u->movieName = x;
		u->movieYear = y;
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

	void bfPrint() {
		queue<Node<T>*> q;
		if (r != NULL) {
			q.push(r);
		}

		while (q.size() > 0) {
			Node<T>* u = q.pop();
			cout << u->movieName << " year: " << u->movieYear << endl;
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

	//finds exact node by movie title
	T findEQ(T x) {
		Node<T>* w = r;
		while (w != NULL) {
			int comp = compare(x, w->movieName);
			if (comp < 0) {
				w = w->left;
			}
			else if (comp > 0) {
				w = w->right;
			}
			else {
				return w->movieName;
			}
		}
		return NULL;
	}

	T findLT(T x) {
		Node<T>* w = r;
		Node<T>* z = NULL;
		while (w != NULL) {
			int comp = compare(x, w->movieName);
			if (comp < 0) {
				if (w->movieName < x) {
					z = w;
				}
				w = w->left;

			}
			else if (comp > 0) {
				if (w->movieName < x) {
					z = w;
				}
				w = w->right;

			}
			else {
				return w->movieName;
			}
		}
		return z == NULL ? NULL : z->movieName;
	}

	T findGT(T x) {
		Node<T>* w = r;
		Node<T>* z = NULL;
		while (w != NULL) {
			int comp = compare(x, w->movieName);
			if (comp < 0) {
				if (x < w->movieName) {
					z = w;
				}
				w = w->left;
			}
			else if (comp > 0) {
				if (x < w->movieName) {
					z = w;
				}
				w = w->right;

			}
			else {
				return w->movieName;
			}
		}
		return z == NULL ? NULL : z->movieName;
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
			int comp = compare(x, w->movieName);
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
	cout << "6: add movie" << endl;
	cout << "0: Quit" << endl;
}

int main() {

	BinarySearchTree<string> movies;
	ifstream inFile("movies.txt");
	string name, year;
	cout << "Creating a tree with Marvel Movies" << endl;
	cout << "**********************************" << endl;
	while (getline(inFile, name)) { 	//geline grabs each line from the file and stores it in the word variable
		getline(inFile, year);
		movies.add(name, year); //the word is added to BTS tree
		cout << "added Movie: " << name << " of Year: " << year << endl;
	}

	cout << "\n begin playing with the tree" << endl << endl;

	int userChoice;
	printMenu();
	cout << "Choose option: ";
	cin >> userChoice;

	while (userChoice != 0) {
		if (userChoice == 1) {
			//findEQ
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string userInput;
			cout << "Enter movie name: ";
			getline (cin, userInput);
			cout << "Movie found: " << movies.findEQ(userInput);
		}
		else if (userChoice == 2) {
			//findGT
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string userInput;
			cout << "Enter MovieName: ";
			getline (cin, userInput);
			cout << "Movie found: " << movies.findGT(userInput);
		}
		else if (userChoice == 3) {
			//findLT
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string userInput;
			cout << "Enter Movie NAme: ";
			getline (cin, userInput);
			cout << "Movie found: " << movies.findLT(userInput);
		}
		else if (userChoice == 4) {
			//depth
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string userInput;
			cout << "Enter Movie name: ";
			getline (cin, userInput);
			cout << "Movie found: " << movies.depth(userInput);
		}
		else if (userChoice == 5) {
			movies.bfPrint();
		}
		else if (userChoice == 6) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string userInput;
			cout << "Enter Movie to add: ";
			getline(cin, userInput);
			movies.add(userInput);
			cout << "Movie Added" << endl;
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