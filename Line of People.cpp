#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;

/*
	queue holds names in a vector data member
	add member function adds string to end of vector
	remove member function removes string from beginning of vector
*/
class Queue {
private:
	vector<string> names;
	int count;
public:
	Queue() {
		count = 0;
	}

	void add(string x) {
		names.push_back(x);
		count++;
	}

	string remove() {
		string name = names[0];
		names.erase(names.begin());
		return name;
	}

	bool empty() {
		if (names.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};


int main() {
	string name;
	Queue line;

	//grab names from user and add to queue instance line
	cout << "Enter names as they show up in a line. enter 'finish' to stop." << endl;
	cin >> name;
	while (name != "finish") {
		line.add(name);
		cin >> name;
	}

	cout << "\nProcessing line in order of arrival.\n" << endl;

	while (!line.empty()) {
		cout << line.remove() << " " << endl;
	}
}