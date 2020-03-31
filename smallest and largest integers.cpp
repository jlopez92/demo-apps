#include<iostream>
#include<vector>
using namespace std;

//int function for largest parameter
//constant int vector is the input parameter
int largestInt(const vector<int>& vec){
	int largest = vec[0]; // initialize int variable to hold the return int
	for(int index = 0; index < vec.size(); index++){//for loop iterates through the vector
		if(vec[index] > largest){//if statment to determine if current iteration of vector is larger than the last
			largest = vec[index];//if current vector iteration is largest, store in largest variable
		}
	}
	return largest; //return largest variable
}


//repeat int function for largest parameter, but replace largest, with smallest, and find smallest int
int smallestInt(const vector<int>& vec){
	int smallest = vec[0];
	
	for(int index = 0; index < vec.size(); index++){
		if(vec[index] < smallest){
			smallest = vec[index];
		}
	}
	
	return smallest;
}


int main(){
	
	cout << "Smallest / Largest vector search" << "\n*******************************\n" << endl;
	
	int userInt; //initialize userint int variable to store user integers 
	int count = 0; //initialize and declare count variable 
	vector<int> userValues; //intialize vector to hold user values 
	
	//while loop to gather 10 integers from user, and add to vector
	while(count < 10){
		cout << "Enter an integer: ";
		cin >> userInt;	
		userValues.push_back(userInt);
		count++;
	}
	
	//call largestint function to find largest integer
	//repeat for smallest value
	cout << "The largest value is: " << largestInt(userValues) << endl;
	cout << "The smallest value is: " << smallestInt(userValues) << endl;
	
	return 0;
}
