#include<iostream>
using namespace std;



class Node {

	void addNode(Node* _node) {
		this->next = _node;
	}

public:
	int data;
	Node* next;

	Node(int _data) {
		data = _data;
		next = NULL;
		cout << "Node initialized with data " << data << endl;
	}



	void pushBack(int _data) {
		Node newNode(_data);
		Node* ptr;
		ptr = new Node(newNode);
		addNode(ptr);
	}

	void printChain() {
		cout << data << endl;
		cout << next->data << endl;
		cout << next->next->data << endl;
	}
};



int main() {

	Node Node(1);
	Node.pushBack(2);
	Node.pushBack(3);
	Node.pushBack(4);
	Node.pushBack(5);
	Node.pushBack(6);
	Node.pushBack(7);
	Node.pushBack(8);
	Node.pushBack(9);

	Node.printChain();


	system("pause");
	return 0;
}
