#include<iostream>
#include<vector>
using namespace std;

//starts with function from assignment 28
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

//void functino to search for names
void searchNames(const vector<string>& vec, string letter){
	//iterate through vector, test whether the name begins with the given letter
	for(int index = 0; index < vec.size(); index++){
		if (startsWith(vec[index], letter)){
			cout << vec[index] << endl;
		} 
	}
}

int main(){
	
	//prompt user for list of names
	cout << "Enter a list of names to add to a list." << endl;
	cout << "***************************************\n" << endl;
	
	cout << "Enter name(0 to stop): ";
	string name; //string variable to hold current name entry
	cin >> name;
	
	vector<string> names; //initalize names vector to hold list
	names.push_back(name); //add current name in name variable to vector list.
	
	while(name != "0"){//sentinal loop to continue prompting for names
		cout << "Enter name(0 to stop): ";
		cin >> name;
		names.push_back(name);	
	}
	
	cout << "\n\nNext i will display all names that begin with a certain character." << endl;
	cout << "Enter chosen character.\n" << endl;
	
	cout << "> ";
	string searchChar;//string variable to hold search character
	cin >> searchChar;
	
	searchNames(names, searchChar);
	
	return 0;
}
