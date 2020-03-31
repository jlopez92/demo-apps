#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float kiloToPounds(int kilo){ //function to calculate kg to lbs
	float pounds = kilo / 0.45359237; //formula to convert kilograms to pounds
	return pounds; //return pounds 
}

float poundsToOunces(float pounds){ //function to calculate lbs to oz
	float ounces = pounds / 16; //formula to convert pounds to ounces
	return ounces; //return ounces 
}


int main(){
	cout << fixed;
	cout.precision(2); //two decimal places 
	
	
	cout << "Kilograms, pounds, and ounces table" << endl;
	cout << "-----------------------------------\n" << endl;
	
		
	int min, max; //min and max variable for lower and upper bound
	
	cout << "       Enter lower bound: ";//prompt user for lower bound and store in min, repeat for max
	cin >> min;
	cout << "       Enter upper bound: ";
	cin >> max;
	
	cout << endl;

	cout << "Kilograms" << setw(10) << "lbs" << setw(10) << "Ounces" << endl; //set up table using setw
	
	while(min <= max ){ //while loop to call and display the function results of the conversions
	//while loop repeats until the min is equal to max(includes max)
		float pounds = kiloToPounds(min); //store the kilo to pound return in a float variable 
		float ounces = poundsToOunces(pounds); //store the pound to ounces variable in a float variable
		cout <<setw(5) << min << setw(13) << pounds << setw(10) << ounces << endl; //display results in table form
		
		min = min + 1; //add 1 to the lower bound in order to continue the while loop until min matches max
		
	}
	
	return 0;
}
