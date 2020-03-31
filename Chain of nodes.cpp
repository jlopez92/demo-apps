#include<iostream>
using namespace std;

/*
*Created a class of type node with two public data members.
*One data member is an int, the other is a node pointer.
*The constructor takes in a int to assign to the data member and sets the pointer to null.
*A function member sets next to an input parameter of type node. 
*/

class Node {
public:
	int data;
	Node* next;

	Node(int _data) {
		data = _data;
		next = NULL;
		cout << "Node initialized with data " << data << endl;
	}

	void addNode(Node* _node){
		this->next = _node;

	}
};



int main() {

	//create an array to hold the 10 nodes 

	

	Node* nodes[10];
	cout << "Creating nodes" << endl;
	cout << "*************" << endl;
	//create nodes and link them together
	for (int i = 0; i < 10; i++) {
		*(nodes + i) = new Node(i + 1);
		if (i > 0) {
			nodes[i - 1]->addNode(nodes[i]);
		}
	}

	//displaying nodes 
	cout << "\n\n Displaying data points in each node again" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Node " << i + 1 << " contains data point " << nodes[i]->data << endl;
	}

	//displaying node locations
	cout << "\n\n Displaying node location" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Node " << i << " location " << *(nodes + i) << " Linked to " << nodes[i]->next << endl;
	}
	

	system("pause");
	return 0;
}
