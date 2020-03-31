#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

//printVector function iterates throught the To_Do list vector
//outputs each vector item to the screen on new line
void printVector(const vector<string>& vec){
	
	for(int index = 0; index < vec.size(); index++){
		cout << index + 1 << ". " << vec[index] << endl;
	}
	cout << endl;
}

//deleteItem function displays the items in the list vector, with vector numbers to choose for deletion
//user input is taken and used to choose which item will be deleted
void deleteItem(vector<string>& vec){
	int itemDelete;
	for(int index = 0; index < vec.size(); index++){
		cout << " (Vector index: " << index << ")" << vec[index] << endl;
	}
	cout << "\nWhich item number would you like to delete from the list: ";
	cin >> itemDelete;
	vec.erase(vec.begin() + itemDelete);
	cout << endl;
}

//addItem function asks user for new item to aedd to list
//item is stored in the list vector using getline
//cin ignore must be used or else the stored item in the vector will be a empty
void addItem(vector<string>& vec){
	string addNew;
	cout << "Add to List:" ;
	cin.ignore();
	getline(cin,addNew);
	vec.push_back(addNew);
}


int main(){
	//create vector to store todo list
	vector<string> list;
	//open and read To_Do.txt file
	ifstream inFile("To_Do.txt");
	
	string item;//string item to iterate through items in file
	int userInput;
	
	//while statement, grabs each line item in the file, stores each line in a string vector
	while(getline(inFile, item)) { 	
	//	inFile >> getline(item, string);
		list.push_back(item);
	}
	inFile.close();	 //close file once it has been read, and transferred to vector
	
	cout << "To Do list\n\n1. Display List.\n2. Add to list. \n3. Remove from list.\n4. Quit.\n" << endl; //menu options
	cout << "What would you like to do? "; //prompt user to choose from menu items
	cin >> userInput;//store user input into int variable
	
	//while loop, call function based on user input or end using item number 4 from the menu options
	while(userInput != 4){ 
		
		//if statement to test user input for menu options
		if(userInput == 1){
			printVector(list);//call function to display the vector list
			cout << endl;
		} else if(userInput == 2){
		addItem(list);//call function that adds item to vector
		} else{
		deleteItem(list); //call function that deletes an item from the vector list
		}
		
		cout << "To Do list\n\n1. Display List.\n2. Add to list. \n3. Remove from list.\n4. Quit.\n" << endl;
		cout << "What would you like to do? "; //continue sentinal loop
		cin >> userInput;
	}

	ofstream outFile("To_Do.txt"); //opens the todo text file
	//for statement iterates through the list vector and stores each item into a new line on the file
	for(int index = 0; index < list.size(); index++){ 
		outFile  << list[index] << endl;
	}
	
	outFile.close();//close todo file 
	
	
	return 0;
}
