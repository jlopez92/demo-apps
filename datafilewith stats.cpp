#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//functions from smallest and largest integers assignment
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

//function that takes in a vector
//grabs the sum of all the integers in vector
//divides the sum by the total number of ints in the vector 
//returns average 
int averageInts(const vector<int>& vec){
	int sum = 0;
	double average;
	
	for(int index = 0; index < vec.size(); index++){
		sum = sum + vec[index];
	}
	
	average = sum / vec.size();
	
	return average;
}

int main(){

	vector<int> numbers; // int vector called numbers to store ints in input.txt file
	int number; // int variable 
	
	ifstream inFile("input.txt"); //open input.txt file 

	
	while(inFile.eof() == false) { 	//grabs each int in input.txt file, stores each number in numbers vector
		inFile >> number;
		numbers.push_back(number);
	}
	
	inFile.close(); //close input.txt file
	
	int average = averageInts(numbers); //calls averageInts function to retrieve average of numbers
	int largest = largestInt(numbers); //calls largestInt function to retrieve largest int in numbers vector
	int smallest = smallestInt(numbers); //calls smallestInt function to retrieve smallest integer
	
	ofstream outFile("Output.txt"); //creates output.txt file 
	outFile << "The average is: " << average << endl; //stores average
	outFile << "The largest integar is: " << largest << endl; //stores largest
	outFile << "The smallest integar is: " << smallest << endl; //stores smallest
	
	outFile.close();
	

	
	return 0;
}
