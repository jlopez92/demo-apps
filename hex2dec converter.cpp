#include<iostream>
#include<cmath>
#include<string>
#include<exception>
using namespace std;

//function takes in a string and converts each character to a int
//if a character is not part of a hexidicimal than an exception is thrown
unsigned int hex2Dec(const string& hexString) {
	unsigned int sum = 0, count = 0, charValue;
	char strToChar;
	int size = hexString.length() - 1;
	while (size >= 0) {
		strToChar = hexString[size];
		if (strToChar >= '0' && strToChar <= '9') {
			strToChar = (strToChar - 48);
			charValue = strToChar * pow(16, count);
			count++;
			sum += charValue;
		}
		else if (strToChar >= 'A' && strToChar <= 'F') {
			strToChar = (strToChar - 55);
			charValue = strToChar * pow(16, count);
			sum += charValue;
			count++;
		}
		else {
			throw "That is not a valid char";
		}
		size--;
	}

	return sum;
}

int main() {
	cout << "Hexidecimal to decimal conversion calculator" << endl;
	cout << "********************************************" << endl << endl;
	invalid_argument except("Error, invalid argument.");
	unsigned int conversionValue;
	cout << "Enter a hexadecimal(q to quit): ";
	string userInput;
	cin >> userInput;
	//while function to repeat program until a valid hexidecimal is input
	while (userInput != "q") {
		try
		{
			conversionValue = hex2Dec(userInput);
			cout << "Hexidecimal to decimal conversion of value " << userInput << " is " << conversionValue;
			break;
		}

		catch (const char* exceptMessage)
		{
			cout << "char*: " << exceptMessage << endl;
		}
		cout << "Enter a hexadecimal(q to quit): ";
		cin >> userInput;
	}
	cout << endl << endl;

	return 0;
}