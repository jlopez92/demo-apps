#include<iostream>;
#include<string>;
using namespace std;

//prints description of program
void intro() {
	cout << "Recursive String Reversal" << endl;
	cout << "*************************\n" << endl;
	cout << "The following program takes in a line of text and reverses it." << endl;
	cout << "To begin, enter a line of text. To quit the program, type quit.\n" << endl;
}

//void function prints out each letter of the input text in reverse order using recursion until the entire text has been input.
//the function prints out the last character in the line, then recalls itself using the line minus the last character in that text.
void reverseDisplay(const string& s) {
	if (s.length() > 1) {
		cout << s[s.length() - 1];
		reverseDisplay(s.substr(0, s.length() - 1));
	}
	else {
		cout << s[s.length() - 1];
	}
}

int main() {
	//call intro function
	intro();
	//initiate a string to be used for user input
	string s;

	cout << "Enter a line of text: ";
	getline(cin, s);

	//while function keeps repeating until user inputs quit
	//calls the reverseDisplay function for every line of text
	while (s != "quit") {

		cout << "Your text reversed! \n";
		reverseDisplay(s);
		cout << "\n\nEnter a line of text: ";
		getline(cin, s);

	}


	system("pause");
	return 0;
}