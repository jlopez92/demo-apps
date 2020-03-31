#include <iostream>
#include <vector>
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

int main(){
	
	//prompt user for sizer of class and grades for each student
	int classSize;
	cout << "Number of students in class: ";
	int studentCount;
	int currentScore;
	cin >> studentCount;
	
	//iterate through a size of class to prompt for each student score. store in scores vector
	vector<int> scores;
	for(int index = 0; index < studentCount; index++){
		cout << "Enter score for student " << index + 1 << ": ";
		cin >> currentScore;
		scores.push_back(currentScore);
	}
	
	cout << "\n--------------------------\n" << endl;
	int bestScore = largestInt(scores); //find best score in class
	
	//for statement to loop through grades of students
	//if statement assigns grades 
	for(int index = 0; index < studentCount; index++){
		if(scores[index] >= bestScore - 10){
			cout << "Grade for student " << index + 1 << ": A" << endl;
		} else if(scores[index] >= bestScore - 20){
			cout << "Grade for student " << index + 1 << ": B" << endl;
		} else if(scores[index] >= bestScore - 30){
			cout << "Grade for student " << index + 1 << ": C" << endl;
		} else if(scores[index] >= bestScore - 40){
			cout << "Grade for student " << index + 1 << ": D" << endl;
		} else {
			cout << "Grade for student " << index + 1 << ": F" << endl;
		}
	}
	
	return 0;
}
