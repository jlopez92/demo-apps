#include<iostream>
#include<vector>
using namespace std;

//template typename gives the option to use any type 
template<typename T>

//class takes in any variable type and creates a queue where first in is first out
class Queue {
private:
	vector<T> vec;
public:
	Queue() {

	}
	void add(T x) {
		vec.insert(vec.begin(), x);
	}
	void remove() {
		vec.pop_back();
	}

	int getCount() {
		return vec.size();
	}

	void printQueue() {
		for (unsigned int i = 0; i < vec.size(); i++) {
			cout << " " << vec[i] << " ";
		}
		cout << endl;
	}
};

//menu choices for adding removing or printing the line
string menu() {
	string userInput;
	cout << "\ntype 'print', 'remove', 'add', or 'quit'" << endl;
	cout << "choice: ";
	cin >> userInput;
	cout << endl;
	return userInput;
}

int main() {
	cout << "Wait patiantly in line! No cutting" << endl << endl;
	Queue<string> line;
	string person;
	string userInput = "add";
	cout << "Line starts here. add person to line!" << endl;
	//testing the queue class
	while (userInput != "quit") {


		if (userInput == "add") {
			cout << "person name: ";
			cin >> person;
			line.add(person);
			userInput = menu();
		}
		else if (userInput == "remove") {
			if (line.getCount() == 0) {
				cout << "nobody is in line" << endl;
				userInput = menu();
			}
			else {
				line.remove();
				userInput = menu();
			}
		}
		else if (userInput == "quit") {

		}
		else if (userInput == "print") {
			line.printQueue();
			userInput = menu();
		}
		else {
			cout << "Invalid input, please try again!" << endl;
			userInput = menu();
		}
	}

	return 0;
}