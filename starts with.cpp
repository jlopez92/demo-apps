#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//bool function determines whether string 1 begins with string 2 by using a for statment to loop through each character in the second string
//compares it to the corresponding character in the first string
bool startsWith(string start1,string start2){
	
	for(int index = 0; index < start2.length(); index++) {
		
		if (start1[index] != start2[index]){
			return false;
		}
}
	return true;
}

int main() {
	
	cout << "Starts with\n" << "-----------" << endl;
	//prompt user for two strings and store in string variables
	string start1, start2;
	cout << "Enter the first string: ";
	getline(cin, start1);
	cout << "Enter the second string: ";
	getline(cin, start2);
	//if statement to determine whether the first string is longer than the second. 
	//if it is, the startswith function is called 
	if (start1.length() >= start2.length()){
		if (startsWith(start1, start2)){
			cout << "True, '" << start1 << "' begins with '" << start2 << "'" << endl;
		} else {
			cout << "False, '" << start1 << "' does not begin with '" << start2 << "'" << endl;	
		}
	} else {
		cout << "False, you're first string is longer than your second string" << endl;
	}
	
	return 0;
}
