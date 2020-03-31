#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	//prompt user for integer and store in userInt variable
	cout << "Enter integers between 1 and 100. Enter 0 to quit.\nEnter integer: ";
	int userInt;
	cin >> userInt;
	
	vector<int> values;//initialize a vector to hold user integers
	values.push_back(userInt);//add user integer to vector
	
	while(userInt != 0){//sentinal loop to add integers by user
		cout << "Enter an integer: ";
		cin >> userInt;
		
		if(userInt > 0 && userInt <= 100){ // if statement to confirm integers are within range 
		values.push_back(userInt);
	} else if(userInt == 0){
		cout << "You entered 0. Integer entry has stopped.\n\n" << endl;
	} else {
		cout << "You entered an invalid integer. Please enter an integer between 1 and 100." << endl;
	}
		
	}
	
	vector<int> valueStorage (101, 0);//create a vector of size 101 that all have a value 0
	
	for(int index = 0; index < values.size(); index++){ //iterate through storage vector and add each integer into its equivalent index
		valueStorage[values[index]] = valueStorage[values[index]] + 1;
	}
	
	//iterate through storage to find how many times each integer occurs
	//based on value of each index
	for(int index = 0; index < valueStorage.size(); index++){
		if(valueStorage[index] == 1){
			cout << index << " Occurs 1 time" << endl;
		} else if(valueStorage[index] > 1) {
			cout << index << " Occurs " << valueStorage[index] << " times. " << endl; 
		}	
	}
	
}
