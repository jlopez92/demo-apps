#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;

//template to be able to use different data types on class
template <typename T>

/*
	PriorityQueue class has two data members
	vector holds the priority number of items
	count holds how many values have been added to vector
	add function member adds value to vector, and removes after every third add
	delete function member finds and deletes lowest value in vector
	print functin member prints values left in vector
*/
class PriorityQueue {
private:
	vector<T> priorityLine;
	int count;
public:
	PriorityQueue() {
		count = 0;
	}

	void add(int x) {
		cout << "Adding patient, priority = " << x << endl;
		priorityLine.push_back(x);
		count++;
		print();
		if (count % 3 == 0) {
			deleteMin();
		}
	}

	void deleteMin() {
		int lowestElement;
		lowestElement = *min_element(priorityLine.begin(), priorityLine.end());
		for (int i = 0; i < priorityLine.size(); i++) {
			if (lowestElement == priorityLine[i]) {
				cout << "Admitting patient to triage, priority = " << priorityLine[i] << endl;
				priorityLine.erase(priorityLine.begin() + i);
				break;
			}
		}
		print();
	}

	void print() {
		cout << "Current queue: ";
		for (int i = 0; i < priorityLine.size(); i++) {
			cout << priorityLine[i] << " ";
		}
		cout << endl;
	}

};

int main() {
	cout << "Emergency Room Waiting Area" << endl;
	cout << "***************************" << endl << endl;

	//creating an instance of the priority queue class
	PriorityQueue<int> test;
	int priority;

	//grabbing priority numbers from user
	cout << "Enter the priority (int > 0) for next patient." << endl;
	cout << "Enter 0 to exit program." << endl << endl;
	cin >> priority;
	while (priority != 0) {
		test.add(priority);
		cin >> priority;
	}

	//printing remainder of patients still in queue
	cout << "Processing remainder of the patients" << endl;
	test.print();
	return 0;
}
