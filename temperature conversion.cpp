#include<iostream>
using namespace std;

int main() 
{
	cout << fixed;
	cout.precision(1);  //display results using 1 decimal place
	
	float kelvin; // create float variable for kelvin
	float fahrenheit; //create float variable for fahrenheit
	float celsius; //create float variable for celsius
	cout << "Please enter a temperature in kelvin: "; //prompt user input for kelvin temperature
	cin >> kelvin; //store user input in kelvin variable
	
	cout << "\n \n  ---------Processing---------" << endl;

	celsius = kelvin - 273.15; //convert kelvin to celius and store in celsius variable
		fahrenheit = (celsius * (9/5)) + 32; //convert celius to farhenheit and store in fehrenheit vairable
	
	
	cout << "\n      Results" << endl;
	cout << "      ----------" << endl;
	cout << "        Kelvin: " << kelvin << endl; //display kelvin temperature
	cout << "       celsius: " << celsius << endl; //display celsius temperature
	cout << "    fahrenheit: " << fahrenheit << endl; //display fahrenheit temperature 
	
	return 0;
	
}
