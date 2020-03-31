#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//bool function to determine if entry is a vowel, parameter is a letter
bool isVowel(char letter){
	
	if(letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' || letter == 'I' || letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U'){
		return true;
	} else {
		return false;
	}
	
}

//bool function to determine if parameter is a letter and not a vowel
bool isConsonant(char letter){
	
	if (isalpha(letter) && !isVowel(letter) ){
		return true;
	} else {
		return false;
	}
	
}

int main() {
	
	//string variable named input takes user input of a sentence
	string input;
	
	cout << "Enter a sentence: ";
	getline(cin, input);

	int lastIndex = input.length() - 1;
	
	//for loop, loops through each letter and calls function to determine vowel, consonant, or neither
	for(int index = 0; index < input.length(); index++) {
	
		if (isVowel(input[index])){
			cout << input[index] << " | Vowel" << endl;	
		} else if(isConsonant(input[index])) {
			cout << input[index] << " | Consonant" << endl;	
		} else {
			cout << input[index] << " | neither a Vowel nor a Consonant" << endl;
		}
	
	}
	
	
	return 0;
}
