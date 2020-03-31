#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//void function takes in the x and y parameters, converts to an int using y as the 10's and x as the 1's
//for loop, loops through each integer and calls the char character, creating a table
void displayASCII(int x1, int x2, int y1, int y2){
	
	int min = y1 * 10 + x1;
	int max = y2 * 10 + x2;
	
	for(min = min; min <= max; min++) {
	if (min % 5 == 0){
		cout << char(min) << endl;
	} else {
		cout << char(min) << " ";
	}
	
}
	
	
}

int main() {
	
	//prompting user for the inputs and storing into int variables 
	cout << "ASCII Table" << endl;
	cout << "------------ \n \n" << endl;
	cout << "Enter values for x and y." << endl;
	cout << "X should be within [0, 9]." << endl;
	cout << "y should be within [6, 11]. \n" << endl;
	
	int x1, x2, y1, y2;
	
	cout << "Enter a mininum x: ";
	cin >> x1;
	
	cout << "Enter a maximum x: ";
	cin >> x2;
	
	cout << "Enter a mininum y: ";
	cin >> y1;
	
	cout << "Enter a maximum y: ";
	cin >> y2;
	
	//if statement determines whether inputs are within range and calls the displayASCII function, or displays error message
	if (x1 >= 0 && x1 <= 9 && x2 >= 0 && x2 <= 9 && y1 >= 6 && y1 <= 11 && y2 >= 6 && y2 <= 11){
		cout << "\n \n ASCII TABLE" << endl;
		cout << "--------------" << endl;
		displayASCII(x1, x2, y1, y2);	
	} else {
		cout << "Invalid output, out of range" << endl;
	}
 	
	
	return 0;
}
	
