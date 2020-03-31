#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << fixed;
	cout.precision(2); //set decimals to display 2 
	cout << "**** Tip Calculator ****" << endl; // 
	
	float subtotal; //create float variable to store subtotal
	float tip; //create float variable to store top
	float tax; //create float variable to store tax
	float total; // create float variable to store total
	
	cout << "\n Enter the bill subtotal: "; //request subtotal from user
	cin >> subtotal; //store user input into subtotal
	
	tip = subtotal * .15; // calculate tip of 15% of subtotal
	tax = subtotal * .085; // calculate tax of 8.5% of subtotal
	total = subtotal + tax + tip; // store total as subtotal, tax, and tip added togeter
	
	cout << "Subtotal:   " << subtotal << endl; //display subtotal
	cout << "     tip:   " << tip << endl; // display tip
	cout << "     tax:   " << tax << endl; //display tax
	cout << "   Total:   " << total << endl; //display total
	
	
	return 0;
	
	
}
