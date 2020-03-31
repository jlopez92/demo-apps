#include<iostream>
using namespace std;

int main(){
	
	cout << fixed;
	cout.precision(2);
	float weight; //create float variable for the weight
	double cost; //create double variable for the cost
	cout << "Please enter weight in lbs: "; //prompt user for weight of package
	cin >> weight; //enter user input into weight variable
	
	//start if else statement
	if (weight > 0 && weight <= 1){ //if weight is between 0 and 1
		cost = 5.50; //set cost amount to 5.50
		cout << "Cost to ship is $" << cost << " Per pound." << endl;//display cost amount per pound to user
	} else if (weight > 1 && weight <= 5){//repeat weight between 1 and 5
		cost = 4.75;
		cout << "Cost to ship is $" << cost << " Per pound." << endl;
	} else if (weight > 5 && weight <=10){
		cost = 3.00;
		cout << "Cost to ship is $" << cost << " Per pound." << endl;
	} else if (weight > 10 && weight <= 25){
		cost = 2.50;
		cout << "Cost to ship is $" << cost << " Per pound." << endl;
	} else if (weight > 25 && weight < 500){
		cost = 2.25;
		cout << "Cost to ship is $" << cost << " Per pound." << endl;
	} else if (weight <= 0){ //if weight less than zero, display error message
		cout << "Error, the weight can't be less than zero, please check again" << endl;
	} else if (weight > 500){ //if weight is greater than zero, display error message
		cout << "weight can't be higher than 500. We are unable to ship" << endl;
	} 
	
	float shippingCost = cost * weight; //calculate shipping cost from cost variable and weight variable
	cout << "Your shipping cost is $" << shippingCost << endl; //let user know their total shipping cost
	
	
	return 0;
}
